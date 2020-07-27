### 1.  PyTorch model definition

import torch.nn as nn

def conv3x3(in_planes, out_planes, stride=1):
    """3x3 convolution with padding"""
    return nn.Conv2d(in_planes, out_planes, kernel_size=3, stride=stride, padding=1, bias=False)


def conv1x1(in_planes, out_planes, stride=1):
    """1x1 convolution"""
    return nn.Conv2d(in_planes, out_planes, kernel_size=1, stride=stride, bias=False)


class BasicBlock(nn.Module):
    expansion = 1

    def __init__(self, inplanes, planes, stride=1, downsample=None):
        super(BasicBlock, self).__init__()
        self.conv1 = conv3x3(inplanes, planes, stride)
        self.bn1 = nn.BatchNorm2d(planes)
        self.relu = nn.ReLU(inplace=True)
        self.conv2 = conv3x3(planes, planes)
        self.bn2 = nn.BatchNorm2d(planes)
        self.downsample = downsample
        self.stride = stride

    def forward(self, x):
        identity = x

        out = self.conv1(x)
        out = self.bn1(out)
        out = self.relu(out)

        out = self.conv2(out)
        out = self.bn2(out)

        if self.downsample is not None:
            identity = self.downsample(x)

        out += identity
        out = self.relu(out)

        return out


class CifarResNet(nn.Module):

    def __init__(self, block, layers, num_classes=10):
        super(CifarResNet, self).__init__()
        self.inplanes = 16
        self.conv1 = conv3x3(3, 16)
        self.bn1 = nn.BatchNorm2d(16)
        self.relu = nn.ReLU(inplace=True)

        self.layer1 = self._make_layer(block, 16, layers[0])
        self.layer2 = self._make_layer(block, 32, layers[1], stride=2)
        self.layer3 = self._make_layer(block, 64, layers[2], stride=2)

        self.avgpool = nn.AdaptiveAvgPool2d((1, 1))
        self.fc = nn.Linear(64 * block.expansion, num_classes)

        for m in self.modules():
            if isinstance(m, nn.Conv2d):
                nn.init.kaiming_normal_(m.weight, mode='fan_out', nonlinearity='relu')
            elif isinstance(m, nn.BatchNorm2d):
                nn.init.constant_(m.weight, 1)
                nn.init.constant_(m.bias, 0)

    def _make_layer(self, block, planes, blocks, stride=1):
        downsample = None
        if stride != 1 or self.inplanes != planes * block.expansion:
            downsample = nn.Sequential(
                conv1x1(self.inplanes, planes * block.expansion, stride),
                nn.BatchNorm2d(planes * block.expansion),
            )

        layers = []
        layers.append(block(self.inplanes, planes, stride, downsample))
        self.inplanes = planes * block.expansion
        for _ in range(1, blocks):
            layers.append(block(self.inplanes, planes))

        return nn.Sequential(*layers)

    def forward(self, x):
        x = self.conv1(x)
        x = self.bn1(x)
        x = self.relu(x)

        x = self.layer1(x)
        x = self.layer2(x)
        x = self.layer3(x)

        x = self.avgpool(x)
        x = x.view(x.size(0), -1)
        x = self.fc(x)

        return x

model = CifarResNet(BasicBlock, [3, 3, 3], num_classes=10)


### 2.  Import weights into the model and freeze it

import torch

# Load the weights from a file (.pth usually)
state_dict = torch.load('../resources/weights/cifar10-resnet20.pth')
model.load_state_dict(state_dict, strict=False)

# Evaluation mode on, training mode off. 
# Necessary since layers such as dropout and batchnorm 
# behave differently during training versus evaluation phases.
model.eval()



### 3.  Test the PyTorch model

### 3a. Helper functions

from PIL import Image
import numpy as np

# Class labels for CIFAR classes 0 to 9
classes = ('plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck')

# Process the image
def process_image(image_path):
    # Load Image
    img = Image.open(image_path)
    
    # Get the dimensions of the image
    width, height = img.size
    
    # Turn image into numpy array
    img = np.array(img)
    
    # Make the color channel dimension first instead of last
    img = img.transpose((2, 0, 1))
    
    # Make all values between 0 and 1
    img = img/255

    # Normalize based on the preset mean and standard deviation
    img[0] = (img[0] - 0.4914)/0.2023
    img[1] = (img[1] - 0.4822)/0.1994
    img[2] = (img[2] - 0.4465)/0.2010
    
    # Add a fourth dimension to the beginning to indicate batch size
    # img = img[np.newaxis,:].astype(np.float16)
    img = img[np.newaxis,:]
    
    # Turn into a torch tensor
    image = torch.from_numpy(img)
    image = image.float()
    return image

# Using our model to predict the label
def predict(image, model):
    # Pass the image through our model
    output = model.forward(image)
    
    # Get the top predicted class
    probs, classes = output.topk(1, dim=1)

    return classes.item(), output


### 3b. Run prediction

# Process Image 
image = process_image("../resources/cifar/horse5.png")

# Give image to model to predict output
top_class, output = predict(image, model)

# Print the output

print(output)

# Print the prediction
print("The PyTorch model predicts the image is a", classes[top_class] + ".")



### 4a. Convert PyTorch to ONNX

# export the model
torch.onnx.export(model,                     # pytorch model
                  image,                     # example or dummy input
                  "cifar10-resnet20.onnx",   # name of onnx file                 
                  export_params=True,        # store the trained parameter weights inside the model file
                  opset_version=7,           # the ONNX version to export the model to
                  do_constant_folding=True,  # whether to execute constant folding for optimization
                  input_names = ['input'],   # the model's input node name
                  output_names = ['output']) # the model's output node name


### 4b.   Cleanup ONNX

import onnx
import onnx.utils
from onnx import version_converter, optimizer
from onnxsim import simplify

# load the model
model_path     = './cifar10-resnet20.onnx'
optimized_model = onnx.load(model_path)

# set ONNX version and ONNX ir_version.
# scailable currently supports ONNX version <= 1.3,
# with ONNX IR version <= 3 and ONNX Operator Set <= 8
optimized_model = version_converter.convert_version(optimized_model, 7) 
optimized_model.ir_version = 3

# optimize, simplifiy and polish the model
optimized_model = optimizer.optimize(optimized_model)
optimized_model, check = simplify(optimized_model)
optimized_model = onnx.utils.polish_model(optimized_model)

# save optimized model
onnx.save(optimized_model, model_path)


### 4c. Test ONNX

import onnxruntime
from onnx import numpy_helper

# load ONNX model
onnx_model = onnxruntime.InferenceSession('cifar10-resnet20.onnx')

# set already defined horse5.png image as input
onnxrt_inputs = {onnx_model.get_inputs()[0].name: image.numpy()}

# run onnx model
onnxrt_outs = onnx_model.run(None, onnxrt_inputs)

# print per class prediction value
print(onnxrt_outs[0])

# Print the prediction
print("The ONNX model predicts the image is a", classes[np.argmax(onnxrt_outs[0])] + ".")



### 5.  Generate base64 string

from onnx import numpy_helper
import base64

# convert numpy array to TensorProto protobuf tensor
output_tensor = numpy_helper.from_array(image.numpy())

# base64 encode the tensor
base64_input  = base64.b64encode(output_tensor.SerializeToString())

# print the resulting base64 string
print(str(base64_input, "ascii"))
# Scailable Tutorials, Information and FAQ
> Last updated 12-08-2020.

In this public repository we gather tutorials, frequently asked questions, and interactive demos. If you are encountering any problems using our services or have suggestions for improvements, please do let us know by [creating a new issue](https://github.com/scailable/sclbl-tutorials/issues/new). 

If you do not yet have a Scailable account, sign up at [www.scailable.net](https://www.scailable.net).

- [Tutorials](https://github.com/scailable/sclbl-tutorials#tutorials)
- [Interactive demos](https://github.com/scailable/sclbl-tutorials#interactive-demos)
- [Videos](https://github.com/scailable/sclbl-tutorials#videos)
- [Posts](https://github.com/scailable/sclbl-tutorials#posts)
- [Data Values and Principles](https://github.com/scailable/sclbl-tutorials#data-values-and-principles)

## Tutorials

* [sclbl-101-getting-started](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-101-getting-started): A step-by-step explanation of the use of Scailable. This tutorial shows how to sign up for a *beta* account, and how to create a first Scailable endpoint using the `sclblpy` package. 
* [sclbl-create-your-own-wasm](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-create-your-own-wasm): This tutorial shows how to create your own custom WebAssembly executable using `c` (and the [wasienv](https://medium.com/wasmer/wasienv-wasi-development-workflow-for-humans-1811d9a50345) toolchain) that can be deployed on the Scailable platform.
* [sclbl-using-the-webnode](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-using-the-webnode): A tutorial that demonstrates how to run a Scailable WebAssembly task either in the browser or in our Scailable cloud - automatic fallback included!
* [sclbl-pytorch-onnx](https://github.com/scailable/sclbl-tutorials/blob/master/sclbl-pytorch-onnx/README.md): A tutorial demonstrating how to convert models fitted using PyTorch to WebAssembly using the Scailable platform and [ONNX](http://onnx.ai).

## Interactive demos
Next to the tutorials presented in this repository, we also have a number of interactive demos:

* [Object recognition on the edge](https://www.scailable.net/demo/cifar/). This demo allows you to recognize object in images directly on the edge (i.e., in your browser). It shows how you can use Scailable to compile complex models to WebAssembly and subsequently how you can use the [`sclbl-webnode`](https://github.com/scailable/sclbl-webnode) for super easy deployment.
* [Scailable supports running complex models](https://www.scailable.net/demo/avm/) (such at [Bayesian Additive Regression Trees](https://projecteuclid.org/euclid.aoas/1273584455)) in the cloud, on the edge, or on a browser. Check how we can flexibly generate posterior predictive inferences for automatic property valuation models, anytime, anywhere.
* [Sometimes what you need is performance](https://www.scailable.net/demo/bench/). We provide nothing less. The inferences from our models are extremely fast; check out some of our benchmarks.
* An interactive [MNIST number recognition model](https://www.scailable.net/demo/mnist/). It updates its estimates as fast as you can draw!

## Videos:
Some sample video's of the use of Scailable:

* [Introducing the Scailable platform](https://youtu.be/47wUrjtgFcs). A simple video showcasing the basic functionalities of the Scailable platform.
* [Image classification in the browser](https://www.youtube.com/watch?v=3m8V-zahU8g) Using PyTorch, ONNX, WebAssembly, and the sclbl-webnode to deploy object recognition directly in the browser. See also [https://www.scailable.net/demo/cifar/](https://www.scailable.net/demo/cifar/).
* [Scailable Webinar](https://www.youtube.com/watch?v=ldhTSQ6K_Co&feature=youtu.be) Webinar explaining the Scailable deployment process to WebAssembly.

## Posts:
Some posts / articles:

* [Object recognition on the edge](https://medium.com/@maurits.kaptein/object-recognition-on-the-edge-fc8aaaeb2c53). An article detailing how we build the [object recognition on the edge!](https://www.scailable.net/demo/cifar/) demo.
* [Why would you use WebAssembly to put scikit-learn in the browser?](https://towardsdatascience.com/why-would-you-use-webassembly-to-put-scikit-learn-in-the-browser-77671e8718d6). A very popular article detailing why WebAssembly is a great tool for deploying AI & ML models. Give it a read!
* [Stop training more models, start deploying them](https://towardsdatascience.com/stop-training-more-models-start-deploying-them-using-webassembly-49a3f178569e). An article detailing the challenges when deploying models in healthcare.
* [From model fitting to production in seconds](https://towardsdatascience.com/from-model-fitting-to-production-in-seconds-8e6823d87f5d). The shortage usage example of Scailable we were able to write.

## Data Values and Principles:

Scailable is committed to the advancement of AI driven by ethical principles that put people first. To further clarify this position, we make our "Ethical Data Science Manifesto" (building on from the Linux Foundation' s "[Data Values and Principles](https://datapractices.org/manifesto/)") available [here](https://github.com/scailable/sclbl-tutorials/blob/master/RESPONSIBLE-AI-MANIFESTO.md). As we acknowledge that this area is dynamic and evolving, we expect to adapt, update and further develop the manifesto as we as we learn over time. 

We also invite our users to check their project(s) against *[deon](https://deon.drivendata.org/)*, an open source command line tool that allows you to easily add an ethics checklist to your data science projects.



----------


Thanks for your attention! Let us know if you have any suggestions please let us know by [creatinging a new issue](https://github.com/scailable/sclbl-tutorials/issues/new) or emailing us at [go at scailable dot net](mailto:go@scailable.net).

If you find any mistakes in our tutorials, please do [add an issue](https://github.com/scailable/sclbl-tutorials/issues/new) so we can fix it asap!

You can find the terms & conditions that apply to our beta program [here](https://github.com/scailable/sclbl-tutorials/blob/master/terms/README.md).

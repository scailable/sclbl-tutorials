> 19-10-2020: Text for Medium / TowardsDataScience post accompanying the jupyter notebook exploring the differences between model training and model deployment as details in [this notebook](logistic-regression.ipynb)


# Exploiting the differences between model training and model deployment
### Reducing the memory footprint and improving the speed of your deployed models.

![Overview image](train-vs-deploy.png)

> The code accompanying this post can be found [here](logistic-regression.ipynb).

By now we have helped a large number of companies deploy their AI / ML models in various enviroments. We have contributed to model deployment in Healthcare, and, in the last few months, we have helped companies move trained models to various IoT devices. Especially in the latter case the tehcnical deployment requirements are often strict: both the number of compute cycles and the available memory are often limited. 

In this post we clarify how we make sure that models which are trained using standard ML libraries such as PyTorch, Scikit-learn, and Tensorflow can efficiently be deployed on various edge devices. To make things tangible, we will examine the model training and deployment of a simple logistic regression model. However, most of what we discuss here transfers directly to more complext models.

## Model training
To illustrate, let's start by simulating some data. The code below generates 1000 observations according to the following simple model:

![dgp](dgp.pdf)

```python
# Simulate Data Generating Process
n = 1000  # 1000 observations
x1 = np.random.uniform(-2,2,n)  # x_1 & x_2 between -2 and 2
x2 = np.random.uniform(-2,2,n)
p = 1 / (1 + np.exp( -1*(.75 + 1.5*x1 - .5*x2) ))  # Implement DGP

y = np.random.binomial(1, p, n)  # Draw outcomes

# Create dataset and print first few lines:
data = np.column_stack((x1,x2,y))
print(data[:10])
```

After generating the data, we can focus on fitting a model. We simply use `sklearn`'s `LogisticRegression()` function to do so:

```python
from sklearn.linear_model import LogisticRegression
mod = LogisticRegression().fit(data[:,[0,1]], np.ravel(data[:,[2]]))
```

However, here it's usefull to pauze and briefly consider what is happening under the hood. Logistic regression models, as are many other interesting ML models, are trained iteratively. To train the model, `sklearn` (or any other package providing similar functionality) will have to implement several functions:

1. Some sort of score funtion indicating the fit of the model. This might be an error function, or a maximum likelihood function.
2. A function which updates the parameters of the fitted model from one iteration to the next.

The training process will effectively use both functions iteratively: First, the parameters of the model are randomly instantiated. Next, the score of the model is checked, and if the score is deemed insufficient (often because it has improved compared to the previous iteration), the model parameters are updated and the process is repeated. 

Even for this simple model, `sklearn` took 8 passes throught the dataset:

```python
print(mod.n_iter_)
```

Thus, to train a model we need access to the data, several utility functions, and multiple iterations / passes throught the dataset. This is why for complex models we use parrallelization and GPUs to carry out the process in a reasonable time.

## Generating predictions

Now, contrast this with 
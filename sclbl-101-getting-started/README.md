# Scailable 101 Getting Started
> Last updated 20-06-2020; By the Scailable core team.

This tutorial provides the absolute starting point to start using [Scailable](https://www.scailable.net). We will take you through, *step-by-step*, the process of setting up your Scailable *beta* account (as currently we are in private beta), and the building of your first model. We will share all the steps as elaborately as possible. 

To start using Scailable we will cover the following steps:

1. [Signing up for the scailable beta](#signup). This should be easy, but we will show it anyway.
2. [After approval: a first look around](#look-around). A brief tour of our web admin.
3. [Installing the `sclblpy` package](#installing-sclblpy). In this "101" we focus on the use of the `sclblpy` `python` package to deploy models directly from python. So, we need to install the package.
4. [Fitting a model](#model-fitting). Model building itself is not a part of the Scailable product, thus, we use a simple generated dataset for illustration purposes.
5. [Deploying the model using Scailable](#model-deployment). So, this is really just one line of code, but we will explain what happens behind the scenes.
6. [Generating predictions](#integrating). Finally, once a model is deployed you can obviously use it; we provide various ways of using the created model in production.

That's it; let's get started.

> **NOTE:** For those not wishing to read all the stuff below, the summary is pretty easy. If you wish to use [Scailable](https://www.scailable.net) to deploy a machine learning model, once you have an account, you only need a single line of code:
`sp.upload(fitted_model, feature_vector, docs=documentation)`.

<a name="signup"></a>
# 1. Signing up

To use [Scailable](https://www.scailable.net) you will need a scailable **beta** account; you get one at [https://admin.sclbl.net](https://admin.sclbl.net) which looks like this:

![Log in to scailable](resources/images/1-login.png "Log in to Scailable")

Admittedly, this is actually the page where you would *log in* if you have an account already. So, click on "here" in the sentence *"No account yet? Create one here."* Doing so gets you to [https://admin.sclbl.net/signup.html](https://admin.sclbl.net/signup.html) which, after scrolling down, looks like this:

![Sign up for scailable](resources/images/1-signup.png "Sign up")

On this page you simply fill in your name, email, and a password, and press the big blue **SIGN UP** button. This subsequently gets you to the following screen:

![Confirmation](resources/images/1-signup-confirm.png "Signed up")

And next, [you wait....](https://www.youtube.com/watch?v=x_iPvUWyzhE)

While you are waiting we will check your application and we will *potentially* allow you into our **beta** program. Once we do, you receive the following email:

![Confirmation email](resources/images/1-confirmation-email.png "Confirmed!")

And you are good to go!

> **NOTE:** If you want to provide us with any feedback regarding the product, please [add an issue here](https://github.com/scailable/sclbl-tutorials/issues/new).

<a name="look-around"></a>
# 2. Looking around

After receiving your confirmation email, the next step should be relatively straightforward; you click the massive blue button in the email (and by doing so fully activate your account), and you arrive once again at our login page. By now you have a valid login, so go ahead!

![Logging in to scailable](resources/images/2-login-filled.png "Logging in to Scailable")

> **NOTE:** In the remainder of this section we effectively explain the Scailable admin interface; you can [skip this](#installing-sclblpy) if you wish.

## Endpoints
After logging in for the first time, you will find yourself at [https://admin.sclbl.net/endpoints.html](https://admin.sclbl.net/endpoints.html) which looks like this:

![Empty endpoints](resources/images/2-endpoints-empty.png "Empty endpoints")

Admittedly, this page is somewhat uninteresting at this point, but that's because you currently do not own any endpoints. However, this might be a good time to explain what an endpoint actually is: A scailable *endpoint* is an easily accessible REST API endpoint which allows you to generate inferences form a machine learning model by simply providing a specific *feature vector* as *input*. The endpoint returns the resulting inference as *output* in JSON format. Thus, effectively, Scailable *endpoints* provide an extremely easy way of deploying ML and AI models.

At [https://admin.sclbl.net/endpoints.html](https://admin.sclbl.net/endpoints.html) you will, after creating an endpoint, be able to see and administer your created endpoints. We will show you how to create endpoints [in a minute](#model-deployment), but first we will continue our tour of the Scailable web admin.

## Toolchains
The next page is [https://admin.sclbl.net/toolchains.html](https://admin.sclbl.net/toolchains.html). This documentation page simply explains how you can use our `[R]` and `python` packages to convert fitted machine learning models directly to a deployment-ready Scailable REST endpoint using a "single-line-of-code". Which is pretty cool. The page itself looks like this:

![Toolchains explained](resources/images/2-toolchains.png "Toolchains explained")

## Upload
The Upload page, found at [https://admin.sclbl.net/upload.hmtl](https://admin.sclbl.net/upload.html), is a bit more interesting: at this page you can upload your AI and machine learning tasks and convert them to a REST endpoint *manually*. By manually we mean that you would not use our `[R]` or `python` packages to upload a model, but rather you will create a machine learning or AI task in [WebAssembly](#wasm) yourself, *by hand*. Once you have such an optimized WebAssembly task with suitable inputs and outputs, you can upload it on the Upload page and we will host the task as a REST endpoint for you.

![Manual upload](resources/images/2-upload.png "Manual upload")

> **NOTE:** Building WebAssembly tasks from scratch can be quite tricky; we thus recommend using our packages. We focus on the `sclblpy` `python` package in the remainder of this document. However, if you want to build your own WebAssembly executable and upload it to Scailable, please check out our [Create your own WASM](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-create-your-own-wasm) tutorial.

## Settings

Finally, the Settings page located at [https://admin.sclbl.net/settings.html](https://admin.sclbl.net/settings.html) allows you to see your personal details, and an overview of your usage of our services. It looks like this:

![Settings](resources/images/2-settings.png "Settings")

<a name="installing-sclblpy"></a>
# 3. Installing `sclblpy`

In this "101", we will explain the use of the `sclblpy` package to deploy ML / AI models directly from `python`. The `sclblpy` package, and its documentation, can all be found at [pypi](https://pypi.org/project/sclblpy/) and the package is thus easily installed using pip:

```
$ pip install sclblpy
```
(or well, `pip3` depending on your installation. `sclblpy` is a `python >3.7` package).

That's it. 

For completeness, on my local machine, using the OSX terminal, installing `sclblpy` looked like this:

![Terminal installation](resources/images/3-terminal.png "Terminal installation")

> **NOTE:** We are actively improving the `sclblpy` package, so by the time you install your version, the minor versioning number might have gone up a notch. Also, if you bump into any issues when using the package, please do report them [here](https://github.com/scailable/sclblpy/issues/new).

<a name="model-fitting"></a>
# 4. Model fitting

For demonstration purposes we fit a very simple linear regression model. The following code generates some data and subsequently fits a model using `sklearn`:

```python
# Imports
import numpy as np
from sklearn.linear_model import LinearRegression

# Data generation y = 10 + 2*x1 -.5*x2 + noise:
np.random.seed(0) 
n = 100
x1 = np.random.uniform(0,10,(n,))
x2 = np.random.uniform(0,10,(n,))
y = 10 + 2 * x1 -.5*x2 + np.random.normal(0,1,(n,))
X = np.column_stack((x1, x2))

# Model fitting
lm = LinearRegression()  
lm.fit(X, y.reshape(-1, 1))
```

The full code for data generation, model fitting, and deployment is availab in [this gist](https://gist.github.com/MKaptein/4277de539ac63645c46148b44951e515). Note that with the current seed a call to `lm.coef_` gives `array([[ 1.94483545, -0.52588468]])`; fairly close to the true data generating process.

<a name="model-deployment"></a>
# 5. Deploying the model

By now we arrive at the cool stuff! We are going to deploy the `sklearn` LinearRegression model that we just fit. Since you should already have a Scailable account by now, the deployment process is simple. First, if you haven't done so already you need to install the `sclblpy` package (we present the actual code instead of screenshots to make copy-pasting a bit easier):

```
$ pip install sclblpy
```
(or `pip3`...)

Next, you should create an example feature vector by simply selecting the first row of our training data. This will allow `sclblpy` to check your model fitting:

```python
# Create an example feature vector
fv = np.array([2,5])  
```
Subsequently, you can create the documentation for this model. Here we simply provide a string, but you can obviously also load the docs from a `.md` file.

```python
docs = {}
docs['name'] = "Simple linear regression demo"
docs['documentation'] = """#Linear regression demonstration.
\nFor the [getting started tutorial](https://github.com/scailable/sclbl-tutorials/blob/master/README.md)."""
```

And now, we are ready to use the `sclblpy` package to deploy the model:

```python
# Import the package
import sclblpy as sp

# Upload the model to transpile to WASM and make available
sp.upload(lm, fv, docs=docs)
```
Which, after prompting for your username and password, provides the following response:

```
> Please provide your username: *******@scailable.net
> Please type your password: ········
> Would you like us to store your user credentials (y/n)? y
> Your model was successfully uploaded to Scailable!
> NOTE: After transpiling, we will send you an email and your model will be available at https://admin.sclbl.net.
> Or, alternatively, you can use the 'endpoints()' function to list all your uploaded models. 

```

And again, you [wait](https://www.youtube.com/watch?v=9JVNMmsN3Co). Although, this time it likely takes less than a few minutes... 

> **NOTE:** For more examples using the `sclblpy` package please read the docs at [https://github.com/scailable/sclblpy](https://github.com/scailable/sclblpy).

<a name="confirmation-email"></a>
## Confirmation email
So, we have now uploaded our first model to [Scailable](https://www.scailable.net). After running `sp.upload()` the fitted model is actually send to our servers where we parse the model, convert it to [WebAssembly](#wasm) such that it is super fast and portable, and we open up a REST endpoint. This takes a bit of time as we go through a bunch of automatic tests in the process, but once its done you will receive a mail like this:

![Successful conversion email](resources/images/5-endpoint-ready-email.png "Successful conversion email")

Clicking the shiny blue button takes us directly to an example webpage where we can test the endpoint. You can give it a spin yourself [here](https://admin.sclbl.net/run.html?cfid=83073f32-b2db-11ea-a47d-9600004e79cc&exin=%5B%5B2%2C%205%5D%5D#a).

## What happens under the hood?

Before exploring the uploaded model in more detail, it's good to know what happens under the hood. Running `sp.upload(lm, fv, docs=docs)` was super simple, but what actually happened? Effectively, the following happened:

1. On the client side, `sclblpy` has ran a number of checks on your fitted model, for example to see if the model is indeed fitted and if the example feature vector indeed produces a valid inference. 
2. From the client to our server, we subsequently checked the user credentials. The first time you are using `sclblpy` you are asked to provide your Scailable login credentials to make sure we associate your model with the right account.
3. Next, the fitted `python` model arrives at our *toolchain server*. This is where some magics happens. The toolchain server effectively:
	- unpacks the model package,
	- runs a bunch of additional tests,
	- *Transpiles* your model to [WebAssembly](https://webassembly.org),
	- runs more tests
	- uploads the model to your account,
	- and finally opens up a REST endpoint where you can consume your model.
4. When all this has finished, we will send you a confirmation email to indicate that you are good to go! 

So, although you might receive your endpoint confirmation email within minutes, a lot has actually happened!

> **NOTE:** You can learn more about WebAssembly and how we use it by checking our [create your own WASM](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-create-your-own-wasm) tutorial.

<a name="wasm"></a>
### A note on WASM

We understand that step 3 in the above process might be a bit unfamiliar to most readers. Why do we "transpile to WebAssembly" (or shorthand *WASM*)? Well, because by transpiling to WebAssembly we make your model magnitudes smaller, and magnitudes faster. This allows us to run you model extremely efficiently on our machines, such that the REST endpoints we open up for you are **truly production ready**. Read more about WebAssembly [here](https://webassembly.org).

Interestingly, the transpiling gives you more cool things pretty much for free: you can now download the resulting WASM binary from Scailable, and use it to run the model you just created not just via REST, but also in browsers or on IoT devices. Effectively, transpiling to WASM liberates your ML model! Pretty cool stuff.

## Inspecting the created endpoint

After this small digression let's get back to the task at hand: let's have a look at the created endpoint. First, we go to [https://admin.sclbl.net/settings.html](https://admin.sclbl.net/settings.html) again, which now looks like this:

![Endpoint list](resources/images/5-demo-list.png "Endpoint list")

Yay, our model is listed! We can expand it and look at the documentation we provided:

![Docs 1](resources/images/5-demo-docs1.png "Docs 1")

And yes, we can click on the [Example task: 83073f32-b2db-11ea-a47d-9600004e79cc.](https://admin.sclbl.net/run.html?cfid=83073f32-b2db-11ea-a47d-9600004e79cc&exin=%5B%5B2%2C%205%5D%5D#a) link to get to:

![Task example](resources/images/5-demo-task.png "Task example")

And, we can now again test our model by simply pressing RUN:

![Task done example](resources/images/5-demo-task-done.png "Task done example")

> **NOTE:** The links provided in this document are to our "open" try out pages; to run your own tasks you  will need to log in using your credentials.

<a name="integrating"></a>
## Integrating the endpoint
We provide a number of tools to easily integrate your deployed model into your application. At the bottom of the test page, you can easily copy-paste the code to integrate the model in projects using various languages:

![Copy code example](resources/images/5-demo-task-copy.png "Task copy example")

After clicking the "copy current code to clipboard" we can easily consume the endpoint using various tools. For example, after copying the `cURL` code by selecting it from the dropdown it is easy to generate inferences in your terminal:

![Copy code curl](resources/images/5-demo-task-curl.png "Task copy curl")

> **NOTE:** The response when executing a task is a `json` string that contains multile fields. The `result` field will contain the requested inference, while the `statusCode` can be used to check whether the task was executed successfully. If `statusCode == 1` the result will be in the `result` field. If `statusCode == 0` an error occured, while if `statusCode == 5` the task takes to long to return directly, and the result can be downloaded at `resultUrl` when its done.

## Using the endpoint directly from python

Next to copy-pasting the code in the admin to consume your endpoint, you can also consume an endpoint using the `sclblpy` package. As long as you have `sclblpy` installed, you can run the following code:

```python
from sclblpy import run

cfid = "83073f32-b2db-11ea-a47d-9600004e79cc"  
fv = [1,2]
result = run(cfid, fv)

print(result) 
```
(where you would obviously change the `cfid` and the `fv` to match your uploaded model.

You can find the documentation for `sclblpy` [here](https://pypi.org/project/sclblpy/).


# 6. Wrap up

The steps above show the main functionality of Scailable, but in any reasonable application you would probably like a nice user interface to the model (or otherwise include your deployed model in your own application): let us know if we can help you create one for your model!



----------

Thanks for your attention! Let us know if you have any suggestions please let us know by [creatinging a new issue](https://github.com/scailable/sclbl-tutorials/issues/new) or emailing us at [go at scailable dot net](mailto:go@scailable.net).

If you find any mistakes in our tutorials, please do [add an issue](https://github.com/scailable/sclbl-tutorials/issues/new) so we can fix it asap!







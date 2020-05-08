# Scailable demos
> Last updated 08-05-2020.

In this public repository we gather all tutorials that describe the the use of Scailable services. 

## Tutorials

* [sclbl-101-getting-started](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-101-getting-started): A step-by-step explanation of the use of Scailable. This tutorial shows how to sign up for a *beta* account, and how to create a first Scailable endpoint using the `sclblpy` package. The tutorial ends with a [simple UI](https://www.scailable.net/demo/salary) that consumes a fitted `xgboost` model. 
* [sclbl-create-your-own-wasm](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-create-your-own-wasm): This tutorial shows how to create your own custom WebAssembly executable using `c` (and the [wasienv](https://medium.com/wasmer/wasienv-wasi-development-workflow-for-humans-1811d9a50345) toolchain) that can be deployed on the Scailable platform.

## Interactive demos
Next to the tutorials presented in this repository, we also have a number of interactive demos:

1. [Predicting a developers salary](https://www.scailable.net/demo/salary). Based on the most recent [Stack Overflow](https://insights.stackoverflow.com/survey/2019) survey, we created a simple model to predict the yearly salary of developers; give it [a spin](https://www.scailable.net/demo/salary/)! This simple front-end supports our getting started tutorial: [Scailable 101: Getting started](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-101-getting-started).
2. [Scailable supports running complex models](https://www.scailable.net/demo/avm/) (such at [Bayesian Additive Regression Trees](https://projecteuclid.org/euclid.aoas/1273584455)) in the cloud, on the edge, or on a browser. Check how we can flexibly generate posterior predictive inferences for automatic property valuation models, anytime, anywhere.
3. [Sometimes what you need is performance](https://www.scailable.net/demo/bench/). We provide nothing less. The inferences from our models are extremely fast; check out some of our benchmarks.
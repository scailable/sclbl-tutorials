# Scailable Frequently asked questions
> Admittedly, some are more frequently asked than others, but we hope the answers are useful!

We split our FAQ up into a few parts:

* [Questions about Scailable services in general; what do we do?](#general)
* [Questions about our python package `sclblpy`](#sclblpy)
* [Questions about manual uploads of WASI / WASM files](#wasi-upload)
* [Questions about running models on the edge](#edge)
* [Questions about our roadmap](#roadmap)
* ["Enterprise" questions (i.e. "We are a big company, can we get special things?")](#enterprise)

<a name="general"></a>
## Scailable services

  1. <b>What do you guys do?</b> We allow user to upload algorithms (at this point in time mainly fitted machine learning models, see the list [here](https://pypi.org/project/sclblpy/)) to our platform which we automatically transpile (i.e., translate / rebuild) to [WebAssembly](https://webassembly.org). Transpiling to WebAssembly (or WASM) makes the algorithm smaller, faster, and more portable. Thus, we allow you to create faster ML / AI inferences from your fitted models. Next, we host the resulting `.wasm` binaries on our servers allowing you to use them via simple REST calls. For a detailed description of the functionality and agreements in our [**beta** program](https://admin.sclbl.net/signup.html?access-code=GITHUB-FAQ) see our [getting started tutorial](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-101-getting-started).
  2. <b>Why is transpiling models to WASM useful?</b> For various reasons: WASM is fast (read, less latency in production, lower costs), small (again, less latency, lower cost), and portable (it can run on servers, in the browser, and on the edge). Thus, after compiling to WASM your model has true production performance and is fully portable to deploy where you need it.
  3. <b>How much faster can things get?</b> Well, compared to relatively standard deployment solutions, such as running a model in a [docker container](https://towardsdatascience.com/deploying-a-scikit-learn-model-on-aws-using-sklearn-estimators-local-jupyter-notebooks-and-the-d94396589498), often magnitudes faster. Here are some [benchmarks](https://www.scailable.net/demo/bench/) that might be interesting. 
  4. <b>Where can I run my models?</b> Due to the great products developed by our friends at [wasmer](https://wasmer.io), virtually anywhere. You can include `.wasm` binaries in any software project. You can run `.wasm` binaries in the cloud (we will host them for you), on your own machines, in a web browser, or event on the smallest IoT devices.
  5. <b>How can I use Scailable services?</b> Currently, you can apply for our [**beta** program](https://admin.sclbl.net/signup.html?access-code=GITHUB-FAQ). Once your application is accepted you can use [the `sclblpy` python package](https://pypi.org/project/sclblpy/) to transpile models directly from your `python` workflow. Please see our [getting started tutorial](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-101-getting-started) for details. 
  6. <b>Is this free?</b> Nope. Sorry. However, if you sign up for our [**beta** program](https://admin.sclbl.net/signup.html?access-code=GITHUB-FAQ) the first 50 &euro; worth of compute is on us. So yeah, effectively you can get started for free.

<a name="sclblpy"></a>
## The `sclblpy` python package

  1. <b>Where can I get the `sclblpy` package?</b> [here](https://pypi.org/project/sclblpy/). (some questions are surprisingly easy to answer)
  2. <b>Do I need an account to use the `sclblpy` package?</b> Yes. You can sign up for one [here](https://admin.sclbl.net/signup.html?access-code=GITHUB-FAQ).
  3. <b>How do I upload a model?</b> We currently support two methods of uploading models. First, you can use [the `sclblpy` python package](https://pypi.org/project/sclblpy/) to upload models directly from your `python` workflow. Next, you can manually create your own `.wasm` binary (for example, by following in [our tutorial on creating binaries from scratch](https://github.com/scailable/sclbl-tutorials/blob/master/sclbl-create-your-own-wasm/README.md)) and upload it using our [admin interface](https://admin.sclbl.net/upload.html). In the `sclblpy` package uploading a model is super easy: `sp.upload(model, feature_vector, docs)`. That's it.
  4. <b>Which models do you support?</b> During our [**beta** program](https://admin.sclbl.net/signup.html?access-code=GITHUB-FAQ) we support most (but not all) of `sklearn`, `xgboost`, and `statsmodels`; you can find a complete list [here](https://pypi.org/project/sclblpy/).
  5. <b>Can I replace an uploaded model?</b> Yes, you can use `sp.update(mod, fv, cfid, docs)` from `sclblpy`, or use the web admin to replace an existing `.wasm` binary. 
  6. <b>How can I use my uploaded model?</b> This is actually super simple! You can just consumer your model using simple REST calls. After using `sp.upload()` we will make your `.wasm` binary available and provide you with code examples for using the binary. Here is a simple [example](https://admin.sclbl.net/run.html?cfid=45017963-8536-11ea-9efc-9600004e79cc&exin=%5B%5B0.0,%201.0,%200.0,%200.0,%201.0,%200.0,%200.0,%201.0,%201.0,%200.0,%200.0,%200.0,%203.0,%201.0,%200.0,%200.0,%200.0,%2028.0,%200.0,%201.0,%200.0%5D%5D). Once your binary is available it is easy to just copy and paste the code you need to use it!

<a name="wasi-upload"></a>
## Manual WASI / WASM uploads

  1. <b>What is this WASM thing exactly?</b> Some questions are harder than you might imagine. You can read all about WebAssembly [here](https://webassembly.org) where it is defined as _"WebAssembly (abbreviated Wasm) is a binary instruction format for a stack-based virtual machine. Wasm is designed as a portable target for compilation of high-level languages like C/C++/Rust, enabling deployment on the web for client and server applications."_ However, technically, we actually use [WASI](https://wasi.dev); see [this post by Lin Clark](https://hacks.mozilla.org/2019/03/standardizing-wasi-a-webassembly-system-interface/) for more details.
  2. <b>Can I upload any `.wasm` binary to Scailable?</b> Well, yes, but most will not work so we would argue against that. If you want us to host your binary, it should [expose the right functions](https://github.com/scailable/sclbl-tutorials/blob/master/sclbl-create-your-own-wasm/README.md#exported_functions).
  3. <b>Is a `.wasm` binary secure?</b> [Yes](https://webassembly.org/docs/security/). 
  4. <b>I want to learn more about WASI / WASM, where should I go?</b> Follow [Lin Clark](https://twitter.com/linclark). Check what the nice people at [wasmer](https://wasmer.io) are up to, and [follow the WebAssembly community](https://www.w3.org/community/webassembly/). Obviously, [follow us](https://twitter.com/scailable) and keep updated by [watching this repo](https://github.com/scailable/sclbl-tutorials).
  4. <b>Can I upload my binaries programmatically?</b> Yes you can. Please see our [API docs](https://docs.sclbl.net) for details.

<a name="edge"></a>
## Running models on the edge

  1. <b>Where can I run a Scailable `.wasm` binary?</b> Well, during our [**beta** program](https://admin.sclbl.net/signup.html?access-code=GITHUB-FAQ) we will run it for you, on our servers. You can use it using simple REST calls. However, you can download your `.wasm` binary and use the runtimes provided by [wasmer](https://wasmer.io) to run it virtually anywhere. Even on the [tiniest of devices](https://www.scailable.net/demo/bench/).
  2. <b>Is it hard to use `.wasm` binaries?</b> Nope. It might take a bit of fiddling around, but [there are plenty of tools](https://wasmer.io) to make it easy.
  3. <b>Why is it useful to run models on the edge?</b> Many use cases exist. For example, you might want to endow your drone with a neural network that recognizes objects; that is easy. And, using `.wasm` binaries for deployment, you can also easily update your model and run it on all kinds of devices. Running on the edge in this cases speeds up execution and saves bandwidth. You might also want to run a model in a web browser; this could greatly improve the user-experience of your website as you limit latency. Or, you might want to make sure that your data does not leave the compound: in a medical setting it might be preferable to send a model to a client as opposed to sending data to a server. All of this is possible using AI / ML models transpiled to `.wasm` binaries.

<a name="roadmap"></a>
## Our roadmap

  1. <b>I love what you do, can you tell me what's coming up next?</b> Yes, we can. In our current [**beta** program](https://admin.sclbl.net/signup.html?access-code=GITHUB-FAQ) you can use the `sclblpy` package to transpile `sklearn`, `xgboost` and `statsmodels` models and we will host them on our servers. Our next step will be supporting (manual) [ONNX uploads](https://onnx.ai), thus greatly extending the types of models (and pipelines) we will be able to transpile. Next, we will add `sklearn.pipeline`, `tensorflow`, `keras`, and `pytorch` support to the `sclblpy` package. And, we will also release our `[R]` package to support users working in `[R]`. In parallel we will be extending the runtimes that we are offering to make sure that your model can indeed run anywhere, anytime. 
  2. <b>Will you support... `{_blank}` soon?</b> See above. If your requested feature is not listed, just [add a feature request](https://github.com/scailable/sclbl-tutorials/issues/new).

<a name="enterprise"></a>
## Enterprise questions

  1. <b>Can you help us get going?</b> Yes we can. Shoot us a message at [go@scailable.net](go@scailable.net) and we will get back to you as soon as possible. We can help putting pretty much any functionality in production using WebAssembly.
  2. <b>I need `{monitoring, experimenting, training, ...}`, do you guys support this?</b> Some if it we do support, but not (yet) in our [**beta** program](https://admin.sclbl.net/signup.html?access-code=GITHUB-FAQ-ENT). Send us a message at [go@scailable.net](go@scailable.net) and we will discuss possibilities.
  3. <b>I want a business account, where do I get it?</b> Although they are notoriously hard to get these days, you can start by contacting us at [go@scailable.net](go@scailable.net) and explaining what you would like to do. We will try to facilitate.
  4. <b>We would like to run Scailable services internally.</b> Technically this does not qualify as a question really. Assuming that you mean _"Can I run Scailable services internally?"_ the answer is easy: That's definitely possible. Please do [send us a message](go@scailable.net) and we will make it work!
  5. <b>Can you help me do my data science?</b> Probably yes, but we are not a DS consultancy. If you want someone to help you setup your data collection infrastructure or analyze your existing data and create a super nice PowerPoint describing precision and recall, that's not us. If you want to move models into production that's were we can help. Obviously, if we are collaborating, we will also help improving your models. So, if that's what you want, [let us know](go@scailable.net).

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

  1. <b>What do you guys do?</b> We allow user to upload algorithms (at this point in time mainly fitted machine learning models, see the list [here](https://pypi.org/project/sclblpy/)) to our platform which we automatically transiple (i.e., translate / rebuild) to [WebAssembly](https://webassembly.org). Transpiling to WebAssembly (or WASM) makes the algorithm smaller, faster, and more portable. Thus, we allow you to create faster ML / AI inferences from your fitted models. Next, we host the resulting `.wasm` binaries on our servers allowing you to use them via simple REST calls. For a detailed description of the functionality and agreements in our [**beta** program](https://admin.sclbl.net/signup.html) see our [terms](https://github.com/scailable/sclbl-tutorials/tree/master/terms).
  2. <b>Why is transpiling models to WASM useful?</b> For various reasons: WASM is fast (read, less latency in production, lower costs), small (again, less latency, lower cost), and portable (it can run on servers, in the browser, and on the edge). Thus, after compiling to WASM your model has true production performance and is fully portable to deploy where you need it.
  3. <b>How much faster can things get?</b> Well, compared to relatively standard deployment solutions, such as running a model in a [docker container](), often magnitudes faster. Here are some [benchmarks](https://www.scailable.net/demo/bench/) that might be interesting. 
  4. <b>Where can I run my models?</b> Due to the great products developed by our friends at [wasmer](https://wasmer.io), virtually anywhere. You can include `.wasm` binaries in any software project. You can run `.wasm` binaries in the cloud (we will host them for you), on your own machines, in a web browser, or event on the smallest IoT devices.
  5. <b>How can I use Scailable services?</b> Currently, you can apply for our [**beta** program](https://admin.sclbl.net/signup.html). Once your application is accepted you can use [the `sclblpy` python package](https://pypi.org/project/sclblpy/) to transpile models directly from your `python` workflow. Please see our [getting started tutorial](https://github.com/scailable/sclbl-tutorials/tree/master/sclbl-101-getting-started) for details. 
  6. <b>Is this free?</b> Nope. Sorry. However, if you sign up for our **beta** program](https://admin.sclbl.net/signup.html)  the first 50 &euro; worth of compute is on us. So yeah, effectively you can get started for free.

<a name="sclblpy"></a>
## The `sclblpy` python package

  1. <b>Where can I get the `sclblpy` package?</b> [here](https://pypi.org/project/sclblpy/). (some answers are surprisingly easy to answer)
  2. <b>Do I need an account to use the package?</b> Yes. You can sign up for one [here](https://admin.sclbl.net/signup.html?access-code=GITHUB-FAQ).
  3. <b>How do I upload a model?</b> We currently support two methods of uploading models. First, you can use [the `sclblpy` python package](https://pypi.org/project/sclblpy/) to upload models directly from your `python` workflow. Next, you can manually create your own `.wasm` binary (for example, by following in [our tutorial on creating binaries from scratch](https://github.com/scailable/sclbl-tutorials/blob/master/sclbl-create-your-own-wasm/README.md)) and upload it using our [admin interface](https://admin.sclbl.net/upload.html). In the `sclblpy` package uploading a model is super easy: `sp.upload(model, feature_vector, docs)`. That's it.
  4. <b>Which models do you support?</b> During our **beta** we support most (but not all) of `sklearn`, `xgboost`, and `statsmodels`; you can find a complete list [here](https://pypi.org/project/sclblpy/).
  5. <b>Can I replace an uploaded model?</b> Yes, you can use `sp.update(mod, fv, cfid, docs)` from `sclblpy`, or use the web admin to replace an existing `.wasm` binary. 
  6. <b>How can I use my uploaded model?</b> This is actualy super simple! You can just consumer your model using simple REST calls. After using `sp.upload()` we will make your `.wasm` binary available and provide you with code examples for using the binary. Here is a simple [example](https://admin.sclbl.net/run.html?cfid=45017963-8536-11ea-9efc-9600004e79cc&exin=%5B%5B0.0,%201.0,%200.0,%200.0,%201.0,%200.0,%200.0,%201.0,%201.0,%200.0,%200.0,%200.0,%203.0,%201.0,%200.0,%200.0,%200.0,%2028.0,%200.0,%201.0,%200.0%5D%5D). Once your binary is available it is easy to just copy and paste the code you need to use it!

<a name="wasi-upload"></a>
## Manual WASI / WASM uploads

  1. <b>What is this WASM thing exactly?</b>
  2. <b>Can I upload any `.wasm` binary to Scailable?</b>
  3. <b>Is the resulting file secure?</b>
  4. <b>I want to learn more about WASI / WASM, where should I go?</b>

<a name="edge"></a>
## Running models on the edge

  1. <b>Where can I run a Scailable `.wasm` binary?</b>
  2. <b>Is it hard to use `.wasm` binaries?</b>
  3. <b>Why is it usefull to run models on the edge?</b>

<a name="roadmap"></a>
## Our roadmap

  1. <b>I love what you do, can you tell me what's coming up next?</b>
  2. <b>Will you support... `{_blank}` soon?</b>

<a name="enterprise"></a>
## Enterprise questions

  1. <b>Can you help us get going?</b>
  2. <b>I need `{monitoring, experimenting, training, ...}`, can you guys support this?</b>
  3. <b>I want a business account, where do I get it?</b>
  4. <b>We would like to run Scailable services internally.</b>
  5. <b>Can you help me do my data science?</b>

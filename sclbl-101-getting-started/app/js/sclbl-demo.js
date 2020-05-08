/*
 * Scailable salary demo
 * 
 * Very simple file to execute a REST call to a scailable endpoint.
 */

 "use strict";
var sclblmod = (function (sclbl) {

    var endpointUrl = "https://taskmanager.sclbl.net:8080/task/45017963-8536-11ea-9efc-9600004e79cc";

    $(document).ready(function() {

        /* button handler */
        $(document).on('click','#demo-run-button', function() {

            $('#js-feedback').html("");
            $("#feedback-conclusion").html("");
            main();
        });

    });


    async function main(){

        var f_open = +$('#demo-f_open').is(':checked');
        
        var f_employed = 0;
        var f_selfemployed = 0;
        var f_unemployed = 1;
        switch($('#demo_f_employed').val()){
            case "employed":
                f_employed = 1;
                break;
            case "self":
                f_selfemployed = 1;
                break;
            case "unemployed":
                f_unemployed = 1;
        }
        
        var f_education = parseInt($('#demo_f_education').val());

        var f_organization = +$('#demo-f_organization').is(':checked');

        var f_datascientist = +$('#demo-f_datascientist').is(':checked');
        var f_designer = +$('#demo-f_designer').is(':checked');
        var f_developer = +$('#demo-f_developer').is(':checked');
        var f_devops = +$('#demo-f_devops').is(':checked');
        var f_engineer = +$('#demo-f_engineer').is(':checked');
        var f_scientist = +$('#demo-f_scientist').is(':checked');

        var f_years = parseInt($('#demo-f_years').val()) || 0; 
        var f_yearspro = parseInt($('#demo-f_yearspro').val()) || 0;

        var f_ambition = +$('#demo-f_ambition').is(':checked');

        var f_python = +$('#demo-f_python').is(':checked');
        var f_r = +$('#demo-f_r').is(':checked');

        var f_age = parseInt($('#demo-f_age').val()) || 0;

        var f_female = 0;
        var f_male = 0;
        var f_other = 0;
        switch($('#demo_f_gender').val()){
            case "female":
                f_female = 1;
                break;
            case "male":
                f_male = 1;
                break;
            case "other":
                f_other = 1;
        }

        var feature_vector = [
            f_open,
            f_employed,
            f_selfemployed,
            f_education,
            f_organization,
            f_datascientist,
            f_designer,
            f_developer,
            f_devops,
            f_engineer,
            f_scientist,
            f_years,
            f_yearspro,
            f_ambition,
            f_python,
            f_r,
            f_age,
            f_female,
            f_male,
            f_other
        ]

        sclbl.input = {
            "content-type": "json",
            "location": "embedded",
            "data": "{\"input\": [" + JSON.stringify(feature_vector) + "]}"
        };


        sclbl.output = {
            "content-type": "json",
            "location": "echo"
        };

    
        pr("<span id='input'></span>");
        await type(sclbl.input.data, "input", 30);
        
        pr("<span id='arrow'></span>");
        await type("....", "arrow", 30);
            

        let taskrequest = await ts_run_demo(endpointUrl, sclbl.input, sclbl.output);
        if (taskrequest !== "Error") {
            let message = JSON.parse(taskrequest).message;
            pr(message);

            let result = JSON.parse(message)
            $("#feedback-conclusion").html("Someone with your profile would make about <b>" + numberWithCommas(parseFloat(result.output).toFixed(0)) + "</b> USD a year!");
        } else {
            pr("Error: Was not able to complete request.", "red");
            return false;
        }

    }

    // Function calling task server -------------------------------------------------------------------
    async function ts_run_demo(url, input, output) {

        let myHeaders = new Headers();
        myHeaders.append("Content-Type", "application/x-www-form-urlencoded");

        let raw = JSON.stringify(
            {
                input: sclbl.input,
                output: sclbl.output,
                control: 1,
                properties: {
                    language: "WASM",
                    profit: 0.5,
                    cycles: 1
                }
            }
        );

        let requestOptions = {
            method: 'POST',
            headers: myHeaders,
            body: raw,
            redirect: 'follow'
        };

        // noinspection JSUnusedLocalSymbols
        return fetch(url, requestOptions)
            .then(response => {
                if (!response.ok) {
                    throw response
                }
                return response.text()
            })
            .then(text => {
                return (text)
            })
            .catch(err => {
                return ("Error")
            })
    }

    // Helper functions ------------------------------------------------------------------------
    function pr(str, color = "black") {
        let fb_selector = document.querySelector('#js-feedback').innerHTML;
        str = str.fontcolor(color);
        document.querySelector('#js-feedback').innerHTML = fb_selector + "<br />" + str + "<br />";
    }

    // just for fun: typing - feel free to remove ;)
    function type(message, id, speed = 30) {
        let output = document.getElementById(id);
        let i = 0;
        message.split("").forEach(function (letter) {
            setTimeout(function () {
                output.innerHTML += letter;
            }, i++ * speed);
        });
        return new Promise(resolve => setTimeout(resolve, i * speed));
    }

    // sleep/wait functionality
    function wait(ms) {
        return new Promise(resolve => setTimeout(resolve, ms));
    }

    // add comma in printing
    function numberWithCommas(x) {
        return x.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
    }

    return sclbl;

}(jQuery));










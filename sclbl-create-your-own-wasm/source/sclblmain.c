/*

    <https://github.com/sclbl/sclbl-minimal-c>

    MIT License

    Copyright (c) [2020] [Scailable]

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

*/

// IMPORTANT:
// To export a function to WASM, make sure to set its function declaration's "used" attribute
# define EXPORT __attribute__((used));

// Include what we need (including our sclblutils)
#include <stdint.h>
#include <stdlib.h>
#include "sclblutil.h"

//  Initialize pointer(s) to position and length of input an output json strings in wasm linear (heap) memory
static int32_t *in_loc = NULL;
static int32_t *out_loc = NULL;
static int32_t out_len = 0;

// Potentially instantiate vars in main(), as it is automatically called by WASI _start() before any other function.
// We simple return EXIT_SUCCESS in this example
int main() {
    return EXIT_SUCCESS;
}

// malloc_buffer returns the location of the available memory of a specific 
//  length that can be used by the runtime to write the input-data
int32_t *malloc_buffer(int32_t length) EXPORT;
int32_t *malloc_buffer(int32_t length) {
    in_loc = (int32_t *) malloc(length * sizeof(uint8_t));
    return in_loc;
}

// pred is the function that is called by the Scailable runtime to execute the actual functionality
// Note that this function is actively exported using the EXPORT declaration.
int pred() EXPORT;
int pred() {

    // First, we retrieve input string at in_loc
    // if none exists we exit
    const char *in_str;
    if (in_loc != NULL) {
        in_str = (char *) in_loc;
    } else {
        return EXIT_FAILURE;
    }

    // Next, we strip the input string of all characters but 1234567890,-
    const char *remove = "1234567890,-";
    str_clean(in_str, remove);

    // We subsequently pass the cleaned string to the sum function (defined below),
    int x = sum((char *) in_loc);

    // and convert the resulting int to a string.
    unsigned char *outstr = local_itoa(x);

    // Next, we create a nice output json
    char *out_str = str_concat(3, "{\"output\": [", outstr, "]}");

    // And finally we store, in the pointers we initialized earlier, the
    // location and length of the output.
    out_loc = (int32_t *) out_str;
    out_len = stringlength(out_str);

    // Done!
    return EXIT_SUCCESS;
}



// sum takes a string containing integers and commas (i.e., 1,5,3,6,...)
//  and adds all the integers. This is the core functionality of our 
//  example.
int sum(const char *str) {
    int sum = 0;
    for (;;) {
        char *p;
        int n = strtol(str, &p, 10);
        if (p == str)
            break;
        sum += n;
        str = p + strspn(p, ", ");
    }
    return sum;
}

// get_out_len retrieves output-data length
int32_t get_out_len() EXPORT;
int32_t get_out_len() {
    return out_len;
}

// get_out_loc retrieves the location of the output-data
int32_t *get_out_loc() EXPORT;
int32_t *get_out_loc() {
    return out_loc;
}

// free_buffer frees the allocated input and output memory
void free_buffer(int32_t *p) EXPORT;
void free_buffer(int32_t *p) {
    free(p);
    p = NULL;
}



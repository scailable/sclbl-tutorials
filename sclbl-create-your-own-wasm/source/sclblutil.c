/*

    <https://github.com/sclbl/sclbl-demos/>

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

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

#include "sclblutil.h"

// str_concat concatenates all the arguments passed to it into one
//  single string. We use this to build up the output-data json
//  object.
char *str_concat(int num_args, ...) {
    int strsize = 0;
    va_list ap;
    va_start(ap, num_args);
    for (int i = 0; i < num_args; i++)
        strsize += stringlength(va_arg(ap, char * ));

    char *res = (char *) malloc(strsize + 1);
    strsize = 0;
    va_start(ap, num_args);
    for (int i = 0; i < num_args; i++) {
        char *s = va_arg(ap, char * );
        strcpy(res + strsize, s);
        strsize += stringlength(s);
    }
    va_end(ap);
    res[strsize] = '\0';
    return res;
}

// local_itoa converts integers to strings
unsigned char *local_itoa(int x) {
    unsigned char *s;
    size_t len;
    unsigned n;
    int negative;

    negative = x < 0;
    n = negative ? 0 - (unsigned) x : (unsigned) x;
    len = local_uintlen(n) + negative + 1;
    if (!(s = (unsigned char *) malloc(len)))
        return (NULL);

    s[--len] = '\0';
    if (negative)
        s[0] = '-';
    do {
        s[--len] = (n % 10) + '0';
        n /= 10;
    } while (n);
    return (s);
}

// local_uintlen retrieves the length of an unsigned interger
//  and is used by local_itoa().
size_t local_uintlen(unsigned n) {
    size_t len = 0;
    do {
        ++len;
        n /= 10;
    } while (n);
    return len;
}

// str_clean removes all invalid characters from a string
//  we use this to only retrieve the digits and commas in the
//  input string.
void str_clean(const char *src, const char *valid_characters) {
    char *dst = (char *) src;
    while (*src) {
        if (strchr(valid_characters, *src)) *dst++ = *src;
        src++;
    }
    *dst = '\0';
}

// stringlength returns the length of a string.
size_t stringlength(const char *s){
    size_t i = 0;
    while(s && *s != '\0'){
        s++;
        i++;
    }
    return i;
}

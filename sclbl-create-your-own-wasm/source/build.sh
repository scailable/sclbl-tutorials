# !/bin/bash

# There are several ways to compile to wasm: clang, emcc, wasienv (a clang wrapper) and others.
# Here, we use wasicc from https://github.com/wasienv/wasienv

# Install using curl https://raw.githubusercontent.com/wasienv/wasienv/master/install.sh | sh
# ..and compile by running the command below.

#==============================================================================================#
#                compile c to wasm                                                             #
#==============================================================================================#

  # sclblmain.c sclblutil.c         # c code
  # -w                              # disable all diagnostics.
  # -O3                             # compiler optimization type 3
  # -fno-exceptions                 # lose the exceptions - they are not supported by wasm
  # -Wl,--export-all                # export all functions
  # -o sclbl.wasm                   # compile to sclbl.wasm

wasicc   sclblmain.c sclblutil.c    \
         -w                         \
         -O3                        \
         -fno-exceptions            \
         -o sclbl.wasm

#        -Wl,--export-all          # optional compiler directive, exports *all* functions.

#==============================================================================================#
#                optional post-compilation commands                                            #
#==============================================================================================#

# check largest functions:
# twiggy top -n 20 sclbl.wasm

# strip unnecessary functions:
# wasm-strip sclbl.wasm

# optimize model:
# wasm-opt -O3 -o sclbl.wasm sclbl.wasm

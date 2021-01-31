#!/bin/sh
# Change this to where you placed your emscripten folder
EMSCRIPTEN_PATH=~/bin/emsdk/
EMSCRIPTEN_ENV_SCRIPT=emsdk_env.sh

EMSDK_KNOWN_GOOD_VERSION=2.0.13

# $EMSCRIPTEN_PATHemsdk install EMSDK_KNOWN_GOOD_VERSION
# $EMSCRIPTEN_PATHemsdk activate EMSDK_KNOWN_GOOD_VERSION

source $EMSCRIPTEN_PATH$EMSCRIPTEN_ENV_SCRIPT
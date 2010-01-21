#!/bin/bash

GEN='Xcode'

if [ "$1" = "examples" ]; then
    echo Building example projects
    cmake -D GEN="${GEN}" -D BUILD_EXAMPLES="YES" -P cmake/genproject.cmake
else
    echo Building projects
    cmake -D GEN="${GEN}" -P cmake/genproject.cmake
fi

if [ -f "cmake/patch_xcode.py" ]; then
    while read target proj
    do
        python cmake/patch_xcode.py -f "$proj" -t "$target"
    done < buildex/xcode_patch_desc.txt
fi
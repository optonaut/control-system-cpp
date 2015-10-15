#!/bin/bash

set -e

if [ ! -d "build" ]; then
    mkdir build
fi
cd build
cmake .. $@
make $MAKEOPTS 
cd ..

echo "Executing tests..."
build/tests/integral
build/tests/derivative
echo "Testing done."

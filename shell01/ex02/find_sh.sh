#!/bin/bash
find . -iname '*.sh' -exec basename {} \; | sed -e 's/\.sh//'
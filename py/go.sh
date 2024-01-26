#!/bin/bash
HEADER_1="../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/"
clang -c -Xclang -ast-dump -I../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/ -I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc -I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/ctrl/ include.c

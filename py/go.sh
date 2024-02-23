#!/bin/bash
HEADER_1="../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/"
#/nv-ioctl.h
clang -c -Xclang -ast-dump  -I../../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix/include -I../../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix -I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/alloc -I../../ide_cuda/open-gpu-kernel-modules/kernel-open/common/inc -I../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/ -I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc -I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/ctrl/ include.c

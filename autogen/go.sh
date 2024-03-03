#!/bin/bash
HEADER_1="../../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix/include"
HEADER_2="../../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix"
HEADER_3="../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/alloc"
clang -c -Xclang -ast-dump -I"$HEADER_1" -I"$HEADER_2" -I"$HEADER_3" -I../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/ -I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc -I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/ctrl/ include.c

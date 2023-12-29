#!/bin/bash -es
HEADER_PATH_1="../ide_cuda/open-gpu-kernel-modules/kernel-open/common/inc"
HEADER_PATH_2="../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix/include"
HEADER_PATH_3="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc"
HEADER_PATH_4="../ide_cuda/open-gpu-kernel-modules/kernel-open/common/inc"
nvcc primer.cu -o primer -lcuda  
clang intercept.c -shared -fPIC -ldl -I"$HEADER_PATH_1" -I"$HEADER_PATH_2" -I"$HEADER_PATH_3" -I"$HEADER_PATH_4" -o intercept.so  
LD_PRELOAD=./intercept.so ./primer
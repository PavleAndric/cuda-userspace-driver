#!/bin/bash -e
HEADER_PATH_1="../ide_cuda/open-gpu-kernel-modules/kernel-open/common/inc"
HEADER_PATH_2="../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix/include"
HEADER_PATH_3="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc"
HEADER_PATH_4="../ide_cuda/open-gpu-kernel-modules/kernel-open/common/inc"
HEADER_PATH_5="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/ctrl"
HEADER_PATH_6="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/ctrl/ctrl0000"
HEADER_PATH_7="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/ctrl/ctrl2080"
HEADER_PATH_8="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/ctrl/ctrl0080/"
HEADER_PATH_9="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/class/"

nvcc primer.cu -o primer -g -lcuda
clang intercept.c -g -Werror -shared -fPIC -ldl -I"$HEADER_PATH_1" -I"$HEADER_PATH_2" -I"$HEADER_PATH_3" -I"$HEADER_PATH_4" -I"$HEADER_PATH_5" -I"$HEADER_PATH_6" -I"$HEADER_PATH_7" -I"$HEADER_PATH_8" -I"$HEADER_PATH_9" -o intercept.so

LD_PRELOAD=./intercept.so ./primer

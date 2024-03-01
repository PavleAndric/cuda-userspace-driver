#!/bin/bash -e
HEADER_PATH_1="../ide_cuda/open-gpu-kernel-modules/kernel-open/common/inc"
HEADER_PATH_2="../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix/include"
HEADER_PATH_3="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc"
HEADER_PATH_4="../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/"
HEADER_PATH_5="../ide_cuda/open-gpu-kernel-modules/src/nvidia/interface/deprecated"

nvcc primer.cu -I"$HEADER_PATH_1" -I"$HEADER_PATH_3" -g -G -o primer -lcuda
clang++ intercept.cc -g -G -lineinfo -shared -fPIC -ldl -lstdc++ -I"$HEADER_PATH_1" -I"$HEADER_PATH_2"  -I"$HEADER_PATH_3" -I"$HEADER_PATH_4"  -I"$HEADER_PATH_5" -o intercept.so
LD_PRELOAD=./intercept.so ./primer
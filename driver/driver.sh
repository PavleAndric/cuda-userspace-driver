HEADER_PATH_1="../../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix/include"
HEADER_PATH_2="../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc"
HEADER_PATH_3="../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm"
HEADER_PATH_4="../../ide_cuda/open-gpu-kernel-modules/kernel-open/common/inc"

clang++ driver.cc  -I"$HEADER_PATH_1"  -I"$HEADER_PATH_2" -I"$HEADER_PATH_3" -I"$HEADER_PATH_4"  -o driver.o && ./driver.o
#LD_PRELOAD=./intercept.so ./driver.o
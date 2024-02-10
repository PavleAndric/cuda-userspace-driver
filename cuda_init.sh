HEADER_PATH_1="../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix/include"
HEADER_PATH_2="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc"
HEADER_PATH_3="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/class"


clang++ cuda_init.cc -G -shared -fPIC -ldl -I"$HEADER_PATH_1" -I"$HEADER_PATH_2" -I"$HEADER_PATH_3" -o cuda_init && ./cuda_init
LD_PRELOAD=./intercept.so ./cuda_init
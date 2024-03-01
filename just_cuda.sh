HEADER_PATH_1="../ide_cuda/open-gpu-kernel-modules/kernel-open/common/inc"
HEADER_PATH_2="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc"
nvcc primer.cu -I"$HEADER_PATH_1" -I"$HEADER_PATH_2" -g  -G -o primer -lcuda && ./primer
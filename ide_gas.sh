HEADER_PATH_1="../ide_cuda/open-gpu-kernel-modules/kernel-open/common/inc"
HEADER_PATH_2="../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/class/"
clang++ -g ide_gas.cc -Werror  -I"$HEADER_PATH_1" -I"$HEADER_PATH_2" -o ide_gas -lcuda  -lpthread && ./ide_gas
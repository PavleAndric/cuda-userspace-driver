Minimal CUDA user space portion of a GPU driver for TURING GeForce GTX 1650 Ti Mobile gpu.

Kernel driver: https://github.com/NVIDIA/open-gpu-kernel-modules.git

Useful: https://github.com/NVIDIA/open-gpu-doc.git

1. Initialize necessary objects (root, device, subdevice, etc...). cuInit
2. Create the command buffer, mappings for NV# and BAR. cuCtxCreate
3. Submit commands to the command buffer.
4. Ring the doorbell register.

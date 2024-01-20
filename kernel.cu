extern "C" __global__ void kernel(int *a, int *b, int *c)
{
    int tidX = blockIdx.x;    // X dimension of the grid
    int tidY = blockIdx.y;    // Y dimension of the grid
    int tid = tidY * blockDim.x * gridDim.x + tidX;  // Calculate the unique thread ID

    c[tid] = a[tid] + b[tid];
}
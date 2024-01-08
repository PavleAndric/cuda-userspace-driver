extern "C" __global__ void kernel(int *a, int *b, int *c , int *romcina)
{
    int tid = blockIdx.x;
    c[tid] = a[tid] + b[tid];
}
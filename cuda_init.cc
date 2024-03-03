#include<stdio.h>
#include<sys/ioctl.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stdint.h>
#include<assert.h>
#include<unistd.h>
#include<string.h> 
#include<dlfcn.h>

#include"nvos.h" 
#include"nv_escape.h" 
#include"nvtypes.h"
#include"nv-ioctl.h"
#include"nvCpuUuid.h"
#include"nv-unix-nvos-params-wrappers.h"
#include"uvm_linux_ioctl.h"
#include"uvm_ioctl.h"

#include "ctrl/ctrl0000/ctrl0000gpu.h"
#include "ctrl/ctrl0000/ctrl0000client.h"
#include "ctrl/ctrl2080/ctrl2080rc.h"
#include "ctrl/ctrl2080/ctrl2080gsp.h"
#include "ctrl/ctrl2080/ctrl2080gpu.h"
#include "ctrl/ctrl0080/ctrl0080fifo.h"
#include "ctrl/ctrl2080/ctrl2080gr.h"
#include "ctrl/ctrla06f/ctrla06fgpfifo.h"
#include "ctrl/ctrl2080/ctrl2080mc.h"
#include "ctrl/ctrlc36f.h"
#include "ctrl/ctrla06c.h"

#include "class/clc597.h"
#include "class/clc5c0.h"
#include "class/cl003e.h"
#include "class/clcb33.h"
#include "class/cl0080.h"
#include "class/cl2080.h"
#include "class/clc461.h"
#include "class/cl50a0.h"
#include "class/cl90f1.h"
#include "class/cl0070.h"
#include "class/cl0040.h"
#include "class/cl9067.h"
#include "class/cla06c.h"
#include "class/cl00c2.h"
#include "class/clc46f.h"
#include "class/clc46f.h"
#include "class/clc5b5.h"
#include "class/cl0005.h"
#include "class/clb0b5sw.h"

#include"helpers.h"
#include"novu.h"


  /////TODO: make all of this GENERIC!/////
  constexpr int N =  64; 
  /*.cu -> .ptx -> .cubin (SASS)*/
  uint32_t program[N] = {
    0x00017a02, 0x00000a00, 0x00000f00, 0x000fc400, 
    0x00067919, 0x00000000, 0x00002500, 0x000e2200, 
    0x00077802, 0x00000004, 0x00000f00, 0x000fc600, 
    0x00037919, 0x00000000, 0x00002100, 0x000e2400, 
    0x06067a24, 0x00000000, 0x078e0203, 0x001fc800, 
    0x06027625, 0x00005800, 0x078e0207, 0x000fc800, 
    0x06047625, 0x00005a00, 0x078e0207, 0x000fc800, 
    0x02027381, 0x00000000, 0x001ee900, 0x000ea800, 
    0x04057381, 0x00000000, 0x001ee900, 0x000ea200, 
    0x06067625, 0x00005c00, 0x078e0207, 0x000fe200, 
    0x02097210, 0x00000005, 0x07ffe0ff, 0x004fd000, 
    0x06007386, 0x00000009, 0x0010e900, 0x000fe200, 
    0x0000794d, 0x00000000, 0x03800000, 0x000fea00, 
    0x00007947, 0xfffffff0, 0x0383ffff, 0x000fc000, 
    0x00007918, 0x00000000, 0x00000000, 0x000fc000, 
    0x00007918, 0x00000000, 0x00000000, 0x000fc000
  };

  constexpr int M = 88; 
  uint32_t load_1[M] = { // 0x7fffcc100000
    0x0000000a, 0x00000001, 0x00000001, 0x00000001, 
    0x00000001, 0x00000001, 0xed000000, 0x00007fff,  
    0xeb000000, 0x00007fff, 0x00fffdc0, 0x00000000,  
    0x00000001, 0x00000000, 0x05408000, 0x00000002,  
    0xce220000, 0x00007fff, 0xce010000, 0x00007fff,  
    0x00000000, 0x00000000, 0x00000000, 0x00000000,  
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x02ee2efe, 0x00000000,  
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000001, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000010,
    0x00000000, 0x00000178, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x05800000, 0x00000002,  
    0xcfe3b300, 0x00007fff, 0x00000000, 0x00000000,  
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
  };
  /*fix this shit*/
  constexpr int O = 66;
  uint32_t load_2[O] ={
    0x00000000, 0x02054080, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000047f, 0x3c000000,
    0x00000000, 0x00000000, 0xffcfe3b3, 0x00000000,
    0x00000000, 0x44010000, 0x00000001, 0x00000001,
    0x00000001, 0x00000000, 0x00000000, 0x22240000,
    0x000a0023, 0x00010001, 0x00121083, 0x00000000,
    0x00000000, 0x03007f7c, 0x80000002, 0x00000006,
    0x00000000, 0x00000000, 0x00000000, 0x08000000,
    0x00000640, 0x7300127f, 0xce220000, 0x0c4c7fff,
    0xce010000, 0x04107fff, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0xce000000, 0x80007fff, 0xcfe3b300, 0x00007fff,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000
  };

NvU8 uud[16] = {0x9f,0xa6,0xcc,0x3,0x56,0xa2,0x1f,0x6b,0x26,0x26,0x8,0x90,0xb,0xbd,0xb4,0x94}; 

/* ioctl */
NvHandle alloc_object(int fd , NvHandle hroot ,NvHandle hObjectParent,NvV32 hClass ,NvP64 pAllocParams){
  
  NVOS21_PARAMETERS object = {.hRoot = hroot,.hObjectParent = hObjectParent,.hClass =hClass,.pAllocParms = pAllocParams,.paramsSize = 0};
  int res = ioctl(fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_ALLOC, sizeof(object)), &object);

  assert(object.status == 0);assert(res == 0);
  return object.hObjectNew;
}

void ctrl(int fd , NvHandle hClient,NvHandle hObject,NvV32 cmd,NvU32 flags,NvP64 params,NvU32 paramsSize){

  NVOS54_PARAMETERS parameters = {.hClient =hClient ,.hObject = hObject,.cmd = cmd,.flags = flags,.params = params ,.paramsSize = paramsSize};
  int res = ioctl(fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_CONTROL, sizeof(parameters)), &parameters);
  assert(parameters.status == 0);  assert(res == 0);
}

void init_uvm(int nv_uvm_fd){
  
  int nv_uvm_fd_2 = open64("/dev/nvidia-uvm", O_RDWR | O_CLOEXEC);

  UVM_INITIALIZE_PARAMS  uvm_init = {0}; uvm_init.flags = 0x0; 
  UVM_MM_INITIALIZE_PARAMS uvm_init_mm = {0}; uvm_init_mm.uvmFd = nv_uvm_fd;
  UVM_PAGEABLE_MEM_ACCESS_PARAMS uvm_i_pageble=  {0};

  int res_0 = ioctl(nv_uvm_fd, UVM_INITIALIZE, &uvm_init);
  int res_1 = ioctl(nv_uvm_fd_2, UVM_MM_INITIALIZE, &uvm_init_mm);
  int res_2 = ioctl(nv_uvm_fd, UVM_PAGEABLE_MEM_ACCESS, &uvm_i_pageble);

  assert(uvm_i_pageble.rmStatus == 0);assert(uvm_init.rmStatus == 0);assert(uvm_init_mm.rmStatus == 0);
  assert(res_0 == 0);assert(res_1 == 0);assert(res_2 == 0);
}

void second_uvm(int nv_uvm_fd){

  UVM_REGISTER_GPU_PARAMS register_ = {0}; register_.rmCtrlFd = -1;
  UVM_PAGEABLE_MEM_ACCESS_ON_GPU_PARAMS pagable = {0};
  UVM_CREATE_RANGE_GROUP_PARAMS range = {0};

  memcpy((void*)register_.gpu_uuid.uuid , (void*)uud ,sizeof(register_.gpu_uuid.uuid));
  memcpy((void*)pagable.gpu_uuid.uuid , (void*)uud ,sizeof(pagable.gpu_uuid.uuid));

  int res_0 = ioctl(nv_uvm_fd, UVM_REGISTER_GPU, &register_);
  int res_1 =  ioctl(nv_uvm_fd ,UVM_PAGEABLE_MEM_ACCESS_ON_GPU , &pagable);
  int res_2 =  ioctl(nv_uvm_fd ,UVM_CREATE_RANGE_GROUP , &range);

  assert(register_.rmStatus == 0);assert(pagable.rmStatus == 0);assert(range.rmStatus == 0);
  assert(res_0 == 0);assert(res_1 == 0);assert(res_2 == 0);
}

void uvm_external_range(uint64_t base, uint64_t lenght , NvHandle mappingObject , NvHandle root , int control_fd , int nv_uvm_fd){

  UVM_CREATE_EXTERNAL_RANGE_PARAMS rom_1 = {.base = base, .length = lenght};
  UVM_MAP_EXTERNAL_ALLOCATION_PARAMS rom_2 = {.base = base,.length = lenght, .gpuAttributesCount = 0x1 ,.rmCtrlFd = control_fd,.hClient = root ,.hMemory = mappingObject}; // imas jedan gpu
  memcpy((void*)rom_2.perGpuAttributes[0].gpuUuid.uuid , (void*)uud , sizeof(rom_2.perGpuAttributes[0].gpuUuid.uuid)); rom_2.perGpuAttributes[0].gpuMappingType = 0x1;

  int res_dumb_1 = ioctl(nv_uvm_fd, UVM_CREATE_EXTERNAL_RANGE ,&rom_1);
  int res_dumb_2 = ioctl(nv_uvm_fd, UVM_MAP_EXTERNAL_ALLOCATION ,&rom_2);

  assert(res_dumb_1 == 0);assert(rom_1.rmStatus == 0);
  assert(res_dumb_2 == 0);assert(rom_2.rmStatus == 0);
}
// ovo moze da bude boje 
void *map_object(int mapping_fd, int control_fd, NvHandle root, NvHandle device, NvHandle subDevice, NvHandle mappingObject , uint32_t mapFlags , uint32_t addrSpaceType ,uint32_t lenght, void* addr ,int not_mmap){

  void *res = NULL;
  NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS params ={ .hObject = mappingObject,.mapFlags = mapFlags};
  NVOS33_PARAMETERS p = {.hClient = root, .hDevice = subDevice,.hMemory = mappingObject, .length=lenght,.flags=mapFlags};
  nv_ioctl_nvos33_parameters_with_fd map_params = {.params = p ,.fd  = mapping_fd};

  ctrl(control_fd, root, root, NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE, 0 ,&params , sizeof(params));
  int res_map = ioctl(control_fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_MAP_MEMORY, sizeof(map_params)), &map_params);
  if (not_mmap == 1){res = mmap64(addr , lenght, PROT_READ|PROT_WRITE , MAP_SHARED|MAP_FIXED, mapping_fd, 0);}

  assert(map_params.params.status == 0);assert(p.status == 0);assert(res_map == 0);
  return res;
}
// ovo je smece
void *dumb_alloc(uint32_t root, uint32_t device, int control_fd , int nv_uvm_fd, uint64_t* addr, uint32_t flags, uint32_t size ,uint32_t attr, uint32_t alignment ,uint32_t offset){

  NV_MEMORY_ALLOCATION_PARAMS params = {.owner = root , .flags = flags ,.attr = attr,.size = size ,.alignment=alignment , .offset = offset}; 
  NvHandle obj = alloc_object(control_fd , root , device, NV01_MEMORY_LOCAL_USER ,  (void*)&params);
  uvm_external_range((uint64_t)addr , size , obj, root , control_fd , nv_uvm_fd);
  return mmap((void*)addr , size , PROT_WRITE|PROT_READ, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0); 
}

/* USER */
uint32_t* host_to_device(nouveau_pushbuf *push , uint32_t* curr , uint64_t addr ,uint32_t line_len, uint32_t* data, uint32_t range){

  push->cur = curr;
  BEGIN_NVC0(push , 0x1, NVC5C0_OFFSET_OUT_UPPER, 0x2);
  PUSH_DATAh(push , addr);
  PUSH_DATAl(push , addr);
  BEGIN_NVC0(push , 0x1, NVC5C0_LINE_LENGTH_IN, 0x2); 
  PUSH_DATA(push , line_len);
  PUSH_DATA(push , 0x1);
  BEGIN_NVC0(push , 0x1 ,NVC5C0_LAUNCH_DMA ,0x1);  // 0x2001206c
  PUSH_DATA(push , 0x41);
  BEGIN_NIC0(push , 0x1, NVC597_LOAD_INLINE_DATA, range); 
  for(int  i = 0 ; i < range; i ++){PUSH_DATA(push , data[i]);}
  return push->cur;
}

void device_to_host(nouveau_pushbuf *push , uint32_t* curr , uint64_t addr_1 ,uint64_t addr_2){
  
  push->cur = curr;
  PUSH_DATA(push ,0x20048100);  // TODO: popravi ovo
  PUSH_DATAh(push ,(uint64_t)addr_1); 
  PUSH_DATAl(push ,(uint64_t)addr_1);
  PUSH_DATAh(push ,(uint64_t)addr_2);
  PUSH_DATAl(push ,(uint64_t)addr_2);
  PUSH_DATA(push ,0x20018106);  //TODO:  popravi ovo
  PUSH_DATA(push ,0x28);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x182);
}

void ring(uint64_t *door_bell, uint32_t work_token){*door_bell = work_token;usleep(50000);}

/* main objects*/
typedef struct {
  NvHandle root;
  NvHandle device;
  NvHandle sub_device;
  NvHandle turing_user;
  NvHandle fermi_1;
  NvHandle fermi_2;
  NvHandle mem_virtual;
  NvHandle kepler_group;
  NvHandle fermi_context;
} ObjectHandles;

ObjectHandles init(int control_fd, int nv_uvm_fd) {
  ObjectHandles objs;

  objs.root = alloc_object(control_fd, 0, 0, NV01_ROOT_CLIENT, NULL);
  init_uvm(nv_uvm_fd); 

  /* device */
  NV0080_ALLOC_PARAMETERS p_80 = {.deviceId=0x0, .hClientShare=objs.root, .vaMode=0x2};
  objs.device = alloc_object(control_fd, objs.root, objs.root, NV01_DEVICE_0, &p_80);

  /* sub_device */
  NV2080_ALLOC_PARAMETERS p_2080 = {0};
  objs.sub_device = alloc_object(control_fd, objs.root, objs.device, NV20_SUBDEVICE_0, &p_2080);

  /* turing user mode */
  objs.turing_user = alloc_object(control_fd, objs.root, objs.sub_device, TURING_USERMODE_A, NULL); 

  /* Fermi vaspace 1 */  
  NV_VASPACE_ALLOCATION_PARAMETERS p_fermi_1 = {.flags = 0x48, .vaBase = 0x1000};
  objs.fermi_1 = alloc_object(control_fd, objs.root, objs.device, FERMI_VASPACE_A, (void*)&p_fermi_1);

  /* Fermi vaspace 2 */  
  NV_VASPACE_ALLOCATION_PARAMETERS p_fermi_2 = {.vaBase = 0x5000000};
  objs.fermi_2 = alloc_object(control_fd, objs.root, objs.device, FERMI_VASPACE_A, &p_fermi_2);  
  second_uvm(nv_uvm_fd);

  /* mem virtual */
  NV_MEMORY_ALLOCATION_PARAMS v_params = {.owner = objs.root, .flags = 0x8c415, .size = 0xfb000000, .offset = 0x5000000, .hVASpace = objs.fermi_2}; 
  objs.mem_virtual = alloc_object(control_fd, objs.root, objs.device, NV50_MEMORY_VIRTUAL, &v_params);  

  UVM_REGISTER_GPU_VASPACE_PARAMS register_ = {.rmCtrlFd = control_fd , .hClient = objs.root , .hVaSpace = objs.fermi_1};
  memcpy((void*)register_.gpuUuid.uuid , (void*)uud ,sizeof(register_.gpuUuid.uuid));
  int res =  ioctl(nv_uvm_fd, UVM_REGISTER_GPU_VASPACE, &register_); assert(res == 0);

  /*main kepler grpup*/
  NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS k_g = {.engineType = 1};
  objs.kepler_group = alloc_object(control_fd, objs.root ,objs.device, KEPLER_CHANNEL_GROUP_A, &k_g);  

  /*fermi context*/
  NV_CTXSHARE_ALLOCATION_PARAMETERS f_c  = {.hVASpace = objs.fermi_1 , .flags = 1 ,.subctxId = 0}; 
  objs.fermi_context =  alloc_object(control_fd, objs.root ,objs.kepler_group, FERMI_CONTEXT_SHARE_A, &f_c); 
  return objs;
}
/* command  buffer and nv0 mmap */
typedef struct {
  uint64_t* door_bell;
  NvHandle ctrl;      /*nvidiactl mmap  200400000-203c00000 */  
  NvHandle nv_0;      /*nvidia0   mmap  200200000-200400000 */  
} MmapObjects;

MmapObjects rom(int control_fd, int nv_uvm_fd, int nv0_fd,  ObjectHandles objs){
  MmapObjects m_objs;

  /* doorbell region */
  void* bar_adrr =  map_object(nv0_fd ,control_fd, objs.root, objs.device, objs.sub_device, objs.turing_user, 0x80002, 0x0, 0x10000 ,(void*)0x7ffff7f9a000, 1);
  m_objs.door_bell = (uint64_t*)((uint64_t)bar_adrr + 0x90);

  NV_MEMORY_ALLOCATION_PARAMS nv_0_mapping = {.owner = objs.root,.flags = 0x1c101,.attr = 0x18000000,.size = 0x200000,.alignment = 0x200000}; 
  m_objs.nv_0 = alloc_object(control_fd , objs.root , objs.device, NV01_MEMORY_LOCAL_USER, (void*)&nv_0_mapping);

  int nv0_f = openat(AT_FDCWD, "/dev/nvidia0", O_RDWR|O_CLOEXEC);
  map_object(nv0_f ,control_fd, objs.root, objs.device, objs.sub_device, m_objs.nv_0, 0xc0000, 0x0, 0x200000 , (void*)0x200200000, 1); close(nv0_f);
  uvm_external_range(0x200200000 , 0x200000 ,m_objs.nv_0, objs.root, control_fd , nv_uvm_fd);

  NV_MEMORY_ALLOCATION_PARAMS nv_ctrl_mapping {.owner = objs.root,.flags = 0xc001,.attr = 0x5a000000,.size = 0x3800000};
  m_objs.ctrl = alloc_object(control_fd, objs.root, objs.device, NV01_MEMORY_SYSTEM, (void*)&nv_ctrl_mapping);

  int new_ctrl = openat(AT_FDCWD, "/dev/nvidiactl", O_RDWR|O_CLOEXEC);
  map_object(new_ctrl ,control_fd, objs.root, objs.device, objs.device, m_objs.ctrl, 0xc0000, 0x0, 0x3800000 , (void*)0x200400000 ,1); close(new_ctrl); 
  uvm_external_range(0x200400000 , 0x3800000 ,m_objs.ctrl, objs.root, control_fd , nv_uvm_fd);

  return m_objs;
}
void gpu_setup(nv_0_buff *nv_buff , nouveau_pushbuf *push){

  *nv_buff->cur++ = 0x400000;
  *nv_buff->cur++ = 0x2a602;
  *nv_buff->next =  0x4002a4;
  *nv_buff->inc =  0x1;
  *(nv_buff->inc + 1) =  0x1;

  PUSH_DATA(push , 0x20012000);
  PUSH_DATA(push , 0xc5c0);
  PUSH_DATA(push , 0x200120a8);   // NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_A
  PUSH_DATA(push , 0x7fff);
  PUSH_DATA(push , 0x200120a9);   // NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_B
  PUSH_DATA(push , 0xed000000);
  PUSH_DATA(push , 0x200120b9);   // NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_A
  PUSH_DATA(push , 0x0);
  PUSH_DATA(push , 0x200120b9);   // NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_B
  PUSH_DATA(push , 0x8);     // ????????
}
uint32_t *gas(uint32_t k){return (uint32_t*)(0x200000000 | k );} 

int main(){ 

  int control[0x100];
  int control_2[0x100];
  // ROOT
  int control_fd = open64( "/dev/nvidiactl", O_RDWR);
  int nv0_fd = open64("/dev/nvidia0", O_RDWR | O_CLOEXEC);
  int nv_uvm_fd = open64("/dev/nvidia-uvm", O_RDWR | O_CLOEXEC);

  ObjectHandles objects = init(control_fd , nv_uvm_fd);

  NvHandle root = objects.root;
  NvHandle device = objects.device;
  NvHandle sub_device = objects.sub_device;
  NvHandle turing_user = objects.turing_user;
  NvHandle fermi_1 = objects.fermi_1;
  NvHandle fermi_2 = objects.fermi_2;
  NvHandle mem_virtual = objects.mem_virtual;
  NvHandle kepler_group = objects.kepler_group;
  NvHandle fermi_context = objects.fermi_context;


  MmapObjects m_objects  = rom(control_fd , nv_uvm_fd, nv0_fd, objects);  
  NvHandle nv_0_object = m_objects.nv_0;
  NvHandle nv_crtl_object = m_objects.ctrl;
  uint64_t* door_bell = m_objects.door_bell;

  //POPRAVI OVO  OVO JE BESKORISNO IZRISI
  NV_MEMORY_ALLOCATION_PARAMS o516_mapping  = {
    .owner = device,
    .flags = 0xc001,
    .attr = 0x3a000000,
    .size = 0x1000
  };

  int new_ctrl_ = openat(AT_FDCWD, "/dev/nvidiactl", O_RDWR|O_CLOEXEC);
  NvHandle o516 =   alloc_object(control_fd, root, device, NV01_MEMORY_SYSTEM, (void*)&o516_mapping);   // 5c016 
  void* o516_addr =  map_object(new_ctrl_ ,control_fd, root, device, device, o516, 0xc0000, 0x0, 0x1000 , (void*)0x7fffe2fdf000 ,1); close(new_ctrl_);

  //CONTEXT FIFO
  NV_CHANNEL_ALLOC_PARAMS params_Gp = {.hObjectError = o516 ,.hObjectBuffer = nv_0_object,.gpFifoOffset = 0x200200000 ,.gpFifoEntries = 0x400,.hContextShare = fermi_context};
  params_Gp.hUserdMemory[0] = nv_0_object; params_Gp.userdOffset[0] = 0x2000;
  NvHandle glupi_objekat = alloc_object(control_fd , root ,kepler_group, TURING_CHANNEL_GPFIFO_A, (void*)&params_Gp); // c46f

  //TURING_COMPUTE_A
  NV_GR_ALLOCATION_PARAMETERS turing_cp_params = {0};
  NvHandle turing_compute_a = alloc_object(control_fd , root ,glupi_objekat,TURING_COMPUTE_A, &turing_cp_params );

  //TURING_DMA_COPY
  NVB0B5_ALLOCATION_PARAMETERS turing_dma_params = {.engineType = 0x1};
  NvHandle turing_dma = alloc_object(control_fd , root , glupi_objekat, TURING_DMA_COPY_A, (void*)&turing_dma_params);

  //WORK_SUBMIT_TOKEN
  NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS token = {.workSubmitToken = 0x0};
  ctrl(control_fd, root, glupi_objekat ,NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN, 0, &token,sizeof(token));
  uint32_t work_token = token.workSubmitToken;
  
  // samo si kopirao cudu,  vidi kako  ovo da se slkoni  
  // OVO JE SMECE
  void *addr_gas = dumb_alloc(root, device, control_fd , nv_uvm_fd , (uint64_t*)0x205400000 , 0x1c101 ,0x200000, 0x11800000 , 0x200000 , 0x2000000);
  void *program_adrr = dumb_alloc(root, device, control_fd , nv_uvm_fd , (uint64_t*)0x7fffcfe00000 , 0x1c101 ,0x200000, 0x11800000 , 0x200000 , 0x2e00000);
  void *lakile_f = dumb_alloc(root, device, control_fd , nv_uvm_fd , (uint64_t*)0x7fffcc000000 , 0x1c101 ,0x2400000, 0x11800000 , 0x200000 , 0x3000000);

  struct nouveau_pushbuf push_buf = {.cur = (uint32_t*)0x200400000};
  nouveau_pushbuf *push =  &push_buf;

  struct nv_0_buff nv_0_buff_ = {.cur = (uint32_t*)0x200200000, .next = (uint32_t*)0x200202040 ,.inc = (uint32_t*)0x200202088};
  nv_0_buff *nv_0_p = &nv_0_buff_;
  gpu_setup(nv_0_p ,push); // setup
  
  UVM_REGISTER_CHANNEL_PARAMS register_params_0 = {
    .rmCtrlFd = control_fd,
    .hClient = root,
    .hChannel = glupi_objekat,
    .base = 0x203c00000,
    .length = 0xc82000,
  };memcpy((void*)register_params_0.gpuUuid.uuid , (void*)uud ,sizeof(register_params_0.gpuUuid.uuid));

  //REGISTER_PARAMS
  int res_channel_params = ioctl(nv_uvm_fd, UVM_REGISTER_CHANNEL, &register_params_0);
  assert(res_channel_params == 0); 
  assert(register_params_0.rmStatus == 0);

  //SCHEDULE_PARAMS
  NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS gpfifo ={.bEnable = 0x1, .bSkipSubmit = 0x0};
  ctrl(control_fd , root ,kepler_group , NVA06C_CTRL_CMD_GPFIFO_SCHEDULE , 0 ,&gpfifo , sizeof(gpfifo));

  
  /*cuDevicePtr*/
  void *k = dumb_alloc(root, device, control_fd , nv_uvm_fd , (uint64_t*)0x7ffff5e00000 , 0x1c101 ,0x1000, 0x18000000 , 0x200000 , 0x200000);
  memset((void*)control ,0x0 , 0x100); memset((void*)control_2 ,0x0 , 0x100); 

  uint32_t data_[10]  ={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  host_to_device(push , gas(*nv_0_p->next), (uint64_t)k ,0x28 ,data_ , sizeof(data_) / sizeof(uint32_t)); 
  ITER(nv_0_p ,0x6202); ring(door_bell , work_token);

  /*kernel launch*/
  host_to_device(push , gas(*nv_0_p->next), (uint64_t)0x7fffcfe3b300, 0x100, program, sizeof(program) /sizeof(uint32_t));
  ITER(nv_0_p ,0x13a02); ring(door_bell , work_token);

  host_to_device(push , gas(*nv_0_p->next), (uint64_t)0x7fffce220000, 0x160, load_1, sizeof(load_1) /sizeof(uint32_t));

  uint32_t f_args[6] = {0xf5e00000 ,0x7fff ,0xf5e00000 ,0x7fff,0xf5e00400 ,0x7fff};
  host_to_device(push , push->cur, (uint64_t)0x7fffce220160, 0x18, f_args, sizeof(f_args) / sizeof(uint32_t));

  uint32_t func_args[8] = {0xcfe3b300 ,0x00007fff ,0x00000000 ,0x00000000,0x00000000 ,0x00000000 ,0x00000001 ,0x00000000};
  host_to_device(push , push->cur, (uint64_t)0x7fffce221860, 0x20, func_args, sizeof(func_args) / sizeof(uint32_t));

  uint32_t lmao[1] = {5}; // ??
  host_to_device(push , push->cur, (uint64_t)0x203007f7c, 0x4, lmao, sizeof(lmao) / sizeof(uint32_t));
  
  /*Q META DATA */
  PUSH_DATA(push ,  0x204220c6); //ovo je djubre tesko
  for(int i = 0 ; i < O ; i ++){PUSH_DATA(push ,  load_2[i]);}                  
  ITER(nv_0_p ,0x34e02);ring(door_bell , work_token);

  device_to_host(push , gas(*nv_0_p->next) , (uint64_t)k + 0x400 ,(uint64_t)control_2);
  ITER(nv_0_p ,0x3e02); ring(door_bell , work_token);usleep(50000);
  
  dump((void*)control_2 , 0x30);
  return 0;
}

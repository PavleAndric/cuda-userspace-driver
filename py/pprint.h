#include"uvm_ioctl.h"
#include "uvm_linux_ioctl.h"

void pretty_print(struct NVB0B5_ALLOCATION_PARAMETERS* p_){
  printf("NVB0B5_ALLOCATION_PARAMETERS\n");
    printf("	version     %x\n",p_->version) ;
    printf("	engineType  %x\n",p_->engineType) ;
}
void pretty_print(struct NV_MEMORY_DESC_PARAMS *p_){
  printf("\t  base  %llx \n", p_->base);
  printf("\t  size  %llx \n", p_->size);
  printf("\t  addresSpace  %x \n", p_->addressSpace);
  printf("\t  cacheAttrib  %x \n", p_->cacheAttrib);
}
void pretty_print(struct NV_CHANNEL_ALLOC_PARAMS* p_){
  printf("NV_CHANNEL_ALLOC_PARAMS\n");
    printf("	hObjectError         %x\n",p_->hObjectError) ;
    printf("	hObjectBuffer        %x\n",p_->hObjectBuffer) ;
    printf("	gpFifoOffset         %llx\n",p_->gpFifoOffset) ;
    printf("	gpFifoEntries        %x\n",p_->gpFifoEntries) ;
    printf("	flags                %x\n",p_->flags) ;
    printf("	hContextShare        %x\n",p_->hContextShare) ;
    printf("	hVASpace             %x\n",p_->hVASpace) ;
    printf("	hUserdMemory         %p\n\t",p_->hUserdMemory) ;
    for(int i = 0 ; i < 8 ; i ++){printf("%x " , p_->hUserdMemory[i]);}printf("\n"); // NV_MAX_SUBDEVICES
    printf("	userdOffset          %p\n\t",p_->userdOffset) ;
    for(int i = 0 ; i < 8 ; i ++){printf("%llx " , p_->userdOffset[i]);}printf("\n"); // NV_MAX_SUBDEVICES
    printf("	engineType           %x\n",p_->engineType) ;
    printf("	cid                  %x\n",p_->cid) ;
    printf("	subDeviceId          %x\n",p_->subDeviceId) ;
    printf("	hObjectEccError      %x\n",p_->hObjectEccError) ;
    printf("	instanceMem          \n");
    pretty_print((NV_MEMORY_DESC_PARAMS*)&p_->instanceMem);
    printf("	userdMem             \n");
    pretty_print((NV_MEMORY_DESC_PARAMS*)&p_->userdMem);
    printf("	ramfcMem             \n");
    pretty_print((NV_MEMORY_DESC_PARAMS*)&p_->ramfcMem);
    printf("	mthdbufMem           \n");
    pretty_print((NV_MEMORY_DESC_PARAMS*)&p_->mthdbufMem);
    printf("	hPhysChannelGroup    %x\n",p_->hPhysChannelGroup) ;
    printf("	internalFlags        %x\n",p_->internalFlags) ;
    printf("	errorNotifierMem     \n");
    pretty_print((NV_MEMORY_DESC_PARAMS*)&p_->errorNotifierMem);
    printf("	eccErrorNotifierMem  \n");
    pretty_print((NV_MEMORY_DESC_PARAMS*)&p_->eccErrorNotifierMem);
    printf("	ProcessID            %x\n",p_->ProcessID) ;
    printf("	SubProcessID         %x\n",p_->SubProcessID) ;
    printf("	encryptIv            %p\n",p_->encryptIv) ;
    printf("	decryptIv            %p\n",p_->decryptIv) ;
    printf("	hmacNonce            %p\n",p_->hmacNonce) ;
}

void pretty_print(NV_MEMORY_ALLOCATION_PARAMS* p_){
  printf("NV_MEMORY_ALLOCATION_PARAMS\n");
    printf("	owner          %x\n",p_->owner) ;
    printf("	type           %x\n",p_->type) ;
    printf("	flags          %x\n",p_->flags) ;
    printf("	width          %x\n",p_->width) ;
    printf("	height         %x\n",p_->height) ;
    printf("	pitch          %lx\n",(uint64_t)(p_->pitch) );
    printf("	attr           %x\n",p_->attr) ;
    printf("	attr2          %x\n",p_->attr2) ;
    printf("	format         %x\n",p_->format) ;
    printf("	comprCovg      %x\n",p_->comprCovg) ;
    printf("	zcullCovg      %x\n",p_->zcullCovg) ;
    printf("	rangeLo        %llx\n",p_->rangeLo) ;
    printf("	rangeHi        %llx\n",p_->rangeHi) ;
    printf("	size           %llx\n",p_->size) ;
    printf("	alignment      %llx\n",p_->alignment) ;
    printf("	offset         %llx\n",p_->offset) ;
    printf("	limit          %llx\n",p_->limit) ;
    printf("	address        %p\n",p_->address) ;
    printf("	ctagOffset     %x\n",p_->ctagOffset) ;
    printf("	hVASpace       %x\n",p_->hVASpace) ;
    printf("	internalflags  %x\n",p_->internalflags) ;
    printf("	tag            %x\n",p_->tag) ;
    printf("	numaNode       %lx\n",(uint64_t)(p_->numaNode) );
}
void pretty_print(UVM_INITIALIZE_PARAMS* p_ ){
  printf("UVM_INITIALIZE_PARAMS\n");
    printf("	flags  %llx\n",p_->flags);
    printf("	rmStatus %x\n",p_->rmStatus);
}
void pretty_print( UVM_RESERVE_VA_PARAMS* p_){
  printf("UVM_RESERVE_VA_PARAMS\n");
    printf("	requestedBase  %llx\n",p_->requestedBase) ;
    printf("	length         %llx\n",p_->length) ;
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_RELEASE_VA_PARAMS* p_){
  printf("UVM_RELEASE_VA_PARAMS\n");
    printf("	requestedBase  %llx\n",p_->requestedBase) ;
    printf("	length         %llx\n",p_->length) ;
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_REGION_COMMIT_PARAMS* p_){
  printf("UVM_REGION_COMMIT_PARAMS\n");
    printf("	requestedBase  %llx\n",p_->requestedBase) ;
    printf("	length         %llx\n",p_->length) ;
    printf("	streamId       %lx\n",(uint64_t)(p_->streamId) );
    printf("gpuUuid LMAO POPRAVI OVO\n");
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_REGION_DECOMMIT_PARAMS* p_){
  printf("UVM_REGION_DECOMMIT_PARAMS\n");
    printf("	requestedBase  %llx\n",p_->requestedBase) ;
    printf("	length         %llx\n",p_->length) ;
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_REGION_SET_STREAM_PARAMS* p_){
  printf("UVM_REGION_SET_STREAM_PARAMS\n");
    printf("	requestedBase  %llx\n",p_->requestedBase) ;
    printf("	length         %llx\n",p_->length) ;
    printf("	newStreamId    %lx\n",(uint64_t)(p_->newStreamId) );
    printf("gpuUuid LMAO POPRAVI OVO\n");
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_SET_STREAM_RUNNING_PARAMS* p_){
  printf("UVM_SET_STREAM_RUNNING_PARAMS\n");
    printf("	streamId  %lx\n",(uint64_t)(p_->streamId) );
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_SET_STREAM_STOPPED_PARAMS* p_){
  printf("UVM_SET_STREAM_STOPPED_PARAMS\n");
    printf("	streamIdArray  %p\n",p_->streamIdArray) ;
    printf("	nStreams       %llx\n",p_->nStreams) ;
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_RUN_TEST_PARAMS* p_){
  printf("UVM_RUN_TEST_PARAMS\n");
    printf("gpuUuid LMAO POPRAVI OVO\n");
    printf("	test      %x\n",p_->test) ;
    printf("multiGpu LMAO POPRAVI OVO\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_ADD_SESSION_PARAMS* p_){
  printf("UVM_ADD_SESSION_PARAMS\n");
    printf("	pidTarget            %x\n",p_->pidTarget) ;
    printf("	countersBaseAddress  %p\n",p_->countersBaseAddress) ;
    printf("	sessionIndex         %lx\n",(uint64_t)(p_->sessionIndex) );
    printf("	rmStatus             %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_REMOVE_SESSION_PARAMS* p_){
  printf("UVM_REMOVE_SESSION_PARAMS\n");
    printf("	sessionIndex  %lx\n",(uint64_t)(p_->sessionIndex) );
    printf("	rmStatus      %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_ENABLE_COUNTERS_PARAMS* p_){
  printf("UVM_ENABLE_COUNTERS_PARAMS\n");
    printf("	sessionIndex  %lx\n",(uint64_t)(p_->sessionIndex) );
    printf("	config        %p\n",p_->config) ;
    printf("	count         %x\n",p_->count) ;
    printf("	rmStatus      %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_MAP_COUNTER_PARAMS* p_){
  printf("UVM_MAP_COUNTER_PARAMS\n");
    printf("	sessionIndex  %lx\n",(uint64_t)(p_->sessionIndex) );
    printf("	scope         %x\n",p_->scope) ;
    printf("	counterName   %x\n",p_->counterName) ;
    printf("gpuUuid LMAO POPRAVI OVO\n");
    printf("	addr          %p\n",p_->addr) ;
    printf("	rmStatus      %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_CREATE_EVENT_QUEUE_PARAMS* p_){
  printf("UVM_CREATE_EVENT_QUEUE_PARAMS\n");
    printf("	sessionIndex       %lx\n",(uint64_t)(p_->sessionIndex) );
    printf("	eventQueueIndex    %x\n",p_->eventQueueIndex) ;
    printf("	queueSize          %llx\n",p_->queueSize) ;
    printf("	notificationCount  %llx\n",p_->notificationCount) ;
    printf("	timeStampType      %x\n",p_->timeStampType) ;
    printf("	rmStatus           %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_REMOVE_EVENT_QUEUE_PARAMS* p_){
  printf("UVM_REMOVE_EVENT_QUEUE_PARAMS\n");
    printf("	sessionIndex     %lx\n",(uint64_t)(p_->sessionIndex) );
    printf("	eventQueueIndex  %x\n",p_->eventQueueIndex) ;
    printf("	rmStatus         %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_MAP_EVENT_QUEUE_PARAMS* p_){
  printf("UVM_MAP_EVENT_QUEUE_PARAMS\n");
    printf("	sessionIndex     %lx\n",(uint64_t)(p_->sessionIndex) );
    printf("	eventQueueIndex  %x\n",p_->eventQueueIndex) ;
    printf("	userRODataAddr   %p\n",p_->userRODataAddr) ;
    printf("	userRWDataAddr   %p\n",p_->userRWDataAddr) ;
    printf("	readIndexAddr    %p\n",p_->readIndexAddr) ;
    printf("	writeIndexAddr   %p\n",p_->writeIndexAddr) ;
    printf("	queueBufferAddr  %p\n",p_->queueBufferAddr) ;
    printf("	rmStatus         %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_EVENT_CTRL_PARAMS* p_){
  printf("UVM_EVENT_CTRL_PARAMS\n");
    printf("	sessionIndex     %lx\n",(uint64_t)(p_->sessionIndex) );
    printf("	eventQueueIndex  %x\n",p_->eventQueueIndex) ;
    printf("	eventType        %lx\n",(uint64_t)(p_->eventType) );
    printf("	enable           %x\n",p_->enable) ;
    printf("	rmStatus         %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_REGISTER_MPS_SERVER_PARAMS* p_){
  printf("UVM_REGISTER_MPS_SERVER_PARAMS\n");
    printf("gpuUuidArray LMAO POPRAVI OVO\n");
    printf("	numGpus       %x\n",p_->numGpus) ;
    printf("	serverId      %llx\n",p_->serverId) ;
    printf("	rmStatus      %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_REGISTER_MPS_CLIENT_PARAMS* p_){
  printf("UVM_REGISTER_MPS_CLIENT_PARAMS\n");
    printf("	serverId  %llx\n",p_->serverId) ;
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_GET_GPU_UUID_TABLE_PARAMS* p_){
  printf("UVM_GET_GPU_UUID_TABLE_PARAMS\n");
    printf("gpuUuidArray LMAO POPRAVI OVO\n");
    printf("	validCount    %x\n",p_->validCount) ;
    printf("	rmStatus      %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_CREATE_RANGE_GROUP_PARAMS* p_){
  printf("UVM_CREATE_RANGE_GROUP_PARAMS\n");
    printf("	rangeGroupId  %llx\n",p_->rangeGroupId) ;
    printf("	rmStatus      %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_DESTROY_RANGE_GROUP_PARAMS* p_){
  printf("UVM_DESTROY_RANGE_GROUP_PARAMS\n");
    printf("	rangeGroupId  %llx\n",p_->rangeGroupId) ;
    printf("	rmStatus      %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_REGISTER_GPU_VASPACE_PARAMS* p_){
  printf("UVM_REGISTER_GPU_VASPACE_PARAMS\n");
    printf("\t----- gpuUuid -----\n\t");
    for( int i = 0 ; i < 16 ; i ++){printf("%x ",p_->gpuUuid.uuid[i]);}printf("\n");
    printf("	rmCtrlFd  %lx\n",(uint64_t)(p_->rmCtrlFd) );
    printf("	hClient   %x\n",p_->hClient) ;
    printf("	hVaSpace  %x\n",p_->hVaSpace) ;
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_UNREGISTER_GPU_VASPACE_PARAMS* p_){
  printf("UVM_UNREGISTER_GPU_VASPACE_PARAMS\n");
    printf("gpuUuid LMAO POPRAVI OVO\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_REGISTER_CHANNEL_PARAMS* p_){
  printf("UVM_REGISTER_CHANNEL_PARAMS\n\t");
    for(int i = 0 ; i < 0x16 ; i ++){printf("%x " , p_->gpuUuid.uuid[i]);}printf("\n");
    printf("	rmCtrlFd  %lx\n",(uint64_t)(p_->rmCtrlFd) );
    printf("	rmCtrlFd  %lx\n",(uint64_t)(p_->rmCtrlFd) );
    printf("	hClient   %x\n",p_->hClient) ;
    printf("	hChannel  %x\n",p_->hChannel) ;
    printf("	base      %llx\n",p_->base) ;
    printf("	length    %llx\n",p_->length) ;
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_UNREGISTER_CHANNEL_PARAMS* p_){
  printf("UVM_UNREGISTER_CHANNEL_PARAMS\n");
    printf("gpuUuid LMAO POPRAVI OVO\n");
    printf("	hClient   %x\n",p_->hClient) ;
    printf("	hChannel  %x\n",p_->hChannel) ;
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_ENABLE_PEER_ACCESS_PARAMS* p_){
  printf("UVM_ENABLE_PEER_ACCESS_PARAMS\n");
    printf("gpuUuidA LMAO POPRAVI OVO\n");
    printf("gpuUuidB LMAO POPRAVI OVO\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_DISABLE_PEER_ACCESS_PARAMS* p_){
  printf("UVM_DISABLE_PEER_ACCESS_PARAMS\n");
    printf("gpuUuidA LMAO POPRAVI OVO\n");
    printf("gpuUuidB LMAO POPRAVI OVO\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_SET_RANGE_GROUP_PARAMS* p_){
  printf("UVM_SET_RANGE_GROUP_PARAMS\n");
    printf("	rangeGroupId   %llx\n",p_->rangeGroupId) ;
    printf("	requestedBase  %llx\n",p_->requestedBase) ;
    printf("	length         %llx\n",p_->length) ;
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_MAP_EXTERNAL_ALLOCATION_PARAMS* p_){
  printf("UVM_MAP_EXTERNAL_ALLOCATION_PARAMS\n");
    printf("	base                %llx\n",p_->base) ;
    printf("	length              %llx\n",p_->length) ;
    printf("	offset              %llx\n",p_->offset) ;
    printf("	perGpuAttributes    %p\n",p_->perGpuAttributes);
    for(int i = 0; i < 1; i++){ // imas samo jedan gpu
      printf("\tperGpuAttributes[%d]\n" , i);
      for(int j = 0 ; j < 16 ; j ++){
      if(j % 8 == 0)printf("\n\t");
        printf("uud[%02d][%02d] = %x " ,i,j,p_->perGpuAttributes[i].gpuUuid.uuid[j]);
      }printf("\n");
      printf("\tp_->perGpuAttributes[%d].gpuMappingType = %x\n" ,i,p_->perGpuAttributes[i].gpuMappingType);
      printf("\tp_->perGpuAttributes[%d].gpuCachingType = %x\n" ,i,p_->perGpuAttributes[i].gpuCachingType);
      printf("\tp_->perGpuAttributes[%d].gpuFormatType = %x\n" ,i,p_->perGpuAttributes[i].gpuFormatType);
      printf("\tp_->perGpuAttributes[%d].gpuElementBits = %x\n" ,i,p_->perGpuAttributes[i].gpuElementBits);
      printf("\tp_->perGpuAttributes[%d].gpuCompressionType = %x\n" ,i,p_->perGpuAttributes[i].gpuCompressionType);
    }
    printf("	gpuAttributesCount  %llx\n",p_->gpuAttributesCount) ;
    printf("	rmCtrlFd            %lx\n",(uint64_t)(p_->rmCtrlFd) );
    printf("	hClient             %x\n",p_->hClient) ;
    printf("	hMemory             %x\n",p_->hMemory) ;
    printf("	rmStatus            %lx\n",(uint64_t)(p_->rmStatus));
}
void pretty_print( UVM_FREE_PARAMS* p_){
  printf("UVM_FREE_PARAMS\n");
    printf("	base      %llx\n",p_->base) ;
    printf("	length    %llx\n",p_->length) ;
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_MEM_MAP_PARAMS* p_){
  printf("UVM_MEM_MAP_PARAMS\n");
    printf("	regionBase    %p\n",p_->regionBase) ;
    printf("	regionLength  %llx\n",p_->regionLength) ;
    printf("	rmStatus      %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_DEBUG_ACCESS_MEMORY_PARAMS* p_){
  printf("UVM_DEBUG_ACCESS_MEMORY_PARAMS\n");
    printf("	sessionIndex  %lx\n",(uint64_t)(p_->sessionIndex) );
    printf("	baseAddress   %llx\n",p_->baseAddress) ;
    printf("	sizeInBytes   %llx\n",p_->sizeInBytes) ;
    printf("	accessType    %x\n",p_->accessType) ;
    printf("	buffer        %llx\n",p_->buffer) ;
    printf("	isBitmaskSet  %lx\n",(uint64_t)(p_->isBitmaskSet) );
    printf("	bitmask       %llx\n",p_->bitmask) ;
    printf("	rmStatus      %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_REGISTER_GPU_PARAMS* p_){
  printf("UVM_REGISTER_GPU_PARAMS\n");
    printf("\tgpu_uuid\n\t");
    for(int i  = 0 ; i < 16; i ++){printf("%x ", p_->gpu_uuid.uuid[i]);};printf("\n");
    printf("	numaEnabled  %lx\n",(uint64_t)(p_->numaEnabled) );
    printf("	numaNodeId   %lx\n",(uint64_t)(p_->numaNodeId) );
    printf("	rmCtrlFd     %d\n",p_->rmCtrlFd);
    printf("	hClient      %x\n",p_->hClient) ;
    printf("	hSmcPartRef  %x\n",p_->hSmcPartRef) ;
    printf("	rmStatus     %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_UNREGISTER_GPU_PARAMS* p_){
  printf("UVM_UNREGISTER_GPU_PARAMS\n");
    printf("gpu_uuid LMAO POPRAVI OVO\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_PAGEABLE_MEM_ACCESS_PARAMS* p_){
  printf("UVM_PAGEABLE_MEM_ACCESS_PARAMS\n");
    printf("	pageableMemAccess  %lx\n",(uint64_t)(p_->pageableMemAccess) );
    printf("	rmStatus           %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_PREVENT_MIGRATION_RANGE_GROUPS_PARAMS* p_){
  printf("UVM_PREVENT_MIGRATION_RANGE_GROUPS_PARAMS\n");
    printf("	rangeGroupIds  %p\n",p_->rangeGroupIds) ;
    printf("	numGroupIds    %llx\n",p_->numGroupIds) ;
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_ALLOW_MIGRATION_RANGE_GROUPS_PARAMS* p_){
  printf("UVM_ALLOW_MIGRATION_RANGE_GROUPS_PARAMS\n");
    printf("	rangeGroupIds  %p\n",p_->rangeGroupIds) ;
    printf("	numGroupIds    %llx\n",p_->numGroupIds) ;
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_SET_PREFERRED_LOCATION_PARAMS* p_){
  printf("UVM_SET_PREFERRED_LOCATION_PARAMS\n");
    printf("	requestedBase      %llx\n",p_->requestedBase) ;
    printf("	length             %llx\n",p_->length) ;
    printf("preferredLocation LMAO POPRAVI OVO\n");
    printf("	rmStatus           %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_UNSET_PREFERRED_LOCATION_PARAMS* p_){
  printf("UVM_UNSET_PREFERRED_LOCATION_PARAMS\n");
    printf("	requestedBase  %llx\n",p_->requestedBase) ;
    printf("	length         %llx\n",p_->length) ;
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_ENABLE_READ_DUPLICATION_PARAMS* p_){
  printf("UVM_ENABLE_READ_DUPLICATION_PARAMS\n");
    printf("	requestedBase  %llx\n",p_->requestedBase) ;
    printf("	length         %llx\n",p_->length) ;
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_DISABLE_READ_DUPLICATION_PARAMS* p_){
  printf("UVM_DISABLE_READ_DUPLICATION_PARAMS\n");
    printf("	requestedBase  %llx\n",p_->requestedBase) ;
    printf("	length         %llx\n",p_->length) ;
    printf("	rmStatus       %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_SET_ACCESSED_BY_PARAMS* p_){
  printf("UVM_SET_ACCESSED_BY_PARAMS\n");
    printf("	requestedBase   %llx\n",p_->requestedBase) ;
    printf("	length          %llx\n",p_->length) ;
    printf("accessedByUuid LMAO POPRAVI OVO\n");
    printf("	rmStatus        %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_UNSET_ACCESSED_BY_PARAMS* p_){
  printf("UVM_UNSET_ACCESSED_BY_PARAMS\n");
    printf("	requestedBase   %llx\n",p_->requestedBase) ;
    printf("	length          %llx\n",p_->length) ;
    printf("accessedByUuid LMAO POPRAVI OVO\n");
    printf("	rmStatus        %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_MIGRATE_PARAMS* p_){
  printf("UVM_MIGRATE_PARAMS\n");
    printf("	base              %llx\n",p_->base) ;
    printf("	length            %llx\n",p_->length) ;
    printf("destinationUuid LMAO POPRAVI OVO\n");
    printf("	flags             %x\n",p_->flags) ;
    printf("	semaphoreAddress  %llx\n",p_->semaphoreAddress) ;
    printf("	semaphorePayload  %x\n",p_->semaphorePayload) ;
    printf("	cpuNumaNode       %x\n",p_->cpuNumaNode) ;
    printf("	userSpaceStart    %llx\n",p_->userSpaceStart) ;
    printf("	userSpaceLength   %llx\n",p_->userSpaceLength) ;
    printf("	rmStatus          %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_MIGRATE_RANGE_GROUP_PARAMS* p_){
  printf("UVM_MIGRATE_RANGE_GROUP_PARAMS\n");
    printf("	rangeGroupId     %llx\n",p_->rangeGroupId) ;
    printf("destinationUuid LMAO POPRAVI OVO\n");
    printf("	rmStatus         %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_ENABLE_SYSTEM_WIDE_ATOMICS_PARAMS* p_){
  printf("UVM_ENABLE_SYSTEM_WIDE_ATOMICS_PARAMS\n");
    printf("gpu_uuid LMAO POPRAVI OVO\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_DISABLE_SYSTEM_WIDE_ATOMICS_PARAMS* p_){
  printf("UVM_DISABLE_SYSTEM_WIDE_ATOMICS_PARAMS\n");
    printf("gpu_uuid LMAO POPRAVI OVO\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_TOOLS_INIT_EVENT_TRACKER_PARAMS* p_){
  printf("UVM_TOOLS_INIT_EVENT_TRACKER_PARAMS\n");
    printf("	queueBuffer      %llx\n",p_->queueBuffer) ;
    printf("	queueBufferSize  %llx\n",p_->queueBufferSize) ;
    printf("	controlBuffer    %llx\n",p_->controlBuffer) ;
    printf("processor LMAO POPRAVI OVO\n");
    printf("	allProcessors    %x\n",p_->allProcessors) ;
    printf("	uvmFd            %x\n",p_->uvmFd) ;
    printf("	rmStatus         %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_TOOLS_SET_NOTIFICATION_THRESHOLD_PARAMS* p_){
  printf("UVM_TOOLS_SET_NOTIFICATION_THRESHOLD_PARAMS\n");
    printf("	notificationThreshold  %x\n",p_->notificationThreshold) ;
    printf("	rmStatus               %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_TOOLS_EVENT_QUEUE_ENABLE_EVENTS_PARAMS* p_){
  printf("UVM_TOOLS_EVENT_QUEUE_ENABLE_EVENTS_PARAMS\n");
    printf("	eventTypeFlags  %llx\n",p_->eventTypeFlags) ;
    printf("	rmStatus        %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_TOOLS_EVENT_QUEUE_DISABLE_EVENTS_PARAMS* p_){
  printf("UVM_TOOLS_EVENT_QUEUE_DISABLE_EVENTS_PARAMS\n");
    printf("	eventTypeFlags  %llx\n",p_->eventTypeFlags) ;
    printf("	rmStatus        %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_TOOLS_ENABLE_COUNTERS_PARAMS* p_){
  printf("UVM_TOOLS_ENABLE_COUNTERS_PARAMS\n");
    printf("	counterTypeFlags  %llx\n",p_->counterTypeFlags) ;
    printf("	rmStatus          %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_TOOLS_DISABLE_COUNTERS_PARAMS* p_){
  printf("UVM_TOOLS_DISABLE_COUNTERS_PARAMS\n");
    printf("	counterTypeFlags  %llx\n",p_->counterTypeFlags) ;
    printf("	rmStatus          %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_TOOLS_READ_PROCESS_MEMORY_PARAMS* p_){
  printf("UVM_TOOLS_READ_PROCESS_MEMORY_PARAMS\n");
    printf("	buffer     %llx\n",p_->buffer) ;
    printf("	size       %llx\n",p_->size) ;
    printf("	targetVa   %llx\n",p_->targetVa) ;
    printf("	bytesRead  %llx\n",p_->bytesRead) ;
    printf("	rmStatus   %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_TOOLS_WRITE_PROCESS_MEMORY_PARAMS* p_){
  printf("UVM_TOOLS_WRITE_PROCESS_MEMORY_PARAMS\n");
    printf("	buffer        %llx\n",p_->buffer) ;
    printf("	size          %llx\n",p_->size) ;
    printf("	targetVa      %llx\n",p_->targetVa) ;
    printf("	bytesWritten  %llx\n",p_->bytesWritten) ;
    printf("	rmStatus      %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_TOOLS_GET_PROCESSOR_UUID_TABLE_PARAMS* p_){
  printf("UVM_TOOLS_GET_PROCESSOR_UUID_TABLE_PARAMS\n");
    printf("	tablePtr  %llx\n",p_->tablePtr) ;
    printf("	count     %x\n",p_->count) ;
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_MAP_DYNAMIC_PARALLELISM_REGION_PARAMS* p_){
  printf("UVM_MAP_DYNAMIC_PARALLELISM_REGION_PARAMS\n");
    printf("	base      %llx\n",p_->base) ;
    printf("	length    %llx\n",p_->length) ;
    printf("gpuUuid LMAO POPRAVI OVO\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_UNMAP_EXTERNAL_PARAMS* p_){
  printf("UVM_UNMAP_EXTERNAL_PARAMS\n");
    printf("	base      %llx\n",p_->base) ;
    printf("	length    %llx\n",p_->length) ;
    printf("gpuUuid LMAO POPRAVI OVO\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_TOOLS_FLUSH_EVENTS_PARAMS* p_){
  printf("UVM_TOOLS_FLUSH_EVENTS_PARAMS\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_ALLOC_SEMAPHORE_POOL_PARAMS* p_){
  printf("UVM_ALLOC_SEMAPHORE_POOL_PARAMS\n");
    printf("	base                %llx\n",p_->base) ;
    printf("	length              %llx\n",p_->length) ;
    printf("	perGpuAttributes    %p\n",p_->perGpuAttributes) ;
    printf("	gpuAttributesCount  %llx\n",p_->gpuAttributesCount) ;
    printf("	rmStatus            %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_CLEAN_UP_ZOMBIE_RESOURCES_PARAMS* p_){
  printf("UVM_CLEAN_UP_ZOMBIE_RESOURCES_PARAMS\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_PAGEABLE_MEM_ACCESS_ON_GPU_PARAMS* p_){ // ROM
  printf("UVM_PAGEABLE_MEM_ACCESS_ON_GPU_PARAMS\n\t");
    for(int i  = 0 ; i < 16; i ++){printf("%x ", p_->gpu_uuid.uuid[i]);};printf("\n");
    printf("	pageableMemAccess  %lx\n",(uint64_t)(p_->pageableMemAccess) );
    printf("	rmStatus           %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_POPULATE_PAGEABLE_PARAMS* p_){
  printf("UVM_POPULATE_PAGEABLE_PARAMS\n");
    printf("	base      %llx\n",p_->base) ;
    printf("	length    %llx\n",p_->length) ;
    printf("	flags     %x\n",p_->flags) ;
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_VALIDATE_VA_RANGE_PARAMS* p_){
  printf("UVM_VALIDATE_VA_RANGE_PARAMS\n");
    printf("	base      %llx\n",p_->base) ;
    printf("	length    %llx\n",p_->length) ;
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_CREATE_EXTERNAL_RANGE_PARAMS* p_){
  printf("UVM_CREATE_EXTERNAL_RANGE_PARAMS\n");
    printf("	base      %llx\n",p_->base) ;
    printf("	length    %llx\n",p_->length) ;
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_MAP_EXTERNAL_SPARSE_PARAMS* p_){
  printf("UVM_MAP_EXTERNAL_SPARSE_PARAMS\n");
    printf("	base      %llx\n",p_->base) ;
    printf("	length    %llx\n",p_->length) ;
    printf("gpuUuid LMAO POPRAVI OVO\n");
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print( UVM_MM_INITIALIZE_PARAMS* p_){
  printf("UVM_MM_INITIALIZE_PARAMS\n");
    printf("	uvmFd     %lx\n",(uint64_t)(p_->uvmFd) );
    printf("	rmStatus  %lx\n",(uint64_t)(p_->rmStatus) );
}
void pretty_print(struct _clc5b5_tag0* p_){
  printf("POCETAK\n");
  for(int i = 0  ; i < 0x40 ; i++){
    if(p_->Reserved00[i] != 0){
      printf("\tp_->Reserved00[%d] = %x \n" ,i, p_->Reserved00[i]);
      }
  }printf("\n");
  //memset(p_->Reserved00 , 0x0  , 0x40);
  /*
  printf("gas\n");
  for(int i = 0  ; i < 0xF ; i++){if(p_->Reserved01[i] != 0)printf("%x " , p_->Reserved01[i]);}printf("\n");
  printf("gas\n");
  for(int i = 0  ; i < 0x3F ; i++){if(p_->Reserved02[i] != 0)printf("%x " , p_->Reserved02[i]);}printf("\n");
  printf("gas\n");
  for(int i = 0  ; i < 0x2 ; i++){if(p_->Reserved03[i] != 0)printf("%x " , p_->Reserved03[i]);}printf("\n");
  printf("gas\n");
  for(int i = 0  ; i < 0x6 ; i++){if(p_->Reserved04[i] != 0)printf("%x " , p_->Reserved04[i]);}printf("\n");
  printf("gas\n");
  for(int i = 0  ; i < 0x1C ; i++){if(p_->Reserved05[i] != 0)printf("%x " , p_->Reserved05[i]);}printf("\n");
  printf("gas\n");
  for(int i = 0  ; i < 0x3F ; i++){if(p_->Reserved06[i] != 0)printf("%x " , p_->Reserved06[i]);}printf("\n");
  printf("gas\n");
  for(int i = 0  ; i < 0x1 ; i++){if(p_->Reserved07[i] != 0)printf("%x " , p_->Reserved07[i]);}printf("\n");
  printf("gas\n");
  for(int i = 0  ; i < 0x1 ; i++){if(p_->Reserved08[i] != 0)printf("%x " , p_->Reserved08[i]);}printf("\n");
  printf("gas\n");
  for(int i = 0  ; i < 0x1 ; i++){if(p_->Reserved09[i] != 0)printf("%x " , p_->Reserved09[i]);}printf("\n");
  printf("gas\n");
  for(int i = 0  ; i < 0x270 ; i++){if(p_->Reserved10[i] != 0)printf("%x " , p_->Reserved10[i]);}printf("\n");
  printf("gas\n");
  for(int i = 0  ; i < 0x3BA ; i++){if(p_->Reserved11[i] != 0)printf("%x " , p_->Reserved11[i]);}printf("\n");
  */

  printf("_clc5b5_tag0\n");
    printf("	Reserved00              %p\n",p_->Reserved00) ; //ovo je  uvek  nula
    printf("	Nop                     %x\n",p_->Nop) ;
    printf("	Reserved01              %p\n",p_->Reserved01) ;
    printf("	PmTrigger               %x\n",p_->PmTrigger) ;
    printf("	Reserved02              %p\n",p_->Reserved02) ;
    printf("	SetSemaphoreA           %x\n",p_->SetSemaphoreA) ;
    printf("	SetSemaphoreB           %x\n",p_->SetSemaphoreB) ;
    printf("	SetSemaphorePayload     %x\n",p_->SetSemaphorePayload) ;
    printf("	Reserved03              %p\n",p_->Reserved03) ;
    printf("	SetRenderEnableA        %x\n",p_->SetRenderEnableA) ;
    printf("	SetRenderEnableB        %x\n",p_->SetRenderEnableB) ;
    printf("	SetRenderEnableC        %x\n",p_->SetRenderEnableC) ;
    printf("	SetSrcPhysMode          %x\n",p_->SetSrcPhysMode) ;
    printf("	SetDstPhysMode          %x\n",p_->SetDstPhysMode) ;
    printf("	Reserved04              %p\n",p_->Reserved04) ;
    printf("	SetGlobalCounterUpper   %x\n",p_->SetGlobalCounterUpper) ;
    printf("	SetGlobalCounterLower   %x\n",p_->SetGlobalCounterLower) ;
    printf("	SetPageoutStartPAUpper  %x\n",p_->SetPageoutStartPAUpper) ;
    printf("	SetPageoutStartPALower  %x\n",p_->SetPageoutStartPALower) ;
    printf("	Reserved05              %p\n",p_->Reserved05) ;
    printf("	LaunchDma               %x\n",p_->LaunchDma) ;
    printf("	Reserved06              %p\n",p_->Reserved06) ;
    printf("	OffsetInUpper           %x\n",p_->OffsetInUpper) ;
    printf("	OffsetInLower           %x\n",p_->OffsetInLower) ;
    printf("	OffsetOutUpper          %x\n",p_->OffsetOutUpper) ;
    printf("	OffsetOutLower          %x\n",p_->OffsetOutLower) ;
    printf("	PitchIn                 %x\n",p_->PitchIn) ;
    printf("	PitchOut                %x\n",p_->PitchOut) ;
    printf("	LineLengthIn            %x\n",p_->LineLengthIn) ;
    printf("	LineCount               %x\n",p_->LineCount) ;
    printf("	Reserved07              %p\n",p_->Reserved07) ;
    printf("	SetRemapConstA          %x\n",p_->SetRemapConstA) ;
    printf("	SetRemapConstB          %x\n",p_->SetRemapConstB) ;
    printf("	SetRemapComponents      %x\n",p_->SetRemapComponents) ;
    printf("	SetDstBlockSize         %x\n",p_->SetDstBlockSize) ;
    printf("	SetDstWidth             %x\n",p_->SetDstWidth) ;
    printf("	SetDstHeight            %x\n",p_->SetDstHeight) ;
    printf("	SetDstDepth             %x\n",p_->SetDstDepth) ;
    printf("	SetDstLayer             %x\n",p_->SetDstLayer) ;
    printf("	SetDstOrigin            %x\n",p_->SetDstOrigin) ;
    printf("	Reserved08              %p\n",p_->Reserved08) ;
    printf("	SetSrcBlockSize         %x\n",p_->SetSrcBlockSize) ;
    printf("	SetSrcWidth             %x\n",p_->SetSrcWidth) ;
    printf("	SetSrcHeight            %x\n",p_->SetSrcHeight) ;
    printf("	SetSrcDepth             %x\n",p_->SetSrcDepth) ;
    printf("	SetSrcLayer             %x\n",p_->SetSrcLayer) ;
    printf("	SetSrcOrigin            %x\n",p_->SetSrcOrigin) ;
    printf("	Reserved09              %p\n",p_->Reserved09) ;
    printf("	SrcOriginX              %x\n",p_->SrcOriginX) ;
    printf("	SrcOriginY              %x\n",p_->SrcOriginY) ;
    printf("	DstOriginX              %x\n",p_->DstOriginX) ;
    printf("	DstOriginY              %x\n",p_->DstOriginY) ;
    printf("	Reserved10              %p\n",p_->Reserved10) ;
    printf("	PmTriggerEnd            %x\n",p_->PmTriggerEnd) ;
    printf("	Reserved11              %p\n",p_->Reserved11) ;
}
void pretty_print(struct Nvc46fControl_struct* p_){
  printf("Nvc46fControl_struct\n");
    printf("	Ignored00      %p\n",p_->Ignored00);
    for(int i = 0 ; i < 0x010 ; i ++ ){printf("%x " , p_->Ignored00[i]);}printf("\n");
    //memset((void*)p_->Ignored00 , 0x0 , 0x10);
    /*for(int i = 0 ; i < 0x002 ; i ++ ){printf("%x " , p_->Ignored01[i]);}printf("\n");
    for(int i = 0 ; i < 0x007 ; i ++ ){printf("%x " , p_->Ignored02[i]);}printf("\n");
    for(int i = 0 ; i < 0x001 ; i ++ ){printf("%x " , p_->Ignored04[i]);}printf("\n");
    for(int i = 0 ; i < 0x5c ; i ++ ){printf("%x " , p_->Ignored05[i]);}printf("\n");*/
    
    memset((void*)p_->Ignored01 , 0x0 , 0x002);
    memset((void*)p_->Ignored02 , 0x0 , 0x007);
    memset((void*)p_->Ignored04 , 0x0 , 0x001);
    memset((void*)p_->Ignored05 , 0x0 , 0x5c);
    printf("	Put            %x\n",p_->Put) ;
    printf("	Get            %x\n",p_->Get) ;
    printf("	Reference      %x\n",p_->Reference) ;
    printf("	PutHi          %x\n",p_->PutHi) ;
    printf("	Ignored01      %p\n",p_->Ignored01) ;
    printf("	TopLevelGet    %x\n",p_->TopLevelGet) ;
    printf("	TopLevelGetHi  %x\n",p_->TopLevelGetHi) ;
    printf("	GetHi          %x\n",p_->GetHi) ;
    printf("	Ignored02      %p\n",p_->Ignored02) ;
    printf("	Ignored03      %x\n",p_->Ignored03) ;
    printf("	Ignored04      %p\n",p_->Ignored04) ;
    printf("	GPGet          %x\n",p_->GPGet) ;
    printf("	GPPut          %x\n",p_->GPPut) ;
    printf("	Ignored05      %p\n",p_->Ignored05) ;
}
void pretty_print(struct NV0080_ALLOC_PARAMETERS* p_){
  printf("NV0080_ALLOC_PARAMETERS\n");
    printf("	deviceId         %x\n",p_->deviceId) ;
    printf("	hClientShare     %x\n",p_->hClientShare) ;
    printf("	hTargetClient    %x\n",p_->hTargetClient) ;
    printf("	hTargetDevice    %x\n",p_->hTargetDevice) ;
    printf("	flags            %x\n",p_->flags) ;
    printf("	vaSpaceSize      %llx\n",p_->vaSpaceSize) ;
    printf("	vaStartInternal  %llx\n",p_->vaStartInternal) ;
    printf("	vaLimitInternal  %llx\n",p_->vaLimitInternal) ;
    printf("	vaMode           %x\n",p_->vaMode) ;
}
void pretty_print(struct NV2080_ALLOC_PARAMETERS* p_){
  printf("NV2080_ALLOC_PARAMETERS\n");
    printf("	subDeviceId  %x\n",p_->subDeviceId) ;
}
void pretty_print(struct NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS* p_){
  printf("NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS\n");
    printf("	pciDeviceId     %x\n",p_->pciDeviceId) ;
    printf("	pciSubSystemId  %x\n",p_->pciSubSystemId) ;
    printf("	pciRevisionId   %x\n",p_->pciRevisionId) ;
    printf("	pciExtDeviceId  %x\n",p_->pciExtDeviceId) ;
}
void pretty_print(struct NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS* p_){
  printf("NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS\n");
    printf("	pciBarCount  %x\n",p_->pciBarCount) ;
    printf("	pciBarInfo   %p\n",p_->pciBarInfo) ;
}
void pretty_print(struct NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS* p_){
  printf("NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS\n");
    printf("	architecture    %x\n",p_->architecture) ;
    printf("	implementation  %x\n",p_->implementation) ;
    printf("	revision        %x\n",p_->revision) ;
    printf("	subRevision     %lx\n",(uint64_t)(p_->subRevision) );
}
void pretty_print(struct NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS* p_){
  printf("NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS\n");
    printf("	engines  %x\n",p_->engines) ;
}
void pretty_print(struct NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS\n");
    printf("	hChannel         %x\n",p_->hChannel) ;
    printf("	totalBufferSize  %llx\n",p_->totalBufferSize) ;
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS\n");
    printf("	engineCount  %x\n",p_->engineCount);
    printf("	engineList   %p\n",p_->engineList);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_GID_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_GID_INFO_PARAMS\n");
    printf("	index   %x\n",p_->index) ;
    printf("	flags   %x\n",p_->flags) ;
    printf("	length  %x\n",p_->length) ;
    printf("	data    %p\n",p_->data);
    //for(int i = 0; i < 0x100 ; i ++){printf("%hhu " , p_->data[i]);}
}
void pretty_print(struct NV2080_CTRL_GSP_GET_FEATURES_PARAMS* p_){
  printf("NV2080_CTRL_GSP_GET_FEATURES_PARAMS\n");
    printf("	gspFeatures       %x\n",p_->gspFeatures) ;
    printf("	bValid            %lx\n",(uint64_t)(p_->bValid) );
    printf("	bDefaultGspRmGpu  %lx\n",(uint64_t)(p_->bDefaultGspRmGpu) );
    printf("	firmwareVersion   %p\n",p_->firmwareVersion) ;
}
void pretty_print(struct NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS\n");
    printf("	numChannels         %x\n",p_->numChannels);
    printf("	pChannelHandleList  %p\n",p_->pChannelHandleList);
    printf("	pChannelList        %p\n",p_->pChannelList) ;
    uint32_t* ptr = (uint32_t*)p_->pChannelHandleList;
    uint32_t* ptr_1 = (uint32_t*)p_->pChannelList;
    for(int i = 0 ; i  < 2 ; i ++){if(*ptr != 0){printf("\t%p: %x\n" , ptr, *ptr);ptr++;}}
    printf("pChannelList DUMP\n");
    for(int i = 0 ; i  < 0x1  ; i ++){if(*ptr_1 != 0){printf("\t%p: %x\n" , ptr_1, *ptr_1);ptr_1++;}}
}
void pretty_print(struct NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS* p_){
  printf("NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS\n");
    printf("	numClasses  %x\n",p_->numClasses) ;
    printf("	classList   %p\n",p_->classList) ;
    for(int i = 0 ; i < 160 ; i++){if(p_->classList[i] != 0){printf("%d %x\n" ,i , p_->classList[i]);}}
}
void pretty_print(struct NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS* p_){
  printf("NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS\n");
    printf("	capsTbl  %p\n",p_->capsTbl) ;
}
void pretty_print(struct NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS* p_){
  printf("NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS\n");
    printf("	hObject        %x\n",p_->hObject) ;
    printf("	classEngineID  %x\n",p_->classEngineID) ;
    printf("	classID        %x\n",p_->classID) ;
    printf("	engineID       %x\n",p_->engineID) ;
}
void pretty_print(struct NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS* p_){
  printf("NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS\n");
    //*(((uint32_t*)&(p_->workSubmitToken))) = 0x100;
    printf("	workSubmitToken  %x\n",p_->workSubmitToken);
}
void pretty_print(struct NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS\n");
    printf("	hObject        %x\n",p_->hObject) ;
    printf("	mapFlags       %x\n",p_->mapFlags) ;
    printf("	addrSpaceType  %x\n",p_->addrSpaceType) ;
}
void pretty_print(struct NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS\n");
    printf("sharePolicy LMAO POPRAVI OVO\n");
}
void pretty_print(struct NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS\n");
    printf("	gpuIds  %p\n",p_->gpuIds) ;
	if (p_->gpuIds != NULL){
	  for(int i = 0 ; i < 32; i ++){if(p_->gpuIds[i]){printf("%d: %x\n",i ,p_->gpuIds[i]);}}
	}
}
void pretty_print(struct NV0000_CTRL_GPU_GET_ID_INFO_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_ID_INFO_PARAMS\n");
    printf("	gpuId              %x\n",p_->gpuId) ;
    printf("	gpuFlags           %x\n",p_->gpuFlags) ;
    printf("	deviceInstance     %x\n",p_->deviceInstance) ;
    printf("	subDeviceInstance  %x\n",p_->subDeviceInstance) ;
    printf("	szName             %p\n",p_->szName) ;
	//if (p_->szName != NULL){
	//  for(int i = 0 ; i < 32; i ++){if(p_->szName[i]){printf("%d: %x\n",i ,p_->szName[i]);}}
	//}
    printf("	sliStatus          %x\n",p_->sliStatus) ;
    printf("	boardId            %x\n",p_->boardId) ;
    printf("	gpuInstance        %x\n",p_->gpuInstance) ;
    printf("	numaId             %lx\n",(uint64_t)(p_->numaId) );
}
void pretty_print(struct NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS\n");
    printf("	gpuId              %x\n",p_->gpuId) ;
    printf("	gpuFlags           %x\n",p_->gpuFlags) ;
    printf("	deviceInstance     %x\n",p_->deviceInstance) ;
    printf("	subDeviceInstance  %x\n",p_->subDeviceInstance) ;
    printf("	sliStatus          %x\n",p_->sliStatus) ;
    printf("	boardId            %x\n",p_->boardId) ;
    printf("	gpuInstance        %x\n",p_->gpuInstance) ;
    printf("	numaId             %lx\n",(uint64_t)(p_->numaId) );
}
void pretty_print(struct NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS\n");
    printf("	gpuIds          %p\n",p_->gpuIds) ;
	if (p_->gpuIds != NULL){
	  for(int i = 0 ; i < 32; i ++){if(p_->gpuIds[i]){printf("%d: %x\n",i ,p_->gpuIds[i]);}}
	}
    printf("	excludedGpuIds  %p\n",p_->excludedGpuIds) ;
	if (p_->excludedGpuIds != NULL){
	  for(int i = 0 ; i < 32; i ++){if(p_->excludedGpuIds[i]){printf("%d: %x\n",i ,p_->excludedGpuIds[i]);}}
	}
}
void pretty_print(struct NV0000_CTRL_GPU_ATTACH_IDS_PARAMS* p_){
  printf("NV0000_CTRL_GPU_ATTACH_IDS_PARAMS\n");
    printf("	gpuIds    %p\n",p_->gpuIds) ;
	if (p_->gpuIds != NULL){
	  for(int i = 0 ; i < 32; i ++){if(p_->gpuIds[i]){printf("%d: %x\n",i ,p_->gpuIds[i]);}}
	}
    printf("	failedId  %x\n",p_->failedId) ;
}
void pretty_print(struct NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS\n");
    printf("	enableMask  %x\n",p_->enableMask) ;
}
void get_uvm_ioct(int nr,void *argp){
  switch(nr){
    case UVM_INITIALIZE:{
      UVM_INITIALIZE_PARAMS *p = (UVM_INITIALIZE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_RESERVE_VA:{
      UVM_RESERVE_VA_PARAMS *p = (UVM_RESERVE_VA_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_RELEASE_VA:{
      UVM_RELEASE_VA_PARAMS *p = (UVM_RELEASE_VA_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_REGION_COMMIT:{
      UVM_REGION_COMMIT_PARAMS *p = (UVM_REGION_COMMIT_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_REGION_DECOMMIT:{
      UVM_REGION_DECOMMIT_PARAMS *p = (UVM_REGION_DECOMMIT_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_REGION_SET_STREAM:{
      UVM_REGION_SET_STREAM_PARAMS *p = (UVM_REGION_SET_STREAM_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_SET_STREAM_RUNNING:{
      UVM_SET_STREAM_RUNNING_PARAMS *p = (UVM_SET_STREAM_RUNNING_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_SET_STREAM_STOPPED:{
      UVM_SET_STREAM_STOPPED_PARAMS *p = (UVM_SET_STREAM_STOPPED_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_RUN_TEST:{
      UVM_RUN_TEST_PARAMS *p = (UVM_RUN_TEST_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_ADD_SESSION:{
      UVM_ADD_SESSION_PARAMS *p = (UVM_ADD_SESSION_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_REMOVE_SESSION:{
      UVM_REMOVE_SESSION_PARAMS *p = (UVM_REMOVE_SESSION_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_ENABLE_COUNTERS:{
      UVM_ENABLE_COUNTERS_PARAMS *p = (UVM_ENABLE_COUNTERS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_MAP_COUNTER:{
      UVM_MAP_COUNTER_PARAMS *p = (UVM_MAP_COUNTER_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_CREATE_EVENT_QUEUE:{
      UVM_CREATE_EVENT_QUEUE_PARAMS *p = (UVM_CREATE_EVENT_QUEUE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_REMOVE_EVENT_QUEUE:{
      UVM_REMOVE_EVENT_QUEUE_PARAMS *p = (UVM_REMOVE_EVENT_QUEUE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_MAP_EVENT_QUEUE:{
      UVM_MAP_EVENT_QUEUE_PARAMS *p = (UVM_MAP_EVENT_QUEUE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_EVENT_CTRL:{
      UVM_EVENT_CTRL_PARAMS *p = (UVM_EVENT_CTRL_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_REGISTER_MPS_SERVER:{
      UVM_REGISTER_MPS_SERVER_PARAMS *p = (UVM_REGISTER_MPS_SERVER_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_REGISTER_MPS_CLIENT:{
      UVM_REGISTER_MPS_CLIENT_PARAMS *p = (UVM_REGISTER_MPS_CLIENT_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_GET_GPU_UUID_TABLE:{
      UVM_GET_GPU_UUID_TABLE_PARAMS *p = (UVM_GET_GPU_UUID_TABLE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_CREATE_RANGE_GROUP:{
      UVM_CREATE_RANGE_GROUP_PARAMS *p = (UVM_CREATE_RANGE_GROUP_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_DESTROY_RANGE_GROUP:{
      UVM_DESTROY_RANGE_GROUP_PARAMS *p = (UVM_DESTROY_RANGE_GROUP_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_REGISTER_GPU_VASPACE:{
      UVM_REGISTER_GPU_VASPACE_PARAMS *p = (UVM_REGISTER_GPU_VASPACE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_UNREGISTER_GPU_VASPACE:{
      UVM_UNREGISTER_GPU_VASPACE_PARAMS *p = (UVM_UNREGISTER_GPU_VASPACE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_REGISTER_CHANNEL:{
      UVM_REGISTER_CHANNEL_PARAMS *p = (UVM_REGISTER_CHANNEL_PARAMS*)argp; pretty_print(p);
      break;
    }
    case UVM_UNREGISTER_CHANNEL:{
      UVM_UNREGISTER_CHANNEL_PARAMS *p = (UVM_UNREGISTER_CHANNEL_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_ENABLE_PEER_ACCESS:{
      UVM_ENABLE_PEER_ACCESS_PARAMS *p = (UVM_ENABLE_PEER_ACCESS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_DISABLE_PEER_ACCESS:{
      UVM_DISABLE_PEER_ACCESS_PARAMS *p = (UVM_DISABLE_PEER_ACCESS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_SET_RANGE_GROUP:{
      UVM_SET_RANGE_GROUP_PARAMS *p = (UVM_SET_RANGE_GROUP_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_MAP_EXTERNAL_ALLOCATION:{
      UVM_MAP_EXTERNAL_ALLOCATION_PARAMS *p = (UVM_MAP_EXTERNAL_ALLOCATION_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_FREE:{
      UVM_FREE_PARAMS *p = (UVM_FREE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_MEM_MAP:{
      UVM_MEM_MAP_PARAMS *p = (UVM_MEM_MAP_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_DEBUG_ACCESS_MEMORY:{
      UVM_DEBUG_ACCESS_MEMORY_PARAMS *p = (UVM_DEBUG_ACCESS_MEMORY_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_REGISTER_GPU:{
      UVM_REGISTER_GPU_PARAMS *p = (UVM_REGISTER_GPU_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_UNREGISTER_GPU:{
      UVM_UNREGISTER_GPU_PARAMS *p = (UVM_UNREGISTER_GPU_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_PAGEABLE_MEM_ACCESS:{
      UVM_PAGEABLE_MEM_ACCESS_PARAMS *p = (UVM_PAGEABLE_MEM_ACCESS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_PREVENT_MIGRATION_RANGE_GROUPS:{
      UVM_PREVENT_MIGRATION_RANGE_GROUPS_PARAMS *p = (UVM_PREVENT_MIGRATION_RANGE_GROUPS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_ALLOW_MIGRATION_RANGE_GROUPS:{
      UVM_ALLOW_MIGRATION_RANGE_GROUPS_PARAMS *p = (UVM_ALLOW_MIGRATION_RANGE_GROUPS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_SET_PREFERRED_LOCATION:{
      UVM_SET_PREFERRED_LOCATION_PARAMS *p = (UVM_SET_PREFERRED_LOCATION_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_UNSET_PREFERRED_LOCATION:{
      UVM_UNSET_PREFERRED_LOCATION_PARAMS *p = (UVM_UNSET_PREFERRED_LOCATION_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_ENABLE_READ_DUPLICATION:{
      UVM_ENABLE_READ_DUPLICATION_PARAMS *p = (UVM_ENABLE_READ_DUPLICATION_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_DISABLE_READ_DUPLICATION:{
      UVM_DISABLE_READ_DUPLICATION_PARAMS *p = (UVM_DISABLE_READ_DUPLICATION_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_SET_ACCESSED_BY:{
      UVM_SET_ACCESSED_BY_PARAMS *p = (UVM_SET_ACCESSED_BY_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_UNSET_ACCESSED_BY:{
      UVM_UNSET_ACCESSED_BY_PARAMS *p = (UVM_UNSET_ACCESSED_BY_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_MIGRATE:{
      UVM_MIGRATE_PARAMS *p = (UVM_MIGRATE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_MIGRATE_RANGE_GROUP:{
      UVM_MIGRATE_RANGE_GROUP_PARAMS *p = (UVM_MIGRATE_RANGE_GROUP_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_ENABLE_SYSTEM_WIDE_ATOMICS:{
      UVM_ENABLE_SYSTEM_WIDE_ATOMICS_PARAMS *p = (UVM_ENABLE_SYSTEM_WIDE_ATOMICS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_DISABLE_SYSTEM_WIDE_ATOMICS:{
      UVM_DISABLE_SYSTEM_WIDE_ATOMICS_PARAMS *p = (UVM_DISABLE_SYSTEM_WIDE_ATOMICS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_TOOLS_INIT_EVENT_TRACKER:{
      UVM_TOOLS_INIT_EVENT_TRACKER_PARAMS *p = (UVM_TOOLS_INIT_EVENT_TRACKER_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_TOOLS_SET_NOTIFICATION_THRESHOLD:{
      UVM_TOOLS_SET_NOTIFICATION_THRESHOLD_PARAMS *p = (UVM_TOOLS_SET_NOTIFICATION_THRESHOLD_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_TOOLS_EVENT_QUEUE_ENABLE_EVENTS:{
      UVM_TOOLS_EVENT_QUEUE_ENABLE_EVENTS_PARAMS *p = (UVM_TOOLS_EVENT_QUEUE_ENABLE_EVENTS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_TOOLS_EVENT_QUEUE_DISABLE_EVENTS:{
      UVM_TOOLS_EVENT_QUEUE_DISABLE_EVENTS_PARAMS *p = (UVM_TOOLS_EVENT_QUEUE_DISABLE_EVENTS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_TOOLS_ENABLE_COUNTERS:{
      UVM_TOOLS_ENABLE_COUNTERS_PARAMS *p = (UVM_TOOLS_ENABLE_COUNTERS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_TOOLS_DISABLE_COUNTERS:{
      UVM_TOOLS_DISABLE_COUNTERS_PARAMS *p = (UVM_TOOLS_DISABLE_COUNTERS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_TOOLS_READ_PROCESS_MEMORY:{
      UVM_TOOLS_READ_PROCESS_MEMORY_PARAMS *p = (UVM_TOOLS_READ_PROCESS_MEMORY_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_TOOLS_WRITE_PROCESS_MEMORY:{
      UVM_TOOLS_WRITE_PROCESS_MEMORY_PARAMS *p = (UVM_TOOLS_WRITE_PROCESS_MEMORY_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_TOOLS_GET_PROCESSOR_UUID_TABLE:{
      UVM_TOOLS_GET_PROCESSOR_UUID_TABLE_PARAMS *p = (UVM_TOOLS_GET_PROCESSOR_UUID_TABLE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_MAP_DYNAMIC_PARALLELISM_REGION:{
      UVM_MAP_DYNAMIC_PARALLELISM_REGION_PARAMS *p = (UVM_MAP_DYNAMIC_PARALLELISM_REGION_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_UNMAP_EXTERNAL:{
      UVM_UNMAP_EXTERNAL_PARAMS *p = (UVM_UNMAP_EXTERNAL_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_TOOLS_FLUSH_EVENTS:{
      UVM_TOOLS_FLUSH_EVENTS_PARAMS *p = (UVM_TOOLS_FLUSH_EVENTS_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_ALLOC_SEMAPHORE_POOL:{
      UVM_ALLOC_SEMAPHORE_POOL_PARAMS *p = (UVM_ALLOC_SEMAPHORE_POOL_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_CLEAN_UP_ZOMBIE_RESOURCES:{
      UVM_CLEAN_UP_ZOMBIE_RESOURCES_PARAMS *p = (UVM_CLEAN_UP_ZOMBIE_RESOURCES_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_PAGEABLE_MEM_ACCESS_ON_GPU:{
      UVM_PAGEABLE_MEM_ACCESS_ON_GPU_PARAMS *p = (UVM_PAGEABLE_MEM_ACCESS_ON_GPU_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_POPULATE_PAGEABLE:{
      UVM_POPULATE_PAGEABLE_PARAMS *p = (UVM_POPULATE_PAGEABLE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_VALIDATE_VA_RANGE:{
      UVM_VALIDATE_VA_RANGE_PARAMS *p = (UVM_VALIDATE_VA_RANGE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_CREATE_EXTERNAL_RANGE:{
      UVM_CREATE_EXTERNAL_RANGE_PARAMS *p = (UVM_CREATE_EXTERNAL_RANGE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_MAP_EXTERNAL_SPARSE:{
      UVM_MAP_EXTERNAL_SPARSE_PARAMS *p = (UVM_MAP_EXTERNAL_SPARSE_PARAMS*)argp; pretty_print(p);break;
    }
    case UVM_MM_INITIALIZE:{
      UVM_MM_INITIALIZE_PARAMS *p = (UVM_MM_INITIALIZE_PARAMS*)argp; pretty_print(p);break;
    }
    default:printf("NIJE  UVM\n");
  }
}

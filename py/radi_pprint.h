void pretty_print( NV_CHANNEL_ALLOC_PARAMS* p_){
  printf("NV_CHANNEL_ALLOC_PARAMS\n");
    printf("	hObjectError        %x\n", p_->hObjectError);
    printf("	hObjectBuffer       %x\n", p_->hObjectBuffer);
    printf("	gpFifoOffset        %llx\n", p_->gpFifoOffset);
    printf("	gpFifoEntries       %x\n", p_->gpFifoEntries);
    printf("	flags               %x\n", p_->flags);
    printf("	hContextShare       %x\n", p_->hContextShare);
    printf("	hVASpace            %x\n", p_->hVASpace);
    printf("	hUserdMemory        %p\n", &p_->hUserdMemory);// fix this
    printf("	userdOffset         %p\n", &p_->userdOffset);// fix this
    printf("	engineType          %x\n", p_->engineType);
    printf("	cid                 %x\n", p_->cid);
    printf("	subDeviceId         %x\n", p_->subDeviceId);
    printf("	hObjectEccError     %x\n", p_->hObjectEccError);
    printf("	instanceMem         %p\n", &p_->instanceMem);// fix this
    printf("	userdMem            %p\n", &p_->userdMem);// fix this
    printf("	ramfcMem            %p\n", &p_->ramfcMem);// fix this
    printf("	mthdbufMem          %p\n", &p_->mthdbufMem);// fix this
    printf("	hPhysChannelGroup   %x\n", p_->hPhysChannelGroup);
    printf("	internalFlags       %x\n", p_->internalFlags);
    printf("	errorNotifierMem    %p\n", &p_->errorNotifierMem);// fix this
    printf("	eccErrorNotifierMem %p\n", &p_->eccErrorNotifierMem);// fix this
    printf("	ProcessID           %x\n", p_->ProcessID);
    printf("	SubProcessID        %x\n", p_->SubProcessID);
    printf("	encryptIv           %p\n", &p_->encryptIv);// fix this
    printf("	decryptIv           %p\n", &p_->decryptIv);// fix this
    printf("	hmacNonce           %p\n", &p_->hmacNonce);// fix this
}
void pretty_print( NVOS00_PARAMETERS* p_){
  printf("NVOS00_PARAMETERS\n");
    printf("	hRoot         %x\n", p_->hRoot);
    printf("	hObjectParent %x\n", p_->hObjectParent);
    printf("	hObjectOld    %x\n", p_->hObjectOld);
    printf("	status        %x\n", p_->status);
}
void pretty_print( NV_MEMORY_ALLOCATION_PARAMS* p_){
  printf("NV_MEMORY_ALLOCATION_PARAMS\n");
    printf("	owner         %x\n", p_->owner);
    printf("	type          %x\n", p_->type);
    printf("	flags         %x\n", p_->flags);
    printf("	width         %x\n", p_->width);
    printf("	height        %x\n", p_->height);
    printf("	pitch         %x\n", p_->pitch);
    printf("	attr          %x\n", p_->attr);
    printf("	attr2         %x\n", p_->attr2);
    printf("	format        %x\n", p_->format);
    printf("	comprCovg     %x\n", p_->comprCovg);
    printf("	zcullCovg     %x\n", p_->zcullCovg);
    printf("	rangeLo       %llx\n", p_->rangeLo);
    printf("	rangeHi       %llx\n", p_->rangeHi);
    printf("	size          %llx\n", p_->size);
    printf("	alignment     %llx\n", p_->alignment);
    printf("	offset        %llx\n", p_->offset);
    printf("	limit         %llx\n", p_->limit);
    printf("	address       %p\n", p_->address);
    printf("	ctagOffset    %x\n", p_->ctagOffset);
    printf("	hVASpace      %x\n", p_->hVASpace);
    printf("	internalflags %x\n", p_->internalflags);
    printf("	tag           %x\n", p_->tag);
    printf("	numaNode      %x\n", p_->numaNode);
}
void pretty_print( NVOS33_PARAMETERS* p_){
  printf("NVOS33_PARAMETERS\n");
    printf("	hClient        %x\n", p_->hClient);
    printf("	hDevice        %x\n", p_->hDevice);
    printf("	hMemory        %x\n", p_->hMemory);
    printf("	offset         %llx\n", p_->offset);
    printf("	length         %llx\n", p_->length);
    printf("	pLinearAddress %p\n", p_->pLinearAddress);
    printf("	status         %x\n", p_->status);
    printf("	flags          %x\n", p_->flags);
}
void pretty_print( NVOS56_PARAMETERS* p_){
  printf("NVOS56_PARAMETERS\n");
    printf("	hClient        %x\n", p_->hClient);
    printf("	hDevice        %x\n", p_->hDevice);
    printf("	hMemory        %x\n", p_->hMemory);
    printf("	pOldCpuAddress %p\n", p_->pOldCpuAddress);
    printf("	pNewCpuAddress %p\n", p_->pNewCpuAddress);
    printf("	status         %x\n", p_->status);
}
void pretty_print( NV_GR_ALLOCATION_PARAMETERS* p_){
  printf("NV_GR_ALLOCATION_PARAMETERS\n");
    printf("	version %x\n", p_->version);
    printf("	flags   %x\n", p_->flags);
    printf("	size    %x\n", p_->size);
    printf("	caps    %x\n", p_->caps);
}
void pretty_print( NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS* p_){
  printf("NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS\n");
    printf("	hObjectError                %x\n", p_->hObjectError);
    printf("	hObjectEccError             %x\n", p_->hObjectEccError);
    printf("	hVASpace                    %x\n", p_->hVASpace);
    printf("	engineType                  %x\n", p_->engineType);
    printf("	bIsCallingContextVgpuPlugin %x\n", p_->bIsCallingContextVgpuPlugin);
}
void pretty_print( NV_VASPACE_ALLOCATION_PARAMETERS* p_){
  printf("NV_VASPACE_ALLOCATION_PARAMETERS\n");
    printf("	index           %x\n", p_->index);
    printf("	flags           %x\n", p_->flags);
    printf("	vaSize          %llx\n", p_->vaSize);
    printf("	vaStartInternal %llx\n", p_->vaStartInternal);
    printf("	vaLimitInternal %llx\n", p_->vaLimitInternal);
    printf("	bigPageSize     %x\n", p_->bigPageSize);
    printf("	vaBase          %llx\n", p_->vaBase);
}
void pretty_print( NV_CTXSHARE_ALLOCATION_PARAMETERS* p_){
  printf("NV_CTXSHARE_ALLOCATION_PARAMETERS\n");
    printf("	hVASpace %x\n", p_->hVASpace);
    printf("	flags    %x\n", p_->flags);
    printf("	subctxId %x\n", p_->subctxId);
}
void pretty_print( UVM_RESERVE_VA_PARAMS* p_){
  printf("UVM_RESERVE_VA_PARAMS\n");
    printf("	requestedBase %llx\n", p_->requestedBase);
    printf("	length        %llx\n", p_->length);
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_RELEASE_VA_PARAMS* p_){
  printf("UVM_RELEASE_VA_PARAMS\n");
    printf("	requestedBase %llx\n", p_->requestedBase);
    printf("	length        %llx\n", p_->length);
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_REGION_COMMIT_PARAMS* p_){
  printf("UVM_REGION_COMMIT_PARAMS\n");
    printf("	requestedBase %llx\n", p_->requestedBase);
    printf("	length        %llx\n", p_->length);
    printf("	streamId      %p\n", &p_->streamId);// fix this
    printf("	gpuUuid       %p\n", &p_->gpuUuid);// fix this
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_REGION_DECOMMIT_PARAMS* p_){
  printf("UVM_REGION_DECOMMIT_PARAMS\n");
    printf("	requestedBase %llx\n", p_->requestedBase);
    printf("	length        %llx\n", p_->length);
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_REGION_SET_STREAM_PARAMS* p_){
  printf("UVM_REGION_SET_STREAM_PARAMS\n");
    printf("	requestedBase %llx\n", p_->requestedBase);
    printf("	length        %llx\n", p_->length);
    printf("	newStreamId   %p\n", &p_->newStreamId);// fix this
    printf("	gpuUuid       %p\n", &p_->gpuUuid);// fix this
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_SET_STREAM_RUNNING_PARAMS* p_){
  printf("UVM_SET_STREAM_RUNNING_PARAMS\n");
    printf("	streamId %p\n", &p_->streamId);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_SET_STREAM_STOPPED_PARAMS* p_){
  printf("UVM_SET_STREAM_STOPPED_PARAMS\n");
    printf("	streamIdArray %p\n", &p_->streamIdArray);// fix this
    printf("	nStreams      %llx\n", p_->nStreams);
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_RUN_TEST_PARAMS* p_){
  printf("UVM_RUN_TEST_PARAMS\n");
    printf("	gpuUuid  %p\n", &p_->gpuUuid);// fix this
    printf("	test     %x\n", p_->test);
    printf("	multiGpu %p\n", &p_->multiGpu);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_ADD_SESSION_PARAMS* p_){
  printf("UVM_ADD_SESSION_PARAMS\n");
    printf("	pidTarget           %x\n", p_->pidTarget);
    printf("	countersBaseAddress %p\n", p_->countersBaseAddress);
    printf("	sessionIndex        %x\n", p_->sessionIndex);
    printf("	rmStatus            %x\n", p_->rmStatus);
}
void pretty_print( UVM_REMOVE_SESSION_PARAMS* p_){
  printf("UVM_REMOVE_SESSION_PARAMS\n");
    printf("	sessionIndex %x\n", p_->sessionIndex);
    printf("	rmStatus     %x\n", p_->rmStatus);
}
void pretty_print( UVM_ENABLE_COUNTERS_PARAMS* p_){
  printf("UVM_ENABLE_COUNTERS_PARAMS\n");
    printf("	sessionIndex %x\n", p_->sessionIndex);
    printf("	config       %p\n", &p_->config);// fix this
    printf("	count        %x\n", p_->count);
    printf("	rmStatus     %x\n", p_->rmStatus);
}
void pretty_print( UVM_MAP_COUNTER_PARAMS* p_){
  printf("UVM_MAP_COUNTER_PARAMS\n");
    printf("	sessionIndex %x\n", p_->sessionIndex);
    printf("	scope        %x\n", p_->scope);
    printf("	counterName  %x\n", p_->counterName);
    printf("	gpuUuid      %p\n", &p_->gpuUuid);// fix this
    printf("	addr         %p\n", p_->addr);
    printf("	rmStatus     %x\n", p_->rmStatus);
}
void pretty_print( UVM_CREATE_EVENT_QUEUE_PARAMS* p_){
  printf("UVM_CREATE_EVENT_QUEUE_PARAMS\n");
    printf("	sessionIndex      %x\n", p_->sessionIndex);
    printf("	eventQueueIndex   %x\n", p_->eventQueueIndex);
    printf("	queueSize         %llx\n", p_->queueSize);
    printf("	notificationCount %llx\n", p_->notificationCount);
    printf("	timeStampType     %x\n", p_->timeStampType);
    printf("	rmStatus          %x\n", p_->rmStatus);
}
void pretty_print( UVM_REMOVE_EVENT_QUEUE_PARAMS* p_){
  printf("UVM_REMOVE_EVENT_QUEUE_PARAMS\n");
    printf("	sessionIndex    %x\n", p_->sessionIndex);
    printf("	eventQueueIndex %x\n", p_->eventQueueIndex);
    printf("	rmStatus        %x\n", p_->rmStatus);
}
void pretty_print( UVM_MAP_EVENT_QUEUE_PARAMS* p_){
  printf("UVM_MAP_EVENT_QUEUE_PARAMS\n");
    printf("	sessionIndex    %x\n", p_->sessionIndex);
    printf("	eventQueueIndex %x\n", p_->eventQueueIndex);
    printf("	userRODataAddr  %p\n", p_->userRODataAddr);
    printf("	userRWDataAddr  %p\n", p_->userRWDataAddr);
    printf("	readIndexAddr   %p\n", p_->readIndexAddr);
    printf("	writeIndexAddr  %p\n", p_->writeIndexAddr);
    printf("	queueBufferAddr %p\n", p_->queueBufferAddr);
    printf("	rmStatus        %x\n", p_->rmStatus);
}
void pretty_print( UVM_EVENT_CTRL_PARAMS* p_){
  printf("UVM_EVENT_CTRL_PARAMS\n");
    printf("	sessionIndex    %x\n", p_->sessionIndex);
    printf("	eventQueueIndex %x\n", p_->eventQueueIndex);
    printf("	eventType       %x\n", p_->eventType);
    printf("	enable          %x\n", p_->enable);
    printf("	rmStatus        %x\n", p_->rmStatus);
}
void pretty_print( UVM_REGISTER_MPS_SERVER_PARAMS* p_){
  printf("UVM_REGISTER_MPS_SERVER_PARAMS\n");
    printf("	gpuUuidArray %p\n", &p_->gpuUuidArray);// fix this
    printf("	numGpus      %x\n", p_->numGpus);
    printf("	serverId     %llx\n", p_->serverId);
    printf("	rmStatus     %x\n", p_->rmStatus);
}
void pretty_print( UVM_REGISTER_MPS_CLIENT_PARAMS* p_){
  printf("UVM_REGISTER_MPS_CLIENT_PARAMS\n");
    printf("	serverId %llx\n", p_->serverId);
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_GET_GPU_UUID_TABLE_PARAMS* p_){
  printf("UVM_GET_GPU_UUID_TABLE_PARAMS\n");
    printf("	gpuUuidArray %p\n", &p_->gpuUuidArray);// fix this
    printf("	validCount   %x\n", p_->validCount);
    printf("	rmStatus     %x\n", p_->rmStatus);
}
void pretty_print( UVM_CREATE_RANGE_GROUP_PARAMS* p_){
  printf("UVM_CREATE_RANGE_GROUP_PARAMS\n");
    printf("	rangeGroupId %llx\n", p_->rangeGroupId);
    printf("	rmStatus     %x\n", p_->rmStatus);
}
void pretty_print( UVM_DESTROY_RANGE_GROUP_PARAMS* p_){
  printf("UVM_DESTROY_RANGE_GROUP_PARAMS\n");
    printf("	rangeGroupId %llx\n", p_->rangeGroupId);
    printf("	rmStatus     %x\n", p_->rmStatus);
}
void pretty_print( UVM_REGISTER_GPU_VASPACE_PARAMS* p_){
  printf("UVM_REGISTER_GPU_VASPACE_PARAMS\n");
    printf("	gpuUuid  %p\n", &p_->gpuUuid);// fix this
    printf("	rmCtrlFd %x\n", p_->rmCtrlFd);
    printf("	hClient  %x\n", p_->hClient);
    printf("	hVaSpace %x\n", p_->hVaSpace);
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_UNREGISTER_GPU_VASPACE_PARAMS* p_){
  printf("UVM_UNREGISTER_GPU_VASPACE_PARAMS\n");
    printf("	gpuUuid  %p\n", &p_->gpuUuid);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_REGISTER_CHANNEL_PARAMS* p_){
  printf("UVM_REGISTER_CHANNEL_PARAMS\n");
    printf("	gpuUuid  %p\n", &p_->gpuUuid);// fix this
    printf("	rmCtrlFd %x\n", p_->rmCtrlFd);
    printf("	hClient  %x\n", p_->hClient);
    printf("	hChannel %x\n", p_->hChannel);
    printf("	base     %llx\n", p_->base);
    printf("	length   %llx\n", p_->length);
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_UNREGISTER_CHANNEL_PARAMS* p_){
  printf("UVM_UNREGISTER_CHANNEL_PARAMS\n");
    printf("	gpuUuid  %p\n", &p_->gpuUuid);// fix this
    printf("	hClient  %x\n", p_->hClient);
    printf("	hChannel %x\n", p_->hChannel);
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_ENABLE_PEER_ACCESS_PARAMS* p_){
  printf("UVM_ENABLE_PEER_ACCESS_PARAMS\n");
    printf("	gpuUuidA %p\n", &p_->gpuUuidA);// fix this
    printf("	gpuUuidB %p\n", &p_->gpuUuidB);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_DISABLE_PEER_ACCESS_PARAMS* p_){
  printf("UVM_DISABLE_PEER_ACCESS_PARAMS\n");
    printf("	gpuUuidA %p\n", &p_->gpuUuidA);// fix this
    printf("	gpuUuidB %p\n", &p_->gpuUuidB);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_SET_RANGE_GROUP_PARAMS* p_){
  printf("UVM_SET_RANGE_GROUP_PARAMS\n");
    printf("	rangeGroupId  %llx\n", p_->rangeGroupId);
    printf("	requestedBase %llx\n", p_->requestedBase);
    printf("	length        %llx\n", p_->length);
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_MAP_EXTERNAL_ALLOCATION_PARAMS* p_){
  printf("UVM_MAP_EXTERNAL_ALLOCATION_PARAMS\n");
    printf("	base               %llx\n", p_->base);
    printf("	length             %llx\n", p_->length);
    printf("	offset             %llx\n", p_->offset);
    printf("	perGpuAttributes   %p\n", &p_->perGpuAttributes);// fix this
    printf("	gpuAttributesCount %llx\n", p_->gpuAttributesCount);
    printf("	rmCtrlFd           %x\n", p_->rmCtrlFd);
    printf("	hClient            %x\n", p_->hClient);
    printf("	hMemory            %x\n", p_->hMemory);
    printf("	rmStatus           %x\n", p_->rmStatus);
}
void pretty_print( UVM_FREE_PARAMS* p_){
  printf("UVM_FREE_PARAMS\n");
    printf("	base     %llx\n", p_->base);
    printf("	length   %llx\n", p_->length);
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_MEM_MAP_PARAMS* p_){
  printf("UVM_MEM_MAP_PARAMS\n");
    printf("	regionBase   %p\n", p_->regionBase);
    printf("	regionLength %llx\n", p_->regionLength);
    printf("	rmStatus     %x\n", p_->rmStatus);
}
void pretty_print( UVM_DEBUG_ACCESS_MEMORY_PARAMS* p_){
  printf("UVM_DEBUG_ACCESS_MEMORY_PARAMS\n");
    printf("	sessionIndex %x\n", p_->sessionIndex);
    printf("	baseAddress  %llx\n", p_->baseAddress);
    printf("	sizeInBytes  %llx\n", p_->sizeInBytes);
    printf("	accessType   %x\n", p_->accessType);
    printf("	buffer       %llx\n", p_->buffer);
    printf("	isBitmaskSet %x\n", p_->isBitmaskSet);
    printf("	bitmask      %llx\n", p_->bitmask);
    printf("	rmStatus     %x\n", p_->rmStatus);
}
void pretty_print( UVM_REGISTER_GPU_PARAMS* p_){
  printf("UVM_REGISTER_GPU_PARAMS\n");
    printf("	gpu_uuid    %p\n", &p_->gpu_uuid);// fix this
    printf("	numaEnabled %x\n", p_->numaEnabled);
    printf("	numaNodeId  %x\n", p_->numaNodeId);
    printf("	rmCtrlFd    %x\n", p_->rmCtrlFd);
    printf("	hClient     %x\n", p_->hClient);
    printf("	hSmcPartRef %x\n", p_->hSmcPartRef);
    printf("	rmStatus    %x\n", p_->rmStatus);
}
void pretty_print( UVM_UNREGISTER_GPU_PARAMS* p_){
  printf("UVM_UNREGISTER_GPU_PARAMS\n");
    printf("	gpu_uuid %p\n", &p_->gpu_uuid);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_PAGEABLE_MEM_ACCESS_PARAMS* p_){
  printf("UVM_PAGEABLE_MEM_ACCESS_PARAMS\n");
    printf("	pageableMemAccess %x\n", p_->pageableMemAccess);
    printf("	rmStatus          %x\n", p_->rmStatus);
}
void pretty_print( UVM_PREVENT_MIGRATION_RANGE_GROUPS_PARAMS* p_){
  printf("UVM_PREVENT_MIGRATION_RANGE_GROUPS_PARAMS\n");
    printf("	rangeGroupIds %p\n", &p_->rangeGroupIds);// fix this
    printf("	numGroupIds   %llx\n", p_->numGroupIds);
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_ALLOW_MIGRATION_RANGE_GROUPS_PARAMS* p_){
  printf("UVM_ALLOW_MIGRATION_RANGE_GROUPS_PARAMS\n");
    printf("	rangeGroupIds %p\n", &p_->rangeGroupIds);// fix this
    printf("	numGroupIds   %llx\n", p_->numGroupIds);
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_SET_PREFERRED_LOCATION_PARAMS* p_){
  printf("UVM_SET_PREFERRED_LOCATION_PARAMS\n");
    printf("	requestedBase     %llx\n", p_->requestedBase);
    printf("	length            %llx\n", p_->length);
    printf("	preferredLocation %p\n", &p_->preferredLocation);// fix this
    printf("	rmStatus          %x\n", p_->rmStatus);
}
void pretty_print( UVM_UNSET_PREFERRED_LOCATION_PARAMS* p_){
  printf("UVM_UNSET_PREFERRED_LOCATION_PARAMS\n");
    printf("	requestedBase %llx\n", p_->requestedBase);
    printf("	length        %llx\n", p_->length);
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_ENABLE_READ_DUPLICATION_PARAMS* p_){
  printf("UVM_ENABLE_READ_DUPLICATION_PARAMS\n");
    printf("	requestedBase %llx\n", p_->requestedBase);
    printf("	length        %llx\n", p_->length);
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_DISABLE_READ_DUPLICATION_PARAMS* p_){
  printf("UVM_DISABLE_READ_DUPLICATION_PARAMS\n");
    printf("	requestedBase %llx\n", p_->requestedBase);
    printf("	length        %llx\n", p_->length);
    printf("	rmStatus      %x\n", p_->rmStatus);
}
void pretty_print( UVM_SET_ACCESSED_BY_PARAMS* p_){
  printf("UVM_SET_ACCESSED_BY_PARAMS\n");
    printf("	requestedBase  %llx\n", p_->requestedBase);
    printf("	length         %llx\n", p_->length);
    printf("	accessedByUuid %p\n", &p_->accessedByUuid);// fix this
    printf("	rmStatus       %x\n", p_->rmStatus);
}
void pretty_print( UVM_UNSET_ACCESSED_BY_PARAMS* p_){
  printf("UVM_UNSET_ACCESSED_BY_PARAMS\n");
    printf("	requestedBase  %llx\n", p_->requestedBase);
    printf("	length         %llx\n", p_->length);
    printf("	accessedByUuid %p\n", &p_->accessedByUuid);// fix this
    printf("	rmStatus       %x\n", p_->rmStatus);
}
void pretty_print( UVM_MIGRATE_PARAMS* p_){
  printf("UVM_MIGRATE_PARAMS\n");
    printf("	base             %llx\n", p_->base);
    printf("	length           %llx\n", p_->length);
    printf("	destinationUuid  %p\n", &p_->destinationUuid);// fix this
    printf("	flags            %x\n", p_->flags);
    printf("	semaphoreAddress %llx\n", p_->semaphoreAddress);
    printf("	semaphorePayload %x\n", p_->semaphorePayload);
    printf("	cpuNumaNode      %x\n", p_->cpuNumaNode);
    printf("	userSpaceStart   %llx\n", p_->userSpaceStart);
    printf("	userSpaceLength  %llx\n", p_->userSpaceLength);
    printf("	rmStatus         %x\n", p_->rmStatus);
}
void pretty_print( UVM_MIGRATE_RANGE_GROUP_PARAMS* p_){
  printf("UVM_MIGRATE_RANGE_GROUP_PARAMS\n");
    printf("	rangeGroupId    %llx\n", p_->rangeGroupId);
    printf("	destinationUuid %p\n", &p_->destinationUuid);// fix this
    printf("	rmStatus        %x\n", p_->rmStatus);
}
void pretty_print( UVM_ENABLE_SYSTEM_WIDE_ATOMICS_PARAMS* p_){
  printf("UVM_ENABLE_SYSTEM_WIDE_ATOMICS_PARAMS\n");
    printf("	gpu_uuid %p\n", &p_->gpu_uuid);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_DISABLE_SYSTEM_WIDE_ATOMICS_PARAMS* p_){
  printf("UVM_DISABLE_SYSTEM_WIDE_ATOMICS_PARAMS\n");
    printf("	gpu_uuid %p\n", &p_->gpu_uuid);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_TOOLS_INIT_EVENT_TRACKER_PARAMS* p_){
  printf("UVM_TOOLS_INIT_EVENT_TRACKER_PARAMS\n");
    printf("	queueBuffer     %llx\n", p_->queueBuffer);
    printf("	queueBufferSize %llx\n", p_->queueBufferSize);
    printf("	controlBuffer   %llx\n", p_->controlBuffer);
    printf("	processor       %p\n", &p_->processor);// fix this
    printf("	allProcessors   %x\n", p_->allProcessors);
    printf("	uvmFd           %x\n", p_->uvmFd);
    printf("	rmStatus        %x\n", p_->rmStatus);
}
void pretty_print( UVM_TOOLS_SET_NOTIFICATION_THRESHOLD_PARAMS* p_){
  printf("UVM_TOOLS_SET_NOTIFICATION_THRESHOLD_PARAMS\n");
    printf("	notificationThreshold %x\n", p_->notificationThreshold);
    printf("	rmStatus              %x\n", p_->rmStatus);
}
void pretty_print( UVM_TOOLS_EVENT_QUEUE_ENABLE_EVENTS_PARAMS* p_){
  printf("UVM_TOOLS_EVENT_QUEUE_ENABLE_EVENTS_PARAMS\n");
    printf("	eventTypeFlags %llx\n", p_->eventTypeFlags);
    printf("	rmStatus       %x\n", p_->rmStatus);
}
void pretty_print( UVM_TOOLS_EVENT_QUEUE_DISABLE_EVENTS_PARAMS* p_){
  printf("UVM_TOOLS_EVENT_QUEUE_DISABLE_EVENTS_PARAMS\n");
    printf("	eventTypeFlags %llx\n", p_->eventTypeFlags);
    printf("	rmStatus       %x\n", p_->rmStatus);
}
void pretty_print( UVM_TOOLS_ENABLE_COUNTERS_PARAMS* p_){
  printf("UVM_TOOLS_ENABLE_COUNTERS_PARAMS\n");
    printf("	counterTypeFlags %llx\n", p_->counterTypeFlags);
    printf("	rmStatus         %x\n", p_->rmStatus);
}
void pretty_print( UVM_TOOLS_DISABLE_COUNTERS_PARAMS* p_){
  printf("UVM_TOOLS_DISABLE_COUNTERS_PARAMS\n");
    printf("	counterTypeFlags %llx\n", p_->counterTypeFlags);
    printf("	rmStatus         %x\n", p_->rmStatus);
}
void pretty_print( UVM_TOOLS_READ_PROCESS_MEMORY_PARAMS* p_){
  printf("UVM_TOOLS_READ_PROCESS_MEMORY_PARAMS\n");
    printf("	buffer    %llx\n", p_->buffer);
    printf("	size      %llx\n", p_->size);
    printf("	targetVa  %llx\n", p_->targetVa);
    printf("	bytesRead %llx\n", p_->bytesRead);
    printf("	rmStatus  %x\n", p_->rmStatus);
}
void pretty_print( UVM_TOOLS_WRITE_PROCESS_MEMORY_PARAMS* p_){
  printf("UVM_TOOLS_WRITE_PROCESS_MEMORY_PARAMS\n");
    printf("	buffer       %llx\n", p_->buffer);
    printf("	size         %llx\n", p_->size);
    printf("	targetVa     %llx\n", p_->targetVa);
    printf("	bytesWritten %llx\n", p_->bytesWritten);
    printf("	rmStatus     %x\n", p_->rmStatus);
}
void pretty_print( UVM_TOOLS_GET_PROCESSOR_UUID_TABLE_PARAMS* p_){
  printf("UVM_TOOLS_GET_PROCESSOR_UUID_TABLE_PARAMS\n");
    printf("	tablePtr %llx\n", p_->tablePtr);
    printf("	count    %x\n", p_->count);
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_MAP_DYNAMIC_PARALLELISM_REGION_PARAMS* p_){
  printf("UVM_MAP_DYNAMIC_PARALLELISM_REGION_PARAMS\n");
    printf("	base     %llx\n", p_->base);
    printf("	length   %llx\n", p_->length);
    printf("	gpuUuid  %p\n", &p_->gpuUuid);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_UNMAP_EXTERNAL_PARAMS* p_){
  printf("UVM_UNMAP_EXTERNAL_PARAMS\n");
    printf("	base     %llx\n", p_->base);
    printf("	length   %llx\n", p_->length);
    printf("	gpuUuid  %p\n", &p_->gpuUuid);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_TOOLS_FLUSH_EVENTS_PARAMS* p_){
  printf("UVM_TOOLS_FLUSH_EVENTS_PARAMS\n");
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_ALLOC_SEMAPHORE_POOL_PARAMS* p_){
  printf("UVM_ALLOC_SEMAPHORE_POOL_PARAMS\n");
    printf("	base               %llx\n", p_->base);
    printf("	length             %llx\n", p_->length);
    printf("	perGpuAttributes   %p\n", &p_->perGpuAttributes);// fix this
    printf("	gpuAttributesCount %llx\n", p_->gpuAttributesCount);
    printf("	rmStatus           %x\n", p_->rmStatus);
}
void pretty_print( UVM_CLEAN_UP_ZOMBIE_RESOURCES_PARAMS* p_){
  printf("UVM_CLEAN_UP_ZOMBIE_RESOURCES_PARAMS\n");
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_PAGEABLE_MEM_ACCESS_ON_GPU_PARAMS* p_){
  printf("UVM_PAGEABLE_MEM_ACCESS_ON_GPU_PARAMS\n");
    printf("	gpu_uuid          %p\n", &p_->gpu_uuid);// fix this
    printf("	pageableMemAccess %x\n", p_->pageableMemAccess);
    printf("	rmStatus          %x\n", p_->rmStatus);
}
void pretty_print( UVM_POPULATE_PAGEABLE_PARAMS* p_){
  printf("UVM_POPULATE_PAGEABLE_PARAMS\n");
    printf("	base     %llx\n", p_->base);
    printf("	length   %llx\n", p_->length);
    printf("	flags    %x\n", p_->flags);
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_VALIDATE_VA_RANGE_PARAMS* p_){
  printf("UVM_VALIDATE_VA_RANGE_PARAMS\n");
    printf("	base     %llx\n", p_->base);
    printf("	length   %llx\n", p_->length);
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_CREATE_EXTERNAL_RANGE_PARAMS* p_){
  printf("UVM_CREATE_EXTERNAL_RANGE_PARAMS\n");
    printf("	base     %llx\n", p_->base);
    printf("	length   %llx\n", p_->length);
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_MAP_EXTERNAL_SPARSE_PARAMS* p_){
  printf("UVM_MAP_EXTERNAL_SPARSE_PARAMS\n");
    printf("	base     %llx\n", p_->base);
    printf("	length   %llx\n", p_->length);
    printf("	gpuUuid  %p\n", &p_->gpuUuid);// fix this
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( UVM_MM_INITIALIZE_PARAMS* p_){
  printf("UVM_MM_INITIALIZE_PARAMS\n");
    printf("	uvmFd    %x\n", p_->uvmFd);
    printf("	rmStatus %x\n", p_->rmStatus);
}
void pretty_print( nv_ioctl_nvos02_parameters_with_fd* p_){
  printf("nv_ioctl_nvos02_parameters_with_fd\n");
    printf("	params %p\n", &p_->params);// fix this
    printf("	fd     %x\n", p_->fd);
}
void pretty_print( nv_ioctl_card_info_t* p_){
  printf("nv_ioctl_card_info_t\n");
    printf("	valid          %x\n", p_->valid);
    printf("	pci_info       %p\n", &p_->pci_info);// fix this
    printf("	gpu_id         %x\n", p_->gpu_id);
    printf("	interrupt_line %x\n", p_->interrupt_line);
    printf("	reg_address    %llx\n", p_->reg_address);
    printf("	reg_size       %llx\n", p_->reg_size);
    printf("	fb_address     %llx\n", p_->fb_address);
    printf("	fb_size        %llx\n", p_->fb_size);
    printf("	minor_number   %x\n", p_->minor_number);
    printf("	dev_name       %p\n", &p_->dev_name);// fix this
}
void pretty_print( nv_ioctl_alloc_os_event* p_){
  printf("nv_ioctl_alloc_os_event\n");
    printf("	hClient %x\n", p_->hClient);
    printf("	hDevice %x\n", p_->hDevice);
    printf("	fd      %x\n", p_->fd);
    printf("	Status  %x\n", p_->Status);
}
void pretty_print( nv_ioctl_sys_params_t* p_){
  printf("nv_ioctl_sys_params_t\n");
    printf("	memblock_size %llx\n", p_->memblock_size);
}
void pretty_print( nv_ioctl_register_fd* p_){
  printf("nv_ioctl_register_fd\n");
    printf("	ctl_fd %x\n", p_->ctl_fd);
}
void pretty_print( nv_ioctl_numa_info_t* p_){
  printf("nv_ioctl_numa_info_t\n");
    printf("	nid               %p\n", &p_->nid);// fix this
    printf("	status            %p\n", &p_->status);// fix this
    printf("	memblock_size     %p\n", &p_->memblock_size);// fix this
    printf("	numa_mem_addr     %p\n", &p_->numa_mem_addr);// fix this
    printf("	numa_mem_size     %p\n", &p_->numa_mem_size);// fix this
    printf("	use_auto_online   %p\n", &p_->use_auto_online);// fix this
    printf("	offline_addresses %p\n", &p_->offline_addresses);// fix this
}
void pretty_print( NVB0B5_ALLOCATION_PARAMETERS* p_){
  printf("NVB0B5_ALLOCATION_PARAMETERS\n");
    printf("	version    %x\n", p_->version);
    printf("	engineType %x\n", p_->engineType);
}
void pretty_print( NV0080_ALLOC_PARAMETERS* p_){
  printf("NV0080_ALLOC_PARAMETERS\n");
    printf("	deviceId        %x\n", p_->deviceId);
    printf("	hClientShare    %x\n", p_->hClientShare);
    printf("	hTargetClient   %x\n", p_->hTargetClient);
    printf("	hTargetDevice   %x\n", p_->hTargetDevice);
    printf("	flags           %x\n", p_->flags);
    printf("	vaSpaceSize     %llx\n", p_->vaSpaceSize);
    printf("	vaStartInternal %llx\n", p_->vaStartInternal);
    printf("	vaLimitInternal %llx\n", p_->vaLimitInternal);
    printf("	vaMode          %x\n", p_->vaMode);
}
void pretty_print( NV2080_ALLOC_PARAMETERS* p_){
  printf("NV2080_ALLOC_PARAMETERS\n");
    printf("	subDeviceId %x\n", p_->subDeviceId);
}
void pretty_print( NV0005_ALLOC_PARAMETERS* p_){
  printf("NV0005_ALLOC_PARAMETERS\n");
    printf("	hParentClient %x\n", p_->hParentClient);
    printf("	hSrcResource  %x\n", p_->hSrcResource);
    printf("	hClass        %x\n", p_->hClass);
    printf("	notifyIndex   %x\n", p_->notifyIndex);
    printf("	data          %p\n", p_->data);
}
void pretty_print( NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS* p_){
  printf("NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS\n");
    printf("	hObject       %x\n", p_->hObject);
    printf("	classEngineID %x\n", p_->classEngineID);
    printf("	classID       %x\n", p_->classID);
    printf("	engineID      %x\n", p_->engineID);
}
void pretty_print( NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS* p_){
  printf("NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS\n");
    printf("	bEnable     %x\n", p_->bEnable);
    printf("	bSkipSubmit %x\n", p_->bSkipSubmit);
}
void pretty_print( NV2080_CTRL_GR_GET_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_INFO_PARAMS\n");
    printf("	grInfoListSize %x\n", p_->grInfoListSize);
    printf("	grInfoList     %p\n", p_->grInfoList);
    printf("	grRouteInfo    %p\n", &p_->grRouteInfo);// fix this
}
void pretty_print( NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS\n");
    printf("	hChannel        %x\n", p_->hChannel);
    printf("	totalBufferSize %llx\n", p_->totalBufferSize);
}
void pretty_print( NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS\n");
    printf("	engineCount %x\n", p_->engineCount);
    printf("	engineList  %p\n", &p_->engineList);// fix this
}
void pretty_print( NV2080_CTRL_GPU_GET_GID_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_GID_INFO_PARAMS\n");
    printf("	index  %x\n", p_->index);
    printf("	flags  %x\n", p_->flags);
    printf("	length %x\n", p_->length);
    printf("	data   %p\n", &p_->data);// fix this
}
void pretty_print( NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS* p_){
  printf("NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS\n");
    printf("	workSubmitToken %x\n", p_->workSubmitToken);
}
void pretty_print( NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS* p_){
  printf("NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS\n");
    printf("	pciDeviceId    %x\n", p_->pciDeviceId);
    printf("	pciSubSystemId %x\n", p_->pciSubSystemId);
    printf("	pciRevisionId  %x\n", p_->pciRevisionId);
    printf("	pciExtDeviceId %x\n", p_->pciExtDeviceId);
}
void pretty_print( NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS* p_){
  printf("NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS\n");
    printf("	pciBarCount %x\n", p_->pciBarCount);
    printf("	pciBarInfo  %p\n", &p_->pciBarInfo);// fix this
}
void pretty_print( NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS* p_){
  printf("NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS\n");
    printf("	architecture   %x\n", p_->architecture);
    printf("	implementation %x\n", p_->implementation);
    printf("	revision       %x\n", p_->revision);
    printf("	subRevision    %p\n", &p_->subRevision);// fix this
}
void pretty_print( NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS* p_){
  printf("NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS\n");
    printf("	engines %x\n", p_->engines);
}
void pretty_print( NV2080_CTRL_GSP_GET_FEATURES_PARAMS* p_){
  printf("NV2080_CTRL_GSP_GET_FEATURES_PARAMS\n");
    printf("	gspFeatures      %x\n", p_->gspFeatures);
    printf("	bValid           %x\n", p_->bValid);
    printf("	bDefaultGspRmGpu %x\n", p_->bDefaultGspRmGpu);
    printf("	firmwareVersion  %p\n", &p_->firmwareVersion);// fix this
}
void pretty_print( NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS\n");
    printf("	numChannels        %x\n", p_->numChannels);
    printf("	pChannelHandleList %p\n", p_->pChannelHandleList);
    printf("	pChannelList       %p\n", p_->pChannelList);
}
void pretty_print( NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS* p_){
  printf("NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS\n");
    printf("	numClasses %x\n", p_->numClasses);
    printf("	classList  %p\n", &p_->classList);// fix this
}
void pretty_print( NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS* p_){
  printf("NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS\n");
    printf("	capsTbl %p\n", &p_->capsTbl);// fix this
}
void pretty_print( NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS\n");
    printf("	hObject       %x\n", p_->hObject);
    printf("	mapFlags      %x\n", p_->mapFlags);
    printf("	addrSpaceType %x\n", p_->addrSpaceType);
}
void pretty_print( NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS\n");
    printf("	gpuIds %p\n", &p_->gpuIds);// fix this
}
void pretty_print( NV0000_CTRL_GPU_GET_ID_INFO_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_ID_INFO_PARAMS\n");
    printf("	gpuId             %x\n", p_->gpuId);
    printf("	gpuFlags          %x\n", p_->gpuFlags);
    printf("	deviceInstance    %x\n", p_->deviceInstance);
    printf("	subDeviceInstance %x\n", p_->subDeviceInstance);
    printf("	szName            %p\n", p_->szName);
    printf("	sliStatus         %x\n", p_->sliStatus);
    printf("	boardId           %x\n", p_->boardId);
    printf("	gpuInstance       %x\n", p_->gpuInstance);
    printf("	numaId            %x\n", p_->numaId);
}
void pretty_print( NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS\n");
    printf("	gpuId             %x\n", p_->gpuId);
    printf("	gpuFlags          %x\n", p_->gpuFlags);
    printf("	deviceInstance    %x\n", p_->deviceInstance);
    printf("	subDeviceInstance %x\n", p_->subDeviceInstance);
    printf("	sliStatus         %x\n", p_->sliStatus);
    printf("	boardId           %x\n", p_->boardId);
    printf("	gpuInstance       %x\n", p_->gpuInstance);
    printf("	numaId            %x\n", p_->numaId);
}
void pretty_print( NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS\n");
    printf("	gpuIds         %p\n", &p_->gpuIds);// fix this
    printf("	excludedGpuIds %p\n", &p_->excludedGpuIds);// fix this
}
void pretty_print( NV0000_CTRL_GPU_ATTACH_IDS_PARAMS* p_){
  printf("NV0000_CTRL_GPU_ATTACH_IDS_PARAMS\n");
    printf("	gpuIds   %p\n", &p_->gpuIds);// fix this
    printf("	failedId %x\n", p_->failedId);
}
void get_uvm_ioctl(uint32_t nr,void* argp){
  switch  (nr){
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
      UVM_REGISTER_CHANNEL_PARAMS *p = (UVM_REGISTER_CHANNEL_PARAMS*)argp; pretty_print(p);break;
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
    default:printf("not important :) \n");
  }
}
void get_command(uint32_t cm,void* params){
  switch  (cm){
    case NV2080_CTRL_CMD_GR_GET_INFO:{
      NV2080_CTRL_GR_GET_INFO_PARAMS *p = (NV2080_CTRL_GR_GET_INFO_PARAMS*)params; pretty_print(p);break;
    }
    case NVA06C_CTRL_CMD_GPFIFO_SCHEDULE:{
       NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS *p = ( NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS*)params; pretty_print(p);break;
    }
    case NV0080_CTRL_CMD_HOST_GET_CAPS_V2:{
       NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS *p = ( NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS*)params; pretty_print(p);break;
    }
    case NV2080_CTRL_CMD_GSP_GET_FEATURES:{
       NV2080_CTRL_GSP_GET_FEATURES_PARAMS *p = ( NV2080_CTRL_GSP_GET_FEATURES_PARAMS*)params; pretty_print(p);break;
    }
    case NV2080_CTRL_CMD_BUS_GET_PCI_INFO:{
       NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS *p = ( NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS*)params; pretty_print(p);break;
    }
    case NV0000_CTRL_CMD_GPU_ATTACH_IDS:{
       NV0000_CTRL_GPU_ATTACH_IDS_PARAMS *p = ( NV0000_CTRL_GPU_ATTACH_IDS_PARAMS*)params; pretty_print(p);break;
    }
    case NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2:{
       NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS *p = ( NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS*)params; pretty_print(p);break;
    }
    case NV0000_CTRL_CMD_GPU_GET_PROBED_IDS:{
       NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS *p = ( NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS*)params; pretty_print(p);break;
    }
    case NV0000_CTRL_CMD_GPU_GET_ID_INFO:{
       NV0000_CTRL_GPU_GET_ID_INFO_PARAMS *p = ( NV0000_CTRL_GPU_GET_ID_INFO_PARAMS*)params; pretty_print(p);break;
    }
    case NV0000_CTRL_CMD_GPU_GET_ATTACHED_IDS:{
       NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS *p = ( NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS*)params; pretty_print(p);break;
    }
    case NV0080_CTRL_CMD_GPU_GET_CLASSLIST_V2:{
       NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS *p = ( NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS*)params; pretty_print(p);break;
    }
    case NV2080_CTRL_CMD_BUS_GET_PCI_BAR_INFO:{
       NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS *p = ( NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS*)params; pretty_print(p);break;
    }
    case NV2080_CTRL_CMD_GPU_GET_ENGINES_V2:{
       NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS *p = ( NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS*)params; pretty_print(p);break;
    }
    case NV2080_CTRL_CMD_MC_GET_ARCH_INFO:{
       NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS *p = ( NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS*)params; pretty_print(p);break;
    }
    case NV2080_CTRL_CMD_MC_SERVICE_INTERRUPTS:{
       NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS *p = ( NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS*)params; pretty_print(p);break;
    }
    case NV2080_CTRL_CMD_GPU_GET_GID_INFO:{
       NV2080_CTRL_GPU_GET_GID_INFO_PARAMS *p = ( NV2080_CTRL_GPU_GET_GID_INFO_PARAMS*)params; pretty_print(p);break;
    }
    case NVC36F_CTRL_GET_CLASS_ENGINEID:{
       NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS *p = ( NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS*)params; pretty_print(p);break;
    }
    case NV2080_CTRL_CMD_GR_GET_CTX_BUFFER_SIZE:{
       NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS *p = ( NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS*)params; pretty_print(p);break;
    }
    case NV0080_CTRL_CMD_FIFO_GET_CHANNELLIST:{
       NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS *p = ( NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS*)params; pretty_print(p);break;
    }
    case NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN:{
       NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS *p = ( NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS*)params; pretty_print(p);break;
    }
    case NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE:{
       NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS *p = ( NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS*)params; pretty_print(p);break;
    }
    case NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY: {printf("NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY\n");break;}
    case NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER: {printf("NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER\n");break;}
    case NV00FD_CTRL_CMD_ATTACH_GPU: {printf("NV00FD_CTRL_CMD_ATTACH_GPU\n");break;}
    case NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION: {printf("NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION\n");break;}
    case NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO: {printf("NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO\n");break;}
    case NV0002_CTRL_CMD_UPDATE_CONTEXTDMA: {printf("NV0002_CTRL_CMD_UPDATE_CONTEXTDMA\n");break;}
    case NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS: {printf("NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS\n");break;}
    case NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE: {printf("NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE\n");break;}
    case NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS: {printf("NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS\n");break;}
    case NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO: {printf("NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO\n");break;}
    case NV2080_CTRL_CMD_GR_GET_CAPS_V2: {printf("NV2080_CTRL_CMD_GR_GET_CAPS_V2\n");break;}
    case NV2080_CTRL_CMD_CE_GET_ALL_CAPS: {printf("NV2080_CTRL_CMD_CE_GET_ALL_CAPS\n");break;}
    case NV2080_CTRL_CMD_GPU_QUERY_ECC_STATUS: {printf("NV2080_CTRL_CMD_GPU_QUERY_ECC_STATUS\n");break;}
    case NV2080_CTRL_CMD_GPU_GET_SHORT_NAME_STRING: {printf("NV2080_CTRL_CMD_GPU_GET_SHORT_NAME_STRING\n");break;}
    case NV2080_CTRL_CMD_GPU_GET_NAME_STRING: {printf("NV2080_CTRL_CMD_GPU_GET_NAME_STRING\n");break;}
    case NV2080_CTRL_CMD_GPU_QUERY_COMPUTE_MODE_RULES: {printf("NV2080_CTRL_CMD_GPU_QUERY_COMPUTE_MODE_RULES\n");break;}
    case NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS: {printf("NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS\n");break;}
    case NV2080_CTRL_CMD_RC_RELEASE_WATCHDOG_REQUESTS: {printf("NV2080_CTRL_CMD_RC_RELEASE_WATCHDOG_REQUESTS\n");break;}
    case NV2080_CTRL_CMD_RC_SOFT_DISABLE_WATCHDOG: {printf("NV2080_CTRL_CMD_RC_SOFT_DISABLE_WATCHDOG\n");break;}
    case NV2080_CTRL_CMD_BUS_GET_C2C_INFO: {printf("NV2080_CTRL_CMD_BUS_GET_C2C_INFO\n");break;}
    case NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES: {printf("NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES\n");break;}
    case NV_CONF_COMPUTE_CTRL_CMD_SYSTEM_GET_CAPABILITIES: {printf("NV_CONF_COMPUTE_CTRL_CMD_SYSTEM_GET_CAPABILITIES\n");break;}
    case NV83DE_CTRL_CMD_DEBUG_SET_EXCEPTION_MASK: {printf("NV83DE_CTRL_CMD_DEBUG_SET_EXCEPTION_MASK\n");break;}
    case NV2080_CTRL_CMD_GR_SET_CTXSW_PREEMPTION_MODE: {printf("NV2080_CTRL_CMD_GR_SET_CTXSW_PREEMPTION_MODE\n");break;}
    case NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE: {printf("NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE\n");break;}
    case NV2080_CTRL_CMD_GPU_GET_INFO: {printf("NV2080_CTRL_CMD_GPU_GET_INFO\n");break;}
    case NV2080_CTRL_CMD_GR_GET_GPC_MASK: {printf("NV2080_CTRL_CMD_GR_GET_GPC_MASK\n");break;}
    case NV2080_CTRL_CMD_GR_GET_TPC_MASK: {printf("NV2080_CTRL_CMD_GR_GET_TPC_MASK\n");break;}
    case NVA06C_CTRL_CMD_SET_TIMESLICE: {printf("NVA06C_CTRL_CMD_SET_TIMESLICE\n");break;}
    case NV2080_CTRL_CMD_PERF_BOOST: {printf("NV2080_CTRL_CMD_PERF_BOOST\n");break;}
    case NV2080_CTRL_CMD_BUS_GET_INFO_V2: {printf("NV2080_CTRL_CMD_BUS_GET_INFO_V2\n");break;}
    case NV0080_CTRL_CMD_FB_GET_CAPS_V2: {printf("NV0080_CTRL_CMD_FB_GET_CAPS_V2\n");break;}
    case NV2080_CTRL_CMD_FB_GET_INFO_V2: {printf("NV2080_CTRL_CMD_FB_GET_INFO_V2\n");break;}
    case NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE: {printf("NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE\n");break;}
    default:printf("not important :) \n");
  }
}
void get_alloc(uint32_t hClass,void* params){
  switch  (hClass){
    case NV01_EVENT_OS_EVENT:{
      NV0005_ALLOC_PARAMETERS *p = (NV0005_ALLOC_PARAMETERS*)params; pretty_print(p);break;
    }
    case NV50_MEMORY_VIRTUAL:{
      NV_MEMORY_ALLOCATION_PARAMS *p = (NV_MEMORY_ALLOCATION_PARAMS*)params; pretty_print(p);break;
    }
    case NV01_MEMORY_LOCAL_USER:{
      NV_MEMORY_ALLOCATION_PARAMS *p = (NV_MEMORY_ALLOCATION_PARAMS*)params; pretty_print(p);break;
    }
    case NV01_MEMORY_SYSTEM:{
      NV_MEMORY_ALLOCATION_PARAMS *p = (NV_MEMORY_ALLOCATION_PARAMS*)params; pretty_print(p);break;
    }
    case FERMI_CONTEXT_SHARE_A:{
      NV_CTXSHARE_ALLOCATION_PARAMETERS *p = (NV_CTXSHARE_ALLOCATION_PARAMETERS*)params; pretty_print(p);break;
    }
    case KEPLER_CHANNEL_GROUP_A:{
      NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS *p = (NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS*)params; pretty_print(p);break;
    }
    case TURING_COMPUTE_A:{
      NV_GR_ALLOCATION_PARAMETERS *p = (NV_GR_ALLOCATION_PARAMETERS*)params; pretty_print(p);break;
    }
    case FERMI_VASPACE_A:{
      NV_VASPACE_ALLOCATION_PARAMETERS *p = (NV_VASPACE_ALLOCATION_PARAMETERS*)params; pretty_print(p);break;
    }
    case NV0080_ALLOC_PARAMETERS_MESSAGE_ID:{
      NV0080_ALLOC_PARAMETERS *p = (NV0080_ALLOC_PARAMETERS*)params; pretty_print(p);break;
    }
    case NV2080_ALLOC_PARAMETERS_MESSAGE_ID:{
      NV2080_ALLOC_PARAMETERS *p = (NV2080_ALLOC_PARAMETERS*)params; pretty_print(p);break;
    }
    case TURING_CHANNEL_GPFIFO_A:{
      NV_CHANNEL_ALLOC_PARAMS *p = (NV_CHANNEL_ALLOC_PARAMS*)params; pretty_print(p);break;
    }
    case TURING_DMA_COPY_A:{
      NVB0B5_ALLOCATION_PARAMETERS *p = (NVB0B5_ALLOCATION_PARAMETERS*)params; pretty_print(p);break;
    }
    default:printf("not important :) \n");
  }
}

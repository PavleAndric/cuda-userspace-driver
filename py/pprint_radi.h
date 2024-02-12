void pretty_print(struct _clc5b5_tag0* p_){
  printf("_clc5b5_tag0\n");
    printf("	Reserved00              %p\n",p_->Reserved00);
    printf("	Nop                     %x\n",p_->Nop);
    printf("	Reserved01              %p\n",p_->Reserved01);
    printf("	PmTrigger               %x\n",p_->PmTrigger);
    printf("	Reserved02              %p\n",p_->Reserved02);
    printf("	SetSemaphoreA           %x\n",p_->SetSemaphoreA);
    printf("	SetSemaphoreB           %x\n",p_->SetSemaphoreB);
    printf("	SetSemaphorePayload     %x\n",p_->SetSemaphorePayload);
    printf("	Reserved03              %p\n",p_->Reserved03);
    printf("	SetRenderEnableA        %x\n",p_->SetRenderEnableA);
    printf("	SetRenderEnableB        %x\n",p_->SetRenderEnableB);
    printf("	SetRenderEnableC        %x\n",p_->SetRenderEnableC);
    printf("	SetSrcPhysMode          %x\n",p_->SetSrcPhysMode);
    printf("	SetDstPhysMode          %x\n",p_->SetDstPhysMode);
    printf("	Reserved04              %p\n",p_->Reserved04);
    printf("	SetGlobalCounterUpper   %x\n",p_->SetGlobalCounterUpper);
    printf("	SetGlobalCounterLower   %x\n",p_->SetGlobalCounterLower);
    printf("	SetPageoutStartPAUpper  %x\n",p_->SetPageoutStartPAUpper);
    printf("	SetPageoutStartPALower  %x\n",p_->SetPageoutStartPALower);
    printf("	Reserved05              %p\n",p_->Reserved05);
    printf("	LaunchDma               %x\n",p_->LaunchDma);
    printf("	Reserved06              %p\n",p_->Reserved06);
    printf("	OffsetInUpper           %x\n",p_->OffsetInUpper);
    printf("	OffsetInLower           %x\n",p_->OffsetInLower);
    printf("	OffsetOutUpper          %x\n",p_->OffsetOutUpper);
    printf("	OffsetOutLower          %x\n",p_->OffsetOutLower);
    printf("	PitchIn                 %x\n",p_->PitchIn);
    printf("	PitchOut                %x\n",p_->PitchOut);
    printf("	LineLengthIn            %x\n",p_->LineLengthIn);
    printf("	LineCount               %x\n",p_->LineCount);
    printf("	Reserved07              %p\n",p_->Reserved07);
    printf("	SetRemapConstA          %x\n",p_->SetRemapConstA);
    printf("	SetRemapConstB          %x\n",p_->SetRemapConstB);
    printf("	SetRemapComponents      %x\n",p_->SetRemapComponents);
    printf("	SetDstBlockSize         %x\n",p_->SetDstBlockSize);
    printf("	SetDstWidth             %x\n",p_->SetDstWidth);
    printf("	SetDstHeight            %x\n",p_->SetDstHeight);
    printf("	SetDstDepth             %x\n",p_->SetDstDepth);
    printf("	SetDstLayer             %x\n",p_->SetDstLayer);
    printf("	SetDstOrigin            %x\n",p_->SetDstOrigin);
    printf("	Reserved08              %p\n",p_->Reserved08);
    printf("	SetSrcBlockSize         %x\n",p_->SetSrcBlockSize);
    printf("	SetSrcWidth             %x\n",p_->SetSrcWidth);
    printf("	SetSrcHeight            %x\n",p_->SetSrcHeight);
    printf("	SetSrcDepth             %x\n",p_->SetSrcDepth);
    printf("	SetSrcLayer             %x\n",p_->SetSrcLayer);
    printf("	SetSrcOrigin            %x\n",p_->SetSrcOrigin);
    printf("	Reserved09              %p\n",p_->Reserved09);
    printf("	SrcOriginX              %x\n",p_->SrcOriginX);
    printf("	SrcOriginY              %x\n",p_->SrcOriginY);
    printf("	DstOriginX              %x\n",p_->DstOriginX);
    printf("	DstOriginY              %x\n",p_->DstOriginY);
    printf("	Reserved10              %p\n",p_->Reserved10);
    printf("	PmTriggerEnd            %x\n",p_->PmTriggerEnd);
    printf("	Reserved11              %p\n",p_->Reserved11);
}
void pretty_print(struct Nvc46fControl_struct* p_){
  printf("Nvc46fControl_struct\n");
    printf("	Ignored00      %p\n",p_->Ignored00);
    printf("	Put            %x\n",p_->Put);
    printf("	Get            %x\n",p_->Get);
    printf("	Reference      %x\n",p_->Reference);
    printf("	PutHi          %x\n",p_->PutHi);
    printf("	Ignored01      %p\n",p_->Ignored01);
    printf("	TopLevelGet    %x\n",p_->TopLevelGet);
    printf("	TopLevelGetHi  %x\n",p_->TopLevelGetHi);
    printf("	GetHi          %x\n",p_->GetHi);
    printf("	Ignored02      %p\n",p_->Ignored02);
    printf("	Ignored03      %x\n",p_->Ignored03);
    printf("	Ignored04      %p\n",p_->Ignored04);
    printf("	GPGet          %x\n",p_->GPGet);
    printf("	GPPut          %x\n",p_->GPPut);
    printf("	Ignored05      %p\n",p_->Ignored05);
}
void pretty_print(struct NV0080_ALLOC_PARAMETERS* p_){
  printf("NV0080_ALLOC_PARAMETERS\n");
    printf("	deviceId         %x\n",p_->deviceId);
    printf("	hClientShare     %x\n",p_->hClientShare);
    printf("	hTargetClient    %x\n",p_->hTargetClient);
    printf("	hTargetDevice    %x\n",p_->hTargetDevice);
    printf("	flags            %x\n",p_->flags);
    printf("	vaSpaceSize      %llx\n",p_->vaSpaceSize);
    printf("	vaStartInternal  %llx\n",p_->vaStartInternal);
    printf("	vaLimitInternal  %llx\n",p_->vaLimitInternal);
    printf("	vaMode           %x\n",p_->vaMode);
}
void pretty_print(struct NV2080_ALLOC_PARAMETERS* p_){
  printf("NV2080_ALLOC_PARAMETERS\n");
    printf("	subDeviceId  %x\n",p_->subDeviceId);
}
void pretty_print(struct NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS* p_){
  printf("NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS\n");
    printf("	pciDeviceId     %x\n",p_->pciDeviceId);
    printf("	pciSubSystemId  %x\n",p_->pciSubSystemId);
    printf("	pciRevisionId   %x\n",p_->pciRevisionId);
    printf("	pciExtDeviceId  %x\n",p_->pciExtDeviceId);
}
void pretty_print(struct NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS* p_){
  printf("NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS\n");
    printf("	pciBarCount  %x\n",p_->pciBarCount);
    printf("	pciBarInfo   %p\n",p_->pciBarInfo);
}
void pretty_print(struct NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS* p_){
  printf("NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS\n");
    printf("	architecture    %x\n",p_->architecture);
    printf("	implementation  %x\n",p_->implementation);
    printf("	revision        %x\n",p_->revision);
    printf("	subRevision     %x\n",p_->subRevision);
}
void pretty_print(struct NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS* p_){
  printf("NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS\n");
    printf("	engines  %x\n",p_->engines);
}
void pretty_print(struct NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS\n");
    printf("	hChannel         %x\n",p_->hChannel);
    printf("	totalBufferSize  %llx\n",p_->totalBufferSize);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS\n");
    printf("	engineCount  %x\n",p_->engineCount);
    printf("	engineList   %p\n",p_->engineList);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_GID_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_GID_INFO_PARAMS\n");
    printf("	index   %x\n",p_->index);
    printf("	flags   %x\n",p_->flags);
    printf("	length  %x\n",p_->length);
    printf("	data    %p\n",p_->data);
}
void pretty_print(struct NV2080_CTRL_GSP_GET_FEATURES_PARAMS* p_){
  printf("NV2080_CTRL_GSP_GET_FEATURES_PARAMS\n");
    printf("	gspFeatures       %x\n",p_->gspFeatures);
    printf("	bValid            %x\n",p_->bValid);
    printf("	bDefaultGspRmGpu  %x\n",p_->bDefaultGspRmGpu);
    printf("	firmwareVersion   %p\n",p_->firmwareVersion);
}
void pretty_print(struct NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS\n");
    printf("	numChannels         %x\n",p_->numChannels);
    printf("	pChannelHandleList  %p\n",p_->pChannelHandleList);
    printf("	pChannelList        %p\n",p_->pChannelList);
}
void pretty_print(struct NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS* p_){
  printf("NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS\n");
    printf("	numClasses  %x\n",p_->numClasses);
    printf("	classList   %p\n",p_->classList);
}
void pretty_print(struct NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS* p_){
  printf("NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS\n");
    printf("	capsTbl  %p\n",p_->capsTbl);
    for(int i = 0  ; i < 3; i ++ ){printf("p_->capsTbl[%d] = %x", i, p_->capsTbl[i]);}
}
void pretty_print(struct NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS* p_){
  printf("NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS\n");
    printf("	hObject        %x\n",p_->hObject);
    printf("	classEngineID  %x\n",p_->classEngineID);
    printf("	classID        %x\n",p_->classID);
    printf("	engineID       %x\n",p_->engineID);
}
void pretty_print(struct NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS* p_){
  printf("NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS\n");
    printf("	workSubmitToken  %x\n",p_->workSubmitToken);
}
void pretty_print(struct NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS\n");
    printf("	hObject        %x\n",p_->hObject);
    printf("	mapFlags       %x\n",p_->mapFlags);
    printf("	addrSpaceType  %x\n",p_->addrSpaceType);
}
void pretty_print(struct NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS\n");
    //printf("	sharePolicy  %x\n",p_->sharePolicy);
}
void pretty_print(struct NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS\n");
    printf("	gpuIds  %p\n",p_->gpuIds);
	if (p_->gpuIds != NULL){
	  for(int i = 0 ; i < 32; i ++){if(p_->gpuIds[i]){printf("%d: %x\n",i ,p_->gpuIds[i]);}}
	}
}
void pretty_print(struct NV0000_CTRL_GPU_GET_ID_INFO_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_ID_INFO_PARAMS\n");
    printf("	gpuId              %x\n",p_->gpuId);
    printf("	gpuFlags           %x\n",p_->gpuFlags);
    printf("	deviceInstance     %x\n",p_->deviceInstance);
    printf("	subDeviceInstance  %x\n",p_->subDeviceInstance);
    printf("	szName             %p\n",p_->szName);
	//if (p_->szName != NULL){
	//  for(int i = 0 ; i < 32; i ++){if(p_->szName[i]){printf("%d: %x\n",i ,p_->szName[i]);}}
	//}
    printf("	sliStatus          %x\n",p_->sliStatus);
    printf("	boardId            %x\n",p_->boardId);
    printf("	gpuInstance        %x\n",p_->gpuInstance);
    printf("	numaId             %x\n",p_->numaId);
}
void pretty_print(struct NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS\n");
    printf("	gpuId              %x\n",p_->gpuId);
    printf("	gpuFlags           %x\n",p_->gpuFlags);
    printf("	deviceInstance     %x\n",p_->deviceInstance);
    printf("	subDeviceInstance  %x\n",p_->subDeviceInstance);
    printf("	sliStatus          %x\n",p_->sliStatus);
    printf("	boardId            %x\n",p_->boardId);
    printf("	gpuInstance        %x\n",p_->gpuInstance);
    printf("	numaId             %x\n",p_->numaId);
}
void pretty_print(struct NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS\n");
    printf("	gpuIds          %p\n",p_->gpuIds);
	if (p_->gpuIds != NULL){
	  for(int i = 0 ; i < 32; i ++){if(p_->gpuIds[i]){printf("%d: %x\n",i ,p_->gpuIds[i]);}}
	}
    printf("	excludedGpuIds  %p\n",p_->excludedGpuIds);
	if (p_->excludedGpuIds != NULL){
	  for(int i = 0 ; i < 32; i ++){if(p_->excludedGpuIds[i]){printf("%d: %x\n",i ,p_->excludedGpuIds[i]);}}
	}
}
void pretty_print(struct NV0000_CTRL_GPU_ATTACH_IDS_PARAMS* p_){
  printf("NV0000_CTRL_GPU_ATTACH_IDS_PARAMS\n");
    printf("	gpuIds    %p\n",p_->gpuIds);
	if (p_->gpuIds != NULL){
	  for(int i = 0 ; i < 32; i ++){if(p_->gpuIds[i]){printf("%d: %x\n",i ,p_->gpuIds[i]);}}
	}
    printf("	failedId  %x\n",p_->failedId);
}
void pretty_print(struct NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS* p_){
  printf("NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS\n");
    printf("	enableMask  %x\n",p_->enableMask);
}

#include<stdio.h>
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
void pretty_print(struct _cl0080_tag0* p_){
  printf("_cl0080_tag0\n");
    printf("	Reserved00  %p\n",p_->Reserved00);
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
void pretty_print(struct _cl2080_tag0* p_){
  printf("_cl2080_tag0\n");
    printf("	Reserved00  %p\n",p_->Reserved00);
}
void pretty_print(struct Nv2080HdcpStatusChangeNotificationRec* p_){
  printf("Nv2080HdcpStatusChangeNotificationRec\n");
    printf("	displayId              %x\n",p_->displayId);
    printf("	hdcpStatusChangeNotif  %x\n",p_->hdcpStatusChangeNotif);
}
void pretty_print(struct Nv2080PStateChangeNotificationRec* p_){
  printf("Nv2080PStateChangeNotificationRec\n");
    printf("	timeStamp  %x\n",p_->timeStamp);
    printf("	NewPstate  %x\n",p_->NewPstate);
}
void pretty_print(struct Nv2080ClocksChangeNotificationRec* p_){
  printf("Nv2080ClocksChangeNotificationRec\n");
    printf("	timeStamp  %x\n",p_->timeStamp);
}
void pretty_print(struct Nv2080WorkloadModulationChangeNotificationRec* p_){
  printf("Nv2080WorkloadModulationChangeNotificationRec\n");
    printf("	timeStamp                  %x\n",p_->timeStamp);
    printf("	WorkloadModulationEnabled  %x\n",p_->WorkloadModulationEnabled);
}
void pretty_print(struct Nv2080DpIrqNotificationRec* p_){
  printf("Nv2080DpIrqNotificationRec\n");
    printf("	displayId  %x\n",p_->displayId);
}
void pretty_print(struct Nv2080DstateXusbPpcNotificationRec* p_){
  printf("Nv2080DstateXusbPpcNotificationRec\n");
    printf("	dstateXusb  %x\n",p_->dstateXusb);
    printf("	dstatePpc   %x\n",p_->dstatePpc);
}
void pretty_print(struct Nv2080XusbPpcConnectStateNotificationRec* p_){
  printf("Nv2080XusbPpcConnectStateNotificationRec\n");
    printf("	bConnected  %x\n",p_->bConnected);
}
void pretty_print(struct Nv2080ACPIEvent* p_){
  printf("Nv2080ACPIEvent\n");
    printf("	event  %x\n",p_->event);
}
void pretty_print(struct _NV2080_COOLER_DIAG_ZONE_NOTIFICATION_REC* p_){
  printf("_NV2080_COOLER_DIAG_ZONE_NOTIFICATION_REC\n");
    printf("	currentZone  %x\n",p_->currentZone);
}
void pretty_print(struct _NV2080_THERM_DIAG_ZONE_NOTIFICATION_REC* p_){
  printf("_NV2080_THERM_DIAG_ZONE_NOTIFICATION_REC\n");
    printf("	currentZone  %x\n",p_->currentZone);
}
void pretty_print(struct Nv2080AudioHdcpRequestRec* p_){
  printf("Nv2080AudioHdcpRequestRec\n");
    printf("	displayId       %x\n",p_->displayId);
    printf("	requestedState  %x\n",p_->requestedState);
}
void pretty_print(struct Nv2080GC5GpuReadyParams* p_){
  printf("Nv2080GC5GpuReadyParams\n");
    printf("	event     %x\n",p_->event);
    printf("	sciIntr0  %x\n",p_->sciIntr0);
    printf("	sciIntr1  %x\n",p_->sciIntr1);
}
void pretty_print(struct Nv2080DstateHdaCodecNotificationRec* p_){
  printf("Nv2080DstateHdaCodecNotificationRec\n");
    printf("	dstateHdaCodec  %x\n",p_->dstateHdaCodec);
}
void pretty_print(struct Nv2080HdmiFrlRequestNotificationRec* p_){
  printf("Nv2080HdmiFrlRequestNotificationRec\n");
    printf("	displayId  %x\n",p_->displayId);
}
void pretty_print(struct _NV2080_PLATFORM_POWER_MODE_CHANGE_STATUS* p_){
  printf("_NV2080_PLATFORM_POWER_MODE_CHANGE_STATUS\n");
    printf("	platformPowerModeIndex  %x\n",p_->platformPowerModeIndex);
    printf("	platformPowerModeMask   %x\n",p_->platformPowerModeMask);
    printf("	eventReason             %x\n",p_->eventReason);
}
void pretty_print(struct NV2080_ALLOC_PARAMETERS* p_){
  printf("NV2080_ALLOC_PARAMETERS\n");
    printf("	subDeviceId  %x\n",p_->subDeviceId);
}
void pretty_print(struct NVXXXX_CTRL_XXX_INFO* p_){
  printf("NVXXXX_CTRL_XXX_INFO\n");
    printf("	index  %x\n",p_->index);
    printf("	data   %x\n",p_->data);
}
void pretty_print(struct NV0080_CTRL_FIFO_GET_CAPS_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_GET_CAPS_PARAMS\n");
    printf("	capsTblSize  %x\n",p_->capsTblSize);
    printf("	capsTbl      %p\n",p_->capsTbl);
}
void pretty_print(struct NV0080_CTRL_FIFO_CHANNEL* p_){
  printf("NV0080_CTRL_FIFO_CHANNEL\n");
    printf("	hChannel  %x\n",p_->hChannel);
}
void pretty_print(struct NV0080_CTRL_FIFO_START_SELECTED_CHANNELS_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_START_SELECTED_CHANNELS_PARAMS\n");
    printf("	fifoStartChannelListCount  %x\n",p_->fifoStartChannelListCount);
    printf("	channelHandle              %p\n",p_->channelHandle);
    printf("	fifoStartChannelList       %p\n",p_->fifoStartChannelList);
}
void pretty_print(struct NV0080_CTRL_FIFO_GET_ENGINE_CONTEXT_PROPERTIES_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_GET_ENGINE_CONTEXT_PROPERTIES_PARAMS\n");
    printf("	engineId   %x\n",p_->engineId);
    printf("	alignment  %x\n",p_->alignment);
    printf("	size       %x\n",p_->size);
}
void pretty_print(struct NV0080_CTRL_FIFO_RUNLIST_GROUP_CHANNELS_PARAM* p_){
  printf("NV0080_CTRL_FIFO_RUNLIST_GROUP_CHANNELS_PARAM\n");
    printf("	hChannel1  %x\n",p_->hChannel1);
    printf("	hChannel2  %x\n",p_->hChannel2);
}
void pretty_print(struct NV0080_CTRL_FIFO_RUNLIST_DIVIDE_TIMESLICE_PARAM* p_){
  printf("NV0080_CTRL_FIFO_RUNLIST_DIVIDE_TIMESLICE_PARAM\n");
    printf("	hChannel   %x\n",p_->hChannel);
    printf("	tsDivisor  %x\n",p_->tsDivisor);
}
void pretty_print(struct NV0080_CTRL_FIFO_PREEMPT_RUNLIST_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_PREEMPT_RUNLIST_PARAMS\n");
    printf("	hRunlist  %x\n",p_->hRunlist);
    printf("	engineID  %x\n",p_->engineID);
}
void pretty_print(struct NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS\n");
    printf("	numChannels         %x\n",p_->numChannels);
    printf("	pChannelHandleList  %p\n",p_->pChannelHandleList);
    printf("	pChannelList        %p\n",p_->pChannelList);
}
void pretty_print(struct NV0080_CTRL_FIFO_GET_LATENCY_BUFFER_SIZE_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_GET_LATENCY_BUFFER_SIZE_PARAMS\n");
    printf("	engineID   %x\n",p_->engineID);
    printf("	gpEntries  %x\n",p_->gpEntries);
    printf("	pbEntries  %x\n",p_->pbEntries);
}
void pretty_print(struct NV0080_CTRL_FIFO_SET_CHANNEL_PROPERTIES_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_SET_CHANNEL_PROPERTIES_PARAMS\n");
    printf("	hChannel  %x\n",p_->hChannel);
    printf("	property  %x\n",p_->property);
    printf("	value     %llx\n",p_->value);
}
void pretty_print(struct NV0080_CTRL_FIFO_STOP_RUNLIST_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_STOP_RUNLIST_PARAMS\n");
    printf("	engineID  %x\n",p_->engineID);
}
void pretty_print(struct NV0080_CTRL_FIFO_START_RUNLIST_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_START_RUNLIST_PARAMS\n");
    printf("	engineID  %x\n",p_->engineID);
}
void pretty_print(struct NV0080_CTRL_FIFO_GET_CAPS_V2_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_GET_CAPS_V2_PARAMS\n");
    printf("	capsTbl  %p\n",p_->capsTbl);
}
void pretty_print(struct NV0080_CTRL_FIFO_IDLE_CHANNELS_PARAMS* p_){
  printf("NV0080_CTRL_FIFO_IDLE_CHANNELS_PARAMS\n");
    printf("	numChannels  %x\n",p_->numChannels);
    printf("	hChannels    %p\n",p_->hChannels);
    printf("	flags        %x\n",p_->flags);
    printf("	timeout      %x\n",p_->timeout);
}
void pretty_print(struct NV0080_CTRL_GR_ROUTE_INFO* p_){
  printf("NV0080_CTRL_GR_ROUTE_INFO\n");
    printf("	flags  %x\n",p_->flags);
    printf("	route  %llx\n",p_->route);
}
void pretty_print(struct NV0080_CTRL_GR_GET_CAPS_PARAMS* p_){
  printf("NV0080_CTRL_GR_GET_CAPS_PARAMS\n");
    printf("	capsTblSize  %x\n",p_->capsTblSize);
    printf("	capsTbl      %p\n",p_->capsTbl);
}
void pretty_print(struct NV0080_CTRL_GR_GET_INFO_PARAMS* p_){
  printf("NV0080_CTRL_GR_GET_INFO_PARAMS\n");
    printf("	grInfoListSize  %x\n",p_->grInfoListSize);
    printf("	grInfoList      %p\n",p_->grInfoList);
}
void pretty_print(struct NV0080_CTRL_GR_TPC_PARTITION_MODE_PARAMS* p_){
  printf("NV0080_CTRL_GR_TPC_PARTITION_MODE_PARAMS\n");
    printf("	hChannelGroup   %x\n",p_->hChannelGroup);
    printf("	mode            %x\n",p_->mode);
    printf("	bEnableAllTpcs  %x\n",p_->bEnableAllTpcs);
    printf("	grRouteInfo     %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV0080_CTRL_GR_GET_CAPS_V2_PARAMS* p_){
  printf("NV0080_CTRL_GR_GET_CAPS_V2_PARAMS\n");
    printf("	capsTbl         %p\n",p_->capsTbl);
    printf("	grRouteInfo     %x\n",p_->grRouteInfo);
    printf("	bCapsPopulated  %x\n",p_->bCapsPopulated);
}
void pretty_print(struct NV0080_CTRL_GR_GET_INFO_V2_PARAMS* p_){
  printf("NV0080_CTRL_GR_GET_INFO_V2_PARAMS\n");
    printf("	grInfoListSize  %x\n",p_->grInfoListSize);
    printf("	grInfoList      %p\n",p_->grInfoList);
    printf("	grRouteInfo     %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_GET_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_INFO_PARAMS\n");
    printf("	grInfoListSize  %x\n",p_->grInfoListSize);
    printf("	grInfoList      %p\n",p_->grInfoList);
    printf("	grRouteInfo     %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_CTXSW_ZCULL_MODE_PARAMS* p_){
  printf("NV2080_CTRL_GR_CTXSW_ZCULL_MODE_PARAMS\n");
    printf("	hChannel       %x\n",p_->hChannel);
    printf("	hShareClient   %x\n",p_->hShareClient);
    printf("	hShareChannel  %x\n",p_->hShareChannel);
    printf("	zcullMode      %x\n",p_->zcullMode);
}
void pretty_print(struct NV2080_CTRL_GR_GET_ZCULL_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_ZCULL_INFO_PARAMS\n");
    printf("	widthAlignPixels            %x\n",p_->widthAlignPixels);
    printf("	heightAlignPixels           %x\n",p_->heightAlignPixels);
    printf("	pixelSquaresByAliquots      %x\n",p_->pixelSquaresByAliquots);
    printf("	aliquotTotal                %x\n",p_->aliquotTotal);
    printf("	zcullRegionByteMultiplier   %x\n",p_->zcullRegionByteMultiplier);
    printf("	zcullRegionHeaderSize       %x\n",p_->zcullRegionHeaderSize);
    printf("	zcullSubregionHeaderSize    %x\n",p_->zcullSubregionHeaderSize);
    printf("	subregionCount              %x\n",p_->subregionCount);
    printf("	subregionWidthAlignPixels   %x\n",p_->subregionWidthAlignPixels);
    printf("	subregionHeightAlignPixels  %x\n",p_->subregionHeightAlignPixels);
}
void pretty_print(struct NV2080_CTRL_GR_CTXSW_PM_MODE_PARAMS* p_){
  printf("NV2080_CTRL_GR_CTXSW_PM_MODE_PARAMS\n");
    printf("	hChannel     %x\n",p_->hChannel);
    printf("	pmMode       %x\n",p_->pmMode);
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_CTXSW_ZCULL_BIND_PARAMS* p_){
  printf("NV2080_CTRL_GR_CTXSW_ZCULL_BIND_PARAMS\n");
    printf("	hClient    %x\n",p_->hClient);
    printf("	hChannel   %x\n",p_->hChannel);
    printf("	vMemPtr    %llx\n",p_->vMemPtr);
    printf("	zcullMode  %x\n",p_->zcullMode);
}
void pretty_print(struct NV2080_CTRL_GR_CTXSW_PM_BIND_PARAMS* p_){
  printf("NV2080_CTRL_GR_CTXSW_PM_BIND_PARAMS\n");
    printf("	hClient      %x\n",p_->hClient);
    printf("	hChannel     %x\n",p_->hChannel);
    printf("	vMemPtr      %llx\n",p_->vMemPtr);
    printf("	pmMode       %x\n",p_->pmMode);
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_SET_GPC_TILE_MAP_PARAMS* p_){
  printf("NV2080_CTRL_GR_SET_GPC_TILE_MAP_PARAMS\n");
    printf("	mapValueCount  %x\n",p_->mapValueCount);
    printf("	mapValues      %p\n",p_->mapValues);
    printf("	grRouteInfo    %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_CTXSW_SMPC_MODE_PARAMS* p_){
  printf("NV2080_CTRL_GR_CTXSW_SMPC_MODE_PARAMS\n");
    printf("	hChannel     %x\n",p_->hChannel);
    printf("	smpcMode     %x\n",p_->smpcMode);
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_GET_SM_TO_GPC_TPC_MAPPINGS_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_SM_TO_GPC_TPC_MAPPINGS_PARAMS\n");
    printf("	smId         %p\n",p_->smId);
    printf("	smCount      %x\n",p_->smCount);
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_SET_CTXSW_PREEMPTION_MODE_PARAMS* p_){
  printf("NV2080_CTRL_GR_SET_CTXSW_PREEMPTION_MODE_PARAMS\n");
    printf("	flags            %x\n",p_->flags);
    printf("	hChannel         %x\n",p_->hChannel);
    printf("	gfxpPreemptMode  %x\n",p_->gfxpPreemptMode);
    printf("	cilpPreemptMode  %x\n",p_->cilpPreemptMode);
    printf("	grRouteInfo      %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_CTXSW_PREEMPTION_BIND_PARAMS* p_){
  printf("NV2080_CTRL_GR_CTXSW_PREEMPTION_BIND_PARAMS\n");
    printf("	flags            %x\n",p_->flags);
    printf("	hClient          %x\n",p_->hClient);
    printf("	hChannel         %x\n",p_->hChannel);
    printf("	vMemPtrs         %x\n",p_->vMemPtrs);
    printf("	gfxpPreemptMode  %x\n",p_->gfxpPreemptMode);
    printf("	cilpPreemptMode  %x\n",p_->cilpPreemptMode);
    printf("	grRouteInfo      %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_PC_SAMPLING_MODE_PARAMS* p_){
  printf("NV2080_CTRL_GR_PC_SAMPLING_MODE_PARAMS\n");
    printf("	hChannel      %x\n",p_->hChannel);
    printf("	samplingMode  %x\n",p_->samplingMode);
    printf("	grRouteInfo   %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_GET_ROP_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_ROP_INFO_PARAMS\n");
    printf("	ropUnitCount         %x\n",p_->ropUnitCount);
    printf("	ropOperationsFactor  %x\n",p_->ropOperationsFactor);
    printf("	ropOperationsCount   %x\n",p_->ropOperationsCount);
}
void pretty_print(struct NV2080_CTRL_GR_GET_CTXSW_STATS_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_CTXSW_STATS_PARAMS\n");
    printf("	hChannel     %x\n",p_->hChannel);
    printf("	flags        %x\n",p_->flags);
    printf("	saveCnt      %x\n",p_->saveCnt);
    printf("	restoreCnt   %x\n",p_->restoreCnt);
    printf("	wfiSaveCnt   %x\n",p_->wfiSaveCnt);
    printf("	ctaSaveCnt   %x\n",p_->ctaSaveCnt);
    printf("	cilpSaveCnt  %x\n",p_->cilpSaveCnt);
    printf("	gfxpSaveCnt  %x\n",p_->gfxpSaveCnt);
}
void pretty_print(struct NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS\n");
    printf("	hChannel         %x\n",p_->hChannel);
    printf("	totalBufferSize  %llx\n",p_->totalBufferSize);
}
void pretty_print(struct NV2080_CTRL_GR_CTX_BUFFER_INFO* p_){
  printf("NV2080_CTRL_GR_CTX_BUFFER_INFO\n");
    printf("	alignment          %llx\n",p_->alignment);
    printf("	size               %llx\n",p_->size);
    printf("	bufferHandle       %p\n",p_->bufferHandle);
    printf("	pageCount          %llx\n",p_->pageCount);
    printf("	physAddr           %llx\n",p_->physAddr);
    printf("	bufferType         %x\n",p_->bufferType);
    printf("	aperture           %x\n",p_->aperture);
    printf("	kind               %x\n",p_->kind);
    printf("	pageSize           %x\n",p_->pageSize);
    printf("	bIsContigous       %x\n",p_->bIsContigous);
    printf("	bGlobalBuffer      %x\n",p_->bGlobalBuffer);
    printf("	bLocalBuffer       %x\n",p_->bLocalBuffer);
    printf("	bDeviceDescendant  %x\n",p_->bDeviceDescendant);
    printf("	uuid               %p\n",p_->uuid);
}
void pretty_print(struct NV2080_CTRL_GR_GET_CTX_BUFFER_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_CTX_BUFFER_INFO_PARAMS\n");
    printf("	hUserClient    %x\n",p_->hUserClient);
    printf("	hChannel       %x\n",p_->hChannel);
    printf("	bufferCount    %x\n",p_->bufferCount);
    printf("	ctxBufferInfo  %p\n",p_->ctxBufferInfo);
}
void pretty_print(struct NV2080_CTRL_GR_GET_GLOBAL_SM_ORDER_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_GLOBAL_SM_ORDER_PARAMS\n");
    printf("	globalSmId   %p\n",p_->globalSmId);
    printf("	numSm        %x\n",p_->numSm);
    printf("	numTpc       %x\n",p_->numTpc);
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_GET_CURRENT_RESIDENT_CHANNEL_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_CURRENT_RESIDENT_CHANNEL_PARAMS\n");
    printf("	chID         %x\n",p_->chID);
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GR_VAT_ALARM_DATA_PER_TPC* p_){
  printf("NV2080_CTRL_GR_VAT_ALARM_DATA_PER_TPC\n");
    printf("	errorCounter      %llx\n",p_->errorCounter);
    printf("	errorTimestamp    %llx\n",p_->errorTimestamp);
    printf("	warningCounter    %llx\n",p_->warningCounter);
    printf("	warningTimestamp  %llx\n",p_->warningTimestamp);
}
void pretty_print(struct NV2080_CTRL_GR_VAT_ALARM_DATA_PER_GPC* p_){
  printf("NV2080_CTRL_GR_VAT_ALARM_DATA_PER_GPC\n");
    printf("	tpc  %p\n",p_->tpc);
}
void pretty_print(struct NV2080_CTRL_GR_VAT_ALARM_DATA* p_){
  printf("NV2080_CTRL_GR_VAT_ALARM_DATA\n");
    printf("	gpc  %p\n",p_->gpc);
}
void pretty_print(struct NV2080_CTRL_GR_GET_VAT_ALARM_DATA_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_VAT_ALARM_DATA_PARAMS\n");
    printf("	smVatAlarm         %x\n",p_->smVatAlarm);
    printf("	maxGpcCount        %x\n",p_->maxGpcCount);
    printf("	maxTpcPerGpcCount  %x\n",p_->maxTpcPerGpcCount);
}
void pretty_print(struct NV2080_CTRL_GR_GET_ATTRIBUTE_BUFFER_SIZE_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_ATTRIBUTE_BUFFER_SIZE_PARAMS\n");
    printf("	attribBufferSize  %x\n",p_->attribBufferSize);
}
void pretty_print(struct NV2080_CTRL_GR_GFX_POOL_QUERY_SIZE_PARAMS* p_){
  printf("NV2080_CTRL_GR_GFX_POOL_QUERY_SIZE_PARAMS\n");
    printf("	maxSlots         %x\n",p_->maxSlots);
    printf("	slotStride       %x\n",p_->slotStride);
    printf("	ctrlStructSize   %llx\n",p_->ctrlStructSize);
    printf("	ctrlStructAlign  %llx\n",p_->ctrlStructAlign);
    printf("	poolSize         %llx\n",p_->poolSize);
    printf("	poolAlign        %llx\n",p_->poolAlign);
}
void pretty_print(struct NV2080_CTRL_GR_GFX_POOL_INITIALIZE_PARAMS* p_){
  printf("NV2080_CTRL_GR_GFX_POOL_INITIALIZE_PARAMS\n");
    printf("	maxSlots  %x\n",p_->maxSlots);
    printf("	hMemory   %x\n",p_->hMemory);
    printf("	offset    %x\n",p_->offset);
    printf("	size      %x\n",p_->size);
}
void pretty_print(struct NV2080_CTRL_GR_GFX_POOL_ADD_SLOTS_PARAMS* p_){
  printf("NV2080_CTRL_GR_GFX_POOL_ADD_SLOTS_PARAMS\n");
    printf("	numSlots  %x\n",p_->numSlots);
    printf("	slots     %p\n",p_->slots);
    printf("	hMemory   %x\n",p_->hMemory);
    printf("	offset    %x\n",p_->offset);
    printf("	size      %x\n",p_->size);
}
void pretty_print(struct NV2080_CTRL_GR_GFX_POOL_REMOVE_SLOTS_PARAMS* p_){
  printf("NV2080_CTRL_GR_GFX_POOL_REMOVE_SLOTS_PARAMS\n");
    printf("	numSlots              %x\n",p_->numSlots);
    printf("	slots                 %p\n",p_->slots);
    printf("	bRemoveSpecificSlots  %x\n",p_->bRemoveSpecificSlots);
    printf("	hMemory               %x\n",p_->hMemory);
    printf("	offset                %x\n",p_->offset);
    printf("	size                  %x\n",p_->size);
}
void pretty_print(struct NV2080_CTRL_GR_GET_GPC_MASK_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_GPC_MASK_PARAMS\n");
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
    printf("	gpcMask      %x\n",p_->gpcMask);
}
void pretty_print(struct NV2080_CTRL_GR_GET_TPC_MASK_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_TPC_MASK_PARAMS\n");
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
    printf("	gpcId        %x\n",p_->gpcId);
    printf("	tpcMask      %x\n",p_->tpcMask);
}
void pretty_print(struct NV2080_CTRL_GR_GET_ENGINE_CONTEXT_PROPERTIES_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_ENGINE_CONTEXT_PROPERTIES_PARAMS\n");
    printf("	grRouteInfo     %x\n",p_->grRouteInfo);
    printf("	engineId        %x\n",p_->engineId);
    printf("	alignment       %x\n",p_->alignment);
    printf("	size            %x\n",p_->size);
    printf("	bInfoPopulated  %x\n",p_->bInfoPopulated);
}
void pretty_print(struct NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS\n");
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
    printf("	imla0        %x\n",p_->imla0);
    printf("	fmla16       %x\n",p_->fmla16);
    printf("	dp           %x\n",p_->dp);
    printf("	fmla32       %x\n",p_->fmla32);
    printf("	ffma         %x\n",p_->ffma);
    printf("	imla1        %x\n",p_->imla1);
    printf("	imla2        %x\n",p_->imla2);
    printf("	imla3        %x\n",p_->imla3);
    printf("	imla4        %x\n",p_->imla4);
}
void pretty_print(struct NV2080_CTRL_GR_FECS_BIND_EVTBUF_FOR_UID_PARAMS* p_){
  printf("NV2080_CTRL_GR_FECS_BIND_EVTBUF_FOR_UID_PARAMS\n");
    printf("	hEventBuffer   %x\n",p_->hEventBuffer);
    printf("	recordSize     %x\n",p_->recordSize);
    printf("	levelOfDetail  %x\n",p_->levelOfDetail);
    printf("	eventFilter    %x\n",p_->eventFilter);
    printf("	bAllUsers      %x\n",p_->bAllUsers);
}
void pretty_print(struct NV2080_CTRL_GR_GET_PHYS_GPC_MASK_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_PHYS_GPC_MASK_PARAMS\n");
    printf("	physSyspipeId  %x\n",p_->physSyspipeId);
    printf("	gpcMask        %x\n",p_->gpcMask);
}
void pretty_print(struct NV2080_CTRL_GR_GET_PPC_MASK_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_PPC_MASK_PARAMS\n");
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
    printf("	gpcId        %x\n",p_->gpcId);
    printf("	ppcMask      %x\n",p_->ppcMask);
}
void pretty_print(struct NV2080_CTRL_GR_GET_NUM_TPCS_FOR_GPC_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_NUM_TPCS_FOR_GPC_PARAMS\n");
    printf("	gpcId    %x\n",p_->gpcId);
    printf("	numTpcs  %x\n",p_->numTpcs);
}
void pretty_print(struct NV2080_CTRL_GR_GET_CTXSW_MODES_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_CTXSW_MODES_PARAMS\n");
    printf("	hChannel         %x\n",p_->hChannel);
    printf("	zcullMode        %x\n",p_->zcullMode);
    printf("	pmMode           %x\n",p_->pmMode);
    printf("	smpcMode         %x\n",p_->smpcMode);
    printf("	cilpPreemptMode  %x\n",p_->cilpPreemptMode);
    printf("	gfxpPreemptMode  %x\n",p_->gfxpPreemptMode);
}
void pretty_print(struct NV2080_CTRL_GR_GET_ZCULL_MASK_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_ZCULL_MASK_PARAMS\n");
    printf("	gpcId      %x\n",p_->gpcId);
    printf("	zcullMask  %x\n",p_->zcullMask);
}
void pretty_print(struct NV2080_CTRL_GR_FECS_BIND_EVTBUF_FOR_UID_V2_PARAMS* p_){
  printf("NV2080_CTRL_GR_FECS_BIND_EVTBUF_FOR_UID_V2_PARAMS\n");
    printf("	hEventBuffer   %x\n",p_->hEventBuffer);
    printf("	recordSize     %x\n",p_->recordSize);
    printf("	levelOfDetail  %x\n",p_->levelOfDetail);
    printf("	eventFilter    %x\n",p_->eventFilter);
    printf("	bAllUsers      %x\n",p_->bAllUsers);
    printf("	reasonCode     %x\n",p_->reasonCode);
}
void pretty_print(struct NV2080_CTRL_GR_GET_GFX_GPC_AND_TPC_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GR_GET_GFX_GPC_AND_TPC_INFO_PARAMS\n");
    printf("	grRouteInfo     %x\n",p_->grRouteInfo);
    printf("	physGfxGpcMask  %x\n",p_->physGfxGpcMask);
    printf("	numGfxTpc       %x\n",p_->numGfxTpc);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_FEATURES_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_FEATURES_PARAMS\n");
    printf("	featuresMask  %x\n",p_->featuresMask);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_PARAMS\n");
    printf("	sizeOfStrings             %x\n",p_->sizeOfStrings);
    printf("	pDriverVersionBuffer      %p\n",p_->pDriverVersionBuffer);
    printf("	pVersionBuffer            %p\n",p_->pVersionBuffer);
    printf("	pTitleBuffer              %p\n",p_->pTitleBuffer);
    printf("	changelistNumber          %x\n",p_->changelistNumber);
    printf("	officialChangelistNumber  %x\n",p_->officialChangelistNumber);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_CPU_INFO_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_CPU_INFO_PARAMS\n");
    printf("	type               %x\n",p_->type);
    printf("	capabilities       %x\n",p_->capabilities);
    printf("	clock              %x\n",p_->clock);
    printf("	L1DataCacheSize    %x\n",p_->L1DataCacheSize);
    printf("	L2DataCacheSize    %x\n",p_->L2DataCacheSize);
    printf("	dataCacheLineSize  %x\n",p_->dataCacheLineSize);
    printf("	numLogicalCpus     %x\n",p_->numLogicalCpus);
    printf("	numPhysicalCpus    %x\n",p_->numPhysicalCpus);
    printf("	name               %p\n",p_->name);
    printf("	family             %x\n",p_->family);
    printf("	model              %x\n",p_->model);
    printf("	stepping           %x\n",p_->stepping);
    printf("	coresOnDie         %x\n",p_->coresOnDie);
    printf("	bSEVEnabled        %x\n",p_->bSEVEnabled);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_CHIPSET_INFO_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_CHIPSET_INFO_PARAMS\n");
    printf("	vendorId                %x\n",p_->vendorId);
    printf("	deviceId                %x\n",p_->deviceId);
    printf("	subSysVendorId          %x\n",p_->subSysVendorId);
    printf("	subSysDeviceId          %x\n",p_->subSysDeviceId);
    printf("	HBvendorId              %x\n",p_->HBvendorId);
    printf("	HBdeviceId              %x\n",p_->HBdeviceId);
    printf("	HBsubSysVendorId        %x\n",p_->HBsubSysVendorId);
    printf("	HBsubSysDeviceId        %x\n",p_->HBsubSysDeviceId);
    printf("	sliBondId               %x\n",p_->sliBondId);
    printf("	vendorNameString        %p\n",p_->vendorNameString);
    printf("	subSysVendorNameString  %p\n",p_->subSysVendorNameString);
    printf("	chipsetNameString       %p\n",p_->chipsetNameString);
    printf("	sliBondNameString       %p\n",p_->sliBondNameString);
    printf("	flags                   %x\n",p_->flags);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_SET_MEMORY_SIZE_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_SET_MEMORY_SIZE_PARAMS\n");
    printf("	memorySize  %x\n",p_->memorySize);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_LOCK_TIMES_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_LOCK_TIMES_PARAMS\n");
    printf("	waitApiLock    %llx\n",p_->waitApiLock);
    printf("	holdRoApiLock  %llx\n",p_->holdRoApiLock);
    printf("	holdRwApiLock  %llx\n",p_->holdRwApiLock);
    printf("	waitGpuLock    %llx\n",p_->waitGpuLock);
    printf("	holdGpuLock    %llx\n",p_->holdGpuLock);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_CLASSLIST_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_CLASSLIST_PARAMS\n");
    printf("	numClasses  %x\n",p_->numClasses);
    printf("	classes     %p\n",p_->classes);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_NOTIFY_EVENT_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_NOTIFY_EVENT_PARAMS\n");
    printf("	eventType         %x\n",p_->eventType);
    printf("	eventData         %x\n",p_->eventData);
    printf("	bEventDataForced  %x\n",p_->bEventDataForced);
}
void pretty_print(struct NV0000_CTRL_CMD_SYSTEM_GET_PLATFORM_TYPE_PARAMS* p_){
  printf("NV0000_CTRL_CMD_SYSTEM_GET_PLATFORM_TYPE_PARAMS\n");
    printf("	systemType  %x\n",p_->systemType);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_DEBUG_RMMSG_CTRL_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_DEBUG_RMMSG_CTRL_PARAMS\n");
    printf("	cmd    %x\n",p_->cmd);
    printf("	count  %x\n",p_->count);
    printf("	data   %p\n",p_->data);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_HWBC_INFO* p_){
  printf("NV0000_CTRL_SYSTEM_HWBC_INFO\n");
    printf("	hwbcId           %x\n",p_->hwbcId);
    printf("	firmwareVersion  %x\n",p_->firmwareVersion);
    printf("	subordinateBus   %x\n",p_->subordinateBus);
    printf("	secondaryBus     %x\n",p_->secondaryBus);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_HWBC_INFO_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_HWBC_INFO_PARAMS\n");
    printf("	hwbcInfo  %p\n",p_->hwbcInfo);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GPS_CONTROL_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GPS_CONTROL_PARAMS\n");
    printf("	command  %x\n",p_->command);
    printf("	locale   %x\n",p_->locale);
    printf("	data     %x\n",p_->data);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GPS_BATCH_CONTROL_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GPS_BATCH_CONTROL_PARAMS\n");
    printf("	cmdCount   %x\n",p_->cmdCount);
    printf("	succeeded  %x\n",p_->succeeded);
    printf("	cmdData    %p\n",p_->cmdData);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_P2P_CAPS_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_P2P_CAPS_PARAMS\n");
    printf("	gpuIds              %p\n",p_->gpuIds);
    printf("	gpuCount            %x\n",p_->gpuCount);
    printf("	p2pCaps             %x\n",p_->p2pCaps);
    printf("	p2pOptimalReadCEs   %x\n",p_->p2pOptimalReadCEs);
    printf("	p2pOptimalWriteCEs  %x\n",p_->p2pOptimalWriteCEs);
    printf("	p2pCapsStatus       %p\n",p_->p2pCapsStatus);
    printf("	busPeerIds          %p\n",p_->busPeerIds);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_P2P_CAPS_V2_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_P2P_CAPS_V2_PARAMS\n");
    printf("	gpuIds              %p\n",p_->gpuIds);
    printf("	gpuCount            %x\n",p_->gpuCount);
    printf("	p2pCaps             %x\n",p_->p2pCaps);
    printf("	p2pOptimalReadCEs   %x\n",p_->p2pOptimalReadCEs);
    printf("	p2pOptimalWriteCEs  %x\n",p_->p2pOptimalWriteCEs);
    printf("	p2pCapsStatus       %p\n",p_->p2pCapsStatus);
    printf("	busPeerIds          %p\n",p_->busPeerIds);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_P2P_CAPS_MATRIX_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_P2P_CAPS_MATRIX_PARAMS\n");
    printf("	grpACount           %x\n",p_->grpACount);
    printf("	grpBCount           %x\n",p_->grpBCount);
    printf("	gpuIdGrpA           %p\n",p_->gpuIdGrpA);
    printf("	gpuIdGrpB           %p\n",p_->gpuIdGrpB);
    printf("	p2pCaps             %p\n",p_->p2pCaps);
    printf("	a2bOptimalReadCes   %p\n",p_->a2bOptimalReadCes);
    printf("	a2bOptimalWriteCes  %p\n",p_->a2bOptimalWriteCes);
    printf("	b2aOptimalReadCes   %p\n",p_->b2aOptimalReadCes);
    printf("	b2aOptimalWriteCes  %p\n",p_->b2aOptimalWriteCes);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GPS_CTRL_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GPS_CTRL_PARAMS\n");
    printf("	cmd     %x\n",p_->cmd);
    printf("	input   %p\n",p_->input);
    printf("	result  %p\n",p_->result);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GPS_GET_PERF_SENSOR_COUNTERS_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GPS_GET_PERF_SENSOR_COUNTERS_PARAMS\n");
    printf("	objHndl                   %x\n",p_->objHndl);
    printf("	blockId                   %x\n",p_->blockId);
    printf("	nextExpectedSampleTimems  %x\n",p_->nextExpectedSampleTimems);
    printf("	countersReq               %x\n",p_->countersReq);
    printf("	countersReturned          %x\n",p_->countersReturned);
    printf("	counterBlock              %p\n",p_->counterBlock);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GPS_CALL_ACPI_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GPS_CALL_ACPI_PARAMS\n");
    printf("	cmd       %x\n",p_->cmd);
    printf("	input     %x\n",p_->input);
    printf("	resultSz  %x\n",p_->resultSz);
    printf("	result    %p\n",p_->result);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_EXECUTE_ACPI_METHOD_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_EXECUTE_ACPI_METHOD_PARAMS\n");
    printf("	method       %x\n",p_->method);
    printf("	inData       %p\n",p_->inData);
    printf("	inDataSize   %x\n",p_->inDataSize);
    printf("	outStatus    %x\n",p_->outStatus);
    printf("	outData      %p\n",p_->outData);
    printf("	outDataSize  %x\n",p_->outDataSize);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_ENABLE_ETW_EVENTS_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_ENABLE_ETW_EVENTS_PARAMS\n");
    printf("	moduleMask  %x\n",p_->moduleMask);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GPS_FRM_DATA_SAMPLE* p_){
  printf("NV0000_CTRL_SYSTEM_GPS_FRM_DATA_SAMPLE\n");
    printf("	frameTime     %x\n",p_->frameTime);
    printf("	renderTime    %x\n",p_->renderTime);
    printf("	targetTime    %x\n",p_->targetTime);
    printf("	sleepTime     %x\n",p_->sleepTime);
    printf("	sampleNumber  %x\n",p_->sampleNumber);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GPS_GET_FRM_DATA_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GPS_GET_FRM_DATA_PARAMS\n");
    printf("	samples           %p\n",p_->samples);
    printf("	nextSampleNumber  %x\n",p_->nextSampleNumber);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GPS_SET_FRM_DATA_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GPS_SET_FRM_DATA_PARAMS\n");
    printf("	sampleData  %x\n",p_->sampleData);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_VGX_SYSTEM_INFO_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_VGX_SYSTEM_INFO_PARAMS\n");
    printf("	szHostDriverVersionBuffer  %x\n",p_->szHostDriverVersionBuffer);
    printf("	szHostVersionBuffer        %x\n",p_->szHostVersionBuffer);
    printf("	szHostTitleBuffer          %x\n",p_->szHostTitleBuffer);
    printf("	szPluginTitleBuffer        %x\n",p_->szPluginTitleBuffer);
    printf("	szHostUnameBuffer          %x\n",p_->szHostUnameBuffer);
    printf("	iHostChangelistNumber      %x\n",p_->iHostChangelistNumber);
    printf("	iPluginChangelistNumber    %x\n",p_->iPluginChangelistNumber);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_GPUS_POWER_STATUS_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_GPUS_POWER_STATUS_PARAMS\n");
    printf("	gpuCount                %x\n",p_->gpuCount);
    printf("	gpuBus                  %p\n",p_->gpuBus);
    printf("	gpuExternalPowerStatus  %p\n",p_->gpuExternalPowerStatus);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_PRIVILEGED_STATUS_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_PRIVILEGED_STATUS_PARAMS\n");
    printf("	privStatusFlags  %x\n",p_->privStatusFlags);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_FABRIC_STATUS_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_FABRIC_STATUS_PARAMS\n");
    printf("	fabricStatus  %x\n",p_->fabricStatus);
}
void pretty_print(struct NV0000_CTRL_VGPU_GET_VGPU_VERSION_PARAMS* p_){
  printf("NV0000_CTRL_VGPU_GET_VGPU_VERSION_PARAMS\n");
    printf("	host_min_supported_version  %x\n",p_->host_min_supported_version);
    printf("	host_max_supported_version  %x\n",p_->host_max_supported_version);
    printf("	user_min_supported_version  %x\n",p_->user_min_supported_version);
    printf("	user_max_supported_version  %x\n",p_->user_max_supported_version);
}
void pretty_print(struct NV0000_CTRL_VGPU_SET_VGPU_VERSION_PARAMS* p_){
  printf("NV0000_CTRL_VGPU_SET_VGPU_VERSION_PARAMS\n");
    printf("	min_version  %x\n",p_->min_version);
    printf("	max_version  %x\n",p_->max_version);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_RM_INSTANCE_ID_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_RM_INSTANCE_ID_PARAMS\n");
    printf("	rm_instance_id  %llx\n",p_->rm_instance_id);
}
void pretty_print(struct NV0000_CTRL_CMD_SYSTEM_NVPCF_GET_POWER_MODE_INFO_PARAMS* p_){
  printf("NV0000_CTRL_CMD_SYSTEM_NVPCF_GET_POWER_MODE_INFO_PARAMS\n");
    printf("	gpuId               %x\n",p_->gpuId);
    printf("	tpp                 %x\n",p_->tpp);
    printf("	ratedTgp            %x\n",p_->ratedTgp);
    printf("	subFunc             %x\n",p_->subFunc);
    printf("	ctgpOffsetmW        %x\n",p_->ctgpOffsetmW);
    printf("	targetTppOffsetmW   %x\n",p_->targetTppOffsetmW);
    printf("	maxOutputOffsetmW   %x\n",p_->maxOutputOffsetmW);
    printf("	minOutputOffsetmW   %x\n",p_->minOutputOffsetmW);
    printf("	version             %x\n",p_->version);
    printf("	samplingPeriodmS    %x\n",p_->samplingPeriodmS);
    printf("	samplingMulti       %x\n",p_->samplingMulti);
    printf("	filterType          %x\n",p_->filterType);
    printf("	filterParam         %x\n",p_->filterParam);
    printf("	filterReserved      %x\n",p_->filterReserved);
    printf("	bIsBoostController  %x\n",p_->bIsBoostController);
    printf("	incRatio            %x\n",p_->incRatio);
    printf("	decRatio            %x\n",p_->decRatio);
    printf("	bSupportBatt        %x\n",p_->bSupportBatt);
    printf("	cpuType             %x\n",p_->cpuType);
    printf("	gpuType             %x\n",p_->gpuType);
    printf("	weight              %x\n" , p_->gpuType.weight);
    printf("	windowSize          %x\n" , p_->gpuType.windowSize);
}
void pretty_print(struct NV0000_CTRL_CMD_SYSTEM_SYNC_EXTERNAL_FABRIC_MGMT_PARAMS* p_){
  printf("NV0000_CTRL_CMD_SYSTEM_SYNC_EXTERNAL_FABRIC_MGMT_PARAMS\n");
    printf("	bExternalFabricMgmt  %x\n",p_->bExternalFabricMgmt);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_CLIENT_DATABASE_INFO_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_CLIENT_DATABASE_INFO_PARAMS\n");
    printf("	clientCount    %x\n",p_->clientCount);
    printf("	resourceCount  %llx\n",p_->resourceCount);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_PARAMS\n");
    printf("	driverVersionBuffer       %x\n",p_->driverVersionBuffer);
    printf("	versionBuffer             %x\n",p_->versionBuffer);
    printf("	titleBuffer               %x\n",p_->titleBuffer);
    printf("	changelistNumber          %x\n",p_->changelistNumber);
    printf("	officialChangelistNumber  %x\n",p_->officialChangelistNumber);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_RMCTRL_CACHE_MODE_CTRL_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_RMCTRL_CACHE_MODE_CTRL_PARAMS\n");
    printf("	cmd   %x\n",p_->cmd);
    printf("	mode  %x\n",p_->mode);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_CONTROL_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_CONTROL_PARAMS\n");
    printf("	command  %x\n",p_->command);
    printf("	locale   %x\n",p_->locale);
    printf("	data     %x\n",p_->data);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_BATCH_CONTROL_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_BATCH_CONTROL_PARAMS\n");
    printf("	cmdCount   %x\n",p_->cmdCount);
    printf("	succeeded  %x\n",p_->succeeded);
    printf("	cmdData    %p\n",p_->cmdData);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_CTRL_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_CTRL_PARAMS\n");
    printf("	cmd     %x\n",p_->cmd);
    printf("	input   %p\n",p_->input);
    printf("	result  %p\n",p_->result);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_GET_PERF_SENSOR_COUNTERS_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_GET_PERF_SENSOR_COUNTERS_PARAMS\n");
    printf("	objHndl                   %x\n",p_->objHndl);
    printf("	blockId                   %x\n",p_->blockId);
    printf("	nextExpectedSampleTimems  %x\n",p_->nextExpectedSampleTimems);
    printf("	countersReq               %x\n",p_->countersReq);
    printf("	countersReturned          %x\n",p_->countersReturned);
    printf("	counterBlock              %p\n",p_->counterBlock);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_CALL_ACPI_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_CALL_ACPI_PARAMS\n");
    printf("	cmd       %x\n",p_->cmd);
    printf("	input     %x\n",p_->input);
    printf("	resultSz  %x\n",p_->resultSz);
    printf("	result    %p\n",p_->result);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_FRM_DATA_SAMPLE* p_){
  printf("NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_FRM_DATA_SAMPLE\n");
    printf("	frameTime     %x\n",p_->frameTime);
    printf("	renderTime    %x\n",p_->renderTime);
    printf("	targetTime    %x\n",p_->targetTime);
    printf("	sleepTime     %x\n",p_->sleepTime);
    printf("	sampleNumber  %x\n",p_->sampleNumber);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_GET_FRM_DATA_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_GET_FRM_DATA_PARAMS\n");
    printf("	samples           %p\n",p_->samples);
    printf("	nextSampleNumber  %x\n",p_->nextSampleNumber);
}
void pretty_print(struct NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_SET_FRM_DATA_PARAMS* p_){
  printf("NV0000_CTRL_SYSTEM_PFM_REQ_HNDLR_SET_FRM_DATA_PARAMS\n");
    printf("	sampleData  %x\n",p_->sampleData);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_INFO_PARAMS\n");
    printf("	gpuInfoListSize  %x\n",p_->gpuInfoListSize);
    printf("	gpuInfoList      %p\n",p_->gpuInfoList);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_INFO_V2_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_INFO_V2_PARAMS\n");
    printf("	gpuInfoListSize  %x\n",p_->gpuInfoListSize);
    printf("	gpuInfoList      %p\n",p_->gpuInfoList);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_NAME_STRING_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_NAME_STRING_PARAMS\n");
    printf("	gpuNameStringFlags  %x\n",p_->gpuNameStringFlags);
    printf("	gpuNameString       %x\n",p_->gpuNameString);
    printf("	ascii               %p\n" , p_->gpuNameString.ascii);
    printf("	unicode             %p\n" , p_->gpuNameString.unicode);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_SHORT_NAME_STRING_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_SHORT_NAME_STRING_PARAMS\n");
    printf("	gpuShortNameString  %p\n",p_->gpuShortNameString);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_POWER_PARAMS* p_){
  printf("NV2080_CTRL_GPU_SET_POWER_PARAMS\n");
    printf("	target    %x\n",p_->target);
    printf("	newLevel  %x\n",p_->newLevel);
    printf("	oldLevel  %x\n",p_->oldLevel);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_SDM_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_SDM_PARAMS\n");
    printf("	subdeviceMask  %x\n",p_->subdeviceMask);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_SDM_PARAMS* p_){
  printf("NV2080_CTRL_GPU_SET_SDM_PARAMS\n");
    printf("	subdeviceMask  %x\n",p_->subdeviceMask);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_SIMULATION_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_SIMULATION_INFO_PARAMS\n");
    printf("	type  %x\n",p_->type);
}
void pretty_print(struct NV2080_CTRL_GPU_REG_OP* p_){
  printf("NV2080_CTRL_GPU_REG_OP\n");
    printf("	regOp            %x\n",p_->regOp);
    printf("	regType          %x\n",p_->regType);
    printf("	regStatus        %x\n",p_->regStatus);
    printf("	regQuad          %x\n",p_->regQuad);
    printf("	regGroupMask     %x\n",p_->regGroupMask);
    printf("	regSubGroupMask  %x\n",p_->regSubGroupMask);
    printf("	regOffset        %x\n",p_->regOffset);
    printf("	regValueHi       %x\n",p_->regValueHi);
    printf("	regValueLo       %x\n",p_->regValueLo);
    printf("	regAndNMaskHi    %x\n",p_->regAndNMaskHi);
    printf("	regAndNMaskLo    %x\n",p_->regAndNMaskLo);
}
void pretty_print(struct NV2080_CTRL_GPU_EXEC_REG_OPS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_EXEC_REG_OPS_PARAMS\n");
    printf("	hClientTarget      %x\n",p_->hClientTarget);
    printf("	hChannelTarget     %x\n",p_->hChannelTarget);
    printf("	bNonTransactional  %x\n",p_->bNonTransactional);
    printf("	reserved00         %p\n",p_->reserved00);
    printf("	regOpCount         %x\n",p_->regOpCount);
    printf("	regOps             %p\n",p_->regOps);
    printf("	grRouteInfo        %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ENGINES_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENGINES_PARAMS\n");
    printf("	engineCount  %x\n",p_->engineCount);
    printf("	engineList   %p\n",p_->engineList);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS\n");
    printf("	engineCount  %x\n",p_->engineCount);
    printf("	engineList   %p\n",p_->engineList);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ENGINE_CLASSLIST_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENGINE_CLASSLIST_PARAMS\n");
    printf("	engineType  %x\n",p_->engineType);
    printf("	numClasses  %x\n",p_->numClasses);
    printf("	classList   %p\n",p_->classList);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ENGINE_FAULT_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENGINE_FAULT_INFO_PARAMS\n");
    printf("	engineType            %x\n",p_->engineType);
    printf("	mmuFaultId            %x\n",p_->mmuFaultId);
    printf("	bSubcontextSupported  %x\n",p_->bSubcontextSupported);
}
void pretty_print(struct NV2080_CTRL_GPU_QUERY_MODE_PARAMS* p_){
  printf("NV2080_CTRL_GPU_QUERY_MODE_PARAMS\n");
    printf("	mode  %x\n",p_->mode);
}
void pretty_print(struct NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ENTRY* p_){
  printf("NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ENTRY\n");
    printf("	gpuPhysAddr  %llx\n",p_->gpuPhysAddr);
    printf("	gpuVirtAddr  %llx\n",p_->gpuVirtAddr);
    printf("	size         %llx\n",p_->size);
    printf("	physAttr     %x\n",p_->physAttr);
    printf("	bufferId     %x\n",p_->bufferId);
    printf("	bInitialize  %x\n",p_->bInitialize);
    printf("	bNonmapped   %x\n",p_->bNonmapped);
}
void pretty_print(struct NV2080_CTRL_GPU_PROMOTE_CTX_PARAMS* p_){
  printf("NV2080_CTRL_GPU_PROMOTE_CTX_PARAMS\n");
    printf("	engineType    %x\n",p_->engineType);
    printf("	hClient       %x\n",p_->hClient);
    printf("	ChID          %x\n",p_->ChID);
    printf("	hChanClient   %x\n",p_->hChanClient);
    printf("	hObject       %x\n",p_->hObject);
    printf("	hVirtMemory   %x\n",p_->hVirtMemory);
    printf("	virtAddress   %llx\n",p_->virtAddress);
    printf("	size          %llx\n",p_->size);
    printf("	entryCount    %x\n",p_->entryCount);
    printf("	promoteEntry  %p\n",p_->promoteEntry);
}
void pretty_print(struct NV2080_CTRL_GPU_EVICT_CTX_PARAMS* p_){
  printf("NV2080_CTRL_GPU_EVICT_CTX_PARAMS\n");
    printf("	engineType   %x\n",p_->engineType);
    printf("	hClient      %x\n",p_->hClient);
    printf("	ChID         %x\n",p_->ChID);
    printf("	hChanClient  %x\n",p_->hChanClient);
    printf("	hObject      %x\n",p_->hObject);
}
void pretty_print(struct NV2080_CTRL_GPU_INITIALIZE_CTX_PARAMS* p_){
  printf("NV2080_CTRL_GPU_INITIALIZE_CTX_PARAMS\n");
    printf("	engineType   %x\n",p_->engineType);
    printf("	hClient      %x\n",p_->hClient);
    printf("	ChID         %x\n",p_->ChID);
    printf("	hChanClient  %x\n",p_->hChanClient);
    printf("	hObject      %x\n",p_->hObject);
    printf("	hVirtMemory  %x\n",p_->hVirtMemory);
    printf("	physAddress  %llx\n",p_->physAddress);
    printf("	physAttr     %x\n",p_->physAttr);
    printf("	hDmaHandle   %x\n",p_->hDmaHandle);
    printf("	index        %x\n",p_->index);
    printf("	size         %llx\n",p_->size);
}
void pretty_print(struct NV2080_CTRL_GPU_QUERY_ECC_INTR_PARAMS* p_){
  printf("NV2080_CTRL_GPU_QUERY_ECC_INTR_PARAMS\n");
    printf("	eccIntrStatus  %x\n",p_->eccIntrStatus);
}
void pretty_print(struct NV2080_CTRL_GPU_QUERY_ECC_EXCEPTION_STATUS* p_){
  printf("NV2080_CTRL_GPU_QUERY_ECC_EXCEPTION_STATUS\n");
    printf("	count  %llx\n",p_->count);
}
void pretty_print(struct NV2080_CTRL_GPU_QUERY_ECC_UNIT_STATUS* p_){
  printf("NV2080_CTRL_GPU_QUERY_ECC_UNIT_STATUS\n");
    printf("	enabled           %x\n",p_->enabled);
    printf("	scrubComplete     %x\n",p_->scrubComplete);
    printf("	supported         %x\n",p_->supported);
    printf("	dbe               %x\n",p_->dbe);
    printf("	dbeNonResettable  %x\n",p_->dbeNonResettable);
    printf("	sbe               %x\n",p_->sbe);
    printf("	sbeNonResettable  %x\n",p_->sbeNonResettable);
}
void pretty_print(struct NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS\n");
    printf("	units               %p\n",p_->units);
    printf("	bFatalPoisonError   %x\n",p_->bFatalPoisonError);
    printf("	uncorrectableError  %x\n",p_->uncorrectableError);
    printf("	flags               %x\n",p_->flags);
    printf("	grRouteInfo         %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_COMPUTE_MODE_RULES_PARAMS* p_){
  printf("NV2080_CTRL_GPU_SET_COMPUTE_MODE_RULES_PARAMS\n");
    printf("	rules  %x\n",p_->rules);
    printf("	flags  %x\n",p_->flags);
}
void pretty_print(struct NV2080_CTRL_GPU_QUERY_COMPUTE_MODE_RULES_PARAMS* p_){
  printf("NV2080_CTRL_GPU_QUERY_COMPUTE_MODE_RULES_PARAMS\n");
    printf("	rules  %x\n",p_->rules);
}
void pretty_print(struct NV2080_CTRL_GPU_QUERY_ECC_CONFIGURATION_PARAMS* p_){
  printf("NV2080_CTRL_GPU_QUERY_ECC_CONFIGURATION_PARAMS\n");
    printf("	currentConfiguration  %x\n",p_->currentConfiguration);
    printf("	defaultConfiguration  %x\n",p_->defaultConfiguration);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_ECC_CONFIGURATION_PARAMS* p_){
  printf("NV2080_CTRL_GPU_SET_ECC_CONFIGURATION_PARAMS\n");
    printf("	newConfiguration  %x\n",p_->newConfiguration);
}
void pretty_print(struct NV2080_CTRL_GPU_RESET_ECC_ERROR_STATUS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_RESET_ECC_ERROR_STATUS_PARAMS\n");
    printf("	statuses  %x\n",p_->statuses);
    printf("	flags     %x\n",p_->flags);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_FERMI_GPC_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_FERMI_GPC_INFO_PARAMS\n");
    printf("	gpcMask  %x\n",p_->gpcMask);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_FERMI_TPC_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_FERMI_TPC_INFO_PARAMS\n");
    printf("	gpcId    %x\n",p_->gpcId);
    printf("	tpcMask  %x\n",p_->tpcMask);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_FERMI_ZCULL_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_FERMI_ZCULL_INFO_PARAMS\n");
    printf("	gpcId      %x\n",p_->gpcId);
    printf("	zcullMask  %x\n",p_->zcullMask);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_OEM_BOARD_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_OEM_BOARD_INFO_PARAMS\n");
    printf("	buildDate           %x\n",p_->buildDate);
    printf("	marketingName       %p\n",p_->marketingName);
    printf("	serialNumber        %p\n",p_->serialNumber);
    printf("	memoryManufacturer  %x\n",p_->memoryManufacturer);
    printf("	memoryPartID        %p\n",p_->memoryPartID);
    printf("	memoryDateCode      %p\n",p_->memoryDateCode);
    printf("	productPartNumber   %p\n",p_->productPartNumber);
    printf("	boardRevision       %p\n",p_->boardRevision);
    printf("	boardType           %x\n",p_->boardType);
    printf("	board699PartNumber  %p\n",p_->board699PartNumber);
    printf("	board965PartNumber  %p\n",p_->board965PartNumber);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ID_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ID_PARAMS\n");
    printf("	gpuId  %x\n",p_->gpuId);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_GPU_DEBUG_MODE_PARAMS* p_){
  printf("NV2080_CTRL_GPU_SET_GPU_DEBUG_MODE_PARAMS\n");
    printf("	mode  %x\n",p_->mode);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_GPU_DEBUG_MODE_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_GPU_DEBUG_MODE_PARAMS\n");
    printf("	currentMode  %x\n",p_->currentMode);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ENGINE_PARTNERLIST_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENGINE_PARTNERLIST_PARAMS\n");
    printf("	engineType          %x\n",p_->engineType);
    printf("	partnershipClassId  %x\n",p_->partnershipClassId);
    printf("	runqueue            %x\n",p_->runqueue);
    printf("	numPartners         %x\n",p_->numPartners);
    printf("	partnerList         %p\n",p_->partnerList);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_GID_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_GID_INFO_PARAMS\n");
    printf("	index   %x\n",p_->index);
    printf("	flags   %x\n",p_->flags);
    printf("	length  %x\n",p_->length);
    printf("	data    %p\n",p_->data);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_INFOROM_OBJECT_VERSION_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_INFOROM_OBJECT_VERSION_PARAMS\n");
    printf("	objectType  %x\n",p_->objectType);
    printf("	version     %x\n",p_->version);
    printf("	subversion  %x\n",p_->subversion);
}
void pretty_print(struct NV2080_CTRL_GPU_OPTIMUS_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_OPTIMUS_INFO_PARAMS\n");
    printf("	isOptimusEnabled  %x\n",p_->isOptimusEnabled);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_IP_VERSION_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_IP_VERSION_PARAMS\n");
    printf("	targetEngine  %x\n",p_->targetEngine);
    printf("	ipVersion     %x\n",p_->ipVersion);
}
void pretty_print(struct NV2080_CTRL_CMD_GPU_QUERY_ILLUM_SUPPORT_PARAMS* p_){
  printf("NV2080_CTRL_CMD_GPU_QUERY_ILLUM_SUPPORT_PARAMS\n");
    printf("	attribute   %x\n",p_->attribute);
    printf("	bSupported  %x\n",p_->bSupported);
}
void pretty_print(struct NV2080_CTRL_CMD_GPU_ILLUM_PARAMS* p_){
  printf("NV2080_CTRL_CMD_GPU_ILLUM_PARAMS\n");
    printf("	attribute  %x\n",p_->attribute);
    printf("	value      %x\n",p_->value);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_INFOROM_IMAGE_VERSION_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_INFOROM_IMAGE_VERSION_PARAMS\n");
    printf("	version  %p\n",p_->version);
}
void pretty_print(struct NV2080_CTRL_GPU_PHYSICAL_BRIDGE_VERSION_PARAMS* p_){
  printf("NV2080_CTRL_GPU_PHYSICAL_BRIDGE_VERSION_PARAMS\n");
    printf("	fwVersion         %x\n",p_->fwVersion);
    printf("	oemVersion        %x\n",p_->oemVersion);
    printf("	siliconRevision   %x\n",p_->siliconRevision);
    printf("	hwbcResourceType  %x\n",p_->hwbcResourceType);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_PHYSICAL_BRIDGE_VERSION_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_PHYSICAL_BRIDGE_VERSION_INFO_PARAMS\n");
    printf("	bridgeCount       %x\n",p_->bridgeCount);
    printf("	hPhysicalBridges  %p\n",p_->hPhysicalBridges);
    printf("	bridgeList        %p\n",p_->bridgeList);
}
void pretty_print(struct NV2080_CTRL_GPU_BRIDGE_VERSION_PARAMS* p_){
  printf("NV2080_CTRL_GPU_BRIDGE_VERSION_PARAMS\n");
    printf("	bus               %x\n",p_->bus);
    printf("	device            %x\n",p_->device);
    printf("	func              %x\n",p_->func);
    printf("	oemVersion        %x\n",p_->oemVersion);
    printf("	siliconRevision   %x\n",p_->siliconRevision);
    printf("	hwbcResourceType  %x\n",p_->hwbcResourceType);
    printf("	domain            %x\n",p_->domain);
    printf("	fwVersion         %x\n",p_->fwVersion);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ALL_BRIDGES_UPSTREAM_OF_GPU_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ALL_BRIDGES_UPSTREAM_OF_GPU_PARAMS\n");
    printf("	bridgeCount        %x\n",p_->bridgeCount);
    printf("	physicalBridgeIds  %p\n",p_->physicalBridgeIds);
    printf("	bridgeList         %p\n",p_->bridgeList);
}
void pretty_print(struct NV2080_CTRL_GPU_QUERY_SCRUBBER_STATUS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_QUERY_SCRUBBER_STATUS_PARAMS\n");
    printf("	scrubberStatus   %x\n",p_->scrubberStatus);
    printf("	remainingTimeMs  %x\n",p_->remainingTimeMs);
    printf("	scrubStartAddr   %llx\n",p_->scrubStartAddr);
    printf("	scrubEndAddr     %llx\n",p_->scrubEndAddr);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_VPR_CAPS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_VPR_CAPS_PARAMS\n");
    printf("	minStartAddr  %llx\n",p_->minStartAddr);
    printf("	maxEndAddr    %llx\n",p_->maxEndAddr);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_PES_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_PES_INFO_PARAMS\n");
    printf("	gpcId              %x\n",p_->gpcId);
    printf("	numPesInGpc        %x\n",p_->numPesInGpc);
    printf("	activePesMask      %x\n",p_->activePesMask);
    printf("	maxTpcPerGpcCount  %x\n",p_->maxTpcPerGpcCount);
    printf("	tpcToPesMap        %p\n",p_->tpcToPesMap);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_OEM_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_OEM_INFO_PARAMS\n");
    printf("	oemInfo  %p\n",p_->oemInfo);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_VPR_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_VPR_INFO_PARAMS\n");
    printf("	queryType               %x\n",p_->queryType);
    printf("	bIsVprEnabled           %x\n",p_->bIsVprEnabled);
    printf("	vprStartAddressInBytes  %llx\n",p_->vprStartAddressInBytes);
    printf("	vprEndAddressInBytes    %llx\n",p_->vprEndAddressInBytes);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ENCODER_CAPACITY_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENCODER_CAPACITY_PARAMS\n");
    printf("	queryType        %x\n",p_->queryType);
    printf("	encoderCapacity  %x\n",p_->encoderCapacity);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_NVENC_SW_SESSION_STATS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_NVENC_SW_SESSION_STATS_PARAMS\n");
    printf("	encoderSessionCount   %x\n",p_->encoderSessionCount);
    printf("	averageEncodeFps      %x\n",p_->averageEncodeFps);
    printf("	averageEncodeLatency  %x\n",p_->averageEncodeLatency);
}
void pretty_print(struct NV2080_CTRL_NVENC_SW_SESSION_INFO* p_){
  printf("NV2080_CTRL_NVENC_SW_SESSION_INFO\n");
    printf("	processId             %x\n",p_->processId);
    printf("	subProcessId          %x\n",p_->subProcessId);
    printf("	sessionId             %x\n",p_->sessionId);
    printf("	codecType             %x\n",p_->codecType);
    printf("	hResolution           %x\n",p_->hResolution);
    printf("	vResolution           %x\n",p_->vResolution);
    printf("	averageEncodeFps      %x\n",p_->averageEncodeFps);
    printf("	averageEncodeLatency  %x\n",p_->averageEncodeLatency);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_NVENC_SW_SESSION_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_NVENC_SW_SESSION_INFO_PARAMS\n");
    printf("	sessionInfoTblEntry  %x\n",p_->sessionInfoTblEntry);
    printf("	sessionInfoTbl       %p\n",p_->sessionInfoTbl);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_FABRIC_BASE_ADDR_PARAMS* p_){
  printf("NV2080_CTRL_GPU_SET_FABRIC_BASE_ADDR_PARAMS\n");
    printf("	fabricBaseAddr  %llx\n",p_->fabricBaseAddr);
}
void pretty_print(struct NV2080_CTRL_GPU_VIRTUAL_INTERRUPT_PARAMS* p_){
  printf("NV2080_CTRL_GPU_VIRTUAL_INTERRUPT_PARAMS\n");
    printf("	handle  %x\n",p_->handle);
}
void pretty_print(struct NV2080_CTRL_CMD_GPU_QUERY_FUNCTION_STATUS_PARAMS* p_){
  printf("NV2080_CTRL_CMD_GPU_QUERY_FUNCTION_STATUS_PARAMS\n");
    printf("	statusMask  %x\n",p_->statusMask);
    printf("	xusbData    %x\n",p_->xusbData);
    printf("	ppcData     %x\n",p_->ppcData);
}
void pretty_print(struct NV2080_CTRL_GPU_PARTITION_SPAN* p_){
  printf("NV2080_CTRL_GPU_PARTITION_SPAN\n");
    printf("	lo  %llx\n",p_->lo);
    printf("	hi  %llx\n",p_->hi);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_PARTITION_INFO* p_){
  printf("NV2080_CTRL_GPU_SET_PARTITION_INFO\n");
    printf("	swizzId        %x\n",p_->swizzId);
    printf("	partitionFlag  %x\n",p_->partitionFlag);
    printf("	bValid         %x\n",p_->bValid);
    printf("	placement      %x\n",p_->placement);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_PARTITIONS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_SET_PARTITIONS_PARAMS\n");
    printf("	partitionCount  %x\n",p_->partitionCount);
    printf("	partitionInfo   %p\n",p_->partitionInfo);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_PARTITION_INFO* p_){
  printf("NV2080_CTRL_GPU_GET_PARTITION_INFO\n");
    printf("	swizzId            %x\n",p_->swizzId);
    printf("	partitionFlag      %x\n",p_->partitionFlag);
    printf("	grEngCount         %x\n",p_->grEngCount);
    printf("	veidCount          %x\n",p_->veidCount);
    printf("	smCount            %x\n",p_->smCount);
    printf("	ceCount            %x\n",p_->ceCount);
    printf("	nvEncCount         %x\n",p_->nvEncCount);
    printf("	nvDecCount         %x\n",p_->nvDecCount);
    printf("	nvJpgCount         %x\n",p_->nvJpgCount);
    printf("	nvOfaCount         %x\n",p_->nvOfaCount);
    printf("	gpcCount           %x\n",p_->gpcCount);
    printf("	virtualGpcCount    %x\n",p_->virtualGpcCount);
    printf("	gfxGpcCount        %x\n",p_->gfxGpcCount);
    printf("	gpcsPerGr          %p\n",p_->gpcsPerGr);
    printf("	virtualGpcsPerGr   %p\n",p_->virtualGpcsPerGr);
    printf("	gfxGpcPerGr        %p\n",p_->gfxGpcPerGr);
    printf("	veidsPerGr         %p\n",p_->veidsPerGr);
    printf("	memSize            %llx\n",p_->memSize);
    printf("	span               %x\n",p_->span);
    printf("	bValid             %x\n",p_->bValid);
    printf("	bPartitionError    %x\n",p_->bPartitionError);
    printf("	validCTSIdMask     %llx\n",p_->validCTSIdMask);
    printf("	validGfxCTSIdMask  %llx\n",p_->validGfxCTSIdMask);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_PARTITIONS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_PARTITIONS_PARAMS\n");
    printf("	queryPartitionInfo    %p\n",p_->queryPartitionInfo);
    printf("	validPartitionCount   %x\n",p_->validPartitionCount);
    printf("	bGetAllPartitionInfo  %x\n",p_->bGetAllPartitionInfo);
}
void pretty_print(struct NV2080_CTRL_GPU_CONFIGURE_PARTITION_PARAMS* p_){
  printf("NV2080_CTRL_GPU_CONFIGURE_PARTITION_PARAMS\n");
    printf("	swizzId            %x\n",p_->swizzId);
    printf("	gpcCountPerSmcEng  %p\n",p_->gpcCountPerSmcEng);
    printf("	updateSmcEngMask   %x\n",p_->updateSmcEngMask);
    printf("	bUseAllGPCs        %x\n",p_->bUseAllGPCs);
}
void pretty_print(struct NV2080_CTRL_GPU_FAULT_PACKET* p_){
  printf("NV2080_CTRL_GPU_FAULT_PACKET\n");
    printf("	data  %p\n",p_->data);
}
void pretty_print(struct NV2080_CTRL_GPU_REPORT_NON_REPLAYABLE_FAULT_PARAMS* p_){
  printf("NV2080_CTRL_GPU_REPORT_NON_REPLAYABLE_FAULT_PARAMS\n");
    printf("	faultPacket  %x\n",p_->faultPacket);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ENGINE_RUNLIST_PRI_BASE_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENGINE_RUNLIST_PRI_BASE_PARAMS\n");
    printf("	engineList      %p\n",p_->engineList);
    printf("	runlistPriBase  %p\n",p_->runlistPriBase);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_HW_ENGINE_ID_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_HW_ENGINE_ID_PARAMS\n");
    printf("	engineList  %p\n",p_->engineList);
    printf("	hwEngineID  %p\n",p_->hwEngineID);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_NVFBC_SW_SESSION_STATS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_NVFBC_SW_SESSION_STATS_PARAMS\n");
    printf("	sessionCount    %x\n",p_->sessionCount);
    printf("	averageFPS      %x\n",p_->averageFPS);
    printf("	averageLatency  %x\n",p_->averageLatency);
}
void pretty_print(struct NV2080_CTRL_NVFBC_SW_SESSION_INFO* p_){
  printf("NV2080_CTRL_NVFBC_SW_SESSION_INFO\n");
    printf("	processId       %x\n",p_->processId);
    printf("	subProcessId    %x\n",p_->subProcessId);
    printf("	vgpuInstanceId  %x\n",p_->vgpuInstanceId);
    printf("	sessionId       %x\n",p_->sessionId);
    printf("	sessionType     %x\n",p_->sessionType);
    printf("	displayOrdinal  %x\n",p_->displayOrdinal);
    printf("	sessionFlags    %x\n",p_->sessionFlags);
    printf("	hMaxResolution  %x\n",p_->hMaxResolution);
    printf("	vMaxResolution  %x\n",p_->vMaxResolution);
    printf("	hResolution     %x\n",p_->hResolution);
    printf("	vResolution     %x\n",p_->vResolution);
    printf("	averageFPS      %x\n",p_->averageFPS);
    printf("	averageLatency  %x\n",p_->averageLatency);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_NVFBC_SW_SESSION_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_NVFBC_SW_SESSION_INFO_PARAMS\n");
    printf("	sessionInfoCount  %x\n",p_->sessionInfoCount);
    printf("	sessionInfoTbl    %p\n",p_->sessionInfoTbl);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_VMMU_SEGMENT_SIZE_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_VMMU_SEGMENT_SIZE_PARAMS\n");
    printf("	vmmuSegmentSize  %llx\n",p_->vmmuSegmentSize);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_PARTITION_CAPACITY_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_PARTITION_CAPACITY_PARAMS\n");
    printf("	partitionFlag        %x\n",p_->partitionFlag);
    printf("	partitionCount       %x\n",p_->partitionCount);
    printf("	availableSpans       %p\n",p_->availableSpans);
    printf("	availableSpansCount  %x\n",p_->availableSpansCount);
    printf("	totalPartitionCount  %x\n",p_->totalPartitionCount);
    printf("	totalSpans           %p\n",p_->totalSpans);
    printf("	totalSpansCount      %x\n",p_->totalSpansCount);
    printf("	bStaticInfo          %x\n",p_->bStaticInfo);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_PARTITIONING_MODE_PARAMS* p_){
  printf("NV2080_CTRL_GPU_SET_PARTITIONING_MODE_PARAMS\n");
    printf("	partitioningMode  %x\n",p_->partitioningMode);
}
void pretty_print(struct NV2080_CTRL_GPU_DESCRIBE_PARTITIONS_INFO* p_){
  printf("NV2080_CTRL_GPU_DESCRIBE_PARTITIONS_INFO\n");
    printf("	partitionFlag    %x\n",p_->partitionFlag);
    printf("	grCount          %x\n",p_->grCount);
    printf("	gfxGrCount       %x\n",p_->gfxGrCount);
    printf("	gpcCount         %x\n",p_->gpcCount);
    printf("	virtualGpcCount  %x\n",p_->virtualGpcCount);
    printf("	gfxGpcCount      %x\n",p_->gfxGpcCount);
    printf("	veidCount        %x\n",p_->veidCount);
    printf("	smCount          %x\n",p_->smCount);
    printf("	ceCount          %x\n",p_->ceCount);
    printf("	nvEncCount       %x\n",p_->nvEncCount);
    printf("	nvDecCount       %x\n",p_->nvDecCount);
    printf("	nvJpgCount       %x\n",p_->nvJpgCount);
    printf("	nvOfaCount       %x\n",p_->nvOfaCount);
    printf("	memorySize       %llx\n",p_->memorySize);
}
void pretty_print(struct NV2080_CTRL_GPU_DESCRIBE_PARTITIONS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_DESCRIBE_PARTITIONS_PARAMS\n");
    printf("	descCount       %x\n",p_->descCount);
    printf("	partitionDescs  %p\n",p_->partitionDescs);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_MAX_SUPPORTED_PAGE_SIZE_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_MAX_SUPPORTED_PAGE_SIZE_PARAMS\n");
    printf("	maxSupportedPageSize  %llx\n",p_->maxSupportedPageSize);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_NUM_MMUS_PER_GPC_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_NUM_MMUS_PER_GPC_PARAMS\n");
    printf("	gpcId        %x\n",p_->gpcId);
    printf("	count        %x\n",p_->count);
    printf("	grRouteInfo  %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ACTIVE_PARTITION_IDS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ACTIVE_PARTITION_IDS_PARAMS\n");
    printf("	swizzId         %p\n",p_->swizzId);
    printf("	partitionCount  %x\n",p_->partitionCount);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_PIDS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_PIDS_PARAMS\n");
    printf("	idType       %x\n",p_->idType);
    printf("	id           %x\n",p_->id);
    printf("	pidTblCount  %x\n",p_->pidTblCount);
    printf("	pidTbl       %p\n",p_->pidTbl);
}
void pretty_print(struct NV2080_CTRL_SMC_SUBSCRIPTION_INFO* p_){
  printf("NV2080_CTRL_SMC_SUBSCRIPTION_INFO\n");
    printf("	computeInstanceId  %x\n",p_->computeInstanceId);
    printf("	gpuInstanceId      %x\n",p_->gpuInstanceId);
}
void pretty_print(struct NV2080_CTRL_GPU_PID_INFO_VIDEO_MEMORY_USAGE_DATA* p_){
  printf("NV2080_CTRL_GPU_PID_INFO_VIDEO_MEMORY_USAGE_DATA\n");
    printf("	memPrivate               %llx\n",p_->memPrivate);
    printf("	memSharedOwned           %llx\n",p_->memSharedOwned);
    printf("	memSharedDuped           %llx\n",p_->memSharedDuped);
    printf("	protectedMemPrivate      %llx\n",p_->protectedMemPrivate);
    printf("	protectedMemSharedOwned  %llx\n",p_->protectedMemSharedOwned);
    printf("	protectedMemSharedDuped  %llx\n",p_->protectedMemSharedDuped);
}
void pretty_print(struct NV2080_CTRL_GPU_PID_INFO_DATA* p_){
  printf("NV2080_CTRL_GPU_PID_INFO_DATA\n");
    printf("	vidMemUsage  %x\n" , p_->('vidMemUsage', 'NV2080_CTRL_GPU_PID_INFO_VIDEO_MEMORY_USAGE_DATA').vidMemUsage);
}
void pretty_print(struct NV2080_CTRL_GPU_PID_INFO* p_){
  printf("NV2080_CTRL_GPU_PID_INFO\n");
    printf("	pid              %x\n",p_->pid);
    printf("	index            %x\n",p_->index);
    printf("	result           %x\n",p_->result);
    printf("	data             %x\n",p_->data);
    printf("	smcSubscription  %x\n",p_->smcSubscription);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_PID_INFO_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_PID_INFO_PARAMS\n");
    printf("	pidInfoListCount  %x\n",p_->pidInfoListCount);
    printf("	pidInfoList       %p\n",p_->pidInfoList);
}
void pretty_print(struct NV2080_CTRL_CMD_GPU_HANDLE_VF_PRI_FAULT_PARAMS* p_){
  printf("NV2080_CTRL_CMD_GPU_HANDLE_VF_PRI_FAULT_PARAMS\n");
    printf("	faultType  %x\n",p_->faultType);
}
void pretty_print(struct NV2080_CTRL_GPU_COMPUTE_POLICY_CONFIG* p_){
  printf("NV2080_CTRL_GPU_COMPUTE_POLICY_CONFIG\n");
    printf("	type  %x\n",p_->type);
    printf("	data  %x\n",p_->data);
    printf("	timeslice  %x\n" , p_->data.timeslice);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_COMPUTE_POLICY_CONFIG_PARAMS* p_){
  printf("NV2080_CTRL_GPU_SET_COMPUTE_POLICY_CONFIG_PARAMS\n");
    printf("	config  %x\n",p_->config);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_COMPUTE_POLICY_CONFIG_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_COMPUTE_POLICY_CONFIG_PARAMS\n");
    printf("	numConfigs  %x\n",p_->numConfigs);
    printf("	configList  %p\n",p_->configList);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_GFID_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_GFID_PARAMS\n");
    printf("	domain    %x\n",p_->domain);
    printf("	bus       %x\n",p_->bus);
    printf("	device    %x\n",p_->device);
    printf("	func      %x\n",p_->func);
    printf("	gfid      %x\n",p_->gfid);
    printf("	gfidMask  %x\n",p_->gfidMask);
}
void pretty_print(struct NV2080_CTRL_CMD_GPU_UPDATE_GFID_P2P_CAPABILITY_PARAMS* p_){
  printf("NV2080_CTRL_CMD_GPU_UPDATE_GFID_P2P_CAPABILITY_PARAMS\n");
    printf("	gfid               %x\n",p_->gfid);
    printf("	bEnable            %x\n",p_->bEnable);
    printf("	fabricPartitionId  %x\n",p_->fabricPartitionId);
}
void pretty_print(struct NV2080_CTRL_GPU_VALIDATE_MEM_MAP_REQUEST_PARAMS* p_){
  printf("NV2080_CTRL_GPU_VALIDATE_MEM_MAP_REQUEST_PARAMS\n");
    printf("	addressStart   %llx\n",p_->addressStart);
    printf("	addressLength  %llx\n",p_->addressLength);
    printf("	protection     %x\n",p_->protection);
}
void pretty_print(struct NV2080_CTRL_GPU_SET_EGM_GPA_FABRIC_BASE_ADDR_PARAMS* p_){
  printf("NV2080_CTRL_GPU_SET_EGM_GPA_FABRIC_BASE_ADDR_PARAMS\n");
    printf("	egmGpaFabricBaseAddr  %llx\n",p_->egmGpaFabricBaseAddr);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ENGINE_LOAD_TIMES_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ENGINE_LOAD_TIMES_PARAMS\n");
    printf("	engineCount          %x\n",p_->engineCount);
    printf("	engineList           %p\n",p_->engineList);
    printf("	engineStateLoadTime  %p\n",p_->engineStateLoadTime);
    printf("	engineIsInit         %p\n",p_->engineIsInit);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_ID_NAME_MAPPING_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_ID_NAME_MAPPING_PARAMS\n");
    printf("	engineCount  %x\n",p_->engineCount);
    printf("	engineID     %p\n",p_->engineID);
    printf("	engineName   %p\n",p_->engineName);
}
void pretty_print(struct NV2080_CTRL_GPU_EXEC_REG_OPS_NOPTRS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_EXEC_REG_OPS_NOPTRS_PARAMS\n");
    printf("	hClientTarget      %x\n",p_->hClientTarget);
    printf("	hChannelTarget     %x\n",p_->hChannelTarget);
    printf("	bNonTransactional  %x\n",p_->bNonTransactional);
    printf("	reserved00         %p\n",p_->reserved00);
    printf("	regOpCount         %x\n",p_->regOpCount);
    printf("	regOps             %p\n",p_->regOps);
    printf("	grRouteInfo        %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GPU_P2P_PEER_CAPS_PEER_INFO* p_){
  printf("NV2080_CTRL_GPU_P2P_PEER_CAPS_PEER_INFO\n");
    printf("	gpuId               %x\n",p_->gpuId);
    printf("	gpuUuid             %p\n",p_->gpuUuid);
    printf("	p2pCaps             %x\n",p_->p2pCaps);
    printf("	p2pOptimalReadCEs   %x\n",p_->p2pOptimalReadCEs);
    printf("	p2pOptimalWriteCEs  %x\n",p_->p2pOptimalWriteCEs);
    printf("	p2pCapsStatus       %p\n",p_->p2pCapsStatus);
    printf("	busPeerId           %x\n",p_->busPeerId);
}
void pretty_print(struct NV2080_CTRL_GET_P2P_CAPS_PARAMS* p_){
  printf("NV2080_CTRL_GET_P2P_CAPS_PARAMS\n");
    printf("	bAllCaps      %x\n",p_->bAllCaps);
    printf("	bUseUuid      %x\n",p_->bUseUuid);
    printf("	peerGpuCount  %x\n",p_->peerGpuCount);
    printf("	peerGpuCaps   %p\n",p_->peerGpuCaps);
}
void pretty_print(struct NV2080_CTRL_GPU_COMPUTE_PROFILE* p_){
  printf("NV2080_CTRL_GPU_COMPUTE_PROFILE\n");
    printf("	computeSize  %x\n",p_->computeSize);
    printf("	gfxGpcCount  %x\n",p_->gfxGpcCount);
    printf("	gpcCount     %x\n",p_->gpcCount);
    printf("	veidCount    %x\n",p_->veidCount);
    printf("	smCount      %x\n",p_->smCount);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_COMPUTE_PROFILES_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_COMPUTE_PROFILES_PARAMS\n");
    printf("	profileCount  %x\n",p_->profileCount);
    printf("	profiles      %p\n",p_->profiles);
}
void pretty_print(struct NV2080_CTRL_CMD_GET_GPU_FABRIC_PROBE_INFO_PARAMS* p_){
  printf("NV2080_CTRL_CMD_GET_GPU_FABRIC_PROBE_INFO_PARAMS\n");
    printf("	state              %x\n",p_->state);
    printf("	status             %x\n",p_->status);
    printf("	clusterUuid        %p\n",p_->clusterUuid);
    printf("	fabricPartitionId  %x\n",p_->fabricPartitionId);
    printf("	fabricCaps         %llx\n",p_->fabricCaps);
    printf("	fabricCliqueId     %x\n",p_->fabricCliqueId);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_CHIP_DETAILS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_CHIP_DETAILS_PARAMS\n");
    printf("	pciDevId   %x\n",p_->pciDevId);
    printf("	chipSku    %p\n",p_->chipSku);
    printf("	chipMajor  %x\n",p_->chipMajor);
    printf("	chipMinor  %x\n",p_->chipMinor);
}
void pretty_print(struct NV2080_CTRL_GPU_MOVE_RUNLISTS_ALLOCATION_TO_SUBHEAP_PARAMS* p_){
  printf("NV2080_CTRL_GPU_MOVE_RUNLISTS_ALLOCATION_TO_SUBHEAP_PARAMS\n");
    printf("	swizzId  %x\n",p_->swizzId);
}
void pretty_print(struct NV2080_CTRL_GPU_MIGRATABLE_OPS_CMN_PARAMS* p_){
  printf("NV2080_CTRL_GPU_MIGRATABLE_OPS_CMN_PARAMS\n");
    printf("	hClientTarget      %x\n",p_->hClientTarget);
    printf("	hChannelTarget     %x\n",p_->hChannelTarget);
    printf("	bNonTransactional  %x\n",p_->bNonTransactional);
    printf("	regOpCount         %x\n",p_->regOpCount);
    printf("	smIds              %p\n",p_->smIds);
    printf("	regOps             %p\n",p_->regOps);
    printf("	grRouteInfo        %x\n",p_->grRouteInfo);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_RESET_STATUS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_RESET_STATUS_PARAMS\n");
    printf("	bResetRequired  %x\n",p_->bResetRequired);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_DRAIN_AND_RESET_STATUS_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_DRAIN_AND_RESET_STATUS_PARAMS\n");
    printf("	bDrainRecommended  %x\n",p_->bDrainRecommended);
}
void pretty_print(struct NV2080_CTRL_GPU_GET_NVENC_SW_SESSION_INFO_V2_PARAMS* p_){
  printf("NV2080_CTRL_GPU_GET_NVENC_SW_SESSION_INFO_V2_PARAMS\n");
    printf("	sessionInfoTblEntry  %x\n",p_->sessionInfoTblEntry);
    printf("	sessionInfoTbl       %p\n",p_->sessionInfoTbl);
}
void pretty_print(struct NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS* p_){
  printf("NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS\n");
    printf("	hObject        %x\n",p_->hObject);
    printf("	classEngineID  %x\n",p_->classEngineID);
    printf("	classID        %x\n",p_->classID);
    printf("	engineID       %x\n",p_->engineID);
}
void pretty_print(struct NV906F_CTRL_CMD_RESET_CHANNEL_PARAMS* p_){
  printf("NV906F_CTRL_CMD_RESET_CHANNEL_PARAMS\n");
    printf("	engineID           %x\n",p_->engineID);
    printf("	subdeviceInstance  %x\n",p_->subdeviceInstance);
    printf("	resetReason        %x\n",p_->resetReason);
}
void pretty_print(struct NV906F_CTRL_EVENT_SET_NOTIFICATION_PARAMS* p_){
  printf("NV906F_CTRL_EVENT_SET_NOTIFICATION_PARAMS\n");
    printf("	event   %x\n",p_->event);
    printf("	action  %x\n",p_->action);
}
void pretty_print(struct NV906F_CTRL_CMD_GET_DEFER_RC_STATE_PARAMS* p_){
  printf("NV906F_CTRL_CMD_GET_DEFER_RC_STATE_PARAMS\n");
    printf("	bDeferRCPending  %x\n",p_->bDeferRCPending);
}
void pretty_print(struct NV906F_CTRL_GET_MMU_FAULT_INFO_PARAMS* p_){
  printf("NV906F_CTRL_GET_MMU_FAULT_INFO_PARAMS\n");
    printf("	addrHi           %x\n",p_->addrHi);
    printf("	addrLo           %x\n",p_->addrLo);
    printf("	faultType        %x\n",p_->faultType);
    printf("	faultString      %x\n",p_->faultString);
    printf("	shaderProgramVA  %p\n",p_->shaderProgramVA);
}
void pretty_print(struct NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS* p_){
  printf("NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS\n");
    printf("	bEnable      %x\n",p_->bEnable);
    printf("	bSkipSubmit  %x\n",p_->bSkipSubmit);
}
void pretty_print(struct NVA06F_CTRL_BIND_PARAMS* p_){
  printf("NVA06F_CTRL_BIND_PARAMS\n");
    printf("	engineType  %x\n",p_->engineType);
}
void pretty_print(struct NVA06F_CTRL_SET_ERROR_NOTIFIER_PARAMS* p_){
  printf("NVA06F_CTRL_SET_ERROR_NOTIFIER_PARAMS\n");
    printf("	bNotifyEachChannelInTSG  %x\n",p_->bNotifyEachChannelInTSG);
}
void pretty_print(struct NVA06F_CTRL_INTERLEAVE_LEVEL_PARAMS* p_){
  printf("NVA06F_CTRL_INTERLEAVE_LEVEL_PARAMS\n");
    printf("	channelInterleaveLevel  %x\n",p_->channelInterleaveLevel);
}
void pretty_print(struct NVA06F_CTRL_RESTART_RUNLIST_PARAMS* p_){
  printf("NVA06F_CTRL_RESTART_RUNLIST_PARAMS\n");
    printf("	bForceRestart  %x\n",p_->bForceRestart);
    printf("	bBypassWait    %x\n",p_->bBypassWait);
}
void pretty_print(struct NVA06F_CTRL_STOP_CHANNEL_PARAMS* p_){
  printf("NVA06F_CTRL_STOP_CHANNEL_PARAMS\n");
    printf("	bImmediate  %x\n",p_->bImmediate);
}
void pretty_print(struct NVA06F_CTRL_EVENT_SET_NOTIFICATION_PARAMS* p_){
  printf("NVA06F_CTRL_EVENT_SET_NOTIFICATION_PARAMS\n");
    printf("	event   %x\n",p_->event);
    printf("	action  %x\n",p_->action);
}
void pretty_print(struct NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS* p_){
  printf("NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS\n");
    printf("	workSubmitToken  %x\n",p_->workSubmitToken);
}
void pretty_print(struct NVC36F_CTRL_GPFIFO_UPDATE_FAULT_METHOD_BUFFER_PARAMS* p_){
  printf("NVC36F_CTRL_GPFIFO_UPDATE_FAULT_METHOD_BUFFER_PARAMS\n");
    printf("	bar2Addr  %p\n",p_->bar2Addr);
}
void pretty_print(struct NVC36F_CTRL_GPFIFO_SET_WORK_SUBMIT_TOKEN_NOTIF_INDEX_PARAMS* p_){
  printf("NVC36F_CTRL_GPFIFO_SET_WORK_SUBMIT_TOKEN_NOTIF_INDEX_PARAMS\n");
    printf("	index  %x\n",p_->index);
}
void pretty_print(struct _cl0000_tag0* p_){
  printf("_cl0000_tag0\n");
    printf("	Reserved00  %p\n",p_->Reserved00);
}
void pretty_print(struct NV0000_ALLOC_PARAMETERS* p_){
  printf("NV0000_ALLOC_PARAMETERS\n");
    printf("	hClient      %x\n",p_->hClient);
    printf("	processID    %x\n",p_->processID);
    printf("	processName  %x\n",p_->processName);
}
void pretty_print(struct RS_ACCESS_MASK* p_){
  printf("RS_ACCESS_MASK\n");
    printf("	limbs  %p\n",p_->limbs);
}
void pretty_print(struct RS_ACCESS_INFO* p_){
  printf("RS_ACCESS_INFO\n");
    printf("	flags  %x\n",p_->flags);
}
void pretty_print(struct RS_SHARE_POLICY* p_){
  printf("RS_SHARE_POLICY\n");
    printf("	target      %x\n",p_->target);
    printf("	accessMask  %x\n",p_->accessMask);
    printf("	type        %x\n",p_->type);
    printf("	action      %x\n",p_->action);
}
void pretty_print(struct NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS\n");
    printf("	hObject        %x\n",p_->hObject);
    printf("	mapFlags       %x\n",p_->mapFlags);
    printf("	addrSpaceType  %x\n",p_->addrSpaceType);
}
void pretty_print(struct NV0000_CTRL_CLIENT_GET_HANDLE_INFO_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_GET_HANDLE_INFO_PARAMS\n");
    printf("	hObject  %x\n",p_->hObject);
    printf("	index    %x\n",p_->index);
    printf("	data     %x\n",p_->data);
    printf("	hResult  %x\n" , p_->data.hResult);
    printf("	iResult  %llx\n" , p_->data.iResult);
}
void pretty_print(struct NV0000_CTRL_CLIENT_GET_ACCESS_RIGHTS_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_GET_ACCESS_RIGHTS_PARAMS\n");
    printf("	hObject     %x\n",p_->hObject);
    printf("	hClient     %x\n",p_->hClient);
    printf("	maskResult  %x\n",p_->maskResult);
}
void pretty_print(struct NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS\n");
    printf("	sharePolicy  %x\n",p_->sharePolicy);
}
void pretty_print(struct NV0000_CTRL_CMD_CLIENT_GET_CHILD_HANDLE_PARAMS* p_){
  printf("NV0000_CTRL_CMD_CLIENT_GET_CHILD_HANDLE_PARAMS\n");
    printf("	hParent  %x\n",p_->hParent);
    printf("	classId  %x\n",p_->classId);
    printf("	hObject  %x\n",p_->hObject);
}
void pretty_print(struct NV0000_CTRL_CLIENT_SHARE_OBJECT_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_SHARE_OBJECT_PARAMS\n");
    printf("	hObject      %x\n",p_->hObject);
    printf("	sharePolicy  %x\n",p_->sharePolicy);
}
void pretty_print(struct NV0000_CTRL_CLIENT_OBJECTS_ARE_DUPLICATES_PARAMS* p_){
  printf("NV0000_CTRL_CLIENT_OBJECTS_ARE_DUPLICATES_PARAMS\n");
    printf("	hObject1     %x\n",p_->hObject1);
    printf("	hObject2     %x\n",p_->hObject2);
    printf("	bDuplicates  %x\n",p_->bDuplicates);
}

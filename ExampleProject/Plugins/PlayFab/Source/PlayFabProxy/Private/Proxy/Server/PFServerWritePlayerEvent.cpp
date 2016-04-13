// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerWritePlayerEvent.h"

UPFServerWritePlayerEvent::UPFServerWritePlayerEvent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FWritePlayerEventDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerWritePlayerEvent* UPFServerWritePlayerEvent::WritePlayerEvent(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InEventName, const FDateTime& InTimestamp)
{
	UPFServerWritePlayerEvent* Proxy = NewObject<UPFServerWritePlayerEvent>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.EventName = InEventName;
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerWritePlayerEvent::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->WritePlayerEvent(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerWriteEventResponse BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerWritePlayerEvent::OnSuccessCallback(const PlayFab::ServerModels::FWriteEventResponse& Result)
{
	FBPServerWriteEventResponse BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerWritePlayerEvent::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerWriteEventResponse BPResult;
 	OnFailure.Broadcast(BPResult);	
}

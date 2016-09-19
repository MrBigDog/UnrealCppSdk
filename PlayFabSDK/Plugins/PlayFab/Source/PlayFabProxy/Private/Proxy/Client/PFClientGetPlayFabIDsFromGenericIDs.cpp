// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetPlayFabIDsFromGenericIDs.h"

UPFClientGetPlayFabIDsFromGenericIDs::UPFClientGetPlayFabIDsFromGenericIDs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayFabIDsFromGenericIDsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetPlayFabIDsFromGenericIDs* UPFClientGetPlayFabIDsFromGenericIDs::GetPlayFabIDsFromGenericIDs(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<FBPClientGenericServiceId>& InGenericIDs)
{
	UPFClientGetPlayFabIDsFromGenericIDs* Proxy = NewObject<UPFClientGetPlayFabIDsFromGenericIDs>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	for (const FBPClientGenericServiceId& elem : InGenericIDs)
    {
        Proxy->Request.GenericIDs.Add(elem.Data);
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetPlayFabIDsFromGenericIDs::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetPlayFabIDsFromGenericIDs(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetPlayFabIDsFromGenericIDsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetPlayFabIDsFromGenericIDs::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayFabIDsFromGenericIDsResult& Result)
{
	FBPClientGetPlayFabIDsFromGenericIDsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetPlayFabIDsFromGenericIDs::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetPlayFabIDsFromGenericIDsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
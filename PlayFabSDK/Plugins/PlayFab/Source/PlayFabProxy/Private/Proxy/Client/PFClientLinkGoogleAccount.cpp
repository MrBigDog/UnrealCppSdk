// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientLinkGoogleAccount.h"

UPFClientLinkGoogleAccount::UPFClientLinkGoogleAccount(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLinkGoogleAccountDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLinkGoogleAccount* UPFClientLinkGoogleAccount::LinkGoogleAccount(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InServerAuthCode, const bool& InForceLink)
{
	UPFClientLinkGoogleAccount* Proxy = NewObject<UPFClientLinkGoogleAccount>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.ServerAuthCode = InServerAuthCode;
	Proxy->Request.ForceLink = InForceLink;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLinkGoogleAccount::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LinkGoogleAccount(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLinkGoogleAccount::OnSuccessCallback(const PlayFab::ClientModels::FLinkGoogleAccountResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientLinkGoogleAccount::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}

// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientLoginWithIOSDeviceID.h"

UPFClientLoginWithIOSDeviceID::UPFClientLoginWithIOSDeviceID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLoginWithIOSDeviceIDDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLoginWithIOSDeviceID* UPFClientLoginWithIOSDeviceID::LoginWithIOSDeviceID(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InDeviceId, const FString& InOS, const FString& InDeviceModel, const bool& InCreateAccount, const FString& InTitleId, const FString& InEncryptedRequest, const FString& InPlayerSecret, const FBPClientGetPlayerCombinedInfoRequestParams& InInfoRequestParameters)
{
	UPFClientLoginWithIOSDeviceID* Proxy = NewObject<UPFClientLoginWithIOSDeviceID>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.DeviceId = InDeviceId;
	Proxy->Request.OS = InOS;
	Proxy->Request.DeviceModel = InDeviceModel;
	Proxy->Request.CreateAccount = InCreateAccount;
	Proxy->Request.TitleId = InTitleId;
	Proxy->Request.EncryptedRequest = InEncryptedRequest;
	Proxy->Request.PlayerSecret = InPlayerSecret;
	*Proxy->Request.InfoRequestParameters = InInfoRequestParameters.Data;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLoginWithIOSDeviceID::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LoginWithIOSDeviceID(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientLoginResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLoginWithIOSDeviceID::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
	FBPClientLoginResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientLoginWithIOSDeviceID::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientLoginResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}

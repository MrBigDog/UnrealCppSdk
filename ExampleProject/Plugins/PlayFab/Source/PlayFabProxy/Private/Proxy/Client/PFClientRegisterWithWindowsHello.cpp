// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientRegisterWithWindowsHello.h"

UPFClientRegisterWithWindowsHello::UPFClientRegisterWithWindowsHello(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FRegisterWithWindowsHelloDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientRegisterWithWindowsHello* UPFClientRegisterWithWindowsHello::RegisterWithWindowsHello(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InUserName, const FString& InPublicKey, const FString& InDeviceName, const FString& InTitleId, const FString& InEncryptedRequest, const FString& InPlayerSecret, const FBPClientGetPlayerCombinedInfoRequestParams& InInfoRequestParameters)
{
	UPFClientRegisterWithWindowsHello* Proxy = NewObject<UPFClientRegisterWithWindowsHello>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.UserName = InUserName;
	Proxy->Request.PublicKey = InPublicKey;
	Proxy->Request.DeviceName = InDeviceName;
	Proxy->Request.TitleId = InTitleId;
	Proxy->Request.EncryptedRequest = InEncryptedRequest;
	Proxy->Request.PlayerSecret = InPlayerSecret;
	*Proxy->Request.InfoRequestParameters = InInfoRequestParameters.Data;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientRegisterWithWindowsHello::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->RegisterWithWindowsHello(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientLoginResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientRegisterWithWindowsHello::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
	FBPClientLoginResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientRegisterWithWindowsHello::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientLoginResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}

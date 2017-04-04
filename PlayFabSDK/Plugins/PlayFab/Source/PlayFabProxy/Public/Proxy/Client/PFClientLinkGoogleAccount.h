// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLinkGoogleAccount.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientLinkGoogleAccount : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Links the currently signed-in user account to their Google account, using their Google account credentials
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Account Management")
	static UPFClientLinkGoogleAccount* LinkGoogleAccount(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InServerAuthCode, const bool& InForceLink);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FLinkGoogleAccountRequest Request;

	PlayFab::UPlayFabClientAPI::FLinkGoogleAccountDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FLinkGoogleAccountResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};

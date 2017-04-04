// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLoginWithEmailAddress.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientLoginWithEmailAddress : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientLoginResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientLoginResultDelegate OnFailure;
	
	// Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user. Unlike most other login API calls, LoginWithEmailAddress does not permit the  creation of new accounts via the CreateAccountFlag. Email addresses may be used to create accounts via RegisterPlayFabUser.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Authentication")
	static UPFClientLoginWithEmailAddress* LoginWithEmailAddress(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InTitleId, const FString& InEmail, const FString& InPassword, const FBPClientGetPlayerCombinedInfoRequestParams& InInfoRequestParameters);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FLoginWithEmailAddressRequest Request;

	PlayFab::UPlayFabClientAPI::FLoginWithEmailAddressDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};

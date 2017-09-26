// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetPlayFabIDsFromSteamIDs.generated.h"

UCLASS(MinimalAPI)
class UPFClientGetPlayFabIDsFromSteamIDs : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientGetPlayFabIDsFromSteamIDsResultDelegate OnSuccess;

    // Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers  are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Account Management")
        static UPFClientGetPlayFabIDsFromSteamIDs* GetPlayFabIDsFromSteamIDs(class APlayerController* PlayerController, const FBPClientGetPlayFabIDsFromSteamIDsRequest& InGetPlayFabIDsFromSteamIDsRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientGetPlayFabIDsFromSteamIDsRequest Request;
    PlayFab::UPlayFabClientAPI::FGetPlayFabIDsFromSteamIDsDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FGetPlayFabIDsFromSteamIDsResult& Result);
};

// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetCharacterInventory.generated.h"

UCLASS(MinimalAPI)
class UPFClientGetCharacterInventory : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientGetCharacterInventoryResultDelegate OnSuccess;

    // Retrieves the specified character's current inventory of virtual goods
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Player Item Management")
        static UPFClientGetCharacterInventory* GetCharacterInventory(class APlayerController* PlayerController, const FBPClientGetCharacterInventoryRequest& InGetCharacterInventoryRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientGetCharacterInventoryRequest Request;
    PlayFab::UPlayFabClientAPI::FGetCharacterInventoryDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FGetCharacterInventoryResult& Result);
};
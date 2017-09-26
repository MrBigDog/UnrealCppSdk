// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerUpdateCharacterReadOnlyData.generated.h"

UCLASS(MinimalAPI)
class UPFServerUpdateCharacterReadOnlyData : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPServerUpdateCharacterDataResultDelegate OnSuccess;

    // Updates the title-specific custom data for the user's character which can only be read by the client
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Character Data")
        static UPFServerUpdateCharacterReadOnlyData* UpdateCharacterReadOnlyData(class APlayerController* PlayerController, const FBPServerUpdateCharacterDataRequest& InUpdateCharacterDataRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerUpdateCharacterDataRequest Request;
    PlayFab::UPlayFabServerAPI::FUpdateCharacterReadOnlyDataDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FUpdateCharacterDataResult& Result);
};

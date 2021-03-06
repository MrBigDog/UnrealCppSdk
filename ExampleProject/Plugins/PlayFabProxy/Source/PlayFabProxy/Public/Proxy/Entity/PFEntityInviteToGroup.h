// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabEntityAPI.h"
#include "Core/PlayFabEntityDataModels.h"
#include "Proxy/PlayFabEntityBPDataModels.h"
#include "PFEntityInviteToGroup.generated.h"

UCLASS(MinimalAPI)
class UPFEntityInviteToGroup : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPEntityInviteToGroupResponseDelegate OnSuccess;

    // Invites a player to join a group
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Entity|Groups")
        static UPFEntityInviteToGroup* InviteToGroup(class APlayerController* PlayerController, const FBPEntityInviteToGroupRequest& InInviteToGroupRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPEntityInviteToGroupRequest Request;
    PlayFab::UPlayFabEntityAPI::FInviteToGroupDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::EntityModels::FInviteToGroupResponse& Result);
};

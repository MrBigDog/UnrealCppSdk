// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabEntityAPI.h"
#include "Core/PlayFabEntityDataModels.h"
#include "Proxy/PlayFabEntityBPDataModels.h"
#include "PFEntityListGroupInvitations.generated.h"

UCLASS(MinimalAPI)
class UPFEntityListGroupInvitations : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPEntityListGroupInvitationsResponseDelegate OnSuccess;

    // Lists all outstanding invitations for a group
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Entity|Groups")
        static UPFEntityListGroupInvitations* ListGroupInvitations(class APlayerController* PlayerController, const FBPEntityListGroupInvitationsRequest& InListGroupInvitationsRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPEntityListGroupInvitationsRequest Request;
    PlayFab::UPlayFabEntityAPI::FListGroupInvitationsDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::EntityModels::FListGroupInvitationsResponse& Result);
};

// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGrantCharacterToUser.generated.h"

UCLASS(MinimalAPI)
class UPFClientGrantCharacterToUser : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientGrantCharacterToUserResultDelegate OnSuccess;

    // Grants the specified character type to the user. CharacterIds are not globally unique; characterId must be evaluated with the parent PlayFabId to guarantee uniqueness.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Characters")
        static UPFClientGrantCharacterToUser* GrantCharacterToUser(class APlayerController* PlayerController, const FBPClientGrantCharacterToUserRequest& InGrantCharacterToUserRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientGrantCharacterToUserRequest Request;
    PlayFab::UPlayFabClientAPI::FGrantCharacterToUserDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FGrantCharacterToUserResult& Result);
};

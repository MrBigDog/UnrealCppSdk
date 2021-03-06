// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntityDeleteRole.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntityDeleteRole::UPFEntityDeleteRole(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FDeleteRoleDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntityDeleteRole* UPFEntityDeleteRole::DeleteRole(class APlayerController* PlayerController, const FBPEntityDeleteRoleRequest& InDeleteRoleRequest)
{
    UPFEntityDeleteRole* Proxy = NewObject<UPFEntityDeleteRole>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InDeleteRoleRequest;
    
    return Proxy;
}

void UPFEntityDeleteRole::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->DeleteRole(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntityDeleteRole::OnSuccessCallback(const PlayFab::EntityModels::FEmptyResult& Result)
{
    OnSuccess.Broadcast();
}

// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminCreatePlayerStatisticDefinition.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminCreatePlayerStatisticDefinition::UPFAdminCreatePlayerStatisticDefinition(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FCreatePlayerStatisticDefinitionDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminCreatePlayerStatisticDefinition* UPFAdminCreatePlayerStatisticDefinition::CreatePlayerStatisticDefinition(class APlayerController* PlayerController, const FBPAdminCreatePlayerStatisticDefinitionRequest& InCreatePlayerStatisticDefinitionRequest)
{
    UPFAdminCreatePlayerStatisticDefinition* Proxy = NewObject<UPFAdminCreatePlayerStatisticDefinition>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InCreatePlayerStatisticDefinitionRequest;
    
    return Proxy;
}

void UPFAdminCreatePlayerStatisticDefinition::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->CreatePlayerStatisticDefinition(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminCreatePlayerStatisticDefinition::OnSuccessCallback(const PlayFab::AdminModels::FCreatePlayerStatisticDefinitionResult& Result)
{
    FBPAdminCreatePlayerStatisticDefinitionResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}

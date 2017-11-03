// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PlayFabMatchmakerBPLibrary.h"
#include "Core/PlayFabBaseModel.h"
#include "PlayFabJsonValue.h"


// AuthUserRequest
FBPMatchmakerAuthUserRequest UPFMatchmakerProxyLibrary::MakeBPMatchmakerAuthUserRequest(
    FString InAuthorizationTicket
    )
{
    FBPMatchmakerAuthUserRequest Out = FBPMatchmakerAuthUserRequest();
    Out.Data.AuthorizationTicket = InAuthorizationTicket;
	
    return Out;
}

// AuthUserResponse
void UPFMatchmakerProxyLibrary::BreakBPMatchmakerAuthUserResponse(
    const FBPMatchmakerAuthUserResponse& In
	, bool& OutAuthorized
	, FString& OutPlayFabId
 )
{
    OutAuthorized = In.Data.Authorized;
	OutPlayFabId = In.Data.PlayFabId;
	
}

// DeregisterGameRequest
FBPMatchmakerDeregisterGameRequest UPFMatchmakerProxyLibrary::MakeBPMatchmakerDeregisterGameRequest(
    FString InLobbyId
    )
{
    FBPMatchmakerDeregisterGameRequest Out = FBPMatchmakerDeregisterGameRequest();
    Out.Data.LobbyId = InLobbyId;
	
    return Out;
}

// DeregisterGameResponse
void UPFMatchmakerProxyLibrary::BreakBPMatchmakerDeregisterGameResponse(
    const FBPMatchmakerDeregisterGameResponse& In
 )
{
    
}

// ItemInstance
FBPMatchmakerItemInstance UPFMatchmakerProxyLibrary::MakeBPMatchmakerItemInstance(
    FString InAnnotation
	, TArray<FString> InBundleContents
	, FString InBundleParent
	, FString InCatalogVersion
	, TMap<FString, FString> InCustomData
	, FString InDisplayName
	, FDateTime InExpiration
	, FString InItemClass
	, FString InItemId
	, FString InItemInstanceId
	, FDateTime InPurchaseDate
	, int32 InRemainingUses
	, FString InUnitCurrency
	, int32 InUnitPrice
	, int32 InUsesIncrementedBy
    )
{
    FBPMatchmakerItemInstance Out = FBPMatchmakerItemInstance();
    Out.Data.Annotation = InAnnotation;
	Out.Data.BundleContents = InBundleContents;
	Out.Data.BundleParent = InBundleParent;
	Out.Data.CatalogVersion = InCatalogVersion;
	Out.Data.CustomData = InCustomData;
	Out.Data.DisplayName = InDisplayName;
	Out.Data.Expiration = InExpiration;
	Out.Data.ItemClass = InItemClass;
	Out.Data.ItemId = InItemId;
	Out.Data.ItemInstanceId = InItemInstanceId;
	Out.Data.PurchaseDate = InPurchaseDate;
	Out.Data.RemainingUses = InRemainingUses;
	Out.Data.UnitCurrency = InUnitCurrency;
	Out.Data.UnitPrice = InUnitPrice;
	Out.Data.UsesIncrementedBy = InUsesIncrementedBy;
	
    return Out;
}
void UPFMatchmakerProxyLibrary::BreakBPMatchmakerItemInstance(
    const FBPMatchmakerItemInstance& In
	, FString& OutAnnotation
	, TArray<FString>& OutBundleContents
	, FString& OutBundleParent
	, FString& OutCatalogVersion
	, TMap<FString, FString>& OutCustomData
	, FString& OutDisplayName
	, FDateTime& OutExpiration
	, FString& OutItemClass
	, FString& OutItemId
	, FString& OutItemInstanceId
	, FDateTime& OutPurchaseDate
	, int32& OutRemainingUses
	, FString& OutUnitCurrency
	, int32& OutUnitPrice
	, int32& OutUsesIncrementedBy
 )
{
    OutAnnotation = In.Data.Annotation;
	OutBundleContents = In.Data.BundleContents;
	OutBundleParent = In.Data.BundleParent;
	OutCatalogVersion = In.Data.CatalogVersion;
	OutCustomData = In.Data.CustomData;
	OutDisplayName = In.Data.DisplayName;
	OutExpiration = In.Data.Expiration;
	OutItemClass = In.Data.ItemClass;
	OutItemId = In.Data.ItemId;
	OutItemInstanceId = In.Data.ItemInstanceId;
	OutPurchaseDate = In.Data.PurchaseDate;
	OutRemainingUses = In.Data.RemainingUses;
	OutUnitCurrency = In.Data.UnitCurrency;
	OutUnitPrice = In.Data.UnitPrice;
	OutUsesIncrementedBy = In.Data.UsesIncrementedBy;
	
}

// PlayerJoinedRequest
FBPMatchmakerPlayerJoinedRequest UPFMatchmakerProxyLibrary::MakeBPMatchmakerPlayerJoinedRequest(
    FString InLobbyId
	, FString InPlayFabId
    )
{
    FBPMatchmakerPlayerJoinedRequest Out = FBPMatchmakerPlayerJoinedRequest();
    Out.Data.LobbyId = InLobbyId;
	Out.Data.PlayFabId = InPlayFabId;
	
    return Out;
}

// PlayerJoinedResponse
void UPFMatchmakerProxyLibrary::BreakBPMatchmakerPlayerJoinedResponse(
    const FBPMatchmakerPlayerJoinedResponse& In
 )
{
    
}

// PlayerLeftRequest
FBPMatchmakerPlayerLeftRequest UPFMatchmakerProxyLibrary::MakeBPMatchmakerPlayerLeftRequest(
    FString InLobbyId
	, FString InPlayFabId
    )
{
    FBPMatchmakerPlayerLeftRequest Out = FBPMatchmakerPlayerLeftRequest();
    Out.Data.LobbyId = InLobbyId;
	Out.Data.PlayFabId = InPlayFabId;
	
    return Out;
}

// PlayerLeftResponse
void UPFMatchmakerProxyLibrary::BreakBPMatchmakerPlayerLeftResponse(
    const FBPMatchmakerPlayerLeftResponse& In
 )
{
    
}

// RegisterGameRequest
FBPMatchmakerRegisterGameRequest UPFMatchmakerProxyLibrary::MakeBPMatchmakerRegisterGameRequest(
    FString InBuild
	, FString InGameMode
	, FString InLobbyId
	, EBPMatchmakerRegion InRegion
	, FString InServerHost
	, FString InServerIPV6Address
	, FString InServerPort
	, TMap<FString, FString> InTags
    )
{
    FBPMatchmakerRegisterGameRequest Out = FBPMatchmakerRegisterGameRequest();
    Out.Data.Build = InBuild;
	Out.Data.GameMode = InGameMode;
	Out.Data.LobbyId = InLobbyId;
	Out.Data.pfRegion = static_cast<PlayFab::MatchmakerModels::Region>(static_cast<uint8>(InRegion));
	Out.Data.ServerHost = InServerHost;
	Out.Data.ServerIPV6Address = InServerIPV6Address;
	Out.Data.ServerPort = InServerPort;
	Out.Data.Tags = InTags;
	
    return Out;
}

// RegisterGameResponse
void UPFMatchmakerProxyLibrary::BreakBPMatchmakerRegisterGameResponse(
    const FBPMatchmakerRegisterGameResponse& In
	, FString& OutLobbyId
 )
{
    OutLobbyId = In.Data.LobbyId;
	
}

// StartGameRequest
FBPMatchmakerStartGameRequest UPFMatchmakerProxyLibrary::MakeBPMatchmakerStartGameRequest(
    FString InBuild
	, FString InCustomCommandLineData
	, FString InExternalMatchmakerEventEndpoint
	, FString InGameMode
	, EBPMatchmakerRegion InRegion
    )
{
    FBPMatchmakerStartGameRequest Out = FBPMatchmakerStartGameRequest();
    Out.Data.Build = InBuild;
	Out.Data.CustomCommandLineData = InCustomCommandLineData;
	Out.Data.ExternalMatchmakerEventEndpoint = InExternalMatchmakerEventEndpoint;
	Out.Data.GameMode = InGameMode;
	Out.Data.pfRegion = static_cast<PlayFab::MatchmakerModels::Region>(static_cast<uint8>(InRegion));
	
    return Out;
}

// StartGameResponse
void UPFMatchmakerProxyLibrary::BreakBPMatchmakerStartGameResponse(
    const FBPMatchmakerStartGameResponse& In
	, FString& OutGameID
	, FString& OutServerHostname
	, FString& OutServerIPV6Address
	, int32& OutServerPort
 )
{
    OutGameID = In.Data.GameID;
	OutServerHostname = In.Data.ServerHostname;
	OutServerIPV6Address = In.Data.ServerIPV6Address;
	OutServerPort = In.Data.ServerPort;
	
}

// UserInfoRequest
FBPMatchmakerUserInfoRequest UPFMatchmakerProxyLibrary::MakeBPMatchmakerUserInfoRequest(
    int32 InMinCatalogVersion
	, FString InPlayFabId
    )
{
    FBPMatchmakerUserInfoRequest Out = FBPMatchmakerUserInfoRequest();
    Out.Data.MinCatalogVersion = InMinCatalogVersion;
	Out.Data.PlayFabId = InPlayFabId;
	
    return Out;
}

// UserInfoResponse
void UPFMatchmakerProxyLibrary::BreakBPMatchmakerUserInfoResponse(
    const FBPMatchmakerUserInfoResponse& In
	, TArray<FBPMatchmakerItemInstance>& OutInventory
	, bool& OutIsDeveloper
	, FString& OutPlayFabId
	, FString& OutSteamId
	, FString& OutTitleDisplayName
	, FString& OutUsername
	, TMap<FString, int32>& OutVirtualCurrency
	, TMap<FString, FBPMatchmakerVirtualCurrencyRechargeTime>& OutVirtualCurrencyRechargeTimes
 )
{
    for (const PlayFab::MatchmakerModels::FItemInstance& elem : In.Data.Inventory)
	{
		OutInventory.Add(FBPMatchmakerItemInstance(elem));
	}
	OutIsDeveloper = In.Data.IsDeveloper;
	OutPlayFabId = In.Data.PlayFabId;
	OutSteamId = In.Data.SteamId;
	OutTitleDisplayName = In.Data.TitleDisplayName;
	OutUsername = In.Data.Username;
	OutVirtualCurrency = In.Data.VirtualCurrency;
	for (auto& elem : In.Data.VirtualCurrencyRechargeTimes)
	{
		const PlayFab::MatchmakerModels::FVirtualCurrencyRechargeTime value = elem.Value;
		OutVirtualCurrencyRechargeTimes.Add(elem.Key, FBPMatchmakerVirtualCurrencyRechargeTime(value));
	}
	
}

// VirtualCurrencyRechargeTime
FBPMatchmakerVirtualCurrencyRechargeTime UPFMatchmakerProxyLibrary::MakeBPMatchmakerVirtualCurrencyRechargeTime(
    int32 InRechargeMax
	, FDateTime InRechargeTime
	, int32 InSecondsToRecharge
    )
{
    FBPMatchmakerVirtualCurrencyRechargeTime Out = FBPMatchmakerVirtualCurrencyRechargeTime();
    Out.Data.RechargeMax = InRechargeMax;
	Out.Data.RechargeTime = InRechargeTime;
	Out.Data.SecondsToRecharge = InSecondsToRecharge;
	
    return Out;
}
void UPFMatchmakerProxyLibrary::BreakBPMatchmakerVirtualCurrencyRechargeTime(
    const FBPMatchmakerVirtualCurrencyRechargeTime& In
	, int32& OutRechargeMax
	, FDateTime& OutRechargeTime
	, int32& OutSecondsToRecharge
 )
{
    OutRechargeMax = In.Data.RechargeMax;
	OutRechargeTime = In.Data.RechargeTime;
	OutSecondsToRecharge = In.Data.SecondsToRecharge;
	
}


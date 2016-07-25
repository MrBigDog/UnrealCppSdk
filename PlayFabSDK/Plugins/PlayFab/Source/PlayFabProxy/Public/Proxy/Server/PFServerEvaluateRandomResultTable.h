// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerEvaluateRandomResultTable.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerEvaluateRandomResultTable : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerEvaluateRandomResultTableResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerEvaluateRandomResultTableResultDelegate OnFailure;
	
	// Returns the result of an evaluation of a Random Result Table - the ItemId from the game Catalog which would have been added to the player inventory, if the Random Result Table were added via a Bundle or a call to UnlockContainer.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Player Item Management")
	static UPFServerEvaluateRandomResultTable* EvaluateRandomResultTable(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InTableId, const FString& InCatalogVersion);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FEvaluateRandomResultTableRequest Request;

	PlayFab::UPlayFabServerAPI::FEvaluateRandomResultTableDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FEvaluateRandomResultTableResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
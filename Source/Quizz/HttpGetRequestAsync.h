// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UserRecewvied.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "HttpGetRequestAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHttpRequestCompleted, const FString&, MOTD, bool, bSuccess);

UCLASS()
class QUIZZ_API UHttpGetRequestAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
protected:

	void HandleRequestCompleted(FString ResponseString, bool bSuccess);

public:

	/** Execute the actual load */
	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "HTTP", WorldContext = "WorldContextObject"))
		static UHttpGetRequestAsync* AsyncRequestHTTP(UObject* WorldContextObject, FString URL);

	UPROPERTY(BlueprintAssignable)
		FOnHttpRequestCompleted Completed;

	/* URL to send GET request to */
	FString URL;
};

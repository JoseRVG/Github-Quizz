// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HttpModule.h"
#include "HttpManager.h"
#include <sstream>
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
#include "Http.h"
#include "IHttpRequest.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UserRecewvied.generated.h"

USTRUCT(BlueprintType)
struct FUserData
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString iveniraID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString activityID;

	UPROPERTY()
		UObject* SafeObjectPointer;
};
/**
 * 
 */
UCLASS()
class QUIZZ_API UUserRecewvied : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static void ReceivedUserData(FUserData &UserData, FString &IveniraID);
};

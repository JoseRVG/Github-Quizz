// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/Online/HTTP/Public/Http.h"
#include "HttpModule.h"
#include "HttpManager.h"
#include <sstream>
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
#include "Http.h"
#include "Interfaces/IHttpRequest.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UserRecewvied.generated.h"

USTRUCT(BlueprintType)
struct FDataUser
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString studentID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString activityID;

	UPROPERTY()
		UObject* SafeObjectPointer;
};

UCLASS()
class QUIZZ_API UUserRecewvied : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "ToolTip")
	static void ReceivedUserData(int32 ResponseAct, FString ResponseUser, FDataUser& UserData, FString& IveniraID);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
	static bool SendGameCode(FString Code, TArray<FString> DBCode, FString& User, int32& ActivityID, FString& GameCode);
};

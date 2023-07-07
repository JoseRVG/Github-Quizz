// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GenericPlatform/GenericPlatformProcess.h"
#include "UserRecewvied.h"
#include "Interfaces/IHttpRequest.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HTTPGameRequest.generated.h"

USTRUCT(BlueprintType)
struct FActivity
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString activityName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString firstQuestionID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString json;

	UPROPERTY()
		UObject* SafeObjectPointer;
};

USTRUCT(BlueprintType)
struct FActivityResults
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString studentID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString userName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString question;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString answer;

	UPROPERTY()
		UObject* SafeObjectPointer;
};

UCLASS()
class QUIZZ_API UHTTPGameRequest : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static int32 GameSend(FString Name, FString Age, FDataUser UserData, FString GameCode);
};

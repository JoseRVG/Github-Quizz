// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HTTPGameRequest.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameAnalitics.generated.h"

/**
 * 
 */
UCLASS()
class QUIZZ_API UGameAnalitics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

	UFUNCTION(BlueprintCallable, Category = "ToolTip")
	static void GameAnalitcs(FString ActivityID, FString ActivityName, FString AnswerID);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
	static FString GetAnswer(FString AnswerID1, FString AnswerID2, FString AnswerID3, FString Button);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
	static void ProcessAcitivityResults(TArray<FActivityResults> Results, FString UserName, FString UserID, TArray<FString>& Question, TArray<FString>& Answer);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static void StartAnalitcs(FString ActivityID);
};

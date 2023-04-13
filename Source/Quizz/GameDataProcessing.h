// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Misc/Char.h"
#include "HTTPGameRequest.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameDataProcessing.generated.h"

USTRUCT(BlueprintType)
struct FQuestion
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString question;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString answerA1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString answerID1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString answer1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString feedback1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString nextQuestion1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString answerA2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString answerID2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString answer2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString feedback2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString nextQuestion2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString answerA3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString answerID3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString answer3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString feedback3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString nextQuestion3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString anexedFile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString videoLink;

	UPROPERTY()
		UObject* SafeObjectPointer;
};

/**
 * 
 */
UCLASS()
class QUIZZ_API UGameDataProcessing : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static void ProcessActivity(const TArray<FActivity> Activities, const int32 ActivityID, FString &Questions, FString &FirstQuestion, FString &ActivityName);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static TArray<FQuestion> ProcessQuizz(TArray<FString> Questions);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static void ProcessGame(TArray<FQuestion> ProcessedQuestions, FString QuestionID, FString Button1, FString NextQuestionID1, FString NextQuestionID2, FString Button2, FString NextQuestionID3, FString Button3, FString &Question, FString &AnexedFile, FString &videoLink, FString &AnswerID1, FString &Answer1, FString &Feedback1, FString &NextQuestion1, FString &AnswerID2, FString &Answer2, FString &Feedback2, FString &NextQuestion2, FString &AnswerID3, FString &Answer3, FString &Feedback3, FString &NextQuestion3);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static bool ProcessURL(FString URL);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static bool ProcessEndGame(FString EndCondition);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static FString ProcessNextQuestion(FString NextQuestion);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static TArray<FActivity> ProcessActivityString(FString ActivityString);
	UFUNCTION(BlueprintCallable, Category = "ToolTip")
		static TArray<FActivityResults> ProcessActivityResultsString(FString ActivityResults);
};

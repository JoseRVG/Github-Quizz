// Fill out your copyright notice in the Description page of Project Settings.


#include "GameDataProcessing.h"

void UGameDataProcessing::ProcessActivity(const TArray<FActivity> Activities, const int32 ActivityID, FString& Questions, FString& FirstQuestion, FString& ActivityName)
{
	for (int32 i = 0; i < Activities.Num(); i++) {
		if (Activities[i].id == ActivityID) {
			ActivityName = Activities[i].activityName;
			Questions = Activities[i].json;
			FirstQuestion = Activities[i].firstQuestionID;
		}
	}
}

TArray<FQuestion> UGameDataProcessing::ProcessQuizz(TArray<FString> Questions)
{
	TArray<FQuestion> Question;
	int32 i = 0;
	while (i < Questions.Num() - 1) {
		FQuestion TempQuestion;
		TempQuestion.id = Questions[i];
		if (i < Questions.Num() - 1) {
			i++;
		}
		else {
			break;
		}
		TempQuestion.question = Questions[i];
		if (i < Questions.Num() - 1) {
			i++;
		}
		else {
			break;
		}
		if (Questions[i] == "nothing") {
			TempQuestion.anexedFile = Questions[i];
		}
		else {
			TempQuestion.anexedFile = "http://localhost/server/media/" + Questions[i];
		}
		if (i < Questions.Num() - 1) {

			i++;
		}
		else {
			break;
		}
		if (Questions[i] == "nothing") {
			TempQuestion.videoLink = Questions[i];
		}
		else {
			TempQuestion.videoLink = Questions[i];
		}
		if (i < Questions.Num() - 1) {
			i++;
		}
		else {
			break;
		}
		TempQuestion.answerA1 = Questions[i];
		if (i < Questions.Num() - 1) {

			i++;
		}
		else {
			break;
		}
		TempQuestion.answerID1 = Questions[i];
		if (i < Questions.Num() - 1) {

			i++;
		}
		else {
			break;
		}
		TempQuestion.answer1 = Questions[i];
		if (i < Questions.Num() - 1) {

			i++;
		}
		else {
			break;
		}
		TempQuestion.feedback1 = Questions[i];
		if (i < Questions.Num() - 1) {

			i++;
		}
		else {
			break;
		}
		TempQuestion.nextQuestion1 = Questions[i];
		if (i < Questions.Num() - 1) {

			i++;
		}
		else {
			break;
		}
		if (Questions[i] == "A2") {
			TempQuestion.answerA2 = Questions[i];
			if (i < Questions.Num() - 1) {
				i++;
			}
			else {
				break;
			}
			TempQuestion.answerID2 = Questions[i];
			if (i < Questions.Num() - 1) {
				i++;
			}
			else {
				break;
			}
			TempQuestion.answer2 = Questions[i];
			if (i < Questions.Num() - 1) {
				i++;
			}
			else {
				break;
			}
			TempQuestion.feedback2 = Questions[i];
			if (i < Questions.Num() - 1) {
				i++;
			}
			else {
				break;
			}
			TempQuestion.nextQuestion2 = Questions[i];
			if (i < Questions.Num() - 1) {
				i++;
			}
			else {
				break;
			}
		}
		if (Questions[i] == "A3") {
			TempQuestion.answerA3 = Questions[i];
			if (i < Questions.Num() - 1) {
				i++;
			}
			else {
				break;
			}
			TempQuestion.answerID3 = Questions[i];
			if (i < Questions.Num() - 1) {
				i++;
			}
			else {
				break;
			}
			TempQuestion.answer3 = Questions[i];
			if (i < Questions.Num() - 1) {
				i++;
			}
			else {
				break;
			}
			TempQuestion.feedback3 = Questions[i];
			if (i < Questions.Num() - 1) {
				i++;
			}
			else {
				break;
			}
			TempQuestion.nextQuestion3 = Questions[i];
			if (i < Questions.Num() - 1) {
				i++;
			}
			else {
				break;
			}
		}
		Question.Add(TempQuestion);
	}
	return Question;
}

void UGameDataProcessing::ProcessGame(TArray<FQuestion> ProcessedQuestions, FString QuestionID, FString Button1, FString NextQuestionID1, FString NextQuestionID2, FString Button2, FString NextQuestionID3, FString Button3, FString& Question, FString& AnexedFile, FString& videoLink, FString& AnswerID1, FString& Answer1, FString& Feedback1, FString& NextQuestion1, FString& AnswerID2, FString& Answer2, FString& Feedback2, FString& NextQuestion2, FString& AnswerID3, FString& Answer3, FString& Feedback3, FString& NextQuestion3)
{
	FString NextQuestionToProcess;
	if (Button1 == "b1") {
		NextQuestionToProcess = NextQuestion1;
	}
	else if (Button2 == "b2") {
		NextQuestionToProcess = NextQuestion2;
	}
	else if (Button3 == "b3") {
		NextQuestionToProcess = NextQuestion3;
	}
	else {
		NextQuestionToProcess = QuestionID;
	}
	for (int32 i = 0; i < ProcessedQuestions.Num(); i++) {
		if (ProcessedQuestions[i].id == NextQuestionToProcess) {
			Question = ProcessedQuestions[i].question;
			AnexedFile = ProcessedQuestions[i].anexedFile;
			videoLink = ProcessedQuestions[i].videoLink;
			AnswerID1 = ProcessedQuestions[i].answerID1;
			Answer1 = ProcessedQuestions[i].answer1;
			Feedback1 = ProcessedQuestions[i].feedback1;
			NextQuestion1 = ProcessedQuestions[i].nextQuestion1;
			AnswerID2 = ProcessedQuestions[i].answerID2;
			Answer2 = ProcessedQuestions[i].answer2;
			Feedback2 = ProcessedQuestions[i].feedback2;
			NextQuestion2 = ProcessedQuestions[i].nextQuestion2;
			AnswerID3 = ProcessedQuestions[i].answerID3;
			Answer3 = ProcessedQuestions[i].answer3;
			Feedback3 = ProcessedQuestions[i].feedback3;
			NextQuestion3 = ProcessedQuestions[i].nextQuestion3;
		}
	}
}

bool UGameDataProcessing::ProcessURL(FString URL)
{
	if (URL == "nothing") {
		return true;
	}

	return false;
}

bool UGameDataProcessing::ProcessEndGame(FString EndCondition)
{
	if (EndCondition == "0") {
		return true;
	}
	return false;
}

FString UGameDataProcessing::ProcessNextQuestion(FString NextQuestion)
{

	return NextQuestion;
}

TArray<FActivity> UGameDataProcessing::ProcessActivityString(FString ActivityString)
{
	TArray<FString> Out;
	TArray<FActivity> ActivityList;
	GLog->Log(ActivityString);
	ActivityString.ParseIntoArray(Out, TEXT("*"), true);

	for (int32 i = 0; i < Out.Num() - 1; i++) {
		TArray<FString> Temp;
		Out[i].ParseIntoArray(Temp, TEXT(";"), true);
		FActivity ActTemp;
		ActTemp.id = FCString::Atoi(*Temp[0]);
		ActTemp.activityName = Temp[1];
		ActTemp.firstQuestionID = Temp[2];
		ActTemp.json = Temp[3];
		ActivityList.Add(ActTemp);
	}

	return ActivityList;
}

TArray<FActivityResults> UGameDataProcessing::ProcessActivityResultsString(FString ActivityResults)
{
	TArray<FActivityResults> Results;

	TArray<FString> Out;

	ActivityResults.ParseIntoArray(Out, TEXT("*"), true);

	for (int32 i = 0; i < Out.Num() - 1; i++) {
		TArray<FString> Temp;
		Out[i].ParseIntoArray(Temp, TEXT("#"), true);
		FActivityResults ActTemp;
		ActTemp.studentID = Temp[0];
		ActTemp.userName = Temp[1];
		ActTemp.question = Temp[2];
		ActTemp.answer = Temp[3];
		Results.Add(ActTemp);
	}

	return Results;
}
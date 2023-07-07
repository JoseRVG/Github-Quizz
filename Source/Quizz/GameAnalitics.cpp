// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAnalitics.h"

void UGameAnalitics::GameAnalitcs(FString ActivityID, FString ActivityName, FString AnswerID)
{
	if (!ActivityID.IsEmpty()) {
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

		JsonObject->SetStringField(TEXT("Activity ID"), ActivityID);
		JsonObject->SetStringField(TEXT("Activity Name"), ActivityName);
		JsonObject->SetStringField(TEXT("Answer ID"), AnswerID);

		FString OutputString;

		TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);

		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();

		HttpRequest->SetVerb("POST");

		HttpRequest->SetHeader(TEXT("Content-Type"), "application/json");

		HttpRequest->SetURL(FString("http://localhost/server/submitGameData.php"));

		HttpRequest->SetContentAsString(OutputString);

		HttpRequest->ProcessRequest();
	}
	else
	{
		GLog->Log("Please Enter Name!!!!");
	}
}

void UGameAnalitics::StartAnalitcs(FString ActivityID)
{
	if (!ActivityID.IsEmpty()) {
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

		JsonObject->SetStringField(TEXT("Activity ID"), ActivityID);

		FString OutputString;

		TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);

		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();

		HttpRequest->SetVerb("POST");

		HttpRequest->SetHeader(TEXT("Content-Type"), "application/json");

		HttpRequest->SetURL(FString("http://localhost/server/submitGameStart.php"));

		HttpRequest->SetContentAsString(OutputString);

		HttpRequest->ProcessRequest();
	}
	else
	{
		GLog->Log("Please Enter Name!!!!");
	}
}
FString UGameAnalitics::GetAnswer(FString AnswerID1, FString AnswerID2, FString AnswerID3, FString Button)
{
	if (Button == "b1") {
		return AnswerID1;
	}
	else if (Button == "b2") {
		return AnswerID2;
	}
	else {
		return AnswerID3;
	}
}

void UGameAnalitics::ProcessAcitivityResults(TArray<FActivityResults> Results, FString UserName, FString UserID, TArray<FString>& Question, TArray<FString>& Answer)
{
	for (int32 i = 0; i < Results.Num(); i++)
	{
		if (Results[i].studentID == UserID) {
			if (Results[i].userName == UserName) {
				Question.Add(Results[i].question);
				Answer.Add(Results[i].answer);
			}
		}
	}
}
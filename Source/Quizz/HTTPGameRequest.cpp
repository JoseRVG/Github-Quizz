// Fill out your copyright notice in the Description page of Project Settings.


#include "HTTPGameRequest.h"

FString temp;

int32 UHTTPGameRequest::GameSend(FString Name, FString Age, FDataUser UserData, FString GameCode)
{
	if (!Name.IsEmpty()) {
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

		JsonObject->SetStringField(TEXT("User Name"), Name);
		JsonObject->SetStringField(TEXT("Group Age"), Age);
		JsonObject->SetStringField(TEXT("StudentID"), UserData.studentID);
		JsonObject->SetStringField(TEXT("ActivityID"), UserData.activityID);
		JsonObject->SetStringField(TEXT("GameCode"), GameCode);

		FString OutputString;

		TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);

		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();

		HttpRequest->SetVerb("POST");

		HttpRequest->SetHeader(TEXT("Content-Type"), "application/json");

		HttpRequest->SetURL(FString("http://localhost/server/submitUserData.php"));

		HttpRequest->SetContentAsString(OutputString);

		HttpRequest->OnProcessRequestComplete().BindLambda([](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
			if (bWasSuccessful)
			{
			}
			else
			{
				// Handle error here
			}
			});

		HttpRequest->ProcessRequest();
	}
	else
	{
		GLog->Log("Please Enter Name!!!!");
		return FCString::Atoi(*UserData.activityID);
	}
	return FCString::Atoi(*UserData.activityID);
}




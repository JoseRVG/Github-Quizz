// Fill out your copyright notice in the Description page of Project Settings.

#include "HTTPGameRequest.h"

FString temp;

int32 UHTTPGameRequest::GameSend(FString Name, FString Age, FUserData UserData)
{
	if (!Name.IsEmpty()) {
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

		JsonObject->SetStringField(TEXT("User Name"), Name);
		JsonObject->SetStringField(TEXT("Group Age"), Age);
		JsonObject->SetStringField(TEXT("IveniraID"), UserData.iveniraID);
		JsonObject->SetStringField(TEXT("ActivityID"), UserData.activityID);
		temp = UserData.activityID;

		FString OutputString;

		TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);

		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

		TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();

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

		double LastTime = FPlatformTime::Seconds();
		while (EHttpRequestStatus::Processing == HttpRequest->GetStatus()) {
			const double AppTime = FPlatformTime::Seconds();
			FHttpModule::Get().GetHttpManager().Tick(AppTime - LastTime);
			LastTime = AppTime;
			//FPlatformProcess::Sleep(0.1f);
		}
	}
	else
	{
		GLog->Log("Please Enter Name!!!!");
		return FCString::Atoi(*UserData.activityID);
	}
	return FCString::Atoi(*UserData.activityID);
}

FString UHTTPGameRequest::GameReciveAcitivity()
{
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();

	HttpRequest->SetURL(FString("http://localhost/server/retrieve.php"));

	HttpRequest->SetVerb("GET");

	HttpRequest->ProcessRequest();

	HttpRequest->OnProcessRequestComplete().BindLambda([](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
		if (bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

			FString OutputString;

			TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);

			FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

			GLog->Log("Hey we received the following response!");
		}
		else
		{
			// Handle error here
		}
	});
	
	double LastTime = FPlatformTime::Seconds();
	while (EHttpRequestStatus::Processing == HttpRequest->GetStatus()) {
		const double AppTime = FPlatformTime::Seconds();
		FHttpModule::Get().GetHttpManager().Tick(AppTime - LastTime);
		LastTime = AppTime;
		//FPlatformProcess::Sleep(0.1f);
	}
		
	FHttpResponsePtr Responses = HttpRequest->GetResponse();

	return Responses->GetContentAsString();
}

FString UHTTPGameRequest::GameAcitivityResults()
{
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();

	HttpRequest->OnProcessRequestComplete().BindLambda([](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
		if (bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

			FString OutputString;

			TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);

			FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

		}
		else
		{
			// Handle error here
		}
	});

	HttpRequest->SetURL(FString("http://localhost/server/gameResults.php"));

	HttpRequest->SetVerb("GET");

	HttpRequest->ProcessRequest();

	double LastTime = FPlatformTime::Seconds();
	while (EHttpRequestStatus::Processing == HttpRequest->GetStatus()) {
		const double AppTime = FPlatformTime::Seconds();
		FHttpModule::Get().GetHttpManager().Tick(AppTime - LastTime);
		LastTime = AppTime;
		//FPlatformProcess::Sleep(0.1f);
	}

	FHttpResponsePtr Responses = HttpRequest->GetResponse();

	return Responses->GetContentAsString();
}

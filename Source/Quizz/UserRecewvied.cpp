// Fill out your copyright notice in the Description page of Project Settings.

#include "UserRecewvied.h"

FUserData UserData;
void UUserRecewvied::ReceivedUserData(FUserData &User, FString &IveniraID)
{

	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();

	HttpRequest->OnProcessRequestComplete().BindLambda([](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
		if (bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

			FString OutputString;

			TArray<FString> Out;

			TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);

			FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

			Response->GetContentAsString().ParseIntoArray(Out, TEXT(";"), true);
			UserData.iveniraID = Out[0];
			UserData.activityID = Out[1];
		}
		else
		{

		}
		{
			// Handle error here
		}
	});

	HttpRequest->SetURL(FString("http://localhost/server/invenira.php"));

	HttpRequest->SetVerb("GET");

	HttpRequest->ProcessRequest();

	double LastTime = FPlatformTime::Seconds();
	while (EHttpRequestStatus::Processing == HttpRequest->GetStatus()) {
		const double AppTime = FPlatformTime::Seconds();
		FHttpModule::Get().GetHttpManager().Tick(AppTime - LastTime);
		LastTime = AppTime;
		//FPlatformProcess::Sleep(0.1f);
	}

	IveniraID = UserData.iveniraID;

	User = UserData;
}

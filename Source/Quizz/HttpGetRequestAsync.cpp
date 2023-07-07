// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpGetRequestAsync.h"

void UHttpGetRequestAsync::Activate()
{
	// Create HTTP Request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetURL(URL);

	// Setup Async response
	HttpRequest->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
		{
			FString ResponseString = "";
			if (bSuccess)
			{
				ResponseString = Response->GetContentAsString();
			}

			this->HandleRequestCompleted(ResponseString, bSuccess);
		});

	// Handle actual request
	HttpRequest->ProcessRequest();
}


void UHttpGetRequestAsync::HandleRequestCompleted(FString ResponseString, bool bSuccess)
{
	FString OutString;
	if (bSuccess)
	{
		OutString = ResponseString;
		GLog->Log("Response Recieved!!!");
	}
	else
	{
		// While response may be successful, we failed to retrieve the string field
		bSuccess = false;
	}


	Completed.Broadcast(OutString, bSuccess);
}


UHttpGetRequestAsync* UHttpGetRequestAsync::AsyncRequestHTTP(UObject* WorldContextObject, FString URL)
{
	// Create Action Instance for Blueprint System
	UHttpGetRequestAsync* Action = NewObject<UHttpGetRequestAsync>();
	Action->URL = URL;
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "UserRecewvied.h"

FDataUser UserData;
void UUserRecewvied::ReceivedUserData(int32 ResponseAct, FString ResponseUser, FDataUser& User, FString& StudentID)
{
	UserData.studentID = ResponseUser;
	UserData.activityID = FString::FromInt(ResponseAct);

	StudentID = UserData.studentID;

	User = UserData;
}

bool UUserRecewvied::SendGameCode(FString Code, TArray<FString> DBCode, FString& User, int32& ActivityID, FString& GameCode)
{
	
	for (int32 i = 0; i < DBCode.Num()-1; i++) {
		TArray<FString> Out;
		DBCode[i].ParseIntoArray(Out, TEXT(";"), true);
		if (Out[2] == Code) {
			User = Out[0];
			ActivityID = FCString::Atoi(*Out[1]);
			GameCode = Out[2];
			return true;
		}
		Out.Empty();
	}
	return false;
}
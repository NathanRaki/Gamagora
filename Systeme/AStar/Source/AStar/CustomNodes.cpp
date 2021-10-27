// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomNodes.h"

void UCustomNodes::FileLoadString(FString FileName, FString& SaveText)
{
	FFileHelper::LoadFileToString(SaveText, *FileName);
}
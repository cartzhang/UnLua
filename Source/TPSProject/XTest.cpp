// Fill out your copyright notice in the Description page of Project Settings.


#include "XTest.h"

// Sets default values
AXTest::AXTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AXTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AXTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString AXTest::GetModuleName() const
{
	FString ObjectPath = GetClass()->GetPathName();	
	FString TmpClassName =  GetClass()->GetName();
#if WITH_EDITOR
	FString StrTest2 = GetClass()->GetOuter()->GetName();
	//UE_LOG(LogTemp, Log, TEXT("test module  1111 name %s"), *TmpClassName);
	//UE_LOG(LogTemp, Log, TEXT("test module  222 name %s"), *StrTest2);
#endif
	// ignore "/Game/"
	ObjectPath = ObjectPath.RightChop(6);
	int LastIndex = -1;
	if (ObjectPath.FindLastChar('/', LastIndex))
	{
		ObjectPath = ObjectPath.Left(LastIndex + 1);
	}
	ObjectPath += TmpClassName;
	ObjectPath = ObjectPath.Replace(TEXT("/"), TEXT("."));
#if WITH_EDITOR
	//UE_LOG(LogTemp, Log, TEXT("test module name %s"), *ObjectPath);
#endif
	return ObjectPath;
}

FString AXTest::GetModuleName_Implementation() const
{
	return GetModuleName();
}


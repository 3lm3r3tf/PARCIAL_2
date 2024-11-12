// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrilFactory.h"
#include "Viscoso.generated.h"

UCLASS()
class DONKEYKONG_L02_API AViscoso : public AActor, public IBarrilFactory
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AViscoso();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	virtual AActor* CrearBarril(UWorld* World) override;
	void Rodar();
};

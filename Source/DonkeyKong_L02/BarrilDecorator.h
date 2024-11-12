// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrilInterface.h"
#include "BarrilDecorator.generated.h"

UCLASS()
class DONKEYKONG_L02_API ABarrilDecorator : public AActor, public IBarrilInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrilDecorator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	void SetBarril(IBarrilInterface* NewBarril);
	virtual AActor* CrearBarril(UWorld* World) override;
	virtual void Rodar() override;
protected:
	IBarrilInterface* Barril;

};

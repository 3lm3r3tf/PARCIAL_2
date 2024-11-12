// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BarrilDecorator.h"
#include "BarrilFuegoQuemaDecorator.generated.h"

UCLASS()
class DONKEYKONG_L02_API ABarrilFuegoQuemaDecorator : public ABarrilDecorator
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrilFuegoQuemaDecorator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	virtual void Rodar() override;
};
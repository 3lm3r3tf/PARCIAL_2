// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrilPiedraInterface.h"
#include "BarrilPiedra.generated.h"

UCLASS()
class DONKEYKONG_L02_API ABarrilPiedra : public AActor, public IBarrilPiedraInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrilPiedra();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	virtual void RodarPiedra() override;

};

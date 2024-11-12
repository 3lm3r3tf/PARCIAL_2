// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrilInterface.h"
#include "BarrilPiedra.h"
#include "AdapterBarrilPiedra.generated.h"

UCLASS()
class DONKEYKONG_L02_API AAdapterBarrilPiedra : public AActor, public IBarrilInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAdapterBarrilPiedra();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	ABarrilPiedra* BarrilPiedra;
public:
	virtual AActor* CrearBarril(UWorld* World) override;
	virtual void Rodar() override;
	void SetBarrilPiedra(ABarrilPiedra* Nuevo);
};

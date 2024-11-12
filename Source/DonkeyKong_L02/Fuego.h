// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrilFactory.h"
#include "BarrilInterface.h"
#include "Fuego.generated.h"

UCLASS()
class DONKEYKONG_L02_API AFuego : public AActor, public IBarrilFactory, public IBarrilInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFuego();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	virtual AActor* CrearBarril(UWorld* World) override;
	virtual void Rodar() override;

};

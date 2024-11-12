// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrilDecorator.h"
#include "Engine/World.h" 
#include "Engine/Engine.h"

// Sets default values
ABarrilDecorator::ABarrilDecorator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABarrilDecorator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrilDecorator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrilDecorator::SetBarril(IBarrilInterface* NewBarril)
{
	Barril = NewBarril;
}

AActor* ABarrilDecorator::CrearBarril(UWorld* World)
{
	if (Barril)
	{
		return Barril->CrearBarril(World);
	}
	return nullptr;
}

void ABarrilDecorator::Rodar()
{
	if (Barril)
	{
		Barril->Rodar();
	}
	GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Magenta, TEXT("Funcionalidades Adicionales del decorador del Fuego"));
}


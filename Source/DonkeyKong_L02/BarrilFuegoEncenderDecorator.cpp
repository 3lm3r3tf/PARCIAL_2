// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrilFuegoEncenderDecorator.h"
#include "Engine/Engine.h"

// Sets default values
ABarrilFuegoEncenderDecorator::ABarrilFuegoEncenderDecorator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABarrilFuegoEncenderDecorator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrilFuegoEncenderDecorator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrilFuegoEncenderDecorator::Rodar()
{
	Super::Rodar();
	GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, TEXT("¡El barril de fuego encenderá todo a su paso...BarrilFuegoEncenderDecorator"));
}


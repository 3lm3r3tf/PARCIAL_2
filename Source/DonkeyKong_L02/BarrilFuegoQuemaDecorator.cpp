// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrilFuegoQuemaDecorator.h"

// Sets default values
ABarrilFuegoQuemaDecorator::ABarrilFuegoQuemaDecorator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABarrilFuegoQuemaDecorator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrilFuegoQuemaDecorator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrilFuegoQuemaDecorator::Rodar()
{
	Super::Rodar();
	GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, TEXT("¡El barril de fuego quema todo a su paso!...BarrilFuegoQuemaDecorator"));
}


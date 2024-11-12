// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrilPiedra.h"
#include "Engine/Engine.h"

// Sets default values
ABarrilPiedra::ABarrilPiedra()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABarrilPiedra::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrilPiedra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrilPiedra::RodarPiedra()
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("El barril de piedra está rodando"));
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Hielo.h"
#include "Engine/Engine.h"

// Sets default values
AHielo::AHielo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHielo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHielo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor* AHielo::CrearBarril(UWorld* World)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("El barril de hielo está rodando.")); 
	return this;
}

void AHielo::Rodar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("El barril de hielo está rodando y enfriando todo a su paso."));
}


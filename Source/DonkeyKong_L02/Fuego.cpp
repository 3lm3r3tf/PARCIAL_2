// Fill out your copyright notice in the Description page of Project Settings.


#include "Fuego.h"
#include "Engine/Engine.h"

// Sets default values
AFuego::AFuego()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFuego::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFuego::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor* AFuego::CrearBarril(UWorld* World)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("El barril de fuego rodando..............	."));
	return this;
}

void AFuego::Rodar()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("El barril de fuego está rodando y quemando todo a su paso."));
}


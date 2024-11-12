// Fill out your copyright notice in the Description page of Project Settings.


#include "AdapterBarrilPiedra.h"

// Sets default values
AAdapterBarrilPiedra::AAdapterBarrilPiedra()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAdapterBarrilPiedra::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAdapterBarrilPiedra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor* AAdapterBarrilPiedra::CrearBarril(UWorld* World)
{
	//crear intancia
	return GetWorld()->SpawnActor<ABarrilPiedra>(ABarrilPiedra::StaticClass());
}

void AAdapterBarrilPiedra::Rodar()
{
	if (BarrilPiedra) {
		BarrilPiedra->RodarPiedra();
	}
}

void AAdapterBarrilPiedra::SetBarrilPiedra(ABarrilPiedra* Nuevo)
{
	BarrilPiedra = Nuevo;
}


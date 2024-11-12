// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrilFacade.h"

// Sets default values
ABarrilFacade::ABarrilFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABarrilFacade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrilFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor* ABarrilFacade::CrearFuego()
{
	AFuego* Barril = GetWorld()->SpawnActor<AFuego>(AFuego::StaticClass()); 
	return Barril;
}

AActor* ABarrilFacade::CrearHielo()
{
	AHielo* Barril = GetWorld()->SpawnActor<AHielo>(AHielo::StaticClass()); 
	return Barril;
}

AActor* ABarrilFacade::CrearViscoso()
{
	AViscoso* Barril = GetWorld()->SpawnActor<AViscoso>(AViscoso::StaticClass()); 
	return Barril;
}


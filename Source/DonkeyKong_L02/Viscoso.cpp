// Fill out your copyright notice in the Description page of Project Settings.


#include "Viscoso.h"
#include "Engine/Engine.h"

// Sets default values
AViscoso::AViscoso()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AViscoso::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AViscoso::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor* AViscoso::CrearBarril(UWorld* World)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Magenta, TEXT("El barril viscoso está rodando."));
	return this;
		
}

void AViscoso::Rodar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Magenta, TEXT("El barril viscoso está rodando y pegajoso todo a su paso."));
}


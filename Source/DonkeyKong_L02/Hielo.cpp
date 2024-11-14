// Fill out your copyright notice in the Description page of Project Settings.


#include "Hielo.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AHielo::AHielo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Crear el componente de malla estática y adjuntarlo al root
	BarrilMeshHielo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BarrilMesh"));
	RootComponent = BarrilMeshHielo;

	// Buscar una malla predeterminada para el barril (opcional, si deseas asignarla aquí)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarrilVisualAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	if (BarrilVisualAsset.Succeeded())
	{
		BarrilMeshHielo->SetStaticMesh(BarrilVisualAsset.Object);
	}
	//aprica la fisica al barril
	BarrilMeshHielo->SetSimulatePhysics(true);
	BarrilMeshHielo->SetMassOverrideInKg(NAME_None, 15050.0f); // Ajustar la masa si es necesario
	//rotar
	BarrilMeshHielo->SetWorldRotation(FRotator(90.0f, 0.0f, 0.0f));
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


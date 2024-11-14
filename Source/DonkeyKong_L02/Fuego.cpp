// Fill out your copyright notice in the Description page of Project Settings.


#include "Fuego.h"
#include "Engine/Engine.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
AFuego::AFuego()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Crear el componente de malla estática y adjuntarlo al root
	BarrilMeshFuego = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BarrilMesh"));
	RootComponent = BarrilMeshFuego;

	// Buscar una malla predeterminada para el barril (opcional, si deseas asignarla aquí)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarrilVisualAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (BarrilVisualAsset.Succeeded())
	{
		BarrilMeshFuego->SetStaticMesh(BarrilVisualAsset.Object);
	}
	//aprica la fisica al barril
	BarrilMeshFuego->SetSimulatePhysics(true);
	BarrilMeshFuego->SetMassOverrideInKg(NAME_None, 15050.0f); // Ajustar la masa si es necesario
	//rotar
	BarrilMeshFuego->SetWorldRotation(FRotator(90.0f, 0.0f, 0.0f));
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


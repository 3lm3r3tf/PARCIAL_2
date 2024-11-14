// Fill out your copyright notice in the Description page of Project Settings.


#include "Viscoso.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AViscoso::AViscoso()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Crear el componente de malla estática y adjuntarlo al root
	BarrilMeshViscoso = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BarrilMesh"));
	RootComponent = BarrilMeshViscoso;

	// Buscar una malla predeterminada para el barril (opcional, si deseas asignarla aquí)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarrilVisualAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	if (BarrilVisualAsset.Succeeded())
	{
		BarrilMeshViscoso->SetStaticMesh(BarrilVisualAsset.Object);
	}
	//aprica la fisica al barril
	BarrilMeshViscoso->SetSimulatePhysics(true);
	BarrilMeshViscoso->SetMassOverrideInKg(NAME_None, 15050.0f); // Ajustar la masa si es necesario
	BarrilMeshViscoso->SetWorldRotation(FRotator(90.0f, 0.0f, 0.0f));
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


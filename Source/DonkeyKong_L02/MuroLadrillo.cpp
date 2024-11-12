// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroLadrillo.h"
#include "UObject/ConstructorHelpers.h"


AMuroLadrillo::AMuroLadrillo()
{
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A'"));
	MuroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMesh"));
	MuroMesh->SetStaticMesh(MeshAsset.Object);
	RootComponent = MuroMesh;
	// agregar un malla 
}

void AMuroLadrillo::ChocarPared()
{
	//UE_LOG(LogTemp, Warning, TEXT("Chocaste con un muro de ladrillo!"));
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Chocaste con un muro ladrillo!"));

}

void AMuroLadrillo::BeginPlay()
{
	Super::BeginPlay();
}

void AMuroLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

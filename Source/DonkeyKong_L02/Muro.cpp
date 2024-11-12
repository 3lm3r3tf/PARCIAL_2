// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro.h"

// Sets default values
AMuro::AMuro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A'"));
	MuroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMesh"));
	RootComponent = MuroMesh;*/
}

// Called when the game starts or when spawned
void AMuro::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMuro::ChocarPared()
{
	//UE_LOG(LogTemp, Warning, TEXT("Chocaste con un muro!"));
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Chocaste con un muro!"));
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrilFacade.h"
#include "AdapterBarrilPiedra.h" //Incluye el Adapter
#include "BarrilManager.generated.h"

UCLASS()
class DONKEYKONG_L02_API ABarrilManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrilManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	//Crean una Instancia  de BarrilFacade
	ABarrilFacade* BarrilFacade;
	//Llamar a la función de la clase BarrilFacade
	void LlamarFuncionesBarrilFacade();
	void RodarFuego();
	void RodarHielo();
	void RodarViscoso();
	void RodarBarrilDecorado(IBarrilInterface* Barril);

//creando un metodo privado para usar adapter 
private:
	void ConfigurarAdapter();
};

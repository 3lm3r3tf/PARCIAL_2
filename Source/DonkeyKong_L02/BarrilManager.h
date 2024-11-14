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
	UFUNCTION(BlueprintCallable, Category = "Barriles")
	void LlamarFuncionesBarrilFacade();
	void RodarFuego();
	void RodarHielo();
	void RodarViscoso();
	void RodarBarrilDecorado(IBarrilInterface* Barril);

//creando un metodo privado para usar adapter 
private:
	void ConfigurarAdapter();


private:
	// En ABarrilManager.h
	TArray<AActor*> BarrilesFuego;       // Array para barriles de fuego
	TArray<AActor*> BarrilesHielo;       // Array para barriles de hielo
	TArray<AActor*> BarrilesViscoso;     // Array para barriles viscosos

	TArray<AActor*> BarrilesTotales;	 // Array para todos los barriles
private:
	// Variables para el número de barriles de cada tipo
	int32 BarrilesFuegoRestantes = 4;
	int32 BarrilesHieloRestantes = 5;
	int32 BarrilesViscosoRestantes = 4;

	// Temporizadores para bajar barriles de cada tipo
	FTimerHandle TimerHandleFuego;
	FTimerHandle TimerHandleHielo;
	FTimerHandle TimerHandleViscoso;

	// Funciones para spawnar barriles individuales con temporizador
	void SpawnBarrilFuego();
	void SpawnBarrilHielo();
	void SpawnBarrilViscoso();
};

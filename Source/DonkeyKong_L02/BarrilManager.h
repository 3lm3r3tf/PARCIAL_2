#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrilFacade.h"
#include "AdapterBarrilPiedra.h"
#include "BarrilFuegoEncenderDecorator.h"
#include "BarrilFuegoExplotaDecorator.h"
#include "BarrilFuegoQuemaDecorator.h"
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

    // Crear una Instancia de BarrilFacade
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Barriles")
    ABarrilFacade* BarrilFacade;

    // Llamar a la función de la clase BarrilFacade
    UFUNCTION(BlueprintCallable, Category = "Barriles")
    void LlamarFuncionesBarrilFacade();
    void RodarFuego();
    void RodarHielo();
    void RodarViscoso();
    void RodarBarrilDecorado(IBarrilInterface* Barril);

    // Método para aplicar decoradores a los barriles
    void AplicarDecoradores(AActor* BarrilFuego);

private:
    // Método para configurar el Adapter
    void ConfigurarAdapter();

    // Arrays para almacenar diferentes tipos de barriles
    TArray<AActor*> BarrilesFuego;
    TArray<AActor*> BarrilesHielo;
    TArray<AActor*> BarrilesViscoso;
    TArray<AActor*> BarrilesTotales;

    // Variables para el número de barriles de cada tipo
    int32 BarrilesFuegoRestantes = 4;
    int32 BarrilesHieloRestantes = 5;
    int32 BarrilesViscosoRestantes = 4;

    // Temporizadores para bajar barriles de cada tipo
    FTimerHandle TimerHandleFuego;
    FTimerHandle TimerHandleHielo;
    FTimerHandle TimerHandleViscoso;

    // Temporizadores para aplicar decoradores
    FTimerHandle TimerHandleDecoradorEncender;
    FTimerHandle TimerHandleDecoradorExplota;
    FTimerHandle TimerHandleDecoradorQuema;

    // Funciones para spawnar barriles individuales con temporizador
    void SpawnBarrilFuego();
    void SpawnBarrilHielo();
    void SpawnBarrilViscoso();

    // Funciones para aplicar decoradores a intervalos de tiempo
    void AplicarDecoradorEncender();
    void AplicarDecoradorExplota();
    void AplicarDecoradorQuema();

	// Funciones decoradores aleatorios
	void AplicarDecoradorAleatorio();
    
    
    // TMap para almacenar barriles de hielo con llaves únicas correlativas
	TMap<int32, AActor*> MapHielo;

   // int32 BarrilesHieloRestantes = 5; 
    int32 ContadorUnicoHielo = 0;
};

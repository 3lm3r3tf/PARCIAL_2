// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrilManager.h"
#include "Engine/World.h"
//#include "Engine/World.h" 
#include "TimerManager.h"
#include "Fuego.h"
#include "Hielo.h"
#include "Viscoso.h"
#include "BarrilDecorator.h"
#include "BarrilFuegoExplotaDecorator.h"
#include "BarrilFuegoEncenderDecorator.h"
#include "BarrilFuegoQuemaDecorator.h"


//#include "TimerManager.h"

// Sets default values
ABarrilManager::ABarrilManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ABarrilManager::BeginPlay()
{
	Super::BeginPlay();
	//Crean una Instancia  de BarrilFacade
	BarrilFacade = GetWorld()->SpawnActor<ABarrilFacade>(ABarrilFacade::StaticClass());
	//Llamar a la función de la clase BarrilFacade
	//LlamarFuncionesBarrilFacade();
	//llamar al metodo privado para usar el adapter
	ConfigurarAdapter();
	// Configura los temporizadores para generar barriles uno por uno
	GetWorldTimerManager().SetTimer(TimerHandleFuego, this, &ABarrilManager::SpawnBarrilFuego, 2.0f, true);
	GetWorldTimerManager().SetTimer(TimerHandleHielo, this, &ABarrilManager::SpawnBarrilHielo, 3.0f, true);
	GetWorldTimerManager().SetTimer(TimerHandleViscoso, this, &ABarrilManager::SpawnBarrilViscoso, 4.0f, true);

	// Configurar los temporizadores para aplicar decoradores 
	GetWorldTimerManager().SetTimer(TimerHandleDecoradorEncender, this, &ABarrilManager::AplicarDecoradorEncender, 5.0f, true); 
	GetWorldTimerManager().SetTimer(TimerHandleDecoradorExplota, this, &ABarrilManager::AplicarDecoradorExplota, 10.0f, true); 
	GetWorldTimerManager().SetTimer(TimerHandleDecoradorQuema, this, &ABarrilManager::AplicarDecoradorQuema, 15.0f, true);

}

// Called every frame
void ABarrilManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrilManager::LlamarFuncionesBarrilFacade()
{
	
}

void ABarrilManager::RodarFuego()
{
	if (BarrilFacade) {
		AFuego* BarrilFuegoCasteado = Cast<AFuego>(BarrilFacade->CrearFuego());
		if (BarrilFuegoCasteado) {
			BarrilFuegoCasteado->Rodar();
		}
	}
}

void ABarrilManager::RodarHielo()
{
	if (BarrilFacade) {
		AHielo* BarrilHieloCasteado = Cast<AHielo>(BarrilFacade->CrearHielo());
		if (BarrilHieloCasteado) {
			BarrilHieloCasteado->Rodar();
		}
	}
}

void ABarrilManager::RodarViscoso()
{
	if (BarrilFacade) {
		AViscoso* BarrilViscosoCasteado = Cast<AViscoso>(BarrilFacade->CrearViscoso());
		if (BarrilViscosoCasteado) {
			BarrilViscosoCasteado->Rodar();
		}
	}
}

void ABarrilManager::RodarBarrilDecorado(IBarrilInterface* Barril)
{
	if (Barril) {
		Barril->Rodar();
	}
}

void ABarrilManager::AplicarDecoradores(AActor* BarrilFuego)
{
}

void ABarrilManager::ConfigurarAdapter()
{
	//crear una instancia del adapter 
	AAdapterBarrilPiedra* Adapter = GetWorld()->SpawnActor<AAdapterBarrilPiedra>(AAdapterBarrilPiedra::StaticClass());
	//crear barril usando el adapter
	AActor* BarrilPiedraActor = Adapter->CrearBarril(GetWorld());
	//configurar el adapter con la nueva instancia de barril de piedra
	Adapter->SetBarrilPiedra(Cast<ABarrilPiedra>(BarrilPiedraActor));
	//Usar el adapter para rodar el barril de piedra
	Adapter->Rodar();
}

void ABarrilManager::SpawnBarrilFuego()
{
	if (BarrilFacade)
	{
		AActor* BarrilFuego = BarrilFacade->CrearFuego();
		if (BarrilFuego)
		{
			BarrilFuego->SetActorLocation(FVector(1160.f, 1200.f, 2400.f));
			BarrilesFuego.Add(BarrilFuego);

			//BarrilesTotales.Add(BarrilFuego);

			// Muestra mensaje de debug
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Barril de Fuego Creado!"));

			// Configura un temporizador para destruir el barril después de 10 segundos
			FTimerHandle DestroyTimer;
			GetWorldTimerManager().SetTimer(DestroyTimer, [BarrilFuego]()
				{
					if (BarrilFuego && !BarrilFuego->IsPendingKill())
					{
						BarrilFuego->Destroy();
					}
				}, 5.0f, false); // 10 segundos de vida
		}
	}
}

void ABarrilManager::SpawnBarrilHielo()
{
	if (BarrilFacade)
	{
		AActor* BarrilHielo = BarrilFacade->CrearHielo();
		if (BarrilHielo)
		{
			BarrilHielo->SetActorLocation(FVector(1190.f, -100.f, 1640.f));
			MapHielo.Add(ContadorUnicoHielo++, BarrilHielo);

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Barril de Hielo Creado con  MpaHielo!"));

			// Configura un temporizador para destruir el barril después de 5 segundos
			FTimerHandle DestroyTimer;
			GetWorldTimerManager().SetTimer(DestroyTimer, [BarrilHielo]()
				{
					if (BarrilHielo && !BarrilHielo->IsPendingKill())
					{
						BarrilHielo->Destroy();
					}
				}, 5.0f, false); // 5 segundos de vida
		}
	}
}


void ABarrilManager::SpawnBarrilViscoso()
{
	if (BarrilFacade)
	{
		AActor* BarrilViscoso = BarrilFacade->CrearViscoso();
		if (BarrilViscoso)
		{
			BarrilViscoso->SetActorLocation(FVector(1190.f, -900.f, 1640.f));
			BarrilesViscoso.Add(BarrilViscoso);
			//BarrilesTotales.Add(BarrilViscoso);

			// Muestra mensaje de debug
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, TEXT("Barril Viscoso Creado!"));

			// Configura un temporizador para destruir el barril después de 10 segundos
			FTimerHandle DestroyTimer;
			GetWorldTimerManager().SetTimer(DestroyTimer, [BarrilViscoso]()
				{
					if (BarrilViscoso && !BarrilViscoso->IsPendingKill())
					{
						BarrilViscoso->Destroy();
					}
				}, 5.0f, false); // 10 segundos de vida
		}
	}
}

void ABarrilManager::AplicarDecoradorEncender()
{
	if (BarrilesFuego.Num() > 0)
	{
		// Selecciona un barril de fuego aleatorio
		int32 Index = FMath::RandRange(0, BarrilesFuego.Num() - 1);
		AActor* BarrilFuego = BarrilesFuego[Index];
		if (BarrilFuego)
		{
			// Crea un decorador de encender
			ABarrilFuegoEncenderDecorator* DecoradorEncender = GetWorld()->SpawnActor<ABarrilFuegoEncenderDecorator>(ABarrilFuegoEncenderDecorator::StaticClass());
			if (DecoradorEncender)
			{
				// Configura el decorador con el barril de fuego
				DecoradorEncender->SetBarril(Cast<IBarrilInterface>(BarrilFuego));
				// Aplica el decorador
				DecoradorEncender->Rodar();
			}
		}
	}

}

void ABarrilManager::AplicarDecoradorExplota()
{	
	if (BarrilesFuego.Num() > 0)
	{
		// Selecciona un barril de fuego aleatorio
		int32 Index = FMath::RandRange(0, BarrilesFuego.Num() - 1);
		AActor* BarrilFuego = BarrilesFuego[Index];
		if (BarrilFuego)
		{
			// Crea un decorador de explota
			ABarrilFuegoExplotaDecorator* DecoradorExplota = GetWorld()->SpawnActor<ABarrilFuegoExplotaDecorator>(ABarrilFuegoExplotaDecorator::StaticClass());
			if (DecoradorExplota)
			{
				// Configura el decorador con el barril de fuego
				DecoradorExplota->SetBarril(Cast<IBarrilInterface>(BarrilFuego));
				// Aplica el decorador
				DecoradorExplota->Rodar();
			}
		}
	}
}

void ABarrilManager::AplicarDecoradorQuema()
{
	if (BarrilesFuego.Num() > 0)
	{
		// Selecciona un barril de fuego aleatorio
		int32 Index = FMath::RandRange(0, BarrilesFuego.Num() - 1);
		AActor* BarrilFuego = BarrilesFuego[Index];
		if (BarrilFuego)
		{
			// Crea un decorador de quema
			ABarrilFuegoQuemaDecorator* DecoradorQuema = GetWorld()->SpawnActor<ABarrilFuegoQuemaDecorator>(ABarrilFuegoQuemaDecorator::StaticClass());
			if (DecoradorQuema)
			{
				// Configura el decorador con el barril de fuego
				DecoradorQuema->SetBarril(Cast<IBarrilInterface>(BarrilFuego));
				// Aplica el decorador
				DecoradorQuema->Rodar();
			}
		}
	}

}

void ABarrilManager::AplicarDecoradorAleatorio()
{


}


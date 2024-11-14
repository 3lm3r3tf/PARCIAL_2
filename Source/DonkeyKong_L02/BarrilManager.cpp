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
	
}

// Called every frame
void ABarrilManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrilManager::LlamarFuncionesBarrilFacade()
{
	//if (BarrilFacade) {
	//	//crear  10 barriles de fuego

	//	AActor* BarrilFuego = BarrilFacade->CrearFuego();
	//	if(BarrilFuego){
	//		//mensaje en pantalla
	//		BarrilFuego->SetActorLocation(FVector(1190.f, -600.f, 640.f));
	//		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Barril de Fuego Creado!"));
	//		//Crear y configurar  los diferentes decoradores
	//		ABarrilFuegoExplotaDecorator* DecoradorExplota = GetWorld()->SpawnActor<ABarrilFuegoExplotaDecorator>(ABarrilFuegoExplotaDecorator::StaticClass());
	//		ABarrilFuegoEncenderDecorator* DecoradorEncender = GetWorld()->SpawnActor<ABarrilFuegoEncenderDecorator>(ABarrilFuegoEncenderDecorator::StaticClass());
	//		ABarrilFuegoQuemaDecorator* DecoradorQuema = GetWorld()->SpawnActor<ABarrilFuegoQuemaDecorator>(ABarrilFuegoQuemaDecorator::StaticClass());
	//		//Decorar el Barril de Fuego
	//		if (DecoradorExplota) {
	//			DecoradorExplota->SetBarril(Cast<IBarrilInterface>(BarrilFuego));
	//			DecoradorExplota->Rodar();
	//		}
	//		if (DecoradorEncender) {
	//			DecoradorEncender->SetBarril(Cast<IBarrilInterface>(BarrilFuego));
	//			DecoradorEncender->Rodar();
	//		}
	//		if (DecoradorQuema) {
	//			DecoradorQuema->SetBarril(Cast<IBarrilInterface>(BarrilFuego));
	//			DecoradorQuema->Rodar();
	//		}
	//		GEngine->AddOnScreenDebugMessage(-1, 25.f, FColor::Yellow, TEXT("llamando en una solo funcionalidad............"));
	//		if (DecoradorExplota && DecoradorEncender && DecoradorQuema) { 
	//			// Opciones de encadenamiento // Ejemplo 1: Explota -> Encender -> Quema 
	//			DecoradorExplota->SetBarril(Cast<IBarrilInterface>(BarrilFuego)); 
	//			DecoradorEncender->SetBarril(DecoradorExplota); 
	//			DecoradorQuema->SetBarril(DecoradorEncender); 
	//			DecoradorQuema->Rodar(); 
	//			 //Ejemplo 2: Quema -> Encender -> Explota (descomentar para usar) 
	//		/*	DecoradorQuema->SetBarril(Cast<IBarrilInterface>(BarrilFuego)); 
	//			DecoradorEncender->SetBarril(DecoradorQuema); 
	//			DecoradorExplota->SetBarril(DecoradorEncender);
	//			DecoradorExplota->Rodar(); */
	//			// Ejemplo 3: Encender -> Quema -> Explota (descomentar para usar) 
	//		/*	DecoradorEncender->SetBarril(Cast<IBarrilInterface>(BarrilFuego)); 
	//			DecoradorQuema->SetBarril(DecoradorEncender); 
	//			DecoradorExplota->SetBarril(DecoradorQuema);
	//			DecoradorExplota->Rodar(); */
	//			
	//		}
	//	}
	//	AActor* BarrilHielo = BarrilFacade->CrearHielo();
	//	if (BarrilHielo) {
	//		//mensaje en pantalla
	//		BarrilHielo->SetActorLocation(FVector(1190.f, -700.f, 640.f));
	//		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("Barril de Hielo Creado! "));
	//		//configurar temporizador para RodarHielo
	//		GetWorldTimerManager().SetTimerForNextTick(this, &ABarrilManager::RodarHielo);
	//	}

	//	AActor* BarrilViscoso = BarrilFacade->CrearViscoso();
	//	if (BarrilViscoso) {
	//		//mensaje en pantalla
	//		BarrilViscoso->SetActorLocation(FVector(1190.f, -800.f, 640.f));
	//		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Magenta, TEXT("Barril Viscoso Creado! "));
	//		//configurar temporizador para RodarViscoso
	//		GetWorldTimerManager().SetTimerForNextTick(this, &ABarrilManager::RodarViscoso);
	//	}
	//}

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
			BarrilesHielo.Add(BarrilHielo);
			//BarrilesTotales.Add(BarrilHielo);

			// Muestra mensaje de debug
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Barril de Hielo Creado!"));

			// Configura un temporizador para destruir el barril después de 10 segundos
			FTimerHandle DestroyTimer;
			GetWorldTimerManager().SetTimer(DestroyTimer, [BarrilHielo]()
				{
					if (BarrilHielo && !BarrilHielo->IsPendingKill())
					{
						BarrilHielo->Destroy();
					}
				}, 5.0f, false); // 10 segundos de vida
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



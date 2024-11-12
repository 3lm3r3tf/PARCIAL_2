// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrilFuegoExplotaDecorator.h"
#include "Engine/Engine.h"

void ABarrilFuegoExplotaDecorator::Rodar()
{
	Super::Rodar();
	GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, TEXT("¡El barril de fuego explota! ..BarrilFuegoExplotaDecorator "));
}

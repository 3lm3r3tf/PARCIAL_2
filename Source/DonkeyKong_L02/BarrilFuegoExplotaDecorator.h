// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BarrilDecorator.h"
#include "BarrilFuegoExplotaDecorator.generated.h"

/**
 * 
 */
UCLASS()
class DONKEYKONG_L02_API ABarrilFuegoExplotaDecorator : public ABarrilDecorator
{
	GENERATED_BODY()
public:
	virtual void Rodar() override;
};

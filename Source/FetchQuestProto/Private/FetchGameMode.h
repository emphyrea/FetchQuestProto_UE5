// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FetchPet.h"
#include "MainCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "FetchGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AFetchGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AFetchGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "PlayerRefs")
	AFetchPet* pet;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "PlayerRefs")
	AMainCharacter* player1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Money")
	float currentMoney;
	
};

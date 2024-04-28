// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "GameFramework/Character.h"
#include "FetchPet.generated.h"

UCLASS()
class AFetchPet : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFetchPet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Camera")
	float maxDistanceApart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Owner Player")
	TSubclassOf<AMainCharacter> OwnerChar;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Stats")
	bool handsFull;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"

#include "GameFramework/Actor.h"
#include "Spawnable.h"

#include "ItemSpawner.generated.h"

UCLASS()
class AItemSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemSpawner();
	
	UFUNCTION(BlueprintPure, Category= "Spawner")
		FVector GetRandomSpawnLoc();

private:
	void SpawnThisActor();
	float randSpawnDelay;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Spawner")
	UBoxComponent* spawnVol;

	UPROPERTY(EditAnywhere, Category= "Spawner")
	TSubclassOf<ASpawnable> itemToSpawn1;
	UPROPERTY(EditAnywhere, Category= "Spawner")
	TSubclassOf<ASpawnable> itemToSpawn2;
	UPROPERTY(EditAnywhere, Category= "Spawner")
	TSubclassOf<ASpawnable> itemToSpawn3;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawner")
	float minSpawnDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawner")
	float maxSpawnDelay;

	FTimerHandle spawnTimerHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

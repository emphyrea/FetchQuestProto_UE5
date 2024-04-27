// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemSpawner.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AItemSpawner::AItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	spawnVol = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawner"));

	minSpawnDelay = 1.0f;
	maxSpawnDelay = 10.0f;
}

FVector AItemSpawner::GetRandomSpawnLoc()
{
	const FVector spawnOrigin = spawnVol->Bounds.Origin;
	const FVector spawnLimits = spawnVol->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(spawnOrigin, spawnLimits);
}

void AItemSpawner::SpawnThisActor()
{
	if(!itemToSpawn1 || !itemToSpawn2 || !itemToSpawn3)
	{
		return;
	}

	FRotator randRot;
	randRot.Yaw = FMath::RandRange(1, 3) * 360.0f;
	randRot.Pitch = 0.0f;
	randRot.Roll = 0.0f;

	FActorSpawnParameters spawnParams;

	spawnParams.Owner = this;
	spawnParams.Instigator = GetInstigator();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	if(!GetWorld())
	{
		return;
	}

	int randNum = FMath::RandRange(0, 8);
	if(randNum >= 6 || randNum <= 8)
	{
		ASpawnable* itemSpawned = GetWorld()->SpawnActor<ASpawnable>(itemToSpawn1, GetRandomSpawnLoc(), randRot, spawnParams);
		itemSpawned->SetLifeSpan(5);
	}
	if(randNum >= 3 || randNum <= 5)
	{
		ASpawnable* itemSpawned = GetWorld()->SpawnActor<ASpawnable>(itemToSpawn2, GetRandomSpawnLoc(), randRot, spawnParams);
		itemSpawned->SetLifeSpan(5);
	}
	if(randNum >= 0 || randNum <= 2)
	{
		ASpawnable* itemSpawned = GetWorld()->SpawnActor<ASpawnable>(itemToSpawn3, GetRandomSpawnLoc(), randRot, spawnParams);
		itemSpawned->SetLifeSpan(5);
	}
	
	GetWorld()->GetTimerManager().SetTimer(spawnTimerHandle, this, &AItemSpawner::SpawnThisActor, randSpawnDelay, false);

}

// Called when the game starts or when spawned
void AItemSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	randSpawnDelay = FMath::RandRange(minSpawnDelay, maxSpawnDelay);
	GetWorld()->GetTimerManager().SetTimer(spawnTimerHandle, this, &AItemSpawner::SpawnThisActor, randSpawnDelay, false);
}

// Called every frame
void AItemSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "FetchPet.h"

// Sets default values
AFetchPet::AFetchPet()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	maxDistanceApart = 800.0f;
	handsFull = false;
}

// Called when the game starts or when spawned
void AFetchPet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFetchPet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFetchPet::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


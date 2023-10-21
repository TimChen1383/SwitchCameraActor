// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwitchCamera.generated.h"

UCLASS()
class UECPP_PRACTICE_API ASwitchCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwitchCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AActor* CameraOne;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AActor* CameraTwo;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float CameraBlendingTime = 2.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float WaitCameraTime = 3.0f;

private:
	float CurrentCameraTime;
};


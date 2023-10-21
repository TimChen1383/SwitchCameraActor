// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchCamera.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASwitchCamera::ASwitchCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentCameraTime = 0;
	WaitCameraTime = 4;
	CameraBlendingTime = 2;

}

// Called when the game starts or when spawned
void ASwitchCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwitchCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentCameraTime -= DeltaTime;

	if(CurrentCameraTime <= 0.0f)
	{
		CurrentCameraTime += WaitCameraTime;
		APlayerController* MyPlayer = UGameplayStatics::GetPlayerController(GetWorld(),0);

		if(MyPlayer)
		{
			if(MyPlayer->GetViewTarget() == CameraOne)
			{
				MyPlayer->SetViewTargetWithBlend(CameraTwo, CameraBlendingTime);
			}
			else
			{
				MyPlayer->SetViewTargetWithBlend(CameraOne, CameraBlendingTime);
			}
		}
	}
}

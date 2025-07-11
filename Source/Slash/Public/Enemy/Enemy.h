#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Enemy.generated.h"

class UAnimMontage;

UCLASS()
class SLASH_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetHit(const FVector& ImpactPoint) override;
protected:
	virtual void BeginPlay() override;

	void PlayHitReactMontage(const FName& SectionName);

private:
    UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* HitReactMontage;
    

public:

};

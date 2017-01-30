#pragma once
#include "Input/Controller.h"
#include "GameWorld/GameEntities/Entity/Entity.h"

namespace BlazeInput
{
	class PlayerController : public Controller
	{
	public:
		PlayerController();
		~PlayerController();

		bool Initialize() override;
		bool Shutdown() override;

		void Update(BlazeGameWorld::Entity& entity) override;

	private:
		Input input;
	};
}
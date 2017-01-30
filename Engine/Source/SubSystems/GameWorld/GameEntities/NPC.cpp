#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Graphics/ShapeData.h"
#include "Graphics/Graphics.h"
#include "Physics/Physics.h"
#include "Input/AIController.h"
#include "NPC.h"

namespace BlazeGameWorld
{
	NPC::NPC() :
		Entity(new BlazeGraphics::Graphics, new BlazePhysics::Physics, new BlazeInput::AIController)
	{
	}

	NPC::~NPC()
	{
	}

	bool NPC::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry)
	{
		Entity::Initialize(startPosition, geometry);

		return true;
	}

	bool NPC::Shutdown()
	{
		Entity::Shutdown();

		return true;
	}

	void NPC::Update()
	{
		controller->Update(*this);
		physics->Update(*this);
		renderer->Update(*this);

		//Have to zero out velocity after updating every frame so that key input doesn't compound and 
		//cause the object to move in a direction its not meant to for a certain key press.
		this->velocity.x = 0;
		this->velocity.y = 0;
	}

}

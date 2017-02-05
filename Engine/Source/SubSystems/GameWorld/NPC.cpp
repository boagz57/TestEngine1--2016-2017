#include "Precompiled.h"
#include "Universal/Macro.h"
#include "GraphicsComponents/RendererComponent/ShapeData.h"
#include "GameWorld/Entity.h"
#include "GraphicsComponents/RendererComponent/RendererComponent.h"
#include "Physics/PhysicsComponents/CollisionComponent.h"
#include "NPC.h"

namespace BlazeGameWorld
{
	NPC::NPC() 
	{
	}

	NPC::~NPC()
	{
	}

	bool NPC::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry)
	{
		Pawn::Initialize(startPosition, geometry);

		return true;
	}

	bool NPC::Shutdown()
	{
		Entity::Shutdown();

		return true;
	}

	void NPC::Update()
	{
		collision.Update();
		renderer.Update();

		//Have to zero out velocity after updating every frame so that key input doesn't compound and 
		//cause the object to move in a direction its not meant to for a certain key press.
		this->velocity.x = 0;
		this->velocity.y = 0;
	}
}

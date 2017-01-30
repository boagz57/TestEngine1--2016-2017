#include "Precompiled.h"
#include <memory.h>
#include "Macro.h"
#include "Graphics/Graphics.h"
#include "Input/Controller.h"
#include "Physics/Physics.h"
#include "Input/Input.h"
#include "Graphics/ShapeData.h"
#include "Entity.h"

namespace BlazeGameWorld
{
	Entity::Entity()
	{}

	Entity::Entity(BlazeGraphics::Graphics* renderer, BlazePhysics::Physics* physics, BlazeInput::Controller* controller) :
		renderer(renderer),
		physics(physics),
		controller(controller),
		position(0.0f, 0.0f),
		velocity(0.0f, 0.0f)
	{
	}

	Entity::~Entity()
	{
	}

	bool Entity::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry)
	{
		RUNTIME_ASSERT(startPosition.x <= 1.0f && startPosition.x >= -1.0f, "ERROR: Entity's x start position is outside current window");
		RUNTIME_ASSERT(startPosition.y <= 1.0f && startPosition.y >= -1.0f, "ERROR: Entity's y start position is outside current window");

		this->position.x = startPosition.x;
		this->position.y = startPosition.y;

		controller->Initialize();
		physics->Initialize();
		renderer->Initialize();

		renderer->addGeometry(geometry);
		renderer->CreateRenderable();
		renderer->InitializeBuffers();

		return true;
	}

	bool Entity::Shutdown()
	{
		controller->Shutdown();
		physics->Shutdown();
		renderer->Shutdown();

		delete physics;
		delete renderer;
		delete controller;

		return true;
	}
}

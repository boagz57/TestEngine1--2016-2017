#include "Precompiled.h"
#include "Graphics/Graphics.h"
#include "Graphics/Geometry.h"
#include "Input/Input.h"
#include "Physics/Physics.h"
#include "Universal/Globals.h"
#include "Input/Input.h"
#include "Player.h"

//TODO: move all game world classes out of GameEntities folder and delete it

namespace BlazeGameWorld
{
	Player::Player() :
		input()
	{
	}

	Player::~Player()
	{
	}

	bool Player::Initialize(BlazeFramework::Math::Vector2D startPosition, BlazeGraphics::Geometry geometry)
	{
		Pawn::Initialize(startPosition, geometry);
		input.Initialize();
		
		return true;
	}

	bool Player::Shutdown()
	{
		Entity::Shutdown();

		return true;
	}

	void Player::Update()
	{
		input.Update(*this);
		physics.Update(*this);

		position += (velocity * engineClock.TimeSinceLastFrame());

		renderer.Update(*this);


		//Have to zero out velocity after updating every frame so that key input 
		//doesn't compound and cause the object to move in a direction its 
		//not meant to for a certain key press.
		this->velocity.x = 0;
		this->velocity.y = 0;
	}
}
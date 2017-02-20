#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Math/Vector2D.h"
#include "Components/Component.h"
#include "SceneManager.h"

SceneManager::SceneManager() :
	numMaxEntities(10)
{
}

SceneManager::~SceneManager()
{
}

bool SceneManager::Initialize()
{
	bitMasks.resize(numMaxEntities);
	positionComponents.resize(numMaxEntities);
	appearanceComponents.resize(numMaxEntities);
	velocityComponents.resize(numMaxEntities);
	AABBComponents.resize(numMaxEntities);

	return false;
}

bool SceneManager::Shutdown()
{
	return false;
}

uint16 SceneManager::M_CreateEntity()
{
	//There are no concrete entities. Only entity ID numbers. Each index 
	//in all container classes represents a separate entity.
	for (uint16 entity = 0; entity < numMaxEntities; entity++)
	{
		//Return the first empty (no bits turned on in bitMask; no 
		//components attached) entity index found.
		if (bitMasks.at(entity) == NoComponents)
			return entity;
	}

	LOG("ERROR: Cannot create more entities!!");
	return numMaxEntities;
}

uint16 SceneManager::CreatePlayer(BlazeFramework::Vector2D startPosition, char8 * shapeToRender)
{
	RUNTIME_ASSERT(shapeToRender != nullptr, "ERROR: Need a valid shape to render!!!");//TODO: Need better assert system here to check that shape name matches a valid choice

	uint16 entity = M_CreateEntity();

	//Set an entity to show as having certain components attached (creates
	//the 'key' for the entity to see if it will fit in a system's 'lock'.
	bitMasks.at(entity) = PositionComponent | AABBComponent | VelocityComponent | AppearanceComponent;

	positionComponents.at(entity).position = startPosition;
	appearanceComponents.at(entity).geometryShapeName = shapeToRender;

	return entity;
}

uint16 SceneManager::CreateStaticEntity(BlazeFramework::Vector2D position, char8* shapeToRender)
{
	uint16 entity = M_CreateEntity();

	//Set an entity to show as having certain components attached (creates
	//the 'key' for the entity to see if it will fit in a system's 'lock'.
	bitMasks.at(entity) = PositionComponent | AABBComponent | AppearanceComponent;

	positionComponents.at(entity).position = position;
	appearanceComponents.at(entity).geometryShapeName = shapeToRender;

	return entity;
}

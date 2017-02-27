#include "Precompiled.h"
#include "SDL_mixer.h"
#include "GameWorld/SceneManager.h"
#include "Components/Component.h"
#include "Components/Velocity.h"
#include "AudioSystem.h"

static Velocity* entityVelocity = nullptr;

namespace BAudio
{
	void SoundEffect::PlaySoundEffect(uint16 loops /*default val = 0*/)
	{
		if (Mix_PlayChannel(-1, soundFile, loops) == -1)
			LOG("SDL_Mixer PlayChannel could not play sound!!");
	}

	AudioSystem::AudioSystem()
	{
	}

	AudioSystem::~AudioSystem()
	{
	}

	bool AudioSystem::Initialize()
	{
		return false;
	}

	bool AudioSystem::Shutdown()
	{
		return false;
	}

	void AudioSystem::Update(SceneManager& scene)
	{
		//Loop through all 'entities' in scene to see which entities match the
		//render bit mask (which entity 'keys' fit into the render 'lock').
		for (uint16 entity = 0; entity < scene.numMaxEntities; entity++)
		{
			if ((scene.bitMasks.at(entity) & AUDIO_MASK) == AUDIO_MASK)
			{
				entityVelocity = &scene.velocityComponents.at(entity);
			}
		}
	}

	SoundEffect AudioSystem::LoadSoundEffect(char8* filePathToSoundEffect)
	{
		auto it = soundEffectCache.find(filePathToSoundEffect);

		SoundEffect effect;

		if (it == soundEffectCache.end())
		{
			//Failed to find effect file path, have to load it
			Mix_Chunk* soundFile = Mix_LoadWAV(filePathToSoundEffect);

			if (soundFile == nullptr)
				LOG("ERROR: Failed to load sound file!!");

			effect.soundFile = soundFile;
			//Cache sound file in map data structure at file path name
			soundEffectCache[filePathToSoundEffect] = soundFile;
		}
		else
		{
			//Already cached
			effect.soundFile = it->second;
		};

		return effect;
	}
}
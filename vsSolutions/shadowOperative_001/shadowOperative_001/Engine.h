/**
*	@author			Ciaran Bent [K00221230]
*					Owen O'Dea	[K00218956]
*					Rory Ryan	[]
*	@creationDate	2018/11/01	YYYY/MM/DD
*	@description	...
*/

#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <list>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "EnemyGenerator.h"
#include "HUD.h"
#include "LevelManager.h"
#include "ParticleSystem.h"
#include "SoundManager.h"
#include "TextureHolder.h"
#include "Thomas.h"
#include "TutorialManager.h"
#include "Item.h"

class Engine {
public:
	// The Engine constructor
	Engine();
	
	// Run will call all the private functions
	void run();
private:
	//  Is the Player using a controller?
	bool m_usingController = true;

	// The Tutorial System
	//TutorialManager tm;

	// The texture holder
	TextureHolder th;

	// create a particle system
	ParticleSystem m_PS;

	// Thomas and Bob (PlayerCharacters)
	Thomas m_Thomas;

	//Enemy Generator
	
	//Enemy list
	std::list<Enemy*> m_EnemyList;

	//Item list
	std::list<Item*> m_ItemList;

	//Level Manager
	LevelManager m_LM;

	// Create a SoundManager
	SoundManager m_SM;

	// The HUD
	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// The force pushing the characters down
	const int GRAVITY = 300;

	// A regular RenderWindow
	sf::RenderWindow m_Window;

	// The main Views
	sf::View m_MainView;
	sf::View m_MiniMap;

	// Two views for the background
	sf::View m_BGMainView;
	sf::View m_BGMiniMap;

	//  One view for the HUD
	sf::View m_HudView;

	// Declare a sprite and a Texture for the background
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	// Declare a shader for the background
	sf::Shader m_RippleShader;

	// Is the game currently playing?
	bool m_Playing = false;

	// Is character 1 or 2 the current focus?
	bool m_Character1 = true;

	// How much time is left in the current level
	float m_TimeRemaining;
	sf::Time m_GameTimeTotal;

	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	// The vertex array for the level design
	sf::VertexArray m_VALevel;

	// The 2d array with the map for the level
	// A pointer to a pointer
	int** m_ArrayLevel = NULL;

	// Texture for the background and the level tiles
	sf::Texture m_TextureTiles;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

	// Load a new Level
	void loadLevel();

	// Spawn Enemies
	void enemySpawn();

	// Spawn Items
	void ItemSpawn();

	// Run will call all the private functions
	bool detectCollisions(PlayableCharacter& character);

	// Make a vector of the best places to emit sounds from
	void populateEmitters(std::vector <sf::Vector2f>& vSoundEmitters,
		int** arrayLevel);

	// A vector of Vector2f for the fire emiiter locations
	std::vector <sf::Vector2f> m_FireEmitters;

	//  Is the Player using a controller?
	//bool getControls();

	//bool patrolStillValid(int** m_ArrayLevel, Enemy& character);
};
#endif // !ENGINE_H
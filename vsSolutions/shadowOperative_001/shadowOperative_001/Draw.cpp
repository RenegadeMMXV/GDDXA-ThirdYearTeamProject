/**
*	@author			Ciaran Bent [K00221230]
*					Owen O'Dea	[K00218956]
*					Rory Ryan	[K00218864]
*	@creationDate	2018/11/01	YYYY/MM/DD
*	@description
*/

#include <iostream>

#include "Engine.h"


void Engine::draw() {
	// Rub out the last frame
	m_Window.clear(sf::Color::Black);

	if (m_GameState == GameState::MAIN_MENU) {
		// Switch to m_MainView
		m_Window.setView(m_MainView);

		// Draw the background, complete with shader effect for the Menu
		m_Window.draw(m_MenuBackgroundSprite, &m_RippleShader);

		for (std::list<GUI::Button>::iterator it = m_mainMenuButtons.begin(); it != m_mainMenuButtons.end(); ++it) {
			m_Window.draw(*it);
		}
	}
	else if (m_GameState == GameState::PLAYING) {
		/***---------------------***\
		|  HANDLE DRAWING WINDOW	|
		\***---------------------***/
		// Update the shader parameters
		m_RippleShader.setUniform("uTime", m_GameTimeTotal.asSeconds());

		// Switch to background view
		m_Window.setView(m_BGMainView);
		// Draw the background
		//m_Window.draw(m_BackgroundSprite);

		// Draw the background, complete with shader effect
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// Switch to m_MainView
		m_Window.setView(m_MainView);

		// Draw the Level
		m_Window.draw(m_VALevel, &m_TextureTiles);
		//Draw the Switches

		
		for (std::list<ToggleSwitch*>::iterator SwitchIt = m_SwitchList.begin();
				SwitchIt != m_SwitchList.end(); SwitchIt++) {
			
			m_Window.draw((*SwitchIt)->getSprite());
		}
		//Draw the doors
		for (std::list<Door*>::iterator doorIt = m_DoorList.begin();
			doorIt != m_DoorList.end();doorIt++) {
			m_Window.draw((*doorIt)->getDoorSprite());
		}

		//Draw Camera
		std::list<Camera*>::iterator cameraIt = m_CameraList.begin();
		for (;cameraIt != m_CameraList.end();cameraIt++) {
			m_Window.draw((*cameraIt)->getSprite());
			m_Window.draw((*cameraIt)->getDetectMeter());
		}
		

		// Draw Player
		m_Window.draw(m_Player.getSprite());

		//drawing targeting laser
		if (m_Player.isTargeting()) {
			m_Window.draw(m_Player.getlaser());
		}

		//Draw Enemies
		if (!m_EnemyList.empty()){
			//std::cout << "\nNumber of enemies:" << m_LM.getNumOfEnemies();
			for (std::list<Enemy*>::iterator it = m_EnemyList.begin(); 
				 it != m_EnemyList.end(); it++){
				//std::cout << "\nDrawing enemies";
				m_Window.draw((*it)->getSprite());
				m_Window.draw((*it)->getDetectMeter());
			}
		}
		//Draw the bullets
		for (int i = 0;i < 5; i++){
			if (bullets[i].isInFlight()){
				//std::cout << "\nDrawing bullets" << i;
				//m_Window.draw(bullets[i].getShape());
				m_Window.draw(bullets[i].getSprite());
			}
		}
		//Draw Items 
		for (std::list<Item*>::iterator itemIter = m_ItemList.begin();
			itemIter != m_ItemList.end();itemIter++) {
			m_Window.draw((*itemIter)->getSprite());
		}

		// Draw the particle system
		if (m_PS.running()) {
			m_Window.draw(m_PS);
		}

		/***---------------------***\
		|	  HANDLE DRAWING HUD	|
		\***---------------------***/
		// Switch to m_HudView
		m_Window.setView(m_HudView);
		m_Window.draw(m_Hud.getHidden());
		//m_Window.draw(m_Hud.getTime());
		m_Window.draw(m_Hud.getGunBackground());
		m_Window.draw(m_Hud.getGunCharge());

		/***---------------------***\
		|  HANDLE DRAWING MINI_MAP	|
		\***---------------------***/
		m_Window.setView(m_BGMiniMap);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_MiniMap);
		m_Window.draw(m_VALevel, &m_TextureTiles);
		m_Window.draw(m_Player.getSprite());
		//Draw the doors
		for (std::list<Door*>::iterator doorIt = m_DoorList.begin();
			doorIt != m_DoorList.end();doorIt++) {
			m_Window.draw((*doorIt)->getDoorSprite());
		}

		for (std::list<Enemy*>::iterator iter = m_EnemyList.begin();
			iter != m_EnemyList.end(); iter++)
		{
			m_Window.draw((*iter)->getSprite());
			m_Window.draw((*iter)->getCone());
		}
		std::list<Camera*>::iterator camIt = m_CameraList.begin();
		for (;camIt != m_CameraList.end();camIt++) {
			m_Window.draw((*camIt)->getSprite());
			m_Window.draw((*camIt)->getCone());
		}
	}
	else if (m_GameState == GameState::PAUSED) {
		//Background of paused menu
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);
		//Message for the paused Game state
		m_Window.draw(m_Hud.getMessage());

	}
	else if (m_GameState == GameState::SETTINGS) {
		// Switch to m_MainView
		m_Window.setView(m_MainView);

		// Put Settings Screen draw code here
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);
		
		//	List all Settings Pages
		if (m_SettingsPage == SettingsPage::LIST) {			
			for (std::list<GUI::Button>::iterator it = m_settingsButtons.begin(); it != m_settingsButtons.end(); ++it) {
				m_Window.draw(*it);
			}			
		}
		//	List Graphics Settings
		else if (m_SettingsPage == SettingsPage::GRAPHICS) {			
			for (std::list<GUI::Button>::iterator it = m_graphicsSettingsButtons.begin(); it != m_graphicsSettingsButtons.end(); ++it) {
				m_Window.draw(*it);
			}			
		}
		//	List Audio Settings
		else if (m_SettingsPage == SettingsPage::AUDIO) {
			for (std::list<GUI::Button>::iterator it = m_audioSettingsButtons.begin(); it != m_audioSettingsButtons.end(); ++it) {
				m_Window.draw(*it);
			}
		}
		//	List Gameplay Settings
		else if (m_SettingsPage == SettingsPage::GAMEPLAY) {
			for (std::list<GUI::Button>::iterator it = m_gameplaySettingsButtons.begin(); it != m_gameplaySettingsButtons.end(); ++it) {
				m_Window.draw(*it);
			}
		}
	}
	else if (m_GameState == GameState::LOADING) {
		// Put Loading Screen draw code here
	}

	// Show everything we have just drawn
	m_Window.display();
}
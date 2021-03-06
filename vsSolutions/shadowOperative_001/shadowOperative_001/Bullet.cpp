/**
*	@author			Ciaran Bent [K00221230]
*					Owen O'Dea	[K00218956]
*					Rory Ryan	[K00218864]
*	@creationDate	2018/11/01	YYYY/MM/DD
*	@description	...
*/

#include "Bullet.h"

/**
*	Default Constructor
*/
Bullet::Bullet() {
	//std::cout << "\nBullet initialised";
	m_BulletSprite = sf::Sprite(TextureHolder::GetTexture(
		"graphics/Purple Spark Bullets/Purple_BULLET_000.png"));
	m_BulletSprite.setPosition(this->m_Position);
	m_InFlight = false;
}

/**
*	Set the trajectory of the bullet object using the player's current location and a target location
*/
void Bullet::shoot(float startX, float startY,
	float targetX, float targetY) {
	// Keep track of the bullet
	m_InFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;

	// Calculate the gradient of the flight path
	float gradient = (startX - targetX) / (startY - targetY);

	// Any gradient less than zero needs to be negative
	if (gradient < 0) {
		gradient *= -1;
	}

	// Calculate the ratio between x and t
	const float ratioXY = m_BulletSpeed / (1 + gradient);

	// Set the "speed" horizontally and vertically
	m_BulletDistance.y = ratioXY;
	m_BulletDistance.x = ratioXY * gradient;

	// Point the bullet in the right direction
	if (targetX < startX) {
		m_BulletDistance.x *= -1;
	}

	if (targetY < startY) {
		m_BulletDistance.y *= -1;
	}

	// Finally, assign the results to the
	// member variables
	m_Target.x = targetX;
	m_Target.y = targetY;

	// Set a max range of 1000 pixels
	const float range = 1000;
	m_Min.x = startX - range;
	m_Max.x = startX + range;
	m_Min.y = startY - range;
	m_Max.y = startY + range;

	// Position the bullet ready to be drawn
	m_BulletSprite.setPosition(startX, startY);
	m_BulletShape.setPosition(startX, startY);
}

/**
*	Set m_InFlight signaling to all functions to stop updating this bullet
*/
void Bullet::stop(SoundManager& m_SM) {
	m_SM.playEnemyHit();
	m_InFlight = false;
}

/**
*	Return wether or not the bullet is currently in flight
*/
bool Bullet::isInFlight() {
	return m_InFlight;
}

/**
*	return the floatRect bounds of the players position
*/
sf::FloatRect Bullet::getPosition() {
	return m_BulletSprite.getGlobalBounds();
}

/**
*	Return the Sprite of the bullet object
*/
sf::Sprite Bullet::getSprite() {
	return m_BulletSprite;
}

/**
*	Update the bullet objects location using its trajectory and time elapsed since last update
*/
void Bullet::update(float elapsedTime) {
	// Update the bullet position variables
	m_Position.x += m_BulletDistance.x * elapsedTime;
	m_Position.y += m_BulletDistance.y * elapsedTime;

	// Move the bullet
	m_BulletSprite.setPosition(m_Position);
	m_BulletShape.setPosition(m_Position);

	// Has the bullet gone out of range?
	if (m_Position.x < m_Min.x || m_Position.x > m_Max.x ||
		m_Position.y < m_Min.y || m_Position.y > m_Max.y) {
		m_InFlight = false;
	}
}

/**
*	get the center of the object(x,y coordinates)
*/
sf::Vector2f Bullet::getCenter() {
	return m_Position;
}

/**
*	set the amount of power in the shot(How much damage it does)
*/
void Bullet::setShotPower(float power) {
	this->shotPower = power;
}

/**
*	return the amount of power in the shot(How much damage it does)
*/
float Bullet::getShotPower() {
	return shotPower;
}
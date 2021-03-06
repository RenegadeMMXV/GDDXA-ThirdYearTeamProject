/**
*	@author			Ciaran Bent [K00221230]
*					Owen O'Dea	[K00218956]
*					Rory Ryan	[K00218864]
*	@creationDate	2019/01/15	YYYY/MM/DD
*	@description
*/

#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "Enemy.h"

class Camera : public Enemy {
public:
	Camera();
	void spawn(sf::Vector2i startPosition, float gravity, sf::Time gameStart, char dir, int** m_ArrayLevel);
	void update(float elapsedTime, int** m_ArrayLevel);
	void takeDamage();
	float getRotation();
	sf::String getClassName();

private:
	//Current rotation orientation
	float rotation;
	//is the camera rotating Forward or backward
	bool forward = true;
	//What was the original Angle of Rotation
	float rotationStartPoint;
	//What direction is the camera Facing
	char direction;
};
#endif //CAMERA_H

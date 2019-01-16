/**
*	@author			Ciaran Bent [K00221230]
*					Owen O'Dea	[K00218956]
*					Rory Ryan	[K00218864]
*	@creationDate	2018/12/11	YYYY/MM/DD
*	@description	Create a new Enemy Object
*/

#pragma once
#ifndef ENEMYGENERATOR_H
#define	ENEMYGENERATOR_H

#include "Enemy.h"

Enemy* createEnemy(sf::Vector2i position, float Gravity,sf::Time gameStart);

#endif // !ENEMYGENERATOR_H


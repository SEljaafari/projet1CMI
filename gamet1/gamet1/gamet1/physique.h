#pragma once
#include "vecteurs.h"
#include"base.h"

struct physique
{
	vecteurs location{ 0, 0 };
	vecteurs speed{ 0, 0 };
	vecteurs acceleration{ 0, 0 };

	void ticks(const sf::Time& deltat)
	{
		acceleration.y = 3500;

		speed += acceleration * deltat.asSeconds();	

			location += speed * deltat.asSeconds();

	}

};
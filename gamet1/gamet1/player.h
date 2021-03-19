#pragma once
#include "vecteurs.h"
#include "physique.h"


namespace sf
{
	class RenderWindow;
	class Time;
};

class player
{
private:
	static constexpr float speed = 16.f;
	//vecteurs location = vecteurs(0, 500);
	physique physique;

 public:
	player();
	~player();

	void draw(sf::RenderWindow& window);
	void inputs();
	void ticks(const sf::Time& deltat);


};
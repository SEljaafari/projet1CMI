#pragma once
#include "vecteurs.h"
#include "physique.h"
#include "physique.h"



namespace sf
{
	class RenderWindow;
	class Time;
	
	
};

class player
{
private:
	static constexpr float speed = 5.f;
	//vecteurs location = vecteurs(0, 500);
	physique physique;

	sf::Texture texture;
	sf::Sprite sprite;

	sf::Texture texturesnk;

	sf::Texture texturer;

	sf::Texture texturel;
	


public:
	player();
	~player();

	void draw(sf::RenderWindow& window);
	void inputs();
	void ticks(const sf::Time& deltat);
	
	float saut = -800;

};
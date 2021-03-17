#include <SFML/Graphics.hpp>
#include "player.h"

player::player()
{
}

player::~player()
{
}

void player::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	if (!texture.loadFromFile("images/cute_image.jpg"))
		return;
	sf::Sprite sprite(texture);


	sprite.setPosition(physique.location.x, physique.location.y);
	window.draw(sprite);
}

void player::inputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		physique.location.x -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		physique.location.x += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		physique.speed.y = -800;
	}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		physique.location.y += speed;
	}


}

void player::ticks(const sf::Time& deltat)
{
	sf::Texture texture;
	if (!texture.loadFromFile("images/cute_image.jpg"))
		return;

	physique.ticks(deltat);

	constexpr float imagesizeY = 300;
	const float border = WINDOW_SIZE_Y - imagesizeY;

	if (physique.location.y > border)
	{
		physique.location.y = border;
		physique.speed.y = 0;

	}

}

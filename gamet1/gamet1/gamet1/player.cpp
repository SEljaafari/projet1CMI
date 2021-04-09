#include <SFML/Graphics.hpp>
#include "player.h"


player::player()
{
	
	if (!texture.loadFromFile("images/persoface.png"))
		return;

	if (!texturesnk.loadFromFile("images/sneak.png"))
		return;

	if (!texturer.loadFromFile("images/oeufright.png"))
		return;

	if (!texturel.loadFromFile("images/oeufleft.png"))
		return;

	sprite = sf::Sprite(texture);

}

player::~player()
{
}

void player::draw(sf::RenderWindow& window)
{


	sprite.setPosition(physique.location.x, physique.location.y);
	window.draw(sprite);
}
void player::inputs()
{
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sprite = sf::Sprite(texturel);

		physique.location.x -= speed;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sprite = sf::Sprite(texturer);

		physique.location.x += speed;
	}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && ( i <30 )) SAUT
	//{
		
			//physique.speed.y = -800;
		//	i += 1;
		
	//}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//while ((physique.location.y) > (WINDOW_SIZE_Y - 300))
		//{
		

			physique.location.y += speed;
		//}
	}


}


void player::ticks(const sf::Time& deltat)
{
	
	physique.ticks(deltat);

	constexpr float imagesizeY = 300;
	const float border = WINDOW_SIZE_Y - imagesizeY;


	if (physique.location.y > border)
	{
		
		sprite = sf::Sprite(texture);
		physique.location.y = border;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			sprite = sf::Sprite(texturesnk);
			saut -= 25;
		}
	
		physique.speed.y = saut;

		
		




	}
	if (physique.location.y < border-15)
	{
		saut = -1600;
		sprite = sf::Sprite(texture);
	}
	
}

//void player::score()
//{
//	text.setFont(baby);


//	text.setString("wesh l'equipe");

	// choix de la taille des caractères
//	text.setCharacterSize(24); // exprimée en pixels, pas en points !

	// choix de la couleur du texte
//	text.setFillColor(sf::Color::Red);

	// choix du style du texte
//	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

//}
#include <SFML/Graphics.hpp>
#include "player.h"
#include "base.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "CUBE");
  
	player player;
	sf::Clock clock;

    while (window.isOpen())
    {
		
		sf::Time deltat = clock.restart();


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			
        }

		player.ticks(deltat);
		player.inputs();
		
		// draw
        window.clear();
		player.draw(window);
		window.display();
    }

    return 0;
}
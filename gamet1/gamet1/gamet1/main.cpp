#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "player.h"
#include "base.h"
#include <sstream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "CUBE");
  
	player player;
	sf::Clock clock;
	sf::Clock clock1;
	

	sf::Font font;

	
	 
	

	if ( !font.loadFromFile( "police/BABYBLOC.ttf" ) )
	{
		std::cout << "error font" << std::endl;
		
		
		system( "pause" );
	}




    while (window.isOpen())
    {
		
		sf::Time deltat = clock.restart();

		sf::Time temps = clock1.getElapsedTime();
		

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                window.close();
			
        }
		//score

		sf::Int32 score = temps.asMilliseconds()/25;
		

		std::ostringstream ssScore;

		ssScore << "score " << score;

		sf::Text text;
		text.setFont(font);
		text.setString(ssScore.str());
		text.setFillColor(sf::Color::White);


		//

		player.ticks(deltat);
		player.inputs();
		
		// draw
        window.clear();
		player.draw(window);
		window.draw( text );
		window.display();
	}

   

    return 0;
}
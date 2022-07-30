#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include"pointsList.h"
#include"GravitySource.h"
//----------------------------------------------------------------------------------------------------------------------------------------
/*
The solar system simulation with the sun, mercury, venus, earth and mars
*/
//----------------------------------------------------------------------------------------------------------------------------------------
int main() {
	constexpr double AU_to_pixle = GravitySource::AU / GravitySource::unit;
	constexpr int width = 1280, height = 800;
	sf::RenderWindow window(sf::VideoMode(width, height), "Solar system simulator");
	window.setFramerateLimit(60);
	
	//creating a vector of planets(and sun)
	//the inputs are(name, x coordination, y coordination, x axis velocity, y axis velocity, mass, color, radius)
	GravitySource sun("sun", width / 2, height / 2, 0, 0, 1.98892 * power(10, 30), sf::Color::Yellow, 20);

	GravitySource earth("earth", width / 2 - AU_to_pixle, height / 2, 0, 29.783 * power(10, 3), 5.9742 * power(10, 24), sf::Color::Blue, 8);

	GravitySource mars("mars", width / 2 + 1.405 * AU_to_pixle, height / 2, 0, -24.077 * power(10, 3), 6.39 * power(10, 23), sf::Color::Red, 6);

	GravitySource mercury("mercury", width / 2, height / 2 - 0.385 * AU_to_pixle, -47.4 * power(10, 3), 0, 3.30 * power(10, 23), sf::Color::Color(100,100,100, 255), 4);

	GravitySource venus("venus", width / 2, height / 2 + 0.725 * AU_to_pixle, 35.02 * power(10, 3), 0, 4.8685 * power(10, 24), sf::Color::White, 7);

	std::vector<GravitySource*> planets{&sun, &earth, &mars, &mercury, &venus};

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{	
			if (event.type == sf::Event::Closed) window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		}

		window.clear(sf::Color::Black);
		//moveing and drawong the planets in the vector
		for (auto planet : planets)
		{
			planet->updatePhysics(planets);
			planet->render(window);
		}
		window.display();
	}
	return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------
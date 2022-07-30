#include"GravitySource.h"

//----------------------------------------------------------------------------------------------------------------------------------------
GravitySource::GravitySource(const char* name, float pos_x, float pos_y, float vel_x, float vel_y, double mass, sf::Color c, float radius) : mass(mass), name(name), radius(radius) 
{
	pos.x = pos_x;
	pos.y = pos_y;
	vel.x = vel_x;
	vel.y = vel_y;
	if(name != "sun")
		poinst.push(pos_x + radius / 2, pos_y + radius / 2);


	s.setPosition(pos);
	s.setFillColor(c);
	s.setRadius(radius);
}
//----------------------------------------------------------------------------------------------------------------------------------------
//drawing planet and it's path
void GravitySource::render(sf::RenderWindow& win)
{
	s.setPosition(pos.x - radius / 2, pos.y -radius / 2);

	if (poinst.getCount() > 1)
	{
		node* temp = poinst.getHead();
		node* temp2 = temp->getNext();

		while (temp2 != nullptr)
		{
			sf::Vertex line[] = { sf::Vertex(sf::Vector2f(temp->getX(), temp->getY())), sf::Vertex(sf::Vector2f(temp2->getX(), temp2->getY())) };
			win.draw(line, 2, sf::Lines);
			temp = temp2;
			temp2 = temp2->getNext();
		}
	}
	win.draw(s);
}
//----------------------------------------------------------------------------------------------------------------------------------------
//updates planets velocity
void GravitySource::updatePhysics(std::vector<GravitySource*>& planets)
{
	double totalForcX = 0, totalForcY = 0;
	for (int i = 0; i < planets.size(); ++i)
	{
		if (planets[i]->getName() == name)
			continue;
		double distanceX = (planets[i]->getPos().x - pos.x) * unit;
		double distanceY = (planets[i]->getPos().y - pos.y) * unit;

		double distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		double inverseDistance = 1.f / distance;

		double normalizedX = distanceX * inverseDistance;
		double normalizedY = distanceY * inverseDistance;

		double inverseSquareDropOff = inverseDistance * inverseDistance;

		double ForcX = normalizedX * G * planets[i]->getMass() * mass * inverseSquareDropOff;	//the gravity inverse square law - F = G*m1*m2/d^2
		double ForcY = normalizedY * G * planets[i]->getMass() * mass * inverseSquareDropOff;	//the gravity inverse square law - F = G*m1*m2/d^2

		vel.x += ForcX / mass * timeStep;	//Newton's second law of motion - F = a * m
		vel.y += ForcY / mass * timeStep;	//Newton's second law of motion - F = a * m
	}
	pos.x += vel.x / unit * timeStep;	//update position
	pos.y += vel.y / unit * timeStep;	//update position
	if(name != "sun")
		poinst.push(pos.x + radius / 2, pos.y + radius / 2);
}
//----------------------------------------------------------------------------------------------------------------------------------------




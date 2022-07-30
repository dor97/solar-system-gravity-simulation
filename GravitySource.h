#pragma once
#include"SFML/Graphics.hpp"
#include"pointsList.h"
#include"utilites.h"
//constexpr double power(double num, int p);
//----------------------------------------------------------------------------------------------------------------------------------------
class GravitySource {
	sf::Vector2f pos;
	sf::CircleShape s;
	double mass;
	sf::Vector2f vel;
	std::string name;
	pointsList poinst;	//poinst to darw planet path
	float radius;
public:
	static constexpr double AU = (double)147098074 * 1000;	//distance from earth to sun(average)
	static constexpr double unit = AU / 280;	//pixel in meters
	static constexpr double G = 6.6743 / power(10, 11);		//the G constant in the gravity inverse square law 
	static constexpr double timeStep = 3600 * 24;		//seconds in a day, use to speed up the movement

public:
	GravitySource(const char* name, float pos_x, float pos_y, float vel_x, float vel_y, double mass, sf::Color c, float radius);
	void render(sf::RenderWindow& win);
	sf::Vector2f getPos() { return pos; } const
	float getMass() { return mass; }
	std::string getName() { return name; }
	void updatePhysics(std::vector<GravitySource*>& planets);

};
//----------------------------------------------------------------------------------------------------------------------------------------

#include "Circle.h"
#include "Shapes.h"
#include <iostream>
#include <fstream>

Circle::Circle(un radius, int x , int y, Color color) : Shapes(x, y, color), radius(radius){
};

Circle::~Circle() {
};

Circle::Circle(const Circle& other) {
	std::cout << "Copy construstor called..." << std::endl;
	//x = other.getX();
	//y = other.getY();
	//color = other.getColor();
	radius = other.getRadius();
};

void Circle::setRadius(int radius) {
	this->radius = radius;
};

int Circle::getRadius() const{ return this->radius; };

void Circle::print(std::ostream& s) const
{
	s << "circle" << " " << getX() << " " << getY() << " " << getRadius() << " " << getColor((int)getColor()) << std::endl;
}

void Circle::SVG(std::ostream& s) const
{
	s << "<circle x = " << getX() << " y = " << getY() << " radius = " << getRadius() << " fill =\"" << getColor() << "\" />";
}




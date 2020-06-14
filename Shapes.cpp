#include "Shapes.h"
#include <iostream>
#include <fstream>

Shapes::Shapes(int x, int y, Color color) {
	this->sx = x;
	this->sy = y;
	this->color = color;
};

Shapes::~Shapes() {

};

Shapes::Shapes(const Shapes& other) {
	std::cout << "Copy construstor called..." << std::endl;
	sx = other.sx;
	sy = other.sy;
	color = other.color;
};

Shapes& Shapes::operator=(Shapes const& other)
{
	if (this != &other)
	{
		sx = other.sx;
		sy = other.sy;
		color = other.color;
	}
	return *this;
}


void Shapes::setX(int x) {
	this->sx = x;
};

void Shapes::setY(int y) {
	this->sy = y;
};

void Shapes::setColor(Color color) {
	this->color = color;
};


int Shapes::getX() const { return sx; }

int Shapes::getY() const { return sy; }

Color Shapes::getColor() const{	return color; }

int Shapes::getColor(const char* color)
{
	if (strcmp(color, "black"))
		return Color::black;
	else if (strcmp(color, "red"))
		return Color::red;
	else if (strcmp(color, "white"))
		return Color::white;
	else if (strcmp(color, "yellow"))
		return Color::yellow;
	else if (strcmp(color, "blue"))
		return Color::blue;
	else if (strcmp(color, "grren"))
		return Color::green;

	return 0;
}

const char* Shapes::getColor(int idOfColor) {
	switch (idOfColor)
	{
	case Color::black: return "black";
	case Color::white: return "white";
	case Color::red: return "red";
	case Color::blue: return "blue";
	case Color::green: return "green";
	case Color::yellow: return "yellow";
	default:
		return nullptr;
	}
}


void Shapes::translateVertical(int vertical)
{
	this->sy = this->sy + vertical;
}

void Shapes::translateHorizontal(int horizontal)
{
	this->sx = this->sx + horizontal;
}

void Shapes::print() const { return; }

void Shapes::SVG(std::ostream& s) const { return; }


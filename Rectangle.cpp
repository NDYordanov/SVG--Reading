#include "Rectangle.h"
#include "Shapes.h"
#include <iostream>
#include <fstream>

Rectangle::Rectangle(un height, un width, int x, int y, Color color) : Shapes(x, y, color), 
					 height(height), width(width) {};


Rectangle::~Rectangle() {
};

Rectangle::Rectangle(const Rectangle &other) {
	std::cout << "Copy construstor called..." << std::endl;
	height = other.height;
	width = other.width;
};

void Rectangle::setHeight(int height) {
	this->height = height;
};

void Rectangle::setWidth(int width) {
	this->width = width;
};

int Rectangle::getHeight() const { return this->height; };

int Rectangle::getWidth() const { return this->width; };

void Rectangle::print(std::ostream& s) const
{
	s << "rectangle" << " " << getX() << " " << getY() << " " << getWidth() << " " << getHeight() << " " << getColor((int)getColor()) << std::endl;
}

void Rectangle::SVG(std::ostream& s) const
{
	s << "<rect x = " << getX() << " y = " << getY() << " width = " << getWidth() << " height = " << getHeight() << " fill =\"" << getColor() << "\" />";
}
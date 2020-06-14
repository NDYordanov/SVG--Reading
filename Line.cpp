#include "Line.h"
#include "Shapes.h"
#include <iostream>
#include <fstream>

Line::Line(un length, int x, int y, Color color) :
		   Shapes(x, y, color), length(length) {

};

Line::~Line() {};

Line::Line(const Line& other) {
	std::cout << "Copy construstor called..." << std::endl;
	length = other.length;
};

void Line::setLength(int length) {
	this->length = length;
};

int Line::getLength() const{ return this->length; };

void Line::print(std::ostream& s) const
{
	s << "line" << " " << getX() << " " << getY() << " " << getLength() << " " << getColor((int)getColor()) << std::endl;
}

void Line::SVG(std::ostream& s) const
{
	s << "<line x = " << getX() << " y = " << getY() << " length = " << getLength() << " fill =\"" << getColor() << "\" />";
}

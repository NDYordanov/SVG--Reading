#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shapes.h"
#pragma once
#define un unsigned
#include <fstream>

class Rectangle : public Shapes 
{
protected:
	un height, width;

public:
	Rectangle(un height = 1, un width = 1, int x = 0, int y = 0, Color color = white);
	~Rectangle();
	Rectangle(const Rectangle &other);
	void setHeight(int height);
	void setWidth(int width);
	int getHeight() const;
	int getWidth() const;
	void print(std::ostream& s) const;
	void SVG(std::ostream& s) const;
};

#endif RECTANGLE_H

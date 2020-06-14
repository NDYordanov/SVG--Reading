#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shapes.h"
#define un unsigned
#pragma once
#include <fstream>

class Circle : public Shapes
{
private:
	un radius;

public:
	Circle(un radius = 1, int x = 0, int y = 0, Color color = white);
	~Circle();
	Circle(const Circle& other);
	void setRadius(int radius);
	int getRadius() const;
	void print(std::ostream& s) const;
	void SVG(std::ostream& s) const;
};

#endif CIRCLE_H


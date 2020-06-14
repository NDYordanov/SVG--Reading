#ifndef LINE_H
#define LINE_H
#include "Shapes.h"
#define un unsigned
#pragma once
#include <fstream>

class Line : public Shapes
{
protected:
	unsigned length;

public:
	Line(un length = 1, int x = 0, int y = 0, Color color = white);
	~Line();
	Line(const Line& other);
	void setLength(int length);
	int getLength() const;
	void print(std::ostream& s) const;
	void SVG(std::ostream& s) const;
};

#endif LINE_H


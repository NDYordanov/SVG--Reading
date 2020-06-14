#ifndef SHAPES_H
#define SHAPES_H
#pragma once
#include <fstream>


enum Color {
	white,
	red, 
	blue, 
	green, 
	yellow, 
	black
};

class Shapes
{
private:
	int sx;
	int sy;
	Color color;

public:
	//Constructors
	Shapes(int x = 0, int y = 0, Color color = white);
	~Shapes();
	Shapes& operator=(Shapes const& other);
	Shapes(const Shapes& other);

	//Getters and setters
	void setX(int x);
	void setY(int y);
	void setColor(Color color);
	int getX() const;
	int getY() const;
	Color getColor() const;
	static int getColor(const char* color);
	static const char* getColor(int idOfColor);

	//Functions
	void translateVertical(int vertical);
	void translateHorizontal(int horizontal);
	virtual void print() const;
	virtual void SVG(std::ostream& s) const;
};


#endif SHAPES_H
#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H
#define un unsigned

#include <vector>
#include <fstream>
#include "Shapes.h"

class Container
{
private:
	Shapes** set;
	un size;
	un maxSize;

	void resize();
	void setContainer(Shapes** set, un size);

public:
	Container(Shapes** set = nullptr, un size = 0, un maxSize = 10);
	Container& operator=(Container const& c);
	Container(Container& const other);
	~Container();

	void SVG(std::ostream& s) const; 
	void print() const; 
	void add(Shapes* figs); 
	void remove(un n); 
	void translateX(int x); 
	void translateY(int y); 
	un getSize() { return size; }
};

#endif


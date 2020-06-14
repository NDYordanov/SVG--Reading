#include "Container.h"
#include <iostream>
#include <fstream>
#define un unsigned

//Private functions
void Container::resize() {
	Shapes** temp;
	temp = new (std::nothrow) Shapes*[size];
	for (un i = 0; i < size; i++)
		temp[i] = new Shapes(*set[i]);

	for (un i = 0; i < size; i++)
		delete set[i];

	set = new (std::nothrow) Shapes*[size * 2];
	for (un i = 0; i < size; i++)
		set[i] = new (std::nothrow) Shapes (*temp[i]);
	
	size *= 2;
	maxSize *= 2;
};

void Container::setContainer(Shapes** set, un size) {
	delete[] set;
	set = new (std::nothrow) Shapes * [size];
	for (un i = 0; i < size; i++)
		this->set[i] = set[i];
};

//Constructors
Container::Container(Shapes** set, un size, un maxSize) : set(nullptr), size(size), maxSize(maxSize) {
	setContainer(set, size);
};

Container& Container::operator=(Container const& c) {
	size = c.size;
	maxSize = c.maxSize;
	setContainer(c.set, c.size);
	return *this;
};

Container::Container(Container& const other) {
	setContainer(other.set, other.size);
	size = other.size;
	maxSize = other.maxSize;
};

Container::~Container() {
	for (un i = 0; i < size; i++)
		delete set[i];

	delete[] set;
};

//public functions
void Container::SVG(std::ostream& s) const {
	for (un i = 0; i < size; i++)
	{
		if (set[i])
		{
			set[i]->SVG(s);
			s << std::endl;
		}

	}
};

//std::ostream& s
void Container::print() const {
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". ";
		if (set[i])
			set[i]->print();
	}
};

void Container::add(Shapes* figs) {
	if (size == maxSize)
		resize();
	set[size] = figs;
	size++;
};

void Container::remove(un n) {
	if (n < 1 || n >= size)
		return;

	set[n - 1] = nullptr;
	for (un i = n - 1; i < size - 1; i++)
		set[i] = set[i + 1];

	size--;
};

void Container::translateX(int x) {
	for (un i = 0; i < size; i++)
		set[i]->setX((set[i]->getX()) + x);
};

void Container::translateY(int y) {
	for (un i = 0; i < size; size++)
		set[i]->setY((set[i]->getY() + y));
};

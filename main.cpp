//  Disabled 'strcpy' warnings
//  with "_CRT_SECURE_NO_WARNINGS"
//  adding to the preprocessor

#include <iostream>
#include <fstream>
#include <cstring>
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Shapes.h"
#include "Container.h"

const int MAX_ELS = 100;

int findVNum(char* str)
{
	char* start = strstr(str, "cal=");
	int value = atoi(start += 4);
	return value;
}
int findHNum(char* str)
{
	char* start = strstr(str, "tal=");
	int value = atoi(start += 4);
	return value;
}
int findX(char* str)
{
	char* start = strstr(str, "x=\"");
	int value = atoi(start += 3);
	return value;
}
int findY(char* str)
{
	char* start = strstr(str, "y=\"");
	int value = atoi(start += 3);
	return value;
}
int findWidth(char* str)
{
	char* start = strstr(str, "width=\"");
	int value = atoi(start += 7);
	return value;
}
int findHeight(char* str)
{
	char* start = strstr(str, "height=\"");
	int value = atoi(start += 8);
	return value;
}
int findRadius(char* str)
{
	char* start = strstr(str, "r=\"");
	int value = atoi(start += 3);
	return value;
}
int findLength(char* str)
{
	char* start = strstr(str, "length=\"");
	int value = atoi(start += 8);
	return value;
}
Color findColour(char* str)
{
	char* start = strstr(str, "fill=\"");
	start += 6;

	if (strstr(start, "green"))
		return green;
	else if (strstr(start, "red"))
		return red;
	else if (strstr(start, "blue"))
		return blue;
	else if (strstr(start, "black"))
		return black;
	else if (strstr(start, "green"))
		return yellow;
	return white;
}

int main() {
		char location[20];
		char open[5];
		std::cin >> open;
		std::cin >> location;
		std::ifstream svg(location);
		if (strcmp(open, "open") == 0 && svg.is_open())
			std::cout << "Successfully opened " << location << std::endl;

		Container svgCon;
		const int maxLine = 100;
		char line[maxLine];

		//Reading file
		bool shouldRead = false;
		while (svg)
		{
			svg.getline(line, maxLine - 1);
			if (strcmp(line, "</svg>") == 0)
			{
				shouldRead = false;
				break;
			}
			if (shouldRead)
			{
				if (strstr(line, "<rect"))
					svgCon.add(new Rectangle(findX(line), findY(line), findWidth(line), findHeight(line), findColour(line)));

				else if (strstr(line, "<circle"))
					svgCon.add(new Circle(findX(line), findY(line), findRadius(line), findColour(line)));

				else if (strstr(line, "<line"))
					svgCon.add(new Line(findX(line), findY(line), findLength(line), findColour(line)));

				continue;
			}
			if (strcmp(line, "<svg>") == 0)
				shouldRead = true;
		}

		//Commands
		bool toExit = true;
		while (toExit)
		{
			char command[20];
			std::cin >> command;
			if (strcmp(command, "print") == 0)
				svgCon.print();

			else if (strcmp(command, "create") == 0)
			{
				char type[10];
				std::cin >> type;
				if (strcmp(type, "rectangle") == 0)
				{
					int x, y, width, height;
					char color[8];
					std::cin >> x >> y >> width >> height >> color;
					svgCon.add(new Rectangle(x, y, width, height, (Color)Shapes::getColor(color)));
				}
				else if (strcmp(type, "circle") == 0)
				{
					int x, y, radius;
					char color[8];
					std::cin >> x >> y >> radius >> color;
					svgCon.add(new Circle(x, y, radius, (Color)Shapes::getColor(color)));
				}
				else if (strcmp(type, "line") == 0)
				{
					int x, y, length;
					char color[8];
					std::cin >> x >> y >> length >> color;
					svgCon.add(new Line(x, y, length, (Color)Shapes::getColor(color)));
				}
			}
			else if (strcmp(command, "erase") == 0)
			{
				int num;
				std::cin >> num;
				if (num <= svgCon.getSize())
					svgCon.remove(num);

				else
					std::cout << "There is no figure number " << num << "!" << std::endl;
			}
			else if (strcmp(command, "translate") == 0)
			{
				char vertical[25];
				char horizontal[25];
				std::cin >> vertical >> horizontal;
				findHNum(horizontal);
				findVNum(vertical);
				svgCon.translateX(findHNum(horizontal));
				svgCon.translateY(findVNum(vertical));
				std::cout << "Translated all figures" << std::endl;

			}

			else if (strcmp(command, "within") == 0)
			{

			}

			else if (strcmp(command, "save") == 0)
			{
				std::ofstream newSvg(location, std::ios::trunc);
				newSvg << "<svg>" << std::endl;
				svgCon.SVG(newSvg);
				newSvg << "</svg>";
				std::cout << "Successfully saved the changes to " << location << std::endl;
			}
			//std::cin >> command;
			else if (strcmp(command, "exit") == 0)
				toExit = false;
		}
		std::cout << "Exited";
		svg.close();
		return 0;
}
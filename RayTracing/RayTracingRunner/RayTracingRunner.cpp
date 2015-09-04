#include "RayTracer.h"
#include <iostream>
#include "Dot.h"

int main()
{
	std::cout << "It Works!\n";
	Geom::Dot a(0, 0, 0);
	Geom::Object& b = a;
	std::cout << a.toString() + "\n";
	std::cout << b.toString() + "\n";
	return 0;
}


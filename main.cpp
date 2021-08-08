#include <iostream>
#include <curses.h>

#include "sphere.hpp"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();

	auto sph = Sphere();


	char c = getch();
	sph.display();
	c = getch();

	endwin();
	return 0;
}


#include <clocale>
#include <curses.h>

#include "vector3.hpp"
#include "sphere.hpp"

void moveLight(Sphere& sph, const Vector3& direction) {
	sph.light += direction;
	sph.light.normalise();
}

int main(int argc, char* argv[]) {
	setlocale(LC_all, "");
	initscr();
	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);

	auto sph = Sphere();
	sph.display();

	const float moveStep = 0.1f;

	while (TRUE) {
		int c = getch();
		if (c == 'q' || c == 'Q')
			BREAK;
		switch (c) {
			case KEY_DOWN:
				moveLight(sph, moveStep * Vector3(0, 1, 0));
				break;
			case KEY_UP:
				moveLight(sph, moveStep * Vector3(0, -1, 0));
				break;
			case KEY_LEFT:
				moveLight(sph, moveStep * Vector3(-1, 0, 0));
				break;
			case KEY_RIGHT:
				moveLight(sph, moveStep * Vector3(1, 0, 0));
				break;
			case 'w':
			case 'W':
				moveLight(sph, moveStep * Vector3(0, 0, -1));
				break;
			case 's':
			case 'S':
				moveLight(sph, moveStep * Vector3(0, 0, 1));
				break;
		}
		sph.display();
	}

	endwin();
	return 0;
}


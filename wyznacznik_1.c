#include <stdio.h>

float tab_1[2][2] = { {1.0, 2.0}, {3.0, -1.0} };
float tab_2[4];

int size = (sizeof(tab_1) / sizeof(tab_1[0]));

int main() {
	int liczba1;
	int liczba2;
	int liczbaA;
	int liczbaB;

	for (int x = 0, index = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++, index++) {
			if (y = 0) {
				liczba1 = tab_1[x][y];
			}
		}
	}

}

#include <stdio.h>

float tab_1[2][2] = { {1.0, 2.0}, {3.0, -1.0} };
float tab_2[4];

int size = (sizeof(tab_1) / sizeof(tab_1[0]));

int main() {
	float wyznacznik;
	int index;

	for (int x = 0, index = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++, index++) {
			tab_2[index] = tab_1[x][y];
			printf("%f \n", tab_2[index]);
		}
	}

	wyznacznik = (tab_2[0] * tab_2[3]) - (tab_2[1] * tab_2[2]);
	printf("wyznacznik macierzy jest rowny: %f", wyznacznik);

}

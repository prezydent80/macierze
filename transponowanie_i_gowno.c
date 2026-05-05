#include <stdio.h>

int tab_1[2][2] = { {1,2}, {3,4} };
char buf[100];

int size = (sizeof(tab_1) / sizeof(tab_1[0]));

void read_from_stdin(char buf[]) {
	int znak;

	for (int i = 0; (znak = getchar()) != '\n'; buf[++i] = 0) {
		buf[i] = znak;
	}
}

int czy_cyfra(int znak) {
	return znak >= 48 && znak <= 57;
}

double text_to_num(char bufor[], int i) {
	double liczba = 0;

	while (czy_cyfra(bufor[i]) == 1) {
		liczba = 10 * liczba + (bufor[i] - '0');
		i++;
	}

	return liczba;
}



int del_spaces(char bufor[], int i) {
	while (bufor[i] == ' ' || bufor[i] == '\n' || bufor[i] == '\r' || bufor[i] == '\t') {
		i++;
	}
	return i;
}

int skip_num(char bufor[], int i) {
	if (bufor[i] == '-') {
		i++;
	}

	while (czy_cyfra(bufor[i]) == 1 || bufor[i] == '.') {
		i++;
	}

	return i;
}

int daj_element(int tab[], int x, int y, int kolumny) {
	int index = (kolumny * (x-1)) + (y-1);
	return tab[index];
}

int odwrot_daj_element(int tab[], int index) {

}

void transponuj(int *tab, int col) {
	int temp;
	int trans[2][2];
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			trans[2 - x][2 - y] = daj_element(tab, x, y, col);
		}
	}
}

//potrzebna tablica dynamiczna

void wypisz(int *tab[]) {
	int tab_1D[4];
	for (int x = 0, index = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++, index++) {
			tab_1D = tab[x][y];
		}
	}
}

int main() {
	int i = 0;
	int x;
	int y;

	printf("wpisz x potem y \n");

	read_from_stdin(buf);
	 i = del_spaces(buf, i);
	 x = text_to_num(buf, i);
	 i = skip_num(buf, i);
	 i = del_spaces(buf, i);
	 y = text_to_num(buf, i);

	
	
	int val = daj_element(&tab_1[0][0], x, y, 2);
	printf("%i", val);
}


#include <stdio.h>
#include <stdlib.h>


double** stworzMac(int n) {
	double** mac = (double**)calloc(n, sizeof(double*));
	if (mac == NULL) {
		printf("błąd alokacji \n");
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		mac[i] = (double*)calloc(n, sizeof(double));
		if (mac[i] == NULL) {
			printf("błąd alokacji \n");
			exit(1);
		}
	}
	return mac;
}

void freeMac(double** mac, int n) {
	for (int i = 0; i < n; i++) {
		free(mac[i]);
	}
	free (mac);
}

void minor(double** mac, double** podMac, int n, int rzad, int kol) {
	int row = 0;
	int col = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != rzad && j != kol) {
				podMac[row][col++] = mac[i][j];

				if (col == n - 1) {
					col = 0;
					row++;
				}
			}
		}
	}
}

double wyznacznik(double **mac, int n) {
	if (n == 1) {
		return mac[0][0];
	}
	if (n == 2) {
		return (mac[0][0] * mac[1][1] - mac[0][1] * mac[1][0]);
	}

	double det = 0.0;
	int znak = 1;

	double **podMac = stworzMac(n - 1);

	for (int i = 0; i < n; i++) {
		minor(mac, podMac, n, 0, i);
		det += znak * mac[0][i] * wyznacznik(podMac, n - 1);
		znak = -znak;
	}

	freeMac(podMac, n - 1);
	return det;
}

int main() {
	int n = 4;
	double MAC[4][4] = {
		{1.0, 2.0, 3.0, 4.0},
		{5.0, 6.0, 7.0, 8.0},
		{9.0, 10.0, 11.0, 12.0},
		{13.0, 14.0, 15.0, 16.0}
	};

	double** mac = stworzMac(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mac[i][j] = MAC[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%6.2lf ", mac[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	double det = wyznacznik(mac, n);
	printf("Wyznacznik = %f \n", det);

	freeMac(mac, n);

	return 0;

}

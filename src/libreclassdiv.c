#include <stdio.h>
// #include "libreclassdivconf.h"

#define MAINCROOM 30
#define SIDECROOM 20

int evaulatecompatibility(char carr1[], char carr2[], char carr3[], char carr4[], char carr5[]) {
	char compatcase;
	int sc1 = sizeof(carr1);
	int sc2 = sizeof(carr2);
	int sc3 = sizeof(carr3);
	int sc4 = sizeof(carr4);
	int sc5 = sizeof(carr5);

	if (SIDECROOM + MAINCROOM < sc1 + sc2 + sc3 + sc4 + sc5)
		compatcase = 99;

	if ((sc1 + sc3 < SIDECROOM && sc1 + sc3 < (MAINCROOM - sc5)) && (sc1 + sc4 < SIDECROOM) && (sc1 + sc4 < (MAINCROOM - sc5))) 
		compatcase = 0;
	else if (sc1 + sc3 < SIDECROOM && sc1 + sc3 < (MAINCROOM - sc5))
		compatcase = 1;
	else if (sc1 + sc4 < SIDECROOM && sc1 + sc4 < (MAINCROOM - sc5))
		compatcase = 2;
	else {
		compatcase = 99;
	}
	
	if (compatcase == 0) {
		if ((sc2 + sc3 < SIDECROOM && sc2 + sc3 < (MAINCROOM - sc5) && (sc2 + sc4 < SIDECROOM && sc2 + sc4 < (MAINCROOM - sc5))))
			compatcase = 0;
		else if (sc2 + sc3 < SIDECROOM && sc2 + sc3 < (MAINCROOM - sc5))
			compatcase = 2;
		else if (sc2 + sc4 < SIDECROOM && sc2 + sc4 < (MAINCROOM - sc5))
			compatcase = 1;
		else
			compatcase = 99;

	} else if (compatcase == 1) {
		if (sc2 + sc4 < SIDECROM && sc2 + sc4 < (MAINCROOM - sc5))
			compatcase = 1;
		else
			compatcase = 99;
	} else if (compatcase == 2) {
		if (sc2 + sc3 < SIDECROM && sc2 + sc3 < (MAINCROOM - sc5))
			compatcase = 2;
		else
			compatcase = 99;
	}

	return compatcase;
}

int main() {
	int maincroom[(MAINCROOM + 1)];
	int sidecroom[(SIDECROOM + 1)];
	int i;
	int ocroommain;
	char year1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char year2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char year3[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char year4[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char year5[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

	for (i = 1; i <= MAINCROOM; i++)
		maincroom[i] = i;
	for (i = 1; i <= SIDECROOM; i++)
		sidecroom[i] = i;
	
	printf("All week:");
	for (ocroommain= 0; ocroommain < sizeof(year5); ocroommain++) {
		printf(" 5%c in M%d,", year5[ocroommain], maincroom[ocroommain + 1]);
	}
	printf("\n");
}

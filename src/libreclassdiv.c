#include <stdio.h>
#include "libreclassdivconf.h"

int evaluatecompatibility(int sc1, int sc2, int sc3, int sc4, int sc5) {
	char compatcase;

	if (SIDECROOM + MAINCROOM < sc1 + sc2 + sc3 + sc4 + sc5) // If there are more classes than classrooms, it's incompatible.
		compatcase = 99;

	if ((sc1 + sc3 <= SIDECROOM && sc1 + sc3 <= (MAINCROOM - sc5)) && (sc1 + sc4 <= SIDECROOM) && (sc1 + sc4 <= (MAINCROOM - sc5))) 
		compatcase = 0;
	else if (sc1 + sc3 <= SIDECROOM && sc1 + sc3 <= (MAINCROOM - sc5))
		compatcase = 1;
	else if (sc1 + sc4 <= SIDECROOM && sc1 + sc4 <= (MAINCROOM - sc5))
		compatcase = 2;
	else {
		compatcase = 99;
	}
	
	if (compatcase == 0) {
		if ((sc2 + sc3 <= SIDECROOM && sc2 + sc3 <= (MAINCROOM - sc5) && (sc2 + sc4 <= SIDECROOM && sc2 + sc4 <= (MAINCROOM - sc5))))
			compatcase = 0;
		else if (sc2 + sc3 <= SIDECROOM && sc2 + sc3 <= (MAINCROOM - sc5))
			compatcase = 2;
		else if (sc2 + sc4 <= SIDECROOM && sc2 + sc4 <= (MAINCROOM - sc5))
			compatcase = 1;
		else
			compatcase = 99;

	} else if (compatcase == 1) {
		if (sc2 + sc4 <= SIDECROOM && sc2 + sc4 <= (MAINCROOM - sc5))
			compatcase = 1;
		else
			compatcase = 99;
	} else if (compatcase == 2) {
		if (sc2 + sc3 <= SIDECROOM && sc2 + sc3 <= (MAINCROOM - sc5))
			compatcase = 2;
		else
			compatcase = 99;
	}

	return compatcase; // The compatibility cases are: 0 (year 1 and year 3 will be inalternate days in the main and side building), 1 (year 1 and year 4 will be in alternate days in the main and side building), 2 (same as 0) and 99 (the classes are incompatible).

}

int assignclassyear5(char sec5[], int sc5, int maincroom[]) {
	int ocroommain;
	
	printf("All week:");
	for (ocroommain= 0; ocroommain < sc5; ocroommain++) {
		printf(" 5%c in M%d,", sec5[ocroommain], maincroom[ocroommain + 1]);
	}
	printf("\n");
	
	return ocroommain;
}

int main() {
	int maincroom[(MAINCROOM + 1)];
	int sidecroom[(SIDECROOM + 1)];
	int i;
	char year1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char year2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char year3[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char year4[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char year5[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	int sc1 = sizeof(year1);
	int sc2 = sizeof(year2);
	int sc3 = sizeof(year3);
	int sc4 = sizeof(year4);
	int sc5 = sizeof(year5);

	for (i = 1; i <= MAINCROOM; i++)
		maincroom[i] = i;
	for (i = 1; i <= SIDECROOM; i++)
		sidecroom[i] = i;
	
	int compatcase = evaluatecompatibility(sc1, sc2, sc3, sc4, sc5);
	switch (compatcase) {
		case 99:
			printf("Your classes and classrooms are incompatible with this algorithm.\n");
			break;
		case 0:
			printf("Your classes are compatible with the algorithm! Proceeding with class distribution.\n");
			break;
		case 1:
			printf("Your classes are compatible with the algorithm! Proceeding with class distribution.\n");
			break;
		case 2:
			printf("Your classes are compatible with the algorithm! Proceeding with class distribution.\n");
			break;
		default:
			printf("How did you get here.\n");
			break;
	}

}

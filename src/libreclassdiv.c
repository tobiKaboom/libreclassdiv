#include <stdio.h>#include <stdio.h>
#include "libreclassdivconf.h"

int ocroommain = 0;

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

int assignclassyear5(char sec5[], int sc5, int maincroom[], int maincroomsize) {
	printf("All week:");
	for (ocroommain = 0; ocroommain < sc5; ocroommain++) {
		printf(" 5%c in M%d,", sec5[ocroommain], maincroom[ocroommain]);
	}
	printf("\n\n");

	ocroommain = sc5; //The occupied classrooms are gonna be the same as the amount of classes in them.
}

int assignclassc1(char sec1[], int sec1size, char sec2[], int sec2size, char sec3[], int sec3size, char sec4[], int sec4size, int maincroom[], int sidecroom[]) {
	int maxclass;
	int i;

	if (sec1size > sec3size)
		maxclass = sec4size;
	else
		maxclass = sec1size;

	for (i = 0; i < maxclass; i++) {
		printf("Monday: 4^%c in classroom M%d and 1^%c in S%d\n", sec4[i], maincroom[ocroommain + i], sec1[i], sidecroom[i]);
		printf("Tuesday: 1^%c in classroom M%d and 4^%c in S%d\n", sec1[i], maincroom[ocroommain + i], sec4[i], sidecroom[i]);
		printf("Wednesday: 4^%c in classroom M%d and 1^%c in S%d\n", sec4[i], maincroom[ocroommain + i], sec1[i], sidecroom[i]);
		printf("Thursday: 1^%c in classroom M%d and 4^%c in S%d\n", sec1[i], maincroom[ocroommain + i], sec4[i], sidecroom[i]);
		printf("Friday: 4^%c in classroom M%d and 1^%c in S%d\n\n", sec4[i], maincroom[ocroommain + i], sec1[i], sidecroom[i]);

	}

}

int main() {
	int maincroom[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}; //Main building classroom names or numbers (can only be ints)
	int sidecroom[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; //Side building classroom names or numbers (can only be ints)
	int i;
	char year1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //Year 1 classes.
	char year2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //Year 2 classes.
	char year3[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //Year 3 classes.
	char year4[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //Year 4 classes.
	char year5[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //Year 5 classes.
	int sc1 = sizeof(year1) / sizeof(year1[0]); //Finds the true size of the array (same with the ones below)
        int sc2 = sizeof(year2) / sizeof(year2[0]);
	int sc3 = sizeof(year3) / sizeof(year3[0]);
	int sc4 = sizeof(year4) / sizeof(year4[0]);
	int sc5 = sizeof(year5) / sizeof(year5[0]);
	int n_maincroom = sizeof(maincroom) / sizeof(maincroom[0]);
	int n_sidecroom = sizeof(sidecroom) / sizeof(sidecroom[0]);

	int compatcase = evaluatecompatibility(sc1, sc2, sc3, sc4, sc5);
	switch (compatcase) {
		case 99:
			printf("Your classes and classrooms are incompatible with this algorithm.\n\n");
			break;
		case 0:
			printf("Your classes are compatible with the algorithm! Proceeding with class distribution.\n\n");
			assignclassyear5(year5, sc5, maincroom, n_maincroom);
			assignclassc1(year1, sc1, year2, sc2, year3, sc3, year4, sc4, maincroom, sidecroom);
			break;
		case 1:
			printf("Your classes are compatible with the algorithm! Proceeding with class distribution.\n\n");
			break;
		case 2:
			printf("Your classes are compatible with the algorithm! Proceeding with class distribution.\n\n");
			break;
		default:
			printf("How did you get here.\n"); //Prints only if evaluatecompatibility returns an invalid compatcase.
			break;
	}

}
	}

}

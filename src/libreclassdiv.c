
/*Original author: tobiKaboom on GitHub and GitLab.
 *This code is licensed under the Creative Commons Attribution
 *Same Agreement 4.0 License.
 *
 * THIS COMMENT MUST BE INCLUDED WITH EVERY DERIVATIVE WORK. */

#include <stdio.h>
#include "libreclassdivconf.h"

int ocroommain = 0;
int ocroomside = 0;

int evaluatecompatibility(int sc1, int sc2, int sc3, int sc4, int sc5) { // Evaluates compatibility with your classes and the amount of classrooms.
	char compatcase;

	if (SIDECROOM + MAINCROOM < sc1 + sc2 + sc3 + sc4 + sc5) // If there are more classes than classrooms, it's incompatible.
		compatcase = 99;

	if ((sc1 + sc3 <= SIDECROOM && sc1 + sc3 <= (MAINCROOM - sc5)) && (sc1 + sc4 <= SIDECROOM) && (sc1 + sc4 <= (MAINCROOM - sc5))) // Check which classes can be in the same building.
		compatcase = 0;
	else if (sc1 + sc3 <= SIDECROOM && sc1 + sc3 <= (MAINCROOM - sc5))
		compatcase = 1;
	else if (sc1 + sc4 <= SIDECROOM && sc1 + sc4 <= (MAINCROOM - sc5))
		compatcase = 2;
	else {
		compatcase = 99;
	}
	
	if (compatcase == 0) { // Continuation of the if-else clause from earlier.
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

int assignclassyear5(char sec5[], int sc5, int maincroom[], int maincroomsize) { // Assigns classrooms to the fifth year classes.
	printf("All week:");
	for (ocroommain = 0; ocroommain < sc5; ocroommain++) {
		printf(" 5%c in M%d,", sec5[ocroommain], maincroom[ocroommain]);
	}
	printf("\n\n");

	ocroommain = sc5;
}

void assignclassc1(char sec1[], int sec1size, char sec2[], int sec2size, char sec3[], int sec3size, char sec4[], int sec4size, int maincroom[], int sidecroom[]) { // Assigns clasrooms to every other years' classes if the compatibility case is 1.
	int maxclass;
	int i;

	// Distribution of classes in year 1 and 4.

	if (sec1size > sec4size) 
		maxclass = sec4size
	else if (sec1size < sec4size) 
		maxclass = sec1size;
	else
		maxclass = sec1size;

	for (i = 0; i < maxclass; i++) {
		printf("Monday: 4^%c in classroom M%d and 1^%c in S%d\n", sec4[i], maincroom[ocroommain + i], sec1[i], sidecroom[i]);
		printf("Tuesday: 4^%c in classroom M%d and 1^%c in S%d\n", sec4[i], maincroom[ocroommain + i], sec1[i], sidecroom[i]);
		printf("Wednesday: 4^%c in classroom M%d and 1^%c in S%d\n", sec4[i], maincroom[ocroommain + i], sec1[i], sidecroom[i]);
		printf("Thursday: 1^%c in classroom M%d and 4^%c in S%d\n", sec1[i], maincroom[ocroommain + i], sec4[i], sidecroom[i]);
		printf("Friday: 1^%c in classroom M%d and 4^%c in S%d\n\n", sec1[i], maincroom[ocroommain + i], sec4[i], sidecroom[i]);

	}

	// Distribution of classes in year 2 and 3.

	ocroommain = ocroommain + i;
	ocroomside = ocroomside + i;

	if (sec2size > sec3size)
		maxclass = sec3size;
	else if (sec2size < sec3size)
		maxclass = sec2size;
	else 
		maxclass = sec2size;

	for (i = 0; i < maxclass; i++) {
		printf("Monday: 3^%c in classroom M%d and 2^%c in S%d\n", sec3[i], maincroom[ocroommain + i], sec2[i], sidecroom[ocroomside + i]);
		printf("Tuesday: 3^%c in classroom M%d and 2^%c in S%d\n", sec3[i], maincroom[ocroommain + i], sec2[i], sidecroom[ocroomside + i]);
		printf("Wednesday: 3^%c in classroom M%d and 2^%c in S%d\n", sec3[i], maincroom[ocroommain + i], sec2[i], sidecroom[ocroomside + i]);
		printf("Thursday: 2^%c in classroom M%d and 3^%c in S%d\n", sec2[i], maincroom[ocroommain + i], sec3[i], sidecroom[ocroomside + i]);
		printf("Friday: 2^%c in classroom M%d and 3^%c in S%d\n\n", sec1[i], maincroom[ocroommain + i], sec3[i], sidecroom[ocroomside + i]);

	}
}

void assignclassc2(char sec1[], int sec1size, char sec2[], int sec2size, char sec3[], int sec3size, char sec4[], int sec4size, int maincroom[], int sidecroom[]) { // Assigns classrooms to every other years' classes if the compatibility case is 2 or 0.
	int maxclass;
	int i;

	// Distribution of classes in year 1 and 3.

	if (sec1size > sec3size)
		maxclass = sec3size;
	else
		maxclass = sec1size;

	for (i = 0; i < maxclass; i++) {
		printf("Monday: 3^%c in classroom M%d and 1^%c in S%d\n", sec3[i], maincroom[ocroommain + i], sec1[i], sidecroom[i]);
		printf("Tuesday: 3^%c in classroom M%d and 1^%c in S%d\n", sec3[i], maincroom[ocroommain + i], sec1[i], sidecroom[i]);
		printf("Wednesday: 3^%c in classroom M%d and 1^%c in S%d\n", sec3[i], maincroom[ocroommain + i], sec1[i], sidecroom[i]);
		printf("Thursday: 1^%c in classroom M%d and 3^%c in S%d\n", sec1[i], maincroom[ocroommain + i], sec3[i], sidecroom[i]);
		printf("Friday: 1^%c in classroom M%d and 3^%c in S%d\n\n", sec1[i], maincroom[ocroommain + i], sec3[i], sidecroom[i]);

	}

	// Distribution of classes in year 2 and 4.

	ocroommain = ocroommain + i;
	ocroomside = ocroomside + i;

	if (sec2size > sec4size)
		maxclass = sec4size;
	else
		maxclass = sec2size;

	for (i = 0; i < maxclass; i++) {
		printf("Monday: 4^%c in classroom M%d and 2^%c in S%d\n", sec4[i], maincroom[ocroommain + i], sec2[i], sidecroom[ocroomside + i]);
		printf("Tuesday: 4^%c in classroom M%d and 2^%c in S%d\n", sec4[i], maincroom[ocroommain + i], sec2[i], sidecroom[ocroomside + i]);
		printf("Wednesday: 4^%c in classroom M%d and 2^%c in S%d\n", sec4[i], maincroom[ocroommain + i], sec2[i], sidecroom[ocroomside + i]);
		printf("Thursday: 2^%c in classroom M%d and 4^%c in S%d\n", sec2[i], maincroom[ocroommain + i], sec4[i], sidecroom[ocroomside + i]);
		printf("Friday: 2^%c in classroom M%d and 4^%c in S%d\n\n", sec2[i], maincroom[ocroommain + i], sec4[i], sidecroom[ocroomside + i]);

	}
}

int main() {
	int maincroom[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}; //Main building classroom names or numbers (can only be ints)
	int sidecroom[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; //Side building classroom names or numbers (can only be ints)
	int i;
	char year1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //Year 1 classes.
	char year2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'}; //Year 2 classes.
	char year3[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //Year 3 classes.
	char year4[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'}; //Year 4 classes.
	char year5[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //Year 5 classes.
	int sc1 = sizeof(year1) / sizeof(year1[0]);
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
			assignclassyear5(year5, sc5, maincroom, n_maincroom);
			assignclassc1(year1, sc1, year2, sc2, year3, sc3, year4, sc4, maincroom, sidecroom);
			break;
		case 2:
			printf("Your classes are compatible with the algorithm! Proceeding with class distribution.\n\n");
			assignclassyear5(year5, sc5, maincroom, n_maincroom);
			assignclassc2(year1, sc1, year2, sc2, year3, sc3, year4, sc4, maincroom, sidecroom);
			break;
		default:
			printf("How did you get here.\n"); //Prints only if evaluatecompatibility returns an invalid compatcase.
			break;
	}

}

//Cipher Lab
//Uses substitution cipher to encode strings.
//Palomar ID: 008372648
//Cody Young

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void processFile(char *congress);
void cipher(int shift, char *congress);

FILE *finput, *foutput;

int main(void) {
	int i;
	static char congress[1000];
	if (!(finput = fopen("congress.txt", "r"))) {
		printf("Error: Cannot open file for input.");
		exit(-1);
	}

	processFile(congress);
	cipher(1, congress);
	printf("%s", congress);
	
	return(0);

}

void processFile(char *congress) {
	int i;
	
	for (i = 0; i < 1000; ++i) {
		fscanf(finput, "%c", &congress[i]);
		if (islower(congress[i])) {
			congress[i] = toupper(congress[i]);
		}
		
	}
	
	for (i = 0; i < 1000; ++i) {

	}
}

void cipher(int shift, char *congress) {
	int i;

	for (i = 0; i < 1000; ++i) {
		if (congress[i] == 'Z') {
			congress[i] += shift - 24;
		}
		else {
			congress[i] += shift;
		}
	}
}

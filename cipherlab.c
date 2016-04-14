//Cipher Lab
//Uses substitution cipher to encode strings.
//Palomar ID: 008372648
//Cody Young

void processFile(char *congress);
void cipher(int shift, char *congress);
char outputfile(char *congress);

FILE *finput, *foutput;

int main(void) {
	int i;
	static char congress[272];

	if (!(finput = fopen("congress.txt", "r"))) {
		printf("Error: Cannot open file for input.");
		exit(-1);
	}

	processFile(congress);
	cipher(1, congress);
	outputfile(congress);
	return(0);

}

void processFile(char *congress) {
	int i;
	
	for (i = 0; i < 272; ++i) {
		fscanf(finput, "%c", &congress[i]);
		if (islower(congress[i])) {
			congress[i] = toupper(congress[i]);
		}
	}
}

void cipher(int shift, char *congress) {
	int i;

	for (i = 0; i < 272; ++i) {
		if (congress[i] == 'Z') {
			congress[i] += shift - 24;
		}
		else {
			congress[i] += shift;
		}
	}

}

char outputfile(char *congress) {
	int i;
	
	for (i = 0; i < 272; ++i) {
		if (congress[i] >= 65 && congress[i] <= 90) {
			printf("%c", congress[i]);
		}
	}

}

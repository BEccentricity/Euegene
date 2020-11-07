#include "Text.h"

const int ERROR = 404;

void fill_strings (char* Data, size_t Length, struct c_string* StrNum, int* Nlines) {

	for (size_t i = 0; i < Length; ++i) {
		if (Data[i] != '\n') {
			StrNum[*Nlines].Len += 1;
		} else {
			StrNum[*Nlines].Len += 1;
			if (StrNum[*Nlines].Len <= 1) {
				StrNum[*Nlines].Len = 0;
				continue;
			}

			StrNum[*Nlines].Str = &(Data[i - StrNum[*Nlines].Len + 1]);
			StrNum[*Nlines].Str[StrNum[*Nlines].Len - 1] = '\0';
			++(*Nlines);
		}
	}
}


int str_count (char* Data, size_t Length) {
	int StrCnt = 0;
	for (long unsigned int i = 0; i < Length; ++i) {
		if (Data[i] == '\n') {
			++StrCnt;
		}
	}
	return StrCnt;

}

char* read_properly (size_t* Length, const char* Path) {
	struct stat buff = {};
	if (stat (Path, &buff) < 0) {
		fprintf (stderr, "STAT FAIL!! Input file doesn`t exist\n");
		exit (ERROR);
	}

	*Length = buff.st_size;

	FILE* file = fopen (Path, "r");
	assert (file);

	char* Data = (char*) calloc(*Length , sizeof(char));
	assert (Data);
	fread (Data, *Length, sizeof(char), file);
	fclose (file);
	return Data;
}

void print_sort (struct c_string* StrNum, int Nlines, const char* Path) {
	FILE* Out = fopen (Path, "a");
	if (!Out) {
		fprintf (stderr, "FAIL!! Ouput file doesn`t exist\n");
		exit (ERROR);

	}

	for (int j = 0; j < Nlines; j++) {
		fprintf (Out, "%d %s\n", j, StrNum[j].Str);
	}

	fclose (Out);
	printf ("\n\n");
}
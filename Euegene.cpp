#include "Text.h"
#include "sort.h"
#include "UnitTest.h"

int main(int argc, char* argv[]) {

	printf("Onegin - Alphabetically sorting text\n");
	printf( "ver 1.337 (c) Eccentricity\n\n");

	UnitTests ();

	int Nlines = 0;
	int StrCnt = 0;
	size_t Length = 0;
	const char* PathIn = argv[1];
	const char* PathOut = argv[2];

	char* Data = read_properly (&Length, PathIn);
	StrCnt = str_count(Data, Length);
	struct c_string* StrNum = (c_string*) calloc(StrCnt, sizeof(StrNum[0]));
	assert (StrNum);

	fill_strings (Data, Length, StrNum, &Nlines);

	str_sort (StrNum, 0, Nlines - 1, &str_compare_drct);
	print_sort (StrNum, Nlines, PathOut);

	str_sort (StrNum, 0, Nlines - 1, &str_compare_rvs);
	print_sort (StrNum, Nlines, PathOut);

	free (Data);
	printf ("\nYAhoooo\n");
	return 0;
}

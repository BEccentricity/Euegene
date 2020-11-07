#include "UnitTest.h"

void UnitTests () {

	char TestNum[6][12] = {
			"Test1.txt",
			"Res1.txt",
			"Test2.txt",
			"Res2.txt",
			"Test3.txt",
			"Res3.txt",
			};
	int Flag = 1;

	for (int i = 0; i < 3; ++i) {
		Flag = 1;
		int Nlines = 0;
		int StrCnt = 0;
		size_t Length = 0;
		size_t ResL = 0;
		int Sz = 0;
		int k = 0;
		int LetterPointer = 0;
		int StrPointer = 0;
 
		char* Data = read_properly (&Length, TestNum[2*i]);
		StrCnt = str_count(Data, Length) + 1;
		struct c_string* StrNum = (c_string*) calloc(StrCnt, sizeof(StrNum[0]));
		assert (StrNum);

		char* Res = read_properly (&ResL, TestNum[2*i + 1]);
		
		for (size_t j = 0; j < ResL; ++j) {
			if (Res[j] == '\n') {
				Res[j] = '\0';
			}
		}

		fill_strings (Data, Length, StrNum, &Nlines);

		str_sort (StrNum, 0, Nlines - 1, &str_compare_drct);

		if (StrNum[k].Str == 0 && ResL == 0) {
			printf ("Test %d ok\n", i + 1);
			free (StrNum);
			free (Data);
			free (Res);
			continue;
		} else {
			if (StrNum[k].Str == 0)
				printf("Test %d BAD\n", i + 1);
		}

		while (k != Nlines) {
			Sz = Sz + 1 + strlen (StrNum[k].Str);
			++k;
		}

		k = 0;
		StrPointer = 0;
		LetterPointer = 0;
		while (StrPointer != Nlines) {
			if (k > Sz) {
				Flag = 0;
				break;
			}

			if (Res[k] != StrNum[StrPointer].Str[LetterPointer]) {
				Flag = 0;
				break;
			}
			++k;
			++LetterPointer;
			if (LetterPointer == StrNum[StrPointer].Len) {
				++StrPointer;
				LetterPointer = 0;
			}
		}

		if (!Flag) {
			printf ("%d Test %d BAD.\nDirect sort is false\n%d symbol: (%c)  expected,\nbut %d symbol: (%c)\n", Sz, i +1, k, Res[k], k, StrNum->Str[k]);
			free (StrNum);
			free (Data);
			free (Res);
			continue;
		}
		str_sort (StrNum, 0, Nlines - 1, &str_compare_rvs);

		StrPointer = 0;
		LetterPointer = 0;
		while (StrPointer != Nlines) {
			if (k - Sz > Sz) {
				Flag = 0;
				break;
			}

			if (Res[k] != StrNum[StrPointer].Str[LetterPointer]) {
				Flag = 0;
				break;
			}
			++k;
			++LetterPointer;
			if (LetterPointer == StrNum[StrPointer].Len) {
				++StrPointer;
				LetterPointer = 0;
			}
		}

		if (!Flag) {
			printf ("Test %d BAD.\nRevers sort is false\n %d symbol: %c -> expected,\nbut %d symbol: %c\n", i + 1, k, Res[k], k, StrNum->Str[k]);
			free (StrNum);
			free (Data);
			free (Res);
			continue;
		}

		free (StrNum);
		free (Data);
		free (Res);
		printf ("Test %d ok\n", i + 1);
	}
}

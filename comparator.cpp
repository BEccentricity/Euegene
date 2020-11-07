#include "comparator.h"

int str_compare_drct (struct c_string* a, struct c_string* b) {
	int aPointer = 0;
	int bPointer = 0;
	int Diff = 0;
	while (aPointer < a->Len - 1 && bPointer < b->Len - 1) {
		if (!isalpha (a->Str[aPointer])) {
			++aPointer;
			continue;
		}

		if (!isalpha (b->Str[bPointer])) {
			++bPointer;
			continue;
		}

		Diff = a->Str[aPointer] - b->Str[bPointer];
		if (Diff != 0) {
			return Diff;
		}
		++aPointer;
		++bPointer;
	}

	return b->Len - a->Len;
}

int str_compare_rvs (struct c_string* a, struct c_string* b) {
	int aPointer = a->Len - 1;
	int bPointer = b->Len - 1;
	int Diff = 0;
	while (aPointer >= 0 && bPointer >= 0) {
		if (!isalpha (a->Str[aPointer])) {
			--aPointer;
			continue;
		}

		if (!isalpha (b->Str[bPointer])) {
			--bPointer;
			continue;
		}

		Diff = a->Str[aPointer] - b->Str[bPointer];
		if (Diff != 0) {
			return Diff;
		}
		--aPointer;
		--bPointer;
	}

	return b->Len - a->Len;
}
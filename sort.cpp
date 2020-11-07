#include "sort.h"

void str_sort (struct c_string* StrNum, int L, int R, int (*cmp)(struct c_string*, struct c_string*)) {
	int Mem = 0;
	int Left = L;
	int Right = R;
	struct c_string Pivot = {StrNum[L].Str, StrNum[L].Len};

	while (L < R) {

		while ((*cmp) (&Pivot, &StrNum[R]) <= 0 && L < R) {
			--R;
		}
		if(L != R) {
			StrNum[L].Str = StrNum[R].Str;
			StrNum[L].Len = StrNum[R].Len;
			++L;
		}

		while ((*cmp) (&Pivot, &StrNum[L]) >= 0 && L < R) {
			++L;
		}
		if (L != R) {
			StrNum[R].Str = StrNum[L].Str;
			StrNum[R].Len = StrNum[L].Len;
			--R;
		}

	}

	Mem = L;
	StrNum[L].Str = Pivot.Str;
	StrNum[L].Len = Pivot.Len;
	L = Left;
	R = Right;
	if (L < Mem) {
		str_sort (StrNum, L, Mem - 1, cmp);
	}
	if (R > Mem) {
		str_sort (StrNum, Mem + 1, R, cmp);
	}
}
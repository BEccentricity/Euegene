#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>
#include "struct.h"
#include "comparator.h"
#pragma once

void str_sort (struct c_string* StrNum, int L, int R, int (*cmp)(struct c_string*, struct c_string*));
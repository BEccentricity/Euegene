#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>
#include "struct.h"
#pragma once
extern const int ERROR;


void fill_strings (char* Data, size_t Length, struct c_string* StrNum, int* Nlines);

int str_count (char* Data, size_t Length);

char* read_properly (size_t* Length, const char* Path);

void print_sort (struct c_string* StrNum, int Nlines, const char* Path);
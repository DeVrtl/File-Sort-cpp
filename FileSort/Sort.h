#pragma once

enum SortMode
{
	ASC = 1,
	DESC
};

namespace Sort
{
    void Sort(char** pointeStringArray, int length, SortMode mode);
    void Sort(double* pointerDoubleArray, int length, SortMode mode);
    void Sort(int* pointerIntArray, int length, SortMode mode);
}
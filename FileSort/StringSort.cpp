#include <algorithm>
#include "Sort.h"

namespace Sort 
{
    bool CompareStringsAscending(const char* a, const char* b)
    {
        return strcmp(a, b) < 0;
    }

    bool CompareStringsDescending(const char* a, const char* b)
    {
        return strcmp(a, b) > 0;
    }

    void Sort(char** pointerStringArray, int length, SortMode mode)
    {
        if (mode == ASC)
        {
            std::sort(pointerStringArray, pointerStringArray + length, CompareStringsAscending);
        }
        else if (mode == DESC)
        {
            std::sort(pointerStringArray, pointerStringArray + length, CompareStringsDescending);
        }
    }
}
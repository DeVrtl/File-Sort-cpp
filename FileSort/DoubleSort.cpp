#include <algorithm>
#include "Sort.h"

namespace Sort 
{
	void Sort(double* pointerDoubleArray, int length, SortMode mode) 
	{
        if (mode == ASC)
        {
            std::sort(pointerDoubleArray, pointerDoubleArray + length);
        }
        else if (mode == DESC)
        {
            std::sort(pointerDoubleArray, pointerDoubleArray + length, std::greater<double>());
        }
	}
}
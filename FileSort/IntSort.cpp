#include <algorithm>
#include "Sort.h"

namespace Sort
{
	void Sort(int* pointerIntArray, int length, SortMode mode)
	{
        if (mode == ASC)
        {
            std::sort(pointerIntArray, pointerIntArray + length);
        }
        else if (mode == DESC)
        {
            std::sort(pointerIntArray, pointerIntArray + length, std::greater<int>());
        }
	}
}
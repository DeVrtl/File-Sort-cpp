#include "storage.h"
#include <iostream>

namespace storage
{
    Storage* Allocate(int initialCapacity)
    {
        if (initialCapacity <= 0)
        {
            return nullptr;  
        }

        Storage* pointerCount = new Storage;
        pointerCount->count = 0;
        pointerCount->allocated = initialCapacity;
        pointerCount->pointerChars = new char* [initialCapacity];

        return pointerCount;

    }

    void Free(Storage* pointerCount)
    {
        if (pointerCount)
        {
            for (int i = 0; i < pointerCount->count; ++i)
            {
                delete[] pointerCount->pointerChars[i];
            }

            delete[] pointerCount->pointerChars;

            delete pointerCount;
        }
    }

    void AddString(Storage& pointerContent, char* pointerChars)
    {
        if (pointerContent.count == pointerContent.allocated)
        {
            int newAllocated = pointerContent.allocated * 1.5;
            char** newPointerChars = (char**)realloc(pointerContent.pointerChars, newAllocated * sizeof(char*));

            if (!newPointerChars)
            {
                std::cout << "Error" << std::endl;

                Free(&pointerContent);

                pointerContent.pointerChars = nullptr;

                return;
            }

            pointerContent.pointerChars = newPointerChars;
            pointerContent.allocated = newAllocated;
        }

        pointerContent.pointerChars[pointerContent.count] = pointerChars;
        pointerContent.count++;
    }
}
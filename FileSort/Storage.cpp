#include "storage.h"

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

    void AddString(Storage& pointerContent, const char* pointerChars)
    {
        
    }
}
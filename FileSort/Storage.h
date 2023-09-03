#pragma once

namespace storage
{
    struct Storage
    {
        int count;
        int allocated;
        char** pointerChars;
    };

    Storage* Allocate(int initialCapacity);
    void Free(Storage* pointerCount);
    void AddString(Storage& pointerContent, char* pointerChars);
}
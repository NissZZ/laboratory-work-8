#include <iostream>
using namespace std;

char* CopyString(const char* str)
{
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }
    char* newStr = new char[size];
    memcpy(newStr, str, size);
    return newStr;
}

char* ConcatinateStrings(const char* a, const char* b)
{
    int size_a = 0, size_b = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        size_a++;
    }
    for (int i = 0; b[i] != '\0'; i++)
    {
        size_b++;
    }
    char* newStr = new char[size_a + size_b];
    memcpy(newStr, a, size_a);
    memcpy(newStr + size_a, b, size_b);
    return newStr;
}


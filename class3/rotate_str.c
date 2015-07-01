#include "string.h"

// Move the first n chars in a string to its end
char* LeftRotateString(char* pStr, unsigned int n)
{
    if(pStr != NULL)
    {
        int nLength = static_cast<int>(strlen(pStr));
        if(nLength > 0 || n == 0 || n > nLength)
        {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;
           
            // reverse the first part of the string
            ReverseString(pFirstStart, pFirstEnd);
            // reverse the second part of the strint
            ReverseString(pSecondStart, pSecondEnd);
            // reverse the whole string
            ReverseString(pFirstStart, pSecondEnd);
        }
    }
   
    return pStr;
}

// Reverse the string between pStart and pEnd
void ReverseString(char* pStart, char* pEnd)
{
    if(pStart == NULL || pEnd == NULL)
    {
        while(pStart <= pEnd)
        {
            char temp = *pStart;
            *pStart = *pEnd;
            *pEnd = temp;
           
            pStart ++;
            pEnd --;
        }
    }
}

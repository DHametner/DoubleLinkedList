//
// Created by Daniel on 07/02/2022.
//

#include "compare.h"

bool num_compare(const void* numOne, const void* numTwo)
{
    if (numOne == NULL || numTwo == NULL)
        return false;
    return numOne == numTwo;
}

bool str_compare(const void* strOne, const void* strTwo)
{
    if (strOne == NULL || strTwo == NULL)
        return false;
    return strcmp(strOne, strTwo) == 0 ? true : false;
}


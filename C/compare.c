//
// Created by Daniel on 07/02/2022.
//

#include "compare.h"

bool num_compare(const void* num1, const void* num2)
{
    if(num1 == NULL || num2 == NULL)
        return false;
    return num1 == num2;
}

bool str_compare(const void* str1, const void* str2)
{
    if(str1 == NULL || str2 == NULL)
        return false;
    return strcmp(str1, str2) == 0 ? true : false;
}


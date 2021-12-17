#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

bool all_of(int32_t *array, size_t length, int32_t value);

bool any_of(int32_t *array, size_t length, int32_t value);

bool none_of(int32_t *array, size_t length, int32_t value);

size_t count(int32_t *array, size_t length, int32_t value);

int main()
{
    int32_t array[] = {3, 1, 4, 1, 5, 9, 2, 6};
    size_t length = 8;

    printf("all_of: %d\n", all_of(array, length, 5));
    printf("any_of: %d\n", any_of(array, length, 5));
    printf("none_of: %d\n", none_of(array, length, 5));
    printf("count of 1: %lu", count(array, length, 1));

    return 0;
}


bool all_of(int32_t *array, size_t length, int32_t value)
{
    if (array == NULL)
    {
        return false;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] != value)
        {
            return false;
        }
    }

    return true;
}

bool any_of(int32_t *array, size_t length, int32_t value)
{
    if (array == NULL)
    {
        return false;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            return true;
        }
    }

    return false;
}

bool none_of(int32_t *array, size_t length, int32_t value)
{
    if (array == NULL)
    {
        return false;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            return false;
        }
    }

    return true;
}

size_t count(int32_t *array, size_t length, int32_t value)
{
    if (array == NULL)
    {
        return 0;
    }

    size_t counter = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            counter++;
        }
    }

    return counter;
}

int32_t *inclusive_scan(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        return NULL;
    }

    int32_t *result = (int32_t *)malloc(sizeof(int32_t) * length);

    result[0] = array[0];

    for (size_t i = 1; i < length; i++)
    {
        result[i] = result[i - 1] + array[i];
    }

    return result;
}
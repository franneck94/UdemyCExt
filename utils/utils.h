#ifndef UTILS_H
#define UTILS_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PI_F32 3.14159265358979311600
#define PI_F64 3.14159265358979311600F

void print_int8_array(const int8_t *const array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%d, ", array[i]);
    }

    printf("%d\n", array[length - 1]);
}

void print_int32_array(const int32_t *const array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%d, ", array[i]);
    }

    printf("%d\n", array[length - 1]);
}

void print_uint8_array(const uint8_t *const array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%u, ", array[i]);
    }

    printf("%u\n", array[length - 1]);
}

void print_uint32_array(const uint32_t *const array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%u, ", array[i]);
    }

    printf("%u\n", array[length - 1]);
}

void print_float_array(const float *const array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%f, ", array[i]);
    }

    printf("%f\n", array[length - 1]);
}

void print_double_array(const double *const array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%lf, ", array[i]);
    }

    printf("%lf\n", array[length - 1]);
}

void clear_console()
{
#if defined _WIN32
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#else
    system("clear");
#endif
}


void sleep_console()
{
    int pollingDelay = 100;

#ifdef _WIN32
    Sleep(pollingDelay);
#else
    usleep(pollingDelay * 1000);
#endif
}

#endif /* UTILS_H */

#include <stdint.h>
#include <stdio.h>

uint32_t recursive_sum(uint32_t lower_value, uint32_t upper_value);

uint32_t recursive_product(uint32_t lower_value, uint32_t upper_value);

int main()
{
    uint32_t lower_value = 3;
    uint32_t upper_value = 5;

    printf("recursive_sum: %u\n", recursive_sum(lower_value, upper_value));
    printf("recursive_product: %u\n", recursive_product(lower_value, upper_value));

    return 0;
}

uint32_t recursive_sum(uint32_t lower_value, uint32_t upper_value)
{
    if (lower_value <= upper_value)
    {
        return lower_value + recursive_sum(lower_value + 1, upper_value);
    }

    return 0;
}

uint32_t recursive_product(uint32_t lower_value, uint32_t upper_value)
{
    if (lower_value <= upper_value)
    {
        return lower_value * recursive_product(lower_value + 1, upper_value);
    }

    return 1;
}

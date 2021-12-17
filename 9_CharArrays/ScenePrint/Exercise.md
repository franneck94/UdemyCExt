# Exercise

Implement the following functions:

```cpp
bool ...
```

- ...
  - ...

Note: Make sure that the input pointer is valid.

## Main Function

```cpp
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

#include "AdFunctions.h"

int main()
{
    printf("Create the properties of a vehicle.\n");

    float speed_mps;
    printf("Speed in m/s: ");
    scanf("%f", &speed_mps);

    float pos_m;
    printf("Distance in m: ");
    scanf("%f", &pos_m);

    uint32_t lane_idx;
    printf("Lane (1=Right, 2=Center, 3=Left): ");
    scanf("%u", &lane_idx);

    while (true)
    {
        clear_console();

        print_scene(speed_mps, pos_m, lane_idx);

        get_user_input(&speed_mps, &lane_idx);
    }

    return 0;
}
```
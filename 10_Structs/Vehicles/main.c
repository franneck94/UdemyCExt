#include <stdio.h>
#include <string.h>

#include "AdFunctions.h"
#include "AdTypes.h"

int main()
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    print_scene(&ego_vehicle, &vehicles);

    printf("Compute forward (1sec)?: ");
    char Input;
    scanf("%c", &Input);

    while (Input == 'y')
    {
        compute_future_state(&ego_vehicle, &vehicles, 1);
        print_scene(&ego_vehicle, &vehicles);

        printf("Compute forward (1sec)?: ");
        scanf("%c", &Input);
    }

    return 0;
}
#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>

#include "AdTypes.h"

float kph_to_mps(const float kph);

float mps_to_kmh(const float mps);

void init_ego_vehicle(VehicleType *vehicle);

void init_vehicles(NeighborVehiclesType *vehicles);

void print_vehicle(const VehicleType *vehicle);

void print_neighbor_vehicles(const NeighborVehiclesType *vehicles);

void print_scene(const VehicleType *vehicle, const NeighborVehiclesType *vehicles);

void print_vehicle_speed(const VehicleType *vehicle, const char *name);

void compute_future_distance(VehicleType *vehicle, const float ego_driven_distance, const float seconds);

void compute_future_state(const VehicleType *vehicle, NeighborVehiclesType *vehicles, const float seconds);

void longitudinal_control(const VehicleType *front_vehicle, VehicleType *ego_vehicle);

#endif

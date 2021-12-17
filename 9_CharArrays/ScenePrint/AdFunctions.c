#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "AdFunctions.h"

#include "utils.h"

void print_scene(float speed_mps, float pos_m, uint32_t lane_idx)
{
    printf("\n\n    \t  L    C    R  \n");

    const int32_t offset_m = 20;

    for (int32_t i = 100; i >= -100; i -= offset_m)
    {
        char left_string[] = "   ";
        char center_string[] = "   ";
        char right_string[] = "   ";

        switch (lane_idx)
        {
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            if ((pos_m <= i) && (pos_m > (i - offset_m)))
            {
                strncpy(left_string, " V ", 4);
            }
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            if ((pos_m <= i) && (pos_m > (i - offset_m)))
            {
                strncpy(center_string, " V ", 4);
            }
            break;
        }
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            if ((pos_m <= i) && (pos_m > (i - offset_m)))
            {
                strncpy(left_string, " V ", 4);
            }
            break;
        }
        default:
        {
            break;
        }
        }

        printf("%d\t|%s|%s|%s|\n", i, left_string, center_string, right_string);
    }

    printf("\n");
}

void get_user_input(float *speed_mps, uint32_t *lane_idx)
{
    printf("\n");
    char longitudinal_action;
    printf("LongitudinalAction (w=Increase, s=Decrease): ");
    scanf(" %c", &longitudinal_action);
    printf("\n");
    char lateral_action;
    printf("LateralAction (a=Left, d=Right): ");
    scanf(" %c", &lateral_action);

    handle_lateral_user_inpur(lane_idx, lateral_action);
    handle_longitudinal_user_inpur(speed_mps, longitudinal_action);
}

void handle_lateral_user_inpur(uint32_t *lane_idx, char lateral_action)
{
    switch (lateral_action)
    {
    case LATERAL_ACTION_LEFT:
    {
        switch (*lane_idx)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            return;
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            *lane_idx = LANE_ASSOCIATION_TYPE_LEFT;
            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            *lane_idx = LANE_ASSOCIATION_TYPE_CENTER;
            break;
        }
        case LANE_ASSOCIATION_TYPE_NONE:
        {
            return;
            break;
        }
        }
        break;
    }
    case LATERAL_ACTION_RIGHT:
    {
        switch (*lane_idx)
        {
        case LANE_ASSOCIATION_TYPE_LEFT:
        {
            *lane_idx = LANE_ASSOCIATION_TYPE_CENTER;
            break;
        }
        case LANE_ASSOCIATION_TYPE_CENTER:
        {
            *lane_idx = LANE_ASSOCIATION_TYPE_RIGHT;

            break;
        }
        case LANE_ASSOCIATION_TYPE_RIGHT:
        {
            return;
            break;
        }
        case LANE_ASSOCIATION_TYPE_NONE:
        {
            return;
            break;
        }
        }
        break;
    }
    case LATERAL_ACTION_NONE:
    {
        return;
        break;
    }
    }
}

void handle_longitudinal_user_inpur(float *speed_mps, char longitudinal_action)
{
    switch (longitudinal_action)
    {
    case LONGITUDINAL_ACTION_ACCELERATE:
    {
        float new_speed = (*speed_mps) + ((*speed_mps) * LONGITUDINAL_DIFFERENCE_PERCENTAGE);
        *speed_mps = new_speed;
        break;
    }
    case LONGITUDINAL_ACTION_DECELERATE:
    {
        float new_speed = (*speed_mps) - ((*speed_mps) * LONGITUDINAL_DIFFERENCE_PERCENTAGE);
        *speed_mps = new_speed;
        break;
    }
    case LONGITUDINAL_ACTION_NONE:
    {
        return;
        break;
    }
    }
}
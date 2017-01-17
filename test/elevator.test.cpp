//
// Created by Javier Sánchez Rois on 17/01/17.
//

#include <gmock/gmock.h>
#include "../src/elevator.h"
using ::testing::Eq;


TEST(Elevator, starts_at_ground_floor) {
    Elevator elevator;
    EXPECT_THAT(elevator.currentFloor(), Eq(0));
}
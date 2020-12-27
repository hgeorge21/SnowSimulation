#ifndef UPDATE_VELOCITY_H
#define UPDATE_VELOCITY_H

#include <Eigen/Core>
#include <grid.h>
#include <particles.h>

void update_grid_velocity(Grid& grid, Particle& particles);

void update_particle_velocity(Grid& grid, Particle& particles);

#endif //UPDATE_VELOCITY_H
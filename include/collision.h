#ifndef COLLISION_H
#define COLLISION_H

#include <eigen/Core>
#include <grid.h>
#include <particles.h>

void grid_collision(Grid& grid, Particle& particles);

void particle_collision(Grid& grid, Particle& particles);

#endif // !COLLISION_H

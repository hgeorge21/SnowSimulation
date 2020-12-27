#include <Eigen/Core>
#include <Eigen/Sparse>

#include <grid.h>
#include <particles.h>

#include <particles_to_grid.h>
#include <particle_precompute.h>
#include <compute_force.h>
#include <update_velocity.h>
#include <collision.h>

#include <iostream>


int main(int argc, char** argv) {
	const double dt = 0.1;
	Eigen::RowVector3d corner1 = Eigen::RowVector3d(0., 0., 0.);
	Eigen::RowVector3d corner2 = Eigen::RowVector3d(1., 1., 1.);
	Eigen::RowVector3d h = Eigen::RowVector3d(0.1, 0.1, 0.1);
	Eigen::RowVector3d gravity = Eigen::RowVector3d(0, -0.5, 0);

	Grid grid(corner1, corner2, gravity, h);
	Particle particles(1000);

	for (int i = 0; i < 100; i++) {
		particles_to_grid(grid, particles);
		if (i == 0)
			particle_precompute(grid, particles);
		compute_force(grid, particles);
		update_grid_velocity(grid, particles);
		grid_collision(grid, particles);
		
		// solve linear system
		// deformation gradient

		update_particle_velocity(grid, particles);
		particle_collision(grid, particles);
		particles.move_particles(dt);
	}


	return 0;
}
#include <particles.h>

void Particle::move_particles(const double& dt) {
	q = q + dt * v;
}
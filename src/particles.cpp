#include <particles.h>

Particle::Particle(const int &n_) {
	n = n_;
	q = Eigen::MatrixXd::Zero(n, 3);
	v = Eigen::MatrixXd::Zero(n, 3);
	m = Eigen::VectorXd::Ones(n);
	rho = Eigen::VectorXd::Zero(n);
	vol = Eigen::VectorXd::Zero(n);

	w = Eigen::VectorXd::Zero(n);
}


void Particle::move_particles(const double& dt) {
	q = q + dt * v;
}

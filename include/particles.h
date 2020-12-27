#ifndef PARTICLE_H
#define PARTICLE_H

#include <Eigen/Core>

class Particle {

public:
	int n;

	Eigen::MatrixXd q;
	Eigen::MatrixXd v;
	Eigen::VectorXd m;
	Eigen::VectorXd rho;
	Eigen::VectorXd vol;

	Eigen::VectorXd w; // weight function

	Particle(const int& n_);

	void move_particles(const double &dt);

private:


};

#endif // !PARTICLE_H

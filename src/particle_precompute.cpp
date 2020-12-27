#include <particle_precompute.h>

void particle_precompute(Grid& grid, Particle& particles) {
	Eigen::VectorXd W = Eigen::VectorXd::Zero(particles.n);

	Eigen::RowVector3d h = grid.h;
	Eigen::RowVector3d x;
	Eigen::RowVector3i indices;

	const auto& grid_idx = [&](const Eigen::RowVector3d& x, const Eigen::RowVector3d& h, Eigen::RowVector3i& idx0) {
		Eigen::RowVector3d tmp = x.cwiseQuotient(h);
		idx0 << int(tmp(0)), int(tmp(1)), int(tmp(2));
	};
	
	particles.rho.setZero();
	for (int l = 0; l < particles.n; l++) {
		x = particles.q.row(l);
		grid_idx(x, h, indices);
		
		int idx = grid.get_idx(indices);
		particles.rho(l) += grid.m(idx) * particles.w(l) / h.prod();
	}
	
	particles.vol = particles.m.cwiseQuotient(particles.rho);
}
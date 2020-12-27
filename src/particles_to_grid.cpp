#include <particles_to_grid.h>


double B_spline(const double& x) {
	const double ax = abs(x);
	if (0 < ax && ax < 1)
		return 0.5 * pow(ax, 3) - x * x + 2 / 3;
	if (1 < ax && ax < 2)
		return -pow(ax, 3) / 6 + x * x - 2 * ax + 4 / 3;
	return 0.;
}

void particles_to_grid(Grid& grid, Particle& particles) {
	Eigen::RowVector3d h = grid.h;
	Eigen::RowVector3d x;
	Eigen::RowVector3i idx;

	const auto& grid_idx = [&](const Eigen::RowVector3d& x, const Eigen::RowVector3d& h, Eigen::RowVector3i &idx0) {
		Eigen::RowVector3d tmp = x.cwiseQuotient(h);
		idx0 << int(tmp(0)), int(tmp(1)), int(tmp(2));
	};
	const auto& compute = [&](const double& x, const int &dim) -> double {
		double h0 = h(dim);
		double ll = grid.lower_corner(dim);
		double x0 = 1. / h0 * (x - 1. * idx(dim) * h0);
		return B_spline(x0);
	};
	
	grid.m.setZero();
	for (int l = 0; l < particles.n; l++) {
		x = particles.q.row(l);
		grid_idx(x, h, idx);
		double wi = compute(x(0), 0) * compute(x(1), 1) * compute(x(2), 2);

		particles.w(l) = wi;
		grid.m(grid.get_idx(idx)) += particles.m(l) * wi;
		grid.V.row(grid.get_idx(idx)) += particles.v.row(l) * particles.m(l) * wi;
	}
	grid.V.col(0) = grid.V.col(0).cwiseQuotient(grid.m);
	grid.V.col(1) = grid.V.col(1).cwiseQuotient(grid.m);
	grid.V.col(2) = grid.V.col(2).cwiseQuotient(grid.m);
}
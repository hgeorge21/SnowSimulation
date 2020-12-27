#include <grid.h>

Grid::Grid(const Eigen::RowVector3d& corner1, const Eigen::RowVector3d& corner2, const Eigen::RowVector3d& gravity, const double &h_)
	: lower_corner(corner1), upper_corner(corner2), g(gravity), h(h_* Eigen::Vector3d::Ones()) {
	init();
}

Grid::Grid(const Eigen::RowVector3d& corner1, const Eigen::RowVector3d& corner2, const Eigen::RowVector3d& gravity, const Eigen::RowVector3d& h_)
	: lower_corner(corner1), upper_corner(corner2), g(gravity), h(h_) {
	init();
}


void Grid::init() {
	Eigen::RowVector3d ns = (upper_corner - lower_corner).cwiseQuotient(h);
	nx = ns(0);
	ny = ns(1);
	nz = ns(2);
	n_grids = nx * ny * nz;
	V = Eigen::MatrixXd::Zero(n_grids, 3);
	m = Eigen::VectorXd::Zero(n_grids);
}


int Grid::get_idx(const Eigen::RowVector3i& idx) {
	return idx(0) * ny * nz + idx(1) * nz + idx(2);
}

int Grid::get_idx(const int& i, const int& j, const int& k) {
	return i * ny * nz + j * nz + k;
}


#ifndef GRID_H
#define GRID_H

#include <Eigen/Core>
#include <Eigen/Sparse>

class Grid {
public:
	int nx, ny, nz;
	int n_grids;

	Eigen::RowVector3d g;

	Eigen::RowVector3d h;
	Eigen::RowVector3d lower_corner;
	Eigen::RowVector3d upper_corner;

	Eigen::VectorXd Vx, Vy, Vz;
	Eigen::MatrixXd V;
	Eigen::VectorXd m; // for weighted average purposes

	Grid(const Eigen::RowVector3d& corner1, const Eigen::RowVector3d& corner2, const Eigen::RowVector3d& gravity, const double &h_);
	Grid(const Eigen::RowVector3d& corner1, const Eigen::RowVector3d& corner2, const Eigen::RowVector3d& gravity, const Eigen::RowVector3d &h_);

	int get_idx(const int& i, const int& j, const int& k);
	int get_idx(const Eigen::RowVector3i& idx);


private:
	void init();

};

#endif // !GRID_H

#include <cstdlib>
#include <ctime>
#include "Visualizer.h"

extern "C" const double EPSILON;
bool CalculateLeastSquares(const double* x, const double* y, int n, double* m, double* b);



int main()
{
	const int n = 24;

	double x[] = { 30.0, 80.0, 130.0, 180.0, 230.0, 280.0, 330.0, 380.0, 430.0, 480.0,
				 530.0, 580.0, 630.0, 680.0, 730.0, 780.0, 830.0, 880.0, 930.0, 980.0,
				 1030.0, 1080.0, 1130.0, 1180.0 };

	double y[] = { 30.0, 80.0, 130.0, 180.0, 230.0, 280.0, 330.0, 380.0, 430.0, 480.0,
				 530.0, 580.0, 630.0, 680.0, 730.0, 780.0, 830.0, 880.0, 930.0, 980.0,
				 1030.0, 1080.0, 1130.0, 1180.0 };

	std::srand(static_cast<unsigned>(std::time(nullptr)));


	for (int i=0;i<n;++i)
	{
		x[i] -= std::rand() % 100 + 50;
		y[i] -= std::rand() % 100 + 50;
	}
	
	double m = 0, b = 0;

	const bool rv = CalculateLeastSquares(x, y, n, &m, &b);

	if(!rv)
	{
		return 1;
	}
	DrawLinearRegression(x,y,n,m,b);

	return 0;
}


bool CalculateLeastSquares(const double* x, const double* y, const int n, double* m, double* b)
{
	if (n <= 0)
	{
		return false;
	}

	double sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0;

	for (int i = 0; i < n; ++i)
	{
		sum_x += x[i];
		sum_y += y[i];
		sum_xx += x[i] * x[i];
		sum_xy += x[i] * y[i];
	}

	double denom = n * sum_xx - sum_x * sum_x;

	if (EPSILON >= fabs(denom))
	{
		return false;
	}

	*m = (n * sum_xy - sum_x * sum_y) / denom;
	*b = (sum_xx * sum_y - sum_x * sum_xy) / denom;

	return true;
}

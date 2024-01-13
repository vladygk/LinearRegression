#ifndef EXAMPLE_H
#define EXAMPLE_H
#include <SFML/Graphics.hpp>

sf::CircleShape DrawPoint(double x, double y);
sf::Vertex* DrawLine(double m, double b);
void DrawLinearRegression(const double* x, const double* y, int n, const double m, const double b);

#endif // EXAMPLE_H
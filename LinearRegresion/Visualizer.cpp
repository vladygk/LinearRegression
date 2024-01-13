#include "Visualizer.h"

sf::CircleShape DrawPoint(double x, double y)
{
	const double radius = 5;
	sf::CircleShape circle(radius);
	circle.setFillColor(sf::Color::Red);

	circle.setPosition(x - radius, y - radius);

	return circle;
}

sf::Vertex* DrawLine(double m, double b)
{
	const double x1 = 0, x2 = 1200;
	//y = x * m + b;

	double y1 = x1 * m + b;
	double y2 = x2 * m + b;

	sf::Vector2f startPoint(x1, y1);
	sf::Vector2f endPoint(x2, y2);

	sf::Vertex line[] = {
	   sf::Vertex(startPoint),
	   sf::Vertex(endPoint)
	};

	return line;
}

void DrawLinearRegression(const double* x, const double* y, int n, const double m, const double b)
{

	sf::RenderWindow window(sf::VideoMode(1300, 1300), "Linear Regression");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		for (int i = 0; i < n; ++i)
		{
			sf::CircleShape point = DrawPoint(x[i], y[i]);
			window.draw(point);
			window.display();
		}

		sf::sleep(sf::milliseconds(1000));
		sf::Vertex* line = DrawLine(m, b);
		window.draw(line, 2, sf::Lines);
		window.display();
	}
}
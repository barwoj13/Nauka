#include <iostream>
#include <cmath>


struct Point2D 
{
	double x;
	double y;
};

double distance(const Point2D& p1, const Point2D& p2)
{
	double wynik = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
	return wynik;
}

void movePoint(Point2D& p, double dx, double dy) 
{
	p.x += dx;
	p.y += dy;
}

int main() 
{

}
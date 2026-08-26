#include <iostream>
#include <vector>

class Shape 
{
private:
public:
	virtual double area() const = 0;
	virtual ~Shape() = default;
};

class Circle : public Shape 
{
private:
	double m_radius;
public:
	Circle(double r) : m_radius(r) {}

	void setRadius(double radius) 
	{
		if (radius <= 0) return;
		m_radius = radius;
	}

	double area() const override { return  3.14 * m_radius * m_radius; }
};

class Rectangle : public Shape 
{
private:
	double m_width;
	double m_height;
public:
	Rectangle(double w, double h) : m_width(w), m_height(h) {}

	void setParam(double width, double height) 
	{
		if (width <= 0 || height <= 0) return;
		m_width = width;
		m_height = height;
	}

	double area() const override {	return m_width * m_height; }

};

int main() {
	// Wejœcie: wektor wskaŸników na klasê bazow¹
	std::vector<Shape*> shapes;

	shapes.push_back(new Circle(3.0));
	shapes.push_back(new Rectangle(4.0, 5.0));
	shapes.push_back(new Circle(1.5));

	double totalArea = 0.0;

	// Polimorficzna pêtla - wywo³uje w³aœciw¹ metodê area() w zale¿noœci od rzeczywistego typu obiektu
	for (const Shape* shape : shapes) {
		totalArea += shape->area();
	}

	std::cout << "Laczne pole powierzchni: " << totalArea << std::endl;

	// Pamiêtaj o zwolnieniu pamiêci (wywo³a wirtualne destruktory!)
	for (Shape* shape : shapes) {
		delete shape;
	}
}
#include <iostream>
#include <time.h>
#include <algorithm>
#include "Figure.h"
#include "Circle.h"
#include "Ellipse.h"
#include <vector>
#include <math.h>

Circle::Circle() : radius(0.0) {};

Circle::Circle(const double _radius) {
    if (_radius < 0)
    {
        throw "error: negative radius";
    }
    radius = _radius;
}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

int Circle::getType() const {
    return 1;
}

Ellipse::Ellipse() : a(0.0), b(0.0) {};

Ellipse::Ellipse(const double _a, const double _b) {
    if (_a < 0 || _b < 0) {
        throw "error: one of the semiaxes is negative";
    }
    a = _a;
    b = _b;
}

double Ellipse::getArea() const {
    return M_PI * a * b;
}

int Ellipse::getType() const {
    return 2;
}

bool isLess(std::unique_ptr<Figure>& c1, std::unique_ptr<Figure>& c2)
{
    return c1->getArea() < c2->getArea();
}

int main()
{
    srand(time(0));
    try
    {
        int size = 10; 
        double AreaCircles = 0.0;
        double AreaEllipses = 0.0;
        std::vector<std::unique_ptr<Figure>> figures(size);
        
        for (int i = 0; i < size; i++) {
            if (rand() % 2 == 0) {
                figures[i] = std::make_unique<Circle>(Circle(static_cast<double>(rand() % 100)));
            } else {
                figures[i] = std::make_unique<Ellipse>(Ellipse(static_cast<double>(rand() % 100), static_cast<double>(rand() % 100)));
            }
        }
        sort(figures.begin(), figures.end(), isLess);
        for (int i = 0; i < size; i++) {
            std::cout << figures[i]->getArea() << std::endl;
        }
        for (int i = 0; i < size; i++) {
            if (figures[i]->getType() == 1) {
                AreaCircles += figures[i]->getArea();
            }
            if (figures[i]->getType() == 2) {
                AreaEllipses += figures[i]->getArea();
            }
        }
        std::cout << std::endl << "FULL CIRCLE AREA: " << AreaCircles << std::endl;
        std::cout << "FULL AREA OF ELLIPSES: " << AreaEllipses << std::endl;
    }
    catch (const char* msg)
    {
        std::cout << msg << std::endl;
    }
    return 0;
}

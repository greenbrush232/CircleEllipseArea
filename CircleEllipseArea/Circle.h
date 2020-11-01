#ifndef _Circle_Header
#define _Circle_Header
#include "Figure.h"

class Circle : public Figure {
protected:
	double radius;

public:
	Circle();
	Circle(const double length);
	double getArea() const  override;
	int getType() const  override;
};

#endif  // _Circle_Header

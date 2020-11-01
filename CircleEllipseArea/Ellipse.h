#ifndef _Ellipse_Header
#define _Ellipse_Header
#include "Figure.h"

class Ellipse : public Figure {
protected:
	double a;
	double b;

public:
	Ellipse();
	Ellipse(const double _a, const double _b);
	virtual double getArea() const  override;
	virtual int getType() const  override;
};

#endif  // _Ellipse_Header

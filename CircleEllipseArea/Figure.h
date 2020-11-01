#ifndef _Figure_Header
#define _Figure_Header
#define _USE_MATH_DEFINES

class Figure {
public:
	Figure() {}
	virtual double getArea() const = 0;
	virtual int getType() const = 0;
	virtual ~Figure() {}
};

#endif  // _Figure_Header

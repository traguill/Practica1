#ifndef __Point2D_H__
#define __Point2D_H__


class Point2D
{
public:
	

	//Attributes
	
	float x, y;

	
	//Methods
	
	bool IsZero() const;
	
	void SetZero();

	float DistanceTo(const Point2D p) const;

	
	//Operators
	
	Point2D operator+ (const Point2D p) const;

	Point2D operator- (const Point2D& p)const;

	Point2D operator+= (const Point2D& p);

	Point2D operator-= (const Point2D& p);

	bool operator== (const Point2D& p) const;

	bool operator!=(const Point2D& p) const;

};
#endif
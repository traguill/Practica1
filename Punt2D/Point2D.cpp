#include "Point2D.h"
#include <math.h>

	//Methods
	
	bool Point2D::IsZero() const
	{
		return x == 0 && y == 0;
	}

	void Point2D::SetZero()
	{
		x = y = 0.0f;
	}

	float Point2D::DistanceTo(const Point2D p) const
	{
		float tmpX = x - p.x;
		float tmpY = y - p.y;

		return sqrtf(tmpX * tmpX + tmpY * tmpY);
	}

	//Operators

	Point2D Point2D::operator+ (const Point2D p) const
	{
		Point2D tmp;
		tmp.x = x + p.x;
		tmp.y = y + p.y;

		return tmp;
	}

	Point2D Point2D::operator- (const Point2D& p)const
	{
		Point2D tmp;
		tmp.x = x - p.x;
		tmp.y = y - p.y;

		return tmp;
	}
	Point2D Point2D::operator+= (const Point2D& p)
	{
		x += p.x;
		y += p.y;

		return *this;
	}

	Point2D Point2D::operator-= (const Point2D& p)
	{
		x -= p.x;
		y -= p.y;

		return *this;
	}

	bool Point2D::operator== (const Point2D& p) const
	{
		return x == p.x && y == p.y;
	}

	bool Point2D::operator!=(const Point2D& p) const
	{
		return x != p.x || y != p.y;
	}

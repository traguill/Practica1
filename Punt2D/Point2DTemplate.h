#ifndef __Point2DTemplate_H__
#define __Point2DTemplate_H__

#include <math.h>


template <class Type>
class Point2DTemplate
{
public:


	//Attributes

	Type x, y;


	//Methods

	bool IsZero() const
	{
		return x == 0 && y == 0;
	}

	void SetZero()
	{
		x = y = 0.0f;
	}

	Type DistanceTo(const Point2DTemplate p) const
	{
		Type tmpX = x - p.x;
		Type tmpY = y - p.y;

		return sqrtf(tmpX * tmpX + tmpY * tmpY);
	}

	//Operators

	Point2DTemplate operator+ (const Point2DTemplate p) const
	{
		Point2DTemplate tmp;
		tmp.x = x + p.x;
		tmp.y = y + p.y;

		return tmp;
	}

	Point2DTemplate operator- (const Point2DTemplate& p)const
	{
		Point2DTemplate tmp;
		tmp.x = x - p.x;
		tmp.y = y - p.y;

		return tmp;
	}
	Point2DTemplate operator+= (const Point2DTemplate& p)
	{
		x += p.x;
		y += p.y;

		return *this;
	}

	Point2DTemplate operator-= (const Point2DTemplate& p)
	{
		x -= p.x;
		y -= p.y;

		return *this;
	}

	bool operator== (const Point2DTemplate& p) const
	{
		return x == p.x && y == p.y;
	}

	bool operator!=(const Point2DTemplate& p) const
	{
		return x != p.x || y != p.y;
	}


};
#endif
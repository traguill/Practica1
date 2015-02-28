#ifndef __Point2D_H__
#define __Point2D_H__

class Point2D
{
public:
	
	//--------------------------------------------------
	//Atributs
	//--------------------------------------------------
	float x, y;

	//--------------------------------------------------
	//Metodes
	//--------------------------------------------------
	bool IsZero() const
	{
		return x == 0 && y == 0;
	}
	
	void SetZero()
	{
		x = y = 0.0f;
	}

	Point2D DistanceTo(const Point2D p) const
	{
		Point2D tmp;
		tmp.x = p.x - x;
		tmp.y = p.y - y;

		return tmp;
	}

	//--------------------------------------------------
	//Operadors
	//--------------------------------------------------
	Point2D operator+ (const Point2D p) const
	{
		Point2D tmp;
		tmp.x = x + p.x;
		tmp.y = y + p.y;

		return tmp;
	}

	Point2D operator- (const Point2D& p)const
	{
		Point2D tmp;
		tmp.x = x - p.x;
		tmp.y = y - p.y;

		return tmp;
	}
	Point2D operator+= (const Point2D& p)
	{
		x += p.x;
		y += p.y;

		return *this;
	}

	Point2D operator-= (const Point2D& p)
	{
		x -= p.x;
		y -= p.y;

		return *this;
	}

	bool operator== (const Point2D& p) const
	{
		return x == p.x && y == p.y;
	}

	bool operator!=(const Point2D& p) const
	{
		return x != p.x || y != p.y;
	}


};
#endif
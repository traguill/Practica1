
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a>b)?(a):(b))


template<class Type> void swap(Type& a, Type& b)
{
	Type tmp;
	tmp = a;
	a = b;
	b = tmp;
};


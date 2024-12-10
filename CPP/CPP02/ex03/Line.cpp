#include "Line.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Line::Line(): _x(), _y(), _m(0), _b(0), _func()
{
}

Line::Line(const Point x, const Point y): _x(x), _y(y)
{
    _m = ((_x.get_x() - _y.get_x()) / (x.get_y() - _y.get_y()));
    _b = (_x.get_y()) - _m;
    _func = "y = " + std::to_string(_m.toFloat()) + "x + " + std::to_string(_b.toFloat());
}

Line::Line( const Line & src )
{
    *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Line::~Line()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Line &				Line::operator=( Line const & rhs )
{
	if ( this != &rhs )
	{
        _x = rhs._x;
        _y = rhs._y;
        _b = rhs._b;
		_m = rhs._m;
        _func = rhs._func;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Line const & i )
{
	o << i.get_m().toFloat() << "*x + " << i.get_b() << std::endl;;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Line::get_func() const
{
    return this->_func;
}

Point Line::get_x() const
{
    return this->_x;
}

Point Line::get_y() const
{
    return this->_y;
}

Fixed Line::get_m() const
{
    return this->_m;
}

Fixed Line::get_b() const
{
    return this->_b;
}

int Line::on_line(Point f)
{
    std::cout << *this << std::endl;
    if (f.get_y().toFloat() == _m.toFloat() * f.get_x().toFloat() + _b.toFloat())
    {
        std::cout << "Point f on the the line ";
        if ((_x.get_x() < f.get_x() && f.get_x() < _y.get_x()) || (_x.get_x() > f.get_x() && f.get_x() > _y.get_x()))
        {
            std::cout << "and in this section" << std::endl;
            return 1;
        }
        else
        {
            std::cout << "but not in this section" << std::endl;
            return (0);
        }
    }
    std::cout << "Point f not on this line" << std::endl;
    return -1;
}

/* ************************************************************************** */

Point *intersection(Line &a, Line &b)
{
    Point *p = NULL;
    Fixed x,y;

    if (a.get_m() == b.get_m() && a.get_b() == a.get_b())
    {
        std::cout << "line " << a << " & " << b << " are the same." << std::endl;
        return NULL;
    }
    else if (a.get_m() == b.get_m() && a.get_b() != a.get_b())
    {
        std::cout << "line " << a << " & " << b << " are //." << std::endl;
        return NULL;
    }
    else if (a.get_m() == 0 && b.get_m() != 0 && b.get_b() != 0)
    {
        x = (a.get_b() - b.get_b()) / a.get_m().toFloat();
        y = a.get_b();
        *p = Point(x,y);
        return p;
    }
    else if (b.get_m() == 0 && a.get_m() != 0 && a.get_b() != 0)
    {
        x = (b.get_b() - a.get_b()) / b.get_m().toFloat();
        y = b.get_b();
        *p = Point(x,y);
        return p;
    }
    else
    {
        x = (a.get_b() - b.get_b()) / (b.get_m() - a.get_m());
        y = a.get_m() * x + a.get_b().toFloat();
        *p = Point(x,y);
        return p;
    }
    return p;
}
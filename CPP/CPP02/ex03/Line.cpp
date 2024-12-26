#include "Line.hpp"
#include <sstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Line::Line(): _x(), _y(), _m(0), _b(0), _func(), _vert(-1)
{
}

Line::Line(const Point x, const Point y): _x(x), _y(y)
{
    Fixed m_up, m_down;
    std::stringstream ss1, ss2;
    std::string s1, s2;

    _vert = 0;
    m_up = (_x.get_x() - _y.get_x());
    m_down = (x.get_y() - _y.get_y());
    if (m_down == 0)
        _m = 0;
    else if (m_up == 0)
    {
        _vert = 1;
        _b = x.get_x();
        ss1 << x.get_x().toFloat();
        s1 = ss1.str();
        _func = "x = " + s1;
        return ;
    }
    else  
        _m = (m_up / m_down);
    _b = (_x.get_y()) - _m;
    ss1 << _m.toFloat();
    s1 = ss1.str();
    ss2 << _b.toFloat();
    s2 = ss2.str();
    _func = "y = " ;
    if (_m != 0)
        _func += s1 + "x + ";
    _func += s2;
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
        _vert = rhs._vert;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Line const & i )
{
	o << i.get_func();
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

int Line::is_vert() const
{
    return this->_vert;
}

int Line::on_line(Point f, int print)
{
    if (print)
    {
       std::cout << *this << std::endl;
        std::cout << "Point f" << f;
    }
    if (_vert)
    {
        if (f.get_x() == _b)
        {
            if (print)
            {
                std::cout << " on the the line " << get_func() << " ";
                if ((f.get_y() <= _x.get_y() && f.get_y() >= _y.get_y()) || (f.get_y() >= _x.get_y() && f.get_y() <= _y.get_y()))
                    std::cout << "and in this segment ";
                else
                    std::cout << "but not in this segment ";
                std::cout << "[" << _x << "," << _y << "]" << std::endl;
            }
            return (_y.get_y() <= f.get_y() && f.get_y() <= _x.get_y()) || (_x.get_y() <= f.get_y() && f.get_y() <= _y.get_y());
        }
    }
    if (f.get_y().toFloat() == _m.toFloat() * f.get_x().toFloat() + _b.toFloat())
    {
        // Point f on the ligne defined by the function of the Line
        if (print)
        {
            std::cout << " on the the line " << get_func() << " ";
            if ((_x.get_x() <= f.get_x() && f.get_x() <= _y.get_x()) || (_x.get_x() >= f.get_x() && f.get_x() >= _y.get_x())) // Point f on the Line segment
                std::cout << "and in this segment ";
            else // Point f not on the Line segment
                std::cout << "but not in this segment ";
            std::cout << "[" << _x << "," << _y << "]" << std::endl;
        }
        return (_x.get_x() <= f.get_x() && f.get_x() <= _y.get_x()) || (_x.get_x() >= f.get_x() && f.get_x() >= _y.get_x());
    }
    // Point f not on the Line
    if (print)
        std::cout << " not on this line" << std::endl;
    return -1;
}

/* ************************************************************************** */

int intersection(Line const &a, Line const &b, Point &p, int print)
{
    Fixed x, y, part;

    if (a.is_vert() || b.is_vert())
    {
        if (a.is_vert() && b.is_vert())
        {
            if (a.get_b() == b.get_b())
            {
                if (print)
                    std::cout << "line " << a << " & " << b << " are the same." << std::endl;
            }
            else
            {
                if (print)
                    std::cout << "line " << a << " & " << b << " are //." << std::endl;
            }
            return 0;
        }
        else if (a.is_vert())
        {
            x = a.get_b();
            part = b.get_m() * a.get_b();
            y = part + b.get_b();
            p = Point(x, y);
            return 1;
        }
        else
        {
            x = b.get_b();
            part = a.get_m() * b.get_b();
            y = part + a.get_b();
            p = Point(x, y);
            return 1;
        }
    }

    if (a.get_m() == b.get_m() && a.get_b() == b.get_b())
    {
        // Line a and b are equal
        if (print)
            std::cout << "line " << a << " & " << b << " are the same." << std::endl;
        return 0;
    }
    else if (a.get_m() == b.get_m() && a.get_b() != b.get_b())
    {
        // Line a and b are parallel
        if (print)
            std::cout << "line " << a << " & " << b << " are //." << std::endl;
        return 0;
    }
    else if (a.get_m() == 0 && b.get_m() != 0 && b.get_b() != 0)
    {
        part = (a.get_b() - b.get_b());
        x = part / a.get_m();
        y = a.get_b();
        p = Point(x,y);
        return 1;
    }
    else if (b.get_m() == 0 && a.get_m() != 0 && a.get_b() != 0)
    {
        part = (b.get_b() - a.get_b());
        x = part / b.get_m();
        y = b.get_b();
        p = Point(x,y);
        return 1;
    }
    else
    {
        x = (a.get_b() - b.get_b()) / (b.get_m() - a.get_m());
        part = (a.get_m() * x);
        y = part + a.get_b();
        p = Point(x,y);
        return 1;
    }
}
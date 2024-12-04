#ifndef LINE_HPP
# define LINE_HPP

# include <iostream>
# include <string>
# include "Point.hpp"


class Line
{
	private:
        Point _x;
        Point _y;
        float   _m, _b;
        std::string _func;
	public:

		Line();
        Line(const Point x, const Point y);
		Line( Line const & src );
		~Line();

		Line &		operator=( Line const & rhs );

        std::string get_func() const;
        Point get_x()const;
        Point get_y()const;
        float get_m()const;
        float get_b()const;

};

std::ostream &			operator<<( std::ostream & o, Line const & i );

void intersection(Line &a, Line &b, Point *p);

#endif /* ************************************************************ LINE_H */
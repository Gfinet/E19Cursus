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
        Fixed _m, _b;
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
        Fixed get_m()const;
        Fixed get_b()const;
        int on_line(Point f);

};

std::ostream &			operator<<( std::ostream & o, Line const & i );

Point *intersection(Line &a, Line &b);

#endif /* ************************************************************ LINE_H */
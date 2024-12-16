#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include <iostream>
# include <string>
# include "Line.hpp"

class Triangle
{
	private:
		Line _a, _b, _c;
		Point _x, _y, _z;

	public:

		Triangle();
		Triangle(Line a, Line b, Line c);
		Triangle(Point x, Point y, Point z);
		Triangle( Triangle const & src );
		~Triangle();

		Triangle &		operator=( Triangle const & rhs );
		
		Fixed get_leftest_point_abs();
		Fixed get_rightest_point_abs();
		Fixed get_top_point_ord();
		Fixed get_bot_point_ord();

		Line get_first_line() const;
		Line get_second_line() const;
		Line get_third_line() const;

		Point get_first_point() const;
		Point get_second_point() const;
		Point get_third_point() const;
};

std::ostream &			operator<<( std::ostream & o, Triangle const & i );

#endif /* ******************************************************** TRIANGLE_H */

int point_in_triangle(Triangle t, Point f);
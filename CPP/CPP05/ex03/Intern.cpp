#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}


std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	o << "Just an Intern";
	return o;
}

const char* Bureaucrat::NorFormException::what() const throw()
{
	return ("[NorFormException : Name of the Form not knowned!]");
}


/*
** --------------------------------- METHODS ----------------------------------
*/

static AForm* PresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);

}

static AForm* RobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm* ShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string Name, std::string target)
{
	std::string form[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
    AForm* (*func[3])(std::string) = {PresidentialForm, RobotomyForm, ShrubberyForm};
	bool found = false;
	try
	{
		for (int i = 0; i < 3; i++)
		{
			found = (form[i] == Name);
			if (found)
				return (func[i](target));
		}
		if (!found)
			throw NoFormException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 0;
	}
	return 0;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */
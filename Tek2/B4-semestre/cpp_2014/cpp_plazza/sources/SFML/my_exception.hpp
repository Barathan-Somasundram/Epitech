#ifndef MY_EXECPTION_HPP_
# define MY_EXECEPTION_HPP_

# include <iostream>
# include <sstream>
# include <exception>
# include <string>

class			my_exception: std::exception
{
private:
  std::string		_msg;

public:
  my_exception(std::string error);
  virtual ~my_exception() throw();

  virtual const char*	what() const throw();
};

#endif /* !MY_EXECTION_HPP_ */

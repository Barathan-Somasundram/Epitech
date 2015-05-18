//
// my_exception.hpp for  in /home/somasu_b/rendu/cpp_plazza/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:17:36 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:17:37 2015 SOMASUNDRAM Barathan
//

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

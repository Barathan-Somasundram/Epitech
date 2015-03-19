//
// my_exeception.hpp for  in /home/somasu_b/rendu/cpp_abstractvm/cpp_abstractvm/sources
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Mar  1 11:50:04 2015 SOMASUNDRAM Barathan
// Last update Sun Mar  1 19:35:10 2015 SOMASUNDRAM Barathan
//

#ifndef MY_EXECPTION_HPP_
# define MY_EXECEPTION_HPP_

# include <iostream>
# include <sstream>
# include <exception>
# include <string>

typedef enum 
  {
    NO_FILE,
    BAD_EXTENSION,
    LINE_CMD,
    LINE_PARAM,
    LINE_SYNTAX,
    EXIT,
    NO_ERROR,
    OTHER,
    OVER_FLOW,
    UNDER_FLOW,
    OPZERO
  } errorType;

class			my_exception: std::exception
{
private:
  std::string		_msg;
  
public:
  my_exception(std::string file, int nb_line, std::string line, errorType type);
  virtual ~my_exception() throw();

  virtual const char*	what() const throw();
};

#endif /* !MY_EXECTION_HPP_ */

//
// my_exception.cpp for  in /home/somasu_b/rendu/cpp_abstractvm/cpp_abstractvm/sources
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Mar  1 13:22:56 2015 SOMASUNDRAM Barathan
// Last update Sun Mar  1 21:32:50 2015 SOMASUNDRAM Barathan
//

#include "../includes/my_exception.hpp"

my_exception::my_exception(std::string file, int nb_line, std::string line, errorType type)
{
  std::ostringstream oss; 

  if (type == UNDER_FLOW || type == OVER_FLOW)
    oss << "\t" << "\x1B[31m" << "Error: " << "\x1B[35m" << "there is an "
	<< (type == UNDER_FLOW ? "underflow" : "overflow") << "\x1B[0m" << std::endl;
  if (type == OPZERO)
    oss << "\t" << "\x1B[31m" << "Error: " << "\x1B[35m" << "there is an " << line << "\x1B[0m"<< std::endl;
  if (type != OPZERO && type != UNDER_FLOW && type != OVER_FLOW)
    oss << "\x1B[31m" << "Error: " << "\x1B[35m" << file << "\x1B[0m";
  if (type == NO_FILE)
    oss << "\x1B[32m" << ": file does not exist" << "\x1B[0m" << std::endl;
  if (type == BAD_EXTENSION)
    oss << "\x1B[32m" << ": file has bad extension" << "\x1B[0m" << std::endl;
  if (type == LINE_CMD)
    oss << ": line: " << nb_line << ": \x1B[33m" << line << "\x1B[32m" << ": is not a valid command" << "\x1B[0m" << std::endl;
  if (type == LINE_PARAM)
    oss << ": line: " << nb_line << ": \x1B[33m" << line << "\x1B[32m" << ": bad parameter syntax" << "\x1B[0m" << std::endl;
  if (type == LINE_SYNTAX)
    oss << ": line: " << nb_line << ": \x1B[33m" << line << "\x1B[32m" << ": bad syntax" << "\x1B[0m" << std::endl;
  if (type == OTHER)
    oss << line;
  if (type == EXIT)
    oss << "\x1B[33m" << "\nExit not initialise" << "\x1B[0m" << std::endl;
  _msg = oss.str();
}

my_exception::~my_exception() throw()
{

}

const char*	my_exception::what() const throw()
{
  return (_msg.c_str());
}

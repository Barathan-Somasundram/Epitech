#include "my_exception.hpp"

my_exception::my_exception(std::string error)
{
  _msg = error;
}

my_exception::~my_exception() throw()
{

}

const char*	my_exception::what() const throw()
{
  return (_msg.c_str());
}

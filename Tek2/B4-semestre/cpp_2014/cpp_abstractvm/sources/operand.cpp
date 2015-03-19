//
// operand.cpp for  in /home/somasu_b/rendu/cpp_abstractvm/cpp_abstractvm/sources
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Feb 28 17:30:27 2015 SOMASUNDRAM Barathan
// Last update Sun Mar  1 19:37:17 2015 SOMASUNDRAM Barathan
//

#include <sstream>
#include <cmath>
#include "../includes/convert.hpp"
#include "../includes/operand.hpp"
#include "../includes/my_exception.hpp"

# define callFunction(object, ptr) ((object).*(ptr))

template <class T>
Operand<T>::Operand() {

}

template <class T>
Operand<T>::~Operand() {}

template <class T>
std::string const &Operand<T>::toString() const
{
  std::stringstream str_nb;

  str_nb << (float)_nb;
  std::string *str = new std::string(str_nb.str());
  return (*str);
}

template <class T>
int			Operand<T>::getPrecision() const
{
  return (this->_type);
}

template <class T>
eOperandType		Operand<T>::getType() const
{
  return (this->_type);
}

template <class T>
T             Operand<T>::getNb()
{
  return (this->_nb);
}

template <class T>
void          Operand<T>::setNb(T nb)
{
  this->_nb = nb;
}

template <class T>
void          Operand<T>::setType(eOperandType type)
{
  this->_type = type;
}

IOperand		*AOperand::createOperand(eOperandType type, const std::string & value)
{
  AOperand::fnc_mth	tab_fnc[5] = {AOperand::createInt8,
				      AOperand::createInt16,
				      AOperand::createInt32,
				      AOperand::createFloat,
				      AOperand::createDouble};
  return (tab_fnc[type](value));
}

IOperand		*AOperand::createInt8(const std::string & value)
{
  Operand<char> *x = new Operand<char>;
  std::stringstream ss(value);
  long i;

  ss >> i;
  if (i < -128 || i > 127)
    throw(my_exception("", -1, "", (i > 127 ? OVER_FLOW : UNDER_FLOW)));
  x->setNb(static_cast<char>(i));
  x->setType(Int8);
  return (x);
}

IOperand		*AOperand::createInt16(const std::string & value)
{
  Operand<short> *x = new Operand<short>;
  std::stringstream ss(value);
  long i;

  ss >> i;
  if (i < -32768 || i > 32767)
    throw(my_exception("", -1, "", (i > 32767 ? OVER_FLOW : UNDER_FLOW)));
  x->setNb(static_cast<short>(i));
  x->setType(Int16);
  return (x);
}

IOperand		*AOperand::createInt32(const std::string & value)
{
  Operand<int> *x = new Operand<int>;
  std::stringstream ss(value);
  long i;

  ss >> i;
  if (i < -2147483648 || i > 2147483647)
    throw(my_exception("", -1, "", (i > 2147483647 ? OVER_FLOW : UNDER_FLOW)));
  x->setNb(static_cast<int>(i));
  x->setType(Int32);
  return (x);
}

IOperand		*AOperand::createFloat(const std::string & value)
{
  Operand<float> *x = new Operand<float>;
  std::stringstream  val(value);
  long double i;

  val >> i;
  if (i < -2147483648 || i > 2147483647)
    throw(my_exception("", -1, "", (i > 2147483647 ? OVER_FLOW : UNDER_FLOW)));
  x->setNb(static_cast<float>(i));
  x->setType(Float);
  return (x);
}

IOperand		*AOperand::createDouble(const std::string & value)
{
  Operand<double > *x = new Operand<double>;
  std::stringstream  val(value);
  long double i;

  val >> i;
  if (i < -2147483648 || i > 2147483647)
    throw(my_exception("", -1, "", (i > 2147483647 ? OVER_FLOW : UNDER_FLOW)));
  x->setNb(static_cast<double>(i));
  x->setType(Double);
  return (x);
}

double		convert_value(const std::string & value, eOperandType type)
{
  double  ret;

  type = type;
  ret = my_atof(value.c_str());
  return (ret);
}

template <class T>
IOperand		*Operand<T>::operator+(const IOperand &rhs) const
{
  double		value1;
  double		value2;
  eOperandType  type;
  std::stringstream   result;
  IOperand      *ret;

  if (this->getType() < rhs.getType())
    type = rhs.getType();
  else
    type = this->getType();
  value1 = convert_value(this->toString(), type);
  value2 = convert_value(rhs.toString(), type);
  result << value1 + value2;
  ret = AOperand::createOperand(type, result.str());
  return (ret);
}

template <class T>
IOperand		*Operand<T>::operator-(const IOperand &rhs) const
{
  double		value1;
  double		value2;
  eOperandType  type;
  std::stringstream   result;
  IOperand      *ret;

  if (this->getType() < rhs.getType())
    type = rhs.getType();
  else
    type = this->getType();
  value1 = convert_value(this->toString(), type);
  value2 = convert_value(rhs.toString(), type);
  result << value1 - value2;
  ret = AOperand::createOperand(type, result.str());
  return (ret);
}

template <class T>
IOperand		*Operand<T>::operator*(const IOperand &rhs) const
{
  double		value1;
  double		value2;
  eOperandType  type;
  std::stringstream   result;
  IOperand      *ret;

  if (this->getType() < rhs.getType())
    type = rhs.getType();
  else
    type = this->getType();
  value1 = convert_value(this->toString(), type);
  value2 = convert_value(rhs.toString(), type);
  result << value1 * value2;
  ret = AOperand::createOperand(type, result.str());
  return (ret);
}

template <class T>
IOperand		*Operand<T>::operator/(const IOperand &rhs) const
{
  double		value1;
  double		value2;
  eOperandType  type;
  std::stringstream   result;
  IOperand      *ret;

  if (this->getType() < rhs.getType())
    type = rhs.getType();
  else
    type = this->getType();
  value1 = convert_value(this->toString(), type);
  value2 = convert_value(rhs.toString(), type);
  if (value2 == 0.0)
    throw(my_exception("", -1, "Division par zero", OPZERO));
  result << value1 / value2;
  ret = AOperand::createOperand(type, result.str());
  return (ret);
}

template <class T>
IOperand		*Operand<T>::operator%(const IOperand &rhs) const
{
  double		value1;
  double		value2;
  eOperandType  type;
  std::stringstream   result;
  IOperand      *ret;

  if (this->getType() < rhs.getType())
    type = rhs.getType();
  else
    type = this->getType();
  value1 = convert_value(this->toString(), type);
  value2 = convert_value(rhs.toString(), type);
  if (value2 == 0.0)
    throw(my_exception("", -1, "Division par zero", OPZERO));
  result << std::fmod(value1, value2);
  ret = AOperand::createOperand(type, result.str());
  return (ret);
}

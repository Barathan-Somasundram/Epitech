//
// operand.hpp for  in /home/somasu_b/rendu/cpp_abstractvm/cpp_abstractvm
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Mar  1 17:09:29 2015 SOMASUNDRAM Barathan
// Last update Sun Mar  1 17:09:48 2015 SOMASUNDRAM Barathan
//

#ifndef OPERAND_HPP_
# define OPERAND_HPP_

#include <iostream>
#include "../includes/operand.hpp"

enum eOperandType { Int8, Int16, Int32, Float, Double };

class               IOperand
{
  public:
  virtual std::string const & toString() const = 0; // Renvoie une string reprensentant l’instance
  virtual int getPrecision() const = 0; // Renvoie la precision du type de l’instance
  virtual eOperandType getType() const = 0; // Renvoie le type de l’instance. Voir plus bas

  virtual IOperand * operator+(const IOperand &rhs) const = 0; // Somme
  virtual IOperand * operator-(const IOperand &rhs) const = 0; // Difference
  virtual IOperand * operator*(const IOperand &rhs) const = 0; // Produit
  virtual IOperand * operator/(const IOperand &rhs) const = 0; // Quotient
  virtual IOperand * operator%(const IOperand &rhs) const = 0; // Modulo

  virtual ~IOperand() {}
};

template <typename T>
class				Operand : public IOperand {
private:

  T				_nb;
  eOperandType			_type;

public:
  Operand();
  ~Operand();

  std::string const & toString() const ;
  int getPrecision() const;
  eOperandType getType() const;

  T			getNb();
  void			setNb(T nb);
  void			setType(eOperandType type);

  IOperand		*operator+(const IOperand &rhs) const;
  IOperand		*operator-(const IOperand &rhs) const;
  IOperand		*operator*(const IOperand &rhs) const;
  IOperand		*operator/(const IOperand &rhs) const;
  IOperand		*operator%(const IOperand &rhs) const;
};

class             AOperand {
public:

  static IOperand	*createOperand(eOperandType type, const std::string & value);

private:
  static IOperand	*createInt8(const std::string & value);
  static IOperand	*createInt16(const std::string & value);
  static IOperand	*createInt32(const std::string & value);
  static IOperand	*createFloat(const std::string & value);
  static IOperand	*createDouble(const std::string & value);
  typedef IOperand	*(*fnc_mth)(std::string const & value);
};

#endif /* !OPERAND_HPP_ */

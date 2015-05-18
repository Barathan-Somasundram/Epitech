//
// pizza.hpp for  in /home/somasu_b/rendu/cpp_plazza/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:17:50 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:17:51 2015 SOMASUNDRAM Barathan
//

#ifndef PIZZA_HPP_
 # define PIZZA_HPP_

#include <iostream>
#include <string>
#include <vector>

class		Pizza
{
public:
  enum TypePizza
    {
      Regina = 1,
      Margarita = 2,
      Americaine = 4,
      Fantasia = 8
    };

  enum TaillePizza
    {
      S = 1,
      M = 2,
      L = 4,
      XL = 8,
      XXL = 16
    };

  typedef struct	s_word
  {
    std::string	       	pizza;
    std::string 	size;
    TypePizza		type;
    TaillePizza		siz;
  }			t_word;
  
  Pizza(std::string line, int multiplier);
  ~Pizza();

  int		getCookTime(void) const;
  TypePizza	getType(void) const;
  TaillePizza	getSize(void) const;
  std::vector<int>	getNeeded(void) const;
  int		getCook(void) const;
  void		delRessources(int id, int nb);

private:
  std::string	_line;
  int		_mult;

  TypePizza	_type;
  TaillePizza	_size;
  std::vector<int>	_needed;
  int		_cookTime;
  int		_cook;

  void		parse(void);
  void		setIngredientCook(void);
};

#endif /* !PIZZA_HPP_ */

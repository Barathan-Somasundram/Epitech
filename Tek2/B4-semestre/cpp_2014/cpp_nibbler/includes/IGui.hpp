//
// IGui.hpp for  in /home/somasu_b/rendu/cpp_nibbler/sources/algo
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Apr  2 03:29:18 2015 SOMASUNDRAM Barathan
// Last update Fri Apr  3 22:20:05 2015 SOMASUNDRAM Barathan
//

#ifndef IGUI_HPP_
# define IGUI_HPP_

# include <vector>

# define FWD		-1
# define L		0
# define R		1
# define ESCAPE		2
# define ONE		3
# define TWO		4
# define THREE		5

class			IGui
{
public:
  virtual		~IGui() {};
  
  virtual int		initialize(int height, int width, std::vector<int> snake, char* map) = 0;
  virtual int		refresh(std::vector<int> snake, char* map) = 0;
  virtual int		getEvent(void) = 0;
  virtual void	        destroy(void) = 0;
};

#endif /* !IGUI_HPP_ */

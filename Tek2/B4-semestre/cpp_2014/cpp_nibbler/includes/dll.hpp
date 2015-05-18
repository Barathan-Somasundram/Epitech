//
// DynaLibLoder.hpp for  in /home/somasu_b/rendu/cpp_nibbler/sources/algo
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Apr  2 03:39:30 2015 SOMASUNDRAM Barathan
// Last update Fri Apr  3 19:00:54 2015 SOMASUNDRAM Barathan
//

#ifndef DLL_HPP_
# define DLL_HPP_

# include <string>
# include <iostream>
# include <dlfcn.h>
# include "IGui.hpp"

template <typename LIB>
class		        Dll
{
public:
  Dll(std::string libName);
  ~Dll();

  LIB			*create();
  void			free(LIB *gui);
private:
  void			*_handle;
  void			*_new;
  void			*_delete;
};

#endif /* !DLL_HPP_ */

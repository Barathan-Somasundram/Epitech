//
// dll.cpp for  in /home/somasu_b/rendu/cpp_nibbler/sources/algo
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Apr  2 03:39:23 2015 SOMASUNDRAM Barathan
// Last update Fri Apr  3 21:39:51 2015 SOMASUNDRAM Barathan
//

#include "dll.hpp"

template<typename LIB>
Dll<LIB>::Dll(std::string libName)
{
  std::string	tmp;

  tmp = "./" + libName;
  if ((_handle = dlopen(tmp.c_str(), RTLD_LAZY)) == NULL)
    std::cout << dlerror() << std::endl;
  if ((_new = dlsym(_handle, "_new")) == NULL)
    std::cout << dlerror() << std::endl;
  if ((_delete = dlsym(_handle, "_delete")) == NULL)
    std::cout << dlerror() << std::endl;
}

template<typename LIB>
Dll<LIB>::~Dll()
{
  dlclose(_handle);
}

template<typename LIB>
LIB*				Dll<LIB>::create()
{
  LIB*				(*entry)(void);

  entry = reinterpret_cast<LIB *(*)(void)>(_new);
  return (entry());
}

template<typename LIB>
void				Dll<LIB>::free(LIB* gui)
{
  void				(*exit)(LIB*);

  exit = reinterpret_cast<void (*)(LIB*)>(_delete);
  exit(gui);
}

template class Dll<IGui>;

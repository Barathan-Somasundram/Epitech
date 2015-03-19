//
// Container.hpp for  in /home/somasu_b/rendu/piscine_cpp_d17/ex04
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 24 07:33:50 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 24 07:43:56 2015 SOMASUNDRAM Barathan
//

#ifndef CONTAINER_HPP_
# define CONTAINER_HPP_

#include <iostream>
#include <algorithm>
#include <stack>

template <typename X>
void aff(X a) 
{
  std::cout << "Valeur : " << a << std::endl;
}

template <typename X>
void add(X& a) 
{
  a++;
}

template <typename T, template<typename, typename> class Container>
class					contain
{
  Container<T, std::allocator<T> >	container;

  public:
  contain() 
  {
  }
  
  virtual ~contain() 
  {
  }
  
  void push(T a) 
  {
    container.push_back(a);
  }
    
  void aff() 
  {
    std::for_each(container.begin(), container.end(), &::aff<T>);
  }
  
  void add() 
  {
    std::for_each(container.begin(), container.end(), &::add<T>);
  }

};


template<typename T>
void					contain<T, std::stack<T, std::allocator<T> > > :: push(T a)
{
  container.push(a);
}

#endif /* !CONTAINER_HPP_ */

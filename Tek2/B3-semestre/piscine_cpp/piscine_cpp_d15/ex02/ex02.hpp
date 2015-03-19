//
// ex02.hpp for  in /home/somasu_b/rendu/piscine_cpp_d15/ex02
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 21 12:16:52 2015 SOMASUNDRAM Barathan
// Last update Thu Jan 22 06:54:58 2015 SOMASUNDRAM Barathan
//

#ifndef EX02_H_
# define EX02_H_

template <typename X>
X	min(const X& a, const X& b)
{
  std::cout << "template min" << std::endl;
  if (a < b)
    return (a);
  else if (a ==b)
    return (a);
  return (b);
}

int	min(int a, int b)
{
  std::cout << "non-template min" << std::endl;
  if (a < b)
    return (a);
  else if (a ==b)
    return (a);
  return (b);
}

template <typename X>
const X&	nonTemplateMin(const X* array, int size)
{
  int	i = 1;
  X&	mini = const_cast<X&>(array[0]);

  while (i < size)
    {
      mini = min<X>(mini, array[i]);
      i++;
    }
  return (mini);
}

int	templateMin(int *array, int size)
{
  int	i = 1;
  int	mini = array[0];

  while (i < size)
    {
      mini = min(mini, array[i]);
      i++;
    }
  return (mini);
}

#endif /* !EX02_H_ */

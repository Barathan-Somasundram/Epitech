//
// ex00.hpp for  in /home/somasu_b/rendu/piscine_cpp_d15/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 21 09:53:24 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 21 10:01:08 2015 SOMASUNDRAM Barathan
//

#ifndef EX00_H_
# define EX00_H_

template<typename X>
void	swap(X& a, X& b)
{
  X	c = a;

  a = b;
  b = c;
}

template<typename X>
X	min(const X& a, const X& b)
{
  if (a < b)
    return (a);
  else if (a == b)
    return (b);
  else
    return (b);  
}

template<typename X>
X	max(const X& a, const X& b)
{
  if (a < b)
    return (b);
  else if (a == b)
    return (b);
  else
    return (a);  
}

template<typename X>
X	add(const X& a, const X& b)
{
  X	c;

  c = a + b;
  return (c);
}

#endif /* !EX00_H_ */

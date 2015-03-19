/*
** Skat.h for  in /home/somasu_b/rendu/piscine_cpp_d07a/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Jan 13 23:41:27 2015 SOMASUNDRAM Barathan
** Last update Wed Jan 14 02:34:52 2015 SOMASUNDRAM Barathan
*/

#ifndef SKAT_H_
# define SKAT_H_

class Skat
{
 public:
  Skat(std::string const& name, int stimPaks);
  ~Skat();
 public:
  int&  stimPaks();
  const std::string& name();
 public:
  void		shareStimPaks(int number, int& stock);
  void		addStimPaks(unsigned int number);
  void		useStimPaks();
 public:
  void		status();
 private:
  [...];
};

#endif /* !SKAT_H_ */

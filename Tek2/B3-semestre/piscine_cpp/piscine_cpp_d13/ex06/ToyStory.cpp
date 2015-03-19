//
// ToyStory.cpp for  in /home/somasu_b/rendu/piscine_cpp_d13/ex06
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 19 21:58:29 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 20 00:27:34 2015 SOMASUNDRAM Barathan
//

#include <cstring>
#include <fstream>
#include "ToyStory.h"

ToyStory::ToyStory()
{

}

ToyStory::~ToyStory()
{

}

static bool	      		printLine(std::string line, int i,
					  Toy& toy1, bool (Toy::*func1)(std::string const statemt),
					  Toy& toy2, bool (Toy::*func2)(std::string const statemt))
{
  std::string			ascii;
  int				index;

  index = line.find("picture:");
  if (index == 0)
    {
      ascii = line.substr(8);
      if (i % 2)
	{
	  if (!toy1.setAscii(ascii))
	    return (false);
	  std::cout << toy1.getAscii() << std::endl;
	}
      else
	{
	  if (!toy2.setAscii(ascii))
	    return (false);
	  std::cout << toy2.getAscii() << std::endl;
	}
    }
  else
    {
      if (i % 2)
	{
	  if (!(toy1.*func1)(line))
	    return (false);
	}
      else
	{
	  if (!(toy2.*func2)(line))
	    return (false);
	}
    }
  return (true);
}

bool				ToyStory::tellMeAStory(const std::string& filename,
						       Toy& toy1, bool (Toy::*func1)(std::string const statemt),
						       Toy& toy2, bool (Toy::*func2)(std::string const statemt))
{
  std::fstream			file;
  std::string			line;
  int				i = 0;
  char				buf[512];

  std::cout << toy1.getAscii() << std::endl;
  std::cout << toy2.getAscii() << std::endl;
  file.open(filename.c_str());
  while (!file.eof())
    {
      memset(buf, 0, 512);
      file.getline(buf, 512);
      line = buf;
      printLine(line, i, toy1, func1, toy2, func2);
      ++i;
    }

  return (true);
}

//
// Picture.cpp for  in /home/somasu_b/rendu/piscine_cpp_d13/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 19 10:04:16 2015 SOMASUNDRAM Barathan
// Last update Mon Jan 19 11:20:38 2015 SOMASUNDRAM Barathan
//

#include <fstream>
#include "Picture.h"

Picture::Picture()
{
  data = "";
}

Picture::Picture(const Picture& other)
{
  data = other.data;
}

Picture::Picture(const std::string& file)
{
  getPictureFromFile(file);
}

Picture::~Picture()
{

}

bool				Picture::getPictureFromFile(const std::string& file)
{
  std::fstream			files;
  std::string			ascii;

  files.open(file.c_str());
  if (!files.is_open())
    {
      data = "ERROR";
      return (false);
    }
  while (std::getline(files, ascii, '\0'))
    data += ascii;
  return (true);
}

void				Picture::operator=(const Picture& other)
{
  data = other.data;
}

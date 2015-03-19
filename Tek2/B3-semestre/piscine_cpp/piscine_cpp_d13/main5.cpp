#include <iostream>
#include "Toy.h"
#include "Buzz.h"
#include "Woody.h"

int main()
{
  Woody w("wood");

  if (w.setAscii("file_who_does_not_exist.txt") == false)
    {
      Toy::Error e = w.getLastError();
      if (e.type == Toy::Error::PICTURE)
	{
	  std::cout << "Error in " << e.where()
		    << ": " << e.what() << std::endl;
	}
    }
  if (w.speak_es("Woody does not have spanish mode") == false)
    {
      Toy::Error e = w.getLastError();
      if (e.type == Toy::Error::SPEAK)
	{
	  std::cout << "Error in " << e.where()
		    << ": " << e.what() << std::endl;
	}
    }
  if (w.speak_es("Woody does not have spanish mode") == false)
    {
      Toy::Error e = w.getLastError();
      if (e.type == Toy::Error::SPEAK)
	{
	  std::cout << "Error in " << e.where()
		    << ": " << e.what() << std::endl;
	}
    }
  return (0);
}

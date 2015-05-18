#include <unistd.h>
#include <pthread.h>
#include <iostream>

#include "resto.hpp"

pthread_mutex_t			my_mutex;

Cook::Cook(Kitchen *kitchen) : _kitchen(kitchen)
{
  pthread_t	thr;

  pthread_create(&thr, NULL, apply_cook, this);
}

Cook::~Cook()
{

}

void		*Cook::apply_cook(void *param)
{
  Cook		*cook;
  Kitchen	*kitchen;
  int		end;
  int		t;
  int		res;
  int		in;

  cook = reinterpret_cast<Cook *>(param);
  kitchen = cook->_kitchen;

  while (42)
    {
      end = 1;
      while (pthread_mutex_trylock(&my_mutex) != 0);
      for (int i = 0; i < (int)kitchen->getPizza().size() && end; i++)
	{
	  std::cout << "CHECK LIST" << std::endl;
	  t = kitchen->getPizza()[i].getCookTime();
	  for (int j = 0; j <= 8 && end; j++)
	    {
	      if (kitchen->getPizza()[i].getNeeded()[j] == 1)
		{
		  in = i;
		  res = j;
		  end = 0;
		  kitchen->delRessources(j);
		  kitchen->getPizza()[i].delRessources(j, -1);
		  kitchen->addCuisto(-1);
		  std::cout << "COOK WORK => " << res << std::endl;
		}
	    }
	}
      if (pthread_mutex_unlock (&my_mutex) != 0)
	{
	  std::cout << "FAIL UNLOCK" << std::endl;
	  return (NULL);
	}
      if (end == 0)
	{
	  sleep(t);
	  kitchen->getPizza()[in].delRessources(res, -1);
	  kitchen->addCuisto(1);
	}
    }
  return (NULL);
}

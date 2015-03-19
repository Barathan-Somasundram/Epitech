//
// Object.hh for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 10:01:40 2015 SOMASUNDRAM Barathan
// Last update Sun Jan 18 04:46:08 2015 SOMASUNDRAM Barathan
//

#ifndef OBJECT_HH_
#define OBJECT_HH_
#include <iostream>
#include <string>

typedef enum
  {
    LITTLEPONY,
    TEDDY,
    BOX,
    PAPER,
    NOTKNOWN,
  }	types;


class				Object
{
protected:
  std::string			name;
  types				type;
  bool				isTake;

public:
  Object(std::string name = "");
  Object(Object const&);
  virtual ~Object();

  void				operator=(Object const&);

  std::string			getName() const;
  types				getType() const;
  bool				isWrap() const;
  bool				isToy() const;
  bool				getIsTaken() const;
  virtual void			isTaken();

  virtual Object*			wrapMeThat(Object const * &, Object const * &, Object const * &);
  virtual void				openMe();
  virtual void				closeMe();
  virtual bool				isOpen();
  virtual bool				isEmpty()};
  virtual void				fillMe();
};

#endif /* !OBJECT_HH_ */

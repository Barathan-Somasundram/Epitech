/*
** Toy.h for  in /home/somasu_b/rendu/piscine_cpp_d13/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Jan 19 09:48:59 2015 SOMASUNDRAM Barathan
** Last update Mon Jan 19 23:07:51 2015 SOMASUNDRAM Barathan
*/

#ifndef TOY_H_
# define TOY_H_

#include <iostream>
#include <string>
#include "Picture.h"

class				Toy
{
 public:
  typedef enum
  {
    BASIC_TOY,
    ALIEN,
    BUZZ,
    WOODY
  }	ToyType;
  
  class				Error
  {
  public:
    typedef enum
    {
      UNKNOWN,
      PICTURE,
      SPEAK
    }	ErrorType;

    ErrorType			type;

    Error();
    ~Error();
    void			setType(ErrorType);
    std::string			what() const;
    std::string			where() const;
  };

 protected:
  std::string			_Name;
  Picture			_Picture;
  ToyType			_Type;
  Error				_Error;

 public:
  Toy();
  Toy(const Toy&);
  Toy(const ToyType type, const std::string name, const std::string filename);
  ~Toy();

  Toy&				operator=(const Toy&);
  Toy&				operator<<(const std::string&);

  ToyType			getType() const;
  std::string			getName() const;
  std::string			getAscii() const;

  void				setName(std::string name);
  bool				setAscii(std::string filename);

  virtual bool			speak(const std::string);
  virtual bool			speak_es(const std::string);

  Toy::Error const&		getLastError() const;
};

std::ostream&			operator<<(std::ostream&, const Toy&);

#endif /* !TOY_H_ */

//
// Team.hh for  in /home/somasu_b/rendu/cpp_pokemon/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 24 12:16:02 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 24 12:39:48 2015 SOMASUNDRAM Barathan
//

#ifndef TEAM_HH_
# define TEAM_HH_

#include <string>
#include "Pokemon.hh"

class				Team
{
  std::string			_name;
  std::vector<int>		_pokemon;

public:
  Team();
  ~Team();

  void				setName(std::string);
  void				setTeam(std::vector<int>);

  std::string			getName() const;
  std::vector<int>		getTeam() const;
  
};

class				GestionTeam
{
  std::vector<Team>		_Team;
  
public:
  void				reset() const;
  void				save() const;
};


#endif /* !TEAM_HH_ */

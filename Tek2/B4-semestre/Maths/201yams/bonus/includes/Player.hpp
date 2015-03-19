//
// Player.hpp for  in /home/somasu_b/Downloads/ISO/l/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Fri Feb 27 23:40:36 2015 SOMASUNDRAM Barathan
// Last update Sat Feb 28 01:10:47 2015 SOMASUNDRAM Barathan
//

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

class			Player
{
  int			_dice[5];
  int			occur[6];
  int			_score;
  int			_brelan;
  int			_carre;
  int			_full;
  int			_suite;
  int			_yams;
  int			_chance;

  void			setScore(void);
  void			setBrelan(int);
  void			setCarre(int);
  void			setFull(void);
  void			setSuite(void);
  void			setYams(void);

public:
  Player();
  ~Player();

  void			setDice(int);
  void			analyse(void);
  int			getScore(void);
  int			getDice(int);
  int			getBrelan(void);
  int			getCarre(void);
  int			getFull(void);
  int			getSuite(void);
  int			getYams(void);
  int			getChance(void);
};

#endif /* !PLAYER_HPP_ */

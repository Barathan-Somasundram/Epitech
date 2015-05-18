#ifndef NEUTRINOS_HPP_
# define NEUTRINOS_HPP_

class				Neutrinos
{
private:
  double			_nb_mesure;
  double			_moy_arith;
  double			_moy_harmo;
  double			_moy_quadr;
  double			_ecar_type;
  double			_new_mesur;

  double			_sum;
  double			_sum_square;
public:
  Neutrinos(char *p1, char *p2, char *p3, char *p4);
  ~Neutrinos();
  void				reinit_value();
  void				loop_run();
  int				exec(const char *mesur);
  void				calc_nb_mesure();
  void				calc_ecrt_type();
  void				calc_moy_arith();
  void				calc_moy_quadr();
  void				calc_moy_harmo();
  void				print_res();
};

#endif /* !NEUTRINOS_HPP_ */


#ifndef INVENDUS_HPP_
# define INVENDUS_HPP_

class                   Invendus
{
private:
    int                 _param_a;
    int                 _param_b;
    float               _tab_x[5];
    float               _tab_y[5];
public:
    Invendus();
    Invendus(int a, int b);
    ~Invendus();

    void                generate_tab_x_y();
    void                generate_tab_z();
    void                generate_esp_var();
    float               calc_math_proba(int x, int y);
    float               calc_math_P(int z);
    float               calc_esp(float *t, int p);
    float               calc_var(float *t);
};

# endif /* !INVENDUS_HPP_ */
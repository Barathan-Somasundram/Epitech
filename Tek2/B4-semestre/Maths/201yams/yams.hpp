
#include <vector>

enum Type { paire, brelan, carre, full, suite, yams };

class                       Yams {
private:
    std::vector<int>        *combi;
    std::vector<int>        *find;
    int                     size;
    int                     param1;
    int                     param2;
    Type                    type;
public:
    Yams();
    Yams(char **av);
    void                    recup_arg(std::string param);

    void                    calc_proba();
    float                   proba_paire(int param);
    float                   proba_brelan(int param);
    float                   proba_carre(int param);
    float                   proba_full(int param, int param02);
    float                   proba_suite(int param);
    float                   proba_yams(int param);
    void                    recup_dice();
    ~Yams();
};

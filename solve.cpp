#include "functions.h"

using namespace std;


/***** Parametros del problema *****/
int N;
int cl=15;
int M=10;
int alpha_ant=1;
int beta_ant=2;
float q_0=0.5;
float ro=0.5;
float tau_0=1/(10);

/***** Estructuras de representación *****/
vector< vector<int> >  ants;
vector< vector<float> >  alphas;
vector< vector<float> >  betas;
vector< vector<float> >  large;
vector< vector<float> >  ss;
vector< vector<float> >  tau;



int main(int argc, char* argv[]) {

    if( argc != 2){
        cout << "usage: " << argv[0] << "<filename>\n";
        exit(0);
    }
    else{
        int i;
        fill(argv[1]);
    }
    float best_time = 0;    
    float best_distance = 0;
    vector <int> best_tour;

    create_tau(tau);

    vector <int> column;
    for(int i=0; i < M; i++){
       ants.push_back(column);
    }
    for(int j=0; j<10; j++)
        for(int i=0; i<M;i++){
            ants[i].push_back(0);
            while(true){
                int next = next_town(0, ants[i]);
                ants[i].push_back(next);
                if(next==19){
                    break;
                }       
            }
            if (best_time == 0 || time_tour(ants[i]) < best_time ){
                best_time = time_tour(ants[i]);
                best_tour = ants[i];
            }
            ants[i].clear();
            //Ecuacion numero 13:
            //τij (t) = (1 − ρ)τij(t) + ∆τij(t) + ro ∗ ∆τ_{ij}(t)
            //∆τ_{ij}(t)=1/L+
            //tau[i][j] = (1-ro)*tau[i][j] + ro/best_time
            cout << "Tour obtenido en la iteracion " << j << ": ";
            for(std::vector<int>::iterator it = best_tour.begin(); it != best_tour.end(); ++it){
                cout << *it+1 << ",";     
            }
            cout << best_time << endl;
        }

    
    return 0;
}
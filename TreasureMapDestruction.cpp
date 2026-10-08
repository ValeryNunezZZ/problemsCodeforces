
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
//#include <bits/stdc++.h>

using namespace std;

void casito(){
    int n; cin>>n;

    vector<int> mapaViejo(n);

    for(int i=0 ; i<n ; i++) cin>>mapaViejo[i];

    vector<int> rangos(n, 0);
    vector<int> res(n, 0);

    for(int i=0 ; i<n ; i++){
        if(mapaViejo[i] == 0){
            rangos[i] = -1;
            res[i] = 1;
        }else if(mapaViejo[i] != -1){
            bool izqValido = false;
            bool derValido = false;
            
            int izq = 0;
            int der = n-1;

            if(i-mapaViejo[i] >= 0 && i+mapaViejo[i] < n){
                izqValido = true;
                derValido = true;

                izq = i-mapaViejo[i];
                der = i+mapaViejo[i];

                res[der] = 1;
            }else if(i-mapaViejo[i] >= 0){
                izqValido = true;

                izq = i-mapaViejo[i];

                res[izq] = 1;
            }else if(i+mapaViejo[i] < n){
                derValido = true;

                der = i+mapaViejo[i];

                res[der] = 1;
            }else{
                cout<<-1<<endl;
                return;
            }

            //EMPEZAR PONER

            if(rangos[izq] == 0 && rangos[der] == 0){
                //REVISAR QUE ESTE COMPLETAMENTE LIBRE

                rangos[izq] = 1;

                for(int j=izq+1 ; j<=der ; j++){
                    if(rangos[j] == -1 || rangos[j] == 1){
                        cout<<-1<<endl;
                        return;
                    }else{
                        rangos[j] = 1;
                    }
                }
            }else if(rangos[izq] != 0 && rangos[der] != 0){
                cout<<-1<<endl;
                return;
            }else if(rangos[izq] == 0){
                int j = izq+1;

                rangos[izq] = 1; 

                while(j <= der && rangos[j] != 1){
                    if(rangos[j] == -1){
                        cout<<-1<<endl;
                        return;
                    }

                    rangos[j] = 1;

                    j++;
                }
            }else if(rangos[der] == 0){
                int j = der-1;

                rangos[der] = 1;

                while(j >= izq && rangos[j] != 1){
                    if(rangos[j] == -1){
                        cout<<-1<<endl;
                        return;
                    }

                    rangos[j] = 1;

                    j--;
                }
            }
        }
    }

    string respuesta = "";

    for(int i=0 ; i<n ; i++){
        if(res[i] == 0){
            respuesta += '0';
        }else{
            respuesta += '1';
        }
    }

    cout<<respuesta<<endl;
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin>>t;
    
    while (t--){
        casito();
    }
    return 0;
    
}


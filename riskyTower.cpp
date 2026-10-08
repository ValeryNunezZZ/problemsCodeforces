
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

    int n, m; cin>>n>>m;

    vector<int> v(n);

    for(int i=0 ; i<n ; i++) cin>>v[i];

    vector< vector<int> > a(n, vector<int>(m));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>a[i][j];
        }
    }

    //CALCULO DE MENORES POR RANGO

    vector<int> menores(n);
    multiset<int> aux;

    for(int i=0 ; i<n ; i++){
        aux.insert(v[i]);
    }

    int p = v.size()-1;

    for(int i=0 ; i<n ; i++){
        int menor = *aux.begin();

        menores[i] = menor;
        aux.erase(aux.find(v[p]));
        
        p--;
    }
    
    //BUSQUEDA DEL MENOR RESULTADO

    int menorActual = m;

    multiset<int> nums;
    int pos = 0;

    for(int i=n-1 ; i>=0 ; i--){
        for(int j=0 ; j<m ; j++){
            nums.insert(a[i][j]);
        }

        int llevo = 0;
        long long suma = 0;
        int menorBuscado = menores[pos];

        for(auto it=nums.rbegin() ; it!=nums.rend() ; it++){

            if(suma >= menorBuscado){
                menorActual = min(menorActual, llevo);
                break;
            }

            llevo++;

            if(llevo >= m){
                break;
            }

            suma += *it;
        }

        pos++;
    }

    cout<<menorActual<<endl;

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


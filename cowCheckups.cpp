
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

    vector<int> a(n);
    vector<int> b(n);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n ; i++) cin>>b[i];

    vector<int> cuantos(n+1, 0);

    int l = 0, r = n-1;
    int fuera = 0;

    //CHEQUEO PRIMERA PARTE

    //POR CADA GRUPO
    while(l < n){

        //CALCULO DE LOS NUMEROS FUERA DEL RANGO
        
        if(l-1 >= 0 && a[l-1] == b[l-1]) fuera++;

        int porGrupo = fuera;

        //CHECAR DENTRO DEL RANGO

        int contrario = n-1;

        for(int i=l ; i<n ; i++){
            if(a[i] == b[contrario]){
                porGrupo++;
            }

            contrario--;
        }

        cuantos[porGrupo]++;

        int rAux = r;
        int lAux = l;

        while(rAux-1 > lAux){

            if(a[rAux] == b[lAux] && b[rAux] == a[lAux]){
                porGrupo -= 2;
            }else if(a[rAux] == b[lAux] || b[rAux] == a[lAux]){
                porGrupo -=1;
            }

            if(a[rAux] == b[rAux]) porGrupo++;
            if(a[lAux] == b[lAux]) porGrupo++;

            cuantos[porGrupo]++;

            rAux--;
            lAux++;
        }

        l++;
    }

    //LA PARTE QUE FALTA

    l = 0, r = n-2; //checar que no est'e mal
    fuera = 0;

    //CHEQUEO PRIMERA PARTE

    //POR CADA GRUPO
    while(r >= 0){

        //CALCULO DE LOS NUMEROS FUERA DEL RANGO
        
        if(r+1 < n && a[r+1] == b[r+1]) fuera++;

        int porGrupo = fuera;

        //CHECAR DENTRO DEL RANGO

        int contrario = 0;

        for(int i=r ; i>=0 ; i--){
            if(a[i] == b[contrario]){
                porGrupo++;
            }

            contrario++;
        }

        cuantos[porGrupo]++;

        int rAux = r;
        int lAux = l;

        while(rAux-1 > lAux){

            if(a[rAux] == b[lAux] && b[rAux] == a[lAux]){
                porGrupo -= 2;
            }else if(a[rAux] == b[lAux] || b[rAux] == a[lAux]){
                porGrupo -=1;
            }

            if(a[rAux] == b[rAux]) porGrupo++;
            if(a[lAux] == b[lAux]) porGrupo++;

            cuantos[porGrupo]++;

            rAux--;
            lAux++;
        }

        r--;
    }

    for(int i=0 ; i<=n ; i++){
        cout<<cuantos[i]<<endl;
    }
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin>>t
    
    while (t--){
        casito();
    }
    return 0;
    
}
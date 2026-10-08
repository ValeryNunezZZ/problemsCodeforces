
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
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string cadena; cin>>cadena;

    char letra = 'A';
    int pares = 0;

    while(letra <= 'Z'){
        int inicio = 0, fin = 0;

        //ENCONTRAR INICIO Y FIN
        while(cadena[inicio] != letra) inicio++;
        
        fin = inicio + 1;

        while(cadena[fin] != letra) fin++;

        //ITERAR ENTRE INICIO Y FIN

        for(int i=inicio+1 ; i<fin ; i++){
            char letraMiddle = cadena[i];

            int aux = i+1;

            while(aux < 52 && cadena[aux] != letraMiddle) aux++;

            if(aux > fin && cadena[aux] == letraMiddle) pares++;
        }

        letra++;
    }

    cout<<pares<<endl;

}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin>>t;
    
    while (t--){
        casito();
    }
    return 0;
    
}


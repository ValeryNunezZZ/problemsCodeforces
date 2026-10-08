
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

void casito(int caso){
    int n; cin>>n;
    string cadena; cin>>cadena;

    if(cadena[0] == '1'){
        int ceros = 0;

        for(int i=0 ; i<n ; i++){
            if(cadena[i] == '0') ceros++;
        }

        cout<<ceros<<endl;
        return;
    }


    vector<int> prefixCeros(n);
    vector<int> prefixUnos(n);

    prefixCeros[0] = 1;
    prefixUnos[0] = 0;

    for(int i=1 ; i<n ; i++){
        if(cadena[i] == '1'){
            prefixCeros[i] = prefixCeros[i-1];
            prefixUnos[i] = prefixUnos[i-1] + 1;
        }else{
            prefixUnos[i] = prefixUnos[i-1];
            prefixCeros[i] = prefixCeros[i-1] + 1;
        }
    }

    //BUSCAR EL PRIMER 1

    int pos = 0;

    while(pos < n && cadena[pos] == '0'){
        pos++;
    }

    if(pos == n){
        cout<<0<<endl;
        return;
    }

    //BUSCAR LA MEJOR DIVISION

    int menor = INT_MAX;

    for(int i=pos ; i<n ; i++){
        int aux = prefixCeros[n-1] - prefixCeros[i-1] + prefixUnos[i-1];

        menor = min(aux, menor);
    }

    //O TODO 0'S

    int aux = prefixUnos[n-1];

    menor = min(menor, aux);

    cout<<menor<<endl;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin>>t;

    int caso = 0;

    while (t--){
        caso++;
        casito(caso);
    }
    return 0;
    
}
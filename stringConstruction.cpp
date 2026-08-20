
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
    
    int n, k; cin>>n>>k;

    int unos, ceros;

    if(n%2 == 1){
        unos = n/2;
        ceros = n/2 + 1;
    }else{
        unos = n/2;
        ceros = unos;
    }

    int maximo = unos - 1 + ceros - 1;

    if(k > maximo){
        cout<<-1<<endl;
        return;
    }

    if(k == maximo){
        for(int i=0 ; i<unos ; i++){
            cout<<1;
        }

        for(int i=0 ; i<ceros ; i++){
            cout<<0;
        }

        cout<<endl;

        return;
    }

    //ENCONTRAR EL NUMERO
    int valor = maximo - 1;
    int cuantos = 1;
    bool primero = false;
    int pos = 0;

    while(pos < unos-1){
        
        if(k == valor || k == valor - 1){
            if(k == valor) primero = true;
            break;
        }

        valor -= 2;

        cuantos++;
        pos++;
    }

    if(k == valor || k == valor - 1){
        if(primero){
            int auxUnos = unos;
            int auxCeros = ceros;

            for(int i=0 ; i<cuantos; i++){
                cout<<1;
                cout<<0;
                
                auxUnos--;
                auxCeros--;
                
            }

            for(int i=0 ; i<auxCeros ; i++){
                cout<<0;
            }

            for(int i=0 ; i<auxUnos ; i++){
                cout<<1;
            }

            cout<<endl;
        }else{
            int auxUnos = unos;
            int auxCeros = ceros;

            for(int i=0 ; i<cuantos; i++){
                cout<<0;
                cout<<1;

                auxCeros--;                
                auxUnos--;
            }

            for(int i=0 ; i<auxCeros ; i++){
                cout<<0;
            }

            for(int i=0 ; i<auxUnos ; i++){
                cout<<1;
            }

            cout<<endl;
        }
    }else{
        for(int i=0 ; i<unos + ceros ; i++){
            if(i%2 == 1){
                cout<<1;
            }else{
                cout<<0;
            }
        }

        cout<<endl;

        return;
    }
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

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

    //valor, posicion
    vector< vector< pair<int, int> > > arbol(n);

    for(int i=0 ; i<=n-2 ; i++){

        int u, v; cin>>u>>v;

        u--;
        v--;

        arbol[u].push_back(make_pair(v, i));
        arbol[v].push_back(make_pair(u, i));
    }

    int nodoUno = -1;
    int posAux = -1;

    for(int i=0 ; i<n ; i++){
        if(arbol[i].size() > 2){
            cout<<-1<<endl;
            return;
        }

        if(arbol[i].size() == 1){
            nodoUno = i;
        }
    }

    //1 ES VISITADO
    vector<int> visitados(n, 0);
    queue<int> cola;

    //RECORRIDO DEL BAMBOO

    cola.push(nodoUno);

    int anterior = 5;

    vector<int> res(n-1);

    while(!cola.empty()){

        int nodo = cola.front();
        cola.pop();

        visitados[nodo] = 1;

        for(int i=0 ; i<arbol[nodo].size() ; i++){
            if(visitados[arbol[nodo][i].first] == 0){
                cola.push(arbol[nodo][i].first);

                if(anterior == 5){
                    res[arbol[nodo][i].second] = 2;
                    anterior = 2;
                }else{
                    res[arbol[nodo][i].second] = 5;
                    anterior = 5;
                }
            }
        }    
    }

    for(int i=0 ; i<res.size() ; i++){
        cout<<res[i]<<" ";
    }

    cout<<endl;
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
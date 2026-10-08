
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

int n, m;

void dfs(int color, vector<string> & cadena, vector< vector<int> > & visitados, int fila, int columna){
    vector< pair<int, int> > pos = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};

    visitados[fila][columna] = color;

    for(int i=0 ; i<pos.size() ; i++){
        int auxFila = fila + pos[i].first;
        int auxColumna = columna + pos[i].second;
        
        if(auxFila >= 0 && auxFila < n && auxColumna < m && auxColumna >= 0 && visitados[auxFila][auxColumna] == 0 && cadena[auxFila][auxColumna] == '.') dfs(color, cadena, visitados, auxFila, auxColumna);
    }
}

void casito(){

    cin>>n>>m;

    vector<string> cadena(n);
    vector< vector<int> > visitados(n, vector<int>(m, 0));

    for(int i=0 ; i<n ; i++) cin>>cadena[i];

    int color = 0;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(visitados[i][j] == 0 && cadena[i][j] == '.'){
                color++;
                dfs(color, cadena, visitados, i, j);
            }
        }   
    }

    cout<<color<<endl;
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


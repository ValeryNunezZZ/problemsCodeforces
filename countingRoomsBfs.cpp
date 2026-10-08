
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

void bfs(vector<string> & candenas, vector< vector<int> > & visitados, int fila, int columna, int color){
    queue< pair<int, int> > cola;

    vector< pair<int, int> > pos = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};

    cola.push(make_pair(fila, columna));

    while(!cola.empty()){
        pair<int, int> tomado = cola.front();
        cola.pop();

        visitados[tomado.first][tomado.second] = color;

        for(int i=0 ; i<pos.size() ; i++){

            int auxFila = tomado.first + pos[i].first;
            int auxColumna = tomado.second + pos[i].second;

            if(auxFila < n && auxFila >= 0 && auxColumna < m && auxColumna >= 0 && visitados[auxFila][auxColumna] == 0 && candenas[auxFila][auxColumna] == '.'){
                cola.push(make_pair(auxFila, auxColumna));
            }
        }

    }
}

void casito(){
    cin>>n>>m;

    vector<string> cadenas(n);
    vector< vector<int> > visitados(n, vector<int>(m, 0));

    for(int i=0 ; i<n ; i++) cin>>cadenas[i];

    int color = 0;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(cadenas[i][j] == '.' && visitados[i][j] == 0){
                color++;
                bfs(cadenas, visitados, i, j, color);
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

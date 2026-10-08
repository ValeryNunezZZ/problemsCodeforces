
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

void bfs(vector< vector<int> > & matriz, vector<int> & visitados, int color, int nodo){

    queue<int> cola;
    cola.push(nodo);

    while(!cola.empty()){
        int actual = cola.front();
        cola.pop();

        visitados[actual] = color;

        for(int j=0 ; j<matriz[actual].size() ; j++){
            if(visitados[matriz[actual][j]] == 0){
                cola.push(matriz[actual][j]);
            }
        }  
    }


}

void casito(){
    cin>>n>>m;

    vector< vector<int> > matriz(n);
    vector<int> visitados(n, 0);

    for(int i=0 ;  i<m ; i++){
        int a, b; cin>>a>>b;

        a--;
        b--;

        matriz[a].push_back(b);
        matriz[b].push_back(a);
    }

    int color = 0;

    for(int i=0 ; i<n ; i++){
        if(visitados[i] == 0){
            color++;
            bfs(matriz, visitados, color, i);
        } 
    }

    cout<<color-1<<endl;

    if(color - 1 == 0) return;

    vector<int> res(color+1);

    for(int i=0 ; i<n ; i++){
        res[visitados[i]] = i;
    }

    //IMPRIMIR RES

    cout<<res[1]+1<<" ";

    for(int i=2 ; i<color ; i++){
        cout<<res[i]+1<<endl;
        cout<<res[i]<<" ";
    }

    cout<<res[color]+1<<endl;
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

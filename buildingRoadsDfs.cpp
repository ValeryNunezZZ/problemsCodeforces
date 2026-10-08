
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

void dfs(vector< vector<int> > & matriz, vector<int> & visitados, int color, int nodo){
    visitados[nodo] = color;

    for(int i=0 ; i<matriz[nodo].size() ; i++){
        if(visitados[matriz[nodo][i]] == 0){
            dfs(matriz, visitados, color, matriz[nodo][i]);
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
            dfs(matriz, visitados, color, i);
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
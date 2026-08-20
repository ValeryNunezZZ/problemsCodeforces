
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

    int n, m; cin>>n>>m;

    vector<int> a(n);
    vector<int> b(m);

    vector<int> aVisitados(n, 0);
    vector<int> bVisitados(m, 0);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<m ; i++) cin>>b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int posA = a.size()-1;
    int posB = b.size()-1;

    while(posB >= 0){

        int buscado = b[posB];
        
        auto iterador = lower_bound(a.begin(), a.end(), buscado);

        if(iterador != a.end() && *iterador == buscado){
            aVisitados[iterador-a.begin()] = 1;
            bVisitados[posB] = 1;
        }

        posB--;
    }

    //JUNTAR LOS NO VISITADOS

    vector<int> aResto;
    vector<int> bResto;

    for(int i=0 ; i<n ; i++){
        if(aVisitados[i] == 0){
            aResto.push_back(a[i]);
        }
    }

    for(int i=0 ; i<m ; i++){
        if(bVisitados[i] == 0){
            bResto.push_back(b[i]);
        }
    }

    posA = aResto.size()-1;
    posB = bResto.size()-1;

    if(aResto.size()/2 < bResto.size()){
        cout<<"NO"<<endl;
        return;
    }

    while(posB >= 0){
        if(aResto[posA] > bResto[posB]){
            posA--;
            posB--;
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }

    posA = 0;
    posB = 0;

    while(posB < bResto.size()){
        if(aResto[posA] < bResto[posB]){
            posA++;
            posB++;
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
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
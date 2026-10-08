
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

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n; cin>>k>>n;

    vector< vector<int> > vacas(k, vector<int>(n));

    for(int i=0 ; i<k ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>vacas[i][j];
        }
    }

    map< pair<int, int> , int > contadores;

    for(int i=0 ; i<k ; i++){
        for(int j=0 ; j<n ; j++){
            for(int k=j+1 ; k<n ; k++){
                contadores[make_pair(vacas[i][j], vacas[i][k])]++;
            }
        }
    }

    int res = 0;
    
    for(auto i : contadores){
        if(i.second == k) res++;
    }

    cout<<res<<endl;
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


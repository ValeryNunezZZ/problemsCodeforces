
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

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin>>n>>m;

    vector<string> cadenas(2*n);

    for(int i=0 ; i<2*n ; i++) cin>>cadenas[i];

    bool bandera = false;
    int res = 0;

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            for(int k=0+n ; k<2*n ; k++){
                if(cadenas[j][i] == cadenas[k][i]){
                    //cout<<cadenas[j][i]<<" : "<<cadenas[k][i]<<" columna : "<<i<<endl;
                    bandera = true;
                    break;
                }
            }

            if(bandera) break;
        }

        if(!bandera){
            res++;
        }

        bandera = false;
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


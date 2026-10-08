
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

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n, b; cin>>n>>b;

    vector< pair<int, int> > coordenadas(n);

    for(int i=0 ; i<n ; i++){
        int x, y; cin>>x>>y;
        coordenadas[i] = make_pair(x, y);
    }

    int res = INT_MAX;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            int primero = 0, segundo = 0, tercero = 0, cuarto = 0;

            int x = coordenadas[i].first;
            int y = coordenadas[j].second;
            
            for(int k=0 ; k<n ; k++){

                auto[f, c] = coordenadas[k];

                if(f <= x && c <= y){
                    primero++;
                }else if(f <= x && c > y){
                    segundo++;
                }else if(f > x && c <= y){
                    tercero++;
                }else{
                    cuarto++;
                }
            }

            int actual = max(primero, segundo);
            actual = max(actual, tercero);
            actual = max(actual, cuarto);

            res = min(actual, res);
        }
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
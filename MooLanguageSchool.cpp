
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

    int n, k; cin>>n>>k;
    string cadena; cin>>cadena;

    int res = 0;
    int i = 0;

    while(i < n){
        int cont = 0;
        int alMenosUno = false;

        while(cont < k){
            if(cadena[i] == '0'){
                alMenosUno = true;
            }

            cont++;
            i++;
        }

        if(!alMenosUno) res++;
    }

    cout<<res<<endl;
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



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
    string cadena; cin>>cadena;

    string nueva = "";
    int pos = 0;

    while(pos < n){
        char anterior = cadena[pos];
        nueva += anterior;
        
        while(pos < n && cadena[pos] == anterior) pos++;
    }

    if(nueva.size() == 2){
        cout<<2<<endl;
    }else{
        cout<<1<<endl;
    }
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

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
    int n;
    cin>>n;

    int anterior;
    int h; 
    bool diferente = false;
    int menor = 10;
    int mayor = -1;

    for(int i=0 ; i<n ; i++){
        cin>>h;
        
        menor = min(menor, h);
        mayor = max(mayor, h);

        if(i == 0) anterior = h;
        
        if(anterior != h) diferente = true;
    }

    if(!diferente){
        cout<<1<<endl;
        return;
    }

    cout<<mayor - menor + 1<<endl;
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
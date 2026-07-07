
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

    if(n%2 == 1){
        int enMedio = ceil((double) n/2);

        cout<<enMedio<<" ";

        for(int i=n ; i>=1 ; i--){
            cout<<i<<" ";
        }

        for(int i=1 ; i<=n ; i++){
            cout<<i<<" ";
        }

        for(int i=n ; i>=1 ; i--){
            if(i != enMedio) cout<<i<<" ";
        }

        for(int i=n ; i>=1 ; i--){
            if(i != enMedio) cout<<i<<" ";
        }

        cout<<enMedio<<" ";

        cout<<endl;

        return;
    }

    for(int i=n ; i>=1 ; i--){
        cout<<i<<" ";
    }

    for(int i=1 ; i<=n ; i++){
        cout<<i<<" ";
    }

    for(int i=n ; i>=1 ; i--){
        cout<<i<<" ";
    }

    for(int i=n ; i>=1 ; i--){
        cout<<i<<" ";
    }

    cout<<endl;
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
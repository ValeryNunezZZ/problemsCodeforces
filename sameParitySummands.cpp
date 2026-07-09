
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

    vector<int> aPar(k, 2);
    vector<int> aImpar(k, 1);

    if(2*k > n && k > n){
        cout<<"NO"<<endl;
        return;
    }

    int resto = n - 2*k;

    if(2*k <= n && resto%2 == 0){
        cout<<"YES"<<endl;
        cout<<aPar[0] + resto<<" ";

        for(int i=1 ; i<k ; i++){
            cout<<aPar[i]<<" ";
        }

        cout<<endl;

        return;
    }
    
    resto = n - k;

    if(k <= n && resto%2 == 0){
        cout<<"YES"<<endl;
        cout<<aImpar[0] + resto<<" ";

        for(int i=1 ; i<k ; i++){
            cout<<aImpar[i]<<" ";
        }

        cout<<endl;

        return;
    }else{
        cout<<"NO"<<endl;
        return;
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
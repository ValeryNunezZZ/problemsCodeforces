
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

    int n; cin>>n;

    vector<int> a(n);

    for(int i=0 ; i<n ; i++) cin>>a[i];

    if(n%2 == 1){
        cout<<"NO"<<endl;
        return;
    }

    int negativos = 0;
    int positivos = 0;

    for(int i=0 ; i<n ; i++){
        if(a[i] == -1){
            negativos++;
        }else{
            positivos++;
        }
    }

    int menor = min(negativos, positivos);

    if((n/2 - menor) % 2 == 1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    
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
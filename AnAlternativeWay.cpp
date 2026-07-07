
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

    vector<long long> a(n);
    vector<long long> b(n);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n ; i++) cin>>b[i];

    long long llevo = 0;

    for(int i=n-1 ; i>0 ; i--){
        a[i] += llevo;

        llevo = 0;

        if(a[i] > b[i]){
            llevo = a[i] - b[i];
        }
    }

    a[0] += llevo;

    if(a[0] > b[0]){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
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
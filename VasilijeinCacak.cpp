
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
    long long x; cin>>x;

    long long l = 0;
    long long r = 0;

    l = (long long)k * (k+1) / 2;
    r = (long long)n * (n+1) / 2;
    r -= (long long)(n-k) * (n-k+1) / 2;

    if(x >= l && x <= r){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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
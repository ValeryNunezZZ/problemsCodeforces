
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

    if(n <= 3){
        cout<<-1<<endl;
        return;
    }

    int primero;

    if(n%2 == 0){
        primero = 2;
    }else{
        primero = 1;
    }

    for(int i=primero ; i<=n ; i+=2){
        cout<<i<<" ";
    }

    cout<<n-3<<" "<<n-1<<" ";

    for(int i=n-5 ; i>=1 ; i-=2){
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
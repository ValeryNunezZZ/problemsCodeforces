
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

    bool sePuede = false;
    int dosOMayor = 0;

    for(int i=0 ; i<n ; i++){
        int c; cin>>c;

        if(c >= 2) dosOMayor++;
        if(c >= 3) sePuede = true;
    }

    if(sePuede || dosOMayor >= 2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin>>t;

    //2168...
    
    while (t--){
        casito();
    }
    return 0;
    
}
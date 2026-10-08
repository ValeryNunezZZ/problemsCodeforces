
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

    vector<int> a(n);

    int ceros = 0;

    for(int i=0 ; i<n ; i++){
        cin>>a[i];

        if(a[i] == 0) ceros++;
    }

    if(ceros == 1){
        cout<<"NO"<<endl;
        return;
    }

    //1. A = 1 cero
    //2. B = Los restantes
    //3. C = Todo lo que no sea cero

    string res = "";

    int ACeros = 0;

    cout<<"YES"<<endl;

    for(int i=0 ; i<n ; i++){
        if(a[i] == 0 && ACeros == 0){
            res += 'A';
            ACeros++;
        }else if(a[i] == 0){
            res += 'B';
        }else{
            res += 'C';
        }
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


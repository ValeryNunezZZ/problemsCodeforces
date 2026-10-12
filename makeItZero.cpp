
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

    for(int i=0 ; i<n ; i++){
        cin>>a[i];
    }

    if(n%2 == 0){
        cout<<2<<endl;

        cout<<1<<" "<<n<<endl;
        cout<<1<<" "<<n<<endl;

        return;
    }

    cout<<4<<endl;
    cout<<1<<" "<<n<<endl;
    cout<<2<<" "<<n<<endl;
    cout<<1<<" "<<2<<endl;
    cout<<1<<" "<<2<<endl;
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
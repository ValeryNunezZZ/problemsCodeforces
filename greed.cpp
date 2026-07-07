
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

    vector<int> b(n);

    long long total = 0;

    for(int i=0 ; i<n ; i++){
        int a; cin>>a;

         total += a;
    }

    for(int i=0 ; i<n ; i++) cin>>b[i];

    sort(b.begin(), b.end());

    int mayores = b[n-1] + b[n-2];

    if(mayores >= total){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    
    while (t--){
        casito();
    }
    return 0;
    
}
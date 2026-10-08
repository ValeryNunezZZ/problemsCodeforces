
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

    vector<int> nums(n);

    for(int i=0 ; i<n ; i++) cin>>nums[i];

    int impares = 0;
    int llegaEnPar = 0;
    int llegaEnImpar = 0;

    for(int i=0 ; i<n ; i++){
        if(nums[i]%2 == 1){
            impares++;
        }else if(nums[i]%2 == 0 && (((nums[i]-2)/2)) % 2 == 0){
            llegaEnPar++;
        }else{
            llegaEnImpar++;
        }
    }

    int res = max(impares, llegaEnPar);

    cout<<max(res, llegaEnImpar)<<endl;
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


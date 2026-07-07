
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

    vector<long long> nums(n);

    for(int i=0 ; i<n ; i++) cin>>nums[i];

    long long res = nums[0];

    for(int i=0 ; i<n-1; i++){
        if(res > nums[i+1]){
            res += nums[i+1];
        }else{
            res = nums[i+1];
        }
    }

    cout<<res<<endl;

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
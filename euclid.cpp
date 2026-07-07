
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

    sort(nums.begin(), nums.end());

    for(int i=n-1 ; i>1 ; i--){
        if(nums[i]%nums[i-1] != nums[i-2]){
            cout<<-1<<endl;
            return;
        }
    }

    cout<<nums[n-1]<<" "<<nums[n-2]<<endl;
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
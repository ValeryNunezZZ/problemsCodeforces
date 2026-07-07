
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

    vector<int> nums(n);

    for(int i=0 ; i<n ; i++) cin>>nums[i];

    sort(nums.begin(), nums.end());

    int pos = n-1;

    while(pos >= 0){
        int ant = nums[pos];
        int cuantos = 0;

        while(pos >= 0 && ant == nums[pos]){
            cuantos++;
            pos--;
        }

        if(cuantos%2 == 0){
            cout<<"YES"<<endl;
            return;
        }else if(pos >= 0 && ant - nums[pos] <= k){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
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
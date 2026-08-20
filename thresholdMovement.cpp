
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

void casito(int caso){
    int n; cin>>n;

    vector<int> nums(n);

    int mayores = INT_MAX;
    int menores = -1;

    for(int i=0 ; i<n ; i++){
        cin>>nums[i];

        if(i%2 == 0){
            mayores = min(nums[i], mayores);
        }else{
            menores = max(nums[i], menores);
        }
    }

    if(n%2 == 1){
        cout<<"NO"<<endl;
        return;
    }

    int res = menores + 1;

    if(res >= mayores){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin>>t;

    int caso = 0;

    while (t--){
        caso++;
        casito(caso);
    }
    return 0;
    
}
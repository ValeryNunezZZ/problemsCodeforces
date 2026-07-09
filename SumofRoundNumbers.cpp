
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

    int chequeo = 1;

    while(chequeo < n){
        chequeo *= 10;
    }

    if(n == 1){
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }

    chequeo /= 10;

    vector<int> nums;

    while(chequeo > 0){
        int num = n/chequeo;

        nums.push_back(num);

        n -= num * chequeo;
        chequeo /= 10;
    }

    int k = 0;

    for(int i=nums.size()-1 ; i>=0 ; i--){
        if(nums[i] != 0){
            k++;
        }
    }

    cout<<k<<endl;

    for(int i=nums.size()-1 ; i>=0 ; i--){
        if(nums[i] != 0){
            int exp = (nums.size() - i - 1);
            int b = (int) pow(10, exp) * nums[i];

            cout<<b<<" ";
        }
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
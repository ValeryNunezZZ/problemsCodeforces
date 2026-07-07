
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
    string cadena; cin>>cadena;

    vector<char> nums(n);
    
    for(int i=0 ; i<n ; i++) nums[i] = cadena[i];

    for(int i=0 ; i<n-k ; i++){
        if(nums[i] == '1'){
            if(nums[i+k] == '1'){
                nums[i+k] = '0';
            }else{
                nums[i+k] = '1';
            }
        }
    }

    for(int i=n-k ; i<n ; i++){
        if(nums[i] == '1'){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    return;
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
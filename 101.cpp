
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

    int primerUno = -1;
    int ultimoUno = -1;
    int i = 0;

    while(i<n && primerUno == -1){
        if(nums[i] == 1 || nums[i] == -1){
            primerUno = i;
            break;
        }

        i++;
    }

    i = n-1;

    while(i>=0 && ultimoUno == -1){
        if(nums[i] == 1 || nums[i] == -1){
            ultimoUno = i;
            break;
        }

        i--;
    }

    vector<int> res(n);

    for(int i=0 ; i<n ; i++){
        if(i == primerUno || i == ultimoUno){
            cout<<1<<" ";
        }else if(nums[i] == -1){
            cout<<0<<" ";
        }else{
            cout<<nums[i]<<" ";
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


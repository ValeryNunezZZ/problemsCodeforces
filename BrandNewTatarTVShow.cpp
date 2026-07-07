
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

    vector<int> pos;

    for(int i=0 ; i<n-1 ; i++){
        if(nums[i] > nums[i+1]){
            pos.push_back(i);
        }
    }

    pos.push_back(nums.size()-1);

    vector<int> faltan(pos.size(), 0);
    vector<int> acumulado(pos.size(), 0);

    int finalPos = n-1;

    for(int i=pos.size()-2 ; i>=0 ; i--){

        int p = pos[i];
        int base = nums[p];

        while(p < pos[i+1] && base > nums[p+1]){
            base += nums[p+1];
            p++;
        }

        if(p == pos[i+1]){
            if(base > nums[i+1] + faltan[i+1]){
                finalPos = i;
            }
        }else{
            while(p < pos[i+1]){
                if(base <= nums[p+1]){
                    int aux = nums[p+1] - base + 1;
                    faltan[i] += aux;
                    base += nums[p+1] + aux;
                }else{
                    base += nums[p+1];
                }

                p++;
            }
        }

        faltan[i] += faltan[i+1];
    }

    int minRes = 0;

    for(int i=finalPos ; i<n ; i++){
        minRes += nums[i];
    }

    cout<<"pos = "<<finalPos<<endl;

    cout<<minRes<<endl;

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
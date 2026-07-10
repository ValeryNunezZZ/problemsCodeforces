
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

    for(int i=0 ; i<n ; i++) cin>>nums[i];

    int res = 0;

    for(int i=0 ; i<n ; i++){
        int left = 0;
        int right = 0;
        long long acum = 0;
        
        while(1){
            while(right < n && acum < nums[i]){
                acum += nums[right];
                right++;
            }

            if(acum == nums[i] && left != right-1 && left != right){
                res++;/* 
                cout<<"num = "<<nums[i]<<endl; */
                break;
            }

            int ant = acum;

            while(left < right && (acum > nums[i] || ant == nums[i])){
                /* if(nums[i] == 5){
                    cout<<"acum = "<<acum<<endl;
                                cout<<"left = "<<left<<endl;
            cout<<"right = "<<right<<endl;
            cout<<endl;
                } */
                acum -= nums[left];
                left++;
            }

            /*
1 5
5 2 1 1 4
            */

/*             cout<<"num = "<<nums[i]<<endl;
            cout<<"left = "<<left<<endl;
            cout<<"right = "<<right<<endl;
            cout<<endl;
 */

             if(acum == nums[i] && left != right-1 && left != right){
                res++;/* 
                cout<<"num = "<<nums[i]<<endl; */
                break;
            }
            
            if(right == n){
                break;
            }
        }
    }

/*     if(caso == 41){
        for(int i=0 ; i<n ; i++){
            cout<<nums[i];
        }
        cout<<endl;
        return;
    } */
    cout<<res<<endl;
}
/*1 8
5 4 5 6 7 4 2 5
 */
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
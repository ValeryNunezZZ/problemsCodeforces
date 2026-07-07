
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

    vector<int> nums(n + 1);
    vector<int> matados(n + 1, 0);
    
    for(int i=1 ; i<=n ; i++) cin>>nums[i];

    for(int i=n ; i>0 ; i--){
        if(nums[i] > 0){
            int posMenor = i - nums[i];

            if(posMenor <= 0) posMenor = 1;

            for(int j=i-1 ; j>=posMenor; j--){
                matados[j] = 1;

                if(j - nums[j] < posMenor){
                    posMenor = j - nums[j]; 

                    if(j - nums[j] <= 0) posMenor = 1;
                }
            }

            i = posMenor;
        }
    }

    int vivos = 0;

    for(int i=1 ; i<=n ; i++){
        if(matados[i] == 0) vivos++;
    }

    cout<<vivos<<endl;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    
    while (t--){
        casito();
    }
    return 0;
    
}
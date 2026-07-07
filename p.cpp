
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

    int limMax = nums[n-1];

    int arriba = limMax + k - 1;
    int abajo = limMax;
    int res = abajo;

    for(int i=0 ; i<n-1 ; i++){
        double dif = limMax - nums[i] + 1;
        
        if(ceil(dif/k) * k + nums[i] - 1 == limMax && (int) ceil(dif/k)%2 == 1){
        //NEGRO IGUAL

            arriba = min(arriba, limMax);
            abajo = max(abajo, limMax);

            if(abajo > arriba){
                cout<<-1<<'\n';
                return;
            }else{
                res = abajo;
            }
        }else if(ceil(dif/k) * k + nums[i] - 1 == limMax && (int) ceil(dif/k)%2 == 0){
        //BLANCO IGUAL
            int siguienteMenor = limMax + 1;
            int siguienteMayor = siguienteMenor + k - 1;
                
            
            arriba = min(arriba, siguienteMayor);
            abajo = max(abajo, siguienteMenor);

            if(abajo > arriba){
                cout<<-1<<'\n';
                return;
            }else{
                res = abajo;
            }
        }else if((int) ceil(dif/k)%2 == 1){
        //NEGRO MAYOR//CAMBIE

            arriba = min(arriba, (int) ceil(dif/k) * k + nums[i] - 1);
            abajo = max(abajo, limMax);

            if(abajo > arriba){
                cout<<-1<<'\n';
                return;
            }else{
                res = abajo;
            }
        }else{
        //BLANCO MAYOR

            int siguienteMenor = ceil(dif/k) * k + nums[i];
            int siguienteMayor = siguienteMenor + k - 1;
                
            
            arriba = min(arriba, siguienteMayor);
            abajo = max(abajo, siguienteMenor);

            if(abajo > arriba){
                cout<<-1<<'\n';
                return;
            }else{
                res = abajo;
            }
        }
    }

    cout<<res<<endl;
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
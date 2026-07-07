
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
    vector<int> visitados(n, 0);

    for(int i=0 ; i<n ; i++) cin>>nums[i];

    for(int i=0 ; i<n ; i++){
        
        int pos = 0;
        int menor = INT_MAX;

        for(int k=0 ; k<n ; k++){
            if(visitados[k] == 0){
                if(nums[k] < menor){
                    menor = nums[k];
                    pos = k;
                }
            }
        }

        //BUSCAR EL SIGUIENTE MAYOR
        for(int j=pos ; j<n ; j++){
            if(nums[j] > nums[pos]){
                nums[j] = nums[pos];
                break;
            }
        }

        visitados[pos] = 1;
        
    }

    int suma = 0;

    for(int i=0 ; i<n ; i++) suma += nums[i];
    
    cout<<suma<<endl;
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
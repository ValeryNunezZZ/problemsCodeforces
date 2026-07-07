
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

    vector<int> cambios;

    int anterior;
    int pos = 0;
    int cuantos;

    while(pos < n){
        anterior = nums[pos];
        cuantos = 0;
        
        while(pos < n && anterior == nums[pos]){
            cuantos++;
            pos++;
        }

        cambios.push_back(cuantos);
    }

    sort(cambios.begin(), cambios.end());

    for(int i=0 ; i<cambios.size() ; i++){
        cout<<cambios[i]<<" ";
    }

    int marcados = cambios.size();
    int posCambios = 0;
    int res = 0;
    int total = n;
    int menosCuanto = 0;

    while(posCambios < cambios.size()){
                cout<<"total = "<<total<<endl;
        if(total < k || total > k){
            int falta = abs(k - total);

            if(falta%marcados == 0) res++;
        }else if(total == k){
            cout<<"mm"<<endl;
            res++;
        }

        int ant = cambios[posCambios];
        int eliminados = 0;

        cout<<"posCmbio = "<<posCambios<<endl;

            cout<<"ant = "<<anterior<<endl;

        while(posCambios < cambios.size() && cambios[posCambios] == ant){
            posCambios++;
            eliminados++;
        }

        cout<<"elim = "<<eliminados<<endl;
        cout<<endl;
    
        total -= eliminados * ant;

        marcados -= eliminados;
    }

    cout<<"res = "<<res<<endl;

}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin>>t;

    //2168...
    
    while (t--){
        casito();
    }
    return 0;
    
}
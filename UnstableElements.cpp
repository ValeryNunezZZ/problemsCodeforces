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

void casito(int cont){
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

    int marcados = cambios.size();
    int posCambios = 0;
    int res = 0;
    int total = n;
    int eliminados = 0;

    while(posCambios < cambios.size()){
        if(total < k){
            int falta = k - total;

            if(falta%marcados == 0) res++;
        }else if(total > k){
            int falta = total - k;

            if(falta%marcados == 0){
                if(falta/marcados < cambios[posCambios] - eliminados){
                    res++;
                }
            }
        }else if(total == k){
            res++;
        }

        int ant = cambios[posCambios];
        int aux = ant - eliminados;
        int c = 0;
        eliminados += aux;

        while(posCambios < cambios.size() && cambios[posCambios] == ant){
            posCambios++;
            c++;
        }
    
        total -= marcados * aux;

        marcados -= c;
    }

    cout<<res<<endl;

}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin>>t;

    int cont = 1;
    //282
    
    while (t--){
        casito(cont);
        cont++;
    }
    return 0;
    
}
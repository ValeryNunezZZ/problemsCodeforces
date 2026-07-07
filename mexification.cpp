
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
    vector<int> cuantos(n+10, 0);

    for(int i=0 ; i<n ; i++){
        cin>>nums[i];
        cuantos[nums[i]]++;
    }

    vector<int> primero(n);
    vector<int> segundo(n);
    vector<int> tercero(n);

    //REVISAR SUCESION

    sort(nums.begin(), nums.end());

    int ultimo = -1;

    for(int i=0 ; i<n ; i++){
        if(nums[i] == ultimo+1){
            ultimo++;
        }else if(nums[i] > ultimo + 1){
            break;
        }
    }

    for(int i=0 ; i<n ; i++){
        if(nums[i] > ultimo || cuantos[nums[i]] > 1){
            primero[i] = ultimo + 1;
        }else{
            primero[i] = nums[i];
        }
    }

    //LIMPIAR CUANTOS

    for(int i=0 ; i<n ; i++) cuantos[i] = 0;

    for(int i=0 ; i<n ; i++){
        cuantos[primero[i]]++;
    }

    //HACER EL SEGUNDO ARREGLO

    sort(primero.begin(), primero.end());
    
    ultimo = -1;

    for(int i=0 ; i<n ; i++){
        if(primero[i] == ultimo+1){
            ultimo++;
        }else if(primero[i] > ultimo + 1){
            break;
        }
    }

    for(int i=0 ; i<n ; i++){
        if(primero[i] > ultimo || cuantos[primero[i]] > 1){
            segundo[i] = ultimo + 1;
        }else{
            segundo[i] = primero[i];
        }
    }


    //LIMPIAR CUANTOS

    for(int i=0 ; i<n ; i++) cuantos[i] = 0;

    for(int i=0 ; i<n ; i++){
        cuantos[segundo[i]]++;
    }

    //HACER EL SEGUNDO ARREGLO

    sort(segundo.begin(), segundo.end());
    
    ultimo = -1;

    for(int i=0 ; i<n ; i++){
        if(segundo[i] == ultimo+1){
            ultimo++;
        }else if(segundo[i] > ultimo + 1){
            break;
        }
    }

    for(int i=0 ; i<n ; i++){
        if(segundo[i] > ultimo || cuantos[segundo[i]] > 1){
            tercero[i] = ultimo + 1;
        }else{
            tercero[i] = segundo[i];
        }
    }

    if(k == 1){
        long long total = 0;

        for(int i=0 ; i<n ; i++){
            total += primero[i];
        }

        cout<<total<<endl;
        return;
    }

    long long total = 0;

    if(k%2 == 0){
        for(int i=0 ; i<n ; i++){
            total += segundo[i];
        }
    }else{
        for(int i=0 ; i<n ; i++){
            total += tercero[i];
        }
    }

    cout<<total<<endl;
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
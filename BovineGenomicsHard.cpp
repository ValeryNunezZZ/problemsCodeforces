
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

int conversion(char uno, char dos, char tres){

    string cadena = "";

    if(uno == 'A'){
        cadena += '1';
    }else if(uno == 'C'){
        cadena += '2';
    }else if(uno == 'G'){
        cadena += '3';
    }else{
        cadena += '4';
    }

    if(dos == 'A'){
        cadena += '1';
    }else if(dos == 'C'){
        cadena += '2';
    }else if(dos == 'G'){
        cadena += '3';
    }else{
        cadena += '4';
    }

    if(tres == 'A'){
        cadena += '1';
    }else if(tres == 'C'){
        cadena += '2';
    }else if(tres == 'G'){
        cadena += '3';
    }else{
        cadena += '4';
    }

    return stoi(cadena);
}

void casito(){

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m; cin>>n>>m;

    vector<string> cadenas(2*n);

    for(int i=0 ; i<2*n ; i++){
        cin>>cadenas[i];
    }

    int res = 0;

    for(int i=0 ; i<m ; i++){
        for(int j=i+1 ; j<m ; j++){
            for(int k=j+1 ; k<m ; k++){

                vector<int> nums(445);

                //VER CUALES TENGO
                for(int l=n ; l<2*n ; l++){
                    nums[conversion(cadenas[l][i], cadenas[l][j], cadenas[l][k])] = 1;
                }

                bool alMenosUno = false;
                
                //CONTEO
                for(int o=0 ; o<n ; o++){
                    int evaluar = conversion(cadenas[o][i], cadenas[o][j], cadenas[o][k]);
                    
                    if(nums[evaluar] == 1){
                        alMenosUno = true;
                        break;
                    }
                }

                if(!alMenosUno) res++;
            }
        }
    }

    cout<<res<<endl;
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin>>t;
    
    while (t--){
        casito();
    }
    return 0;
    
}


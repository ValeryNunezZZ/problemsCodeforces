
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
    int n0, n1, n2; cin>>n0>>n1>>n2;
    string res = "";

    if(n0 != 0 && n1 == 0 && n2 == 0){
        for(int i=0 ; i<=n0 ; i++){
            res += "0";
        }
    }else if(n0 == 0 && n1 == 0 && n2 != 0){
        for(int i=0 ; i<=n2 ; i++){
            res += "1";
        }
    }else if(n0 == 0 && n1 != 0 && n2 == 0){
        for(int i=0 ; i<=n1 ; i++){
            if(i%2 == 0){
                res += "1";
            }else{
                res += "0";
            }
        }
    }else if(n1%2 == 1){
        //PARA LOS UNOS
        for(int i=0 ; i<n2 ; i++){
            res += "1";
        }

        //PARA LOS DE EN MEDIO
        for(int i=0 ; i<=n1 ; i++){
            if(i%2 == 0){
                res += "1";
            }else{
                res += "0";
            }
        }

        //PARA LOS CEROS
        for(int i=0 ; i<n0 ; i++){
            res += "0";
        }
    }else{
        //PARA LOS CEROS
        for(int i=0 ; i<n0 ; i++){
            res += "0";
        }

        //PARA LOS DE EN MEDIO
        for(int i=0 ; i<n1 ; i++){
            if(i%2 == 0){
                res += "0";
            }else{
                res += "1";
            }
        }

        //PARA LOS UNOS
        for(int i=0 ; i<n2 ; i++){
            res += "1";
        }

        res += "0";
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
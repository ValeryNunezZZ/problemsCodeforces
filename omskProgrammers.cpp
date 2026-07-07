
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
    int a, b, x; cin>>a>>b>>x;

    vector<int> resA;
    vector<int> resB;

    int aux = a;

    while(aux > 0){
        resA.push_back(aux);
        aux/=x;
    }

    resA.push_back(0);

    aux = b;

    while(aux > 0){
        resB.push_back(aux);
        aux/=x;
    }

    resB.push_back(0);

/*     for(int i=0 ; i<resA.size() ; i++){
        cout<<resA[i]<<" ";
    }


    for(int i=0 ; i<resB.size() ; i++){
        cout<<resB[i]<<" ";
    } */

    sort(resA.begin(), resA.end());
    sort(resB.begin(), resB.end());

    int minOp = INT_MAX;

    if(resB.size() <= resA.size()){
        for(int i=0 ; i<resB.size() ; i++){
            auto it = lower_bound(resA.begin(), resA.end(), resB[i]);

            if(it != resA.end()){
                int mayor = *it;
                int menor = -1;
                int resTentativaMayor = (resA.size() - 1 - (it - resA.begin())) + (resB.size() - 1 - i);
                int resTentativaMenor = resTentativaMayor + 1;

                if(it - resA.begin() > 0){
                    menor = resA[it-resA.begin()-1];
                }
            
                int dif = mayor - resB[i];

                minOp = min(resTentativaMayor+dif, minOp);

                if(menor != -1){
                    dif = resB[i] - menor;
                    minOp = min(resTentativaMenor+dif, minOp);
                }
            }else{
                int menor = resA[resA.size() - 1];
                int dif = resB[i] - menor;
                int resTentativa = resB.size() - 1 - i;

                minOp = min(resTentativa+dif, minOp);
            }
        }
    }else{
        for(int i=0 ; i<resA.size() ; i++){
            auto it = lower_bound(resB.begin(), resB.end(), resA[i]);

            if(it != resB.end()){
                int mayor = *it;
                int menor = -1;
                int resTentativaMayor = (resB.size() - 1 - (it - resB.begin())) + (resA.size() - 1 - i);
                int resTentativaMenor = resTentativaMayor + 1;
                

                if(it - resB.begin() > 0){
                    menor = resB[it-resB.begin()-1];
                }
            
                int dif = mayor - resA[i];

                minOp = min(resTentativaMayor+dif, minOp);

                if(menor != -1){
                    dif = resA[i] - menor;
                    minOp = min(resTentativaMenor+dif, minOp);
                }
            }else{
                int menor = resB[resB.size() - 1];
                int dif = resA[i] - menor;
                int resTentativa = resA.size() - 1 - i;

                minOp = min(resTentativa+dif, minOp);
            }

/*             cout<<"minOp = "<<minOp<<endl;
            cout<<"uno con = "<<resA[i]<<endl;
            cout<<endl; */
        }
    }

    cout<<minOp<<endl;
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
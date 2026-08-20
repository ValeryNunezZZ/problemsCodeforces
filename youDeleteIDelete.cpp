
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
    string cadena; cin>>cadena;

    int pos = 0;

    string res1 = "";

    while(pos < cadena.size()){
        if(cadena[pos] == '0'){
            //AVANZAR HASTA EL ULTIMO CERO

            while(pos < cadena.size() && cadena[pos] == '0'){
                pos++;
            }

            //CONTAR SI AL MENOS TIENE MAS DE UN UNO
            int cont = 0;
            int empiezaUnos = pos;

            while(pos < cadena.size() && cadena[pos] == '1'){
                pos++;
                cont++;
            }

            int p = 0;

            if(cont > 1){
                while(p < empiezaUnos-1){
                    res1 += cadena[p];
                    p++;
                }

                p = empiezaUnos;

                while(p < cadena.size()){
                    res1 += cadena[p];
                    p++;
                }

                break;
            }
        }else{
            pos++;
        }
    }

    if(res1.size() == 0){
        int p = 0;

        while(p < cadena.size()){
            if(cadena[p] == '0'){
                int pos = 0;

                while(pos < p){
                    res1 += cadena[pos];
                    pos++;
                }

                pos = p+1;

                while(pos < cadena.size()){
                    res1 += cadena[pos];
                    pos++;
                }

                break;
            }else{
                p++;
            }
        }
    }

    //QUITAR UNO
    int p = 0;
    string res2 = "";

    while(p < res1.size()){
        if(res1[p] == '1'){
            int pos = 0;

            while(pos < p){
                res2 += res1[pos];
                pos++;
            }

            pos = p+1;

            while(pos < res1.size()){
                res2 += res1[pos];
                pos++;
            }

            break;
        }else{
            p++;
        }
    }

    cout<<res2<<endl;
}

//0100100110110101110100000101111
//010010110110101110100000101111
//00010110110101110100000101111

//00100110110101110100000101111
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
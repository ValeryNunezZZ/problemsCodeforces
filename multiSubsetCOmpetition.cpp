
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
    int n, m; cin>>n>>m;
    
    map< int, vector<int> > students;
    vector<long long> sumas(m+1, 0);

    for(int i=0 ; i<n ; i++){
        int s, r; cin>>s>>r;

        students[s].push_back(-1 * r);
    }

    for(auto &i : students){
        sort(i.second.begin(), i.second.end());
    }

    int cuantos = 0;
    long long actual = 0;
    long long maximo = LLONG_MIN;
    
    //NECESITO SABER CUANTO VALIAN EN TOTAL

    while(1){
        for(auto it = students.begin(); it != students.end();){

            if(cuantos < it->second.size()){

                if(sumas[it->first] + it->second[cuantos] * -1 > 0){

                    actual += it->second[cuantos] * -1;
                    sumas[it->first] += it->second[cuantos] * -1 ;

                    ++it;
                }else{
                    actual -= sumas[it->first];

                    it = students.erase(it);
                }

            }else{
                actual -= sumas[it->first];

                it = students.erase(it);
            }
        }
        
        if(actual > maximo) maximo = actual;

        if (students.empty()) {
            break; 
        }

        cuantos++;
    }

    if(maximo <= 0){
        cout<<0<<'\n';
        return;
    }

    cout<<maximo<<'\n';
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;

    while (t--){
        casito();
    }
    return 0;
    
}
/* 

SSH protocolo Secure Shell
sustituye telnet

Puerto tcp 22
*/
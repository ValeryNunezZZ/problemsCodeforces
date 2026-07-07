
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

    for(int i=0 ; i<n ; i++) cin>>nums[i];

    int unos = 0;
    int dosTres = 0;
    int posGrupoUno = -2;    

    //PRIMER GRUPO
    for(int i=0 ; i<n ; i++){
        if(nums[i] == 1){
            unos++;
        }else{
            dosTres++;
        }

        if(unos >= dosTres){
            posGrupoUno = i;
            break;
        }
    }

    int dif;
    bool entre = false;
    
    if(unos > dosTres){
        posGrupoUno++;

        dif = unos - dosTres;

        while(posGrupoUno < n && dif > 0 && nums[posGrupoUno] == 3){
            posGrupoUno++;
            dif--;
        }


        entre = true;
    }

    int unoDos = 0;
    int tres = 0;
    int posGrupoDos = -2;

    if(posGrupoUno == -2){
        cout<<"NO"<<endl;
        return;
    }

    if(entre) posGrupoUno--;

    //GRUPO DOS
    for(int i=posGrupoUno+1 ; i<n ; i++){
        if(nums[i] == 3){
            tres++;
        }else{
            unoDos++;
        }

        if(unoDos >= tres){
            posGrupoDos = i;
            break;
        }
    }

    if(posGrupoDos+1 < n && posGrupoDos+1 != -1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
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
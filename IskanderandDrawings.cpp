
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
    int n; cin>>n;
    string cadena; cin>>cadena;

    int masLarga = -1;
    int pos = 0;

    while(pos < n){
        int actual = 0;

        if(cadena[pos] == '#'){
            while(pos < n && cadena[pos] == '#'){
                actual++;
                pos++;
            }
        }else{
            pos++;
        }

        masLarga = max(masLarga, actual);
    }

    cout<<ceil((double) masLarga/2)<<endl;
}

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
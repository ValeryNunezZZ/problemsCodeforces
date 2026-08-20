
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

    int n, k, m; cin>>n>>k>>m;

    if(k == m || k < m){

        cout<<"YES"<<endl;

        int valorExtra = m - k + 1;
        int pos = 1;

        for(int i=0 ; i<n ; i++){
            if(i+1 == pos){
                cout<<valorExtra<<" ";
                
                valorExtra += k; 
            }else{
                cout<<1<<" ";
            }

        }

        cout<<endl;

        return;
    }

    cout<<"NO"<<endl;
    
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

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
    int x;
    cin>>x;

    if(x < 10){
        cout<<2<<endl;
        return;
    }

    if(x < 100){
        cout<<101<<endl;
    }else if(x < 1000){
        cout<<1001<<endl;
    }else if(x < 10000){
        cout<<10001<<endl;
    }else if(x < 100000){
        cout<<100001<<endl;
    }else if(x < 1000000){
        cout<<1000001<<endl;
    }else if(x < 10000000){
        cout<<10000001<<endl;
    }else if(x < 100000000){
        cout<<100000001<<endl;
    }else if(x < 1000000000){
        cout<<1000000001<<endl;
    }
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
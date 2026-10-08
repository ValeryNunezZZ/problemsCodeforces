
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

bool esPosible(int obj, vector<int> & nums, int n, int k){

    //cantidad / color
    vector< pair<int, int> > cubetita(n, make_pair(0, 0));

    int necesito = 0;
    int gruposFormados = 0;
    int i = 0;
    int color = 0;
    
    while(i < n){

        if(nums[i] < n){
            if(cubetita[nums[i]].second == color){
                cubetita[nums[i]].first++;
            }else{
                cubetita[nums[i]].first = 1;
                cubetita[nums[i]].second = color;
            }
        }
        
        if(cubetita[necesito].first >= 1 && cubetita[necesito].second == color){
            necesito++;

            if(necesito - 1 == obj){
                gruposFormados++;
                i++;
                color++;
                necesito = 0;
            }
        }else{
            i++;
        }
    }

    if(gruposFormados >= k){
        return true;
    }else{
        return false;
    }
}

void casito(){

    int n, k; cin>>n>>k;

    vector<int> nums(n);

    for(int i=0 ; i<n ; i++) cin>>nums[i];

    int izq = 0;
    int der = n-1;
    int maxRes = -1;

    while(izq <= der){
        int middle = izq + (der - izq) / 2;

        bool posible = esPosible(middle, nums, n, k);

        if(posible){
            izq = middle + 1;
            maxRes = max(maxRes, middle);
        }else{
            der = middle - 1;
        }
    }

    cout<<maxRes+1<<'\n';
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


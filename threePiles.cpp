
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
    long long a, b, c; cin>>a>>b>>c;

    long long A = 0;
    long long B = 0;

    if(abs(a+c-b) > abs(b-a)){
        cout<<abs(a+c-b)<<endl;
    }else{
        cout<<abs(b-a)<<endl;
    }
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



    val topCancionesMundiales: List< List<String> > = listOf(
        listOf("1", "Blinding Lights", "The Weeknd", "5.59"),
        listOf("2", "Shape Of You", "Ed Sheeran", "5.10"),
        listOf("3", "Sweater Weather", "The Neighbourhood", "4.88"),
        listOf("4", "Starboy", "The Weeknd ft. Daft Punk", "4.76"),
        listOf("5", "As It Was", "Harry Styles", 4.62"),
        listOf("6", "One Dance", "Drake ft. Wizkid & Kyla", 4.47"),
        listOf("7", "Sunflower", "Post Malone & Swae Lee", 4.46"),
        listOf("8", "Someone You Loved", "Lewis Capaldi", 4.43"),
        listOf("9", "Perfect", "Ed Sheeran", 4.11"),
        listOf("10", "Stay", "The Kid LAROI & Justin Bieber", 4.07")
    )
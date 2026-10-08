
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
    //rows
    //columns
    //for rows
    //for columns
    int n, m, x, y;
    cin>>n>>m>>x>>y;

    vector<int> a(x);
    vector<int> b(y);

    for(int i=0 ; i<x ; i++) cin>>a[i];
    for(int i=0 ; i<y ; i++) cin>>b[i];

    set<int> actualesA;
    set<int> actualesB;
    set<int> repetidos;

    int faltantesA = n;
    int faltantesB = m;

    int menorA;
    int menorB;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=x-1 ; i>=0 ; i--){
        bool existe = binary_search(b.begin(), b.end(), a[i]);

        if(!existe && faltantesA > 0){
            faltantesA--;
            actualesA.insert(a[i]);
        }else if(existe){
            repetidos.insert(a[i]);
        }
    }    

    for(int i=y-1 ; i>=0 ; i--){
        bool existe = binary_search(a.begin(), a.end(), b[i]);

        if(!existe && faltantesB > 0){
            faltantesB--;
            actualesB.insert(b[i]);
        }
    }   

    while(!repetidos.empty()){
        int mayor = *repetidos.rbegin();

        if(faltantesA > 0){
            actualesA.insert(mayor);
            faltantesA--;
        }else if(faltantesB > 0){
            actualesB.insert(mayor);
            faltantesB--;
        }else if(*actualesA.begin() < *actualesB.begin() && mayor > *actualesA.begin()){
            actualesA.erase(actualesA.begin());
            actualesA.insert(mayor);
        }else if(*actualesB.begin() < *actualesA.begin() && mayor > *actualesB.begin()){
            actualesB.erase(actualesB.begin());
            actualesB.insert(mayor);    
        }

        repetidos.erase(--repetidos.end());
    }

    //CALCULAR EL MEJOR

    long long sumaA = 0;
    long long sumaB = 0;

    for(auto i : actualesA){
        sumaA += (long long) i;
    }

    for(auto i : actualesB){
        sumaB += (long long) i;
    }

    if(actualesA.size() + actualesB.size() <= n + m - 1){
        cout<<sumaA + sumaB<<endl;
        return;
    }

    long long opUno = sumaA + sumaB - *actualesB.begin();
    long long opDos = sumaA + sumaB - *actualesA.begin();

    cout<<max(opUno, opDos)<<endl;
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


/*
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> filas(x, 0);
    vector<int> columnas(y, 0);

    int iguales = 0;
    int inicioB = b.size() - m;
    int inicioA = a.size() - n;

    cout<<"inicioB = "<<inicioB<<endl;

    for(int i=a.size()-1 ; i>=inicioA ; i--){

        bool it = binary_search(b.begin() + inicioB, b.end(), a[i]);

        if(it == true){
            auto it = lower_bound(b.begin(), b.end(), a[i]);
            int pos = it - b.end();

            filas[i] = 1;
            columnas[pos] = 1;

            iguales++;

        }
    }

    //hacer un while con iguales
    //En cada iteracion se busca el primer elemento que no se encuentre en el arreglo contrario dentro del rango
    //Se hace la comparacion de los dos numeros
    //Se elige el mayor y se marca en el arreglo de visitados con un 2

cout<<"iguales = "<<iguales<<endl;
    //En caso de que se nos acaben los numeros para ambos lados, detener el while

    int posA = inicioA - 1;
    int posB = inicioB - 1;
    bool enA = false;
    bool enB = false;

    while(iguales > 0){
        int mayorArregloA = -1;

        while(posA > 0 && !enA){
            bool it = binary_search(b.begin() + inicioB, b.end(), a[posA]);

            if(!it){
                mayorArregloA = a[posA];
                posA--;
                
                break;
            }

            posA--;
        }

        int mayorArregloB = -1;

        while(posB > 0 && !enB){
            bool it = binary_search(a.begin() + inicioA, a.end(), b[posB]);

            if(it){
                mayorArregloB = b[posB];
                posB--;
                
                break;
            }

            posB--;
        }
        cout<<"veces"<<endl;
        cout<<"numA = "<<mayorArregloA<<endl;
        cout<<"numB = "<<mayorArregloB<<endl;

        if(mayorArregloA == -1 && mayorArregloB == -1){
            cout<<"hola"<<endl;
            break;
        }else if(mayorArregloA > mayorArregloB){
            filas[posA+1] = 2;
            enA = true;
            enB = false;
        }else if(mayorArregloA == mayorArregloB){
            filas[posA+1] = 2;
            enA = false;
            enB = false;
        }else{
            columnas[posB+1] = 2;
            enA = true;
            enB = false;
        }

        iguales--;
    }

    //SUMA DE LOS ELEMENTOS

    int suma = 0;

    for(int i=a.size()-1 ; i>=inicioA ; i--){
        if(filas[i] != 1){
            cout<<"i = "<<i<<endl;
            cout<<"filas = "<<filas[i]<<endl;
            suma += a[i];
        }
    } 

    for(int i=b.size()-1 ; i>=inicioB ; i--){
        suma += b[i];
    }    

    int dosA = -1;
    int dosB = -1;

    for(int i=b.size()-1 ; i>=0 ; i--){
        if(columnas[i] == 2){
            suma += b[i];
            dosB = b[i];
        }
    }

    for(int i=a.size()-1 ; i>=0 ; i--){
        if(filas[i] == 2){
            suma += a[i];
            dosA = a[i];
        }
    }

    if(dosA == -1){
        if(filas[inicioA] == 0){
            dosA = a[inicioA];
        }else{
            cout<<suma<<endl;
            return;
        } 
    }

    if(dosB == -1){
        if(columnas[inicioB] == 0){
            dosB = b[inicioB];
        }else{
            cout<<suma<<endl;
            return;
        } 
    }

    int menor = min(dosB, dosA);

    suma -= menor;

    cout<<suma<<endl;
*/
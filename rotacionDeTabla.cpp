
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

void imprimir(int columnas, int filas, vector< vector<int> >* destino){
    for(int i=0 ; i<columnas ; i++){
        for(int j=0 ; j<filas ; j++){
            int &num = (*destino)[i][j];
            cout<<num<<" ";
        }
        cout<<endl;   
    }
}

void casito(int caso){

    /*
    OPERACIONES:

    1. Rotacion de tabla a la izquierda
    2. Rotacion de tabala a la derecha
    3. Swap de columnas
    4. Swap de filas
    5. Salir
    */

    //n = filas
    //m = columnas
    int n, m; cin>>n>>m;

    vector< vector<int> >matriz(n, vector<int>(m));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>matriz[i][j];
        }
    }

    vector< vector<int> > aux(m, vector<int>(n));

    //tipo es impar => ocupa a "aux"
    int tipo = 0;
    int op;

    do{

        cout<<"Operacion a realizar : ";
        cin>>op;

        vector< vector<int> >* destino = nullptr;
        vector< vector<int> >* origen = nullptr;

        int filas, columnas;

        if(tipo%2 == 0){
            origen = &matriz;
            destino = &aux;

            filas = n;
            columnas = m;
        }else{
            origen = &aux;
            destino = &matriz;

            filas = m;
            columnas = n;
        }

        if(op == 1){
            //1. Rotacion de tabla a la izquierda

            int f = 0, c = 0;

            for(int i=columnas-1 ; i>=0 ; i--){
                for(int j=0 ; j<filas ; j++){
                    (*destino)[f][c] = (*origen)[j][i];
                    c++;
                }
                f++;
                c = 0;
            }
        
            tipo++;

        }else if(op == 2){
            //2. Rotacion de tabala a la derecha

            int f = 0, c = 0;
            
            for(int j=0 ; j<columnas ; j++){
                for(int i=filas-1 ; i>=0 ; i--){
                    (*destino)[f][c] = (*origen)[i][j];
                    c++;
                } 
                f++;  
                c = 0;
            }

            tipo++;

        }else if(op == 3){
            //3. Swap de columnas

            int c1, c2;

            cout<<"Introduce columna 1 y 2 = ";
            cin>>c1>>c2;

            for(int i=0 ; i<filas ; i++){
                int numAux = (*origen)[i][c2];

                (*origen)[i][c2] = (*origen)[i][c1];
                (*origen)[i][c1] = numAux;
            } 

        }else if(op == 4){
            //3. Swap de filas

            int f1, f2;

            cout<<"Introduce columna 1 y 2 = ";
            cin>>f1>>f2;

            for(int i=0 ; i<columnas ; i++){
                int numAux = (*origen)[f1][i];

                (*origen)[f1][i] = (*origen)[f2][i];
                (*origen)[f2][i] = numAux;
            }
        }


        if(op == 1 || op == 2){
            imprimir(columnas, filas, destino);
        }else{
            imprimir(filas, columnas, origen);
        }
    }while(op != 5);

}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;

    int caso = 0;

    while (t--){
        caso++;
        casito(caso);
    }
    return 0;
    
}
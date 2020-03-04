//
//  main.cpp
//  Proyecto1
//  A01282574
//  Created by Miguel Tánori on 03/03/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Ejercicio1(){
    string linea,linea1, entrada, salida, arr;
    //char a;
    ifstream archEnt;
    cout << "¿Cuál es el archivo de entrada? \n";
    cin >> entrada;
    archEnt.open("/Users/migueltanori/Desktop/" + entrada);
    
    cout << "¿Cuál es el archivo de salida? \n";
    cin >> salida;
    ofstream archivoSalida;
    archivoSalida.open("/Users/migueltanori/Desktop/" + salida);
    
    getline(archEnt, linea1);
    for (int x = 0; x<=linea1.length(); x+=2){
        arr[x] = linea1[x];
        cout << arr[x];
    }
    cout << "\n";
}
    
   /* while (archEnt>>linea){
        for (int x = 0; x<=linea.length(); x++){
            if(linea[x]=='2' || linea[x]=='4' || linea[x]=='8'){
                linea[x] = 'X';
            }
            if (linea[x]=='0'){
                linea.erase(x,1);
                // Para los dobles 0s
                x-=1;
            }
        }
        cout<<linea<<endl;
        archivoSalida << linea << endl;
    }
    cout << endl;
    archEnt.close();
    archivoSalida.close();
}

void Ejercicio2(){
    int a = 0;
    double prom=0;
    string linea;
    ifstream archEnt;
    archEnt.open("/Users/migueltanori/Desktop/entrada2.txt");
    
    ofstream archivoSalida;
    archivoSalida.open("/Users/migueltanori/Desktop/answer2.txt");
    
    while (getline(archEnt, linea)){
        if (linea[0] == '4'){
            for(int y=6; y<=linea.length(); y++){
                a = (int)(linea[y]);
                // ASCII de tab es 9
                if(a == 9){
                    a=0;
                }
                // ASCII de 0 en adelante empieza en 48
                if(a>47){
                    a-=48;
                }
                prom += a;
            }
            linea = linea.substr(0,5);
            cout << linea << "\t" << prom/4 << endl;
            archivoSalida << linea << "\t" << prom/4 << endl;
            prom =0;
        }
    }
}*/

int main() {
    Ejercicio1();
    //Ejercicio2();
    return 0;
}

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
    string linea,linea1, entrada, salida, arr, base = "0123456789+-*/";
    ifstream archEnt;
    cout << "¿Cuál es el archivo de entrada? \n";
    cin >> entrada;
    archEnt.open("/Users/migueltanori/Desktop/" + entrada + ".txt");
    
    cout << "¿Cuál es el archivo de salida? \n";
    cin >> salida;
    ofstream archivoSalida;
    archivoSalida.open("/Users/migueltanori/Desktop/" + salida + ".txt");
    cout << endl;
    
    getline(archEnt, linea1);
    int c = 0;
    for (int x = 0; x<29; x++){
        if (x%2==0 || x==0){
            arr[c] = linea1[x];
            c++;
        }
    }

    cout << endl << endl;

     while (getline(archEnt, linea)){
           for (int x = 0; x<linea.length(); x++){
               for (int y = 0; y<14; y++){
                   if (linea[x] == arr[y]){
                       linea[x] = base[y];
                   }
               }
           }
          cout<< linea<<endl;
          archivoSalida << linea + " = " << endl;
       }
    
    cout << endl;
    archEnt.close();
    archivoSalida.close();
}

int main() {
    Ejercicio1();
    //Ejercicio2();
    return 0;
}




/*void Ejercicio2(){
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

//
//  main.cpp
//  Proyecto1
//  A01282574
//  Created by Miguel Tánori on 06/03/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string linea, arr, a, base = "0123456789+-*/";
    int palabra[3];
    
    ifstream archEnt;
    cout << "¿Cuál es el archivo de entrada? \n";
    cin >> linea;
    archEnt.open("/Users/migueltanori/Desktop/" + linea + ".txt");
    
    cout << "¿Cuál es el archivo de salida? \n";
    cin >> linea;
    ofstream archivoSalida;
    archivoSalida.open("/Users/migueltanori/Desktop/" + linea + ".txt");
    
    getline(archEnt, linea);
    int cont = 0;
    for (int x = 0; x<29; x++){
        if (x%2==0 || x==0){
            arr[cont] = linea[x];
            cont++;
        }
    }
    
    cont = 0;
    while (archEnt >> linea){
        for (int x = 0; x<linea.length(); x++){
            for (int y = 0; y<14; y++){
                if (linea[x] == arr[y]){
                    linea[x] = base[y];
                    palabra[cont] = (int)(linea[x]) - 48;
                    a += to_string(palabra[cont]);
                }
            }
        }
        palabra[cont] = stoi(a);
        cont++;
        a="";
        if (cont == 3){
            cont = 0;
            switch(palabra[1]){
                case -5:
                    archivoSalida << "(" + to_string(palabra[0]) +") + " + "("+ to_string(palabra[2]) + ") = " +  to_string(palabra[0] + palabra[2]) << endl;
                    break;
                case -3:
                    archivoSalida << "(" + to_string(palabra[0]) +") - " + "("+ to_string(palabra[2]) + ") = " +  to_string(palabra[0] - palabra[2]) << endl;
                    break;
                case -6:
                    archivoSalida << "(" + to_string(palabra[0]) +") * " + "("+ to_string(palabra[2]) + ") = " +  to_string(palabra[0] * palabra[2]) << endl;
                    break;
                case -1:
                    archivoSalida << "(" + to_string(palabra[0]) +") / " + "("+ to_string(palabra[2]) + ") = " +  to_string(palabra[0] / palabra[2]) << endl;
                    break;
                default:
                    cout<<endl;
                    break;
            }
        }
    }
    archEnt.close();
    archivoSalida.close();
    return 0;
}

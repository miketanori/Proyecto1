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
    // Declaro variables (base es un string con la traducción)
    string linea, arr, a, base = "0123456789+-*/";
    int palabra[3];
    
    //acceso archivo entrada
    ifstream archEnt;
    cout << "¿Cuál es el archivo de entrada? \n";
    cin >> linea;
    archEnt.open("/Users/migueltanori/Desktop/" + linea + ".txt");
    
    // creo archivo salida
    cout << "¿Cuál es el archivo de salida? \n";
    cin >> linea;
    ofstream archivoSalida;
    archivoSalida.open("/Users/migueltanori/Desktop/" + linea + ".txt");
    
    // paso primera línea con la base 0123456789+-*/ a un string arr
    getline(archEnt, linea);
    int cont = 0;
    for (int x = 0; x<29; x++){
        if (x%2==0 || x==0){
            arr[cont] = linea[x];
            cont++;
        }
    }
    
    // para desencriptar comparo la línea con la base
    cont = 0;
    while (archEnt >> linea){
        for (int x = 0; x<linea.length(); x++){
            for (int y = 0; y<14; y++){
                if (linea[x] == arr[y]){
                    //desencripto la línea
                    linea[x] = base[y];
                    // convierto código ASCII (restando 48) y voy guardando a un string "a" cada caracter de la línea
                    palabra[cont] = (int)(linea[x]) - 48;
                    a += to_string(palabra[cont]);
                }
            }
        }
        // una vez desencriptada la línea, guardo valor en un arreglo "palabra" tamaño 3
        // palabra[0] = 1er numero , palabra[1] = operador, palabra[2] = 2do numero
        // palabra[1] está en valor ASCII menos 48 -> ASCII: 43(+), 45(-), 42(*), 47(/)
        palabra[cont] = stoi(a);
        cont++;
        a="";
        if (cont == 3){
            // el arreglo palabra se llena (contador = 3) -> linea desencriptada
            cont = 0;
            // switch del valor del operador en palabra[1] -> -5(+), -3(-), -6(*), -1(/)
            // escribo en archivo de salida con respuesta y los paréntesis
            switch(palabra[1]){
                case -5:
                    archivoSalida << "(" + to_string(palabra[0]) +") + (" + to_string(palabra[2]) + ") = " +  to_string(palabra[0] + palabra[2]) << endl;
                    break;
                case -3:
                    archivoSalida << "(" + to_string(palabra[0]) +") - (" + to_string(palabra[2]) + ") = " +  to_string(palabra[0] - palabra[2]) << endl;
                    break;
                case -6:
                    archivoSalida << "(" + to_string(palabra[0]) +") * (" + to_string(palabra[2]) + ") = " +  to_string(palabra[0] * palabra[2]) << endl;
                    break;
                case -1:
                    archivoSalida << "(" + to_string(palabra[0]) +") / (" + to_string(palabra[2]) + ") = " +  to_string(palabra[0] / palabra[2]) << endl;
                    break;
                default:
                    cout<<endl;
                    break;
            }
        }
    }
    // cierro archivo de entrada y salida
    archEnt.close();
    archivoSalida.close();
    return 0;
}

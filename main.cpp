// #include "Utilitarios.h"
#include<iostream>
#include "Vector3D.h"
#include "Punto3D.h"
using namespace std;
int main() {
   //Ejercicio 1
    int c = 7;
    Vector3D v_1 = Vector3D(6, 9, 6);
    Vector3D vectorResultado = v_1 * c;
    cout << "Ejercicio 1: ";
    vectorResultado.mostrar();

    //Ejercicio 2
    int n = 3;
    Vector3D v2 = Vector3D(6, 6, 6);
    vectorResultado = v2 / n;
    cout << "Ejercicio 2: ";
    vectorResultado.mostrar();

    //Ejercicio 3
    Vector3D a = Vector3D(1,1,1);
    Vector3D b = Vector3D(2,3,4);
    int constanteResultado = a * b;
    cout << "Ejercicio 3: " << constanteResultado << endl;

    //Ejercicio 4
    Vector3D v1_4 = Vector3D(1,1,1);
    Vector3D v2_4 = Vector3D(2,2,2);
    vectorResultado = v1_4 + v2_4;
    cout << "Ejercicio 4: ";
    vectorResultado.mostrar();

    //Ejercicio 5
    vectorResultado = v1_4 - v2_4;
    cout << "Ejercicio 5: ";
    vectorResultado.mostrar();
    
    //Ejercicio 6
    Punto3D A = Punto3D(1,2,3);
    Vector3D v_6 = Vector3D(3,3,3);
    Punto3D puntoResultado = A - v_6;
    cout << "Ejercicio 6: ";
    puntoResultado.mostrar();

    //Ejercicio 7
    Punto3D puntoA = Punto3D(5, 4, 3);
    Punto3D puntoB = Punto3D(2, 2, 2);
    Vector3D resultado = puntoA - puntoB;
    cout << "Ejercicio 7: ";
    resultado.mostrar();

    //Ejercicio 8
    Vector3D v1_8 = Vector3D(1,1,1);
    Vector3D v2_8 = Vector3D(2,3,4);   
    vectorResultado = v1_8 ^ v2_8;
    cout << "Ejercicio 8: ";
    vectorResultado.mostrar();

    //Ejercicio 9
    Punto3D p_9 = Punto3D(1,2,3);
    Vector3D v1_9 = Vector3D(1,2,3);
    puntoResultado = p_9 + v1_9;
    cout << "Ejercicio 9: ";
    puntoResultado.mostrar();
    return 0;
}
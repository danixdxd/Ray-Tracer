// #include <vector>

// #include "Utilitarios.h"
// #include <iostream>
// #include "Vector3D.h"
// #include "Punto3D.h"
// #include "Esfera.h"
// #include "ObjetoGeometrico.h"
// #include "ViewPlane.h"

// using namespace std;
// ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos){
    
//     ColorRGB color;

//     color.r = 0.0;
//     color.g = 0.0;
//     color.b = 0.0;

//     double t;
//     double tmin = 2000000;              //Cualquier numero que sea sumamente grande
//     Vector3D n;
//     Punto3D q;

//     Vector3D h;
//     for(int i = 0; i < objetos.size(); i++) {
//         if( objetos[i]->hayImpacto(r, t, n, q) && t < tmin){
//             color.r = objetos[i]->obtenerColor().r;
//             color.g = objetos[i]->obtenerColor().g;
//             color.b = objetos[i]->obtenerColor().b;

//             tmin = t;
//         }
//     }
//     return color;
// }
// int main() {
    
//      // ESCENA------------------------------------------------------------------
//     Punto3D centro1(0.0, 0.0, -400.0);
//     double radio1 = 120;
//     Esfera esfera1(centro1, radio1);   
//     esfera1.establecerColor(0.30, 0.40, 1.0); // [0-]

//     Punto3D centro2(150.0, 50.0, -200.0);
//     double radio2 = 100;
//     Esfera esfera2(centro2, radio2);   
//     esfera2.establecerColor(0.80, 0.10, 0.05);


//     vector<ObjetoGeometrico*> escena;
//     escena.push_back(&esfera1);
//     escena.push_back(&esfera2);
    
    
//      // VIEWPLANE
//     int hres = 800;
//     int vres = 600;
//     double s = 1.0;
//     ViewPlane vp(hres, vres, s);
    
    
//      // UTILITARIO PARA GUARDAR IMAGEN -------------------------------------------------------------------
//     int dpi = 72;
//     int width = vp.hres;
//     int height = vp.vres;
//     int n = width * height;
//     ColorRGB* pixeles = new ColorRGB[n];    
    
//      // ALGORITMO
//     for(int fil = 0; fil < vp.vres; fil++)
//     {
//         for ( int col = 0; col < vp.hres; col++) 
//         {
//              // Disparar un rayo
//             Vector3D direccion(0.0, 0.0, -1.0);
//             double x = vp.s * ( col - vp.hres/2 + 0.5 );
//             double y = vp.s * ( fil - vp.vres/2 + 0.5 );
//             double z = 0;
//             Punto3D origen(x, y, z);
//             Rayo rayo(origen, direccion);

//             pixeles[fil*width+col].r = obtenerColorPixel(rayo, escena).r;
//             pixeles[fil*width+col].g = obtenerColorPixel(rayo, escena).g;
//             pixeles[fil*width+col].b = obtenerColorPixel(rayo, escena).b;
//         }
//     }    
//     savebmp("img.bmp", width, height, dpi, pixeles);
//     return 0; 

// }

#include <vector>
#include <iostream>

#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"

#include "Utilitarios.h"

using namespace std;


ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos){
    
    ColorRGB color;

    color.r = 0.0;
    color.g = 0.0;
    color.b = 0.0;

    double t;
    double tmin = 2000000;    
    Vector3D n;
    Punto3D q;

    Vector3D h;
    for(int i = 0; i < objetos.size(); i++) {
        if( objetos[i]->hayImpacto(r, t, n, q) && t < tmin){
            color.r = objetos[i]->obtenerColor().r;
            color.g = objetos[i]->obtenerColor().g;
            color.b = objetos[i]->obtenerColor().b;

            tmin = t;
        }
    }
    return color;
}


int main() {

     // ESCENA------------------------------------------------------------------
    Punto3D centro1(0.0, 0.0, -400.0);
    double radio1 = 120;
    Esfera esfera1(centro1, radio1);   
    esfera1.establecerColor(0.30, 0.40, 1.0); // [0-]

    Punto3D centro2(150.0, 50.0, -200.0);
    double radio2 = 100;
    Esfera esfera2(centro2, radio2);   
    esfera2.establecerColor(0.80, 0.10, 0.05);


    vector<ObjetoGeometrico*> escena;
    escena.push_back(&esfera1);
    escena.push_back(&esfera2);
    
    
     // VIEWPLANE
    int hres = 800;
    int vres = 600;
    double s = 1.0;
    ViewPlane vp(hres, vres, s);
    
    
     // UTILITARIO PARA GUARDAR IMAGEN -------------------------------------------------------------------
    int dpi = 72;
    int width = vp.hres;
    int height = vp.vres;
    int n = width * height;
    ColorRGB* pixeles = new ColorRGB[n];
    
    
     // ALGORITMO
    for(int fil = 0; fil < vp.vres; fil++)
    {
        for ( int col = 0; col < vp.hres; col++) 
        {
             // Disparar un rayo
            Vector3D direccion(0.0, 0.0, -1.0);
            double x = vp.s * ( col - vp.hres/2 + 0.5 );
            double y = vp.s * ( fil - vp.vres/2 + 0.5 );
            double z = 0;
            Punto3D origen(x, y, z);
            Rayo rayo(origen, direccion);

            pixeles[fil*width+col].r = obtenerColorPixel(rayo, escena).r;
            pixeles[fil*width+col].g = obtenerColorPixel(rayo, escena).g;
            pixeles[fil*width+col].b = obtenerColorPixel(rayo, escena).b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}
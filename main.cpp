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
#include "Plano.h"
#include "Triangulo.h"
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
     //Simbolo de paz
    Punto3D centro1(0.0, 0.0, -400.0);
    double radio1 = 120;
    Esfera esfera1(centro1, radio1);   
    esfera1.establecerColor(0.30, 0.40, 1.0); // [0-]

    Punto3D centro2(0.0, 0.0, -200.0);
    double radio2 = 100;
    Esfera esfera2(centro2, radio2);   
    esfera2.establecerColor(0.0, 0.0, 0.0);

    Punto3D p(0, -209, 0);
    Vector3D q(0.0, -1.0, 0);
    Plano plano(p, q.hat());
    plano.establecerColor(0.0, 0.0, 0.0);

    Punto3D A(-360,-100,-600);
    Punto3D B(-140,0,-300);
    Punto3D C(-70,-220, -400);
    Triangulo triangulo(A, B, C);
    triangulo.establecerColor(0,1.0,0.0);

    Punto3D A1(10,0,-100);
    Punto3D B1(10,120,-100);
    Punto3D C1(100,-70, -100);
    Triangulo triangulo1(A1, B1, C1);
    triangulo1.establecerColor(0,0,0.0);

    Punto3D A2(-10,0,-100);
    Punto3D B2(-10,120,-100);
    Punto3D C2(-100,-70, -100);
    Triangulo triangulo2(A2, B2, C2);
    triangulo2.establecerColor(0,0,0.0);

    Punto3D A3(10,-120, -100);
    Punto3D B3(10,-20,-100);
    Punto3D C3(90,-80,-100);
    Triangulo triangulo3(A3, B3, C3);
    triangulo3.establecerColor(0,0,0.0);

    Punto3D A4(-10,-120, -100);
    Punto3D B4(-10,-20,-100);
    Punto3D C4(-90,-80,-100);
    Triangulo triangulo4(A4, B4, C4);
    triangulo4.establecerColor(0,0,0.0);

    //Sol
    Punto3D centro_sol(-240.0, 190.0, -400.0);
    double radio_sol = 30;
    Esfera esfera_sol(centro_sol, radio_sol);   
    esfera_sol.establecerColor(1.0, 1.0, 0.20);

    
    Punto3D A_trianguloUno_sol(-280, 195, -100);
    Punto3D B_trianguloUno_sol(-280, 185, -100);
    Punto3D C_trianguloUno_sol(-290, 190, -100);
    Triangulo trianguloUno_sol(A_trianguloUno_sol, B_trianguloUno_sol, C_trianguloUno_sol);
    trianguloUno_sol.establecerColor(1.0,1.0,0.20);

    Punto3D A_trianguloDos_sol(-200, 195, -100);
    Punto3D B_trianguloDos_sol(-200, 185, -100);
    Punto3D C_trianguloDos_sol(-190, 190, -100);
    Triangulo trianguloDos_sol(A_trianguloDos_sol, B_trianguloDos_sol, C_trianguloDos_sol);
    trianguloDos_sol.establecerColor(1.0,1.0,0.20);

    Punto3D A_trianguloTres_sol(-235, 230, -100);
    Punto3D B_trianguloTres_sol(-245, 230, -100);
    Punto3D C_trianguloTres_sol(-240, 240, -100);
    Triangulo trianguloTres_sol(A_trianguloTres_sol, B_trianguloTres_sol, C_trianguloTres_sol);
    trianguloTres_sol.establecerColor(1.0,1.0,0.20);
    
    Punto3D A_trianguloCuatro_sol(-235, 150, -100);
    Punto3D B_trianguloCuatro_sol(-245, 150, -100);
    Punto3D C_trianguloCuatro_sol(-240, 140, -100);
    Triangulo trianguloCuatro_sol(A_trianguloCuatro_sol, B_trianguloCuatro_sol, C_trianguloCuatro_sol);
    trianguloCuatro_sol.establecerColor(1.0,1.0,0.20);
    vector<ObjetoGeometrico*> escena;
    escena.push_back(&esfera1);
    //escena.push_back(&esfera2);
    escena.push_back(&plano);
    //escena.push_back(&triangulo);
    escena.push_back(&triangulo1);
    escena.push_back(&triangulo2);
    escena.push_back(&triangulo3);
    escena.push_back(&triangulo4);

    //Sol
    escena.push_back(&esfera_sol);    
    escena.push_back(&trianguloUno_sol); 
    escena.push_back(&trianguloDos_sol); 
    escena.push_back(&trianguloTres_sol); 
    escena.push_back(&trianguloCuatro_sol);    
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
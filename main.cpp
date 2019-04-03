#include <vector>
#include <iostream>
#include <math.h>
#include "Vector3D.h"
#include "Esfera.h"
#include "Plano.h"
#include "Triangulo.h"
#include "ViewPlane.h"
#include "LuzPuntual.h"
#include "Utilitarios.h"

using namespace std;

double acotar(double n)
{
    if ( n > 1.0)
    {
        return 1.0;
    }
    else
    {
        return n;
    }
}

ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos, LuzPuntual luz){
    
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
            // color.r = luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) ;
            // color.g = luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat());
            // color.b = luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat());
        
            h = ((-1)*r.d).hat();
            color.r = acotar( 0.1 + luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            color.g = acotar( 0.1 + luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            color.b = acotar( 0.1 + luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));

            tmin = t;
        }
    }
    return color;
}

int main() {

    LuzPuntual luz(1.0, 1.0, 1.0, 50, 100, -30);
     // ESCENA------------------------------------------------------------------
    vector<ObjetoGeometrico*> escena;

    //escena.push_back(&esfera1);
     // ESCENA------------------------------------------------------------------
    //Simbolo de paz circulos
    Punto3D centro1(0.0, 0.0, -400.0);
    double radio1 = 122;
    Esfera esfera1(centro1, radio1);   
    esfera1.establecerColor(0.30, 0.40, 1.0); // [0-]

    Punto3D centro2(0.0, 0.0, -300.0);
    double radio2 = 100;
    Esfera esfera2(centro2, radio2);   
    esfera2.establecerColor(0.0, 0.0, 0.0);

    Punto3D p(0, -209, 0);
    Vector3D q(0.0, -1.0, 0);
    Plano plano(p, q.hat());
    plano.establecerColor(0, 0, 0.0);

    //Lineas del centro del simbolo
    Punto3D A_centro1(-10,110, -100);
    Punto3D B_centro1(10,110,-100);
    Punto3D C_centro1(10,-110,-100);
    Triangulo triangulo__centro1(A_centro1, B_centro1, C_centro1);
    triangulo__centro1.establecerColor(0.30, 0.40, 1.0);

    Punto3D A_centro2(-10,-110, -100);
    Punto3D B_centro2(-10,110,-100);
    Punto3D C_centro2(10,-110,-100);
    Triangulo triangulo__centro2(A_centro2, B_centro2, C_centro2);
    triangulo__centro2.establecerColor(0.30, 0.40, 1.0);

    Punto3D A_izquierdo1(-10,0, -100);
    Punto3D B_izquierdo1(-10,-20,-100);
    Punto3D C_izquierdo1(-90,-80,-100);
    Triangulo triangulo__izquierdo1(A_izquierdo1, B_izquierdo1, C_izquierdo1);
    triangulo__izquierdo1.establecerColor(0.30, 0.40, 1.0);

    Punto3D A_izquierdo2(-10,0, -100);
    Punto3D B_izquierdo2(-90,-80,-100);
    Punto3D C_izquierdo2(-100,-70, -100);
    Triangulo triangulo__izquierdo2(A_izquierdo2, B_izquierdo2, C_izquierdo2);
    triangulo__izquierdo2.establecerColor(0.30, 0.40, 1.0);

    Punto3D A_derecho1(10,0, -100);
    Punto3D B_derecho1(10,-20,-100);
    Punto3D C_derecho1(90,-80,-100);
    Triangulo triangulo__derecho1(A_derecho1, B_derecho1, C_derecho1);
    triangulo__derecho1.establecerColor(0.30, 0.40, 1.0);

    Punto3D A_derecho2(10,-0, -100);
    Punto3D B_derecho2(90,-80,-100);
    Punto3D C_derecho2(100,-70, -100);
    Triangulo triangulo__derecho2(A_derecho2, B_derecho2, C_derecho2);
    triangulo__derecho2.establecerColor(0.30, 0.40, 1.0);


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
    escena.push_back(&esfera1);
    escena.push_back(&esfera2);
    escena.push_back(&plano);
    //Nubes
    Punto3D centro_nube1(245.0, 190.0, -400.0);
    double radio_nube1 = 30;
    Esfera esfera_nube1(centro_nube1, radio_nube1);   
    esfera_nube1.establecerColor(0.129, 0.92, 0.99);

    Punto3D centro_nube2(295.0, 190.0, -400.0);
    double radio_nube2 = 30;
    Esfera esfera_nube2(centro_nube2, radio_nube2);   
    esfera_nube2.establecerColor(0.129, 0.92, 0.99);

    Punto3D centro_nube3(220.0, 160.0, -400.0);
    double radio_nube3 = 30;
    Esfera esfera_nube3(centro_nube3, radio_nube3);   
    esfera_nube3.establecerColor(0.129, 0.92, 0.99);

    Punto3D centro_nube4(270.0, 160.0, -400.0);
    double radio_nube4 = 30;
    Esfera esfera_nube4(centro_nube4, radio_nube4);   
    esfera_nube4.establecerColor(0.129, 0.92, 0.99);

    Punto3D centro_nube5(320.0, 160.0, -400.0);
    double radio_nube5 = 30;
    Esfera esfera_nube5(centro_nube5, radio_nube5);   
    esfera_nube5.establecerColor(0.129, 0.92, 0.99);

    //lluvias
    Punto3D A_triangulo1_lluvia(230, 120, -100);
    Punto3D B_triangulo1_lluvia(240, 120, -100);
    Punto3D C_triangulo1_lluvia(235, 110, -100);
    Triangulo triangulo1_lluvia(A_triangulo1_lluvia, B_triangulo1_lluvia, C_triangulo1_lluvia);
    triangulo1_lluvia.establecerColor(0.117,0.623,0.98);

    Punto3D A_triangulo2_lluvia(265, 120, -100);
    Punto3D B_triangulo2_lluvia(275, 120, -100);
    Punto3D C_triangulo2_lluvia(270, 110, -100);
    Triangulo triangulo2_lluvia(A_triangulo2_lluvia, B_triangulo2_lluvia, C_triangulo2_lluvia);
    triangulo2_lluvia.establecerColor(0.117,0.623,0.98);

    Punto3D A_triangulo3_lluvia(300, 120, -100);
    Punto3D B_triangulo3_lluvia(310, 120, -100);
    Punto3D C_triangulo3_lluvia(305, 110, -100);
    Triangulo triangulo3_lluvia(A_triangulo3_lluvia, B_triangulo3_lluvia, C_triangulo3_lluvia);
    triangulo3_lluvia.establecerColor(0.117,0.623,0.98);

    Punto3D A_triangulo4_lluvia(230, 90, -100);
    Punto3D B_triangulo4_lluvia(240, 90, -100);
    Punto3D C_triangulo4_lluvia(235, 80, -100);
    Triangulo triangulo4_lluvia(A_triangulo4_lluvia, B_triangulo4_lluvia, C_triangulo4_lluvia);
    triangulo4_lluvia.establecerColor(0.117,0.623,0.98);

    Punto3D A_triangulo5_lluvia(265, 90, -100);
    Punto3D B_triangulo5_lluvia(275, 90, -100);
    Punto3D C_triangulo5_lluvia(270, 80, -100);
    Triangulo triangulo5_lluvia(A_triangulo5_lluvia, B_triangulo5_lluvia, C_triangulo5_lluvia);
    triangulo5_lluvia.establecerColor(0.117,0.623,0.98);

    Punto3D A_triangulo6_lluvia(300, 90, -100);
    Punto3D B_triangulo6_lluvia(310, 90, -100);
    Punto3D C_triangulo6_lluvia(305, 80, -100);
    Triangulo triangulo6_lluvia(A_triangulo6_lluvia, B_triangulo6_lluvia, C_triangulo6_lluvia);
    triangulo6_lluvia.establecerColor(0.117,0.623,0.98);

    Punto3D A_triangulo7_lluvia(230, 60, -100);
    Punto3D B_triangulo7_lluvia(240, 60, -100);
    Punto3D C_triangulo7_lluvia(235, 50, -100);
    Triangulo triangulo7_lluvia(A_triangulo7_lluvia, B_triangulo7_lluvia, C_triangulo7_lluvia);
    triangulo7_lluvia.establecerColor(0.117,0.623,0.98);

    Punto3D A_triangulo8_lluvia(265, 60, -100);
    Punto3D B_triangulo8_lluvia(275, 60, -100);
    Punto3D C_triangulo8_lluvia(270, 50, -100);
    Triangulo triangulo8_lluvia(A_triangulo8_lluvia, B_triangulo8_lluvia, C_triangulo8_lluvia);
    triangulo8_lluvia.establecerColor(0.117,0.623,0.98);

    Punto3D A_triangulo9_lluvia(300, 60, -100);
    Punto3D B_triangulo9_lluvia(310, 60, -100);
    Punto3D C_triangulo9_lluvia(305, 50, -100);
    Triangulo triangulo9_lluvia(A_triangulo9_lluvia, B_triangulo9_lluvia, C_triangulo9_lluvia);
    triangulo9_lluvia.establecerColor(0.117,0.623,0.98);

    //lineas del simbolo
    escena.push_back(&triangulo__centro1);
    escena.push_back(&triangulo__centro2);
    escena.push_back(&triangulo__izquierdo1);
    escena.push_back(&triangulo__izquierdo2);
    escena.push_back(&triangulo__derecho1);
    escena.push_back(&triangulo__derecho2);

    //Sol
    escena.push_back(&esfera_sol);    
    escena.push_back(&trianguloUno_sol); 
    escena.push_back(&trianguloDos_sol); 
    escena.push_back(&trianguloTres_sol); 
    escena.push_back(&trianguloCuatro_sol);    


    //Nubes
    escena.push_back(&esfera_nube1);    
    escena.push_back(&esfera_nube2); 
    escena.push_back(&esfera_nube3); 
    escena.push_back(&esfera_nube4); 
    escena.push_back(&esfera_nube5); 

    //LLuvias
    escena.push_back(&triangulo1_lluvia);    
    escena.push_back(&triangulo2_lluvia); 
    escena.push_back(&triangulo3_lluvia); 
    escena.push_back(&triangulo4_lluvia); 
    escena.push_back(&triangulo5_lluvia); 
    escena.push_back(&triangulo6_lluvia); 
    escena.push_back(&triangulo7_lluvia); 
    escena.push_back(&triangulo8_lluvia); 
    escena.push_back(&triangulo9_lluvia); 

  
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

            pixeles[fil*width+col].r = obtenerColorPixel(rayo, escena,luz).r;
            pixeles[fil*width+col].g = obtenerColorPixel(rayo, escena,luz).g;
            pixeles[fil*width+col].b = obtenerColorPixel(rayo, escena,luz).b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}
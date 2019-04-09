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
    if (n > 1.0)
    {
        return 1.0;
    }
    else
    {
        return n;
    }
}

ColorRGB obtenerColorPixel(const Rayo &r, vector<ObjetoGeometrico *> objetos, LuzPuntual luz)
{

    ColorRGB color;

    color.r = 0.0;
    color.g = 0.0;
    color.b = 0.0;

    double t;
    double tmin = 2000000;
    Vector3D n;
    Punto3D q;

    Vector3D h;
    for (int i = 0; i < objetos.size(); i++)
    {
        if (objetos[i]->hayImpacto(r, t, n, q) && t < tmin)
        {
            color.r = luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat());
            color.g = luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat());
            color.b = luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat());

            h = ((-1) * r.d).hat();
            color.r = acotar(0.1 + luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            color.g = acotar(0.1 + luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            color.b = acotar(0.1 + luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            //  color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            //             color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            //             color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);

            //             tmin = t;
        }
    }
    return color;
}

int main()
{

    LuzPuntual luz(0, 1.0, 1.0, 0, 0, -30);
    vector<ObjetoGeometrico *> escena;

    //escena.push_back(&esfera1);
    // ESCENA------------------------------------------------------------------

    Punto3D C_6(10 * -4.93348836898804, 10 * -3.70572090148926, 10 * -4.27007165626492E-7);
    Punto3D B_6(10 * -1.08620393276215, 10 * -0.485148787498474, 10 * -4.27007165626492E-7);
    Punto3D A_6(10 * -6.11230707168579, 10 * -3.56674957275391, 10 * -4.27007165626492E-7);
    Triangulo triangulo6(A_6, B_6, C_6);
    triangulo6.establecerColor(0.5, 0.3, 0.3);

    Punto3D C_7(10 * -4.73867416381836, 10 * 2.24646043777466, 10 * -4.27007165626492E-7);
    Punto3D B_7(10 * -6.11230707168579, 10 * -3.56674957275391, 10 * -4.27007165626492E-7);
    Punto3D A_7(10 * -1.08620393276215, 10 * -0.485148787498474, 10 * -4.27007165626492E-7);
    Triangulo triangulo7(A_7, B_7, C_7);
    triangulo7.establecerColor(0.5, 0.3, 0.3);

    Punto3D C_8(10 * -4.26685047149658, 10 * -6.29674005508423, 10 * -4.27007165626492E-7);
    Punto3D B_8(10 * -1.08620393276215, 10 * -0.485148787498474, 10 * -4.27007165626492E-7);
    Punto3D A_8(10 * -4.93348836898804, 10 * -3.70572090148926, 10 * -4.27007165626492E-7);
    Triangulo triangulo8(A_8, B_8, C_8);
    triangulo8.establecerColor(0.5, 0.3, 0.3);

    Punto3D C_9(10 * -1.69852924346924, 10 * -6.04895067214966, 10 * -4.27007165626492E-7);
    Punto3D B_9(10 * -1.08620393276215, 10 * -0.485148787498474, 10 * -4.27007165626492E-7);
    Punto3D A_9(10 * -4.26685047149658, 10 * -6.29674005508423, 10 * -4.27007165626492E-7);
    Triangulo triangulo9(A_9, B_9, C_9);
    triangulo9.establecerColor(0.5, 0.3, 0.3);

    Punto3D C_A(10 * -0.757190942764282, 10 * -6.99429512023926, 10 * -4.27007165626492E-7);
    Punto3D B_A(10 * 3.11041307449341, 10 * -2.83210325241089, 10 * -4.27007165626492E-7);
    Punto3D A_A(10 * -1.69852924346924, 10 * -6.04895067214966, 10 * -4.27007165626492E-7);
    Punto3D C_B(10 * -1.08620393276215, 10 * -0.485148787498474, 10 * -4.27007165626492E-7);
    Punto3D B_B(10 * -1.69852924346924, 10 * -6.04895067214966, 10 * -4.27007165626492E-7);
    Punto3D A_B(10 * 3.11041307449341, 10 * -2.83210325241089, 10 * -4.27007165626492E-7);
    Punto3D C_C(10 * 3.11041307449341, 10 * -2.83210325241089, 10 * -4.27007165626492E-7);
    Punto3D B_C(10 * 1.38716101646423, 10 * 4.17418050765991, 10 * -4.27007165626492E-7);
    Punto3D A_C(10 * -1.08620393276215, 10 * -0.485148787498474, 10 * -4.27007165626492E-7);
    Punto3D C_D(10 * -1.08620393276215, 10 * -0.485148787498474, 10 * -4.27007165626492E-7);
    Punto3D B_D(10 * 1.38716101646423, 10 * 4.17418050765991, 10 * -4.27007165626492E-7);
    Punto3D A_D(10 * -4.73867416381836, 10 * 2.24646043777466, 10 * -4.27007165626492E-7);
    Punto3D C_E(10 * -4.73867416381836, 10 * 2.24646043777466, 10 * -4.27007165626492E-7);
    Punto3D B_E(10 * -4.20485353469849, 10 * 1.63319611549377, 10 * 1.63109004497528);
    Punto3D A_E(10 * -6.11230707168579, 10 * -3.56674957275391, 10 * -4.27007165626492E-7);
    Punto3D C_F(10 * -4.76714754104614, 10 * -3.21641826629639, 10 * 1.80845320224762);
    Punto3D B_F(10 * -6.11230707168579, 10 * -3.56674957275391, 10 * -4.27007165626492E-7);
    Punto3D A_F(10 * -4.20485353469849, 10 * 1.63319611549377, 10 * 1.63109004497528);
    Punto3D C_10(10 * 1.38716101646423, 10 * 4.17418050765991, 10 * -4.27007165626492E-7);
    Punto3D B_10(10 * 0.786814510822296, 10 * 3.38750171661377, 10 * 1.26213490962982);
    Punto3D A_10(10 * -4.73867416381836, 10 * 2.24646043777466, 10 * -4.27007165626492E-7);
    Punto3D C_11(10 * -4.20485353469849, 10 * 1.63319611549377, 10 * 1.63109004497528);
    Punto3D B_11(10 * -4.73867416381836, 10 * 2.24646043777466, 10 * -4.27007165626492E-7);
    Punto3D A_11(10 * 0.786814510822296, 10 * 3.38750171661377, 10 * 1.26213490962982);
    Punto3D C_12(10 * -6.11230707168579, 10 * -3.56674957275391, 10 * -4.27007165626492E-7);
    Punto3D B_12(10 * -4.76714754104614, 10 * -3.21641826629639, 10 * 1.80845320224762);
    Punto3D A_12(10 * -4.93348836898804, 10 * -3.70572090148926, 10 * -4.27007165626492E-7);
    Punto3D C_13(10 * -4.93348836898804, 10 * -3.70572090148926, 10 * -4.27007165626492E-7);
    Punto3D B_13(10 * -4.76714754104614, 10 * -3.21641826629639, 10 * 1.80845320224762);
    Punto3D A_13(10 * -4.26685047149658, 10 * -6.29674005508423, 10 * -4.27007165626492E-7);
    Punto3D C_14(10 * -1.69852924346924, 10 * -6.04895067214966, 10 * -4.27007165626492E-7);
    Punto3D B_14(10 * -1.175048828125, 10 * -5.87052297592163, 10 * 2.15543818473816);
    Punto3D A_14(10 * -0.757190942764282, 10 * -6.99429512023926, 10 * -4.27007165626492E-7);
    Punto3D C_15(10 * -0.757190942764282, 10 * -6.99429512023926, 10 * -4.27007165626492E-7);
    Punto3D B_15(10 * -1.175048828125, 10 * -5.87052297592163, 10 * 2.15543818473816);
    Punto3D A_15(10 * 3.11041307449341, 10 * -2.83210325241089, 10 * -4.27007165626492E-7);
    Punto3D C_16(10 * 2.45908713340759, 10 * -3.04126310348511, 10 * 2.18911218643188);
    Punto3D B_16(10 * 3.11041307449341, 10 * -2.83210325241089, 10 * -4.27007165626492E-7);
    Punto3D A_16(10 * -1.175048828125, 10 * -5.87052297592163, 10 * 2.15543818473816);
    Punto3D C_17(10 * 3.11041307449341, 10 * -2.83210325241089, 10 * -4.27007165626492E-7);
    Punto3D B_17(10 * 2.45908713340759, 10 * -3.04126310348511, 10 * 2.18911218643188);
    Punto3D A_17(10 * 1.38716101646423, 10 * 4.17418050765991, 10 * -4.27007165626492E-7);
    Punto3D C_18(10 * 0.786814510822296, 10 * 3.38750171661377, 10 * 1.26213490962982);
    Punto3D B_18(10 * 1.38716101646423, 10 * 4.17418050765991, 10 * -4.27007165626492E-7);
    Punto3D A_18(10 * 2.45908713340759, 10 * -3.04126310348511, 10 * 2.18911218643188);
    Punto3D C_19(10 * -4.20485353469849, 10 * 1.63319611549377, 10 * 1.63109004497528);
    Punto3D B_19(10 * -4.94298028945923, 10 * 1.73314416408539, 10 * 7.34607744216919);
    Punto3D A_19(10 * -4.76714754104614, 10 * -3.21641826629639, 10 * 1.80845320224762);
    Punto3D C_1A(10 * -5.70446157455444, 10 * -3.08901453018188, 10 * 8.27276706695557);
    Punto3D B_1A(10 * -4.76714754104614, 10 * -3.21641826629639, 10 * 1.80845320224762);
    Punto3D A_1A(10 * -4.94298028945923, 10 * 1.73314416408539, 10 * 7.34607744216919);
    Punto3D C_1B(10 * -4.76714754104614, 10 * -3.21641826629639, 10 * 1.80845320224762);
    Punto3D B_1B(10 * -5.70446157455444, 10 * -3.08901453018188, 10 * 8.27276706695557);
    Punto3D A_1B(10 * -1.175048828125, 10 * -5.87052297592163, 10 * 2.15543818473816);
    Punto3D C_1C(10 * -1.1680748462677, 10 * -6.29389429092407, 10 * 7.00677108764648);
    Punto3D B_1C(10 * -1.175048828125, 10 * -5.87052297592163, 10 * 2.15543818473816);
    Punto3D A_1C(10 * -5.70446157455444, 10 * -3.08901453018188, 10 * 8.27276706695557);
    Punto3D C_1D(10 * -1.175048828125, 10 * -5.87052297592163, 10 * 2.15543818473816);
    Punto3D B_1D(10 * -1.1680748462677, 10 * -6.29389429092407, 10 * 7.00677108764648);
    Punto3D A_1D(10 * 2.45908713340759, 10 * -3.04126310348511, 10 * 2.18911218643188);
    Punto3D C_1E(10 * 4.1150279045105, 10 * -4.67934083938599, 10 * 5.37508583068848);
    Punto3D B_1E(10 * 2.45908713340759, 10 * -3.04126310348511, 10 * 2.18911218643188);
    Punto3D A_1E(10 * -1.1680748462677, 10 * -6.29389429092407, 10 * 7.00677108764648);
    Punto3D C_1F(10 * -0.734199404716492, 10 * 3.20553731918335, 10 * 6.31084251403809);
    Punto3D B_1F(10 * -4.94298028945923, 10 * 1.73314416408539, 10 * 7.34607744216919);
    Punto3D A_1F(10 * -4.20485353469849, 10 * 1.63319611549377, 10 * 1.63109004497528);
    Punto3D C_20(10 * 2.45908713340759, 10 * -3.04126310348511, 10 * 2.18911218643188);
    Punto3D B_20(10 * 4.1150279045105, 10 * -4.67934083938599, 10 * 5.37508583068848);
    Punto3D A_20(10 * 0.786814510822296, 10 * 3.38750171661377, 10 * 1.26213490962982);
    Punto3D C_21(10 * 4.32776784896851, 10 * 2.07285118103027, 10 * 4.34882831573486);
    Punto3D B_21(10 * 0.786814510822296, 10 * 3.38750171661377, 10 * 1.26213490962982);
    Punto3D A_21(10 * 4.1150279045105, 10 * -4.67934083938599, 10 * 5.37508583068848);
    Punto3D C_22(10 * 4.1150279045105, 10 * -4.67934083938599, 10 * 5.37508583068848);
    Punto3D B_22(10 * 7.67125844955444, 10 * -1.64701318740845, 10 * 1.61039781570435);
    Punto3D A_22(10 * 4.32776784896851, 10 * 2.07285118103027, 10 * 4.34882831573486);
    Punto3D C_23(10 * -5.70446157455444, 10 * -3.08901453018188, 10 * 8.27276706695557);
    Punto3D B_23(10 * -3.91582775115967, 10 * -0.395822167396545, 10 * 12.3854598999023);
    Punto3D A_23(10 * -1.1680748462677, 10 * -6.29389429092407, 10 * 7.00677108764648);
    Punto3D C_24(10 * 0.5173299908638, 10 * -5.64533853530884, 10 * 8.68273639678955);
    Punto3D B_24(10 * -1.1680748462677, 10 * -6.29389429092407, 10 * 7.00677108764648);
    Punto3D A_24(10 * -3.91582775115967, 10 * -0.395822167396545, 10 * 12.3854598999023);
    Punto3D C_25(10 * -4.94298028945923, 10 * 1.73314416408539, 10 * 7.34607744216919);
    Punto3D B_25(10 * -4.33553123474121, 10 * 1.38756763935089, 10 * 9.55333805084229);
    Punto3D A_25(10 * -5.70446157455444, 10 * -3.08901453018188, 10 * 8.27276706695557);
    Punto3D C_26(10 * -3.91582775115967, 10 * -0.395822167396545, 10 * 12.3854598999023);
    Punto3D B_26(10 * -5.70446157455444, 10 * -3.08901453018188, 10 * 8.27276706695557);
    Punto3D A_26(10 * -4.33553123474121, 10 * 1.38756763935089, 10 * 9.55333805084229);
    Punto3D C_27(10 * -0.734199404716492, 10 * 3.20553731918335, 10 * 6.31084251403809);
    Punto3D B_27(10 * -4.33553123474121, 10 * 1.38756763935089, 10 * 9.55333805084229);
    Punto3D A_27(10 * -4.94298028945923, 10 * 1.73314416408539, 10 * 7.34607744216919);
    Punto3D C_28(10 * -1.1680748462677, 10 * -6.29389429092407, 10 * 7.00677108764648);
    Punto3D B_28(10 * 0.5173299908638, 10 * -5.64533853530884, 10 * 8.68273639678955);
    Punto3D A_28(10 * 4.1150279045105, 10 * -4.67934083938599, 10 * 5.37508583068848);
    Punto3D C_29(10 * 4.37552213668823, 10 * -6.5931658744812, 10 * 7.4106559753418);
    Punto3D B_29(10 * 4.1150279045105, 10 * -4.67934083938599, 10 * 5.37508583068848);
    Punto3D A_29(10 * 0.5173299908638, 10 * -5.64533853530884, 10 * 8.68273639678955);
    Punto3D C_2A(10 * -4.33553123474121, 10 * 1.38756763935089, 10 * 9.55333805084229);
    Punto3D B_2A(10 * -5.23562860488892, 10 * 1.45083868503571, 10 * 11.6873979568481);
    Punto3D A_2A(10 * -3.91582775115967, 10 * -0.395822167396545, 10 * 12.3854598999023);

    Punto3D A_2B(10 * -5.23562860488892, 10 * 1.45083868503571, 10 * 11.6873979568481);
    Punto3D B_2B(10 * -5.37751007080078, 10 * 2.60753536224365, 10 * 13.36936378479);
    Punto3D C_2B(10 * -7.21234035491943, 10 * -2.85102367401123, 10 * 25.8264274597168);
    Punto3D A_2C(10 * -7.21234035491943, 10 * -2.85102367401123, 10 * 25.8264274597168);
    Punto3D B_2C(10 * -7.18538999557495, 10 * -5.24253511428833, 10 * 25.7309455871582);
    Punto3D C_2C(10 * -5.23562860488892, 10 * 1.45083868503571, 10 * 11.6873979568481);
    Punto3D A_2D(10 * -5.37751007080078, 10 * 2.60753536224365, 10 * 13.36936378479);
    Punto3D B_2D(10 * -5.23562860488892, 10 * 1.45083868503571, 10 * 11.6873979568481);
    Punto3D C_2D(10 * -0.734199404716492, 10 * 3.20553731918335, 10 * 6.31084251403809);
    Punto3D A_2E(10 * -0.734199404716492, 10 * 3.20553731918335, 10 * 6.31084251403809);
    Punto3D B_2E(10 * 2.54806041717529, 10 * 9.17465877532959, 10 * 8.0393590927124);
    Punto3D C_2E(10 * -5.37751007080078, 10 * 2.60753536224365, 10 * 13.36936378479);
    Punto3D A_2F(10 * -0.734199404716492, 10 * 3.20553731918335, 10 * 6.31084251403809);
    Punto3D B_2F(10 * 5.61027145385742, 10 * 8.87635135650635, 10 * 6.2088565826416);
    Punto3D C_2F(10 * 2.54806041717529, 10 * 9.17465877532959, 10 * 8.0393590927124);
    Punto3D A_30(10 * 2.54806041717529, 10 * 9.17465877532959, 10 * 8.0393590927124);
    Punto3D B_30(10 * 5.61027145385742, 10 * 8.87635135650635, 10 * 6.2088565826416);
    Punto3D C_30(10 * 7.67125844955444, 10 * 9.17754554748535, 10 * 6.56408214569092);
    Punto3D A_31(10 * 7.67125844955444, 10 * 9.17754554748535, 10 * 6.56408214569092);
    Punto3D B_31(10 * 7.67125844955444, 10 * 10.3385591506958, 10 * 8.29707145690918);
    Punto3D C_31(10 * 2.54806041717529, 10 * 9.17465877532959, 10 * 8.0393590927124);
    Punto3D A_32(10 * -7.18538999557495, 10 * -5.24253511428833, 10 * 25.7309455871582);
    Punto3D B_32(10 * -7.21234035491943, 10 * -2.85102367401123, 10 * 25.8264274597168);
    Punto3D C_32(10 * -1.93972730636597, 10 * -1.16435313224792, 10 * 33.1125602722168);
    Punto3D A_33(10 * -1.93972730636597, 10 * -1.16435313224792, 10 * 33.1125602722168);
    Punto3D B_33(10 * -2.20416808128357, 10 * -4.17985439300537, 10 * 32.6183853149414);
    Punto3D C_33(10 * -7.18538999557495, 10 * -5.24253511428833, 10 * 25.7309455871582);
    Punto3D A_34(10 * -2.20416808128357, 10 * -4.17985439300537, 10 * 32.6183853149414);
    Punto3D B_34(10 * -1.93972730636597, 10 * -1.16435313224792, 10 * 33.1125602722168);
    Punto3D C_34(10 * 7.67125844955444, 10 * 1.96017563343048, 10 * 35.4984283447266);
    Punto3D A_35(10 * 7.67125844955444, 10 * 1.96017563343048, 10 * 35.4984283447266);
    Punto3D B_35(10 * 7.67125844955444, 10 * 0.393481433391571, 10 * 35.252758026123);
    Punto3D C_35(10 * -2.20416808128357, 10 * -4.17985439300537, 10 * 32.6183853149414);
    Punto3D A_36(10 * 7.67125844955444, 10 * 1.96017563343048, 10 * 35.4984283447266);
    Punto3D B_36(10 * -1.93972730636597, 10 * -1.16435313224792, 10 * 33.1125602722168);
    Punto3D C_36(10 * -1.14246201515198, 10 * -0.96076238155365, 10 * 30.9910049438477);
    Punto3D A_37(10 * -1.14246201515198, 10 * -0.96076238155365, 10 * 30.9910049438477);
    Punto3D B_37(10 * 7.67125844955444, 10 * 1.93105161190033, 10 * 34.127326965332);
    Punto3D C_37(10 * 7.67125844955444, 10 * 1.96017563343048, 10 * 35.4984283447266);
    Punto3D A_38(10 * -1.93972730636597, 10 * -1.16435313224792, 10 * 33.1125602722168);
    Punto3D B_38(10 * -7.21234035491943, 10 * -2.85102367401123, 10 * 25.8264274597168);
    Punto3D C_38(10 * -5.00436401367188, 10 * -2.55507612228394, 10 * 26.1755084991455);
    Punto3D A_39(10 * -5.00436401367188, 10 * -2.55507612228394, 10 * 26.1755084991455);
    Punto3D B_39(10 * -1.14246201515198, 10 * -0.96076238155365, 10 * 30.9910049438477);
    Punto3D C_39(10 * -1.93972730636597, 10 * -1.16435313224792, 10 * 33.1125602722168);


    Triangulo trianguloA(A_A, B_A, C_A);
    trianguloA.establecerColor(0.5, 0.3, 0.3);
    Triangulo trianguloB(A_B, B_B, C_B);
    trianguloB.establecerColor(0.5, 0.3, 0.3);
    Triangulo trianguloC(A_C, B_C, C_C);
    trianguloC.establecerColor(0.5, 0.3, 0.3);
    Triangulo trianguloD(A_D, B_D, C_D);
    trianguloD.establecerColor(0.5, 0.3, 0.3);
    Triangulo trianguloE(A_E, B_E, C_E);
    trianguloE.establecerColor(0.5, 0.3, 0.3);
    Triangulo trianguloF(A_F, B_F, C_F);
    trianguloF.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo10(A_10, B_10, C_10);
    triangulo10.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo11(A_11, B_11, C_11);
    triangulo11.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo12(A_12, B_12, C_12);
    triangulo12.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo13(A_13, B_13, C_13);
    triangulo13.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo14(A_14, B_14, C_14);
    triangulo14.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo15(A_15, B_15, C_15);
    triangulo15.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo16(A_16, B_16, C_16);
    triangulo16.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo17(A_17, B_17, C_17);
    triangulo17.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo18(A_18, B_18, C_18);
    triangulo18.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo19(A_19, B_19, C_19);
    triangulo19.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo1A(A_1A, B_1A, C_1A);
    triangulo1A.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo1B(A_1B, B_1B, C_1B);
    triangulo1B.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo1C(A_1C, B_1C, C_1C);
    triangulo1C.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo1D(A_1D, B_1D, C_1D);
    triangulo1D.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo1E(A_1E, B_1E, C_1E);
    triangulo1E.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo1F(A_1F, B_1F, C_1F);
    triangulo1F.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo20(A_20, B_20, C_20);
    triangulo20.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo21(A_21, B_21, C_21);
    triangulo21.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo22(A_22, B_22, C_22);
    triangulo22.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo23(A_23, B_23, C_23);
    triangulo23.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo24(A_24, B_24, C_24);
    triangulo24.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo25(A_25, B_25, C_25);
    triangulo25.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo26(A_26, B_26, C_26);
    triangulo26.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo27(A_27, B_27, C_27);
    triangulo27.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo28(A_28, B_28, C_28);
    triangulo28.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo29(A_29, B_29, C_29);
    triangulo29.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo2A(A_2A, B_2A, C_2A);
    triangulo2A.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo2B(A_2B, B_2B, C_2B);
    triangulo2B.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo2C(A_2C, B_2C, C_2C);
    triangulo2C.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo2D(A_2D, B_2D, C_2D);
    triangulo2D.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo2E(A_2E, B_2E, C_2E);
    triangulo2E.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo2F(A_2F, B_2F, C_2F);
    triangulo2F.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo30(A_30, B_30, C_30);
    triangulo30.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo31(A_31, B_31, C_31);
    triangulo31.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo32(A_32, B_32, C_32);
    triangulo32.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo33(A_33, B_33, C_33);
    triangulo33.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo34(A_34, B_34, C_34);
    triangulo34.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo35(A_35, B_35, C_35);
    triangulo35.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo36(A_36, B_36, C_36);
    triangulo36.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo37(A_37, B_37, C_37);
    triangulo37.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo38(A_38, B_38, C_38);
    triangulo38.establecerColor(0.5, 0.3, 0.3);
    Triangulo triangulo39(A_39, B_39, C_39);
    triangulo39.establecerColor(0.5, 0.3, 0.3);

    escena.push_back(&triangulo6);
    escena.push_back(&triangulo7);
    escena.push_back(&triangulo8);
    escena.push_back(&triangulo9);
    escena.push_back(&trianguloA);
    escena.push_back(&trianguloB);
    escena.push_back(&trianguloC);
    escena.push_back(&trianguloD);
    escena.push_back(&trianguloE);
    escena.push_back(&trianguloF);
    escena.push_back(&triangulo10);
    escena.push_back(&triangulo11);
    escena.push_back(&triangulo12);
    escena.push_back(&triangulo13);
    escena.push_back(&triangulo14);
    escena.push_back(&triangulo15);
    escena.push_back(&triangulo16);
    escena.push_back(&triangulo17);
    escena.push_back(&triangulo18);
    escena.push_back(&triangulo19);
    escena.push_back(&triangulo1A);
    escena.push_back(&triangulo1B);
    escena.push_back(&triangulo1C);
    escena.push_back(&triangulo1D);
    escena.push_back(&triangulo1E);
    escena.push_back(&triangulo1F);
    escena.push_back(&triangulo20);
    escena.push_back(&triangulo21);
    escena.push_back(&triangulo22);
    escena.push_back(&triangulo23);
    escena.push_back(&triangulo24);
    escena.push_back(&triangulo25);
    escena.push_back(&triangulo26);
    escena.push_back(&triangulo27);
    escena.push_back(&triangulo28);
    escena.push_back(&triangulo29);
    escena.push_back(&triangulo2A);
    escena.push_back(&triangulo2B);
    escena.push_back(&triangulo2C);
    escena.push_back(&triangulo2D);
    escena.push_back(&triangulo2E);
    escena.push_back(&triangulo2F);
    escena.push_back(&triangulo30);
    escena.push_back(&triangulo31);
    escena.push_back(&triangulo32);
    escena.push_back(&triangulo33);
    escena.push_back(&triangulo34);
    escena.push_back(&triangulo35);
    escena.push_back(&triangulo36);
    escena.push_back(&triangulo37);
    escena.push_back(&triangulo38);
    escena.push_back(&triangulo39);

    // escena.push_back(&triangulo5);
    //  escena.push_back(&triangulo6);

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
    ColorRGB *pixeles = new ColorRGB[n];

    // ALGORITMO
    for (int fil = 0; fil < vp.vres; fil++)
    {
        for (int col = 0; col < vp.hres; col++)
        {
            // Disparar un rayo
            Vector3D direccion(0.0, 0.0, -1.0);
            double x = vp.s * (col - vp.hres / 2 + 0.5);
            double y = vp.s * (fil - vp.vres / 2 + 0.5);
            double z = 0;
            Punto3D origen(x, y, z);
            Rayo rayo(origen, direccion);

            pixeles[fil * width + col].r = obtenerColorPixel(rayo, escena, luz).r;
            pixeles[fil * width + col].g = obtenerColorPixel(rayo, escena, luz).g;
            pixeles[fil * width + col].b = obtenerColorPixel(rayo, escena, luz).b;
        }
    }
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}
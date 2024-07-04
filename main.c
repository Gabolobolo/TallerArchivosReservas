#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
   

    char clientes[5][2][40]={{"Juan","1789654123"},
                             {"",""},
                             {"",""},
                             {"",""},
                             {"",""}};

    char habitaciones[9][3][40]={{"1","simple","Dan Carlton"},
                                  {"2","doble","Dan Carlton"},
                                  {"3","triple","Dan Carlton"},
                                  {"4","simple","Swissotel"},
                                  {"5","doble","Swissotel"},
                                  {"6","triple","Swissotel"},
                                  {"7","simple","Sheraton"},
                                  {"8","doble","Sheraton"},
                                  {"9","triple","Sheraton"}};
    
    double precios[9]={90,120,160,65,100,140,85,110,150};

    int reservas[10][4]={{-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0}};

    int opcion,numHabitacion,numReserva;
    do
    {   
        printf("Escoja una opcion:\n\n1.Buscar Habitacion\n\n2.Realizar reserva\n\n3.Ver reservas\n\n4.Pagar Reserva\n\n");
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1:
            printf("1.Por tamaño\n2.Por Hotel\n");
            scanf("%d",&opcion);
            switch (opcion)
            {
            case 1:
                buscarPorTamano(&numHabitacion,habitaciones,precios);
                DatosHotel(habitaciones, precios);
                break;
            case 2:
                buscarHotel(&numHabitacion,habitaciones,precios);  
                DatosHotel(habitaciones, precios);
            default:
                break;
            }
            break;
        case 2:
           realizarReserva(numHabitacion,habitaciones,clientes,reservas);
           DatosCliente(clientes);
        DatosReserva(reservas);
            break;
        case 3:
        buscarReservaPorCedula(&numReserva,clientes,reservas);
        DatosReserva(reservas);
            break;
        case 4:
          buscarReservaPorCedula(&numReserva,clientes,reservas);
          pagarReserva(numReserva,reservas,habitaciones,precios);
            break;
        default:
            break;
        }
        printf("Desea elegir otra opcion (Si:1 / No:2)\n");
        scanf("%d",&opcion);
    } while (opcion==1);
    return 0; 
}

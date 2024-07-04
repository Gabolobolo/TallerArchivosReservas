#include <stdio.h>
#include "funciones.h"
#include <string.h>

void buscarPorTamano(int *numHabitacion,char habitaciones[][3][40],double precios[]){
    char tipo[40];
    printf("Ingrese el tamaño de habitacion que desea buscar (simple, doble, triple): ");
    scanf("%s",tipo);
    printf("Numero\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][1],tipo)==0)    
        {
            printf("%s\t\t%s\t\t%s\t\t%lf\n",habitaciones[i][0],habitaciones[i][1],habitaciones[i][2],precios[i]);
        }
    }
    printf("Elija la habitacion que desea reservar: ");
    scanf("%d",numHabitacion); 
}

void buscarHotel(int *numHabitacion,char habitaciones[][3][40],double precios[]){
    char hotel[40];
    printf("Ingrese el nombre del hotel que desea buscar: ");
    scanf("%s",hotel);
    printf("Numero\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][2],hotel)==0)
        {
            printf("%s\t\t%s\t\t%s\t\t%lf\n",habitaciones[i][0],habitaciones[i][1],habitaciones[i][2],precios[i]);
        }
    }
    printf("Elija el numero de habitacion que desea reservar: ");
    scanf("%d",numHabitacion); 
}

void realizarReserva(int numHabitacion, char habitaciones[][3][40], char clientes[][2][40], int reservas[][4]) {
    char nombre[40];
    char cedula[40];
    int indiceCliente = -1;
    int dias;
    int estadoReserva = 0; 
    int indiceLibreCliente = -1;

    
    for (int i = 0; i < 5; i++) {
        if (clientes[i][0][0] == '\0' && clientes[i][1][0] == '\0') { 
            indiceLibreCliente = i;
            break;
        }
    }

    if (indiceLibreCliente == -1) {
        printf("No hay espacio disponible para mas clientes.\n");
        return;
    }

   
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nombre);
    strcpy(clientes[indiceLibreCliente][0], nombre);


    printf("Ingrese la cedula del cliente: ");
    scanf("%s", cedula);
    strcpy(clientes[indiceLibreCliente][1], cedula);

    indiceCliente = indiceLibreCliente;


    printf("Ingrese la cantidad de dias de la reserva: ");
    scanf("%d", &dias);


    estadoReserva = 0; 

    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] == -1) { 
            reservas[i][0] = indiceCliente;
            reservas[i][1] = numHabitacion; 
            reservas[i][2] = dias;
            reservas[i][3] = estadoReserva;
            return;
        }
    }

    printf("No hay espacio disponible para realizar la reserva.\n");
}

void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[][4]) {
    char cedula[40];
    int indiceCliente = -1;

    
    printf("Ingrese la cedula del cliente para buscar la reserva: ");
    scanf("%s", cedula);

    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            indiceCliente = i;
            break;
        }
    }

    
    if (indiceCliente == -1) {
        printf("Cliente no encontrado.\n");
        *numReserva = -1; 
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] == indiceCliente) {
            *numReserva = i; 

            printf("Detalles de la reserva encontrada:\n");
            printf("Cliente: %s\n", clientes[indiceCliente][0]);
            printf("Habitacion: %d\n", reservas[i][1]);
            printf("Dias de reserva: %d\n", reservas[i][2]);
            
       
            if (reservas[i][3] == 0) {
                printf("Estado de reserva: Reservado\n");
            } else {
                printf("Estado de reserva: Pagado\n");
            }

            return;
        }
    }
    printf("No se encontro reserva\n");
    *numReserva = -1; 
}
void pagarReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
    printf("------------------------------------\n");
    printf("Detalles de la reserva a pagar:\n");
    printf("Numero de habitacion: %d\n", reservas[numReserva][1]);
    printf("Precio total: %.2lf\n", precios[reservas[numReserva][1] - 1]); 

    
    printf("Desea pagar esta reserva? (Si:1 / No:2): ");
    int opcion;
    scanf("%d", &opcion);

    if (opcion == 1) {
        reservas[numReserva][3] = 1;
        printf("La reserva ha sido pagada exitosamente\n");
    } else {
        printf("La reserva no ha sido pagada\n");
    }
}
// Funciones con textos//
void DatosHotel(char habitaciones[][3][40], double precios[]) {
    FILE *archivohotel = fopen("hotel.txt", "r"); 
    if (archivohotel == NULL) {
        printf("El archivo hotel.txt no se encontro. Creando un archivo nuevo.\n");
        archivohotel = fopen("hotel.txt", "w"); 
    fprintf(archivohotel, "1 simple Dan Carlton 90.0\n");
        fprintf(archivohotel, "2 doble Dan Carlton 120.0\n");
        fprintf(archivohotel, "3 triple Dan Carlton 160.0\n");
        fprintf(archivohotel, "4 simple Swissotel 65.0\n");
        fprintf(archivohotel, "5 doble Swissotel 100.0\n");
        fprintf(archivohotel, "6 triple Swissotel 140.0\n");
        fprintf(archivohotel, "7 simple Sheraton 85.0\n");
        fprintf(archivohotel, "8 doble Sheraton 110.0\n");
        fprintf(archivohotel, "9 triple Sheraton 150.0\n");
        fclose(archivohotel);
    } else {
        fclose(archivohotel); 
    }    
}
void DatosCliente(char clientes[][2][40]){
    FILE *Clientearchivo = fopen("clientes.txt", "w");
    if (Clientearchivo == NULL) {
        printf("El archivo clientes.txt no se encontro. Creando un archivo nuevo.\n");
        Clientearchivo = fopen("clientes.txt", "w"); 
        return;
    }
    fprintf(Clientearchivo,"\nDatos de los Clientes:\n");
    fprintf(Clientearchivo,"---------------------\n");
    for (int i = 0; i < 5; i++) {
        fscanf(Clientearchivo, "%s %s\n",
               clientes[i][0],
               clientes[i][1]);
        fprintf(Clientearchivo, "Nombre: %s\n", clientes[i][0]); 
        fprintf(Clientearchivo, "Cedula: %s\n\n", clientes[i][1]);
    }
    fclose(Clientearchivo);
}
void DatosReserva(int reservas[][4]){
    FILE *Reservarchivo = fopen("reservas.txt", "w");
    if (Reservarchivo == NULL) {
        printf("El archivo reservas.txt no se encontro. Creando un archivo nuevo.\n");
        Reservarchivo = fopen("reservas.txt", "w"); 
        return;
    }
    fprintf(Reservarchivo, "\nDatos de las Reservas:\n"); 
    fprintf(Reservarchivo, "----------------------\n");
    for (int i = 0; i < 10; i++) {
        fscanf(Reservarchivo, "%d %d %d %d\n", 
               &reservas[i][0],
               &reservas[i][1],
               &reservas[i][2],
               &reservas[i][3]);
        if (reservas[i][0] != -1) { 
            fprintf(Reservarchivo, "Cliente: %d\n", reservas[i][0]); 
            fprintf(Reservarchivo, "Habitacion: %d\n", reservas[i][1]);
            fprintf(Reservarchivo, "Dias: %d\n", reservas[i][2]);
            fprintf(Reservarchivo, "Estado: %s\n\n", reservas[i][3] == 0 ? "Reservado" : "Pagado"); 
        }
    }
    fclose(Reservarchivo);
}



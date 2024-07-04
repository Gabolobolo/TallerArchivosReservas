void buscarPorTamano(int *numHabitacion,char habitaciones[][3][40],double precios[]);
void buscarHotel(int *numHabitacion,char habitaciones[][3][40],double precios[]);
void realizarReserva(int numHabitacion, char habitaciones[][3][40], char clientes[][2][40], int reservas[][4]);
void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[][4]);
void pagarReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]);

//funciones para los archivos de texto//
void DatosHotel(char habitaciones[][3][40], double precios[]);
void DatosCliente(char clientes[][2][40]);
void DatosReserva(int reservas[][4]);

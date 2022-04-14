#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define CLIENTES 5
#define PRODUCTOS 10
#define BUFFER 50

char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;
typedef struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;        // El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} Cliente;

void AltaClientes(Cliente *arregloClientes,int cantidadClientes); //funcion para cargar el arreglo de clientes
void AltaCliente(Cliente* cliente, int numeroCliente); //funcion para cargar la informacion de un cliente
void AltaProductos(Producto* puntProductos, int cantidadProductos); //genera los productos al azar
void mostrarClientes(Cliente* arregloClientes, int cantidadClientes);
void mostrarCliente(Cliente* cliente, int numeroCliente);
float calcularTotalProductos(Producto* puntProductos, int numProductos);
float calcularCostoProducto(Producto producto);

int main()
{
    srand(time(NULL));
    int cantClientes;
    Cliente* arregloClientes;

    printf("\t\tSERVICIO DISTRIBUIDORA\n");

    do
    {
        printf("\t -Ingrese la cantidad de clientes: ");
        scanf("%d",&cantClientes);
    } while (cantClientes < 1 || cantClientes > CLIENTES);

    fflush(stdin);

    arregloClientes = (Cliente*) malloc(sizeof(Cliente)*cantClientes);

    printf("\n\t -Ingrese la informacion de cada uno de los clientes \n");

    AltaClientes(arregloClientes,cantClientes);
    puts("\n\n");

    mostrarClientes(arregloClientes,cantClientes);

    //liberar memoria
    for (int i = 0; i < cantClientes; i++)
    {
        free(arregloClientes[i].NombreCliente);
        for (int j = 0; j < arregloClientes->CantidadProductosAPedir; j++)
        {
            free(arregloClientes[i].Productos[j].TipoProducto);
        }
        free(arregloClientes[i].Productos);
    }
    free(arregloClientes);
    
    return 0;
}

void AltaClientes(Cliente* arregloClientes,int cantidadClientes)
{
    for (int i=0; i<cantidadClientes; i++)
    {
        printf("   Cliente %d: \n",i+1);
        AltaCliente(arregloClientes, i+1);
        arregloClientes++;
    }
}

void AltaCliente(Cliente* cliente,int numeroCliente)
{
    cliente->ClienteID = numeroCliente;

    char* buffer = (char*) malloc(BUFFER*sizeof(char));
    printf("    - Nombre del cliente: ");
    gets(buffer);

    cliente->NombreCliente = (char*) malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(cliente->NombreCliente,buffer);

    cliente->CantidadProductosAPedir = rand()%5 + 1;
    
    cliente->Productos = (Producto*) malloc(cliente->CantidadProductosAPedir*sizeof(Producto));
        
    AltaProductos(cliente->Productos,cliente->CantidadProductosAPedir);

    free(buffer);
}

void AltaProductos(Producto* puntProductos, int cantidadProductos)
{
    int randTipo;
    for (int i=0; i<cantidadProductos; i++)
    {
        puntProductos[i].ProductoID = i+1;
        puntProductos[i].Cantidad = rand()%PRODUCTOS + 1;

        randTipo = rand()%5;
        puntProductos[i].TipoProducto = (char*) malloc((strlen(TiposProductos[randTipo])+1)*sizeof(char));
        strcpy(puntProductos[i].TipoProducto,TiposProductos[randTipo]);
        
        puntProductos[i].PrecioUnitario = rand()%91 + 10;
    }

}

void mostrarClientes(Cliente* arregloClientes,int cantidadClientes)
{
    for (int i=0; i<cantidadClientes; i++)
    {
        mostrarCliente(arregloClientes,i+1);
        arregloClientes++;
    }   
}

void mostrarCliente(Cliente* cliente, int numeroCliente)
{
    float total;
    printf(" Informacion del cliente %d: \n",numeroCliente);

    printf("   Nombre e ID: %s, %d\n",cliente->NombreCliente,cliente->ClienteID);
  
    printf("   Pidio %d productos: \n",cliente->CantidadProductosAPedir);

    total = calcularTotalProductos(cliente->Productos,cliente->CantidadProductosAPedir);

    printf("   Total de su compra: $%.2f \n",total);
    puts("\n");
}

float calcularTotalProductos(Producto* puntProductos, int numProductos)
{
    float total = 0;

    for (int i = 0; i < numProductos; i++)
    {
        printf("    - ID: %d - Tipo: %s - Precio unitario: $%.2f - Cantidad: %d - Costo total: $%.2f \n",puntProductos[i].ProductoID,puntProductos[i].TipoProducto,puntProductos[i].PrecioUnitario,puntProductos[i].Cantidad,calcularCostoProducto(puntProductos[i]));

        total = total + calcularCostoProducto(puntProductos[i]);

    }   
}

float calcularCostoProducto(Producto producto)
{
    return producto.Cantidad*producto.PrecioUnitario;
}
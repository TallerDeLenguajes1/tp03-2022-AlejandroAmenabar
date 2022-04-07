#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int cant;
    char *buff;
    char **V;
    printf("Ingrese la cantidad de nombres a ingresar:");
    scanf("%i",&cant);
    getchar();
    V = (char**)malloc(sizeof(char *) * cant);

    buff = (char *)malloc(100 * sizeof(char));
    
    for (int i=0; i<cant; i++)
    {
        printf("Ingrese el %d) nombre: ",i);
        gets(buff);
        *(V+i)=(char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(*(V+i),buff);
    }
    
    for (int j=0; j<cant; j++)
    {
        printf("\n los nombres ingresados son: %s",*(V+j));
    }
        
    for (int i=0; i<cant; i++)
    {
        free(V[i]);
    }
    
    free(buff);
    return 0;
}

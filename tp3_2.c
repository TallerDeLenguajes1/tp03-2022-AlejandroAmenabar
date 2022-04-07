#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMA 5

int main()
{
    char *buff;
    char *V[TAMA];

    buff = (char *)malloc(100 * sizeof(char));
    
    for (int i=0; i<TAMA; i++)
    {
        printf("Ingrese el %d) nombre: ",i+1);
        gets(buff);
        V[i]=(char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(V[i],buff);
    }
    
    for (int j=0; j<TAMA; j++)
    {
        printf("\n los nombres ingresados son: %s",*(V+j));
    }
        
    for (int i=0; i<TAMA; i++)
    {
        free(V[i]);
    }
    
    free(buff);
    return 0;
}


#include <stdio.h>

// Ejemplos resueltos
/// Ejemplo 1 - Trabajando con cadena de caracteres
// cargar cadena con gets()
//  imprimir frases por pantalla con printf() y puts()
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char frase[100];
//     char texto[] = "Ud escribió:";
//     printf("Escriba una frase: ");
//     gets(frase);
//     printf("%s\n", texto);
//     printf("%s\n", frase); // forma 1 de escribir
//     puts(frase);           // forma 2 de escribir
//     return 0;
// }

// Ejemplo 2 - Trabajando con cadena de caracteres con reserva de memoria
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char *Buff;
//     Buff = (char *)malloc(100 * sizeof(char));
//     printf("Ingrese una frase\n");
//     gets(Buff);
//     printf("%s\n", Buff); // forma 1 de escribir
//     puts(Buff);           // forma 2 de escribir
//     free(Buff);
//     return 0;
// }

// Ejemplo 3 - reserva dinámica de memoria con variable auxiliar
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main()
// {
//     char *Buff; // variable auxiliar
//     char *Nombre;
//     char *Apellido;

//     Buff = (char *)malloc(100 * sizeof(char));
//     printf("Ingrese sus nombres: ");
//     gets(Buff);

//     Nombre = (char *)malloc((strlen(Buff) + 1) * sizeof(char));
//     strcpy(Nombre, Buff);
    
//     printf("Ingrese sus Apellidos: ");
//     gets(Buff);
//     Apellido = (char *)malloc((strlen(Buff) + 1) * sizeof(char));
//     strcpy(Apellido, Buff);

//     printf("escribiendo usando printf\n");
//     printf("%s\n", Buff);
//     printf("%s\n", Nombre);
//     printf("%s\n", Apellido);
    
//     printf("escribiendo usando puts\n");
//     puts(Buff);
//     puts(Nombre);
//     puts(Apellido);
//     // libero la memoria reservada en todos los punteros
//     free(Buff);
//     free(Nombre);
//     free(Apellido);
//     return 0;
// }

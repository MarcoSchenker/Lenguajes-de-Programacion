#include <stdio.h>

int main() {
    char nombre_entrada[100], nombre_salida[100];
    FILE *entrada, *salida;
    int c, anterior_espacio = 0;

    printf("Ingrese el nombre del archivo de entrada: ");
    scanf("%99s", nombre_entrada);
    printf("Ingrese el nombre del archivo de salida: ");
    scanf("%99s", nombre_salida);

    entrada = fopen(nombre_entrada, "r");
    if (entrada == NULL) {
        printf("No se pudo abrir el archivo de entrada.\n");
        return 1;
    }

    salida = fopen(nombre_salida, "w");
    if (salida == NULL) {
        printf("No se pudo crear el archivo de salida.\n");
        fclose(entrada);
        return 1;
    }

    while ((c = fgetc(entrada)) != EOF) {
        if (c == ' ') {
            if (!anterior_espacio) { // Si el anterior no era un espacio escribo normal y cambio el valor del anterior_espacio
                fputc(c, salida);
                anterior_espacio = 1;
            }
            // Si anterior_espacio ya era un espacio (1), no escribe el espacio
        } else { // Si el caracter es cualquier otra cosa a un espacio
            fputc(c, salida);
            anterior_espacio = 0;
        }
    }

    fclose(entrada);
    fclose(salida);

    printf("Archivo procesado y guardado en '%s'.\n", nombre_salida);
    return 0;
}
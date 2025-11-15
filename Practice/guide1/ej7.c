#include <stdio.h>

int main() {
    char nombre_archivo[100];
    FILE *archivo;
    int c;
    int lineas = 1, espacios = 0, tabs = 0;

    printf("Ingrese el nombre del archivo de texto: ");
    scanf("%99s", nombre_archivo);

    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while ((c = fgetc(archivo)) != EOF) {
        if (c == '\n') lineas++;
        else if (c == ' ') espacios++;
        else if (c == '\t') tabs++;
    }

    fclose(archivo);

    printf("Cantidad de líneas: %d\n", lineas);
    printf("Cantidad de espacios (' '): %d\n", espacios);
    printf("Cantidad de tabs (\\t): %d\n", tabs);

    return 0;
}
#include <stdio.h>

int main() {
    char nombre_archivo[100];
    char linea[256];
    FILE *archivo;

    printf("Ingrese el nombre del archivo de texto: ");
    scanf("%99s", nombre_archivo);

    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }

    fclose(archivo);
    return 0;
}
#include <stdio.h>

// 1. Imprimir un array usando aritmética de punteros
void print_array(int *arr, int size) {
    int *end = arr + size; // Puntero al final del array
    
    printf("[");
    while (arr < end) {
        printf("%d", *arr);
        arr++;
        
        if (arr < end) {
            printf(", ");
        }
    }
    printf("]\n");
}

// 2. Calcular la longitud de una string usando punteros
int str_length(const char *str) {
    const char *ptr = str;
    
    while (*ptr != '\0') {
        ptr++;
    }
    
    return ptr - str; 
    // La diferencia entre punteros es la longitud
}

// 3. Invertir un array in place
void reverse_array(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    
    while (start < end) {
        // Intercambiar elementos
        int temp = *start;
        *start = *end;
        *end = temp;
        
        // Mover los punteros hacia el centro
        start++;
        end--;
    }
}

int main() {
    
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array: ");
    print_array(numbers, size);
    
    reverse_array(numbers, size);
    printf("Reversed array: ");
    print_array(numbers, size);
    
    char str[] = "Ejercicio de punteros";
    printf("String: %s\n", str);
    printf("Length: %d\n", str_length(str));
    
    return 0;
}
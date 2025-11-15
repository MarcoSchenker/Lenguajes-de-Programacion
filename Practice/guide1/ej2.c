#include <stdio.h>

int main() {
    int n;
    printf("número: ");
    scanf("%d", &n);

    if (n%2 == 0) {
        printf("El número es par.\n");
    } else {
        printf("El número es impar.\n");
    }

    return 0;
}
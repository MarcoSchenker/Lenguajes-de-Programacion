#include <stdio.h>

int main() {
    int n;
    int result = 0;
    int resultado_while =0;
    printf("números a sumar: ");
    scanf("%d", &n);

    for(int i = 0; i <= n; i++){
        result+=i;
    }
    printf("resultado = %d\n", result);

    while(n!=0){
        resultado_while+=n;
        n--;
    }
    printf("resultado = %d", resultado_while);
    return 0;

}
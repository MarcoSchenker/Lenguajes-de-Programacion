#include<stdio.h>

int main(){
    int n;
    int result = 1;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    while(n!=1){
        result*=n;
        n--;
    }
    printf("Factorial = %d", result);
    return 0;
}

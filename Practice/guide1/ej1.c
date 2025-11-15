//#include<stdio.h>
//#define limit 300.0
//
//int main() {
//    int n;
//    scanf("&d", &n);
//    for (int i = 0; i<=n, i++) {
//    double celsius = i*limit/n;
//    double far = (celsius * 9 /5) +32;
//    printf("%.2d C = %.2d F\n",celsius,far);
//    }
//    return 0;
//}



















#include<stdio.h>
#define limit 300.0

int main() {
    int n;
    printf("número de pasos: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El número de pasos debe ser mayor que 0.\n");
        return 1;
    }

    for (int i = 0; i <= n; i++) {
        double celsius = (limit * i) / n;
        double fahrenheit = (celsius * 9 / 5) + 32;
        printf("%.2f C = %.2f F\n", celsius, fahrenheit);
    }

    return 0;
}
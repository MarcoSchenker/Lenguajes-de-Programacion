#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utility helpers
static void print_bytes(const char *label, const unsigned char *buf, size_t n) {
    printf("%s", label);
    for (size_t i = 0; i < n; ++i) printf("%02X ", buf[i]);
    putchar('\n');
}

// static void bad1(void) {
//     char buf[8];
//     const char *s = "AAAAAAAAAAAAAAAA";
//     strcpy(buf, s);
//     puts(buf);
// }
// static void bad2(void) {
//     char *p = malloc(8);
//     if (!p) { perror("malloc"); return; }

//     for (int i = 0; i <= 8; ++i)
//         p[i] = 'A';

//     free(p);
// }

// static void bad3(void) {
//     char s[4] = "abc";
//     s[3] = 'x'; // overwrites '\0'
//     puts(s);    // UB
// }

// static void bad4(void) {
//     size_t n = SIZE_MAX / 2 + 1;
//     int *a = malloc(n * 2 * sizeof *a);
//     if (!a) { puts("malloc failed"); return; }
//     a[0] = 1;
//     free(a);
// }
// static void bad5(void) {
//     int len = -5;
//     char *p = (char*)malloc(len);
//     if (!p) { perror("malloc"); return; }
//     free(p);
// }

// static void bad6(void) {
//     int *p = (int*)malloc(sizeof *p);
//     if (!p) { perror("malloc"); return; }
//     *p = 7;
//     free(p);
//     *p = 42; // UAF write
// }

// static void bad7(void) {
//     int *p = (int*)malloc(4);
//     if (!p) { perror("malloc"); return; }
//     free(p);
//     free(p); // double free
// }
// static void bad8(void) {
//     char *p = (char*)malloc(100);
//     if (!p) { perror("malloc"); return; }
//     // Lost reference without freeing -> leak
//     p = (char*)malloc(200);
//     if (!p) { perror("malloc"); return; }
//     free(p);
// }

// static void bad9(void) {
//     char *p = (char*)malloc(10);
//     if (!p) { perror("malloc"); return; }
//     char *q = p + 2;
//     free(q); // not the start of allocation
// }

// static int* returns_local_bad(void) {
//     int x = 7;
//     return &x;
// }

// static void bad10(void) {
//     int *p = returns_local_bad();
//     // Using p is UB
//     printf("dangling value: %d\n", *p);
// }
// static void bad11(void) {
//     int x;
//     if (x == 123) puts("equal");
// }

// static void bad12(void) {
//     size_t huge = (size_t)1 << 62; // Muevo el 1 binario 62 posiciones a la izquierda
//     char *p = (char*)malloc(huge);
//     p[0] = 'x'; // maybe NULL deref
//     free(p);
// }

// static void bad13(void) {
//     char *p = (char*)malloc(10);
//     if (!p) { perror("malloc"); return; }
//     p = (char*)realloc(p, SIZE_MAX/4);
//     if (!p) {
//         puts("realloc failed");
//         return;
//     }
//     free(p);
// }

// static void bad14(void) {
//     char buf[16] = "abcdefgh";
//     memcpy(buf+2, buf, 8); // overlap -> UB
//     puts(buf);
// }

// static void bad15(void) {
//     char buf[16];
//     const char *a = "0123456789";
//     const char *b = "ABCDEFGHIJ";
//     // can overflow
//     sprintf(buf, "%s %s", a, b);
//     puts(buf);
// }
// static void rec(int n){ if(n) rec(n-1); }

// static void bad16(void) {
//     rec(1000000000);
// }

// static int static_x;
// static void bad18(void) {
//     int local;
//     (void)static_x;
//     free(&local);
//     free(&static_x);
// }
// static void bad20(void) {
//     char *p = (char*)malloc(10);
//     if (!p) { perror("malloc"); return; }
//     char *alias = p;
//     free(p);
//     alias[0] = 'x';
// }

// 1. Se copia una cadena de 16 caracteres en un buffer de solo 8 bytes

static void good1(void) {
    char buf[8];
    const char *s = "AAAAAAAAAAAAAAAA";
    strncpy(buf, s, sizeof(buf) - 1);  // Copia segura limitada
    buf[sizeof(buf) - 1] = '\0';       // Garantiza terminación
    puts(buf);
}

// 2. El ciclo escribe hasta p[8], pero solo se reservaron 8 bytes (índices 0-7).

static void good2(void) {
    char *p = malloc(8);
    if (!p) { perror("malloc"); return; }

    for (int i = 0; i < 8; ++i)  // Límite corregido
        p[i] = 'A';

    free(p);
}

// 3. Se sobreescribe el carácter nulo terminador, rompiendo la cadena.

static void good3(void) {
    char s[5] = "abc";  // Un byte extra para el nuevo carácter (5 chars)
    s[3] = 'x'; //Pongo x en el indice 3
    s[4] = '\0'; // Pongo el terminador nulo en el indice 4 (último)
    puts(s);
}

// 4. La multiplicación n * 2 * sizeof *a produce un overflow.

static void good4(void) {
    size_t n = SIZE_MAX / 2 + 1;
    if (n > SIZE_MAX / (2 * sizeof(int))) {
        puts("Size too large, allocation would overflow");
        return;
    }
    int *a = malloc(n * 2 * sizeof *a);
    if (!a) { puts("malloc failed"); return; }
    a[0] = 1;
    free(a);
}

// 5. El valor negativo se convierte a un valor sin signo muy grande, potencialmente asignando memoria excesiva.

static void good5(void) {
    int len = 5;  // Valor positivo
    
    if (len <= 0) {
        puts("Invalid size for allocation");
        return;
    }
    
    char *p = (char*)malloc(len);
    if (!p) { perror("malloc"); return; }
    free(p);
}

// 6. Se accede a memoria después de liberarla.

static void good6(void) {
    int *p = (int*)malloc(sizeof *p);
    if (!p) { perror("malloc"); return; }
    *p = 7;
    free(p);
    p = NULL; // Evita uso posterior
}

// 7. Se libera el mismo puntero dos veces

static void good7(void) {
    int *p = (int*)malloc(4);
    if (!p) { perror("malloc"); return; }
    free(p);
    p = NULL; // O simplemente no poner esta línea ya que no se usa más
}

// 8. No se libera p al querer volver a usarlo

static void good8(void) {
    char *p = (char*)malloc(100);
    if (!p) { perror("malloc"); return; }
    free(p);
    p = (char*)malloc(200);
    if (!p) { perror("malloc"); return; }
    free(p);
}

// 9. Se libera un puntero que no está en el heap (no usó malloc)

static void good9(void) {
    char *p = (char*)malloc(10);
    if (!p) { perror("malloc"); return; }
    char *q = p + 2;

    // Libero el puntero original
    free(p);
}

// 10. Se retorna la dirección de una variable que deja de existir al salir de la función.

static int* returns_heap_good(void) {
    int *x = (int*)malloc(sizeof(int));
    if (x) {
        *x = 7;
    }
    return x;
}

static void good10(void) {
    int *p = returns_heap_good();
    if (p) {
        printf("heap value: %d\n", *p);
        free(p);
    }
}

// 11. Se usa una variable sin inicializar

static void good11(void) {
    int x;
    scanf("%d", &x);
    printf("Input: %d\n", x);
    if (x == 123) puts("equal");
}

// 12. Se intenta asignar memoria muy grande

static void good12(void) {
    size_t big = (size_t)1 << 8; 
    char *p = (char*)malloc(big);
    p[0] = 'x'; // maybe NULL deref
    free(p);
}

// 13. Se pierde la referencia original si realloc falla, causando memory leak.

static void good13(void) {
    char *p = (char*)malloc(10);
    if (!p) { perror("malloc"); return; }
     char *new_p = (char*)realloc(p, 20); // Le doy un tamaño de 20 ahora
    if (!new_p) {
        puts("realloc failed");
        free(p);
        return;
    }
    
    p = new_p;
    free(p);
}

// 14. Regiones de memoria superpuestas en memcpy

static void good14(void) {
    char buf[16] = "abcdefgh";
    memmove(buf+2, buf, 8);  // memmove maneja superposición correctamente
    puts(buf);
}

// 15. Sprintf puede escribir más bytes de los que buf puede almacenar.

static void good15(void) {
    char buf[16];
    const char *a = "0123456789";
    const char *b = "ABCDEFGHIJ";
    
    snprintf(buf, sizeof(buf), "%s %s", a, b);  // Limita los bytes escritos
    puts(buf);
}

// 16. Recursividad excesiva produce stack overflow

static void rec_good(int rec_quantity, int max_depth) {
    if (rec_quantity && max_depth > 0) rec_good(rec_quantity-1, max_depth-1);
}

static void good16(void) {
    int n;
    scanf("%d", &n);
    printf("Recursion depth requested: %d\n", n);
    int limit; // Limitar profundidad de recursión
    scanf("%d", &limit);
    printf("Recursion depth limit set to: %d\n", limit);
    rec_good(n, limit);
    
}


// 18. Se intenta liberar memoria no asignada con malloc

static int static_x;
static void good18(void) {
    int local;
    (void)static_x;
    
    // No intentar liberar variables no asignadas con malloc
}

// 20. Se usa un alias para acceder a memoria ya liberada

static void good20(void) {
    char *p = (char*)malloc(10);
    if (!p) { perror("malloc"); return; }
    char *alias = p;
    free(p);
    
    p = NULL;
    alias = NULL; 
}

int main(int argc, char **argv) {
    //bad1();
    // bad2();
    // bad3();
    // bad4();
    // bad5();
    // bad6();
    // bad7();
    // bad8();
    // bad9();
    // bad10();
    // bad11();
    // bad12();
    // bad13();
    // bad14();
    // bad15();
    // bad16();
    // bad18();
    // bad20();
    return 0;
}
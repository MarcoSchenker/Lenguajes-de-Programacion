#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void append(struct Node** head, int value){
    // Creo el nuevo nodo reservando el espacio de memoria
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    // Casteo necesario para evitar void*
    (*new_node).value = value;
    (*new_node).next = NULL;
    
    // Si la lista está vacía, el nuevo nodo es el head
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    // Si no, encontrar el último nodo y añadir el nuevo nodo después de él
    struct Node* current = *head;
    while ((*current).next != NULL) {
        current = (*current).next;
    }
    (*current).next = new_node;
}

void prepend(struct Node** head, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    (*new_node).value = value;
    (*new_node).next = *head;
    *head = new_node; 
    // Hago que el nuevo nodo apunte a lo que 
    // apunta head y hago que head apunte a mi nuevo nodo
}

int delete(struct Node** head, int value) {
    // Si la lista está vacía
    if (*head == NULL) {
        return 0;
    }
    
    // Si el nodo cabeza contiene el valor a eliminar
    if ((**head).value == value) {
        struct Node* temp = *head;
        *head = (*temp).next;
        free(temp);
        return 1;
    }
    
    // Buscar el valor a eliminar
    struct Node* current = *head;
    while ((*current).next != NULL && (*(*current).next).value != value) {
        current = (*current).next;
    }
    
    // Si se encontró el valor
    if ((*current).next != NULL) {
        struct Node* temp = (*current).next;
        (*current).next = (*temp).next;
        free(temp);
        return 1;
    }
    
    return 0; // Valor no encontrado
}

int find(struct Node* head, int value) {
    struct Node* current = head; 
    
    while (current != NULL) {
        if ((*current).value == value) {
            return 1; // Valor encontrado
        }
        current = (*current).next;
    }
    
    return 0; // Valor no encontrado
}

void print(struct Node* head) {
    struct Node* current = head;
    
    if (current == NULL) {
        printf("Lista vacía\n");
        return;
    }
    
    printf("Lista: ");
    while (current != NULL) {
        printf("%d ", (*current).value);
        current = (*current).next;
    }
    printf("\n");
}

void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    
    while (current != NULL) {
        next = (*current).next;
        free(current);
        current = next;
    }
    
    *head = NULL; // Establecer head a NULL después de liberar
}

int len(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        count++;
        current = (*current).next;
    }
    
    return count;
}


void selectionSort(struct Node* head) {
    if (head == NULL || (*head).next == NULL) {
        return; // Lista vacía o con un solo elemento
    }
    
    struct Node* current = head;
    
    // Recorrer la lista
    while (current != NULL) {
        struct Node* minNode = current;
        struct Node* temp = (*current).next;
        
        // Buscar el valor mínimo en la porción no ordenada
        while (temp != NULL) {
            if ((*temp).value < (*minNode).value) {
                minNode = temp;
            }
            temp = (*temp).next;
        }
        
        // Intercambiar valores (no nodos)
        if (minNode != current) {
            int tempVal = (*current).value;
            (*current).value = (*minNode).value;
            (*minNode).value = tempVal;
        }
        
        current = (*current).next;
    }
}


void insertionSort(struct Node* head) {
    if (head == NULL || (*head).next == NULL) {
        return; // Lista vacía o con un solo elemento
    }
    
    struct Node* sorted = head; // Hasta aquí está ordenado
    struct Node* current = (*head).next; // Elemento a insertar
    
    while (current != NULL) {
        // Si el elemento actual está en la posición correcta
        if ((*sorted).value <= (*current).value) {
            sorted = current;
        } else {
            // Guardar el valor a insertar
            int key = (*current).value;
            
            // Encontrar dónde insertar en la parte ordenada
            struct Node* pos = head;
            while (pos != current && (*pos).value < key) {
                pos = (*pos).next;
            }
            
            // Desplazar todos los valores entre pos y current
            struct Node* move = current;
            while (move != pos) {
                // Encontrar el nodo previo a move
                struct Node* prev = head;
                while ((*prev).next != move) {
                    prev = (*prev).next;
                }
                
                // Desplazar el valor
                (*move).value = (*prev).value;
                move = prev;
            }
            
            // Insertar el valor en su posición correcta
            (*pos).value = key;
        }
        
        current = (*current).next;
    }
}


void bubbleSort(struct Node* head) {
    if (head == NULL || (*head).next == NULL) {
        return; // Lista vacía o con un solo elemento
    }
    
    int swapped;
    struct Node* end = NULL; // Límite de la parte ordenada
    
    do {
        swapped = 0;
        struct Node* current = head;
        
        while ((*current).next != end) {
            if ((*current).value > (*(*current).next).value) {
                // Intercambiar valores
                int temp = (*current).value;
                (*current).value = (*(*current).next).value;
                (*(*current).next).value = temp;
                swapped = 1;
            }
            current = (*current).next;
        }
        
        end = current; // Reducimos el rango de la siguiente iteración
    } while (swapped);
}

int main() {
    struct Node* head = NULL; // Lista vacía
    
    // Poblar la lista con valores desordenados
    append(&head, 30);
    append(&head, 10);
    append(&head, 50);
    append(&head, 20);
    print(head);
    delete(&head, 50);
    print(head);
    append(&head, 40);
    
    printf("Lista original:\n");
    print(head);
        
    // selectionSort(head);
    // printf("Después de Selection Sort:\n");
    
    // insertionSort(head);
    // printf("Después de Insertion Sort:\n");
    
    bubbleSort(head);
    printf("Después de Bubble Sort:\n");
    
    print(head);
    
    // Liberar memoria
    freeList(&head);
    
    return 0;
}
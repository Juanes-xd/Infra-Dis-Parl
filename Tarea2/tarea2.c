#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para revertir el vector
void revertirVector(int* vector, size_t tamanio) {
    int temp;
    size_t inicio = 0;
    size_t fin = tamanio - 1;
    
    while (inicio < fin) {
        // Intercambiar elementos
        temp = vector[inicio];
        vector[inicio] = vector[fin];
        vector[fin] = temp;
        
        // Mover índices
        inicio++;
        fin--;
    }
}

int main() {
    const size_t SIZE = 100000000; // 100 millones
    
    printf("Creando arreglo de %zu elementos...\n", SIZE);
    
    // Usar memoria dinámica para arreglo grande
    int* datos = (int*)malloc(SIZE * sizeof(int));
    
    if (datos == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }
    
    // Inicializar el arreglo con valores que sean el cociente entre la posición y 100
    for (size_t i = 0; i < SIZE; i++) {
        datos[i] = i % 100; // Usando división de enteros como se solicitó antes
    }
    
    // Mostrar algunos valores antes de revertir
    printf("Primeros 5 valores (antes de revertir):\n");
    for (size_t i = 0; i < 5 && i < SIZE; i++) {
        printf("datos[%zu] = %d\n", i, datos[i]);
    }
    
    printf("Últimos 5 valores (antes de revertir):\n");
    for (size_t i = SIZE - 5; i < SIZE; i++) {
        printf("datos[%zu] = %d\n", i, datos[i]);
    }
    
    // Revertir el vector (medir tiempo)
    printf("\nRevirtiendo el vector...\n");
    clock_t inicio = clock();
    revertirVector(datos, SIZE);
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo para revertir: %f segundos\n\n", tiempo);
    
    // Mostrar algunos valores después de revertir
    printf("Primeros 5 valores (después de revertir):\n");
    for (size_t i = 0; i < 5 && i < SIZE; i++) {
        printf("datos[%zu] = %d\n", i, datos[i]);
    }
    
    printf("Últimos 5 valores (después de revertir):\n");
    for (size_t i = SIZE - 5; i < SIZE; i++) {
        printf("datos[%zu] = %d\n", i, datos[i]);
    }
    
    // Liberar memoria
    free(datos);
    
    return 0;
}

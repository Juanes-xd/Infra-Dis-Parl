#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

// Función que suma elementos con stride específico
int sumarConStride(int* vector, size_t tamanio, int stride) {
    int suma = 0;
    for (size_t i = 0; i < tamanio; i += stride) {
        suma += vector[i];
    }
    return suma;
}

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
    const size_t SIZE = 100000000;
    int* datos = (int*)malloc(SIZE * sizeof(int));
    
    // Validar con assert que la memoria fue asignada correctamente
    assert(datos != NULL && "Error: No se pudo asignar memoria.");
    
    // Inicializar arreglo con valores 0-99
    for (size_t i = 0; i < SIZE; i++) {
        datos[i] = i % 100;
    }
    revertirVector(datos, SIZE);
    // Mostrar sumas con diferentes strides
    printf("Suma con stride 1 (todos los elementos): %d\n", 
           sumarConStride(datos, SIZE, 1));
    
  /**  printf("Suma con stride 2 (elementos pares): %d\n", 
           sumarConStride(datos, SIZE, 2));
    
    printf("Suma con stride 5 (cada quinto elemento): %d\n", 
           sumarConStride(datos, SIZE, 5));
    
    printf("Suma con stride 10 (cada décimo elemento): %d\n", 
           sumarConStride(datos, SIZE, 10));
    */
    free(datos);
    return 0;
}

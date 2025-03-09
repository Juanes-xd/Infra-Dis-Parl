#include <stdio.h>
#include <stdlib.h>
#include <assert.h>  // Incluir para usar assert()

#define SIZE 100000000   // Tamaño del vector: 100,000,000 elementos
#define STRIDE 16         // Valor del stride (salto)

int main() {
    // Reservar memoria dinámica para el vector
    int *vector = (int *)malloc(SIZE * sizeof(int));
    assert(vector != NULL && "Error: Fallo en malloc()");  // Validar con assert()

    // Recorrer cada offset desde 0 hasta STRIDE-1
    for (size_t offset = 0; offset < STRIDE; offset++) {
        // Visitar elementos comenzando en 'offset' con saltos de 'STRIDE'
        for (size_t i = offset; i < SIZE; i += STRIDE) {
            vector[i] = i % 100; // Operación de ejemplo
        }
    }

    // Liberar memoria y finalizar
    free(vector);
    return 0;
}

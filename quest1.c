#include <stdio.h>
#include <stdlib.h>

// Função para alocar memória dinamicamente
int *alocarMemoria(int n) {
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return array;
}

// Função para preencher o vetor
void preencherVetor(int *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = i * 10;
    }
}

// Função para imprimir o vetor
void imprimirVetor(int *array, int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *array, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Alocar memória dinamicamente
    array = alocarMemoria(n);

    // Preencher o array
    preencherVetor(array, n);

    // Imprimir o array
    imprimirVetor(array, n);

    // Liberar a memória alocada com malloc
    free(array);

    return 0;
}
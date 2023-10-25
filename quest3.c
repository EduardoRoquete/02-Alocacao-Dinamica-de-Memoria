#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Veículo
struct Veiculo {
    char chassi[20];
    char marca[50];
    char modelo[50];
    float preco;
};

// Função para alocar memória dinamicamente para um vetor de Veículo
struct Veiculo *alocarMemoria(int n) {
    struct Veiculo *array = (struct Veiculo *)malloc(n * sizeof(struct Veiculo));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return array;
}

// Função para preencher o vetor de Veículo
void preencherVetor(struct Veiculo *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o número do chassi do veículo %d: ", i + 1);
        scanf("%s", array[i].chassi);

        printf("Digite a marca do veículo %d: ", i + 1);
        scanf("%s", array[i].marca);

        printf("Digite o modelo do veículo %d: ", i + 1);
        scanf("%s", array[i].modelo);

        printf("Digite o preço do veículo %d: ", i + 1);
        scanf("%f", &array[i].preco);
    }
}

// Função para imprimir o vetor de Veículo
void imprimirVetor(struct Veiculo *array, int n) {
    printf("Dados dos veículos:\n");
    for (int i = 0; i < n; i++) {
        printf("Veículo %d:\n", i + 1);
        printf("Chassi: %s\n", array[i].chassi);
        printf("Marca: %s\n", array[i].marca);
        printf("Modelo: %s\n", array[i].modelo);
        printf("Preço: %.2f\n", array[i].preco);
    }
}

// Função para realocar o vetor de Veículo
struct Veiculo *realocarMemoria(struct Veiculo *array, int *n, int novo_tamanho) {
    array = (struct Veiculo *)realloc(array, novo_tamanho * sizeof(struct Veiculo));
    if (array == NULL) {
        printf("Falha na realocação de memória.\n");
        exit(1);
    }
    return array;
}

int main() {
    struct Veiculo *array;
    int n;

    printf("Digite o tamanho inicial do vetor de veículos: ");
    scanf("%d", &n);

    // Alocar memória dinamicamente para o vetor de Veículo
    array = alocarMemoria(n);

    // Preencher o vetor de Veículo
    preencherVetor(array, n);

    // Imprimir o vetor de Veículo
    imprimirVetor(array, n);

    // Realocar o vetor de Veículo para um tamanho maior
    int novo_tamanho = n + 5;
    array = realocarMemoria(array, &n, novo_tamanho);

    // Preencher os elementos adicionais
    for (int i = n; i < novo_tamanho; i++) {
        printf("Digite o número do chassi do veículo %d: ", i + 1);
        scanf("%s", array[i].chassi);

        printf("Digite a marca do veículo %d: ", i + 1);
        scanf("%s", array[i].marca);

        printf("Digite o modelo do veículo %d: ", i + 1);
        scanf("%s", array[i].modelo);

        printf("Digite o preço do veículo %d: ", i + 1);
        scanf("%f", &array[i].preco);

        n++; // Incrementar o tamanho do vetor
    }

    // Imprimir o vetor de Veículo após a realocação
    imprimirVetor(array, n);

    // Liberar a memória alocada
    free(array);

    return 0;
}
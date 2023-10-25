#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar funções de manipulação de strings

// Definição da estrutura Pessoa
struct Pessoa {
    char cpf[12];    // CPF como uma string de 11 dígitos
    char nome[100];  // Nome da pessoa
    float salario;   // Salário da pessoa
};

// Função para alocar memória dinamicamente para um vetor de Pessoa
struct Pessoa *alocarMemoria(int n) {
    struct Pessoa *pessoas = (struct Pessoa *)calloc(n, sizeof(struct Pessoa));
    if (pessoas == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return pessoas;
}

// Função para preencher o vetor de Pessoa
void preencherVetor(struct Pessoa *pessoas, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o CPF da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].cpf);

        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);

        printf("Digite o salário da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].salario);
    }
}

// Função para imprimir o vetor de Pessoa
void imprimirVetor(struct Pessoa *pessoas, int n) {
    printf("Vetor de Pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("CPF: %s\n", pessoas[i].cpf);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Salário: %.2f\n", pessoas[i].salario);
        printf("\n");
    }
}

int main() {
    struct Pessoa *pessoas;
    int n;

    printf("Digite o número de pessoas: ");
    scanf("%d", &n);

    // Alocar memória dinamicamente para o vetor de Pessoa
    pessoas = alocarMemoria(n);

    // Preencher o vetor de Pessoa
    preencherVetor(pessoas, n);

    // Imprimir o vetor de Pessoa
    imprimirVetor(pessoas, n);

    // Liberar a memória alocada com calloc
    free(pessoas);

    return 0;
}
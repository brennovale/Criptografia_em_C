#include <stdio.h>  
#include <string.h>  

// Define o tamanho máximo de caracteres
#define MAX 15

int main() {
    // Declaração dos vetores de caracteres com +1 espaço para o caractere nulo '\0'
    char palavra[MAX + 1];
    char palavra_criptografada[MAX + 1];
    
    // Variáveis inteiras para controle de dados e opções do menu
    int shift, opcao;
    int seq[MAX]; // Vetor que guardará a sequência matemática gerada

    printf("   SISTEMA DE CRIPTOGRAFIA MULTICAMADA   \n");

    // Leitura da palavra secreta (limita em 15 caracteres para evitar estouro de memória)
    printf("Digite a palavra secreta (ate 15 letras): ");
    scanf("%15s", palavra);

    // Leitura do SHIFT fixo (Cifra de César - Camada 1)
    printf("Digite o valor do SHIFT (ex: 3): ");
    scanf("%d", &shift);

    // Exibição do menu de sequências matemáticas
    printf("\nEscolha a sequencia matematica:\n");
    printf("1 - PA (1, 2, 3, 4...)\n");
    printf("2 - PG (1, 2, 4, 8...)\n");
    printf("3 - Fibonacci (1, 1, 2, 3, 5, 8, 13...)\n");
    printf("4 - Numeros Primos (2, 3, 5, 7, 11...)\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Obtenção do número exato de letras da palavra inserida
    int tamanho = strlen(palavra);
    
    // Progressão Aritmética (PA) -> Soma +1 a cada posição
    if (opcao == 1) { 
        for (int i = 0; i < tamanho; i++) {
            seq[i] = i + 1;
        }
    } 
    // Progressão Geométrica (PG) -> Multiplica por 2 a cada posição
    else if (opcao == 2) { 
        int val = 1;
        for (int i = 0; i < tamanho; i++) {
            seq[i] = val;
            val = val * 2;
        }
    } 
    // Série de Fibonacci -> Cada termo é a soma dos dois anteriores
    else if (opcao == 3) { 
        for (int i = 0; i < tamanho; i++) {    
            if (i == 0 || i == 1) {             
                seq[i] = 1;                     
            } else {                            
                seq[i] = seq[i - 1] + seq[i - 2];
            }
        }
    }
    // Números Primos -> Preenche com a lista ordenada de primos
    else if (opcao == 4) { 
        int primos[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
        for (int i = 0; i < tamanho; i++) {
            seq[i] = primos[i];
        }
    }

    for (int i = 0; i < tamanho; i++) {
        char letra = palavra[i];
        
        // Deslocamento total = SHIFT fixo (Camada 1) + Valor da sequência (Camada 2)
        int deslocamento = shift + seq[i];

        // Processa apenas caracteres minúsculos ('a' ate 'z')
        if (letra >= 'a' && letra <= 'z') {
            // A fórmula '% 26' garante que o alfabeto gire se a soma ultrapassar a letra 'z'
            palavra_criptografada[i] = 'a' + (letra - 'a' + deslocamento) % 26;
        } 
        // Processa apenas caracteres maiúsculos ('A' ate 'Z')
        else if (letra >= 'A' && letra <= 'Z') {
            palavra_criptografada[i] = 'A' + (letra - 'A' + deslocamento) % 26;
        } 
        // Mantém caracteres especiais ou números sem alterar
        else {
            palavra_criptografada[i] = letra;
        }
    }
    // Finaliza a string criptografada adicionando o caractere terminador nulo
    palavra_criptografada[tamanho] = '\0';

    printf("Palavra Criptografada: %s\n", palavra_criptografada);
    
    // Abre o arquivo "resultado_criptografia.txt" em modo de escrita
    FILE *arquivo = fopen("resultado_criptografia.txt", "w");
    
    if (arquivo != NULL) {
        // Grava a linha formatada com as informações exigidas no enunciado
        fprintf(arquivo, "Palavra codificada: %s | SHIFT: %d | Tipo: %d | Letras: %d\n",
                palavra_criptografada, shift, opcao, tamanho);
        
        // Fecha o arquivo para salvar as alterações no disco
        fclose(arquivo);
        printf("Resultado gravado com sucesso em 'resultado_criptografia.txt'\n");
    } else {
        printf("Erro ao criar o arquivo de resultado.\n");
    }

    return 0; 
}

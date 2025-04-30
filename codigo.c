#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 1
int fatorial(int n) {
    return (n <= 1) ? 1 : n * fatorial(n - 1);
}

// 2
int soma_natural(int n) {
    return (n <= 1) ? 1 : n + soma_natural(n - 1);
}

// 3
int fibonacci(int n) {
    return (n <= 1) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

// 4
int potencia(int n, int y) {
    return (y == 0) ? 1 : n * potencia(n, y - 1);
}

// 5
int regressivo(int n) {
    if (n <= 0) return 0;
    printf("%d ", n);
    return regressivo(n - 1);
}

// 6
int digitos(int n) {
    return (n == 0) ? 0 : (n % 10) + digitos(n / 10);
}

// 7
void inverter_string(char str[], int i, int tamanho) {
    if (i >= tamanho / 2) return;
    char temp = str[i];
    str[i] = str[tamanho - i - 1];
    str[tamanho - i - 1] = temp;
    inverter_string(str, i + 1, tamanho);
}

// 8
int ehPalindromo(const char *str, int inicio, int fim) {
    if (inicio >= fim) return 1;
    if (str[inicio] != str[fim]) return 0;
    return ehPalindromo(str, inicio + 1, fim - 1);
}


// 9
int mdc(int a, int b) {
    return (b == 0) ? a : mdc(b, a % b);
}

// 10
int multiplicar(int a, int b) {
    return (b == 0) ? 0 : a + multiplicar(a, b - 1);
}

// 11
int contarChar(const char *str, char c) {
    return (*str == '\0') ? 0 : (*str == c) + contarChar(str + 1, c);
}

// 12
int somaArray(int arr[], int tamanho, int indice) {
    return (indice == tamanho) ? 0 : arr[indice] + somaArray(arr, tamanho, indice + 1);
}

// 13 && 14
int ehPrimoAux(int n, int i) {
    if (i * i > n) return 1;
    if (n % i == 0) return 0;
    return ehPrimoAux(n, i + 1);
}
int Primo(int n) {
    if (n <= 1) return 0;
    return ehPrimoAux(n, 2);
}

// 15
void decimalParaBinario(int n) {
    if (n == 0) return;
    decimalParaBinario(n / 2);
    printf("%d", n % 2);
}

// 16
void imprimirPares(int n) {
    if (n < 0) return;
    imprimirPares(n - 2);
    if (n % 2 == 0) printf("%d ", n);
}

// 17
void imprimirImpares(int n) {
    if (n <= 0) return;
    imprimirImpares(n - 2);
    if (n % 2 == 1) printf("%d ", n);
}

// 18
int buscaArray(int arr[], int tamanho, int elemento, int indice) {
    if (indice == tamanho) return 0;
    if (arr[indice] == elemento) return 1;
    return buscaArray(arr, tamanho, elemento, indice + 1);
}

// 19
int comprimento(const char *str) {
    return (*str == '\0') ? 0 : 1 + comprimento(str + 1);
}

// 20
void torreDeHanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }
    torreDeHanoi(n - 1, origem, auxiliar, destino);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    torreDeHanoi(n - 1, auxiliar, destino, origem);
}

// 21
void trocar(char *x, char *y) {
    char temp = *x; *x = *y; *y = temp;
}
void permutar(char *str, int inicio, int fim) {
    if (inicio == fim) {
        printf("%s\n", str);
        return;
    }
    for (int i = inicio; i <= fim; i++) {
        trocar(&str[inicio], &str[i]);
        permutar(str, inicio + 1, fim);
        trocar(&str[inicio], &str[i]);
    }
}

// 22
void combinar(int arr[], int n, int k, int index, int dados[], int i) {
    if (index == k) {
        for (int j = 0; j < k; j++) printf("%d ", dados[j]);
        printf("\n");
        return;
    }
    if (i >= n) return;
    dados[index] = arr[i];
    combinar(arr, n, k, index + 1, dados, i + 1);
    combinar(arr, n, k, index, dados, i + 1);
}

// 23
void subconjuntos(int arr[], int n, int index, int subset[], int tam) {
    if (index == n) {
        printf("{ ");
        for (int i = 0; i < tam; i++) printf("%d ", subset[i]);
        printf("}\n");
        return;
    }
    subset[tam] = arr[index];
    subconjuntos(arr, n, index + 1, subset, tam + 1);
    subconjuntos(arr, n, index + 1, subset, tam);
}

// 24 & 25
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = j = 0; k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int dividir(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        if (arr[j] <= pivo) {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1]; arr[i + 1] = arr[alto]; arr[alto] = tmp;
    return i + 1;
}
void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = dividir(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

// 26
int buscaBinaria(int arr[], int esq, int dir, int alvo) {
    if (esq > dir) return -1;
    int meio = (esq + dir) / 2;
    if (arr[meio] == alvo) return meio;
    return (arr[meio] > alvo)
        ? buscaBinaria(arr, esq, meio - 1, alvo)
        : buscaBinaria(arr, meio + 1, dir, alvo);
}

// 27
int potenciaRapida(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return potenciaRapida(x * x, n / 2);
    return x * potenciaRapida(x * x, (n - 1) / 2);
}

// 28
int contarCaminhos(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    if (x1 == x2 && y1 == y2) return 1;
    return contarCaminhos(x1 + 1, y1, x2, y2) + contarCaminhos(x1, y1 + 1, x2, y2);
}

// 29
int subsetSoma(int arr[], int n, int soma) {
    if (soma == 0) return 1;
    if (n == 0) return 0;
    if (arr[n - 1] > soma) return subsetSoma(arr, n - 1, soma);
    return subsetSoma(arr, n - 1, soma) || subsetSoma(arr, n - 1, soma - arr[n - 1]);
}

// 30
#define L 3
#define C 4
int resolverLabirinto(int lab[L][C], int x, int y, int sol[L][C]) {
    if (x == L - 1 && y == C - 1 && lab[x][y] == 0) {
        sol[x][y] = 1;
        return 1;
    }
    if (x >= 0 && x < L && y >= 0 && y < C && lab[x][y] == 0 && sol[x][y] == 0) {
        sol[x][y] = 1;
        if (resolverLabirinto(lab, x + 1, y, sol) || resolverLabirinto(lab, x, y + 1, sol)) return 1;
        sol[x][y] = 0;
    }
    return 0;
}

// 30
void gerarParenteses(int abertos, int fechados, int n, char *str, int pos) {
    if (pos == 2 * n) {
        str[pos] = '\0';
        printf("%s\n", str);
        return;
    }
    if (abertos < n) {
        str[pos] = '(';
        gerarParenteses(abertos + 1, fechados, n, str, pos + 1);
    }
    if (fechados < abertos) {
        str[pos] = ')';
        gerarParenteses(abertos, fechados + 1, n, str, pos + 1);
    }
}



int main() {
    int resultado;

    resultado = fatorial(5);
    printf("1. Fatorial: %d\n", resultado);

    resultado = soma_natural(5);
    printf("2. Soma natural: %d\n", resultado);

    resultado = fibonacci(5);
    printf("3. Fibonacci: %d\n", resultado);

    resultado = potencia(2, 3);
    printf("4. Potência: %d\n", resultado);

    printf("5. Regressivo: ");
    regressivo(5);
    printf("\n");

    resultado = digitos(1234);
    printf("6. Soma dos dígitos: %d\n", resultado);

    char str[] = "recursao";
    inverter_string(str, 0, strlen(str));
    printf("7. String invertida: %s\n", str);

    char palavra[] = "radar";
    printf("8. Verificando se '%s' é palíndromo: %s\n", palavra,
           ehPalindromo(palavra, 0, strlen(palavra) - 1) ? "Sim" : "Não");
    
    resultado = mdc(48, 18);
    printf("9. MDC: %d\n", resultado);

    resultado = multiplicar(3, 4);
    printf("10. Multiplicação: %d\n", resultado);

    resultado = contarChar("banana", 'a');
    printf("11. Ocorrências de 'a': %d\n", resultado);

    int arr1[] = {1, 2, 3, 4, 5};
    resultado = somaArray(arr1, 5, 0);
    printf("12. Soma array: %d\n", resultado);

    resultado = Primo(7);
    printf("13. É primo: %s\n", resultado ? "Sim" : "Não");

    printf("14. Binário de 10: ");
    decimalParaBinario(10);
    printf("\n");

    printf("15. Pares até 10:\n");
    imprimirPares(10);
    printf("\n16. Ímpares até 9:\n");
    imprimirImpares(9);
    printf("\n");

    int arr2[] = {1, 2, 3};
    resultado = buscaArray(arr2, 3, 2, 0);
    printf("17. Busca elemento 2: %s\n", resultado ? "Encontrado" : "Não encontrado");

    resultado = comprimento("exemplo");
    printf("18. Comprimento da string: %d\n", resultado);

    printf("19. Torre de Hanoi (3 discos):\n");
    torreDeHanoi(3, 'A', 'C', 'B');

    char perm[] = "abc";
    printf("20. Permutações de 'abc':\n");
    permutar(perm, 0, strlen(perm) - 1);

    int dados[3], subset[5];
    printf("21. Combinações de 3 entre 5 elementos:\n");
    combinar(arr1, 5, 3, 0, dados, 0);

    printf("22. Subconjuntos:\n");
    subconjuntos(arr1, 5, 0, subset, 0);

    int arr3[] = {5, 2, 4, 1, 3};
    mergeSort(arr3, 0, 4);
    printf("23. MergeSort:\n");
    for (int i = 0; i < 5; i++) printf("%d ", arr3[i]);
    printf("\n");

    int arr4[] = {7, 3, 9, 1, 5};
    quickSort(arr4, 0, 4);
    printf("24. QuickSort:\n");
    for (int i = 0; i < 5; i++) printf("%d ", arr4[i]);
    printf("\n");

    int arr5[] = {1, 2, 3, 4, 5};
    resultado = buscaBinaria(arr5, 0, 4, 3);
    printf("25. Busca Binária de 3: Índice %d\n", resultado);

    resultado = potenciaRapida(2, 10);
    printf("26. Potência rápida 2^10: %d\n", resultado);

    resultado = contarCaminhos(0, 0, 2, 2);
    printf("27. Caminhos possíveis: %d\n", resultado);

    int arr6[] = {3, 34, 4, 12, 5, 2};
    resultado = subsetSoma(arr6, 6, 9);
    printf("28. Subset sum para 9: %s\n", resultado ? "Sim" : "Não");

    int lab[L][C] = {
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 0}
    };
    int sol[L][C] = {0};

    if (resolverLabirinto(lab, 0, 0, sol)) {
        printf("29. Caminho encontrado no labirinto:\n");
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < C; j++) {
                printf("%d ", sol[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("29. Nenhum caminho encontrado no labirinto.\n");
    }

    int nPar = 3;
    char parenteses[2 * nPar + 1];
    printf("30. Parênteses balanceados:\n");
    gerarParenteses(0, 0, nPar, parenteses, 0);

    return 0;
}

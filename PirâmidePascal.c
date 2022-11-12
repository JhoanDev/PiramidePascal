#include <stdio.h>
#include <locale.h>

unsigned long long int fatorial(int numero);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int altura, largura, linhas, qnt = 0, contP, testes, testescont;
    int pascal[17][17], resultado = 0;
    printf("Insira a quantidade de testes que deseja fazer: ");
    scanf("%d", &testes);
    for (testescont = 1; testescont <= testes; testescont++)
    {
        resultado = 0;
        contP = 0;
        printf("\n||%dº teste||\n", testescont);
        printf("\nInsira quantas linhas (limite de 17) deseja que tenha o seu triângulo de pascal: ");
        scanf("%d", &linhas);
        printf("\n");
        for (altura = 0; altura < linhas; altura++)
        {
            contP++;
            for (largura = 0; largura < 17; largura++)
            {
                if (largura != contP)
                {
                    pascal[altura][largura] = (fatorial(altura)) / ((fatorial(largura)) * (fatorial(altura - largura)));
                    resultado = pascal[altura][largura] + resultado;
                    qnt++;
                }
                else
                {
                    break;
                }
            }
            for (largura = 0; largura < contP; largura++)
            {
                printf("%d\t", pascal[altura][largura]);
            }
            printf("\n");
        }
        printf("\n\nA soma de todos os números do seu triângulo é: %d \n", resultado);
        printf("\nA média de todos os números do seu triângulo é: %d \n\n", resultado / qnt);
    }
}

unsigned long long int fatorial(int numero)
{
    unsigned long long int fat = 1;
    if (numero > 1)
    {
        for (int i = 2; i <= numero; i++)
        {
            fat = i * fat;
        }
    }
    else
    {
        fat = 1;
    }
    return (fat);
}
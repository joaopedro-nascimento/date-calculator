#include <stdio.h>
#include <locale.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;
int ehbissexto(int a)
{
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
    {
        return 1;
    }
    return 0;
}
int validarData(Data data)
{
    if (data.dia <= 0 || data.dia > 31)
    {
        return 0;
    }
    if (data.mes <= 0 || data.mes > 12)
    {
        return 0;
    }
    if (data.ano <= 0)
    {
        return 0;
    }
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Data data;
    Data data2;
    int opcao;

    do
    {
        printf("informe a primeira data em formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    } while (!validarData(data));

    do
    {
        printf("informe a segunda data em formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);
    } while (!validarData(data));

    printf("A data é em %d/%d/%d\n", data.dia, data.mes, data.ano);
    printf("A segunda data é em %d/%d/%d\n", data2.dia, data2.mes, data2.ano);

    opcao = menu();
    switch (opcao)
    {

    case 1:
        printf("Calculando...");

    case 2:
        printf("Calculando...");

    case 3:
        printf("Calculando...");

    case 4:
        printf("Calculando...");

    case 5:
        printf("Calculando...");

    default:
        printf("Invalido!");
    }
}

int menu()
{
    int opcao;

    printf("========== ESCOLHA DO CALCULO ==========\n");
    printf("1) Calcular a quantidade de dias entre duas datas no mesmo mês.\n");
    printf("2) Calcular a quantidade de dias entre duas datas no mesmo ano.\n");
    printf("3) Calcular a quantidade de dias entre duas datas em anos consecutivos.\n");
    printf("4) Calcular a quantidade de dias entre duas datas em anos quaisquer (inclusive em séculos diferentes).\n");
    printf("5) Calcular a data final que marca a quantidade de dias passado no periodo.\n");
    printf("Digite um dos valores acima para escolher (1 a 5), 0 para cancelar.\n");
    scanf("%d", &opcao);

    return opcao;
}
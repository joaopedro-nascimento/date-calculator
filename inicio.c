#include <stdio.h>
#include <locale.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

int ehbissexto(Data data)
{
    if ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int validarData(Data data)
{
    if (data.mes <= 0 || data.mes > 12 || data.ano <= 0)
    {
        return 0;
    }

    int diasDoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(ehbissexto(data)){
        diasDoMes[2] = 29;
    }

    if (data.dia <= 0 || data.dia > diasDoMes[data.mes])
    {
        return 0;
    }
    
    return 1;
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
    } while (!validarData(data2));

    printf("A primeira data é em %d/%d/%d\n", data.dia, data.mes, data.ano);
    printf("A segunda data é em %d/%d/%d\n", data2.dia, data2.mes, data2.ano);

    opcao = menu();
    switch (opcao)
    {

    case 1:
        printf("Calculando...");
        break;

    case 2:
        printf("Calculando...");
        break;

    case 3:
        printf("Calculando...");
        break;

    case 4:
        printf("Calculando...");
        break;

    case 5:
        printf("Calculando...");
        break;

    default:
        printf("Invalido!");
        break;
        
    }
}
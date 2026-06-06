#include <stdio.h>
#include <locale.h>
int diasDoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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

    if (ehbissexto(data))
    {
        diasDoMes[2] = 29;
    }

    if (data.dia <= 0 || data.dia > diasDoMes[data.mes])
    {
        return 0;
    }

    return 1;
}
int dma(Data data, Data data2)
{
    int soma = 0;
    if (data.mes > data2.mes)
    {
        for (int i = data2.mes; i <= data.mes; i++)
        {
            soma += diasDoMes[i];
        }
    }
    else
    {
        for (int i = data.mes; i <= data2.mes; i++)
        {
            soma += diasDoMes[i];
        }
    }
    int dia1 = diasDoMes[data.mes] - data.dia;
    int somaDia = dia1 + data2.dia;
    return soma - somaDia;
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

int DmM(Data data, Data data2)
{
    int diferenca;
    diferenca = data.dia - data2.dia;
    if (data.dia < data2.dia)
    {
        diferenca = -diferenca;
    }
    return diferenca;
}

int main()
{
    int sma;
    setlocale(LC_ALL, "Portuguese");
    Data data;
    Data data2;
    int opcao;
    int DiferDmM;

    do
    {
        printf("informe a primeira data em formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
        if (!validarData(data))
        {
            printf("Data inválida!\n");
        }
    } while (!validarData(data));

    do
    {
        printf("informe a segunda data em formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);
        if (!validarData(data2))
        {
            printf("Data inválida!\n");
        }
    } while (!validarData(data2));

    printf("A primeira data é em %d/%d/%d\n", data.dia, data.mes, data.ano);
    printf("A segunda data é em %d/%d/%d\n", data2.dia, data2.mes, data2.ano);

    opcao = menu();
    switch (opcao)
    {

    case 1:
        if (data.mes != data2.mes)
        {
            printf("Erro: As datas precisam ser do mesmo mês para esta opção!\n");
        }
        else
        {
            printf("Calculando...\n");
            DiferDmM = DmM(data, data2);
            printf("A quantidade de dias entre as duas datas eh de %d dias.\n", DiferDmM);
        }
        break;

    case 2:
        if (data.ano != data2.ano)
        {
            printf("Sinto muito! Mas esta opcão só é válida para datas dentro do mesmo ano... ");
        }
        else
        {
            sma = dma(data, data2);
            printf("Calculando...\n");
            printf("A quantidade de dias entre as duas datas é de %d dias.", sma);
        }
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
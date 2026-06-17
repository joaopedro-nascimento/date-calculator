#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "calculos.h"

int diasDoMesL[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Data data;
Data data2;
Data dataFinal;
int opcao, DiferDmM, DiferDmA, DiferDmAC, DiferDmAQ, diasParaSomar, continuar;

int validarData(Data data)
{
    diasDoMesL[2] = 28;
    if (data.mes <= 0 || data.mes > 12 || data.ano <= 0)
    {
        return 0;
    }

    if (ehbissexto(data))
    {
        diasDoMesL[2] = 29;
    }

    if (data.dia <= 0 || data.dia > diasDoMesL[data.mes])
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

void pegarData()
{
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
}

void Caso1()
{
    pegarData();
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
}

void Caso2()
{
    pegarData();
    if (data.ano != data2.ano)
    {
        printf("Sinto muito! Mas esta opcão só é válida para datas dentro do mesmo ano...\n");
    }
    else
    {
        printf("Calculando...\n");
        DiferDmA = dma(data, data2);
        printf("A quantidade de dias entre as duas datas é de %d dias.\n", DiferDmA);
    }
}

void Caso3()
{
    pegarData();
    if (data2.ano - data.ano != 1)
    {
        printf("Erro: As data devem ser de anos consecutivos para essa opção.");
    }
    else
    {
        printf("Calculando...\n");
        DiferDmAC = DmAC(data, data2);
        printf("A quantidade de dias entre as duas datas é de %d dias.\n", DiferDmAC);
    }
}

void Caso4()
{
    pegarData();
    printf("Calculando...\n");
    DiferDmAQ = DmAQ(data, data2);
    printf("A quantidade de dias entre as duas datas eh de %ld dias\n", DiferDmAQ);
}

void Caso5()
{
    do
    {
        do
        {
            printf("informe a data inicial em formato dd/mm/aaaa\n");
            scanf(" %d/%d/%d", &data.dia, &data.mes, &data.ano);
            if (!validarData(data))
            {
                printf("Data inválida!\n");
            }
        } while (!validarData(data));
        printf("Digite a quantidade de dias que se passaram no periodo: ");
        scanf("%d", &diasParaSomar);
        if (diasParaSomar < 0)
        {
            printf("Por favor insira uma quantidade positiva de dias.");
        }
    } while (diasParaSomar < 0);

    printf("Calculando...\n");

    long diasData1 = converterParaDias(data);
    long diasFinal = diasData1 + diasParaSomar;
    dataFinal = descobrirData(diasFinal);

    printf("A data final apos %d dias sera: %02d/%02d/%04d\n", diasParaSomar, dataFinal.dia, dataFinal.mes, dataFinal.ano);
}

void chamarProjeto()
{
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            Caso1();
            break;

        case 2:
            Caso2();
            break;

        case 3:
            Caso3();
            break;

        case 4:
            Caso4();
            break;

        case 5:
            Caso5();
            break;

        default:
            printf("Invalido!");
            break;
        }
        printf("\nDeseja realizar uma nova operacao? (1 - Sim / 0 - Nao): ");
        scanf("%d", &continuar);

    } while (continuar == 1);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    chamarProjeto();
    return 0;
}
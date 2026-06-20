// utility.c
#include <stdio.h>
#include "calculos.h"
#include "utility.h"

// Vetor auxiliar com a quantidade de dias de cada mês.
int diasDoMesL[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Declaração de Variáveis.
Data data;
Data data2;
Data dataFinal;
int opcao, DiferDmM, DiferDmA, DiferDmAC, DiferDmAQ, diasParaSomar, continuar;

// Função para validar a data, com dias de meses e anos corretos.
int validarData(Data data)
{
    diasDoMesL[2] = 28; // Reseta fevereiro para o padrão
    if (data.mes <= 0 || data.mes > 12 || data.ano <= 0)
    {
        return 0;
    }

    // Ajusta fevereiro caso o ano seja bissexto
    if (ehbissexto(data))
    {
        diasDoMesL[2] = 29;
    }

    // Verifica se o dia está no intervalo correto do mês correspondente
    if (data.dia <= 0 || data.dia > diasDoMesL[data.mes])
    {
        return 0;
    }

    return 1;
}

/*Exibe o menu principal de opções de cálculo no terminal.
Lê a opção digitada pelo usuário e a retorna.*/
int menu()
{
    int opcao;
    printf("=============================");
    printf("\n   =====   INICIO   =====\n");
    printf("=============================\n\n");
    printf("========== ESCOLHA UMA OPERACAO ==========\n");
    printf("1) Calcular a quantidade de dias entre duas datas no mesmo mês.\n");
    printf("2) Calcular a quantidade de dias entre duas datas no mesmo ano.\n");
    printf("3) Calcular a quantidade de dias entre duas datas em anos consecutivos.\n");
    printf("4) Calcular a quantidade de dias entre duas datas em anos quaisquer (inclusive em séculos diferentes).\n");
    printf("5) Calcular a data final que marca a quantidade de dias passado no periodo.\n");
    printf("Digite um dos valores acima para escolher (1 a 5), 0 para cancelar.\n");
    scanf("%d", &opcao);

    return opcao;
}

/*Solicita ao usuário a entrada de duas datas no formato dd/mm/aaaa.
A função repete o pedido individual de cada data até que ambas sejam válidas.*/
void pegarData()
{
    // Entrada e validação da primeira data
    do
    {
        printf("Por favor, informe a primeira data em formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
        if (!validarData(data))
        {
            printf("Data inválida!\n");
            printf("Tente novamente com outros valores...");
        }
    } while (!validarData(data));

    // Entrada e validação da segunda data
    do
    {
        printf("Por favor, informe a segunda data em formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);
        if (!validarData(data2))
        {
            printf("Data inválida!\n");
            printf("Tente novamente com outros valores...");
        }
    } while (!validarData(data2));
}

/*Gerencia o fluxo principal do projeto.
Controla a exibição do menu, chama as funções de leitura, valida as regras de
negócio de cada opção e exibe os resultados.*/
void chamarProjeto()
{
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            pegarData();
            // Valida se pertencem ao mesmo mês antes de calcular
            if (data.mes != data2.mes)
            {
                printf("Erro: As datas precisam ser do mesmo mes para esta opcao!\n");
                printf("Tente novamente com outros valores...");
            }
            else
            {
                printf("Calculando...\n");
                DiferDmM = DmM(data, data2);
                printf("SHOW!!\n");
                printf("A quantidade de dias entre as datas eh de %d dias.\n",DiferDmM);
            }
            break;

        case 2:
            pegarData();
            // Valida se pertencem ao mesmo ano antes de calcular
            if (data.ano != data2.ano)
            {
                printf("Sinto muito! Mas esta opcão so eh válida para datas dentro do mesmo ano...\n");
                printf("Tente novamente com outros valores...");
            }
            else
            {
                printf("Calculando...\n");
                DiferDmA = DmA(data, data2);
                printf("Eba!\n");
                printf("A quantidade de dias entre as duas datas é de %d dias.\n", DiferDmA);
            }
            break;

        case 3:
            pegarData();
            // Valida se pertencem anos consecutivos antes de calcular
            if (data2.ano - data.ano != 1)
            {
                printf("Erro: As data devem ser de anos consecutivos para essa opção.");
                printf("Tente novamente com outros valores...\n");
            }
            else
            {
                printf("Calculando...\n");
                DiferDmAC = DmAC(data, data2);
                printf("Que dahora!!\n");
                printf("A quantidade de dias entre as duas datas eh de %d dias.\n", DiferDmAC);
            }
            break;

        case 4:
            pegarData();
            printf("Calculando...\n");
            DiferDmAQ = DmAQ(data, data2);
            printf("Maravilha!!\n");
            printf("A quantidade de dias entre as duas datas eh de %d dias\n", DiferDmAQ);
            break;

        case 5:
            // Solicita uma data base e uma quantidade positiva de dias para somar
            do
            {
                do
                {
                    printf("Informe a data inicial em formato dd/mm/aaaa\n");
                    scanf(" %d/%d/%d", &data.dia, &data.mes, &data.ano);
                    if (!validarData(data))
                    {
                        printf("Data invalida!\n");
                        printf("Tente novamente com outros valores...\n");
                    }
                } while (!validarData(data));
                printf("Por gentileza, digite a quantidade de dias que se passaram no periodo: ");
                scanf("%d", &diasParaSomar);
                if (diasParaSomar < 0)
                {
                    printf("Por favor, insira uma quantidade positiva de dias.");
                }
            } while (diasParaSomar < 0);

            printf("Calculando...\n");

            // Converte a data inicial para dias totais, soma o período e converte de volta para Data
            long diasData1 = converterParaDias(data);
            long diasFinal = diasData1 + diasParaSomar;
            dataFinal = descobrirData(diasFinal);
            printf("Por essa voce não esperava...\n");
            printf("A data final apos %d dias sera: %02d/%02d/%04d\n", diasParaSomar, dataFinal.dia, dataFinal.mes, dataFinal.ano);
            break;

        default:
            printf("\n--OPERACAO CANCELADA--\n");
            break;
        }
        
        // Pergunta se o usuário deseja reiniciar o loop principal
        printf("\nDeseja realizar uma nova operacao? (1 - Sim / 0 - Nao): \n");
        scanf("%d", &continuar);

    } while (continuar == 1);
    if(continuar== 0){
       printf("====================");
       printf("--FIM DO PROGRAMA--");
       printf("====================\n");
       printf("QUANDO ESTIVER PRECISANDO CALCULAR MAIS DATAS EH SO CHAMAR :P...");
    }
}
// main.c
#include <stdio.h>
#include <locale.h>
#include "utility.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    chamarProjeto();
    return 0;
}
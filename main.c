#include <stdio.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
* Início da declaração prévia das funções
-------------------------------------------------*/

void calculadoraHexaAdicao(char *valor1, char *valor2);
void calculadoraHexaSub(char *valor1, char *valor2);
void calculadoraHexaMulti(char *valor1, char *valor2);
void calculadoraHexaDiv(char *valor1, char *valor2);

int max(int, int);
int valorNumerico(char valor);
char valorChar(int valor);

/*-------------------------------------------------
*Fim da declaração prévia das funções
-------------------------------------------------*/


//transformador de números para caracteres ----> usar em todos os conversores hexadecimais
char numeroEMCHAR(long long int numero)
{
    if (numero >= 0 && numero <= 9)
    {
        return (char)(numero + '0');
    } else if (numero >= 10 && numero <= 15)
    {
        return (char)(numero - 10 + 'A');
    }else
    {
        return -1;
    }

}

//decimal PARA binário ----> divisão do número decimal por 2, atribuição do resto para o número binário final.
//sem erros -- adicionar casos de restrição
long long int decimalBINARIO(long long int decimal)
{
    long long int binario = 0, base = 1;
    int resto, i, n = 0;

        while (decimal > 0)
        {
        resto = decimal % 2;
        binario += resto * base;
        decimal /= 2;
        base *= 10;
        }
        return binario;
}

//decimal PARA octal ----> divisão do número decimal por 8, atribuição do inverso do resto para o número octal final.
//sem erros ---- adicionar casos de restrição
long long int decimalOCTAL(long long int decimal)
{
    long long int octal = 0, Ioctal = 0;
    int resto, i, n = 0;

        while(decimal > 0)
        {
            resto = decimal % 8;
            Ioctal = (Ioctal * 10) + resto;
            decimal /= 8;
            n++;
        }

        for(i = 0; i < n; i++)
        {
            octal *= 10;
            octal = octal + Ioctal % 10;
            Ioctal /= 10;
        }

        return octal;
}

//decimal PARA hexadecimal ----> divisão do número decimal por 16, atribuição do inverso do resto para o número hexadecimal final.
// ----------------------------> efetuar a divisão de todos os algarismos por 16, e verificar se deve ser trocado por CHAR, inverter.
long long int decimalHEXADECIMAL(long long int decimal, char hexa[])
{
    int i = 0;
    long long int resto;
    char charHEXA;

    while(decimal > 0)
    {
        resto = decimal % 16;
        charHEXA = numeroEMCHAR(resto);
        hexa[i] = charHEXA;
        i++;
        decimal /= 16;
    }
    hexa[i] = "\0";

    int esquerda = 0;
    int direita = i - 1;
    while(esquerda < direita)
    {
        char flag = hexa[esquerda];
        hexa[esquerda] = hexa[direita];
        hexa[direita] = flag;
        esquerda++;
        direita--;
    }

return i;

}


//binário PARA decimal ----> contador de algarismos, conversão por potenciação do número 2 à posição do algarismo.
//sem erros ---- adicionar casos de restrição
long long int binarioDECIMAL(long long int binario)
{
    long long int Idecimal, decimal = 0;
    int i, n = 0;
    long long int Ibinario = binario;

        do
        {
            Ibinario /= 10;
            n++;
        }while(Ibinario > 0);

        for(i = 0; i < n; i++)
        {
            Idecimal = binario % 10;
            decimal = decimal + Idecimal * pow(2, i);
            binario /= 10;
        }

        return decimal;
}

//binário PARA octal ----> contador de algarismos, fragmentação do número binário em partes de 3 algarismo, conversão de cada fração + adesão das partes.
//sem erros ---- adicionar casos de restrição
long long int binarioOCTAL(long long int binario)
{
    long long int Ioctal, octal = 0;
    int i, j, n = 0, In = 0;
    long long int Ibinario = binario;

        do
        {
            Ibinario /= 10;
            n++;
        }while(Ibinario > 0);

        for(i = 0; i < n; i = i + 3)
        {
            octal *= 10;
            Ibinario = Ibinario + binario % 1000;
            binario /= 1000;
            for(j = 0; j < 3; j++)
            {
                Ioctal = Ibinario % 10;
                octal = octal + (Ioctal * pow(2, j));
                Ibinario /= 10;
            }
            In++;
        }

        for(i = 0; i < In; i++)
        {
            Ibinario *= 10;
            Ibinario = Ibinario + octal % 10;
            octal /= 10;
        }
        octal = Ibinario;

        return octal;

}

//binário PARA hexadecimal
//fetuar a divisão de todos os algarismos por 16, e verificar se deve ser trocado por CHAR, inverter.
long long int binarioHEXA(long long int binario, char Hexa[])
{
    int j, i = 0;
    long long int digito = 0, numeroDECIMAL, numeroHEXA = 0;
    int bit, base;
    char charHEXA;

    while(binario > 0)
    {
            bit = binario % 10000;
            numeroDECIMAL = 0;
            base = 1;

        for(j = 0; j < 4; j++)
        {
            digito = bit % 10;
            numeroDECIMAL += digito * base;
            base *= 2;
            bit /= 10;
        }

        charHEXA = numeroEMCHAR(numeroDECIMAL);
        Hexa[i] = charHEXA;
        i++;

        binario /= 10000;
    }

    int esquerda = 0;
    int direita = i - 1;
    while(esquerda < direita)
    {
        char flag = Hexa[esquerda];
        Hexa[esquerda] = Hexa[direita];
        Hexa[direita] = flag;
        esquerda++;
        direita--;
    }

    return i;

}


//octal PARA decimal ----> contador de algarismos, conversão por potenciação do número 8 à posição do algarismo.
//sem erros ---- adicionar casos de restrição
long long int octalldECIMAL(long long int octal)
{
    long long int Idecimal, decimal = 0;
    int i, n = 0;
    long long int Ioctal = octal;

        do
        {
            Ioctal /= 10;
            n++;
        }while(Ioctal > 0);

        for(i = 0; i < n; i++)
        {
            Idecimal = octal % 10;
            decimal = decimal + Idecimal * pow(8, i);
            octal /= 10;
        }

        return decimal;
}

//octal PARA binário ----> converto o ultimo número do algarismo PAR binario e, inverto o resultado.
//sem erros ---- adicionar casos de restrição
long long int octalBINARIO(long long int octal)
{
    long long int binario = 0;
    long long int base = 1;

    while (octal > 0)
    {
        int octalld = octal % 10;
        long long int binarioD = 0;
        long long int peso = 1;

        while (octalld > 0)
        {
            int resto = octalld % 2;
            binarioD += resto * peso;
            octalld /= 2;
            peso *= 10;
        }

        binario += binarioD * base;
        base *= 1000;

        octal /= 10;
    }

    return binario;
}


//octal PARA hexadecimal

long long int octalHEXA(long long int octal, char Hexa[])
{
    long long int binario = 0;
    long long int base = 1;
    int i;

    while (octal > 0)
    {
        int octalld = octal % 10;
        long long int binarioD = 0;
        long long int peso = 1;

        while (octalld > 0)
        {
            int resto = octalld % 2;
            binarioD += resto * peso;
            octalld /= 2;
            peso *= 10;
        }

        binario += binarioD * base;
        base *= 1000;

        octal /= 10;
    }

    i = binarioHEXA(binario, Hexa);

    return i;
}

//transformador de caracteres para números ----> aplicação em todos os hexadecimais
long long int charEMNUMERO(char Hexa)
{
    if (Hexa >= '0' && Hexa <= '9')
    {
        return (char)(Hexa - '0');
    } else if (Hexa >= 'A' && Hexa <= 'F')
    {
        return (char)(Hexa - 'A' + 10);
    } else {
        return -1;
    }
}

//hexadecimal PARA decimal
long long int hexaDECIMAL(char Hexa[])
{
    long long int decimal = 0;
    int i = 0;

    while (Hexa[i] != '\0')
    {
        char caractere = Hexa[i];

        if ((caractere >= '0' && caractere <= '9') || (caractere >= 'A' && caractere <= 'F')) {
            int valor = charEMNUMERO(caractere);
            if (valor == -1) {
                return -1;
            }
            // Atualize o valor decimal multiplicando por 16 e adicionando o valor do caractere
            decimal = decimal * 16 + valor;
        } else
        {
            return -1;
        }
        i++;
    }
    return decimal;
}


//hexadecimal PARA binário
long long int hexaBINARIO(char Hexa[])
{
    long long int decimal = 0;
    int i = 0;
    long long int binario = 0, base = 1;
    int resto, n = 0;

    decimal = hexaDECIMAL(Hexa);

        while (decimal > 0)
        {
        resto = decimal % 2;
        binario += resto * base;
        decimal /= 2;
        base *= 10;
    }
        return binario;

}

//hexadecimal PARA octal
long long int hexaOCTAL(char Hexa[])
{
    long long int decimal = hexaDECIMAL(Hexa);
    long long int octal = 0, Ioctal = 0;
    int resto, i, n = 0;

        while(decimal > 0)
        {
            resto = decimal % 8;
            Ioctal = (Ioctal * 10) + resto;
            decimal /= 8;
            n++;
        }

        for(i = 0; i < n; i++)
        {
            octal *= 10;
            octal = octal + Ioctal % 10;
            Ioctal /= 10;
        }

        return octal;

}

int calculadoraOctalAdicao(int num1, int num2) {
    num1 = (long long int)num1;
    num2 = (long long int)num2;
    
    long long int dec1 = octalldECIMAL(num1);
    long long int dec2 = octalldECIMAL(num2);
    long long int resDecimal=dec1 + dec2;
    long long int resOctal= decimalOCTAL(resDecimal);
    return (int)resOctal;
}
int calculadoraOctalSubtracao(int num1, int num2){
    num1 = (long long int)num1;
    num2 = (long long int)num2;
    
    long long int dec1 = octalldECIMAL(num1);
    long long int dec2 = octalldECIMAL(num2);
    long long int resDecimal=dec1 - dec2;
    long long int resOctal= decimalOCTAL(resDecimal);
    return (int)resOctal;
}
int calculadoraOctalMultiplicacao (int num1, int num2){
    num1 = (long long int)num1;
    num2 = (long long int)num2;
    
    long long int dec1 = octalldECIMAL(num1);
    long long int dec2 = octalldECIMAL(num2);
    long long int resDecimal=dec1 * dec2;
    long long int resOctal= decimalOCTAL(resDecimal);
    return (int)resOctal;
}
int calculadoraOctalDivisao(int num1, int num2){
        num1 = (long long int)num1;
    num2 = (long long int)num2;
    
    long long int dec1 = octalldECIMAL(num1);
    long long int dec2 = octalldECIMAL(num2);
    long long int resDecimal=dec1 / dec2;
    long long int resOctal= decimalOCTAL(resDecimal);
    return (int)resOctal;
}

//calculadoraBinarioAdicao: recebe dois inteiros em binario e converte ambos em decimal
//depois realiza a soma em decimal e converte o resultado em binário 
int calculadoraBinarioAdicao(int num1, int num2) {
        num1 = (long long int)num1;
        num2 = (long long int)num2;
    
            long long int d1 = binarioDECIMAL(num1);
            long long int d2 = binarioDECIMAL(num2);
            long long int resultadoDecimal= d1 + d2;
            long long int resultadoBinario = decimalBINARIO(resultadoDecimal);
        return (int)resultadoBinario;
}
//calculadoraBinarioSubtracao: recebe dois inteiros em binario e converte ambos em decimal
//depois realiza a subtração em decimal e converte o resultado em binário 
int calculadoraBinarioSubtracao(int num1, int num2){
        num1 = (long long int)num1;
        num2 = (long long int)num2;
    
            long long int d1 = binarioDECIMAL(num1);
            long long int d2 = binarioDECIMAL(num2);
            long long int resultadoDecimal = d1 - d2;
            long long int resultadoBinario= decimalBINARIO(resultadoDecimal);
        return (int)resultadoBinario;
}
//calculadoraBinarioMultiplicacao: recebe dois inteiros em binário e converte ambos em decimal
//depois realiza a multiplicação em decimal e converte o resultado em binário 
int calculadoraBinarioMultiplicacao (int num1, int num2){
        num1 = (long long int)num1;
        num2 = (long long int)num2;
    
            long long int d1 = binarioDECIMAL(num1);
            long long int d2 = binarioDECIMAL(num2);
            long long int resultadoDecimal = d1 * d2;
            long long int resultadoBinario = decimalBINARIO(resultadoDecimal);
        return (int)resultadoBinario;
}
//calculadoraBinarioDivisao: recebe dois inteiros em binario e converte ambos em decimal
//depois realiza a divisão em decimal e converte o resultado em binário 
int calculadoraBinarioDivisao(int num1, int num2){
        num1 = (long long int)num1;
        num2 = (long long int)num2;
    
            long long int d1 = binarioDECIMAL(num1);
            long long int d2 = binarioDECIMAL(num2);
            long long int resultadoDecimal = d1 / d2;
            long long int resultadoBinario = decimalBINARIO(resultadoDecimal);
        return (int)resultadoBinario;
}

int main() {
    int baseConversor, baseCalculadora, converter, contador = 0, opcao, entradaCalculo1, entradaCalculo2, operacao;
    char entradaHexa1[20], entradaHexa2[20];
    //Loop infinito para converter quantas vezes o usúario do programa quiser, ele vai ser finalizado quando o contador ser igual a 1
    while(contador == 0) {
        long long int decimal;
        long long int binario;
        long long int octal;
        long long hexa;
        long long int entrada = 0;

        printf("\n\n");
        printf("--------------------------------------------\n");
        printf("          QUAL OPÇÃO VOCÊ DESEJA\n");
        printf("--------------------------------------------\n\n");

        printf(">> [1] - CALCULADORA 2000\n");
        printf(">> [2] - CONVERSOR 2000\n");
        printf(">> [3] - SAIR\n");

        printf("\n~ ");
        scanf("%d", &opcao);
        printf("\n");

        if(opcao == 1){
            printf("--------------------------------------------\n");
            printf("          CALCULADORA 2000\n");
            printf("--------------------------------------------\n\n");

            printf("------------------------\n");
            printf("|      MADE IN INF     |\n");
            printf("------------------------\n");
            printf("|   1   |   2   |   3   |+|/|\n");
            printf("|   4   |   5   |   6   |-|\n");
            printf("|   7   |   8   |   9   |*|$|\n");
            printf("------------------------\n\n");

            printf(">>DIGITE O NÚMERO DA BASE QUE DESEJA CALCULAR\n");

            printf("$");
            scanf("%d", &baseCalculadora);
            printf("\n");

            printf(">>1 - SOMA\n");
            printf(">>2 - SUBTRAÇÃO\n");
            printf(">>3 - MULTIPLICAÇÃO\n");
            printf(">>4 - DIVISÃO\n");
            printf(">>5 - SAIR\n\n");

            printf("QUAL OPERAÇÃO VOCÊ DESEJA?\n");
            printf("$");
            scanf("%d", &operacao);
            printf("\n");

            switch (baseCalculadora) {
                case 16:
                    printf(">>DIGITE OS NÚMEROS QUE DESEJA CALCULAR COM LETRAS MAIÚSCULAS\n");
                    scanf("%s %s", &entradaHexa1, &entradaHexa2);

                    switch(operacao) {
                        case 1:
                            printf("--------------------------------------------\n");
                            printf("          	SOMA\n");
                            printf("--------------------------------------------\n\n");
					
                            calculadoraHexaAdicao(entradaHexa1, entradaHexa2);

                            break;
                        case 2:
                            printf("--------------------------------------------\n");
                            printf("          		SUBTRAÇÃO\n");
                            printf("--------------------------------------------\n\n");

                            calculadoraHexaSub(entradaHexa1, entradaHexa2);

                            break;
                        case 3:
                            printf("--------------------------------------------\n");
                            printf("          	  MULTIPLICAÇÃO\n");
                            printf("--------------------------------------------\n\n");
                            
                            calculadoraHexaMulti(entradaHexa1, entradaHexa2);
                            
                            break;
                        case 4:
                            printf("--------------------------------------------\n");
                            printf("          		DIVISÃO\n");
                            printf("--------------------------------------------\n\n");
                            
                            calculadoraHexaDiv(entradaHexa1, entradaHexa2);
                            
                            break;
                        case 5:
                            //agradecimentos finais do código
                            printf(">>Obrigado por usar nosso conversor de medidas! \nFeito pelos alunos:\n");
                            printf(">>Ryan Gabryel\n");
                            printf(">>Luis Renato\n");
                            printf(">>Rafael Mattos\n");
                            printf(">>Felipe S\n");
                            printf(">>Joao Pedro\n");
                            //contador = 1, para sair do while true, já que 5 é o caso de saída
                            contador++;
                            break;
                    }
                    break;
                case 2:
                    printf(">>DIGITE OS NÚMEROS QUE DESEJA CALCULAR COM LETRAS MAIÚSCULAS\n");
                    scanf("%d %d", &entradaCalculo1, &entradaCalculo2);

                    switch(operacao) {
                        case 1:
                            printf("--------------------------------------------\n");
                            printf("          	SOMA\n");
                            printf("--------------------------------------------\n\n");
                            printf("Resultado: %d", calculadoraBinarioAdicao(entradaCalculo1, entradaCalculo2));
                            break;
                        case 2:
                            printf("--------------------------------------------\n");
                            printf("          		SUBTRAÇÃO\n");
                            printf("--------------------------------------------\n\n");
                            printf("Resultado: %d", calculadoraBinarioSubtracao(entradaCalculo1, entradaCalculo2));
                            break;
                        case 3:
                            printf("--------------------------------------------\n");
                            printf("          	  MULTIPLICAÇÃO\n");
                            printf("--------------------------------------------\n\n");
                            printf("Resultado: %d", calculadoraBinarioMultiplicacao(entradaCalculo1, entradaCalculo2));
                            break;
                        case 4:
                            printf("--------------------------------------------\n");
                            printf("          		DIVISÃO\n");
                            printf("--------------------------------------------\n\n");
                            printf("Resultado: %d", calculadoraBinarioDivisao(entradaCalculo1, entradaCalculo2));
                            break;
                        case 5:

                            //agradecimentos finais do código
                            printf(">>Obrigado por usar nosso conversor de medidas! \nFeito pelos alunos:\n");
                            printf(">>Ryan Gabryel\n");
                            printf(">>Luis Renato\n");
                            printf(">>Rafael Mattos\n");
                            printf(">>Felipe S\n");
                            printf(">>Joao Pedro\n");
                            //contador = 1, para sair do while true, já que 5 é o caso de saída
                            contador++;
                            break;
                    }
                    break;
                case 8:
                    printf(">>DIGITE OS NÚMEROS QUE DESEJA CALCULAR COM LETRAS MAIÚSCULAS\n");
                    scanf("%d %d", &entradaCalculo1, &entradaCalculo2);
                    
                    switch(operacao) {
                        case 1:
                            printf("--------------------------------------------\n");
                            printf("          	SOMA\n");
                            printf("--------------------------------------------\n\n");

                            printf("O resultado é: %d", calculadoraOctalAdicao(entradaCalculo1, entradaCalculo2));

                            break;
                        case 2:
                            printf("--------------------------------------------\n");
                            printf("          		SUBTRAÇÃO\n");
                            printf("--------------------------------------------\n\n");
                            printf("O resultado é: %d", calculadoraOctalSubtracao(entradaCalculo1, entradaCalculo2));
                            break;
                        case 3:
                            printf("--------------------------------------------\n");
                            printf("          	  MULTIPLICAÇÃO\n");
                            printf("--------------------------------------------\n\n");
                            printf("O resultado é: %d", calculadoraOctalMultiplicacao(entradaCalculo1, entradaCalculo2));
                            break;
                        case 4:
                            printf("--------------------------------------------\n");
                            printf("          		DIVISÃO\n");
                            printf("--------------------------------------------\n\n");
                            printf("O resultado é: %d", calculadoraOctalDivisao(entradaCalculo1, entradaCalculo2));
                            break;
                        case 5:

                            //agradecimentos finais do código
                            printf(">>Obrigado por usar nosso conversor de medidas! \nFeito pelos alunos:\n");
                            printf(">>Ryan Gabryel\n");
                            printf(">>Luis Renato\n");
                            printf(">>Rafael Mattos\n");
                            printf(">>Felipe S\n");
                            printf(">>Joao Pedro\n");
                            //contador = 1, para sair do while true, já que 5 é o caso de saída
                            contador++;
                            break;
                    }
                    break;
            }
        } else if(opcao == 2) {
            char Hexa[50];
            int i, BASE = 0, BASE2 = 0;
            long long int tamanho;

            printf("--------------------------------------------\n");
            printf("	      CONVERSOR 2000               \n");
            printf("--------------------------------------------\n\n");

            printf("--------------------------------------------\n");
            printf("          CONVERSOES SUPORTADAS\n");
            printf("--------------------------------------------\n\n");
            printf(">>Selecione a base que deseja converter\n");
            printf(">> [2] - BINARIO\n");
            printf(">> [8] - OCTAL\n");
            printf(">> [10] - DECIMAL\n");
            printf(">> [16] - HEXADECIMAL\n");
            printf("\n~ ");
            scanf("%d", &BASE);
            if(BASE != 2 && BASE != 8 && BASE != 10 && BASE != 16)
            {
                printf("ERRO: selecione um sistema númerico válido\n");
                contador++;
                return 0;
            }

            //recebo a entrada que vou converter
            printf("\n>>Qual o número que deseja converter? \n");
            printf("~ ");

            int funcionaporfavor = 0;
            if(BASE == 16)
            {
                scanf("%s", Hexa);
            }
            else if(BASE == 2)
            {
                int j = 0;
                scanf("%lld", &entrada);
                binario = entrada;
                do
                {
                    j = (entrada % 10);
                    if(j > 1 || j < 0)
                    {
                        printf("ERRO: digite um número binário válido!\n");  
                        funcionaporfavor++;
                        return 0;

                    }
                    entrada /= 10;
                }while(entrada > 0);
            }
            else if(BASE == 8)
            {
                int j = 0;
                scanf("%lld", &entrada);
                octal = entrada;
                do
                {
                    j = (entrada % 10);
                    if(j == 8 || j == 9)
                    {
                        printf("ERRO: digite um número octal válido!\n");
                        funcionaporfavor++;
                        return 0;
                    }
                    entrada /= 10;
                }while(entrada > 0);
            }
            else
            {
                scanf("%lld", &entrada);
                decimal = entrada;
                hexa = entrada;
            }

            
            printf("\n");

            //construi o codigo baseado em suas proprias variaveis.


            printf(">>Selecione a base desejada para a conversão.\n");
                switch(BASE)
                {
                    case 2:
                        printf(">> [8] - OCTAL\n");
                        printf(">> [10] - DECIMAL\n");
                        printf(">> [16] - HEXADECIMAL\n");
                        printf("\n~ ");
                        scanf("%d", &BASE2);
                        break;

                    case 8:
                        printf(">> [2] - BINARIO\n");
                        printf(">> [10] - DECIMAL\n");
                        printf(">> [16] - HEXADECIMAL\n");
                        printf("\n~ ");
                        scanf("%d", &BASE2);
                    break;

                    case 10:
                        printf(">> [2] - BINARIO\n");
                        printf(">> [8] - OCTAL\n");
                        printf(">> [16] - HEXADECIMAL\n");
                        printf("\n~ ");
                        scanf("%d", &BASE2);
                        break;

                    case 16:
                        printf(">> [2] - BINARIO\n");
                        printf(">> [8] - OCTAL\n");
                        printf(">> [10] - DECIMAL\n");
                        printf("\n~ ");
                        scanf("%d", &BASE2);
                        break;

                    default:
                    return 0;
                }

            if(BASE2 != 2 && BASE2 != 8 && BASE2 != 10 && BASE2 != 16)
            {
                printf("ERRO: selecione um sistema númerico válido!\n");
                contador++;
                return 0;
            }
            

            //a opção é basicamente o número que eu tenho e vou converter ele para binario, octal e hexadecimal;
            switch (BASE)
                {
                //binario para N
                case 2:
                    printf("--------------------------------------------\n");
                    printf("	     BINARIO");
                    switch (BASE2)
                    {
                        case 8:
                    printf(" - OCTAL\n");
                    printf("--------------------------------------------\n\n");
                    printf("CONVERSÂO:\n");
                            // Caso para BASE = 2 e BASE2 = 8
                            octal = binarioOCTAL(binario);
                            printf("%lld(2) = %lld(8)\n", binario, octal);
                            break;
                        case 10:
                    printf(" - DECIMAL\n");
                    printf("--------------------------------------------\n\n");
                    printf("CONVERSÂO:\n");
                            // Caso para BASE = 2 e BASE2 = 10
                            decimal = binarioDECIMAL(binario);
                            printf("%lld(2) = %lld(10)\n", binario, decimal);
                            break;
                        case 16:
                    printf(" - HEXADECIMAL\n");
                    printf("--------------------------------------------\n\n");
                    printf("CONVERSÂO:\n");
                            // Caso para BASE = 2 e BASE2 = 16
                            tamanho = binarioHEXA(octal, Hexa);

                            printf("%lld(8) = ", binario);
                            for(i = 0; i < tamanho; i++)
                                {
                                    printf("%c", Hexa[i]);
                                }
                            printf("(16)\n");
                            break;
                    }
                    break;
                //octal para N
            case 8:
                printf("--------------------------------------------\n");
                printf("	     OCTAL");
                switch (BASE2)
                    {
                        case 2:
                            printf(" - BINARIO\n");
                            printf("--------------------------------------------\n");
                            printf("CONVERSÂO:\n");
                            // Caso para BASE = 8 e BASE2 = 2
                            binario = octalBINARIO(octal);
                            printf("%lld(8) = %lld(2)\n", octal, binario);
                            break;
                        case 10:
                            printf(" - DECIMAL\n");
                            printf("--------------------------------------------\n");
                            printf("CONVERSÂO:\n");
                            // Caso para BASE = 8 e BASE2 = 10
                            decimal = octalldECIMAL(octal);
                            printf("%lld(8) = %lld(10)\n", octal, decimal);
                            break;
                        case 16:
                            printf(" - HEXADECIMAL\n");
                            printf("--------------------------------------------\n");
                            printf("CONVERSÂO:\n");
                                        // Caso para BASE = 8 e BASE2 = 16
                                        tamanho = octalHEXA(octal, Hexa);

                                        printf("%lld(8) = ", octal);
                                        for(i = 0; i < tamanho; i++)
                                            {
                                                printf("%c", Hexa[i]);
                                            }
                                        printf("(16)\n");
                                        break;
                                }
                                break;

                //decimal para N
                case 10:
                    printf("--------------------------------------------\n");
                    printf("	     DECIMAL");
                    switch (BASE2)
                    {
                        case 2:
                            printf(" - BINARIO\n");
                            printf("--------------------------------------------\n");
                            printf("CONVERSÂO:\n");
                            // Caso para BASE = 10 e BASE2 = 2
                            binario = decimalBINARIO(decimal);
                            printf("%lld(10) = %lld(2)\n", decimal, binario);
                            break;
                        case 8:
                            printf(" - OCTAL\n");
                            printf("--------------------------------------------\n");
                            printf("CONVERSÂO:\n");
                            // Caso para BASE = 10 e BASE2 = 8
                            octal = decimalOCTAL(decimal);
                            printf("%lld(10) = %lld(8)\n", decimal, octal);
                            break;
                        case 16:
                            printf(" - HEXADECIMAL\n");
                            printf("--------------------------------------------\n");
                            printf("CONVERSÂO:\n");
                            // Caso para BASE = 10 e BASE2 = 16
                            tamanho = decimalHEXADECIMAL(decimal, Hexa);
                            printf("%lld(10) = ", decimal);

                            for(i = 0; i < tamanho; i++)
                            {
                                printf("%c", Hexa[i]);
                            }
                            printf("(16)\n");
                            break;
                            }
                    break;

                //hexadecimal para N
                case 16:
                printf("--------------------------------------------\n");
                printf("	   HEXADECIMAL");
                    switch (BASE2)
                    {
                        case 2:
                            printf(" - BINARIO\n");
                            printf("--------------------------------------------\n");
                            printf("CONVERSÂO:\n");
                            // Caso para BASE = 16 e BASE2 = 2

                            binario = hexaBINARIO(Hexa);
                            printf("%s(16) = %lld(2)\n", Hexa, binario);
                            break;
                        case 8:
                            printf(" - OCTAL\n");
                            printf("--------------------------------------------\n");
                            printf("CONVERSÂO:\n");
                                        // Caso para BASE = 16 e BASE2 = 8

                            octal = hexaOCTAL(Hexa);
                            printf("%s(16) = %lld(8)\n", Hexa, octal);
                            break;
                        case 10:
                            printf(" - DECIMAL\n");
                            printf("--------------------------------------------\n");
                            printf("CONVERSÂO:\n");
                                        // Caso para BASE = 16 e BASE2 = 10

                            decimal = hexaDECIMAL(Hexa);
                            printf("%s(16) = %lld(10)\n", Hexa, decimal);
                            break;
                    }
                            }

                            char g;
                            printf("\n\nContinuar?\n [Y]:\n [N]:\n\n ~");
                            getchar();
                                scanf(" %c", &g);
                                if(g == 'Y' || g == 'y')
                                {
                                    continue;
                                }
                                else if(g == 'N' || 'n')
                                {
                                    contador++;
                                }
                                else
                                {
                                    return 0;
                                }
                            
                

        } else if(opcao == 3) {
            printf("\n\n>>Obrigado por usar nosso conversor de medidas! \nFeito pelos alunos:\n");
            printf(">>Ryan Gabryel\n");
            printf(">>Luis Renato\n");
            printf(">>Rafael Mattos\n");
            printf(">>Felipe S\n");
            printf(">>Joao Pedro\n");
            contador++;
        }
    }

    return 0;
}

/*-------------------------------------------------
* Início das funções de calculadora
-------------------------------------------------*/

// calculadoraHexaAdicao: recebe duas strings de números hexadecimais com letras maiúsculas, soma os números e printa o resultado
void calculadoraHexaAdicao(char *valor1, char *valor2) {
    int algarismo1, algarismo2, numeroAtual;
    int resto = 0;

    int tamanhoMaximo = max(strlen(valor1), strlen(valor2));

    char resultado[tamanhoMaximo + 2];
    
    // esse loop itera por cara algarismo da direita para a esquerda, adiciona
    // seus resultados e coloca na posiçao correta na string resultado, considerando
    // o resto
    for (int i = 0; i < tamanhoMaximo; i++) {
        algarismo1 = valorNumerico(valor1[strlen(valor1) - 1 - i]);
        algarismo2 = valorNumerico(valor2[strlen(valor2) - 1 - i]);

        numeroAtual = algarismo1 + algarismo2 + resto;
        resto = 0;
        if (numeroAtual > 15) {
            resto = numeroAtual / 15;
            numeroAtual -= resto * 16;
        }

        resultado[tamanhoMaximo - i] = valorChar(numeroAtual);
    }

    // essa parte adiciona os caracteres necessários para a string em c
    resultado[tamanhoMaximo + 1] = '\0';
    if (resto != 0) {
        resultado[0] = valorChar(resto);
    }
    else {
        resultado[0] = '\b'; // o '\b' é backspace. só precisava de qualquer caractere q o printf não lê
    }

    printf("RESULTADO: %s", resultado);
}

void calculadoraHexaSub(char *valor1, char *valor2) {
    long long int valorDecimal1 = hexaDECIMAL(valor1);
    long long int valorDecimal2 = hexaDECIMAL(valor2);

    long long int resultadoDecimal = valorDecimal1 - valorDecimal2;

    char resultadoHexadecimal[20];
    decimalHEXADECIMAL(resultadoDecimal, resultadoHexadecimal);
    printf ("RESULTADO: %s", resultadoHexadecimal);
}

void calculadoraHexaMulti(char *valor1, char *valor2) {
    long long int valorDecimal1 = hexaDECIMAL(valor1);
    long long int valorDecimal2 = hexaDECIMAL(valor2);

    long long int resultadoDecimal = valorDecimal1 * valorDecimal2;

    char resultadoHexadecimal[20];
    decimalHEXADECIMAL(resultadoDecimal, resultadoHexadecimal);
    printf ("RESULTADO: %s", resultadoHexadecimal);
}

void calculadoraHexaDiv(char *valor1, char *valor2) {
    long long int valorDecimal1 = hexaDECIMAL(valor1);
    long long int valorDecimal2 = hexaDECIMAL(valor2);

    long long int resultadoDecimal = valorDecimal1 / valorDecimal2;

    char resultadoHexadecimal[20];
    decimalHEXADECIMAL(resultadoDecimal, resultadoHexadecimal);
    printf ("RESULTADO: %s", resultadoHexadecimal);
}

/*-------------------------------------------------
* Fim das funções de calculadora
-------------------------------------------------*/

/*-------------------------------------------------
* Início das funções globais
-------------------------------------------------*/

// max: recebe dois números inteiros e retorna o maior dentre eles.
int max(int num1, int num2) {
    if (num1 >= num2) {
        return num1;
    }
    else {
        return num2;
    }
}

// min: recebe dois números inteiros e retorna o menor dentre eles
int min(int num1, int num2) {
    if (num1 <= num2) {
        return num1;
    }
    else {
        return num2;
    }
}

// valorNumerico: recebe um caractere e retorna seu valor numérico de acordo com a tabela ascii
int valorNumerico (char valor) {
    if (valor >= 'A' && valor <= 'F') {
            return valor - 55;
    }
    else if (valor >= '0' && valor <= '9') {
        return valor - '0';
    }
    return 0;
}

// valorChar: recebe um charactere e retorna seu formato em char, convertendo os números para letras
char valorChar (int valor) {
    if (valor > 9) {
        return valor + 55;
    }
    else {
        return valor + '0';
    }
}

/*-------------------------------------------------
* Fim das funções globais
-------------------------------------------------*/

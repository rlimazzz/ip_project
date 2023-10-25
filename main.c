#include <stdio.h>

/* 
Início da declaração prévia das variáveis
 */

char[] calculadoraHexaAdição(char[], char[]);

int max(int, int);

/* 
Fim da declaração prévia das variáveis
 */

int main() {
	int entrada, baseConversor, baseCalculadora, converter, contador = 0, opcao, entradaCalculo1, entradaCalculo2, operacao;
	//Loop infinito para converter quantas vezes o usúario do programa quiser, ele vai ser finalizado quando o contador ser igual a 1 
	while(contador < 1){
		printf("--------------------------------------------\n");
		printf("          QUAL OPÇÃO VOCÊ DESEJA\n");
		printf("--------------------------------------------\n\n");
		
		printf(">>1 - CALCULADORA 2000\n");
		printf(">>2 - CONVERSOR 2000\n");
		printf(">>3 - SAIR\n");
		
		printf("$");
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
			
			printf(">>ENTRADA : BASE, PRIMEIRO NUMERO, SEGUNDO NUMERO\n");
			
			printf("$");
			scanf("%d %d %d", &baseCalculadora, &entradaCalculo1, &entradaCalculo2);
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
			
			switch(operacao) {
				
				case 1:
				
					printf("--------------------------------------------\n");
					printf("          	SOMA\n");
					printf("--------------------------------------------\n\n");
					break;
					
				case 2: 
				
					printf("--------------------------------------------\n");
					printf("          		SUBTRAÇÃO\n");
					printf("--------------------------------------------\n\n");
					break;
					
				case 3: 
				
					printf("--------------------------------------------\n");
					printf("          	  MULTIPLICAÇÃO\n");
					printf("--------------------------------------------\n\n");
					break;
					
				case 4: 
				
					printf("--------------------------------------------\n");
					printf("          		DIVISÃO\n");
					printf("--------------------------------------------\n\n");
					break;
					
				case 5:
				
					//agradecimentos finais do código
					printf(">>Obrigado por usar nosso conversor de medidas! \nFeito pelos alunos:\n");
					printf(">>Ryan Gabryel\n");
					printf(">>Luiz Renato\n");
					printf(">>Rafael Mattos\n");
					printf(">>Felipe S\n");
					//contador = 1, para sair do while true, já que 5 é o caso de saída
					contador++;
					break;
			}
			
		}
		else if(opcao == 2) {
			printf("--------------------------------------------\n");
			printf("	      CONVERSOR 2000               \n");
			printf("--------------------------------------------\n\n");
		
			//recebo a entrada que vou converter
			printf(">>Qual o número que deseja converter e a base desse número? \n");
			printf("$");
			scanf("%d %d", &entrada, &baseConversor);
			printf("\n");

			printf("--------------------------------------------\n");
			printf("          CONVERSOES SUPORTADAS\n");
			printf("--------------------------------------------\n\n");
			printf(">>1 - BINARIO\n");
			printf(">>2 - DECIMAL\n");
			printf(">>3 - HEXADECIMAL\n");
			printf(">>4 - OCTAL\n");
			printf(">>5 - FECHAR\n");
		
			//a opção é basicamente o número que eu tenho e vou converter ele para binario, octal e hexadecimal;
			printf(">>Digite para qual quer converter\n");
			printf("$");
			scanf("%d", &converter);
			printf("\n");
			
			switch(converter) {
				case 1:
				
					printf("--------------------------------------------\n");
					printf("                BINARIO\n");
					printf("--------------------------------------------\n\n");
					break;
				case 2:
				
					printf("--------------------------------------------\n");
					printf("          		DECIMAL\n");
					printf("--------------------------------------------\n\n");
					break;
				case 3:
				
					printf("--------------------------------------------\n");
					printf("          		HEXADECIMAL\n");
					printf("--------------------------------------------\n\n");
					break;
				case 4:
				
					printf("--------------------------------------------\n");
					printf("          		OCTAL\n");
					printf("--------------------------------------------\n\n");
					break;

				case 5:
				
					//agradecimentos finais do código
					printf(">>Obrigado por usar nosso conversor de medidas! \nFeito pelos alunos:\n");
					printf(">>Ryan Gabryel\n");
					printf(">>Luiz Renato\n");
					printf(">>Rafael Mattos\n");
					printf(">>Felipe S\n");
					//contador = 1, para sair do while true, já que 5 é o caso de saída
					contador++;
					break;
				}
		}else {
				//agradecimentos finais do código
				printf(">>Obrigado por usar nosso conversor de medidas! \nFeito pelos alunos:\n");
				printf(">>Ryan Gabryel\n");
				printf(">>Luiz Renato\n");
				printf(">>Rafael Mattos\n");
				printf(">>Felipe S\n");
				//contador = 1, para sair do while true, já que 5 é o caso de saída
				contador++;
				break;
		}
	}
	return 0;
}

/* 
* Início das funções de calculadora
*/

// essa função recebe duas strings de números hexadecimais com letras maiúsculas, soma elas e retorna uma string contendo a soma
char[] calculadoraHexaAdição(char valor1[], char valor2[]) {
	int tamanho1 = sizeof(valor1) / sizeof(valor1[0]);
	int tamanho2 = sizeof(valor2) / sizeof(valor2[0]);
	int algarismo1, algarismo2;
	int resto = 0;

	int tamanhoMaximo = max(tamanho1, tamanho2);

	char resultado[tamanhoMaximo];
	
	for (int i = 0; i < tamanhoMaximo; i++) {
		// esses dois ifs pegam os valores numéricos dos atuais algarismos sendo somados
		if (valor1[tamanho1 - 1 - i] >= 'A' && valor1[tamanho1 - 1 - i] <= 'F') {
			algarismo1 = valor1[tamanho1 - 1 - i] - 55;
		}
		else {
			algarismo1 = valor1[tamanho1 - 1 - i] - '0';
		}
		if (valor2[tamanho2 - 1 - i] >= 'A' && valor2[tamanho2 - 1 - i] <= 'F') {
			algarismo2 = valor2[tamanho2 - 1 - i] - 55;
		}
		else {
			algarismo2 = valor2[tamanho2 - 1 - i] - '0';
		}

		if (algarismo1 + algarismo2 > 15) {
			resultado[tamanhoMaximo - 1 - i] = algarismo1 + algarismo2 - resto;
			resto = (algarismo1 + algarismo2) / 10;
		}

		if (resultado[tamanhoMaximo - 1 - i] > 9) {

		}
	}
}

// Fim das funções de calculadora

/* 
* Início das funções globais
*/

// essa função recebe dois números inteiros e retorna o maior dentre eles.
int max(int num1, int num2) {
	if (num1 >= num2) {
		return num1;
	}
	else {
		return num2;
	}
}

// Fim das funções globais

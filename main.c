#include <stdio.h>
#include <string.h>

/* 
Início da declaração prévia das variáveis
 */

char *calculadoraHexaAdicao(char *valor1, char *valor2);

int max(int, int);
int valorNumerico(char valor);
char valorChar(int valor);

/* 
Fim da declaração prévia das variáveis
 */

int main() {
	calculadoraHexaAdicao("", "");

	int entrada, baseConversor, baseCalculadora, converter, contador = 0, opcao, operacao;
	char entradaCalculo1[20], entradaCalculo2[20];
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

					switch (baseCalculadora) {
					case 16:
						printf("RESULTADO DA SOMA: %s\n", calculadoraHexaAdicao(entradaCalculo1, entradaCalculo2));
						break;
					
					default:
						break;
					}

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
char *calculadoraHexaAdicao(char *valor1, char *valor2) {
	valor1 = "1";
	valor2 = "2";

	int tamanho1 = strlen(valor1);
	int tamanho2 = strlen(valor2);
	int algarismo1, algarismo2, numeroAtual;
	int resto = 0;

	int tamanhoMaximo = max(tamanho1, tamanho2);

	char resultado[tamanhoMaximo + 1];
	
	for (int i = 0; i < tamanhoMaximo + 1; i++) {
		if (i == tamanhoMaximo) {
			resultado[tamanhoMaximo - 1 - i] = valorChar(resto);
			continue;
		}

		algarismo1 = valorNumerico(valor1[tamanho1 - 1 - i]);
		algarismo2 = valorNumerico(valor2[tamanho1 - 1 - i]);

		numeroAtual = algarismo1 + algarismo2 + resto;
		if (numeroAtual > 15) {
			resto = (algarismo1 + algarismo2 + resto) / 15;
			numeroAtual -= resto / 10;
		}

		resultado[tamanhoMaximo - 1 - i] = valorChar(numeroAtual);
	}

	printf("%s\n", resultado);
}
// estou com problemas para fazer o último algarismo funcionar e para fazer os números serem colocados no resultado na ordem certa

// Fim das funções de calculadora

/* 
* Início das funções globais
*/

// Max: recebe dois números inteiros e retorna o maior dentre eles.
int max(int num1, int num2) {
	if (num1 >= num2) {
		return num1;
	}
	else {
		return num2;
	}
}

// valorNumerico: recebe um charactere e retorna seu valor numérico de acordo com a tabela ascii
int valorNumerico (char valor) {
	if (valor >= 'A' && valor <= 'F') {
			return valor - 55;
	}
	else {
		return valor - '0';
	}
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

// Fim das funções globais

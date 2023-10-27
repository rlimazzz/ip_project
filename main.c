#include <stdio.h>
#include <string.h>

/*-------------------------------------------------
* Início da declaração prévia das variáveis
-------------------------------------------------*/

char *calculadoraHexaAdicao(char *valor1, char *valor2);
void calculadoraHexaMulti(char *valor1, char *valor2);

int max(int, int);
int valorNumerico(char valor);
char valorChar(int valor);

/*-------------------------------------------------
*Fim da declaração prévia das variáveis
-------------------------------------------------*/

int main() {
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
			scanf("%d %s %s", &baseCalculadora, &entradaCalculo1, &entradaCalculo2);
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
						printf("O resultado é: %s\n", calculadoraHexaAdicao(entradaCalculo1, entradaCalculo2));
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
				printf(">>Felipe Sucupira	\n");
				//contador = 1, para sair do while true, já que 5 é o caso de saída
				contador++;
				break;
		}
	}
	return 0;
}

/*-------------------------------------------------
* Início das funções de calculadora
-------------------------------------------------*/

// calculadoraHexaAdicao: recebe duas strings de números hexadecimais com letras maiúsculas, soma os números e printa o resultado
char *calculadoraHexaAdicao(char *valor1, char *valor2) {
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

	return resultado;
}

// calculadoraHexaMulti: recebe duas strings de números hexadecimais com letras maiúsculas e printa o resultado
void calculadoraHexaMulti(char *valor1, char *valor2) {
	int algarismo1, algarismo2, numeroAtual;
	int resto = 0;
	
	char temp[strlen(valor1) + 2];
	char resultado[strlen(valor1) + strlen(valor2) + 3];
	
	for (int i = 0; i < strlen(valor2); i++) {
		algarismo2 = valorNumerico(valor2[strlen(valor2) - 1 - i]);

		for (int j = 0; j < strlen(valor1); j++) {
			algarismo1 = valorNumerico(valor1[strlen(valor1) - 1 - i]);

			numeroAtual = algarismo1 + algarismo2 + resto;
			resto = 0;
			if (numeroAtual > 15) {
				resto = numeroAtual / 15;
				numeroAtual -= resto * 16;
			}

			temp[strlen(resultado) - 1 - i] = valorChar(numeroAtual);
		}
	}
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
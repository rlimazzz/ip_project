#include <stdio.h>
#include <string.h>

// Início da declaração das funções

int hexadecimalBinario(char[]);

// Fim da declaração das funções

int main() {
	int entrada, baseConversor, baseCalculadora, converter, contador = 0, opcao, entradaCalculo1, entradaCalculo2, operacao;
	char numeroHexadecimal[20];
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
			
			printf(">>ENTRADA : BASE, PRIMEIRO NUMERO, SEGUNDO NUMERO\n"); // aqui tem que mudar o printf, assim parece que precisa da virgula no input
			
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
			printf(">>Qual o número que deseja converter e a base desse número? \n"); // aqui também se pá explicar melhor o input

			printf("--------------------------------------------\n");
			printf("          CONVERSOES SUPORTADAS\n");
			printf("--------------------------------------------\n\n");
			printf(">>1 - BINARIO\n");
			printf(">>2 - DECIMAL\n");
			printf(">>3 - HEXADECIMAL\n");
			printf(">>4 - OCTAL\n");
			printf(">>5 - FECHAR\n");
		
			printf("$");
			scanf("%d %d", &entrada, &baseConversor);
			printf("\n");
			
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

					printf(">>Digite o número utilizando as letras maiúsculas\n");
					printf("$");
					scanf("%s", &numeroHexadecimal);
					printf("\n");

					printf(">>O resultado da conversão é: %d\n", hexadecimalBinario(numeroHexadecimal));
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

// Início das funções de conversão

int hexadecimalBinario (char hexadecimal[]) {
	int resultado = 0;
	size_t tamanho = strlen(hexadecimal);

	return resultado;
}

// Fim das funções de conversão
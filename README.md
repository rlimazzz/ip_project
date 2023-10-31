# Conversor e calculadora de Bases Numericas
https://github.com/rlimazzz/ip_project

Esse é o mini projeto número 1 da disciplina de Introdução a Programação.

Nós fizemos um conversor de bases númericas capaz de converter entre números de base 2, 8, 10 e 16.
O conversor é baseado no método comum de conversão, em sucessivas divisões. Fizemos uma função para cada uma das 12 possíveis conversões.

Além disso, também fizemos uma calculadora que faz as quatro operações básicas com as bases 2, 8 e 16. Utilizamos as funções de conversão nas funções de calculadora.

## Organização
Apesar do código estar em um único arquivo, ele está bem organizado e seccionado por comentários.
No começo ficam declarações prévias das funções, depois a função main, onde foi feito o menu, e depois todas as outras funções.

## Especificações
A calculadora e o conversor funcionam apenas com números inteiros positivos.

## Testes
Fizemos casos de testes para as funções da calculadora. Como elas são baseadas nas funções de conversão, o funcionamento da calculadora garante o funcionamento do conversor.
Os testes se encontram nas funções testHexa, testBinario e testOctal. Se apertar 4 no menu, elas são chamadas.

## Desafio
Nós nos desafiamos a fazer a função de adição hexadecimal (calculadoraHexaAdicao) sem utilizar as funções de conversão.

### Integrandes
* Luis Renato - Calculadora Octal
* Ryan Gabryel - Menu
* Rafael Mattos - Conversor
* João Pedro - Calculadora Binário
* Felipe Sucupira - Calculadora Hexadecimal
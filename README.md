# Compiladores - Mércia Ferreira
Esta é a documentação da linguagem desenvolvida na disciplina de compiladores. 

## INDICARORES DE INÍCIO E FIM DO PROGRAMA 

```
M_INICIO
  m\Códio
  ....
  m\Código
M_FIM
```

## COMENTÁRIOS
Para comentar uma linha, adicione m\ no início.
```
Ex.: m\ Meu primeiro compilador.
```

## TIPOS E DECLARAÇÕES DE VARIÁVEIS
OBS:
1. Todas as declarações de variáveis são obrigatoriamente feitas DEPOIS do
indicador de INÍCIO. Se alguma variável for declarada antes do início vai
retornar erro.
2. As variáveis podem vir compostas de letras, números e operadores especiais
como: ‘-’, ‘_’.
```
Ex.: int var_1, var-2, var3.
```
- int: Aceita um número inteiro ou uma variável.
```
Ex.: int a
     int a, b, c
     int a = 10, b, c= 2
```
- real: Aceita um número real ou uma variável.
```
Ex.: real a
     real a = 10.2, b = 2.2
```
-string: Aceita texto/string.
```
Ex.: texto a = "Mércia"
     texto a, b = "Texto"
```
-vetores: Aceita declarações dos tipos reais, inteiro e texto
```
Ex.: int vetor[10]
     real vetor[10]
     texto vetor[10]
```
## ATRIBUIÇÃO DE VALORES
A atribuição de valores é dada pelo símbolo de igual: "=".
```
Ex.: a = 2
     b = 10
     c = a + b
```

## OPERAÇÕES DE ESCRITA E LEITURA
- Escrita
Para a operação de escrita utiliza-se o comando "escreva" acompanhado de strings, variáveis, operações aritméticas.
```
escreva ("Olá mundo")
escreva (a)
escreva (a+b)
escreva ("Escreva o primeiro valor", a)
```
- Leitura
Para efetuar a leitura de uma variável utiliza-se o comando "leia" acompanhado da variável.
```
int nota 
escreva ("Digite sua nota", "\n")
leia (nota)
leia (a)
``` 

## OPERADORES MATEMÁTICOS
São utilizados os símbolos de operadores matemáticos: Ex.: +, -, *,/.
```
Soma = a + b
Subtração = a - b
Multiplicação = a * b
Divisão = a / b
Exponenciação = a ^ b
Radiciação = sqrt(a)

Ex.: escreva (“soma:”)
escreva (a + b)

```
## ORDEM DE PRECEDÊNCIA
1. Parênteses. 
2. Exponenciação.
3. Multiplicação e divisão possui o mesmo grau de precedência.
4. Soma e subtração possui o mesmo grau de precedência.

```
exemplo = ((1+2)^(4*2)) 
```
Nesse exemplo será resolvido primeiro o que está entre os parênteses e só depois a exponenciação. 

## ESTRUTURAS CONDICIONAIS IF, IF ELSE E OPERADORER TERNARIO

- IF
``` 
if (media >= 7.0){
    escreva("Aluno aprovado.", "\n")
}
```
- IF ELSE
```
if (media >= 7.0){
    escreva("Aluno aprovado.", "\n")
}
else{
  escreva("Aluno reprovado")
}
``` 
- TERNÁRIO
``` 
escreva("Digite um numero")
leia(numero)
numero >= 0 ? numero++ : numero--;
escreva(numero)
```
##ESTRUTURAS DE REPETIÇÃO FOR, WHILE

- FOR
```
for i=0; i<=4; i++ {
    leia(i)
}
```

- WHILE
```
while (cont < n) {
    termo = (a + cont * razao)
    escreva( termo, " ")
    cont = cont + 1
}
```

## FUNÇÃO
```
void funcao(){
  m\ comandos
}
```

# EXEMPLOS 

Os exemplos a seguir são todos feitos a partir de questões do URI

- Exemplo 1 
Problema: Seleçao em Vetor I [URI - 1174]
```
M_INICIO 

int vetor[10]
int i

for i=0; i<=4; i++ {
    leia(vetor[i])
}

for i=0; i<=4; i++ {
    if(vetor[i]<=10){
        escreva(i, " = ", vetor[i])
    }
}

M_FIM
```

-Exemplo 2
Problema: Média 3 [URI - 1040]
```
M_INICIO

real n1, n2, n3, n4, media, exame

	leia(n1)
    leia(n2)
    leia(n3)
    leia(n4)
	media = (n1*2 + n2*3 + n3*4 + n4 * 1) / (2 + 3 + 4 + 1)
	escreva("Media: ", media, "\n")


	if (media >= 7.0){

		escreva("Aluno aprovado.", "\n")

	}
	else{

		if (media < 5.0){

			escreva("Aluno reprovado.", "\n")

		}
		else{

			escreva("Aluno em exame", "\n")
			leia(exame)
			escreva("Nota do exame: ", exame, "\n")
			media = (media + exame)/2
			if (media >= 5.0){

				escreva("Aluno aprovado.", "\n")

			}
			else{

				escreva("Aluno reprovado.\n")

			}

		escreva("Media final: ", media, "\n")

		}
	}

M_FIM
```

-Exemplo 3
Problema: Fatorial Simples [URI - 1153]
```
M_INICIO 
 
int n, i, resultado = 1

escreva ("Digite um valor:", "\n")

leia(n)

  for i = n; i > 0; i-- {

      resultado = resultado * i

  }
  escreva(resultado, "\n")
 
M_FIM
``` 


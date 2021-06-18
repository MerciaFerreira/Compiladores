/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Mercia_sint.y"

    //Codigo C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <math.h>
    #include <ctype.h>
    #include <stdbool.h>
    extern int yylineno;
    
    int yylex();
    void yyerror(const char *str)
    {
        fprintf(stderr,"Error: %s\n Linha: %d\n", str, yylineno);
    }

    #define name_size 50
    #define string_size 1000

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo real
    typedef struct vars {
		char name[name_size];
		float v;
        float *vet;
		struct vars * prox;
	} VARS;

    // Adicionar nova variavel do tipo real na lista
    VARS * ins(VARS *l, char n[]){
		VARS *new =(VARS*)malloc(sizeof(VARS));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}

    VARS * ins_a(VARS *l, char n[], int tamanho){
		VARS *new =(VARS*)malloc(sizeof(VARS));
		strcpy(new->name, n);
        new->vet = (float*)malloc(tamanho * sizeof(float));
		new->prox = l;
		return new;
	}
    
    // Busca uma variável do tipo real na lista de variáveis
	VARS *srch(VARS *l, char n[]){
		VARS *aux = l;
		while(aux != NULL){
			if(strcmp(n, aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}
    
    // Verificar se o valor dado é real
    bool is_real(char test[]){
        int i = 0;
        int ponto = 0;
        do{
            if(isdigit(test[i])!=0 || test[i] == '.'){
                if(test[i]=='.')
                    ponto = ponto + 1;
                if(ponto>1)
                    return false;
                i=i+1;
            }
            else
                return false;
        }while(test[i]!='\0');
        
        return true;
    }

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo string
    typedef struct VARST {
		char name[name_size];
		char v[string_size];
        char **vet;
		struct VARST * prox;
	} VARST;

    // Adicionar nova variável do tipo string na lista 
    VARST * inst(VARST *l, char n[]){
		VARST *new =(VARST*)malloc(sizeof(VARST));
		strcpy(new->name, n);
        strcpy(new->v, "");
		new->prox = l;
		return new;
	}

    VARST * inst_a(VARST *l, char n[], int tamanho){
		VARST *new =(VARST*)malloc(sizeof(VARST));
		strcpy(new->name, n);
        new->vet = (char**)malloc(tamanho * sizeof(char));
		new->prox = l;
		return new;
	}

    // Busca uma nova variável do tipo string na lista de variáveis
    VARST *srcht(VARST *l, char n[]){
		VARST *aux = l;
		while(aux != NULL){
			if(strcmp(n,aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}

    // Construção de uma struct para receber o nome e o valor para cada variavel do tipo inteiro
    typedef struct varsi {
		char name[name_size];
		int v;
        int *vet;
		struct varsi * prox;
	} VARSI;

    // Adicionar nova variavel inteiro na lista de variáveis inteiro
    VARSI * insi(VARSI *l, char n[]){
		VARSI *new =(VARSI*)malloc(sizeof(VARSI));
		strcpy(new->name, n);
		new->prox = l;
		return new;
	}

    // Insercao de inteiros no array
    VARSI * insi_a(VARSI *l, char n[], int tamanho){
		VARSI *new =(VARSI*)malloc(sizeof(VARSI));
		strcpy(new->name, n);
        new->vet = (int*)malloc(tamanho * sizeof(int));
		new->prox = l;
		return new;
	}

    // Busca uma variável inteiro na lista de variáveis inteiro
	VARSI *srchi(VARSI *l, char n[]){
		VARSI *aux = l;
		while(aux != NULL){
			if(strcmp(n, aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
		return aux;
	}

    // Verificar se o valor dado é inteiro
    bool is_int(char test[]){
        int i = 0;
        int ponto = 0;
        do{
            if(isdigit(test[i])!=0){
                i=i+1;
            }
            else
                return false;
        }while(test[i]!='\0');
        
        return true;
    }

	VARS *rvar = NULL;
    VARSI *ivar = NULL;
    VARST *tvar = NULL;

    /* O nodetype serve para indicar o tipo de nó que está na árvore. Isso serve para a função eval entender o que realizar naquele no */
    typedef struct ast { /*Estrutura de um nó*/
        int nodetype;
        struct ast *l; /*Esquerda*/
        struct ast *r; /*Direita*/
    }Ast; 

    typedef struct intval { /*Estrutura de uma variavel inteira*/
        int nodetype;
        int v;
    }Intval;

    typedef struct realval { /* Estrutura de uma variavel real */
        int nodetype;
        double v;
    }Realval;

    typedef struct textoval { /*Estrutura de uma variavel texto*/
        int nodetype;
        char v[string_size];
    }Textoval;

    typedef struct varval { /*Estrutura de um nome de variável, nesse exemplo uma variável é um número no vetor var[26]*/
        int nodetype;
        char var[name_size];
        int size;
        Ast * pos; /* posicao no vetor */
    }Varval;

    typedef struct flow { /*Estrutura de um desvio (if/else/while)*/
	    int nodetype;
	    Ast *cond;		/*condição*/
	    Ast *tl;		/*then, ou seja, verdade*/
	    Ast *el;		/*else*/
    }Flow;

    /*Estrutura para um nó de atribuição. Para atrubuir o valor de v em s*/
    typedef struct symasgn { 
        int nodetype;
        char s[name_size];
        Ast *v;
        Ast *n;
        Ast * pos; /* posicao para atribuir um valor novo nela no array */
    }Symasgn;

    typedef struct function {
        int nodetype;
        int type;
		char name[name_size];
        Ast *v;
        struct function * prox;
	} Function;

    /*Função para criar um nó*/
    Ast * newast(int nodetype, Ast *l, Ast *r){ 

	    Ast *a = (Ast*) malloc(sizeof(Ast));
	    if(!a) {
		    printf("out of space");
		    exit(0);
	}
	    a->nodetype = nodetype;
	    a->l = l;
	    a->r = r;
	    return a;
    }

    /*Estrutura de um fluxo para o FOR*/
    typedef struct flowfor{ 
        int nodetype;
        Ast* v1;
        Ast* v2;
        Ast* v3;
    }Flowfor;

    /*Função que cria um nó de FOR*/
    Ast * newflowfor(int nodetype, Ast *b1, Ast *b2, Ast *b3, Ast *tl, Ast *el){ 
        Flow *a = (Flow*)malloc(sizeof(Flow));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        Flowfor *b = (Flowfor*)malloc(sizeof(Flowfor));
        if(!b) {
            printf("out of space");
            exit(0);
        }
        b->nodetype = 'F';
        b->v1 = b1;
        b->v2 = b2;
        b->v3 = b3;
        a->nodetype = nodetype;
        a->cond = (Ast*)b;
        a->tl = tl;
        a->el = el;
        return (Ast *)a;
    }

    /* Função de que cria um número inteiro (folha)*/
    Ast * newint(int d) {	
        Intval *a = (Intval*) malloc(sizeof(Intval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'k';
        a->v = d;
        return (Ast*)a;
    }


    /*Função de que cria um número real (folha)*/
    Ast * newreal(double d) {		
        Realval *a = (Realval*) malloc(sizeof(Realval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'K';
        a->v = d;
        return (Ast*)a;
    }

    /*Função de que cria um novo texto (folha)*/
    Ast * newtexto(char d[]) {			
        Textoval *a = (Textoval*) malloc(sizeof(Textoval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'm';
        strcpy(a->v, d);
        return (Ast*)a;
    }

    /*Função de que cria uma nova variável array*/
    Ast * newarray(int nodetype, char nome[], int tam) {
        Varval *a = (Varval*) malloc(sizeof(Varval) * tam);
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = nodetype;
        strcpy(a->var,nome);
        a->size = tam;
        return (Ast*)a;
    }

    /*Função que cria um nó de if/else/while*/
    Ast * newflow(int nodetype, Ast *cond, Ast *tl, Ast *el){ 
        Flow *a = (Flow*)malloc(sizeof(Flow));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = nodetype;
        a->cond = cond;
        a->tl = tl;
        a->el = el;
        return (Ast *)a;
    }

    /*Função que cria um nó para testes lógicos*/
    Ast * newcmp(int cmptype, Ast *l, Ast *r){
        Ast *a = (Ast*)malloc(sizeof(Ast));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = '0' + cmptype; /*Para pegar o tipe de teste, definido no arquivo.l e utilizar na função eval()*/
        a->l = l;
        a->r = r;
        return a;
    }

    /* Funcão que cria um nó para a variavel do tipo inteiro ou real ou texto e atribui o valor */
    Ast * newvar(int t, char s[], Ast *v, Ast *n){
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = t; /*tipo i, r ou t, conforme arquivo .l*/
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        a->n = n; /*proxima declaração*/
        return (Ast *)a;
    }

    /*Função para um nó de atribuição*/
    Ast * newasgn(char s[], Ast *v) { 
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = '=';
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        return (Ast *)a;
    }

     /*Função para um nó de atribuição em um array*/
    Ast * newasgn_a(char s[], Ast *v, Ast * pos) { 
        Symasgn *a = (Symasgn*)malloc(sizeof(Symasgn));
        if(!a) {
            printf("out of space");
        exit(0);
        }
        a->nodetype = 'D';
        strcpy(a->s, s); /*Símbolo/variável*/
        a->v = v; /*Valor*/
        a->pos = pos;
        return (Ast *)a;
    }

    /*Função que recupera o nome/referência de uma variável*/
    Ast * newValorVal(char s[]) { 
        Varval *a = (Varval*) malloc(sizeof(Varval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'N';
        strcpy(a->var, s);
        return (Ast*)a;
        
    }

    /*Função que recupera o nome/referência de um array */
    Ast * newValorVal_a(char s[], Ast * i) { 
        Varval *a = (Varval*) malloc(sizeof(Varval));
        if(!a) {
            printf("out of space");
            exit(0);
        }
        a->nodetype = 'E';
        strcpy(a->var, s);
        a->pos = i;
        return (Ast*)a;
        
    }

    /*Função para criar um nó para salvar a funcao na lista de funcoes*/
    Ast * newfunction(int type, char n[], Ast *fun){
        Function *aux = (Function*)malloc(sizeof(Function));
        if(!aux){
            printf("out of space in newfuntion()");
            exit(1);
        }
        aux->nodetype = 'f';
        aux->type = type;
        strcpy(aux->name, n);
        aux->v = fun;
        return (Ast*)aux;
    }

    /* Verificar se a variavel existe na lista de variaveis */
    bool varexiste(char v[]) {
        VARS* xr = srch(rvar, v);
        VARSI* xi = srchi(ivar, v);
        VARST* xt = srcht(tvar, v);

    if(!xr && !xi && !xt) 
        return false; // se tudo NULL, variavel nao existe
    else
        return true;  // se tudo for TRUE, variavel existe
    }

    Function * listFunction = NULL;

    // Busca uma função por nome na lista de funções
    Function *srchfunction(Function *l, char n[]){
		Function *aux = l;
        //printf("open srchfuntion\n");
		while(aux != NULL){
			if(strcmp(n,aux->name)==0){
				return aux;
			}
			aux = aux->prox;
		}
        //printf("function NULL\n");
		return aux;
	}

    /*Função que executa operações a partir de um nó*/
    double eval(Ast *a) { 
        double v;
        char v1[50];
        int pos;
        Function *auxFunction; //armazena o resultado da busca na lista de funções

        if(!a) {
            printf("internal error, null eval\n");
            return 0.0;
        }
        //printf("nodetype: %c\n", a->nodetype);
        switch(a->nodetype) {
            case 'k': v = ((Intval *)a)->v; break; 	/*Recupera um número inteiro*/
            case 'K': v = ((Realval *)a)->v; break; 	/*Recupera um número real*/
            case 'm': v = atof(((Textoval *)a)->v); break; 	/*Recupera um número real dentro de string*/
            case 'N':; /*  Verificar se foi realizado a declaracao da variavel corretamente */
                VARS * aux = (VARS*)malloc(sizeof(VARS));
                aux = srch(rvar, ((Varval*)a)->var);
                if (!aux){
                    VARSI * aux2 = (VARSI*)malloc(sizeof(VARSI));
                    aux2 = srchi(ivar, ((Varval*)a)->var);
                    if (!aux2){
                        VARST * aux3 = (VARST*)malloc(sizeof(VARST));
                        if(!aux3){
                                printf("out of space");
                                exit(0);
                            }
                        aux3 = srcht(tvar, ((Varval*)a)->var);
                        if (!aux3){
                            printf ("Erro 'sem valor'. Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                            v = 0.0;
                        }
                        else{
                            v = atof(aux3->v);
                        }
                    }
                    else{
                        v = (double)aux2->v;
                    }
                }
                else{
                    v = aux->v;
                }
                break;
            case '+': v = eval(a->l) + eval(a->r); break;	/*Operações "árv esq   +   árv dir"*/
            case '-': v = eval(a->l) - eval(a->r); break;	/*Operações de subtração */
            case '*': v = eval(a->l) * eval(a->r); break;	/*Operações de multiplicação */
            case '/': v = eval(a->l) / eval(a->r); break; /*Operação de divisão */
            case 'R': v = sqrt(eval(a->l)); break;				/*Operações RAIZ*/
            case 'M': v = -eval(a->l); break;				/*Operações, número negativo*/
            case '|': v = fabs(eval(a->l)); break;          /*Operações de módulo*/

            case '1': v = (eval(a->l) > eval(a->r))? 1 : 0; break;	/* Operações lógicas. "árv esq   >   árv dir"  Se verdade 1, falso 0 */
            case '2': v = (eval(a->l) < eval(a->r))? 1 : 0; break;
            case '3': v = (eval(a->l) != eval(a->r))? 1 : 0; break;
            case '4': v = (eval(a->l) == eval(a->r))? 1 : 0; break;
            case '5': v = (eval(a->l) >= eval(a->r))? 1 : 0; break;
            case '6': v = (eval(a->l) <= eval(a->r))? 1 : 0; break;
            case '7': v = (eval(a->l) || eval(a->r))? 1 : 0; break;
            case '8': v = (eval(a->l) && eval(a->r))? 1 : 0; break;
            case '?': (eval(((Flow *)a)->cond)) != 0 ? eval(((Flow *)a)->tl) : eval(((Flow *)a)->el); break; /* Case para operador iterator */
            
            /* Atribuicao */
            case '=':;
                v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                
                VARS * x = (VARS*)malloc(sizeof(VARS));
                if(!x) {
                    printf("out of space");
                    exit(0);
                }
                x = srch(rvar, ((Symasgn *)a)->s);
                if(!x){
                    VARSI * xi = (VARSI*)malloc(sizeof(VARSI));
                    if(!xi) {
                        printf("out of space");
                        exit(0);
                    }
                    xi = srchi(ivar, ((Symasgn *)a)->s);
                    if(!xi){
                        printf("Erro 'atribuir valor'. Var '%s' nao declarada.\n", ((Symasgn *)a)->s);
                    } else
                        xi->v = (int)v; /*Atribui à variável*/
                } else {
                    x->v = v;   /*Atribui à variável*/
                }
                break;

            /* caso if ou if/else */
            case 'I': 
                if (eval(((Flow *)a)->cond) != 0) {	/*executa a condição / teste*/
                    if (((Flow *)a)->tl)		/*Se existir árvore*/
                        v = eval(((Flow *)a)->tl); /*Verdade*/
                    else
                        v = 0.0;
                } else {
                    if( ((Flow *)a)->el) {
                        v = eval(((Flow *)a)->el); /*Falso*/
                    } else
                        v = 0.0;
                    }
                break;

            /* caso while */
            case 'W':
                v = 0.0;
                if( ((Flow *)a)->tl) {
                    while( eval(((Flow *)a)->cond) != 0){
                        v = eval(((Flow *)a)->tl);
                        }
                }
            break;

            // leitura das variaveis: int, real e texto
            case 'c':; 
                //v = eval(((Symasgn *)a)->v); /*Recupera o valor*/
                VARS * xcr = (VARS*)malloc(sizeof(VARS));
                if(!xcr) {
                    printf("out of space");
                    exit(0);
                }
                xcr = srch(rvar, ((Varval *)a->l)->var);
                if(xcr){
                    scanf("%f", &xcr->v);
                } else {
                    VARSI * xci = (VARSI*)malloc(sizeof(VARSI));
                    if(!xci) {
                        printf("out of space");
                        exit(0);
                    }
                    xci = srchi(ivar, ((Varval *)a->l)->var);
                    if(xci){
                        scanf("%d", &xci->v);
                    } else {
                        VARST * xct = (VARST*)malloc(sizeof(VARST));
                        if(!xct) {
                            printf("out of space");
                            exit(0);
                        }
                        xct = srcht(tvar, ((Varval *)a->l)->var);
                        if(xct){
                            scanf("%s", &xct->v);
                        } else {
                            printf("Variavel inválida!\n");
                        }
                    }
                }
                break;
            
            case 'L': eval(a->l); v = eval(a->r); break; /*Lista de operções em um bloco IF/ELSE/WHILE. Assim o analisador não se perde entre os blocos*/
            case 'n': 
            { /* printar os tipos de variaveis corretamente na saída */
                VARS * auxn = (VARS*)malloc(sizeof(VARS));
                auxn = srch(rvar, ((Varval*)a)->var);
                if (!auxn){
                    VARSI * auxn2 = srchi(ivar, ((Varval*)a)->var);
                    if (!auxn2){
                        VARST * auxn3 = srcht(tvar, ((Varval*)a)->var);
                        if (!auxn3){
                            printf ("359 - Variavel '%s' nao foi declarada.\n", ((Varval*)a)->var);
                            v = 0.0;
                        }
                        else{
                            Ast * auxnt = (Ast*)malloc(sizeof(Ast));
                            if(!auxnt){
                                printf("out of space");
                                exit(0);
                            }
                            printf("%s", auxn3->v);
                            v = atof(auxn3->v);
                        }
                    }
                    else{
                        Ast * auxni = (Ast*)malloc(sizeof(Ast));
                        if(!auxni){
                            printf("out of space");
                            exit(0);
                        }
                        printf("%d", auxn2->v);
                        v = (double)auxn2->v;
                    }
                }
                else{
                    Ast * auxnr = (Ast*)malloc(sizeof(Ast));
                    if(!auxnr){
                        printf("out of space");
                        exit(0);
                    }
                    printf("%.2f", auxn->v);
                    v = auxn->v;
                }
                break;
            }
            /* O case P é um comando de print geral, mas ele não trabalha pesado,
            *  o case 'n' ajuda quando precisar imprimir variaveis
            */
            case 'P': 
                //printf("P1: %c\nP2: %c\n", a->nodetype, a->l->nodetype);
                if(a->l==NULL)
                    break;
                /* printf("node %c\n", a->l->nodetype);*/
                if (a->l->nodetype == 'E') {
                    a->l->nodetype = 'H';
                    v = eval(a->l);
                }
                else if(a->l->nodetype == 'N'){
                    a->l->nodetype = 'n';
                    v = eval(a->l);
                    //printf("\nnodetype 'N'\n");
                } else {
                    v = eval(a->l);
                    if(a->l->nodetype != 'n' && a->l->nodetype != 'k' && a->l->nodetype != 'K' && a->l->nodetype != 'm' && a->l->nodetype != 'H')
                        printf("%.2f", v);
                }
                if(((Intval*)a->l)->nodetype == 'k') {
                    printf ("%d", ((Intval*)a->l)->v);		/*Recupera um valor inteiro*/
                }
                else if(((Realval*)a->l)->nodetype == 'K') {
                    printf ("%.2f", ((Realval*)a->l)->v);		/*Recupera um valor real*/
                }
                else if(((Textoval*)a->l)->nodetype == 'm') {
                    if(strcmp(((Textoval*)a->l)->v, "\\n")==0)
                        printf("\n");
                    else
                        printf ("%s", ((Textoval*)a->l)->v);		/*Recupera um valor texto*/
                }
                if(a->r==NULL){
                    /* printf("\n");*/ 
                    /* printf("Quebra linha entra variaveis"); */
                }else{
                    v = eval(a->r);
                    /* printf("\n");*/
                }
                break; 
            /* caso para a opcao FOR */
            case 'F':
                v = 0.0;
                if( ((Flow *)a)->tl ) {
                    for(eval(((Flowfor*)((Flow *)a)->cond)->v1); 
                        eval(((Flowfor*)((Flow *)a)->cond)->v2); 
                        eval(((Flowfor*)((Flow *)a)->cond)->v3)
                        ){
                            v =  eval(((Flow *)a)->tl);
                    }
                }
                break;
            // declaracao da variavel inteira
            case 'i':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    ivar = insi(ivar, ((Symasgn *)a)->s);
                    VARSI * xi = (VARSI*)malloc(sizeof(VARSI));
                    if(!xi) {
                        printf("out of space");
                        exit(0);
                    }
                    xi = srchi(ivar, ((Symasgn *)a)->s);
                    if(((Symasgn *)a)->v)
                        xi->v = (int)eval(((Symasgn *)a)->v); /*Atribui à variável*/
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            // declaracao da variavel real
            case 'r':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    rvar = ins(rvar, ((Symasgn *)a)->s);
                    VARS * xr = (VARS*)malloc(sizeof(VARS));
                    if(!xr) {
                        printf("out of space");
                        exit(0);
                    }
                    xr = srch(rvar, ((Symasgn *)a)->s);
                    if(((Symasgn *)a)->v)
                        xr->v = eval(((Symasgn *)a)->v);
                }else
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                break;
            // declara a variavel texto
            case 't':;
                if(((Symasgn *)a)->n)
                    eval(((Symasgn *)a)->n);

                if(!varexiste(((Symasgn *)a)->s)){
                    tvar = inst(tvar, ((Symasgn *)a)->s);
                    VARST * xt = (VARST*)malloc(sizeof(VARST));
                    if(!xt) {
                        printf("out of space");
                        exit(0);
                    }
                    xt = srcht(tvar, ((Symasgn *)a)->s);
                    if((((Symasgn *)a)->v))
                        strcpy(xt->v, ((Textoval*)((Symasgn*)a)->v)->v);
                }else
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                break;
            /* Case referente a execucao da funcao */    
            case 'a':;
                auxFunction = srchfunction(listFunction, ((Textoval*)a->l)->v);
                if(auxFunction != NULL) {
                   eval(auxFunction->v);
                }
                else {
                    printf("\nErro (case 'a'): chamada de funcao errada\n");
                }
                break;
            /* Case para adicionar uma funcao em uma lista de funcoes */
            case 'f':;
                if(srchfunction(listFunction, ((Function*)a)->name) == NULL) {
                    ((Function*)a)->prox = listFunction; //faz o elemento atual apontar o inicio da lista
                    listFunction = (Function*)a; // faz o elemento atual ser o inicio da lista
                }else{
                    printf("\nErro (case 'f'): reescrita de funcao nao permitada.\n");
                    printf("Function %s\n", ((Function*)a)->name);
                }
                break;
            case 'z':;
                printf("Fim do programa\n");
                free(ivar);
                ivar = NULL;
                free(rvar);
                rvar = NULL;
                free(tvar);
                tvar = NULL;
                exit(0);
                break;
            case 'A':; //inserir uma array de inteiros
                if(!varexiste(((Varval*)a)->var)){
                    ivar = insi_a(ivar,((Varval*)a)->var,((Varval*)a)->size);
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            case 'B':; //inserir uma array de real
                if(!varexiste(((Varval*)a)->var)){
                    rvar  = ins_a(rvar,((Varval*)a)->var,((Varval*)a)->size);
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            case 'C':; //inserir uma array de texto
                if(!varexiste(((Varval*)a)->var)){
                    tvar = inst_a(tvar,((Varval*)a)->var,((Varval*)a)->size);
                }else{
                    printf("Erro de redeclaracao: variavel '%s' ja existe.\n",((Symasgn *)a)->s);
                }
                break;
            case 'D':; //atribuir em um array 
                v = eval(((Symasgn *)a)->v);  //valor que sera atriuido no array
                pos = (int)eval(((Symasgn *)a)->pos);
                VARS * vx = srch(rvar, ((Symasgn *)a)->s);
                VARSI * vxi = srchi(ivar, ((Symasgn *)a)->s);
                VARST * vxt = srcht(tvar, ((Symasgn *)a)->s);

                if(vx != NULL){
                    vx->vet[pos] = v; /*Atribui à variável*/
                } else if (vxi != NULL) {
                    vxi->vet[pos] = (int)v; /*Atribui à variável*/
                } else if (vxt != NULL) {
                    VARST * auxVxt = srcht(tvar, ((Textoval*)((Symasgn*)a)->v)->v);
                    if (auxVxt != NULL) {
                        vxt->vet[pos] = auxVxt->v;
                    }
                    else {
                        vxt->vet[pos] = ((Textoval*)((Symasgn*)a)->v)->v; /*Atribui à variável*/
                    }
                } else {
                    printf("Erro 'atribuir valor'. Var '%s' nao declarada.\n", ((Symasgn *)a)->s);
                }
                break;
            case 'E':; /*  Verificar se foi realizado a declaracao da variavel corretamente */
                pos = (int)eval(((Varval *)a)->pos);
                VARS * evx = srch(rvar, ((Varval *)a)->var);
                VARSI * evxi = srchi(ivar, ((Varval *)a)->var);
                VARST * evxt = srcht(tvar, ((Varval *)a)->var);

                if(evx != NULL){
                    v = evx->vet[pos];
                } else if (evxi != NULL) {
                    v = evxi->vet[pos];
                } else if (evxt != NULL) {
                    v = atof(evxt->vet[pos]);
                }

                break;

            // leitura das variaveis: int, real e texto de um array array
            case 'G':; 
                VARSI * posvxi = srchi(ivar, ((Varval *)a->r)->var);
                if(posvxi != NULL){
                   pos = posvxi->v;
                }
    
                VARS * apvx = srch(rvar, ((Varval *)a->l)->var);
                VARSI * apvxi = srchi(ivar, ((Varval *)a->l)->var);
                VARST * apvxt = srcht(tvar, ((Varval *)a->l)->var);

                if(apvx != NULL){
                    scanf("%f", &apvx->vet[pos]); 
                } else if (apvxi != NULL) {
                    scanf("%d", &apvxi->vet[pos]);
                } else if (apvxt != NULL) {
                    scanf("%s", &apvxt->vet[pos]);
                }
                break;
            case 'H':; /*  imprimir array */
                pos = (int)eval(((Varval *)a)->pos);
                VARS * pvx = srch(rvar, ((Varval *)a)->var);
                VARSI * pvxi = srchi(ivar, ((Varval *)a)->var);
                VARST * pvxt = srcht(tvar, ((Varval *)a)->var);

                if(pvx != NULL){
                    v = pvx->vet[pos];
                    printf("%.2f\n", pvx->vet[pos]); 
                } else if (pvxi != NULL) {
                    v = pvxi->vet[pos];
                    printf("%d\n", pvxi->vet[pos]);
                } else if (pvxt != NULL) {
                    v = 0.0;
                    printf("%s\n", pvxt->vet[pos]);
                } 

                break;

            default: printf("internal error: bad node %c\n", a->nodetype);
        }
        return v;
    }


#line 961 "Mercia_sint.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INICIO = 258,                  /* INICIO  */
    FIM = 259,                     /* FIM  */
    REAL = 260,                    /* REAL  */
    INTEIRO = 261,                 /* INTEIRO  */
    T_INT = 262,                   /* T_INT  */
    T_REAL = 263,                  /* T_REAL  */
    T_TEXTO = 264,                 /* T_TEXTO  */
    VOID = 265,                    /* VOID  */
    VARIAVEL = 266,                /* VARIAVEL  */
    STRING = 267,                  /* STRING  */
    PLUS = 268,                    /* PLUS  */
    LESS = 269,                    /* LESS  */
    COMENTARIO = 270,              /* COMENTARIO  */
    FUNCAO = 271,                  /* FUNCAO  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    WHILE = 274,                   /* WHILE  */
    FOR = 275,                     /* FOR  */
    SQRT = 276,                    /* SQRT  */
    LEITURA = 277,                 /* LEITURA  */
    ESCRITA = 278,                 /* ESCRITA  */
    CMP = 279,                     /* CMP  */
    IFX = 280,                     /* IFX  */
    NEG = 281,                     /* NEG  */
    FUN = 282,                     /* FUN  */
    VET = 283                      /* VET  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 891 "Mercia_sint.y"

    char texto[50];
    double real;
    int inteiro;
    int fn;
    Ast *a;

#line 1044 "Mercia_sint.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INICIO = 3,                     /* INICIO  */
  YYSYMBOL_FIM = 4,                        /* FIM  */
  YYSYMBOL_REAL = 5,                       /* REAL  */
  YYSYMBOL_INTEIRO = 6,                    /* INTEIRO  */
  YYSYMBOL_T_INT = 7,                      /* T_INT  */
  YYSYMBOL_T_REAL = 8,                     /* T_REAL  */
  YYSYMBOL_T_TEXTO = 9,                    /* T_TEXTO  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_VARIAVEL = 11,                  /* VARIAVEL  */
  YYSYMBOL_STRING = 12,                    /* STRING  */
  YYSYMBOL_PLUS = 13,                      /* PLUS  */
  YYSYMBOL_LESS = 14,                      /* LESS  */
  YYSYMBOL_COMENTARIO = 15,                /* COMENTARIO  */
  YYSYMBOL_FUNCAO = 16,                    /* FUNCAO  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_SQRT = 21,                      /* SQRT  */
  YYSYMBOL_LEITURA = 22,                   /* LEITURA  */
  YYSYMBOL_ESCRITA = 23,                   /* ESCRITA  */
  YYSYMBOL_CMP = 24,                       /* CMP  */
  YYSYMBOL_25_ = 25,                       /* '='  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '*'  */
  YYSYMBOL_29_ = 29,                       /* '/'  */
  YYSYMBOL_30_ = 30,                       /* '^'  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_IFX = 33,                       /* IFX  */
  YYSYMBOL_NEG = 34,                       /* NEG  */
  YYSYMBOL_FUN = 35,                       /* FUN  */
  YYSYMBOL_VET = 36,                       /* VET  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '?'  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_begin = 46,                     /* begin  */
  YYSYMBOL_prog = 47,                      /* prog  */
  YYSYMBOL_cmds = 48,                      /* cmds  */
  YYSYMBOL_ternario = 49,                  /* ternario  */
  YYSYMBOL_var = 50,                       /* var  */
  YYSYMBOL_var1 = 51,                      /* var1  */
  YYSYMBOL_funcao = 52,                    /* funcao  */
  YYSYMBOL_declmult = 53,                  /* declmult  */
  YYSYMBOL_declmult2 = 54,                 /* declmult2  */
  YYSYMBOL_escreva = 55,                   /* escreva  */
  YYSYMBOL_leitura = 56,                   /* leitura  */
  YYSYMBOL_list = 57,                      /* list  */
  YYSYMBOL_exp = 58,                       /* exp  */
  YYSYMBOL_num = 59                        /* num  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    31,    28,    26,    44,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    41,
       2,    25,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      33,    34,    35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   928,   928,   931,   932,   936,   937,   938,   939,   940,
     941,   942,   943,   944,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   956,   959,   962,   963,   964,   965,   968,
     969,   973,   974,   975,   976,   977,   978,   979,   980,   984,
     985,   986,   987,   988,   991,   992,   993,   994,   997,   998,
     999,  1003,  1004,  1007,  1008,  1009,  1010,  1011,  1012,  1013,
    1014,  1015,  1016,  1019,  1020,  1021,  1022,  1023
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INICIO", "FIM",
  "REAL", "INTEIRO", "T_INT", "T_REAL", "T_TEXTO", "VOID", "VARIAVEL",
  "STRING", "PLUS", "LESS", "COMENTARIO", "FUNCAO", "IF", "ELSE", "WHILE",
  "FOR", "SQRT", "LEITURA", "ESCRITA", "CMP", "'='", "'+'", "'-'", "'*'",
  "'/'", "'^'", "')'", "'('", "IFX", "NEG", "FUN", "VET", "'{'", "'}'",
  "'['", "']'", "';'", "'?'", "':'", "','", "$accept", "begin", "prog",
  "cmds", "ternario", "var", "var1", "funcao", "declmult", "declmult2",
  "escreva", "leitura", "list", "exp", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    61,    43,    45,    42,    47,
      94,    41,    40,   280,   281,   282,   283,   123,   125,    91,
      93,    59,    63,    58,    44
};
#endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,   285,    25,  -123,  -123,    37,    45,    49,    51,    -5,
    -123,    38,    41,    70,    55,    56,    57,   292,   292,   257,
    -123,  -123,  -123,    39,    53,   124,  -123,  -123,   -18,    -8,
       8,    61,  -123,  -123,    63,    67,     0,   292,   292,    75,
      64,   292,    91,    80,    69,  -123,   323,  -123,  -123,    95,
     100,   292,   292,   292,   292,   292,   292,   316,   292,   107,
     292,   115,   110,   117,    94,  -123,   195,  -123,    93,    97,
     331,   339,   292,   292,   347,    96,   103,    98,   114,   -14,
      18,  -123,   113,   121,   229,    50,    50,   119,   119,   119,
     143,   127,   195,   195,   132,   195,   138,  -123,   139,   130,
     155,   158,   147,   163,   195,   161,  -123,    66,  -123,    80,
    -123,    80,   164,   166,   292,   128,  -123,  -123,   292,   316,
    -123,  -123,  -123,   285,   304,   292,   285,   285,   285,   172,
     173,  -123,  -123,  -123,  -123,   195,  -123,   195,   160,  -123,
      44,  -123,   195,   195,   109,   154,   177,  -123,  -123,  -123,
    -123,  -123,   198,  -123,   285,   180,   188,   285,  -123,   222,
    -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    64,    63,     0,     0,     0,     0,    65,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,    16,    20,    21,    22,     0,    62,     1,    33,    35,
      42,     0,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    60,     0,     2,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    30,     0,     0,
       0,     0,     0,     0,     0,    48,     0,    46,     0,    44,
       0,    58,    31,    39,    61,    53,    54,    55,    56,    59,
      65,     0,    28,    34,     0,    36,     0,    41,     0,     0,
      66,    67,     0,     0,    24,     0,    57,     0,    14,     0,
      13,     0,     0,     0,     0,     0,    26,    27,     0,     0,
      37,    38,    43,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    45,    66,    67,    32,    40,    25,     0,    51,
       0,    12,    10,    11,     0,     0,     0,    49,    50,    23,
      29,    52,     5,     7,     0,     0,     0,     0,    15,     0,
       6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -123,  -123,  -123,    -1,  -123,  -123,    99,  -123,  -123,  -123,
     -65,  -123,  -122,   -15,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    19,   139,    21,    40,    91,    22,    23,    24,
      78,    76,   140,    25,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,     1,    45,    46,   144,   145,    68,    58,    32,    33,
      51,    69,    52,    53,    54,    55,    56,    60,    48,    66,
      34,    59,    70,    71,   112,    27,    74,    35,    79,   113,
     111,    61,   156,    62,    36,   159,    84,    85,    86,    87,
      88,    89,    92,    93,   131,    95,   132,    63,    28,     3,
       4,     5,     6,     7,     8,     9,    29,   104,   105,    10,
      30,    11,    31,    12,    13,    14,    15,    16,     3,     4,
      37,    17,   129,    38,    44,    65,    18,   130,    54,    55,
      56,    39,   150,    49,    14,     3,     4,    41,    42,    43,
      17,    44,    77,    64,    79,    18,    79,    50,    67,   135,
      72,    14,    75,   137,    92,    73,    82,    17,    80,   142,
     143,    83,    18,    94,     3,     4,     5,     6,     7,     8,
       9,    96,    97,    98,    10,    99,    11,   146,    12,    13,
      14,    15,    16,   100,   108,   107,    17,   101,   114,   151,
     136,    18,   109,   151,   151,   110,   115,   152,    51,    56,
      52,    53,    54,    55,    56,   151,   116,   117,   151,     3,
       4,     5,     6,     7,     8,     9,    57,   123,   118,    10,
     119,    11,   120,    12,    13,    14,    15,    16,   121,   122,
     124,    17,    80,   125,   126,    51,    18,    52,    53,    54,
      55,    56,   153,     3,     4,     5,     6,     7,     8,     9,
     127,   149,   128,    10,   133,    11,   134,    12,    13,    14,
      15,    16,   147,   148,   154,    17,   155,   157,   138,    51,
      18,    52,    53,    54,    55,    56,   158,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,    10,     0,    11,
       0,    12,    13,    14,    15,    16,     0,     0,     0,    17,
       0,     0,     0,     0,    18,    52,    53,    54,    55,    56,
     160,    47,     3,     4,     5,     6,     7,     8,     9,     0,
       0,     0,    10,     0,    11,     0,    12,    13,    14,    15,
      16,     0,     0,     0,    17,     0,     0,     0,     0,    18,
       3,     4,     5,     6,     7,     8,     9,     3,     4,     0,
      10,     0,    11,    44,    12,    13,    14,    15,    16,     3,
       4,     0,    17,    14,     0,    44,   141,    18,     0,    17,
       0,     3,     4,     0,    18,    14,     0,    90,     0,     0,
       0,    17,     0,     0,     0,     0,    18,    14,     0,     0,
       0,     0,     0,    17,     0,     0,     0,    51,    18,    52,
      53,    54,    55,    56,    81,    51,     0,    52,    53,    54,
      55,    56,   102,    51,     0,    52,    53,    54,    55,    56,
     103,    51,     0,    52,    53,    54,    55,    56,   106
};

static const yytype_int16 yycheck[] =
{
       1,     3,    17,    18,   126,   127,     6,    25,    13,    14,
      24,    11,    26,    27,    28,    29,    30,    25,    19,    34,
      25,    39,    37,    38,     6,     0,    41,    32,    43,    11,
      44,    39,   154,    25,    39,   157,    51,    52,    53,    54,
      55,    56,    57,    58,   109,    60,   111,    39,    11,     5,
       6,     7,     8,     9,    10,    11,    11,    72,    73,    15,
      11,    17,    11,    19,    20,    21,    22,    23,     5,     6,
      32,    27,     6,    32,    11,    12,    32,    11,    28,    29,
      30,    11,    38,    44,    21,     5,     6,    32,    32,    32,
      27,    11,    12,    32,   109,    32,   111,    44,    31,   114,
      25,    21,    11,   118,   119,    41,    11,    27,    39,   124,
     125,    11,    32,     6,     5,     6,     7,     8,     9,    10,
      11,     6,    12,     6,    15,    31,    17,   128,    19,    20,
      21,    22,    23,    40,    31,    39,    27,    40,    25,   140,
      12,    32,    44,   144,   145,    31,    25,    38,    24,    30,
      26,    27,    28,    29,    30,   156,    13,    14,   159,     5,
       6,     7,     8,     9,    10,    11,    42,    37,    25,    15,
      43,    17,    40,    19,    20,    21,    22,    23,    40,    40,
      25,    27,    39,    25,    37,    24,    32,    26,    27,    28,
      29,    30,    38,     5,     6,     7,     8,     9,    10,    11,
      37,    41,    41,    15,    40,    17,    40,    19,    20,    21,
      22,    23,    40,    40,    37,    27,    18,    37,   119,    24,
      32,    26,    27,    28,    29,    30,    38,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    -1,    17,
      -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    32,    26,    27,    28,    29,    30,
      38,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
       5,     6,     7,     8,     9,    10,    11,     5,     6,    -1,
      15,    -1,    17,    11,    19,    20,    21,    22,    23,     5,
       6,    -1,    27,    21,    -1,    11,    12,    32,    -1,    27,
      -1,     5,     6,    -1,    32,    21,    -1,    11,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    32,    21,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    24,    32,    26,
      27,    28,    29,    30,    31,    24,    -1,    26,    27,    28,
      29,    30,    31,    24,    -1,    26,    27,    28,    29,    30,
      31,    24,    -1,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    46,     5,     6,     7,     8,     9,    10,    11,
      15,    17,    19,    20,    21,    22,    23,    27,    32,    47,
      48,    49,    52,    53,    54,    58,    59,     0,    11,    11,
      11,    11,    13,    14,    25,    32,    39,    32,    32,    11,
      50,    32,    32,    32,    11,    58,    58,     4,    48,    44,
      44,    24,    26,    27,    28,    29,    30,    42,    25,    39,
      25,    39,    25,    39,    32,    12,    58,    31,     6,    11,
      58,    58,    25,    41,    58,    11,    56,    12,    55,    58,
      39,    31,    11,    11,    58,    58,    58,    58,    58,    58,
      11,    51,    58,    58,     6,    58,     6,    12,     6,    31,
      40,    40,    31,    31,    58,    58,    31,    39,    31,    44,
      31,    44,     6,    11,    25,    25,    13,    14,    25,    43,
      40,    40,    40,    37,    25,    25,    37,    37,    41,     6,
      11,    55,    55,    40,    40,    58,    12,    58,    51,    48,
      57,    12,    58,    58,    57,    57,    48,    40,    40,    41,
      38,    48,    38,    38,    37,    18,    57,    37,    38,    57,
      38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    50,    51,    51,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    54,    54,    54,    55,    55,    55,    55,    56,    56,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    59,    59,    59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     7,    11,     7,     3,     3,
       6,     6,     6,     4,     4,     9,     1,     2,     2,     1,
       1,     1,     1,     6,     3,     3,     2,     2,     1,     7,
       3,     3,     5,     2,     4,     2,     4,     5,     5,     3,
       5,     4,     2,     5,     1,     3,     1,     3,     1,     4,
       4,     1,     2,     3,     3,     3,     3,     4,     3,     3,
       2,     3,     1,     1,     1,     1,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* begin: INICIO prog FIM  */
#line 928 "Mercia_sint.y"
                       {eval(newast('z', NULL, NULL));}
#line 2216 "Mercia_sint.tab.c"
    break;

  case 3: /* prog: cmds  */
#line 931 "Mercia_sint.y"
           {eval((yyvsp[0].a));}
#line 2222 "Mercia_sint.tab.c"
    break;

  case 4: /* prog: prog cmds  */
#line 932 "Mercia_sint.y"
                    {eval((yyvsp[0].a));}
#line 2228 "Mercia_sint.tab.c"
    break;

  case 5: /* cmds: IF '(' exp ')' '{' list '}'  */
#line 936 "Mercia_sint.y"
                                            {(yyval.a) = newflow('I', (yyvsp[-4].a), (yyvsp[-1].a), NULL);}
#line 2234 "Mercia_sint.tab.c"
    break;

  case 6: /* cmds: IF '(' exp ')' '{' list '}' ELSE '{' list '}'  */
#line 937 "Mercia_sint.y"
                                                    {(yyval.a) = newflow('I', (yyvsp[-8].a), (yyvsp[-5].a), (yyvsp[-1].a));}
#line 2240 "Mercia_sint.tab.c"
    break;

  case 7: /* cmds: WHILE '(' exp ')' '{' list '}'  */
#line 938 "Mercia_sint.y"
                                     {(yyval.a) = newflow('W', (yyvsp[-4].a), (yyvsp[-1].a), NULL);}
#line 2246 "Mercia_sint.tab.c"
    break;

  case 8: /* cmds: VARIAVEL '=' STRING  */
#line 939 "Mercia_sint.y"
                          {(yyval.a) = newasgn((yyvsp[-2].texto), newtexto((yyvsp[0].texto)));}
#line 2252 "Mercia_sint.tab.c"
    break;

  case 9: /* cmds: VARIAVEL '=' exp  */
#line 940 "Mercia_sint.y"
                       {(yyval.a) = newasgn((yyvsp[-2].texto), (yyvsp[0].a));}
#line 2258 "Mercia_sint.tab.c"
    break;

  case 10: /* cmds: VARIAVEL '[' INTEIRO ']' '=' exp  */
#line 941 "Mercia_sint.y"
                                     {(yyval.a) = newasgn_a((yyvsp[-5].texto), (yyvsp[0].a), newint((yyvsp[-3].inteiro)));}
#line 2264 "Mercia_sint.tab.c"
    break;

  case 11: /* cmds: VARIAVEL '[' VARIAVEL ']' '=' exp  */
#line 942 "Mercia_sint.y"
                                      {(yyval.a) = newasgn_a((yyvsp[-5].texto), (yyvsp[0].a), newValorVal((yyvsp[-3].texto)));}
#line 2270 "Mercia_sint.tab.c"
    break;

  case 12: /* cmds: VARIAVEL '[' INTEIRO ']' '=' STRING  */
#line 943 "Mercia_sint.y"
                                        {(yyval.a) = newasgn_a((yyvsp[-5].texto), newtexto((yyvsp[0].texto)), newint((yyvsp[-3].inteiro)));}
#line 2276 "Mercia_sint.tab.c"
    break;

  case 13: /* cmds: ESCRITA '(' escreva ')'  */
#line 944 "Mercia_sint.y"
                              {(yyval.a) = (yyvsp[-1].a);}
#line 2282 "Mercia_sint.tab.c"
    break;

  case 14: /* cmds: LEITURA '(' leitura ')'  */
#line 945 "Mercia_sint.y"
                              {(yyval.a) = (yyvsp[-1].a);}
#line 2288 "Mercia_sint.tab.c"
    break;

  case 15: /* cmds: FOR var ';' exp ';' cmds '{' list '}'  */
#line 946 "Mercia_sint.y"
                                              { (yyval.a) = newflowfor('F', (yyvsp[-7].a), (yyvsp[-5].a), (yyvsp[-3].a), (yyvsp[-1].a), NULL);}
#line 2294 "Mercia_sint.tab.c"
    break;

  case 16: /* cmds: ternario  */
#line 947 "Mercia_sint.y"
               { (yyval.a) = (yyvsp[0].a); }
#line 2300 "Mercia_sint.tab.c"
    break;

  case 17: /* cmds: VARIAVEL PLUS  */
#line 948 "Mercia_sint.y"
                               {(yyval.a) = newasgn((yyvsp[-1].texto), newast('+',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2306 "Mercia_sint.tab.c"
    break;

  case 18: /* cmds: VARIAVEL LESS  */
#line 949 "Mercia_sint.y"
                               {(yyval.a) = newasgn((yyvsp[-1].texto), newast('-',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2312 "Mercia_sint.tab.c"
    break;

  case 19: /* cmds: COMENTARIO  */
#line 950 "Mercia_sint.y"
                 {(yyval.a) = newast('P', NULL, NULL);}
#line 2318 "Mercia_sint.tab.c"
    break;

  case 20: /* cmds: funcao  */
#line 951 "Mercia_sint.y"
             {(yyval.a) = (yyvsp[0].a);}
#line 2324 "Mercia_sint.tab.c"
    break;

  case 21: /* cmds: declmult  */
#line 952 "Mercia_sint.y"
               { (yyval.a) = (yyvsp[0].a) ;}
#line 2330 "Mercia_sint.tab.c"
    break;

  case 22: /* cmds: declmult2  */
#line 953 "Mercia_sint.y"
                { (yyval.a) = (yyvsp[0].a) ;}
#line 2336 "Mercia_sint.tab.c"
    break;

  case 23: /* ternario: exp '?' var1 ':' var1 ';'  */
#line 956 "Mercia_sint.y"
                                    {(yyval.a) = newflow('?', (yyvsp[-5].a), (yyvsp[-3].a), (yyvsp[-1].a));}
#line 2342 "Mercia_sint.tab.c"
    break;

  case 24: /* var: VARIAVEL '=' exp  */
#line 959 "Mercia_sint.y"
                       {(yyval.a) = newasgn((yyvsp[-2].texto), (yyvsp[0].a));}
#line 2348 "Mercia_sint.tab.c"
    break;

  case 25: /* var1: VARIAVEL '=' exp  */
#line 962 "Mercia_sint.y"
                       {(yyval.a) = newasgn((yyvsp[-2].texto), (yyvsp[0].a));}
#line 2354 "Mercia_sint.tab.c"
    break;

  case 26: /* var1: VARIAVEL PLUS  */
#line 963 "Mercia_sint.y"
                               {(yyval.a) = newasgn((yyvsp[-1].texto), newast('+',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2360 "Mercia_sint.tab.c"
    break;

  case 27: /* var1: VARIAVEL LESS  */
#line 964 "Mercia_sint.y"
                               {(yyval.a) = newasgn((yyvsp[-1].texto), newast('-',newValorVal((yyvsp[-1].texto)),newint(1)));}
#line 2366 "Mercia_sint.tab.c"
    break;

  case 28: /* var1: exp  */
#line 965 "Mercia_sint.y"
         {(yyval.a)= (yyvsp[0].a);}
#line 2372 "Mercia_sint.tab.c"
    break;

  case 29: /* funcao: VOID VARIAVEL '(' ')' '{' list '}'  */
#line 968 "Mercia_sint.y"
                                                     {(yyval.a) = newfunction((yyvsp[-6].inteiro), (yyvsp[-5].texto), (yyvsp[-1].a));}
#line 2378 "Mercia_sint.tab.c"
    break;

  case 30: /* funcao: VARIAVEL '(' ')'  */
#line 969 "Mercia_sint.y"
                                     {(yyval.a) = newast('a', newtexto((yyvsp[-2].texto)), NULL);}
#line 2384 "Mercia_sint.tab.c"
    break;

  case 31: /* declmult: declmult ',' VARIAVEL  */
#line 973 "Mercia_sint.y"
                                 {(yyval.a) = newvar((yyvsp[-2].a)->nodetype, (yyvsp[0].texto), NULL, (yyvsp[-2].a));}
#line 2390 "Mercia_sint.tab.c"
    break;

  case 32: /* declmult: declmult ',' VARIAVEL '=' exp  */
#line 974 "Mercia_sint.y"
                                    {(yyval.a) = newvar((yyvsp[-4].a)->nodetype, (yyvsp[-2].texto), (yyvsp[0].a), (yyvsp[-4].a));}
#line 2396 "Mercia_sint.tab.c"
    break;

  case 33: /* declmult: T_INT VARIAVEL  */
#line 975 "Mercia_sint.y"
                     {(yyval.a) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2402 "Mercia_sint.tab.c"
    break;

  case 34: /* declmult: T_INT VARIAVEL '=' exp  */
#line 976 "Mercia_sint.y"
                             {(yyval.a) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), (yyvsp[0].a), NULL);}
#line 2408 "Mercia_sint.tab.c"
    break;

  case 35: /* declmult: T_REAL VARIAVEL  */
#line 977 "Mercia_sint.y"
                      {(yyval.a) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2414 "Mercia_sint.tab.c"
    break;

  case 36: /* declmult: T_REAL VARIAVEL '=' exp  */
#line 978 "Mercia_sint.y"
                              {(yyval.a) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), (yyvsp[0].a), NULL);}
#line 2420 "Mercia_sint.tab.c"
    break;

  case 37: /* declmult: T_INT VARIAVEL '[' INTEIRO ']'  */
#line 979 "Mercia_sint.y"
                                     { (yyval.a) = newarray('A',(yyvsp[-3].texto), (yyvsp[-1].inteiro));}
#line 2426 "Mercia_sint.tab.c"
    break;

  case 38: /* declmult: T_REAL VARIAVEL '[' INTEIRO ']'  */
#line 980 "Mercia_sint.y"
                                      { (yyval.a) = newarray('B',(yyvsp[-3].texto), (yyvsp[-1].inteiro));}
#line 2432 "Mercia_sint.tab.c"
    break;

  case 39: /* declmult2: declmult2 ',' VARIAVEL  */
#line 984 "Mercia_sint.y"
                                  {(yyval.a) = newvar((yyvsp[-2].a)->nodetype, (yyvsp[0].texto), NULL, (yyvsp[-2].a));}
#line 2438 "Mercia_sint.tab.c"
    break;

  case 40: /* declmult2: declmult2 ',' VARIAVEL '=' STRING  */
#line 985 "Mercia_sint.y"
                                        {(yyval.a) = newvar((yyvsp[-4].a)->nodetype, (yyvsp[-2].texto), newtexto((yyvsp[0].texto)), (yyvsp[-4].a));}
#line 2444 "Mercia_sint.tab.c"
    break;

  case 41: /* declmult2: T_TEXTO VARIAVEL '=' STRING  */
#line 986 "Mercia_sint.y"
                                  {(yyval.a) = newvar((yyvsp[-3].inteiro), (yyvsp[-2].texto), newtexto((yyvsp[0].texto)), NULL);}
#line 2450 "Mercia_sint.tab.c"
    break;

  case 42: /* declmult2: T_TEXTO VARIAVEL  */
#line 987 "Mercia_sint.y"
                       {(yyval.a) = newvar((yyvsp[-1].inteiro), (yyvsp[0].texto), NULL, NULL);}
#line 2456 "Mercia_sint.tab.c"
    break;

  case 43: /* declmult2: T_TEXTO VARIAVEL '[' INTEIRO ']'  */
#line 988 "Mercia_sint.y"
                                       { (yyval.a) = newarray('C',(yyvsp[-3].texto), (yyvsp[-1].inteiro));}
#line 2462 "Mercia_sint.tab.c"
    break;

  case 44: /* escreva: exp  */
#line 991 "Mercia_sint.y"
             {(yyval.a) = newast('P', (yyvsp[0].a), NULL);}
#line 2468 "Mercia_sint.tab.c"
    break;

  case 45: /* escreva: exp ',' escreva  */
#line 992 "Mercia_sint.y"
                      {(yyval.a) = newast('P', (yyvsp[-2].a), (yyvsp[0].a));}
#line 2474 "Mercia_sint.tab.c"
    break;

  case 46: /* escreva: STRING  */
#line 993 "Mercia_sint.y"
             {(yyval.a) = newast('P', newtexto((yyvsp[0].texto)), NULL);}
#line 2480 "Mercia_sint.tab.c"
    break;

  case 47: /* escreva: STRING ',' escreva  */
#line 994 "Mercia_sint.y"
                         {(yyval.a) = newast('P', newtexto((yyvsp[-2].texto)), (yyvsp[0].a));}
#line 2486 "Mercia_sint.tab.c"
    break;

  case 48: /* leitura: VARIAVEL  */
#line 997 "Mercia_sint.y"
                  {(yyval.a) = newast('c', newValorVal((yyvsp[0].texto)), NULL);}
#line 2492 "Mercia_sint.tab.c"
    break;

  case 49: /* leitura: VARIAVEL '[' INTEIRO ']'  */
#line 998 "Mercia_sint.y"
                                   {(yyval.a) = newast('G', newValorVal((yyvsp[-3].texto)), newint((yyvsp[-1].inteiro)));}
#line 2498 "Mercia_sint.tab.c"
    break;

  case 50: /* leitura: VARIAVEL '[' VARIAVEL ']'  */
#line 999 "Mercia_sint.y"
                                    {(yyval.a) = newast('G', newValorVal((yyvsp[-3].texto)), newValorVal((yyvsp[-1].texto)));}
#line 2504 "Mercia_sint.tab.c"
    break;

  case 51: /* list: cmds  */
#line 1003 "Mercia_sint.y"
           {(yyval.a) = (yyvsp[0].a);}
#line 2510 "Mercia_sint.tab.c"
    break;

  case 52: /* list: list cmds  */
#line 1004 "Mercia_sint.y"
                { (yyval.a) = newast('L', (yyvsp[-1].a), (yyvsp[0].a));}
#line 2516 "Mercia_sint.tab.c"
    break;

  case 53: /* exp: exp '+' exp  */
#line 1007 "Mercia_sint.y"
                 {(yyval.a) = newast('+', (yyvsp[-2].a), (yyvsp[0].a));}
#line 2522 "Mercia_sint.tab.c"
    break;

  case 54: /* exp: exp '-' exp  */
#line 1008 "Mercia_sint.y"
                  {(yyval.a) = newast('-',(yyvsp[-2].a),(yyvsp[0].a));}
#line 2528 "Mercia_sint.tab.c"
    break;

  case 55: /* exp: exp '*' exp  */
#line 1009 "Mercia_sint.y"
                  {(yyval.a) = newast('*',(yyvsp[-2].a),(yyvsp[0].a));}
#line 2534 "Mercia_sint.tab.c"
    break;

  case 56: /* exp: exp '/' exp  */
#line 1010 "Mercia_sint.y"
                  {(yyval.a) = newast('/',(yyvsp[-2].a),(yyvsp[0].a));}
#line 2540 "Mercia_sint.tab.c"
    break;

  case 57: /* exp: SQRT '(' exp ')'  */
#line 1011 "Mercia_sint.y"
                       {{(yyval.a) = newast('R',(yyvsp[-1].a),NULL);}}
#line 2546 "Mercia_sint.tab.c"
    break;

  case 58: /* exp: '(' exp ')'  */
#line 1012 "Mercia_sint.y"
                  {(yyval.a) = (yyvsp[-1].a);}
#line 2552 "Mercia_sint.tab.c"
    break;

  case 59: /* exp: exp '^' exp  */
#line 1013 "Mercia_sint.y"
                  {(yyval.a) = newast('^',(yyvsp[-2].a),(yyvsp[0].a));}
#line 2558 "Mercia_sint.tab.c"
    break;

  case 60: /* exp: '-' exp  */
#line 1014 "Mercia_sint.y"
                        {(yyval.a) = newast('M',(yyvsp[0].a),NULL);}
#line 2564 "Mercia_sint.tab.c"
    break;

  case 61: /* exp: exp CMP exp  */
#line 1015 "Mercia_sint.y"
                  {(yyval.a) = newcmp((yyvsp[-1].fn),(yyvsp[-2].a),(yyvsp[0].a));}
#line 2570 "Mercia_sint.tab.c"
    break;

  case 62: /* exp: num  */
#line 1016 "Mercia_sint.y"
          {(yyval.a) = (yyvsp[0].a);}
#line 2576 "Mercia_sint.tab.c"
    break;

  case 63: /* num: INTEIRO  */
#line 1019 "Mercia_sint.y"
             { (yyval.a) = newint((yyvsp[0].inteiro));}
#line 2582 "Mercia_sint.tab.c"
    break;

  case 64: /* num: REAL  */
#line 1020 "Mercia_sint.y"
           { (yyval.a) = newreal((yyvsp[0].real));}
#line 2588 "Mercia_sint.tab.c"
    break;

  case 65: /* num: VARIAVEL  */
#line 1021 "Mercia_sint.y"
                         { (yyval.a) = newValorVal((yyvsp[0].texto)); }
#line 2594 "Mercia_sint.tab.c"
    break;

  case 66: /* num: VARIAVEL '[' INTEIRO ']'  */
#line 1022 "Mercia_sint.y"
                               {(yyval.a) = newValorVal_a((yyvsp[-3].texto), newint((yyvsp[-1].inteiro)));}
#line 2600 "Mercia_sint.tab.c"
    break;

  case 67: /* num: VARIAVEL '[' VARIAVEL ']'  */
#line 1023 "Mercia_sint.y"
                                {(yyval.a) = newValorVal_a((yyvsp[-3].texto), newValorVal((yyvsp[-1].texto)));}
#line 2606 "Mercia_sint.tab.c"
    break;


#line 2610 "Mercia_sint.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1026 "Mercia_sint.y"


#include "lex.yy.c"

int main(){
    yyin=fopen("vetor.txt", "r");
    
    yyparse();
    yylex();
    fclose(yyin);
    return 0;

}

int yywrap(){
    return 0;
}

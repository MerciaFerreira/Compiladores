%{
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

%}

%union {
    char texto[50];
    double real;
    int inteiro;
    int fn;
    Ast *a;
}


%token INICIO FIM 
%token <real> REAL 
%token <inteiro> INTEIRO T_INT T_REAL T_TEXTO VOID
%token <texto> VARIAVEL STRING PLUS LESS COMENTARIO 
%token IF ELSE WHILE FOR SQRT LEITURA ESCRITA
%token <fn> CMP


%type <a> list begin exp num prog cmds var var1 ternario declmult declmult2 escreva funcao leitura

// Declaração de precedência dos operadores
%left CMP
%right PLUS LESS
%right '='
%left '+' '-'
%left '*' '/' 
%right '^'
%left ')'
%right '('



%nonassoc IFX NEG FUN VET


//%Iniciando as regras do analisador sintático
%%
// inicio do programa
begin: INICIO prog FIM {eval(newast('z', NULL, NULL));} 
     ;

prog: cmds {eval($1);}  
	| prog cmds {eval($2);} 
	;

// variacoes dos codigos dessa linguagem
cmds: IF '(' exp ')' '{' list '}' %prec IFX {$$ = newflow('I', $3, $6, NULL);}
    | IF '(' exp ')' '{' list '}' ELSE '{' list '}' {$$ = newflow('I', $3, $6, $10);} 
    | WHILE '(' exp ')' '{' list '}' {$$ = newflow('W', $3, $6, NULL);}
    | VARIAVEL '=' STRING {$$ = newasgn($1, newtexto($3));} 
    | VARIAVEL '=' exp {$$ = newasgn($1, $3);} 
    | VARIAVEL '['INTEIRO']' '=' exp {$$ = newasgn_a($1, $6, newint($3));}
    | VARIAVEL '['VARIAVEL']' '=' exp {$$ = newasgn_a($1, $6, newValorVal($3));} 
    | VARIAVEL '['INTEIRO']' '=' STRING {$$ = newasgn_a($1, newtexto($6), newint($3));}
    | ESCRITA '(' escreva ')' {$$ = $3;} 
    | LEITURA '(' leitura ')' {$$ = $3;}
    | FOR  var ';' exp ';' cmds  '{' list '}' { $$ = newflowfor('F', $2, $4, $6, $8, NULL);}
    | ternario { $$ = $1; }
    | VARIAVEL PLUS %prec PLUS {$$ = newasgn($1, newast('+',newValorVal($1),newint(1)));} // incremento
    | VARIAVEL LESS %prec LESS {$$ = newasgn($1, newast('-',newValorVal($1),newint(1)));} 	
    | COMENTARIO {$$ = newast('P', NULL, NULL);}
    | funcao {$$ = $1;}
    | declmult { $$ = $1 ;} 
    | declmult2 { $$ = $1 ;}
    ;

ternario: exp '?' var1 ':' var1 ';' {$$ = newflow('?', $1, $3, $5);} 
        ;

var:  VARIAVEL '=' exp {$$ = newasgn($1, $3);}
    ;

var1: VARIAVEL '=' exp {$$ = newasgn($1, $3);}
    | VARIAVEL PLUS %prec PLUS {$$ = newasgn($1, newast('+',newValorVal($1),newint(1)));} 
    | VARIAVEL LESS %prec LESS {$$ = newasgn($1, newast('-',newValorVal($1),newint(1)));}
    | exp{$$= $1;}
    ;

funcao: VOID VARIAVEL '(' ')' '{' list '}' %prec FUN {$$ = newfunction($1, $2, $6);}
        | VARIAVEL '(' ')' %prec FUN {$$ = newast('a', newtexto($1), NULL);}
        ;


declmult:  declmult ',' VARIAVEL {$$ = newvar($1->nodetype, $3, NULL, $1);} 
    | declmult ',' VARIAVEL '=' exp {$$ = newvar($1->nodetype, $3, $5, $1);} 
    | T_INT VARIAVEL {$$ = newvar($1, $2, NULL, NULL);} 
    | T_INT VARIAVEL '=' exp {$$ = newvar($1, $2, $4, NULL);} 
    | T_REAL VARIAVEL {$$ = newvar($1, $2, NULL, NULL);} 
    | T_REAL VARIAVEL '=' exp {$$ = newvar($1, $2, $4, NULL);} 
    | T_INT VARIAVEL '[' INTEIRO ']' { $$ = newarray('A',$2, $4);} 
    | T_REAL VARIAVEL '[' INTEIRO ']' { $$ = newarray('B',$2, $4);} 
    ;

// declaracao de multiplas variaveis do tipo texto
declmult2: declmult2 ',' VARIAVEL {$$ = newvar($1->nodetype, $3, NULL, $1);} 
    | declmult2 ',' VARIAVEL '=' STRING {$$ = newvar($1->nodetype, $3, newtexto($5), $1);} 
    | T_TEXTO VARIAVEL '=' STRING {$$ = newvar($1, $2, newtexto($4), NULL);} // declaracao de String e a atribuicao
    | T_TEXTO VARIAVEL {$$ = newvar($1, $2, NULL, NULL);} 
    | T_TEXTO VARIAVEL '[' INTEIRO ']' { $$ = newarray('C',$2, $4);}
    ;

escreva: exp {$$ = newast('P', $1, NULL);}
    | exp ',' escreva {$$ = newast('P', $1, $3);}
    | STRING {$$ = newast('P', newtexto($1), NULL);} 
    | STRING ',' escreva {$$ = newast('P', newtexto($1), $3);}
    ; 

leitura: VARIAVEL {$$ = newast('c', newValorVal($1), NULL);} 
        | VARIAVEL '[' INTEIRO ']' {$$ = newast('G', newValorVal($1), newint($3));} 
        | VARIAVEL '[' VARIAVEL ']' {$$ = newast('G', newValorVal($1), newValorVal($3));}
        ;

// estrutura para multiplas linhas de codigo para estruturas de decisão/loop
list: cmds {$$ = $1;}
    | list cmds { $$ = newast('L', $1, $2);}
    ;

exp: exp '+' exp {$$ = newast('+', $1, $3);}
    | exp '-' exp {$$ = newast('-',$1,$3);}
    | exp '*' exp {$$ = newast('*',$1,$3);}
    | exp '/' exp {$$ = newast('/',$1,$3);}
    | SQRT '(' exp ')' {{$$ = newast('R',$3,NULL);}}
    | '(' exp ')' {$$ = $2;} 
    | exp '^' exp {$$ = newast('^',$1,$3);} 
    | '-' exp %prec NEG {$$ = newast('M',$2,NULL);}
    | exp CMP exp {$$ = newcmp($2,$1,$3);}
    | num {$$ = $1;}
    ; 

num: INTEIRO { $$ = newint($1);} 
    | REAL { $$ = newreal($1);} 
    | VARIAVEL %prec VET { $$ = newValorVal($1); }  
    | VARIAVEL '[' INTEIRO ']' {$$ = newValorVal_a($1, newint($3));}
    | VARIAVEL '[' VARIAVEL ']' {$$ = newValorVal_a($1, newValorVal($3));} 
    ;

%%

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
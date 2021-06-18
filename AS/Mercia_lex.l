%option yylineno
%{
    
%}

INICIO "M_INICIO" 
FIM "M_FIM" 
LETRAS [a-zA-Z]+  
INTEIRO [0-9]+     
REAL [0-9]*"."[0-9]+ 
STRING \"[^\"]*\" 
SQRT "sqrt"  
VARIAVEL {LETRAS}({LETRAS}|{INTEIRO}|"_")* 
COMENTARIO "m\\".* 
IF "if" 
ELSE "else" 
WHILE "while" 
FOR "for" 
LEITURA "leia" 
ESCRITA "escreva" 
PLUS "++" 
LESS "--" 
IGNORAR [\ \t\s] 
INVALIDO . 
%%

"int" {
    yylval.inteiro = 'i';
    return T_INT;
}
"real" {
    yylval.inteiro = 'r';
    return T_REAL;
}
"texto" {
    yylval.inteiro = 't';
    return T_TEXTO;
}
"void" {
    yylval.inteiro = 'v';
    return VOID;
}

{COMENTARIO} {
    strcpy(yylval.texto, yytext);
    return COMENTARIO;
}
{PLUS} {
    return PLUS;
}
{LESS} {
    return LESS;
}

[-+/|*=^:;,\[\](){}] {
    return *yytext;
}
{LEITURA} { 
    return LEITURA;
}
 /* OPERADORES LOGICOS */
">" {yylval.fn = 1; return CMP; }
"<" {yylval.fn = 2; return CMP; }
"!=" {yylval.fn = 3; return CMP; }
"==" {yylval.fn = 4; return CMP; }
">=" {yylval.fn = 5; return CMP; }
"<=" {yylval.fn = 6; return CMP; }
"||" {yylval.fn = 7; return CMP; }
"&&" {yylval.fn = 8; return CMP; }
"?" { return '?'; }

[\n] {
    /* CONTADOR PARA SALTO DE LINHAS */
    yylineno++;
}
{INICIO} {
    return INICIO;
}
{FIM} {
    return FIM;
}
{REAL} {
    yylval.real = atof(yytext);
    return REAL;
}
{INTEIRO} {
    yylval.inteiro = atoi(yytext);
    return INTEIRO;
}
{SQRT} {
    return SQRT;
}
{ESCRITA} {
    return ESCRITA;
}
{IF} {
    return IF;
}
{ELSE} {
    return ELSE;
}
{WHILE} {
    return WHILE;
}
{FOR} {
    return FOR;
}
{VARIAVEL} {
    strcpy(yylval.texto, yytext);
    return VARIAVEL;
}
{STRING} {
    int x; 
    for(x=0; x<strlen(yytext); x++){
        yytext[x] = yytext[x+1];
    }
    yytext[strlen(yytext)-1] = '\0';
    strcpy(yylval.texto, yytext);
    return STRING;
}
{IGNORAR} {
    /* ignore */
}
{INVALIDO} {
    /* ignore */
}
%%
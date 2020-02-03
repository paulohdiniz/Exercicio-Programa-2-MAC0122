#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _RegPilha{
    char nome[1000];
    int linha;
    struct _RegPilha *prox;
} RegPilha;
typedef RegPilha* Pilha;
typedef enum boolean {false,true} bool;
/*alocação */
RegPilha *AlocaRegPilha(){
    RegPilha* q;
    q = (RegPilha*)calloc(1, sizeof(RegPilha));
    if(q==NULL){
        exit(-1);
    }
return q;
}
/*cria pilha*/
Pilha CriaPilha(){
    Pilha p;
    p = AlocaRegPilha();
    p->prox = NULL;
    return p;
}
/*libera pilha */
void LiberaPilha(Pilha p){
    RegPilha *q,*t;
    q = p;
    while(q!=NULL){
        t = q;
        q = q->prox;
        free(t);
    }
}
/*pilha vazia */
int PilhaVazia(Pilha p){
    int i =0;
    if (p->prox==NULL){
        i = 1;
    }
return i;
}
/*inserção*/
void Empilha(Pilha p, int x, char *name){
    RegPilha *q;
    q = AlocaRegPilha();
    q->linha = x;
    strcpy( (q->nome), name);
    q->prox = p->prox;
    p->prox = q;
}
/*remocao */
int Desempilha(Pilha p){
    RegPilha *q;
    int x;
    q = p->prox;
    if(q==NULL)
        exit(-1);
    x = q->linha;
    p->prox = q->prox;
    free(q);
return x;
}
char *stringdotopo(Pilha p){
    RegPilha *q;
    q = p->prox;
return q->nome;
}
/*le proximo caracter do arquivo */
int leprox (FILE* fp){
    int proxvar;
    proxvar = fgetc(fp);
    return proxvar;
}
/*transforma a string de entrada em minuscula */
char *minuscula(char *nome1){
    char nome[500];
    char *nomepointer = nome;
    int i =0;
    strcpy(nome, nome1);
    while (nome[i] != EOF){
        if (nome[i] <= 'Z' && nome[i] >= 'A'){
            nome[i] = nome[i] + 'a' - 'A';
        }
    i++;
    }
return nomepointer;
}
int main (){
    char arquivo[1000], tag[20];
    int ch1, ch2, i = 0, linhaTAG = 2, linha1=0, k, testinho =0;
    Pilha p;
    FILE *fp = NULL;
    p = CriaPilha();
    scanf("%s", arquivo);
    fp = fopen(arquivo, "r");
    /* verificar existência */
    if (fp == NULL){
        exit (-1);
    }else{
        while ( (ch1=leprox(fp)) != '\n'){
                /*le a primeira linha fazendo o deslocamento da leitura até o fim da linha */
        }
        while( (ch1=leprox(fp)) != EOF ){
            if (ch1 == '\n'){
                linhaTAG++;
            }
            if (ch1 == '<'){
                ch2 = leprox(fp);
                if (ch2 == '/'){
                    i=0;
                    do{
                        ch1 = leprox(fp);
                        if (ch1 != '>' && ch1 != ' '){
                            tag[i] = ch1;
                        }else{
                            tag[i] = '\0';
                        }
                        i++;
                    }while( ch1 != '>' && ch1 != ' ');
                    if ( (k = strcmp ( stringdotopo(p) , tag)) == 0 ){
                            linha1 = Desempilha(p);
                            if (PilhaVazia(p) == 1){
                                ch1 = leprox(fp);
                                testinho = 171;
                            }
                    }else if ( (k = strcmp ( stringdotopo(p) , minuscula(tag) )) == 0 ){
                            printf("Violacao da regra #1:\n");
                            printf("Tags incompativeis (abertura '%s' na linha", stringdotopo(p));
                            linha1 = Desempilha(p);
                            printf(" %d e fechamento '%s' na linha %d)\n", linha1, tag, linhaTAG );
                            fclose(fp);
                            LiberaPilha(p);
                            exit(-1);
                    }else if ( (k = strcmp ( stringdotopo(p) , minuscula(tag) )) != 0  ){
                            printf("Violacao da regra #2:\n");
                            printf("Tags incompativeis (abertura '%s' na linha", stringdotopo(p));
                            linha1 = Desempilha(p);
                            printf(" %d e fechamento '%s' na linha %d)\n", linha1, tag, linhaTAG );
                            fclose(fp);
                            LiberaPilha(p);
                            exit(-1);
                    }
                }else{
                    i = 1;
                    tag[0] = ch2;
                    do{
                        ch1 = leprox(fp);
                        if(ch1 != '>' && ch1 != ' '){
                            tag[i] = ch1;
                        }else{
                            tag[i] = '\0';
                        }
                        i++;
                    }while( ch1 != '>' && ch1 != ' ');
                    if (testinho != 171){
                        Empilha (p, linhaTAG, tag);
                    }else{
                        printf("Violacao da regra #3:\n");
                        printf("Raiz adicional ('%s' na linha %d)\n", tag, linhaTAG+1);
                        fclose(fp);
                        LiberaPilha(p);
                        exit(-1);
                    }
                }
            }
            ch2 = ch1;
        }
        if (PilhaVazia(p) == 1){
            printf("Tags balanceadas\n");
            fclose(fp);
            LiberaPilha(p);
            exit(-1);
        }
    }
return 0;
}

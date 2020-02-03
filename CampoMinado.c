/***************************************************************/
/**                                                           **/
/**   PAULO HENRIQUE DINIZ FERNANDES          11257630        **/
/**   Exercício-Programa: 03                                  **/
/**   Professor: ALAIR DO LAGO                                **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MMAX 90
#define NMAX 90
/* Durante todo o EP:
matriz com letra maiuscula é do tipo CHAR
matriz com letra miniscula é do tipo INTEIRO */

/* contador de posicoes livres do campo minado */
int qtdlivre (char M[100][100], int x, int y)
{
    int i, j, qtd;
    qtd = 0;
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= y; j++)
        {
            if (M[i][j] == '.')
            {
                qtd = qtd + 1;
            }
        }
    }
    return qtd;
}
/* contador de posicoes marcadas do campo minado */
int qtdmarc (char M[100][100], int t, int u)
{
    int i, j, qtd;
    qtd = 0;
    for (i = 1; i <= t; i++)
    {
        for (j = 1; j <= u; j++)
        {
            if (M[i][j] == '*')
            {
                qtd = qtd + 1;
            }
        }
    }
    return qtd;
}
/* funcao para abrir os zeros */
void zeros (int i, int j, int ma[100][100], char MA[100][100])
{
    if (ma[i][j] == 999)
    {
        MA[i][j] = '0';
        if (ma[i-1][j-1] == 0)
        {
            MA[i-1][j-1] = '0';
            ma[i-1][j-1] = 999;
        }
        else if (ma[i-1][j-1] != 999)
        {
            MA[i-1][j-1] = 48 + ma[i-1][j-1];
        }
        if (ma[i-1][j] == 0)
        {
            MA[i-1][j] = '0';
            ma[i-1][j] = 999;
        }
        else if (ma[i-1][j] != 999)
        {
            MA[i-1][j] = 48 + ma[i-1][j];
        }
        if (ma[i-1][j+1] == 0)
        {
            MA[i-1][j+1] = '0';
            ma[i-1][j+1] = 999;
        }
        else if (ma[i-1][j+1] != 999)
        {
            MA[i-1][j+1] = 48 + ma[i-1][j+1];
        }
        if (ma[i][j-1] == 0)
        {
            MA[i][j-1] = '0';
            ma[i][j-1] = 999;
        }
        else if (ma[i][j-1] != 999)
        {
            MA[i][j-1] = 48 + ma[i][j-1];
        }
        if (ma[i][j+1] == 0)
        {
            MA[i][j+1] = '0';
            ma[i][j+1] = 999;
        }
        else if (ma[i][j+1] != 999)
        {
            MA[i][j+1] = 48 + ma[i][j+1];
        }
        if (ma[i+1][j-1] == 0)
        {
            MA[i+1][j-1] = '0';
            ma[i+1][j-1] = 999;
        }
        else if (ma[i+1][j-1] != 999)
        {
            MA[i+1][j-1] = 48 + ma[i+1][j-1];
        }
        if (ma[i+1][j] == 0)
        {
            MA[i+1][j] = '0';
            ma[i+1][j] = 999;
        }
        else if (ma[i+1][j] != 999)
        {
            MA[i+1][j] = 48 + ma[i+1][j];
        }
        if (ma[i+1][j+1] == 0)
        {
            MA[i+1][j+1] = '0';
            ma[i+1][j+1] = 999;
        }
        else if (ma[i+1][j+1] != 999)
        {
            MA[i+1][j+1] = 48 + ma[i+1][j+1];
        }
    }
}
/* funcao para imprimir a matriz dos caracteres */
void printar (char MATRI[100][100], int m, int n)
{
    int i, j;
    /* primeira linha */
    i = 1;
    printf ("      %d", i);
    for (i = 2; i < n; i++)
    {
        printf ("%3d", i);
    }
    i = n;
    printf ("%3d\n", i);
    /* segunda linha */
    i = 1;
    printf ("   +");
    for (i = 1; i <= n; i++)
    {
        printf ("---");
    }
    i = n + 1;
    printf ("-+\n");
    /* primeira linha do campo minado */
    i = 1;
    printf ("%-3d|", i);
    for (j = 1; j <= (n-1); j++)
    {
        printf ("%3c", MATRI[1][j]);
    }
    printf ("%3c |  1\n", MATRI[1][n]);
    /* segunda linha até a (m -1) */
    for (i = 2; i < m; i++)
    {
        printf ("%-3d|", i);
        for (j = 1; j <= (n-1); j++)
        {
            printf ("%3c", MATRI[i][j]);
        }
        printf ("%3c |  %d\n", MATRI[i][j], i);
    }
    /* m-ésima linha */
    i = m;
    printf ("%-3d|", i);
    for (j = 1; j <= (n-1); j++)
    {
        printf ("%3c", MATRI[i][j]);
    }
    printf ("%3c |  %d\n", MATRI[i][j], i);
    /* tracejado embaixo do campo */
    i = 1;
    printf ("   +");
    for (i = 1; i <= n; i++)
    {
        printf ("---");
    }
    i = n + 1;
    printf ("-+\n");
    /* ultima linha com os numeros da parte inferior */
    i = 1;
    printf ("      %d", i);
    for (i = 2; i < n; i++)
    {
        printf ("%3d", i);
    }
    i = n;
    printf ("%3d\n", i);
}
/* funcao para analisar as entradas do usuario */
void entradas (char comando1, char MAT[100][100], int mat[100][100], int a, int b, int c, int d)
{
    int i,                          /* contador para a linha */
        j,                          /* contador para a coluna */
        marc,                       /* recebe a quantidade de posicoes já marcadas */
        livr,                       /* recebe a quantidade de posicoes livres */
        k;                          /* contador */
    /* a se refere a linha de entrada */
    /* b se refere a coluna de entrada */
    /* c se refere ao numero de linhas do campo minado */
    /* d se refere ao numero de colunas do campo minado */
    /* marcando a posicao do campo */
    if (comando1 == 'm' || comando1 == 'M')
    {
        if (MAT[a][b] != '.')
        {
            printf ("Sem efeito.\n");
        }
        if (MAT[a][b] == '.')
        {
            MAT[a][b] = '*';
            marc = qtdmarc (MAT, c, d);
            livr = qtdlivre (MAT,c, d);
            printf ("Por enquanto: %d/%d marcadas, %d livres.\n", marc, c*d, livr);
            printar (MAT, c, d);
        }
    }
    /* desmarcando a posicao do campo */
    if (comando1 == 'd' || comando1 == 'D')
    {
        if (MAT[a][b] != '*')
        {
            printf ("Sem efeito.\n");
        }
        if (MAT[a][b] == '*')
        {
            MAT[a][b] = '.';
            marc = qtdmarc (MAT, c, d);
            livr = qtdlivre (MAT,c, d);
            printf ("Por enquanto: %d/%d marcadas, %d livres.\n", marc, c*d, livr);
            printar (MAT, c, d);
        }
    }
    /* abrindo uma posicao do campo */
    if (comando1 == 'a' || comando1 == 'A')
    {
        if (MAT[a][b] != '.')
        {
            printf ("Sem efeito.\n");
        }
        if (MAT[a][b] == '.')
        {
            if (mat[a][b] == -1)
            {
                printf ("BOOOOM! Voce acaba de pisar numa mina!\n");
                for (i = 1; i <= c; i++)
                {
                    for (j = 1; j <= d; j++)
                    {
                        if (mat[i][j] == -1)
                        {
                            MAT[i][j] = '@';
                        }
                        if (mat[i][j] == 0)
                        {
                            MAT[i][j] = '0';
                        }
                        if (mat[i][j] == 1)
                        {
                            MAT[i][j] = '1';
                        }
                        if (mat[i][j] == 2)
                        {
                            MAT[i][j] = '2';
                        }
                        if (mat[i][j] == 3)
                        {
                            MAT[i][j] = '3';
                        }
                        if (mat[i][j] == 4)
                        {
                            MAT[i][j] = '4';
                        }
                        if (mat[i][j] == 5)
                        {
                            MAT[i][j] = '5';
                        }
                        if (mat[i][j] == 6)
                        {
                            MAT[i][j] = '6';
                        }
                        if (mat[i][j] == 7)
                        {
                            MAT[i][j] = '7';
                        }
                        if (mat[i][j] == 8)
                        {
                            MAT[i][j] = '8';
                        }
                    }
                }
                printar (MAT, c, d);
            }
            if (mat[a][b] != -1 && mat[a][b] != 0)
            {
                if (mat[a][b] == 1)
                {
                    MAT[a][b] = '1';
                }
                if (mat[a][b] == 2)
                {
                    MAT[a][b] = '2';
                }
                if (mat[a][b] == 3)
                {
                    MAT[a][b] = '3';
                }
                if (mat[a][b] == 4)
                {
                    MAT[a][b] = '4';
                }
                if (mat[a][b] == 5)
                {
                    MAT[a][b] = '5';
                }
                if (mat[a][b] == 6)
                {
                    MAT[a][b] = '6';
                }
                if (mat[a][b] == 7)
                {
                    MAT[a][b] = '7';
                }
                if (mat[a][b] == 8)
                {
                    MAT[a][b] = '8';
                }
                marc = qtdmarc (MAT, c, d);
                livr = qtdlivre (MAT, c, d);
                printf ("Por enquanto: %d/%d marcadas, %d livres.\n", marc, c*d, livr);
                printar (MAT, c, d);
            }
            if (mat[a][b] == 0)
            {
                mat[a][b] = 999;    /* o 999 eh um numero aleatorio para marcar a posicao */
                for (k = 0; k <= c*d; k++)
                {
                    for (i = 1; i <= c; i++)
                    {
                        for (j = 1; j <= d; j++)
                        {
                            zeros (i, j, mat, MAT);
                        }
                    }
                }
                marc = qtdmarc (MAT, c, d);
                livr = qtdlivre (MAT,c, d);
                printf ("Por enquanto: %d/%d marcadas, %d livres.\n", marc, c*d, livr);
                printar (MAT, c, d);
            }

        }
    }
}
int main()
{
    int m,                  /* numero de linhas */
        n,                      /* numero de colunas */
        z,                      /* numero de bombas */
        random,                 /* numero aleatorio */
        i,                      /* posicao da linha */
        j,                      /* posicao da coluna */
        s,                      /* semente */
        contadorminas,          /* contador usado para distribuir e contar minas */
        linha,                  /* variavel referente a posicao da linha */
        coluna;                 /* variavel referente a posicao da coluna */
    char letra;             /* variavel char para entrada de comando */
    int matriz[100][100];   /* matriz de inteiros que localizam bombas e os valores das casas do entorno de bombas */
    char MATRIZ[100][100];  /* matriz dos caracteres que vamos usar para imprimir */
    m = n = z = s = -1; /* valores iniciais para o looping */
    /*inicio das entradas do usuario */
    while (m < 3 || m > MMAX)
    {
        printf ("De o numero de linhas do tabuleiro do jogo:\n");
        scanf ("%d", &m);
    }
    while (n < 3 || n > NMAX)
    {
        printf ("De o numero de colunas do tabuleiro do jogo:\n");
        scanf ("%d", &n);
    }
    while (z < 1 || z > (m*n -1))
    {
        printf ("De o numero de minas:\n");
        scanf ("%d", &z);
    }
    while (s < 1 || s > 12345)
    {
        printf ("De a semente:\n");
        scanf ("%d", &s);
    }
    /* atribuindo zero a matriz dos valores */
    for (i = 1; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            matriz[i][j]= 0;
        }
    }
    /* atribuindo . para a matriz dos caracteres */
    for (i = 1; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            MATRIZ[i][j] = 46;
        }
    }
    /* distribuindo as minas aleatoriamente no campo minado(matriz dos valores) */
    srand(s);
    contadorminas = 0;
    while (contadorminas != z)
    {
        random = rand();
        i = random%m + 1;
        j = (random/m)%n + 1;
        matriz [i][j] = -1;
        contadorminas = 0;
        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (matriz[i][j] == -1)
                {
                    contadorminas = contadorminas +1;
                }
            }
        }
    }
    /* atribuindo o k de cada lugar */
    contadorminas = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (matriz[i][j] != -1)
            {
                if(matriz[i-1][j-1] == -1)
                {
                    contadorminas = contadorminas +1;
                }
                if(matriz[i-1][j] == -1)
                {
                    contadorminas = contadorminas +1;
                }
                if(matriz[i-1][j+1] == -1)
                {
                    contadorminas = contadorminas +1;
                }
                if(matriz[i][j-1] == -1)
                {
                    contadorminas = contadorminas +1;
                }
                if(matriz[i][j+1] == -1)
                {
                    contadorminas = contadorminas +1;
                }
                if(matriz[i+1][j-1] == -1)
                {
                    contadorminas = contadorminas +1;
                }
                if(matriz[i+1][j] == -1)
                {
                    contadorminas = contadorminas +1;
                }
                if(matriz[i+1][j+1] == -1)
                {
                    contadorminas = contadorminas +1;
                }
                matriz[i][j] = contadorminas;
                contadorminas = 0;
            }
        }
    }
    /* impressao das entradas mais a matriz inicial fechada*/
    printf ("Numero de linhas (3 <= m <= 90): %d\n", m);
    printf ("Numero de colunas (3 <= n <= 90): %d\n", n);
    printf ("Numero de minas (1 <= z <= 15): %d\n", z);
    printf ("Semente (1 <= s <= 12345): %d\n", s);
    printf ("Bem vindo ao Caca-Minas!\n");
    printar (MATRIZ, m, n);
    /*condição de looping até que o usuario acabe o jogo */
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            while (MATRIZ[i][j] == '.')
            {
                printf ("Proximo chute:\n");
                scanf (" %c %d %d", &letra, &linha, &coluna);
                entradas (letra, MATRIZ, matriz, linha, coluna, m, n);
            }

        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

//enum categoria{ Verd, Falso, ConstInt, ConstReal, Id
//, Se, Senão, RepAte, RepEnq, Ou, E, OpU, OpM, OpA
//, OpAtr, OpC, OpI, Atr, APar, FPar, Ponto, PV, ACol
//, FCol, AChaves, FChaves, Virgula, Inteiro, Decimal
//, Booleano, Caractere, ListaInt, ListaDec, ListaBool
//, ListaCarac, Inclua, Devolva, Constante, Caso, Seja
//, Vazio}categ;

enum categoria{ Verd, Falso, ConstInt, ConstReal, Id, 
  Se, Senao, RepAte, RepEnq, Ou, E, OpU, OpM, OpA, 
  OpAtr, OpC, OpI, Atr, APar, FPar, Ponto, PV, ACol, 
  FCol, AChaves, FChaves, Virgula, Inteiro, Decimal, 
  Booleano, Caractere, ListaInt, ListaDec, ListaBool, 
  ListaCarac, Inclua, Devolva, Constante, Caso, Seja, 
  Vazio, ConstCarac, ConstLisCa, Comentario, Principal };

typedef enum categoria categToken;


typedef struct
{
	int linha, coluna;
	categToken categoriaDoToken;
	char lexema[51];
}Token;

char PALAVRAS_RESERVADAS[][51] = { "inteiro", "decimal", 
  "booleano", "caractere", "listaInteiro", "listaDecimal", 
  "listaBooleano", "listaCaractere", "inclua", "devolva", 
  "se", "senao", "repitaAte", "repitaEnquanto",
  "constante", "verdadeiro", "caso", "seja", "vazio", 
  "falso", "principal" };
int tamanhoPR = 21;

categToken calculadorTokenPalavraReservada( char *cadeia )
{
  bool achou = false;
  char *ponteiro;
  int a, qual = -1;
  for( a = 0; a < tamanhoPR && !achou; a++ )
  {

    //printf( "{%s == %s = %d} ",cadeia, PALAVRAS_RESERVADAS[a], strcmp( cadeia, PALAVRAS_RESERVADAS[a] ) );

    if( strcmp( cadeia, PALAVRAS_RESERVADAS[a] ) == 0 )
    {
      achou = true;
      qual = a;
    }
  }


  if( cadeia[0] >= '0' && cadeia[0] <= '9' )
  {
    //pch = (char*) memchr (str, 'p', strlen(str));
    ponteiro = (char*) memchr( cadeia, '.', strlen(cadeia) );

    if(ponteiro != NULL)
    {
      return ConstReal;
    }else
    {
      return ConstInt;
    }
  }

  //printf("\n");

  switch(qual)
  {
    case 0:
      return Inteiro;
    break;
    case 1:
      return Decimal;
    break;
    case 2:
      return Booleano;
    break;
    case 3:
      return Caractere;
    break;
    case 4:
      return ListaInt;
    break;
    case 5:
      return ListaDec;
    break;
    case 6:
      return ListaBool;
    break;
    case 7:
      return ListaCarac;
    break;
    case 8:
      return Inclua;
    break;
    case 9:
      return Devolva;
    break;
    case 10:
      return Se;
    break;
    case 11:
      return Senao;
    break;
    case 12:
      return RepAte;
    break;
    case 13:
      return RepEnq;
    break;
    case 14:
      return Constante;
    break;
    case 15:
      return Verd;
    break;
    case 16:
      return Caso;
    break;
    case 17:
      return Seja;
    break;
    case 18:
      return Vazio;
    break;
    case 19:
      return Falso;
    break;
    case 20:
      return Principal;
    break;
    case -1:
      return Id;
    break;
    /*case 1:

    break;
    case 2:

    break;
    case 3:

    break;
    case 4:

    break;
    case 5:

    break;
    case 6:

    break;
    case 7:

    break;
    case 8:

    break;
    case 9:

    break;*/
    default:
      return Id;
  }
}

char *calculadorNomeDaCategoria( int c )
{
  switch( c )
  {
    case 0:
      return "Verd";
    break;
    case 1:
      return "Falso";
    break;
    case 2:
      return "ConstInt";
    break;
    case 3:
      return "ConstReal";
    break;
    case 4:
      return "Id";
    break;
    case 5:
      return "Se";
    break;
    case 6:
      return "Senão";
    break;
    case 7:
      return "RepAte";
    break;
    case 8:
      return "RepEnq";
    break;
    case 9:
      return "Ou";
    break;
    case 10:
      return "E";
    break;
    case 11:
      return "OpU";
    break;
    case 12:
      return "OpM";
    break;
    case 13:
      return "OpA";
    break;
    case 14:
      return "OpAtr";
    break;
    case 15:
      return "OpC";
    break;
    case 16:
      return "OpI";
    break;
    case 17:
      return "Atr";
    break;
    case 18:
      return "APar";
    break;
    case 19:
      return "FPar";
    break;
    case 20:
      return "Ponto";
    break;
    case 21:
      return "PV";
    break;
    case 22:
      return "ACol";
    break;
    case 23:
      return "FCol";
    break;
    case 24:
      return "AChaves";
    break;
    case 25:
      return "FChaves";
    break;
    case 26:
      return "Virgula";
    break;
    case 27:
      return "Inteiro";
    break;
    case 28:
      return "Decimal";
    break;
    case 29:
      return "Booleano";
    break;
    case 30:
      return "Caractere";
    break;
    case 31:
      return "ListaInt";
    break;
    case 32:
      return "ListaDec";
    break;
    case 33:
      return "ListaBool";
    break;
    case 34:
      return "ListaCarac";
    break;
    case 35:
      return "Inclua";
    break;
    case 36:
      return "Devolva";
    break;
    case 37:
      return "Constante";
    break;
    case 38:
      return "Caso";
    break;
    case 39:
      return "Seja";
    break;
    case 40:
      return "Vazio";
    break;
    case 41:
      return "ConstCarac";
    break;
    case 42:
      return "ConstLisCa";
    break;
    case 43:
      return "Comentario";
    break;
    case 44:
      return "Principal";
    break;
    default:
      return "ERRO!!!\a";
    
  }
}

void imprimeTodosOsTokens( Token *lista, int tamanho )
{
  int i;
  for( i = 0; i < tamanho; i ++ )
  {
    printf( "          [%04d, %04d] (%04d, %20s) (%s) )\n",
      lista[i].linha, lista[i].coluna, lista[i].categoriaDoToken, 
      calculadorNomeDaCategoria(lista[i].categoriaDoToken), lista[i].lexema );
  }
}



int main( int argc, char *argv[ ] )
{
  FILE *arq;
  char ch, lex[501];
  int lin, col, tamanhoLex = 0, tamanhoLis = 0;
  bool abriu = false, jaLeu;
  Token listaDeTokens[100];

  // Abre um arquivo TEXTO para LEITURA
  //printf("%d\n", argc);
  if( argc > 1 )
  {
    arq = fopen(argv[1], "rt");
  }else
  {
    arq = fopen("shellSort.tpq", "rt");
  }

  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return -1;
  }

  lin = 1;
  col = 1;
  ch=fgetc(arq);

  while( ch != EOF )
  {
    //printf("[%c]",ch);
    //printf("[%s]\n", lex);

    jaLeu = false;

    switch(ch)
    {
      case ';':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;

          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }
        
        listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = PV;

      break;
      case '(':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }
        
        listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = APar;
      break;
      case ')':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = FPar;
      break;
      case '[':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = AChaves;
      break;
      case ']':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = FChaves;
      break;
      case '\n':
        lin++;
        col = 1;
      break;
      case '!':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = OpU;
      break;
      case '=':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = Atr;
      break;
      case '*':
      case '/':
      case '%':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        lex[tamanhoLex++] = ch;
        lex[tamanhoLex] = '\0';


        ch=fgetc(arq);
        col++;

        if( ch == '\n' )
        {
          lin++;
        }

        if( ch == '=' )
        {
          printf("Entrou!\n");
          abriu = false;

          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';
          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = OpAtr;

          strcpy(lex, "\0");
          tamanhoLex = 0;
            
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }else
        {
          jaLeu = true;

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = OpM;

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;

          //lex[tamanhoLex++] = ch;
          //lex[tamanhoLex] = '\0';
        }

        printf("[%s]  [%d]  [%c]\n", lex, abriu, ch);
      case '+':
      case '-':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        lex[tamanhoLex++] = ch;
        lex[tamanhoLex] = '\0';


        ch=fgetc(arq);
        col++;

        if( ch == '\n' )
        {
          lin++;
        }

        if( ch == '=' )
        {
          //printf("Entrou!\n");
          abriu = false;

          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';
          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = OpAtr;

          strcpy(lex, "\0");
          tamanhoLex = 0;
            
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }else
        {
          jaLeu = true;

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = OpA;

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;



          //lex[tamanhoLex++] = ch;
          //lex[tamanhoLex] = '\0';
        }

        printf("[%s]  [%d]  [%c]\n", lex, abriu, ch);
      break;
      case '>':
      case '<':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        lex[tamanhoLex++] = ch;
        lex[tamanhoLex] = '\0';


        ch=fgetc(arq);
        col++;

        if( ch == '\n' )
        {
          lin++;
        }

        if( ch == '=' )
        {
          //printf("Entrou!\n");

          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';
          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = OpC;

          strcpy(lex, "\0");
          tamanhoLex = 0;
            
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }else
        {
          jaLeu = true;

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = OpC;

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;

          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';
        }

        printf("[%s]  [%d]  [%c]\n", lex, abriu, ch);
      break;
      case '|':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        lex[tamanhoLex++] = ch;
        lex[tamanhoLex] = '\0';


        ch=fgetc(arq);
        col++;

        if( ch == '\n' )
        {
          lin++;
        }

        if( ch == '|' )
        {
          //printf("Entrou!\n");

          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';
          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = OpI;

          strcpy(lex, "\0");
          tamanhoLex = 0;
            
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }else
        {
          jaLeu = true;

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = OpI;

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;

          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';
        }

        printf("[%s]  [%d]  [%c]\n", lex, abriu, ch);
      break;
      case '&':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        lex[tamanhoLex++] = ch;
        lex[tamanhoLex] = '\0';


        ch=fgetc(arq);
        col++;

        if( ch == '\n' )
        {
          lin++;
        }

        if( ch == '&' )
        {
          //printf("Entrou!\n");

          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';
          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = OpI;

          strcpy(lex, "\0");
          tamanhoLex = 0;
            
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }else
        {
          jaLeu = true;

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = OpI;

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;

          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';
        }

        printf("[%s]  [%d]  [%c]\n", lex, abriu, ch);
      break;
      case '{':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }
        
        listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = AChaves;
      break;
      case '}':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = FChaves;
      break;
      case ',':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;

          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }
        
        listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = Virgula;

      break;
      case '"':
        abriu = true;

        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        do
        {
          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';


          ch=fgetc(arq);

          if( ch == '\n' )
          {
            lin++;
          }

          if( ch == '\"' )
          {
            //printf("Entrou!\n");
            abriu = false;
          }

          col++;

          //printf("[%s]  [%d]  [%c]\n", lex, abriu, ch);
        }while( abriu && ch != EOF );

        lex[tamanhoLex++] = ch;
        lex[tamanhoLex] = '\0';
        strcpy(listaDeTokens[tamanhoLis].lexema, lex);
        listaDeTokens[tamanhoLis].categoriaDoToken = ConstLisCa;

        strcpy(lex, "\0");
        tamanhoLex = 0;
          
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis++].coluna = col - 1;
        
      break;
      case '\'':
        abriu = true;

        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        do
        {
          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';

          ch=fgetc(arq);

          if( ch == '\n' )
          {
            lin++;
          }

          if( ch == '\'' )
          {
            abriu = false;
          }

          col++;
        }while( !abriu && ch != EOF );

        lex[tamanhoLex++] = ch;
        lex[tamanhoLex] = '\0';
        strcpy(listaDeTokens[tamanhoLis].lexema, lex);
        listaDeTokens[tamanhoLis].categoriaDoToken = ConstCarac;

        strcpy(lex, "\0");
        tamanhoLex = 0;
          
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis++].coluna = col - 1;
        
      break;
      case '/*':
        abriu = true;

        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        do
        {
          lex[tamanhoLex++] = ch;
          lex[tamanhoLex] = '\0';

          if( ch == '\n' )
          {
            lin++;
          }

          if( ch == '*/' )
          {
            abriu = false;
          }

          col++;
        }while( !abriu && (ch=fgetc(arq))!= EOF );

        strcpy(listaDeTokens[tamanhoLis].lexema, lex);
        listaDeTokens[tamanhoLis].categoriaDoToken = Comentario;

        strcpy(lex, "\0");
        tamanhoLex = 0;
          
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis++].coluna = col - 1;
        
      break;
      case ' ':
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {
          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);


          printf("[%s]\n", lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        
        /*listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = FChaves;*/
      break;
      case 9:
        if( tamanhoLex != 0 ) //Ou seja, se tem um token antes
        {

          strcpy(listaDeTokens[tamanhoLis].lexema, lex);
          listaDeTokens[tamanhoLis].categoriaDoToken = calculadorTokenPalavraReservada(lex);

          strcpy(lex, "\0");
          tamanhoLex = 0;
          
          listaDeTokens[tamanhoLis].linha = lin;
          listaDeTokens[tamanhoLis++].coluna = col - 1;
        }

        /*listaDeTokens[tamanhoLis].lexema[0] = ch;
        listaDeTokens[tamanhoLis].lexema[1] = '\0';
        listaDeTokens[tamanhoLis].linha = lin;
        listaDeTokens[tamanhoLis].coluna = col;
        listaDeTokens[tamanhoLis++].categoriaDoToken = FChaves;*/
      break;
      default:
        lex[tamanhoLex++] = ch;
        lex[tamanhoLex] = '\0';
   }

   if( ch != EOF && !jaLeu )
   {
    ch=fgetc(arq);
    col++;
   }

   //col++;
  }
 
 printf("Existem %d linhas e %d colunas no arquivo\n", lin, col);
 imprimeTodosOsTokens( listaDeTokens, tamanhoLis );
 fclose(arq);
 
 return 0;
}
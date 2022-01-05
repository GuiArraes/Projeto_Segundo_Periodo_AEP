#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <conio.c> // Cor
//Tamanho do vetores das struct cad e cadMaq
#define SIZE_CAD 100
#define SIZE_MAQ 1001
//Estilo
#define SIZE_TOP 8
#define SIZE_TAB 4
#define SIZE_IGUAL 40 
//------------------------------------------------------------------------------
struct endereco {
       char logra[20], num[7], complemento[20], bairro[20], cidade[20], CEP[9];    
};
struct telefone {
       char celular[11];       
};
struct cadastro{
       int id;
       char nome[20], email[20], CPF[12], senha[10], senhaR[10];
       char tmp;
       struct endereco End;
       struct telefone Tel;       
};
struct cadastroMaq {
       int id;
       char nome[20], categoria[20], marca[20], modelo[20], ano[7], potencia[10];
       float valor; 
};
//------------------------------------------------------------------------------
//Variaveis Golobais
struct cadastro cad[SIZE_CAD];
struct cadastroMaq cadMaq[SIZE_MAQ];
int contMaq = 0;
//------------------------------------------------------------------------------
//Inicializando as Funções
/*Feito*/void diagramacao (int n, int z);
/*Feito*/void cadCliente();
/*Feito*/int validarEmail (char c[20], int *p);
/*Feito*/bool validarCPF (char cpf[15]);   
/*Feito*/bool comparacao (char compara[20], int tipo, int tmVetor);
/*Feito*/void cadMaquina ();
/*Feito*/void pesquisa ();
/*Feito*/void selection ();
/*Feito*/int procurarMaq();
/*Feito*/void quadrado (int x, int y, int altura, int largura);
/*Feito*/void divisaoTotal (int x, int y, int altura, int largura);
/*Feito*/void corFundo (int x, int y, int altura, int largura, int cor);
/*Feito*/void rodaPe ();
/*Feito*/void botao (int X, int Y, int corVoltar, int corConfirmar, char textEsq, char testDir);
/*Feito*/void margemPadrao (int refX, int cor, char frase[30]);
/*Feito*/void gridCadastro ();
/*Feito*/void gridMaquina ();
/*Feito*/void print ();  //FUNÇÃO SÓ PARA VER SE A LOGICA QUE EU CRIEI ESTA CORRETA
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//Programa Principal...
//------------------------------------------------------------------------------
int main (){
    //Não posso usar essa função por conta da biblioteca coin
    //setlocale(LC_ALL,"portuguese"); 
    system("mode con:cols=80 lines=25"); //Tamenho da tela padão 
    int op;
    int k;
 
    while (op != 0){
        system ("cls");
        quadrado (1,1,24,79); //Margens laterais
        quadrado (20,4,2,39);
        gotoxy (21,5);
        textbackground (4);
        printf ("         BEM VINDO A RENTagro         ");
        textbackground (0);
        quadrado (26,9,5,28); //Menu
        rodaPe();
        gotoxy (27,10);
        printf ("1 - Realizar Cadastro\n");
        gotoxy (27,11);
        printf ("2 - Cadastrar Maquinario\n");
        gotoxy (27,12);
        printf ("3 - Procurar por Maquinario\n");
        gotoxy (27,13);
        printf ("0 - Sair\n");
        gotoxy (27,15);
        printf ("Escolha uma opcao: ");
        scanf ("%d",&op);
        printf ("\a");
        switch (op){
               case 1: cadCliente(); break;
               case 2: cadMaquina(); break;
               case 3: pesquisa (); break;
               case 4: print (); break;
               case 0: break;
        }
    }
    system ("cls");
    
    margemPadrao (3, 4, "Volte Sempre!!!");    
    quadrado (22,10,2,32);
    gotoxy (25,11);        
    printf ("Obrigado!!! Volte sempre =)"); 
    gotoxy (20,13);            
    system ("pause");
return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//---------------Procedimento para a estilização das telas----------------------
//------------------------------------------------------------------------------
void quadrado (int x, int y, int altura, int largura){
    gotoxy (x,y); //Posição de referencia do quadrado (canto superior esquedo)
    //for para criar as duas COLUNAS
    for (int alfa=1; alfa<=altura; alfa++){
        //Coluna ESQUERDA
        gotoxy (x, y+alfa);
        printf("%c",186);
        //Coluna DIREITA
        gotoxy (x+largura, y+alfa);
        printf("%c",186);   
    }
    //for para ciar as duas LINHAS
    for (int alfa=1; alfa<=largura; alfa++){
        //Linha CIMA
        gotoxy (x+alfa, y);
        printf ("%c",205);      
        //Linha BAIXO
        gotoxy (x+alfa, y+altura);
        printf ("%c",205);    
    }
    //canto superior direito 187
    gotoxy (x+largura, y); 
    printf ("%c",187);
    //canto superior esquerdo 201
    gotoxy (x, y); 
    printf ("%c",201);
    //canto inferior esquerdo 200
    gotoxy (x,y+altura);
    printf ("%c",200);
    //canto inferior direito 188
    gotoxy (x+largura, y+altura);
    printf ("%c",188);   
}
//------------------------------------------------------------------------------
void divisaoTotal (int x, int y, int altura, int largura){
     
    gotoxy (x,y);
    for (int alfa=1; alfa<=largura; alfa++){
        //Linha 205
        gotoxy (x+alfa, y);
        printf ("%c",205);        
    }         
     //canto superior direito 185
     gotoxy (x+largura, y); 
     printf ("%c",185);
     //canto superior esquerdo 204
     gotoxy (x, y); 
     printf ("%c",204);        
}
//------------------------------------------------------------------------------
void corFundo (int x, int y, int altura, int largura, int cor){
     for (int i=x; i<=altura; i++){
        for (int j=y; j<=largura; j++){
            gotoxy(j,i);
            textbackground(cor);
            printf (" ");
        }
    }
    textbackground (0);    
}
//------------------------------------------------------------------------------
void margemPadrao (int refX, int cor, char frase[30]){
    
    refX = 31 - refX;
    system ("cls");
    quadrado (1,1,24,79); //Margens
    rodaPe (); //Rodapé
    //gotoxy (31,2);
    corFundo (2,2,2,79,4);
    gotoxy (refX,2);
    textbackground (cor);
    printf ("RENTagro - %s",frase);
    textbackground (0);
          
}
//------------------------------------------------------------------------------
void rodaPe (){
     divisaoTotal (1,22,1,79); //Linha rodapé
     gotoxy (3,23);
     printf ("RENTagro");
     gotoxy (3,24);
     printf ("Sobre a RENTagro | Fale conosco | Mapa do Site | Termos de uso");    
}
//------------------------------------------------------------------------------
void botao (int X, int Y, int corVoltar, int corConfirmar, char textEsq[15], char testDir[15]){

    quadrado (X,Y,2,13);
    gotoxy (X+1,Y+1);
    textbackground (corVoltar);
    printf ("%s",textEsq);
    textbackground (0);
    quadrado (X+14,Y,2,13);
    gotoxy (X+15,Y+1);
    textbackground (corConfirmar);
    printf ("%s",testDir);
    textbackground (0);
}
//------------------------------------------------------------------------------
void gridCadastro (){
    int refEsq, linhaEsq;
       
    margemPadrao (0, 4, "Cadastro");
    //Quadrado Esquerdo
    refEsq = 9;
    linhaEsq = 3;
    quadrado (refEsq,linhaEsq,10,31);
    divisaoTotal (refEsq,linhaEsq+2,5,31);
    divisaoTotal (refEsq,linhaEsq+4,5,31);
    divisaoTotal (refEsq,linhaEsq+6,5,31);
    divisaoTotal (refEsq,linhaEsq+8,5,31);
    
    gotoxy (10,4);
    printf ("Nome:");
    gotoxy (10,6);
    printf ("E-mail:");
    gotoxy (10,8);
    printf ("CPF:");
    gotoxy (10,10);
    printf ("Senha:");
    gotoxy (10,12);
    printf ("Repita Senha:");
    
    //Quadrado Direito
    int refDir, linhaDir;
    refDir = 41;
    linhaDir = 3;
    quadrado (refDir,linhaDir,10,31);
    divisaoTotal (refDir,linhaDir+2,5,31);
    divisaoTotal (refDir,linhaDir+4,5,31);
    divisaoTotal (refDir,linhaDir+6,5,31);
    divisaoTotal (refDir,linhaDir+8,5,31);
    //Divisão do número e CEP
    gotoxy (refDir+16,linhaDir+2);
    printf ("%c",203);
    gotoxy (refDir+16,linhaDir+3);
    printf ("%c",186);
    gotoxy (refDir+16,linhaDir+4);
    printf ("%c",202);
            
    gotoxy (refDir+1,linhaDir+1);
    printf ("Endereco:");
    gotoxy (refDir+1,linhaDir+3);
    printf ("Numero:");
    gotoxy (refDir+17,linhaDir+3);
    printf ("CEP:");
    gotoxy (refDir+1,linhaDir+5);
    printf ("Bairro:");
    gotoxy (refDir+1,linhaDir+7);
    printf ("Cidade:");
    gotoxy (refDir+1,linhaDir+9);
    printf ("Telefone:"); 
    
    botao (27,16,4,1," Voltar [0] ","Confirmar[1]"); //4 - Vermelho || 1 - Azul 
     
}
//------------------------------------------------------------------------------
void gridMaquina (){
    int refX = 18, refY = 6;
        
    margemPadrao (6, 4, "Cadastro de Maquinario");
    //Quadrado Centro
    quadrado (refX,refY,10,45);
    divisaoTotal (refX,refY+2,5,45);
    divisaoTotal (refX,refY+4,5,45);
    divisaoTotal (refX,refY+6,5,45);
    divisaoTotal (refX,refY+8,5,45);
    
    //Divisão Modelo e Marca
    gotoxy (refX+23,refY+4);
    printf ("%c",203);
    gotoxy (refX+23,refY+5);
    printf ("%c",186);
    
    //Divisão Potencia e Ano
    gotoxy (refX+23,refY+6);
    printf ("%c",206);
    gotoxy (refX+23,refY+7);
    printf ("%c",186);
    gotoxy (refX+23,refY+8);
    printf ("%c",202);
       
    gotoxy (refX+1,refY+1);
    printf ("Nome:");
    gotoxy (refX+1,refY+3);
    printf ("Categoria:");
    gotoxy (refX+1,refY+5);
    printf ("Modelo:");
    gotoxy (refX+24,refY+5);
    printf ("Marca:");
    gotoxy (refX+1,refY+7);
    printf ("Potencia:");    
    gotoxy (refX+24,refY+7);
    printf ("Ano:");
    gotoxy (refX+18,refY+9);
    printf ("VALOR:");  
    
    //Texto acima do botão
    gotoxy (refX+13, refY+11);
    fflush (stdin);
    gotoxy (refX+33, refY+11);
    printf (" ");
    gotoxy (refX+13, refY+11);
    //printf ("Escolha uma opcao...");
}
//------------------------------------------------------------------------------
//-----------------Procedimento e Funções das funcionalidades ------------------
//------------------------------------------------------------------------------
void cadCliente (){
     int textCenter = 40, linhaCentro = 14;
     int refEsq = 9, linhaEsq = 3;
     static int i;
     int op;

     gridCadastro ();
     if (i > SIZE_CAD){
        gotoxy (textCenter-20,linhaCentro+1);
        printf ("ERRO: Nao ha mais espaço para cadastro!!!\n");
     }else{
         gotoxy (refEsq-5,linhaEsq+1);
         cad[i].id = i;
         printf ("id:%d \n",i);    //SÓ PARA TESTAR O i
              
         fflush (stdin);
         gotoxy(refEsq+6,linhaEsq+1);
         gets (cad[i].nome);
         
         int flag = 0;
         int k = 0;
         bool flag2 = true;
         
         while (flag != 1 || k == 0 || flag2 == true){
             flag = 0;
             flag2 = true;
             fflush (stdin);
             
             gotoxy(refEsq+8,linhaEsq+3);
             printf ("                     ");

             gotoxy(refEsq+8,linhaEsq+3);
             gets (cad[i].email);
             
             //Verifica se tem um @ e pelo menos um ponto
             flag = validarEmail (cad[i].email, &k);
             if (flag < 1 || k == 0){
                gotoxy (textCenter-8,linhaCentro);
                printf ("E-mail INVALIDO!!!      ");
                gotoxy (textCenter-18,linhaCentro+1);
                printf ("Tem que ter um @ e pelo menos um ponto.");
             }
             flag2 = comparacao (cad[i].email, 1, i); 
             //1°email p/comparar, 2°Tipo comparação, 3°Tamanho vetor atual
             if (flag2 == true){
                  gotoxy (textCenter-18,linhaCentro+1);
                  printf ("                                            ");
                  gotoxy (textCenter-10,linhaCentro);
                  printf ("E-mail já cadastrado.\n");
               }  
         }
         gotoxy (textCenter-18,linhaCentro);
         printf ("                                            ");
         gotoxy (textCenter-18,linhaCentro+1);
         printf ("                                            ");
         
         bool valida = false;
         flag2 = true;
         while (not valida || flag2){   
               flag2 = true;
               
               gotoxy(refEsq+5,linhaEsq+5);
               printf ("                     ");
               
               fflush (stdin);
               gotoxy(refEsq+5,linhaEsq+5);
               gets (cad[i].CPF);
               
               //FUNÇÃO VALIDAR CPF passagem por parametro.
               valida = validarCPF (cad[i].CPF);
               if (valida == false ){
                  gotoxy (textCenter-12,linhaCentro);
                  printf ("                       ");
                  gotoxy (textCenter-12,linhaCentro);
                  printf ("CPF Informado INVALIDO.");
               }
               flag2 = comparacao (cad[i].CPF, 2, i);
               if (flag2 == true){
                  gotoxy (textCenter-8,linhaCentro);
                  printf ("                  ");
                  gotoxy (textCenter-8,linhaCentro);
                  printf ("CPF ja Cadastrado.     ");
               }
         }
         gotoxy (textCenter-18,linhaCentro);
         printf ("                                            ");
         do{
            do {
                 gotoxy(refEsq+7,linhaEsq+7);
                 printf ("                     ");
                 
                 fflush(stdin);
                 gotoxy(refEsq+7,linhaEsq+7);
                 gets (cad[i].senha);
                  
                 if (strlen(cad[i].senha) < 6){
                    gotoxy (textCenter-20,linhaCentro);
                    printf ("Senha tem que ter no minimo 6 caracter."); 
                 }
            }while (strlen(cad[i].senha) < 6);
            
            gotoxy (textCenter-20,linhaCentro);
            printf ("                                       ");
            
            gotoxy(refEsq+14,linhaEsq+9);
            printf ("             ");
            fflush (stdin);
            gotoxy(refEsq+14,linhaEsq+9);
            gets (cad[i].senhaR);

            if (strcmp (cad[i].senha,cad[i].senhaR) != 0){
               gotoxy (textCenter-20,linhaCentro);
               printf ("Senhas diretentes. Digite novamente.\n");

            }          
         }while (strcmp (cad[i].senha,cad[i].senhaR) != 0); 
         //As duas senhas têm que serem iguais.         
     
     int refDir, linhaDir;
     refDir = 41;
     linhaDir = 3;
     gotoxy (refDir+10,linhaDir+1);
     fflush (stdin);
     gets (cad[i].End.logra);
     gotoxy (refDir+8,linhaDir+3);
     fflush (stdin);
     gets (cad[i].End.num);
     gotoxy (refDir+21,linhaDir+3);
     fflush (stdin);
     gets (cad[i].End.CEP);
     gotoxy (refDir+8,linhaDir+5);
     fflush (stdin);
     gets (cad[i].End.bairro);
     gotoxy (refDir+8,linhaDir+7);
     fflush (stdin);
     gets (cad[i].End.cidade);
     gotoxy (refDir+10,linhaDir+9);
     fflush (stdin);
     gets (cad[i].Tel.celular);

     i++;
     }
     
     do{
         gotoxy (textCenter-10,linhaCentro);
         printf ("Escolha uma opcao...");
         gotoxy (textCenter+11,linhaCentro);
         scanf ("%d",&op);
         if (op == 0){
            i--;
         }
     }while (op != 0 && op != 1);
}
//------------------------------------------------------------------------------
int validarEmail (char c[20], int *p){
     int vali = 0;     
     int cont = 0;
     int tm;         
     
     *p = 0;
     tm = strlen (c);
     for (int i= 0; i<tm; i++){
         if (c[i] == '@'){
            vali = vali + 1;
         }
         else{
            if (c[i] == '.'){
               *p = *p + 1;
            }        
         }
     }
    return vali;    
}
//------------------------------------------------------------------------------
bool validarCPF (char cpf[11]){
     //TRABALHAR COM A TABELA ASCII
     int soma = 0;
     int verificar;
     char vetorCPF[11];
     //"Convertendo caracter em número"
     for (int y=0; y<=10; y++){ //Só foi ateé o índice 11 pq o '\0' não me intereça.
         vetorCPF[y] = (cpf[y] - 48); //48 é o valor ASCII para o caracter '0'
     }
     //Desta forma tenho os "números inteiro" do cpf digitado
     //Isto é, tem-se os numeros do cpf digitado ente 0-9 em cada posição do vetorCPF
       
     //Verificando o Digito 10
     for (int x=0; x<=8; x++){
         soma = soma + (vetorCPF[x] * (10-x)); //A "Conversão" é para usar aqui.
     }
     verificar = 11 - (soma%11);
     if (verificar > 9){
        verificar = 0;
     }
     else{
        verificar <- verificar; 
     }
     
     if (verificar != vetorCPF[9]){
        return false; //CPF invalido 
     } 
     //Verificando o Digito 11
     soma = 0;
     for (int x=0; x<=9; x++){
         soma = soma + (vetorCPF[x]*(11 - x));
     }
     
     verificar = 11 - (soma  % 11);
     if (verificar > 9) {
        verificar = 0;
     }
     else {
        verificar = verificar;
     }
     
     if (verificar == vetorCPF[10]){
        return true; //CPF valido
     }else{
        return false; //CPF invalido
     }         
}
//------------------------------------------------------------------------------
bool comparacao (char compara[12], int tipo, int tmVetor){
     //tipo = 1: analiza os e-mail
     //tipo = 2: analiza os cpf 
     bool flag;
     char comparaCPF[12];    
        
     switch (tipo){
            case 1:               
                 for (int x=0; x<tmVetor; x++){
                     if (strcmp (compara,cad[x].email) == 0){
                        return true;
                     }else{
                        flag = false;   
                     }  
                 }
                 return flag;
                 break;
            case 2:
                 strncpy (comparaCPF,compara,11);
                 comparaCPF[11] = '\0';    
                 for (int x=0; x<tmVetor; x++){
                     if (strcmp (comparaCPF,cad[x].CPF) == 0){
                        return true;
                     }else{
                        flag = false;   
                     }  
                 }
                 return flag;
                 break;
     }              
}
//------------------------------------------------------------------------------
void cadMaquina (){  
     static int j = 1;
     int op;
     char converter[20];
     int refX = 18, refY = 6;
         
     system ("cls");
     gridMaquina ();
     botao (27,18,4,1,"Cancelar [0]","Confirmar[1]");
                            
     gotoxy (refX+6, refY+1);
     fflush (stdin);
     gets (cadMaq[j].nome);

     //-----------------------------------------------------------
     //Guardando os nomes com TODOS os caracteres Maiusculo
     strcpy (converter,cadMaq[j].nome);
     for (int k=0; k<strlen(converter); k++){
         converter[k] = toupper(converter[k]);
     }
     strcpy (cadMaq[j].nome,converter);         
     //-----------------------------------------------------------
     gotoxy (refX+11, refY+3);
     fflush (stdin);
     gets (cadMaq[j].categoria);
     
     gotoxy (refX+8, refY+5); 
     fflush (stdin); 
     gets (cadMaq[j].modelo);
     
     gotoxy (refX+30, refY+5);
     fflush (stdin);
     gets (cadMaq[j].marca);
     
     gotoxy (refX+10, refY+7);
     fflush (stdin);
     gets(cadMaq[j].potencia);
     
     gotoxy (refX+28, refY+7);
     fflush (stdin);
     gets (cadMaq[j].ano);
     
     
     fflush (stdin);
     gotoxy (refX+24, refY+9);
     scanf ("%f",&cadMaq[j].valor); 
     
     j++;
     
     do{
         gotoxy (refX+13, refY+11);
         fflush (stdin);
         gotoxy (refX+33, refY+11);
         printf ("    ");
         gotoxy (refX+13, refY+11);
         fflush (stdin);
         printf ("Escolha uma opcao...");
         scanf ("%d",&op);
         if (op == 0){
            j--;
         }
     }while (op != 0 && op != 1);
     
     contMaq = j-1;
     selection ();  //Função para ordenar o vetor 
     //Pesquisar uma ordenação mais eficiente para a minha aplicação.
}
//------------------------------------------------------------------------------
void pesquisa (){
     int k;
     int refX = 18, refY = 6, op;

     k = procurarMaq ();
       if (k == -1){
          do{
              margemPadrao (0, 4, "Pesquisa");    
              quadrado (refX+4,refY+3,3,35);
              botao (refX+8,refY+8,4,1,"   Menu[0]  ","Pesquisar[1]"); 
                                                                                                                                           
              gotoxy (refX+5,refY+4);        
              printf ("Maquinario pesquisado ");
              textbackground (4);
              printf ("INDISPONIVEL"); 
              textbackground (0);        
              gotoxy (refX+12,refY+7);
              fflush (stdin);
              printf ("Escolha uma opcao...");
              scanf ("%d",&op);
              
              if (op == 1) pesquisa ();
              
          }while (op != 0 && op != 1);
       }
       else {
            gridMaquina ();
            botao (27,18,4,1,"   Menu[0]  ","Pesquisar[1]");      
            
            gotoxy (refX+1,refY+1);
            printf ("Nome:%s",cadMaq[k].nome);
            gotoxy (refX+1,refY+3);
            printf ("Categoria:%s",cadMaq[k].categoria);
            gotoxy (refX+1,refY+5);
            printf ("Modelo:%s",cadMaq[k].modelo);
            gotoxy (refX+24,refY+5);
            printf ("Marca:%s",cadMaq[k].marca);
            gotoxy (refX+1,refY+7);
            printf ("Potencia:%s",cadMaq[k].potencia);    
            gotoxy (refX+24,refY+7);
            printf ("Ano:%s",cadMaq[k].ano);
            gotoxy (refX+18,refY+9);
            printf ("VALOR:%.2f",cadMaq[k].valor); 
            
            do{
               gotoxy (refX+13, refY+11);
               fflush (stdin);
               gotoxy (refX+33, refY+11);
               printf (" ");
               gotoxy (refX+13, refY+11);
               fflush (stdin);
               printf ("Escolha uma opcao...");
               scanf ("%d",&op);
             }while (op != 0 && op != 1);
             
             if (op == 1) pesquisa();         
            
            //gotoxy (refX,refY+11);
            //system ("pause");               
        } 
}
//------------------------------------------------------------------------------
void selection (){ //Selection Short
     struct cadastroMaq comp; 
     
     for (int i=0; i<=contMaq-1; i++){
         for (int j=i+1; j<=contMaq; j++){
             if (strcmp(cadMaq[j].nome, cadMaq[i].nome) < 0){
                comp = cadMaq[i];
                cadMaq[i]=cadMaq[j];
                cadMaq[j]=comp;
             }           
         }         
     }  
}
//------------------------------------------------------------------------------
int procurarMaq (){          //BUSCA BINARIA
    int ini, fim, meio, p = 0;                
    char pesquisa[20];
    int refX = 25, refY = 9, op;
    
       margemPadrao (0, 4, "Pesquisa");    
       quadrado (refX,refY,3,29);
       botao (refX+1,refY+5,4,1,"   Menu[0]  ","Pesquisar[1]");
       gotoxy (refX+1,refY+1);
       fflush (stdin);
       printf ("Nome do maquinario desejado?");
       gotoxy (refX+8,refY+2);
       gets (pesquisa);
       //strcpy (*pv, pesquisa);
    do{
       gotoxy (refX+24,refY+4);
       printf ("    ");
       gotoxy (refX+4,refY+4);
       fflush (stdin);
       printf ("Escolha uma opcao...");
       scanf ("%d",&op);     
    }while (op != 0 && op != 1);
    
    if (op == 0) main(); 

    // TODOS os caracteres da pesquisa maiusculo.
    for (int k=0; k<strlen(pesquisa); k++){
        pesquisa[k] = toupper(pesquisa[k]);
    }
    ini = 1;
    fim = contMaq;
    while (ini <= fim){
          meio = (ini+fim)/2;
          //printf ("valor meio: %d\nmeio: %s\npesquisa: %s\n",meio, cadMaq[meio].nome, pesquisa);
          if (strcmp(cadMaq[meio].nome,pesquisa) == 0){
             p = meio;
             return p;//retorna a posição que a maquina buscada esta no vetor cadMaq
          }else{
              if (strcmp(pesquisa, cadMaq[meio].nome) < 0){ 
                 fim = meio - 1;
                 //printf ("fim - meio - 1\n\n"); 
                 //system ("pause");            
              }
              else {
                   ini = meio + 1;
                   //printf ("ini = meio + 1\n\n");
                   //system ("pause");
              }
          }                  
    }
    return -1; // retorna -1 se a maquina buscada não fazer parte do vetor cadMaq[j].nome  
}
//------------------------------------------------------------------------------
//FUNÇÃO SÓ PARA VER SE A LOGICA QUE EU CRIEI ESTA CORRETA
void print (){
     system ("cls");
     int j = 0;
     //for (int j=1; j<=contMaq; j++){
         //printf ("contMaq: %d\n",contMaq);
         printf ("%s \n",cad[j].End.logra);
         printf ("%s \n",cad[j].End.num);
         printf ("%s \n",cad[j].End.CEP);
         printf ("%s \n",cad[j].End.bairro);
         printf ("%s \n",cad[j].End.cidade);
         printf ("%s \n",cad[j].Tel.celular);
         //printf ("%.2f \n",cad[j]);
     //}
     system ("pause");
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
//Tamanho do vetores das struct cad e cadMaq
#define SIZE_CAD 100
#define SIZE_MAQ 1001
//Estilo
#define SIZE_TOP 8
#define SIZE_TAB 4
#define SIZE_IGUAL 40 

/*                     IDAIA PARA MELHORAR O CÓDIGO (se der tempo) - 26/08/21
      Utilizar o variavel id da (struct cadastro) para linkar os maquinários fornecido pelo usuário
      OBS: o id já esta implementado, amarzenando a posição do nome no vetor da (struct cadastro cad)
      Como fazer...
      Quando alguem for add um novo maquinário perguntar o nome.
      buscar pelo nome se existe, caso sim, pegar o id relacionado a esse nome
      add esse id ao maquinário que esta sendo adicionado a lista.
      
      Quando buscar por maquinário, trazer tmb o nome da pessoa que add o maquinário a lista    
*/
//Implementar as Struct> endereco, telefone com a nova forma de escrever em C
//Com a materia vista no dia 08/09/21 em Algoritmo e Logica de Programação II
//------------------------------------------------------------------------------
struct endereco {
       char logra[20], num[7], complemento[20], bairro[20], cidade[20];
       int CEP;    
};
struct telefone {
       int celular[11];       
};
struct cadastro{
       int id;
       char nome[20], email[20], CPF[12], senha[10], senhaR[10];
       char tmp;
       struct endereco Endereco;
       struct telefone Telefone;       
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
/*Feito*/void topo ();
/*Feito*/void cadCliente();
/*Feito*/int validarEmail (char c[20], int *p);
/*Feito*/bool validarCPF (char cpf[15]);   
/*Feito*/bool comparacao (char compara[20], int tipo, int tmVetor);
/*Feito*/void cadMaquina ();
/*Feito*/void pesquisa ();
/*Feito*/void selection ();
/*Feito*/int procurarMaq();
/*Feito*/void print ();  //FUNÇÃO SÓ PARA VER SE A LOGICA QUE EU CRIEI ESTA CORRETA

//Fazer para a proxima entrega
void listarMaquinas ();//Mostrar lista dos maquinarios com: nome, valor, potencia...
void deletarMaquina ();//Deletar algum maquinario do vetor cadMaq;
//Vai ser complicado, pq tem que ajustar o vetor para não ficar com valores NULL entre
//valores preenchidos.

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//Programa Principal...
//------------------------------------------------------------------------------
int main (){
    setlocale(LC_ALL,"portuguese");
    system("mode con:cols=120 lines=40"); //Tamenho da tela padão 
    //(tem que ver se é esse o comando esta certo)
    int opi;
    int k;
    
    strcpy (cadMaq[1].nome, "Carro");
    strcpy (cadMaq[2].nome, "Colheitadeira");
    strcpy (cadMaq[3].nome, "Plantadeira");
    strcpy (cadMaq[4].nome, "Trator");
 
    while (opi != 0){
        system ("cls");
        topo();
        diagramacao (1,0);
        diagramacao (2,0);
        diagramacao (4,0);
        printf ("\n");
        diagramacao (2,0);
        printf ("1 - Realizar Cadastro\n");
        diagramacao (2,0);
        printf ("2 - Cadastrar Maquinario\n");
        diagramacao (2,0);
        printf ("3 - Procurar por Maquinário\n");
        diagramacao (2,0);
        printf ("0 - Sair\n");
        diagramacao (2,0);
        diagramacao (4,0);
        diagramacao (2,0);
        printf ("Escolha uma opção: ");
        scanf ("%d",&opi);
        switch (opi){
               case 0: break;
               case 1: cadCliente(); break;
               case 2: cadMaquina(); break;
               case 3: pesquisa (); break;
        }
    }
    system ("cls");
    topo ();
    diagramacao (1,0);
    diagramacao (2,1);
    diagramacao (3,-15);
    diagramacao (2,1);
    printf ("Obrigado!!! Volte sempre =)\n");
    diagramacao (2,1); 
    diagramacao (3,-15);
    diagramacao (1,0);       
             
    system ("pause");
return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void diagramacao (int n, int z){
     switch (n){
            case 1:                              //PARA PULAR LINHAS
                for (int x= 0; x<=SIZE_TOP + z; x++){
                    printf ("\n");
                } 
                break;
            
            case 2:                              //PARA COLOCAR TAB
               for (int x=0; x<=SIZE_TAB + z; x++){
                   printf ("\t");
               }
               break;
            
            case 3:
                 for (int x=0; x<=SIZE_IGUAL + z; x++){
                     printf ("=");
                 }      
                 printf ("\n");
                 break;
            case 4:
                 for (int x=0; x<=SIZE_IGUAL + z; x++){
                     printf ("_");
                 }      
                 printf ("\n");
                 break;
     }   
}
//------------------------------------------------------------------------------
void topo (){
     system ("cls");
     system ("color F0"); //Muda a cor do fundo e letra ("color(fundo)(letra)") Hexadecimal*** 
     //printf ("\t\t\t\t\t\t\t\t\t\t\t    AJUDA  CADASTRA-SE  ENTRAR");
     printf(" _____  ______ _   _ _______                      \n");
     printf("|  __ \\|  ____| \\ | |__   __|                   \n");                   
     printf("| |__) | |__  |  \\| |  | | __ _  __ _ _ __ ___  \n");  
     printf("|  _  /|  __| | . ` |  | |/ _` |/ _` | '__/ _ \\ \n");
     printf("| | \\ \\| |____| |\\  |  | | (_| | (_| | | | (_) |\n");
     printf("|_|  \\_\\______|_| \\_|  |_|\\__,_|\\__, |_|  \\___/ \n");
     printf("                                 __/ |          \n");          
     printf("                                |___/           \n");
}
//------------------------------------------------------------------------------
void cadCliente (){
     static int i;
   
     topo();
     diagramacao (1,0); 
     if (i > SIZE_CAD){
        diagramacao (2,0);
        printf ("ERRO: Não há mais espaço para cadastro!!!\n");
     }else{
         cad[i].id = i;
         /*diagramacao (2,0);
         printf ("id:%d \n",i);    //SÓ PARA TESTAR O i
         */
         fflush (stdin);
         diagramacao (2,0);
         diagramacao (4,0);
         diagramacao (2,0);
         printf ("Nome          : ");
         gets (cad[i].nome);
         diagramacao (2,0);
         diagramacao (3,0);
         
         int flag = 0;
         int k = 0;
         bool flag2 = true;
         while (flag != 1 || k == 0 || flag2 == true){
             flag = 0;
             flag2 = true;
             fflush (stdin);
             diagramacao (2,0);
             printf ("E-mail        : ");
             gets (cad[i].email);
             
             //Verifica se tem um @ e pelo menos um ponto
             flag = validarEmail (cad[i].email, &k);
             if (flag < 1 || k == 0){
                diagramacao (2,1);
                printf ("     E-mail INVALIDO!!!\n");
                diagramacao (2,0);
                printf ("Tem que ter um @ e pelo menos um ponto.\n");
             }
             flag2 = comparacao (cad[i].email, 1, i); 
             //1°email p/comparar, 2°Tipo comparação, 3°Tamanho vetor atual
             if (flag2 == true){
                  diagramacao (2,0);
                  printf ("E-mail já cadastrado.\n");
               }  
             diagramacao (2,0);
             diagramacao (3,0);
         }
         
         bool valida = false;
         flag2 = true;
         while (valida == false || flag2 == true){   
               flag2 = true;
               fflush (stdin);
               diagramacao (2,0);
               printf ("CPF           : ");
               gets (cad[i].CPF);
               
               //FUNÇÃO VALIDAR CPF passagem por parametro.
               valida = validarCPF (cad[i].CPF);
               if (valida == false ){
                  diagramacao (2,0);
                  printf ("CPF informado INVALIDO.\n");
               }
               flag2 = comparacao (cad[i].CPF, 2, i);
               if (flag2 == true){
                  diagramacao (2,0);
                  printf ("CPF já cadastrado.\n");
               }
         }          
         diagramacao (2,0);
         diagramacao (3,0);
         do{
            do {
                 fflush(stdin);
                 diagramacao (2,0);
                 printf ("Senha         : ");
                 gets (cad[i].senha);
                 diagramacao (2,0);
                 diagramacao (3,0);
                 if (strlen(cad[i].senha) < 6){
                     diagramacao (2,0);
                     printf ("Senha tem que ter no minimo 6 caracter.\n"); 
                     diagramacao (2,0);
                     diagramacao (3,0); 
                 }
            }while (strlen(cad[i].senha) < 6);
            
            fflush (stdin);
            diagramacao (2,0);
            printf ("Repetir Senha : ");
            gets (cad[i].senhaR);
            diagramacao (2,0);
            diagramacao (4,0);
            if (strcmp (cad[i].senha,cad[i].senhaR) != 0){
               diagramacao (2,0);
               printf ("Senhas diretentes. Digite novamente.\n");
               diagramacao (2,0);
               diagramacao (3,0);
            }
                  
         }while (strcmp (cad[i].senha,cad[i].senhaR) != 0); 
         //As duas senhas têm que serem iguais.
     i++;
     }
     diagramacao (2,0);
     system ("pause");
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
     char op;
     char converter[20];
     do {
         system ("cls");
         topo();
         diagramacao (1,0);
         diagramacao (2,0);
         diagramacao (4,0);
         printf ("\n");
         
         fflush (stdin);
         diagramacao (2,0);
         printf ("Nome do Maquinário      : ");
         gets (cadMaq[j].nome);
         diagramacao (2,0);
         diagramacao (3,0);
         //-----------------------------------------------------------
         //Guardando os nomes com TODOS os caracteres Maisculo
         strcpy (converter,cadMaq[j].nome);
         for (int k=0; k<strlen(converter); k++){
             converter[k] = toupper(converter[k]);
         }
         strcpy (cadMaq[j].nome,converter);         
         //-----------------------------------------------------------
         fflush (stdin);
         diagramacao (2,0);
         printf ("Categoria do Maquinário : ");
         gets (cadMaq[j].categoria);
         diagramacao (2,0);
         diagramacao (3,0);
         
         fflush (stdin);
         diagramacao (2,0);
         printf ("Marca do Maquinário     : ");
         gets (cadMaq[j].marca);
         diagramacao (2,0);
         diagramacao (3,0);

         fflush (stdin);
         diagramacao (2,0);
         printf ("Modelo do Maquinário    : ");
         gets (cadMaq[j].modelo);
         diagramacao (2,0);
         diagramacao (3,0);
         
         fflush (stdin);
         diagramacao (2,0);
         printf ("Ano do Maquinário       : ");
         gets (cadMaq[j].ano);
         diagramacao (2,0);
         diagramacao (3,0);
         
         fflush (stdin);
         diagramacao (2,0);
         printf ("Potência do Maquinário  : ");
         gets(cadMaq[j].potencia);
         diagramacao (2,0);
         diagramacao (3,0);
         
         fflush (stdin);
         diagramacao (2,0);
         printf ("Valor por hora       R$: ");
         scanf ("%f",&cadMaq[j].valor); 
         diagramacao (2,0);
         diagramacao (4,0);
         
         j++;
         
         fflush (stdin);
         diagramacao (2,0);
         printf ("Digite [S] para continuar cadastrando: ");
         scanf ("%c",&op);
         op = toupper(op);              
     }while (op == 'S');     
     
     contMaq = j-1;
     selection ();  //Função para ordenar o vetor 
     //Pesquisar uma ordenação mais eficiente para a minha aplicação.
}
//------------------------------------------------------------------------------
void pesquisa (){
     int k;
     topo ();
     k = procurarMaq ();
       if (k == -1){
          diagramacao (2,0);
          printf ("Maquinário pesquisado INDISPONÍVEL\n");
          diagramacao (2,0);
          diagramacao (4,0);
          diagramacao (2,0);
          system ("pause");
       }
       else {
          diagramacao (2,0);
          printf ("\n");
          diagramacao (2,0);
          printf ("Nome do Maquinário      : %s\n",cadMaq[k].nome);
          diagramacao (2,0);
          printf ("Categoria do Maquinário : %s\n",cadMaq[k].categoria);
          diagramacao (2,0);
          printf ("Marca do Maquinário     : %s\n",cadMaq[k].marca);
          diagramacao (2,0);
          printf ("Modelo do Maquinário    : %s\n",cadMaq[k].modelo);
          diagramacao (2,0);
          printf ("Ano do Maquinário       : %s\n",cadMaq[k].ano);
          diagramacao (2,0);
          printf ("Potência do Maquinário  : %s\n",cadMaq[k].potencia);
          diagramacao (2,0);
          printf ("Valor por hora          : %.2f\n",cadMaq[k].valor);
          diagramacao (2,0);
          diagramacao (4,0);
          diagramacao (2,0);
          system ("pause");               
        }  
}
//------------------------------------------------------------------------------
void selection (){
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

    fflush (stdin);
    diagramacao (1,0);
    diagramacao (2,0);
    diagramacao (4,0);
    diagramacao (2,0);
    printf ("Nome do maquinario desejado? ");
    gets (pesquisa);
    diagramacao (2,0);
    diagramacao (4,0);
    
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
     //system ("cls");
     for (int j=1; j<=contMaq; j++){
         printf ("contMaq: %d\n",contMaq);
         printf ("%s \n",cadMaq[j].nome);
         printf ("%s \n",cadMaq[j].categoria);
         printf ("%s \n",cadMaq[j].marca);
         printf ("%s \n",cadMaq[j].modelo);
         printf ("%s \n",cadMaq[j].ano);
         printf ("%s \n",cadMaq[j].potencia);
         printf ("%.2f \n",cadMaq[j].valor);
     }
     system ("pause");
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> // função strlen(char) - conta caracteres
                    //função strcpy(char) - copia caracter
struct endereco {
       char logra[20], num[7], complemento[20], bairro[20], cidade[20];
       int CEP;    
};
struct telefone {
       int celular[11];       
};
struct cadastro{
       char nome[20], email[20], CPF[15], senha[10], senhaR[10];
       //int senha;
       //int senhaR;
       struct endereco Endereco;
       struct telefone Telefone;       
};
//------------------------------------------------------------------------------
struct cadastroMaq {
       char nomeMaq[20], catMaq[20], marMaq[20], modMaq[20], anoMaq[7], potMaq[10];
       //int anoMaq;
       //int potMaq; 
};
//------------------------------------------------------------------------------
//Variaveis Golobais
struct cadastro cad;
//------------------------------------------------------------------------------

void cadCliente();
void enterCadCliente (int c);

void cadMaquina (int M);

void diagramacao (int n);
void topo ();
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int main (){
    setlocale(LC_ALL,"portuguese");
    
    
    system("mode con:cols=120 lines=40"); //Tamenho da tela
    


    cadCliente ();
    //cadMaquina (1);

    system ("pause");
return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void diagramacao (int n){
     for (int x= 0; x<=n; x++){
         printf ("\n");
     }
}
//------------------------------------------------------------------------------
void topo (){
     system ("cls");
     system ("color F0"); //Muda a cor do fundo e letra ("color(fundo)(letra)") Hexadecimal*** 
     
     printf ("RENTagro\t\t\t\t\t\t\t\t\t\t    AJUDA  CADASTRA-SE  ENTRAR\n");
     
     /*
     printf(" _____  ______ _   _ _______                    \n");                    
     printf("|  __ \|  ____| \ | |__   __|                   \n");                   
     printf("| |__) | |__  |  \| |  | | __ _  __ _ _ __ ___  \n");  
     printf("|  _  /|  __| | . ` |  | |/ _` |/ _` | '__/ _ \ \n");
     printf("| | \ \| |____| |\  |  | | (_| | (_| | | | (_) |\n");
     printf("|_|  \_\______|_| \_|  |_|\__,_|\__, |_|  \___/ \n");
     printf("                                 __/ |          \n");          
     printf("                                |___/           \n");
     */

}
//------------------------------------------------------------------------------
void cadCliente (){
     topo();
     diagramacao (10);
     
     /*
      memset (&cad.nome, 0, sizeof (cad.nome) ); //Limpa a memória de mod.nome ...
      memset (&cad.email, 0, sizeof (cad.email) );
      memset (&cad.CPF, 0, sizeof (cad.CPF) );
      memset (&cad.senha, 0, sizeof (cad.senha) );
      memset (&cad.senhaR, 0, sizeof (cad.senhaR) );
     */
     //for (int i=0; i<=N; i++){
         fflush (stdin);
         printf ("\t\t\t\t\t________________________________________\n");
         printf ("\t\t\t\t\tNome          :%s \n",cad.nome);
         //gets (cad[i].nome);
         printf ("\t\t\t\t\t========================================\n");
         
         fflush (stdin);
         printf ("\t\t\t\t\tE-mail        :%s \n",cad.email);
         //gets (cad[i].email);
         //Validar e-mail
         printf ("\t\t\t\t\t========================================\n");
         
         fflush (stdin);
         printf ("\t\t\t\t\tCPF           :%s \n",cad.CPF);
         //gets (cad[i].CPF);
         printf ("\t\t\t\t\t========================================\n");
     //Função para validar o CPF
         // do{
             fflush(stdin);
             printf ("\t\t\t\t\tSenha         :%s \n",cad.senha);
             //scanf ("%d",&cad.senha);
             //gets (cad[i].senha);
             printf ("\t\t\t\t\t========================================\n");
             
             fflush (stdin);
             printf ("\t\t\t\t\tRepetir Senha :%s \n",cad.senhaR);
             //scanf ("%d",&cad.senhaR);
             //gets (cad[i].senhaR);
             printf ("\t\t\t\t\t________________________________________\n");     
         //}while ((cad.senha) != (cad.senhaR)); //As duas senhas tem que serem iguais.

            for (int c=1; c<=5; c++){ 
                enterCadCliente (2);
            }
 
     //}    
}
//------------------------------------------------------------------------------
void enterCadCliente (int c){         
         switch (c){
                case 1: 
                     printf ("\n\t\t\t\t\tNome:");
                     gets (cad.nome);
                     break; 
                case 2:
                     int contEmail = 0;
                     char validaEmail; //Pegar um caracter por vez
                     do {
                        system ("cls");
                        cadCliente (); 
                        printf ("\n\t\t\t\t\tE-mail:");
                        gets (cad.email);
                     }while (contEmail >= 2);
                     break;
                case 3:
                     printf ("\n\t\t\t\t\tCPF:");
                     gets (cad.nome);
                     break;
                case 4:
                     printf ("\n\t\t\t\t\tSenha:");
                     gets (cad.senha);
                     break;
                case 5:
                     printf ("\n\t\t\t\t\tRepetir Senha:");
                     gets (cad.senhaR);
                     break;
         }     
}
//------------------------------------------------------------------------------
void cadMaquina (int M){
     printf ("%d \n",M);
     struct cadastroMaq cadMaq[M];
     for (int i=0; i<=M; i++){
         printf ("%d",i);
         fflush (stdin);
         printf ("Nome do Maquinário: \n");
         //gets (cadMaq[i].nomeMaq);
         
         fflush (stdin);
         printf ("Categoria do Maquinário: \n");
         //gets (cadMaq[i].catMaq);
         
         fflush (stdin);
         printf ("Marca do Maquinário: \n");
         //gets (cadMaq[i].marMaq);
         //Tem um erro aqui********************************************
         fflush (stdin);
         printf ("Modelo do Maquinário: \n");
         //gets (cadMaq[i].modMaq);
         
         fflush (stdin);
         printf ("Ano do Maquinário: \n");
         //gets (cadMaq[i].anoMaq); 
         
         fflush (stdin);
         printf ("Potência do Maquinário: \n");
         //gets(cadMaq[i].potMaq);     
         /*
         fflush (stdin);
         printf ("Ano do Maquinário: ");
         scanf ("%d",cadMaq[i].anoMaq);
         fflush (stdin);
         printf ("Potência do Maquinário: ");
         scanf ("%d",cadMaq[i].potMaq);
         */
     }
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//Cadastro
/* TEM ERRO AQUIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII Duvida professor!!!!!
   printf ("Nome: ");
   gets (cad[i] -> nome);
   validoE = true;
/*
   int validoE;
   do{
      validoE = 0;
      printf ("Email: ");
      gets (cad[i].email);
      for (int x=0; x <= strlen(cad[i].email); x++){
          if (strcpy('@',ad[i].email) == '@' || strcpy('.',cad[i].email) == '.'){
             validoE == validoE + 1;
          }  
      } 
   }while (validoE >= 2);
     
*/

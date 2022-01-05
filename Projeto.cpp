#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> // função strlen(char) - conta caracteres
                    //função strcpy(char) - copia caracter


struct endereco {
       char logra[20];
       int CEP;
       char num[7];
       char complemento[20];
       char bairro[20];
       char cidade[20];     
};

struct telefone {
       int celular[11];       
};

struct cadastro{
       char nome[20];
       char email[20];
       int CPF[15];
       //int senha;
       //int senhaR;
       char senha[10];
       char senhaR[10];
       struct endereco Endereco;
       struct telefone Telefone;       
};
//------------------------------------------------------------------------------
void cadastro();
void busca ();
void lendoCadastro ();
//------------------------------------------------------------------------------
int main (){
    setlocale(LC_ALL,"portuguese");
    
    //cadastro ();
    //busca ();
    lendoCadastro ();
    
    
    //system ("cls");
    printf ("---------------------");
    for (int i=0; i<=30; i++){
        printf ("%s", textoNome[i]);
    }
    

system ("pause");
return 0;
}
//------------------------------------------------------------------------------
void cadastro (){
     //int x;
     FILE *cadastroCliente;
     cadastroCliente = fopen ("CadastroCliente.txt","a");
     struct cadastro cad;
     
     if (cadastroCliente == NULL){
        printf ("Erro: O Arquivo 'Cadastro Cliente' não foi aberto!\n");
     }

     
     printf ("Nome: ");
     gets (cad.nome);


  // do{
         fflush(stdin);
         printf ("Senha: ");
         //scanf ("%d",&cad.senha);
         gets (cad.senha);

         printf ("Repetir Senha: ");
         //scanf ("%d",&cad.senhaR);
         gets (cad.senhaR);     
   //}while ((cad.senha) != (cad.senhaR)); //As duas senhas tem que serem iguais.
   
   int k;
   k = fputs (cad.nome, cadastroCliente);
   k = fputs (cad.senha, cadastroCliente); //Armazena STRING no Formato: txt.
   k = fputs ("\n", cadastroCliente);
   if (k == EOF){
      printf ("Erro ao gravar os Dados no arquivo 'CadastroCliente'!");
   }

   //fwrite (&cad,sizeof(struct cadastro),1,cadastroCliente);   //Armazena um Bloco de Dados Formato: Binario
   fclose (cadastroCliente);

}
//------------------------------------------------------------------------------
void busca (){
     FILE *cadastroCliente;
     cadastroCliente = fopen ("CadastroCliente.txt","r");
     
     if (cadastroCliente == NULL){
        printf ("Erro: O Arquivo 'Cadastro Cliente' não foi aberto!\n");
     }
     
     char leitura[30];
     
     //fgets(leitura,)
     
     fclose (cadastroCliente);
     /*
     struct cadastro cad; 
     printf ("-----------\n");
     while (fread (&cad,sizeof(struct cadastro),1,cadastroCliente)==1){
           printf ("%d \n",cad.senha);
     }
     printf ("-----------\n"); 
     */    
}
//------------------------------------------------------------------------------

/* Essa ideia não da certo!!!
void lendoCadastro (){
     FILE *cadastroCliente;
   
    char textoNome[30]; //Amarzenar os nomes que são do arquivo CadastroCliente.
    char texto [30];
     
     cadastroCliente = fopen ("CadastroCliente.txt","r");
     for (int i=0; i<=30; i++){
         fgets(texto,30,cadastroCliente);
         textoNome [i] = texto;
     }
     fclose (cadastroCliente);
}
*/






































         //p -> senhaR = x;
//printf ("\n\n%d \n\n",p -> senhaR);   //TESTESSSS





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
     
   printf ("CPF: ");
   scanf ("%1d",&cad[i].CPF);
   //fflush (stdin);
   validaCPF(cad[i].CPF);
*/

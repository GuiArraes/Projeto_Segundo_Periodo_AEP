#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> // função strlen(char) - conta caracteres
                    //função strcpy(char) - copia caracter
struct end {
       char logra[20];
       int CEP;
       char num[7];
       char complemento[20];
       char bairro[20];
       char cidade[20];     
};

struct tel {
       int celular[11];       
};

struct cadastro{
       char nome[20];
       char email[20];
       int CPF[11];
       int senha;
       int senhaR;
       struct end Endereco;
       struct tel telefone;       
};
//------------------------------------------------------------------------------
int validaCPF (int cCPF){
    int soma;
 
//Primeiro número verificador
    soma = 0;
    for (int x= 1; x<=9; x++){
        //soma = soma + (vCPF[x]*(11-x));
    }
}
//------------------------------------------------------------------------------
void cadastro (struct cadastro *p){
     int x;
     FILE *cadastroCliente;
     cadastroCliente = fopen ("CadastroCliente.txt","w");

//As duas senhas tem que serem iguais.
   while ((p -> senha) != (p -> senhaR)){ //Esta apontando para dois endereço de memoria distinto.
         
         printf ("Senha: ");
         scanf ("%d",&x);
         p -> senha = x;
//printf ("\n\n%d \n\n",p -> senha);    //TESTESSSS
         printf ("Repetir Senha: ");
         scanf ("%d",&x);
         p -> senhaR = x;
//printf ("\n\n%d \n\n",p -> senhaR);   //TESTESSSS
   }
   fwrite (&x,sizeof(struct cadastro),1,cadastroCliente);
   fclose (cadastroCliente);

}
//------------------------------------------------------------------------------
int main (){
    setlocale(LC_ALL,"portuguese");
    

    struct cadastro cad;
    cadastro (&cad); //Passagem por referencia




    
system ("pause");
return 0;
}






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

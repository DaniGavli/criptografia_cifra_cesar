#include <stdio.h>
#include <string.h>
#include <locale.h>

// Ex: $<script> <arquivo.txt> <chave> <criptografar ou decriptografar>
 
 	        FILE *arq_base;
			FILE *arq_criptografado;
    		char nome_arq[50], nome[50], cripto_descripto[30], chave[30], chave2[30];
    		char caractereInicial, caractereCripto;
    		int opcao;
void main() {
   
   setlocale(LC_ALL, "Portuguese");

    do {
        printf("Escolha: (1. Criptografar - 2. Descriptografar - 3. Sair) - Opção: ");
        scanf("%d", &opcao);
        
        if(opcao == 1 ) { 
            funcaoCripto3();
        	
} 
  		else if(opcao== 2) {
         	funcaoDecripto3();
}
		
		
		pause();    
		system("clear || cls");

      } while(opcao != 3);

}



void funcaoCripto3(){
			int posicoes=4;
				 printf("Informe o nome do arquivo txt a ser criptografado: ");
            scanf("%s", nome);
             printf("Crie uma senha p/ o arquivo txt a ser criptografado: ");
            scanf("%s", chave);
			
            strcpy(nome_arq, nome);
            strcat(nome_arq, ".txt");

            arq_base = fopen(nome_arq, "r");
            if(arq_base == NULL) {
                printf("Falha ao abrir arquivo (%s)", nome_arq);
            } else {
                strcpy(nome_arq, nome);
                strcat(nome_arq, "_cripto.txt");
                arq_criptografado = fopen(nome_arq, "w");
  			
                 while((caractereInicial = fgetc(arq_base)) != EOF) {
                        caractereCripto = caractereInicial + posicoes;
                        fputc(caractereCripto, arq_criptografado);
                    }

                    printf("\nArquivo criado %s - %s \n", cripto_descripto, nome_arq);

                    fclose(arq_base);
                    fclose(arq_criptografado);
        	
	
}
}

void funcaoDecripto3(){
			int posicoes=-4;
				printf("Informe o nome do arquivo txt a ser descriptografado: ");
            	scanf("%s", nome);
            strcpy(nome_arq, nome);
            strcat(nome_arq, ".txt");

            arq_base = fopen(nome_arq, "r");
            if(arq_base == NULL) {
                printf("Falha ao abrir arquivo (%s)", nome_arq);
            } else {
                strcpy(nome_arq, nome);
                strcat(nome_arq, "_descriptografado.txt");
                arq_criptografado = fopen(nome_arq, "w");
   
                    printf("Informe a senha do arquivo txt a ser descriptografado: ");
                    scanf("%s", chave2);
                    
                    if(strcmp(chave2, chave)==0){
                    	
                    while((caractereInicial = fgetc(arq_base)) != EOF) {
                        caractereCripto = caractereInicial + posicoes;
                        fputc(caractereCripto, arq_criptografado);
                    }
                

                    printf("\nArquivo Descriptografado %s - %s \n", cripto_descripto, nome_arq);

                    fclose(arq_base);
                    fclose(arq_criptografado);
                }else{
                	
                 printf("Senha incorreta ");
				
				}
             
		    }
}
   
   
 


void pause() {
    int caractereInicial = 0;
       printf("\n\n\nPressione qualquer tecla para continuar...");
    getchar();
    while ((caractereInicial = getchar()) != '\n' && caractereInicial != EOF) {
	}
    return;
   
}

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(){
	srand(time(NULL));

	char b[100];
	char p[5] = {'c','a','r','r','o'};
	int esq = 0, dir = 0, cim = 0, baix = 0, esq_cim = 0,dir_cim = 0,esq_baix = 0, dir_baix = 0;
	int qtdL = 10, qtdC = 10;
	int i = 0, j = 0;
	int num, l, c;
	int tamP = 5;
	int max = qtdL * qtdC;
	int linhas, colunas;
	char palavras[100][47]; 

	// pega numero de linhas e colunas e testa pra erro
	printf("Digite o numero de linhas: ");
	scanf("%d", &linhas);
	printf("Digite o numero de colunas: ");
	scanf("%d", &colunas);

 	if (linhas <= 0 || colunas <= 0)
	{
		printf("Número inválido de linhas ou colunas.\n");
		return 2;
	}

	// armazena ate 100 palavras ate que o usuario insira 0
	while(1)
	{
        	printf("Insira palavra %i (0 para prosseguir): ", i + 1);
        	scanf("%s", palavras[i]);

        	if (strcmp(palavras[i], "0") == 0) break;

        	i++;
    	}

	//preenche matriz para exemplo: 
	for (i = 0; i < 100; i++){
		b[i] = 'a' + rand() % 26;
	}
	
	//randomiza um número e obtem os espaços em cada direção(vai continuar aleatorizando até conseguir espaço para palavra)
	while (esq < tamP && dir < tamP && cim < tamP && baix < tamP && esq_cim <tamP && dir_cim <tamP && esq_baix < tamP && dir_baix <tamP){
		
		num = rand() % max;
		esq = num % qtdC + 1;
		dir = qtdC - num % qtdC;
		cim = num / qtdC + 1;
		baix = qtdL - cim + 1;
		
		l = num / qtdC;
		c = num % qtdC;
		
		if(l > c){ esq_cim = c +1;dir_baix = qtdL-l;}
		if(c > l) {esq_cim = l +1;dir_baix = qtdC-c;}
		if(c == l) {esq_cim = l + 1;dir_baix = qtdL-l;}
		if(l < qtdC-c)dir_cim = l +1;
		if(l > qtdC-c)dir_cim = qtdC - c ;
		if(l == qtdC-c)dir_cim = qtdC -c;
		if(c > qtdL-l)esq_baix = qtdL-l;
		if(c < qtdL-l)esq_baix = c+1;
		if(c == qtdL-l)esq_baix = qtdL-l;
	}	
	
	//randomiza uma das direções para colocar a palavra na matriz e coloca a palavra na matriz
	while (j > -5){
		int aleat = rand() % 8;
		if (aleat == 0){
			if (esq >= tamP){
				for (i = num; i > num - tamP; i--){
					b[i] = p[j];
					j++;
				}
				break;
			}
			if (esq < tamP)
				aleat = rand() % 8;
		}
		if (aleat == 1){
			if (dir >= tamP){
				for (i = num; i < num + tamP; i++){
					b[i] = p[j];
					j++;
				}
				break;
			}
			if (dir < tamP)
				aleat = rand() % 8;
		}
		if (aleat == 2){
			if (cim >= tamP){
				for (i = num; i >= num % qtdL; i = i - qtdC){
					b[i] = p[j];
					j++;
					if (j == tamP) break;
				}
				break;
			}
			if (cim < tamP)
				aleat = rand() % 8;
		}
		if (aleat == 3){
			if (baix >= tamP){
				for (i = num; i < max; i = i + qtdC){
					b[i] = p[j];
					j++;
					if (j == tamP) break;
				}
				break;
			}
			if (baix < tamP)
				aleat = rand() % 8;
		}
		if(aleat == 4){
			if (esq_cim >= tamP){
				for (i = num; i >= num % qtdL; i = i - qtdC-1){
					b[i] = p[j];
					j++;
					if (j == tamP) break;
				}
				break;
			}
			if (esq_cim < tamP)
				aleat = rand() % 8;
		}
		if(aleat == 5){
			if (dir_cim >= tamP){
				for (i = num; i >= num % qtdL; i = i - qtdC+1){
					b[i] = p[j];
					j++;
					if (j == tamP) break;
				}
				break;
			}
			if (dir_cim < tamP)
				aleat = rand() % 8;
		}
		if(aleat == 6){
			if (esq_baix >= tamP){
				for (i = num; i < max; i = i + qtdC-1){
					b[i] = p[j];
					j++;
					if (j == tamP) break;
				}
				break;
			}
			if (esq_baix < tamP)
				aleat = rand() % 8;
		}
		if(aleat == 7){
			if (dir_baix >= tamP){
				for (i = num; i < max; i = i + qtdC+1){
					b[i] = p[j];
					j++;
					if (j == tamP) break;
				}
				break;
			}
			if (dir_baix < tamP)
				aleat = rand() % 8;
		}
	}

	//imprime a matriz
	printf("\n");
	for (i = 0; i < 100; i++){
		printf("%c  ", b[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}

	FILE *file = fopen("caca_palavra.txt", "w");
	if(file == NULL) {
        	perror("Erro ao abrir o arquivo!\n");
        	return 1;
    	}

    	for (i = 0; i < 100; i++) 
    	{
        	fputc(b[i], file);
        	if ((i + 1) % 10 == 0) {
            		fputc('\n', file);
        	}
        else {
            fputc(' ', file);
        }
    	}
    
	fclose(file);

	return 0;
}

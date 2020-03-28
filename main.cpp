#include <windows.h>	//Todas as definicoes de janelas: criar, abrir, etc.
#include <stdio.h>		//Essa biblioteca e responsavel pela entrada e saida 
#include <conio.h>		//serve para que vc possa usar em seus programas funcoes de leitura/escrita (input/output ou IO no meu caso o XYloc e getch
#include <iostream>		//Este cabecalho e responsavel pela manipulacao de fluxo de dados padrao do sistema representa uma evolucao do stdio.h
#include <stdlib.h>		//Ela e responsavel pela conversoes de numeros, as alocacoes na memorias e outras funcoes
#include <time.h>		//Esta biblioteca declara funcoes para manipularmos a data e hora
#include <bits/stringfwd.h>
void XYloc(int x, int y)// Aqui serve para que o XYloc salte de posicao para um ponto especifico ou ande na tela 
{
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});//////////cursor obedescer o XYloc
}

void txt(void); // arquivo de texto com o registro das jogadas
void telinha(void);
void jogo(void);
void historico(void);
void cadastro(void);

	struct cadas{
	
		char n;
		int idade;
	};

/*********************************/
/********VARIAVEIS GLOBAIS********/
/*********************************/

int numero;
int pontos=0;
char nome [100];


main()
{
/**************MENU***************/
do	{
		system("cls"); 
		printf("-----------------------------------------------------------------------------------\n");
		printf("\n-                                                  XXXXXXXXXXXX                   -\n");
		printf("-                    SNAKE                       XXXXX(i)XXXX(i)XX                -\n");
		printf("-                                               XXXXXXXXXXXXXXXXXX                -\n");
		printf("-              1 - Iniciar jogo                 XXXXXXXXXXXXX----------<          -\n");
		printf("-              2 - Ver historico                  XXXXXXXXXXXXXX                  -\n");
		printf("-              3 - Resetar historico             XXXXXXXXXXXX                       -\n");
		printf("-              4 - Sair                      XXXXXXXXXXXXX                          -\n");	
		printf("-                                        XXXXXXXXXXXXX                            -\n");
		printf("-                                      XXXXXXXXXXXX                               -\n");
		printf("-                                     XXXXXXXXXXXX                                -\n");
		printf("-                                      XXXXXXXXXXXXXXXX                           -\n");
		printf("-                                         XXXXXXXXXXXXXX                          -\n");
		printf("-                     I                       XXXXXXXXXXXXX                       -\n");
		printf("-                   III                           XXXXXXXXXXXX                    -\n");
		printf("-                  IIII                               XXXXXXXXXX                  -\n");
		printf("-                  IIII                                  XXXXXXXX                 -\n");
		printf("-                  IIII                                 XXXXXXXXX                 -\n");
		printf("-                  XXXXX                              XXXXXXXXXXX                 -\n");
		printf("-                   XXXXX                         XXXXXXXXXXXXX                   -\n");
		printf("-                   XXXXXXX                    XXXXXXXXXXXXX                      -\n");
		printf("-                      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                            -\n");
		printf("-                           XXXXXXXXXXXXXXXXXXXXXX                                -\n");
		printf("-                                XXXXXXXXXXXXX                                    -\n");
		printf("- Cristian - Igor                                                                 -\n");
		printf("-----------------------------------------------------------------------------------\n");       
		scanf("%d", &numero);
		switch(numero)
		{
			case 1:
				system("cls");
				printf("\n\n   Jogando");
				telinha();
				break;
			case 2:
				system("cls");
				printf("\nRegistro de jogadas\n   ");
				historico();
				break;
			case 3:
				FILE *historico;
				historico = fopen("historico.txt", "w");
				fprintf(historico,"---------------------------------------------------");
				fprintf(historico,"\n            HISTORICO DE JOGADAS     \n");
				fprintf(historico,"---------------------------------------------------\n");
				fclose(historico);
				main();
				break;
			case 4:
				system("cls");
				printf("\n\n   Obrigado por Testar");
				getch();
				return(0);
				break;
			default:
				printf("\n\nOpcao invalida...");
				getch();
				break;
		}
	}while(numero != 3);
}

void jogo(void)
{
	// Aqui as variaveis
	system("cls"); 

 	int x;
 	int d=2;
 	int cx[300]={1,2};
 	int cy[300]={7,7};
 	int t=1;
 	int mx;  // frutinhas
 	int my;  // frutinhas
 	int velo=100;
 	int velo2=5;
 	char niv;

 	char tecla='a';
 	int opcao;
// 	int pontos=0;
 	int nivel = 1;//Aqui � o nivel come�ando do 1
 
 
 	//Aqui o for para trabalhar a parte grafica cursor e bordas
 	for(x=0;x<18;x++)//aqui 18 � o tamanho da borda
	{
		XYloc(0,x); //vertical esquerda.//
		printf("%c",178);//aqui 178 � a borda representada na tabela ascii
	}
	for(x=0;x<50;x++)//aqui 50 � o tamanho da borda
	{
		XYloc(x,0); //horizontal ssuperior//
		printf("%c",178);//aqui 178 � a borda representada na tabela ascii
	}
	for(x=0;x<18;x++)//aqui 18 � o tamanho da borda
	{
		XYloc(50,x); //vertical direita//
		printf("%c",178);//aqui 178 � a borda representada na tabela ascii
	}
	for(x=0;x<51;x++)//aqui 51 � o tamanho da borda
	{
		XYloc(x,18); //horizontal inferior.//
		printf("%c",178);//aqui 178 � a borda representada na tabela ascii
	}
	 
 	srand(time(NULL));//Gera posi��o aleatoria das frutinhas
 	mx=(rand()%49)+1;
 	my=(rand()%17)+1;
 	
 	velo = 180;//Aqui � a velocidade em que o cursor ira se movimentar
 	
 	while(tecla!='s')
 	{ 
 		while(tecla!='s'&&!(tecla=kbhit()))
 	
 		{ 
		 for(x=t;x>0;x--)//x e igual t x e maior que zero e x incrementa menos m
	 		{
				cx[x]=cx[x-1];
	 			cy[x]=cy[x-1];
	 		}
	 		if(d==0)cx[0]--;
			if(d==1)cy[0]--;
			if(d==2)cx[0]++;
			if(d==3)cy[0]++;
			XYloc(cx[t],cy[t]);
			printf(" ");
			if(mx==cx[0]&&my==cy[0]) /// aqui ele pega a frutinha
		{ 
			t++;
			pontos++;
	 		mx=(rand()%25)+1;
	 		my=(rand()%17)+1;
	 		velo-=5;// aqui a velocidade 5 � a maxima
	 		velo2+=5;// aqui vai da 2 e incrementa at� a 5
		}
	 	XYloc(cx[0],cy[0]);
	 
	 	printf("%c",254);// este aqui � o cursosr que vai andar pela tela que � um quadradinho representado pela tabela ascii
		
		XYloc(mx,my);
		printf("%c",1);// aqui Start of Heading - SOH consultar tabela asciii
		XYloc(55,10);// Aqui posicionamento x, y
		
		printf ("Pontos: %d",pontos);
		XYloc(55,5);
		printf ("Nivel: %d",nivel);
		XYloc(55,3);
		printf ("Velocidade: %d",velo2);
		XYloc(3,22);
		
		
		printf ("\nJogador :   ----  %s  ----\n\n",nome);
		printf (" Equipe : Cristian - Igor");

		Sleep(velo);
		
		for(x=1;x<t;x++)
		{
			if(cx[0]==cx[x]&&cy[0]==cy[x])tecla='s';
		}
		
	 	if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==50)tecla='s';
	 
	 	}
	 
	 	if(tecla!='s')tecla=getch();
	 	if(tecla=='K')d=0;
	 	if(tecla=='H')d=1;
	 	if(tecla=='M')d=2;
		if(tecla=='P')d=3;
		if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==26)tecla='s';
	 
	}
	system("cls"); //limpa a tela
	system("pause");
	
	printf ("\n\n\tVOCE PERDEU\n\n");//Aqui exibe caso voce perca
	printf ("\n\n\tVOCE FEZ %d PONTOS %s",pontos, nome);// AQUI EXIBE A PONTUA��O
 	getch();
	txt(); // fun��o sendo chamada
}


void txt(void)
{
	FILE *historico;
	historico = fopen("historico.txt", "a");
	fprintf(historico,"---------------------------------------------------\n",pontos);
	fprintf(historico,"\t Nome :  %s \n",nome);
	fprintf(historico,"\t Pontos : %d\n",pontos);
	fprintf(historico,"---------------------------------------------------\n",pontos);
	fclose(historico);
	main();
}

void historico(void)
{
	char linhas[100];
	FILE *historico;
	historico = (FILE*) malloc(sizeof (FILE*));
	historico = fopen("historico.txt", "r");
	
	while(fgets(linhas,100,historico) !=NULL)
	{
		printf("%s", linhas);	
	}
//	free (historico);
	getch();
	main();
}
void cadastro(void)
{
/*
	struct cdt 
	{
		char nome[100];
		int idade;
	};
	
	struct cdt vet[ 2 ];
	
//	for ( ; i < 2; i++)
int resposta;
	do
	{
	
	printf("\nDigite o nome:");
	scanf("%s",vet[i].nome);
	printf("\nDigite a idade:");
	scanf("%d",&vet[i].idade);
	
	
	printf("\ndeseja continuar 8 para sim 9 para nao: ");
	scanf("&d",resposta);
	getch();
	
	}while (resposta != 9);
	main();
	
	
	
	
//	fprintf(usuarios);
//	fclose(user);
//	main();*/
}
void telinha(void)
{
		system("cls");
		printf("\n\n   Digite seu nome: ");
		scanf("%s", nome);
		jogo();
}





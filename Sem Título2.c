#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 
typedef struct{ 
		
        int cpf;
		char nome[30];
		int sex;
		int email;
		int dtnasc;
		int tel;
		int cpfdep;
		char nomedep[30];
		int dtnascdep;
		float valorplano;
		int dtvencimento;
                
} TCliente;

FILE *pcliente;

TCliente cliente_aux, cliente_nulo;

void cabec() {
system("cls");
printf("**Nucleo de Saude**\n\n");
}

void abre_arquivo()
{ 
	pcliente = fopen("cliente.txt", "a+b");
}
/*
void ValorPlano (int sex, int valorplano, int qtdDependente, int i)

{
	if (qtdDependente >= 2)
    {
        cliente_aux.valorplano[i]-=(cliente_aux.valorplano[i] *20)/100;
    }
    else if (cliente_aux.idade >= 13)
    {
    	cliente_aux.valorplano[i]+=(cliente_aux.valorplano[i] *30)/100;
	}
    
    else if (cliente_aux.idade <= 35)
    {
    	cliente_aux.ValorPlano[i]+=(cliente_aux.valorplano[i] *30)/100;
	}
    
    else if (cliente_aux.idade < 13)
    {
        cliente_aux.valorplano[i]-=(cliente_aux.valorplano[i] *30)/100;
    }
    
	else if (cliente_aux.idade >= 60)
    {
    	cliente_aux.ValorPlano[i]+=(cliente_aux.valorplano[i] *40)/100;
	}
} */  
void inserir()
	{ 
	int resp;
	do { 
		cabec();
		printf("\n\nCadastrar Cliente\n\n");//CADASTRO
		printf("\nCPF: ");
		scanf("%i", &cliente_aux.cpf);

		printf("\nNome: ");
		fflush(stdin);
		gets(cliente_aux.nome);
		
		printf("\nSEXO: (1-F/2-M): ");
		scanf("%i", &cliente_aux.sex);
		
		printf("\nEMAIL: ");
    	scanf("%i", &cliente_aux.email);
    		 	   
    	printf("\nDATA DE NASCIMENTO: ");
    	scanf("%i", &cliente_aux.dtnasc);
     	   
    	printf("\nTELEFONE: ");
    	scanf("%i", &cliente_aux.tel);
     	   
    	printf("\nCPF DEPENDENTE: ");
    	scanf("%i", &cliente_aux.cpfdep);
    	    
    	printf("\nDIGITE NOME DEPENTENTE: ");
    	fflush(stdin);
    	gets(cliente_aux.nomedep);
     	   
    	printf("\nDATA DE NASCIMENTO DEPENDENTE: ");
    	scanf("%i", &cliente_aux.dtnascdep);

	fseek(pcliente, 0, SEEK_END);
	fwrite(&cliente_aux, sizeof(TCliente), 1, pcliente);
	printf("\n\nCliente cadastrado com sucesso!\n\n");
	printf("\nDeseja cadastrar outro: (1-sim/0-nao)? ");
	scanf("%d", &resp);
	}
	while (resp ==1);
}
int procura(int cpfp)
{ 
	int p;
	p = 0;
	rewind(pcliente);
	fread(&cliente_aux, sizeof(TCliente), 1, pcliente);
	
while (feof(pcliente)==0)
{ 
	if (cliente_aux.cpf == cpfp)
	return p;
	
	else
	{ 
	fread(&cliente_aux, sizeof(TCliente), 1, pcliente);
	p++;
	}
}
return -1;
}
void mostre(int pos)
{ 
	fseek(pcliente, pos*sizeof(TCliente), SEEK_SET);
	fread(&cliente_aux, sizeof(TCliente), 1, pcliente);
	printf("\n\n\n");
	printf("CPF      Nome            Sexo   \n\n");
	printf("%14i %-20s %8i \n\n", cliente_aux.cpf, cliente_aux.nome, cliente_aux.sex);
}

void consultar()

{ 

int resp, cpfcon, posicao;

do
	{ 
	cabec();
	printf("\n\nConsultar Cliente\n\n\n");
	printf("CPF: ");
	scanf("%d", &cpfcon);
	posicao = procura(cpfcon);

	if (posicao == -1)
	printf("\n\nCPF nao encontrado!\n\n");
	else
	mostre(posicao);
	printf("\n\nDeseja consultar outro (1-sim/0-nao)? ");
	scanf("%d", &resp);
	} 
	while (resp == 1);
}
void remover()//REMOVER CLIENTE
{ 
	int cpfrem, conf, resp, posicao;
	cliente_nulo.cpf = 0;
do
	{ 
	cabec();
	printf("\n\nRemover cliente\n\n\n");
	printf("CPF: ");
	scanf("%d", &cpfrem);
	posicao = procura(cpfrem);
	if (posicao == -1)
		printf("\nCliente nao encontrado!!\a");

	else 
	{ 
		mostre(posicao);
		printf("\n\nDeseja remover o cliente (1-sim/0-nao)? ");
		scanf("%d", &conf);
		if (conf == 1)
	{	 
			fseek(pcliente,posicao*sizeof(TCliente),SEEK_SET);
			fwrite ( &cliente_nulo, sizeof(TCliente), 1, pcliente);
			printf("\n\nCliente removido com sucesso!");
		}
		else
			printf("\nRemocao cancelada!");
	}
	printf("\n\n\nDeseja remover outro (1-sim/0-nao)? ");
	scanf("%d", &resp);
	} while (resp ==1);
}
void alterar()//EDITAR CLIENTE

{
	int cpfalt, conf, resp, posicao;
do 
	{
	cabec();
	printf("\n\nEditar cliente\n\n\n");
	printf("CPF: ");
	scanf("%i", &cpfalt);
	posicao = procura(cpfalt);
	if (posicao == -1)
		printf("\nCliente,nao encontrado!!\a");
	
	else
	{
		char novoNome[30];
		int novoCpf, novoSexo, novoEmail, novoDtnasc, novoTel;
		
		mostre(posicao);
		printf("\n\nEditar cliente(1-sim/0-nao)? ");
		scanf("%i", &conf);
		if (conf == 1)
		{
			printf("\nO QUE DESEJA ALTERAR: \n");
			printf("\nNOME[1]\n");
			printf("\nTURNO[4]\n");
			printf("\nCURSO[3]\n");
			printf("\nSEXO[2]/n");
			printf ("\nIDADE [5]\n");
			scanf("%d", &resp);
			if (resp == 1)
			/*printf("\nNovo cpf: ");
			scanf("%i", &cliente_aux.cpf);
			printf("\nNovo Nome: ");
			scanf("%c", &cliente_aux.nome);
			printf("\nNovo Sexo: ");
			scanf("%i", &cliente_aux.sex);
			printf("\nNovo Email: ");
			scanf("%i", &cliente_aux.email);
			printf("\nNova Data de Nascimento: ");
			scanf("%i", &cliente_aux.dtnasc);
			printf("\nNovo Telefone: ");
			scanf("%i", &cliente_aux.tel);
			printf("\nNovo CPF dependente: ");
			scanf("%i", &cliente_aux.cpfdep);
			printf("\nNovo Dependente: ");
			scanf("%c", &cliente_aux.nomedep);
			printf("\nNova Data de Nascimento Dependente: ");
			scanf("%i", &cliente_aux.dtnascdep);*/
			printf("\nDados alterados com sucesso! \n\n");
			fseek(pcliente,posicao*sizeof(TCliente),SEEK_SET);
			fwrite(&cliente_aux,sizeof(TCliente), 1,pcliente);
			mostre(posicao);
			printf("\nDados alterados com sucesso!\n");
		}
	else
		printf("\n\nAlteracao cancelada!\n\n");
	}
	printf("\n\nDeseja alterar outro (1-S/0-N)? ");
	scanf("%d", &resp);
}
	while (resp ==1);
}
	void listagem()
{ 
	cabec();
	printf("\n\nListagem Geral\n\n\n\n");
	printf("\n\nCPF      Nome            Sexo   Fone       Email       Idade      Plano      Dependente      Valor Plano    Vencimento do Plano   \n\n");
	rewind(pcliente);
	fread(&cliente_aux, sizeof(TCliente), 1, pcliente);

while(feof(pcliente)==0)
	{ 
	if (cliente_aux.cpf != 0)
	printf("%9i %-20s \n", cliente_aux.cpf, cliente_aux.nome);
	fread(&cliente_aux, sizeof(TCliente), 1, pcliente);
	}

	printf("\nTecle enter para voltar ao menu...");
	getche();
}

main()
{ 
	int op;
	abre_arquivo();
do	{ 
	cabec();
	printf("\n\nOpcoes: \n\n\n");
	printf(" 1- Cadastrar cliente\n\n");
	printf(" 2- Remover cliente\n\n");
	printf(" 3- Consultar cliente por cpf\n\n");
	printf(" 4- Editar cliente\n\n");
	printf(" 5- Listagem geral\n\n");
	printf("0- Sair\n\n\n");
	printf("Informe a opcao desejada: ");
	scanf("%d", &op);
	
switch(op)
		{ 
		case 1: inserir(); break;
		case 2: remover(); break;
		case 3: consultar(); break;
		case 4: alterar(); break;
		case 5: listagem(); break;
		case 0: fclose(pcliente); break;
		default: printf("\n\n\aOpcao invalida!");
		break;
		}
	} 
	while (op != 0);
}

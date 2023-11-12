#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void batalha();
void batalhaP1();
void batalhaP2();
void tirodir();
void P1turno();
void P2turno();
void P1win();
void P2win();


int bala[51];

int P1vida, P2vida, P1armadura, P2armadura, P1armaduradur, P2armaduradur, P1arma, P2arma, P1sorte, P2sorte, P1defesa, P2defesa, P1capacete, P2capacete, P1acc1, P1acc2, P2acc1, P2acc2, P1dano, P2dano, length;
int op=1, turno, decisao, r2=0;

int main()
{
    srand(time(NULL));

    //titulo do jogo
    int menu;

    printf("\t       .__                              .__                   __                 \n");
    printf("\t  _____|  |__ _____ _____________  _____|  |__   ____   _____/  |_  ___________  \n");
    printf("\t /  ___/  |  \x5c\x5c__  \x5c\x5c_  __ \x5c____ \x5c/  ___/  |  \x5c /  _ \x5c /  _ \x5c   __\x5c/ __ \x5c_  __ \x5c \n");
    printf("\t \x5c___ \x5c|   Y  \x5c/ __ \x5c|  | \x5c/  |_> >___ \x5c|   Y  (  <_> |  <_> )  | \x5c  ___/|  | \x5c/ \n");
    printf("\t/____  >___|  (____  /__|  |   __/____  >___|  /\x5c____/ \x5c____/|__|  \x5c___  >__|    \n");
    printf("\t     \x5c/     \x5c/     \x5c/      |__|       \x5c/     \x5c/                        \x5c/        \n\n");
    printf("\tPressione 1 para Jogar\n\n\tPressione 2 para sair\n\n\t->");
    scanf("%d", &menu);

    do
    {
    for(int i=0;i<60;i++)bala[i]=' ';
    P1vida=2000,P2vida=2000, length=0;

    //Limpa o ecrã

    system("cls");


    //Randomização do equipamento e stats do player 1

    P1dano=0;
    P1defesa=0;
    P1armaduradur=100;
    P1acc1=rand()%3+1;
    P1acc2=rand()%3+1;
    P1armadura=rand()%3+1;
    P1capacete=rand()%3+1;
    P1arma=rand()%4+1;
    P1sorte=rand()%40+1;


    //Atribuição dos equipamentos do player 1


    switch(P1arma) //arma player 1
        {
        case 1:
        P1arma="Pistola";
        P1dano=100;

        break;
        case 2:
        P1arma="Espingarda";
        P1dano=200;

        break;
        case 3:
        P1arma="Cacadeira";
        P1dano=350;

        break;
        case 4:
        P1arma="Sniper";
        P1dano=500;

        break;
        }

    switch(P1armadura) //armadura player 1
        {
        case 1:
        P1armadura="armadura nivel 1";
        P1defesa+=10;
        break;
        case 2:
        P1armadura="armadura nivel 2";
        P1defesa+=20;
        break;
        case 3:
        P1armadura="armadura nivel 3";
        P1defesa+=30;
        break;
        }

    switch(P1capacete) //capacete player 1
        {
        case 1:
        P1capacete="capacete nivel 1";
        P1defesa+=10;
        break;
        case 2:
        P1capacete="capacete nivel 2";
        P1defesa+=15;
        break;
        case 3:
        P1capacete="capacete nivel 3";
        P1defesa+=20;
        break;
        }

    switch(P1acc1) //primeiro acessorio da arma do player 1
        {
        case 1:
        P1acc1="mira padrao";
        break;
        case 2:
        P1acc1="mira red dot";
        P1sorte+=5;
        break;
        case 3:
        P1acc1="mira acog";
        P1sorte+=10;
        break;
        }

    switch(P1acc2) //segundo acessorio da arma do player 1
        {
        case 1:
        P1acc2="carregador extendido";
        break;
        case 2:
        P1acc2="muzzle break";
        P1dano*=1.25;
        break;
        case 3:
        P1acc2="carregador padrao";
        break;
        }

    //Randomização do equipamento e stats do player 2

    P2dano=0;
    P2defesa=0;
    P2armaduradur=100;
    P2acc1=rand()%3+1;
    P2acc2=rand()%3+1;
    P2armadura=rand()%3+1;
    P2capacete=rand()%3+1;
    P2arma=rand()%4+1;
    P2sorte=rand()%40+1;

    //Atribuição dos equipamentos do player 2


    switch(P2arma) //arma do player 2
        {
        case 1:
        P2arma="Pistola";
        P2dano=100;

        break;
        case 2:
        P2arma="Espingarda";
        P2dano=200;

        break;
        case 3:
        P2arma="Cacadeira";
        P2dano=350;

        break;
        case 4:
        P2arma="Sniper";
        P2dano=500;

        break;
        }

    switch(P2armadura) //armadura do player 2
        {
        case 1:
        P2armadura="armadura nivel 1";
        P2defesa+=10;
        break;
        case 2:
        P2armadura="armadura nivel 2";
        P2defesa+=15;
        break;
        case 3:
        P2armadura="armadura nivel 3";
        P2defesa+=20;
        break;
        }

    switch(P2capacete) //capacete do player 2
        {
        case 1:
        P2capacete="capacete nivel 1";
        P2defesa+=5;
        break;
        case 2:
        P2capacete="capacete nivel 2";
        P2defesa+=10;
        break;
        case 3:
        P2capacete="capacete nivel 3";
        P2defesa+=15;
        break;
        }

    switch(P2acc1) ////primeiro acessorio da arma do player 2
        {
        case 1:
        P2acc1="iron sights";
        break;
        case 2:
        P2acc1="mira red dot";
        P2sorte+=5;
        break;
        case 3:
        P2acc1="mira acog";
        P2sorte+=10;
        break;
        }

    switch(P2acc2) //segundo acessorio da arma do player 2

        {
        case 1:
        P2acc2="carregador extendido";
        break;
        case 2:
        P2acc2="muzzle break";
        P2dano*=1.25;
        break;
        case 3:
        P2acc2="carregador padrao";
        break;
        }

///////MENU//////

turno=rand()%2+1;

switch(turno)
    {
    case 1:
    P1turno();
    break;

    case 2:
    P2turno();
    break;
    }


switch(menu)
    {
    case 1:

        //fase de batalha

        do
        {

            switch(turno)
                {
                //turno do jogador 1
                case 1:
                    batalha();
                    printf("1 -> atacar\n2 -> tentar desviar\n");
                    scanf("%d", &decisao);
                    while(decisao<1||decisao>2)
                        {
                        printf("opcao invalida tente novamente\n");
                        scanf("%d", &decisao);
                        }
                    sleep(1);
                    if(P1acc2=="carregador extendido"&&decisao==1)
                    {
                    batalhaP1();
                        if(P2vida>0&&P1acc2=="carregador extendido"&&r2<=P2sorte)
                        {
                        r2=rand()%100+1;
                        batalhaP1();
                        turno=2;
                        r2=0;
                        }else if(P2vida>0&&r2>P2sorte||P2vida>0&&r2==0) r2=0, batalhaP1(), turno=2;

                    }else batalhaP1(), turno=2;

                break;

                //turno do jogador 2
                case 2:
                    batalha();
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t atacar <- 1\n\t\t\t\t\t\t\t\t\t\t\t tentar desviar <- 2\n\t\t\t\t\t\t\t\t\t\t\t\t\t   ");
                    scanf("%d", &decisao);
                    while(decisao<1||decisao>2)
                        {
                        printf("\t\t\t\t\t\t\t\t\t      opcao invalida tente novamente\n\t\t\t\t\t\t\t\t\t\t\t\t\t   ");
                        scanf("%d", &decisao);
                        }
                    sleep(1);
                    if(P2acc2=="carregador extendido"&&decisao==1)
                    {
                    batalhaP2();

                        if(P1vida>0&&P2acc2=="carregador extendido"&&r2<=P1sorte)
                        {
                        r2=rand()%100+1;
                        batalhaP2();
                        turno=1;
                        r2=0;
                        }else if(P1vida>0&&r2>P1sorte||P1vida>0&&r2==0) r2=0, batalhaP2(), turno=1;

                    }else batalhaP2(), turno=1;

                break;
                }

        }while(P1vida>0&&P2vida>0);

    break;

    case 2:
    exit(0);

    break;
    }

    //Menu de Game over//

    if(P2vida<=0)
    {
    P1win();
    }else if (P1vida<=0)
        {
        P2win();
        }



    printf("\nDeseja jogar novamente?\n1-sim\n2-nao\n->");
    fflush(stdin);
    scanf("%d",&op);
    }while(op==1);

    return 0;
}


void batalha()
    {
        system("cls");
        printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n", turno);
        printf("P1 Vidas: %d\t\t\t\t\t\t\t\tP2 Vidas: %d", P1vida, P2vida);
        printf("\n%s\t\t\t\t\t\t\t%s", P1capacete, P2capacete);
        printf("\n%s %d%c\t\t\t\t\t\t\t%s %d%c", P1armadura, P1armaduradur, 37, P2armadura, P2armaduradur, 37);
        printf("\n%s com %s e %s",P1arma, P1acc1, P1acc2);
        length=strlen(P1arma)+strlen(P1acc1)+strlen(P1acc2);
        if(length>39)
                {
                printf("\t\t\t");
                }else if(length>=32)
                    {printf("\t\t\t\t");}else{printf("\t\t\t\t\t");}

        printf("%s com %s e %s", P2arma, P2acc1, P2acc2);
        printf("\nSorte: %d%c\t\t\t\t\t\t\t\tSorte: %d%c",P1sorte ,37 , P2sorte, 37);
        printf("\nDefesa: %d\t\t\t\t\t\t\t\tDefesa: %d\n",P1defesa, P2defesa);
        printf("\n/////////////////////////////////////////////////Fase do Player %d///////////////////////////////////////////////////////\n\n", turno);
        printf("\n\n\xdc\xdb\xdb\xdc\t\t\t\t\t\t\t\t\t\t\t\t\t\xdc\xdb\xdb\xdc\n");
        printf(" \xdb\xdb\t\t\t\t\t\t\t\t\t\t\t\t\t \xdb\xdb\n");
        printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf(" \xdf\xdf\t\t\t\t\t\t\t\t\t\t\t\t         \xdf\xdf\n");
    }


void batalhaP1()
    {

    switch(decisao)
    {
    case 1:
    for(int i=0; i<=50;i++)
        {
        bala[i]=220;
        system("cls");
        printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("P1 Vidas: %d\t\t\t\t\t\t\t\tP2 Vidas: %d", P1vida, P2vida);
        printf("\n%s\t\t\t\t\t\t\t%s", P1capacete, P2capacete);
        printf("\n%s %d%c\t\t\t\t\t\t\t%s %d%c", P1armadura, P1armaduradur, 37, P2armadura, P2armaduradur, 37);
        printf("\n%s com %s e %s",P1arma, P1acc1, P1acc2);
        length=strlen(P1arma)+strlen(P1acc1)+strlen(P1acc2);
        if(length>39)
                {
                printf("\t\t\t");
                }else if(length>=32)
                    {
                    printf("\t\t\t\t");
                    }else{printf("\t\t\t\t\t");}

        printf("%s com %s e %s", P2arma, P2acc1, P2acc2);
        printf("\nSorte: %d%c\t\t\t\t\t\t\t\tSorte: %d%c",P1sorte ,37 , P2sorte, 37);
        printf("\nDefesa: %d\t\t\t\t\t\t\t\tDefesa: %d\n",P1defesa, P2defesa);
        printf("\n/////////////////////////////////////////////////Fase do Player 1///////////////////////////////////////////////////////\n\n");
        printf("\n\n\xdc\xdb\xdb\xdc\t\t\t\t\t\t\t\t\t\t\t\t\t\xdc\xdb\xdb\xdc\n");
        printf(" \xdb\xdb    BANG!  \t\t\t\t\t\t\t\t\t\t\t\t \xdb\xdb\n");
        printf(" \xdb   \xdc\xdc\xdc ");

        //implementar o tiro
        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", bala[0],bala[1],bala[2],bala[3],bala[4],bala[5], bala[6],bala[7],bala[8],bala[9],bala[10],bala[11], bala[12],bala[13],bala[14],bala[15],bala[16],bala[17], bala[18],bala[19],bala[20],bala[21],bala[22],bala[23],bala[24],bala[25],bala[26],bala[27],bala[28],bala[29],bala[30],bala[31],bala[32],bala[33],bala[34],bala[35],bala[36],bala[37],bala[38],bala[39],bala[40],bala[41],bala[42],bala[43],bala[44],bala[45],bala[46],bala[47],bala[48]);
        printf("\xdb\n");
        printf(" \xdb\xdf\xdf\xdf\xdb\xdf\t\t\t\t\t\t\t\t\t\t\t\t          \xdb\n");
        printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf(" \xdf\xdf\t\t\t\t\t\t\t\t\t\t\t\t         \xdf\xdf\n");


        bala[i]=' ';
        usleep(10000);
        }

        //Sistema de dano critico e durabilidade da armadura
        int r1=rand()%100+1, P1danoDefault=P1dano, danosofrido=0, vidainicial=P2vida;

            if(r2==0||r2>P2sorte)
                {
                if(r1<=P1sorte&&P2armaduradur>0) //se o adversario ainda possuir armadura e for dano critico
                    {
                    system("color 47");
                    system("color 07");
                    P2armaduradur-=50;
                    P1dano*=1.75;
                    }else if(r1<=P1sorte&&P2armaduradur<=0) //se o adversario ja nao possuir armadura e for dano critico
                        {
                        system("color 47");
                        system("color 07");
                        P1dano*=1.75;
                        }

               //Sistema de dano
               if(P2armaduradur==0||P2armaduradur<0)
                    {
                    P2defesa=0;
                    P2vida= P2vida-P1dano;
                    }else{P2vida=P2vida-(P1dano-P2defesa);}
                }


            //Contador de dano sofrido
            for(int i=vidainicial;i>P2vida;i--, danosofrido++);

            //Não permite a vida chegar a valores negativos
            if(P2vida<0) P2vida=0;

            system("cls");

            printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
            printf("P1 Vidas: %d\t\t\t\t\t\t\t\tP2 Vidas: %d", P1vida, P2vida);
            printf("\n%s\t\t\t\t\t\t\t%s", P1capacete, P2capacete);
            printf("\n%s %d%c\t\t\t\t\t\t\t%s %d%c", P1armadura, P1armaduradur, 37, P2armadura, P2armaduradur, 37);
            printf("\n%s com %s e %s",P1arma, P1acc1, P1acc2);
            length=strlen(P1arma)+strlen(P1acc1)+strlen(P1acc2);
            if(length>39)
                    {
                    printf("\t\t\t");
                    }else if(length>=32)
                        {
                        printf("\t\t\t\t");
                        }else{printf("\t\t\t\t\t");}

            printf("%s com %s e %s", P2arma, P2acc1, P2acc2);
            printf("\nSorte: %d%c\t\t\t\t\t\t\t\tSorte: %d%c",P1sorte ,37 , P2sorte, 37);
            printf("\nDefesa: %d\t\t\t\t\t\t\t\tDefesa: %d\n",P1defesa, P2defesa);
            printf("\n/////////////////////////////////////////////////Fase do Player 1///////////////////////////////////////////////////////\n\n");
            printf("\n\n\xdc\xdb\xdb\xdc\t\t\t\t\t\t\t\t\t\t\t\t\t\xdc\xdb\xdb\xdc\n");
            printf(" \xdb\xdb           \t\t\t\t\t\t\t\t\t\t    Dano: %d", danosofrido);
            if(danosofrido>=1000)
                {
                printf("   \xdb\xdb\n");
                }else if(danosofrido>=100)
                    {
                    printf("    \xdb\xdb\n");
                    }else if(danosofrido>=10)
                        {
                        printf("     \xdb\xdb\n");
                        }else printf("      \xdb\xdb\n");

            printf(" \xdb   \xdc\xdc\xdc ");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
            printf(" \xdb\xdf\xdf\xdf\xdb\xdf\t\t\t\t\t\t\t\t\t\t\t\t          \xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
            printf(" \xdf\xdf\t\t\t\t\t\t\t\t\t\t\t\t         \xdf\xdf\n");
            sleep(2);

            //Dá reset ao dano para o seu valor padrão após um hit critico
            P1dano=P1danoDefault;

        break;

        case 2:
        r2=rand()%100;

        break;
        }
    }


void batalhaP2()
    {

    switch(decisao)
        {
        case 1:
        for(int i=50; i>=0;i--)
        {
        bala[i-1]=220;
        system("cls");
        printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
            printf("P1 Vidas: %d\t\t\t\t\t\t\t\tP2 Vidas: %d", P1vida, P2vida);
            printf("\n%s\t\t\t\t\t\t\t%s", P1capacete, P2capacete);
            printf("\n%s %d%c\t\t\t\t\t\t\t%s %d%c", P1armadura, P1armaduradur, 37, P2armadura, P2armaduradur, 37);
            printf("\n%s com %s e %s",P1arma, P1acc1, P1acc2);
            length=strlen(P1arma)+strlen(P1acc1)+strlen(P1acc2);
            if(length>39)
                    {
                    printf("\t\t\t");
                    }else if(length>=32)
                        {printf("\t\t\t\t");}else{printf("\t\t\t\t\t");}

            printf("%s com %s e %s", P2arma, P2acc1, P2acc2);
            printf("\nSorte: %d%c\t\t\t\t\t\t\t\tSorte: %d%c",P1sorte ,37 , P2sorte, 37);
            printf("\nDefesa: %d\t\t\t\t\t\t\t\tDefesa: %d\n",P1defesa, P2defesa);
            printf("\n/////////////////////////////////////////////////Fase do Player 2///////////////////////////////////////////////////////\n\n");
            printf("\n\n\xdc\xdb\xdb\xdc\t\t\t\t\t\t\t\t\t\t\t\t\t\xdc\xdb\xdb\xdc\n");
            printf(" \xdb\xdb  \t\t\t\t\t\t\t\t\t\t\t\t  BANG!  \xdb\xdb\n");
            printf(" \xdb");
            printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", bala[0], bala[1], bala[2],bala[3],bala[4],bala[5], bala[6],bala[7],bala[8],bala[9],bala[10],bala[11], bala[12],bala[13],bala[14],bala[15],bala[16],bala[17], bala[18],bala[19],bala[20],bala[21],bala[22],bala[23],bala[24],bala[25],bala[26],bala[27],bala[28],bala[29],bala[30],bala[31],bala[32],bala[33],bala[34],bala[35],bala[36],bala[37],bala[38],bala[39],bala[40],bala[41],bala[42],bala[43],bala[44],bala[45],bala[46],bala[47]);
            printf("   \xdc\xdc\xdc   \xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t     \xdf\xdb\xdf\xdf\xdf\xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
            printf(" \xdf\xdf\t\t\t\t\t\t\t\t\t\t\t\t         \xdf\xdf\n");


        bala[i-1]=' ';
        usleep(10000);
        }

        //Sistema de dano critico e durabilidade da armadura
        int r1=rand()%100+1, P2danoDefault=P2dano, danosofrido=0, vidainicial=P1vida;

        if(r2==0||r2>P1sorte)
                {
                if(r1<=P2sorte&&P1armaduradur>0) //se o adversario ainda possuir armadura e sofrer dano critico
                    {
                    system("color 47");
                    system("color 07");
                    P1armaduradur-=50;
                    P2dano*=1.75;
                    }else if(r1<=P2sorte&&P1armaduradur<=0) //se o adversario ja nao possuir armadura e sofrer dano critico
                        {
                        system("color 47");
                        system("color 07");
                        P2dano*=1.75;
                        }

                //Sistema de dano
                if(P1armaduradur==0||P1armaduradur<0)
                    {
                    P1defesa=0;
                    P1vida= P1vida-P2dano;
                    }else P1vida=P1vida-(P2dano-P1defesa);
                }

        //Contador de dano sofrido
        for(int i=vidainicial;i>P1vida; i--, danosofrido++);

        //Não permite a vida chegar a valores negativos
        if(P1vida<0) P1vida=0;

        system("cls");
        printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
            printf("P1 Vidas: %d\t\t\t\t\t\t\t\tP2 Vidas: %d", P1vida, P2vida);
            printf("\n%s\t\t\t\t\t\t\t%s", P1capacete, P2capacete);
            printf("\n%s %d%c\t\t\t\t\t\t\t%s %d%c", P1armadura, P1armaduradur, 37, P2armadura, P2armaduradur, 37);
            printf("\n%s com %s e %s",P1arma, P1acc1, P1acc2);
            length=strlen(P1arma)+strlen(P1acc1)+strlen(P1acc2);
        if(length>39)
                {
                printf("\t\t\t");
                }else if(length>=32)
                    {printf("\t\t\t\t");}else{printf("\t\t\t\t\t");}

            printf("%s com %s e %s", P2arma, P2acc1, P2acc2);
            printf("\nSorte: %d%c\t\t\t\t\t\t\t\tSorte: %d%c",P1sorte ,37 , P2sorte, 37);
            printf("\nDefesa: %d\t\t\t\t\t\t\t\tDefesa: %d\n",P1defesa, P2defesa);
            printf("\n/////////////////////////////////////////////////Fase do Player 2///////////////////////////////////////////////////////\n\n");
            printf("\n\n\xdc\xdb\xdb\xdc\t\t\t\t\t\t\t\t\t\t\t\t\t\xdc\xdb\xdb\xdc\n");
            printf(" \xdb\xdb");
        if(P1dano>=1000)
            {
            printf("    dano: %d      \t\t\t\t\t\t\t\t\t\t\t \xdb\xdb\n", danosofrido);
            }else if(P1dano>=100)
                {
                printf("    dano: %d     \t\t\t\t\t\t\t\t\t\t\t \xdb\xdb\n", danosofrido);
                }else if(P1dano>=10)
                    {
                    printf("    dano: %d    \t\t\t\t\t\t\t\t\t\t\t \xdb\xdb\n", danosofrido);
                    }else printf("    dano: %d   \t\t\t\t\t\t\t\t\t\t\t \xdb\xdb\n", danosofrido);

            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t ");
            printf("   \xdc\xdc\xdc   \xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t     \xdf\xdb\xdf\xdf\xdf\xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
            printf(" \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
            printf(" \xdf\xdf\t\t\t\t\t\t\t\t\t\t\t\t         \xdf\xdf\n");
            sleep(1);

            //Dá reset ao dano para o seu valor padrão após um hit critico
            P2dano=P2danoDefault;

        break;

        case 2:
        r2=rand()%100+1;

        break;
        }
    }


void P1turno()
    {
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t        \xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\t\t\t      \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    printf("\t\t\t        \xdf\xdf\xdf\xdf\xdf\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);


    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t      \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb\xb0\xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);


    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t      \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);


    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t        \xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\t\t\t      \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\t\t\t        \xdf\xdf\xdf\xdf\xdf\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t      \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb\xb0\xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t      \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n");
    printf("\t\t\t  Turno do Jogador 1\n\n");
    printf("\t\t\t        \xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\t\t\t      \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    printf("\t\t\t        \xdf\xdf\xdf\xdf\xdf\xdf\n");
    printf("\n\n\n\n");
    sleep(2);

    }

void P2turno()
    {
system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t        \xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\t\t\t      \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\t\t\t        \xdf\xdf\xdf\xdf\xdf\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t      \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb\xb0\xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t      \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t        \xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\t\t\t      \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    printf("\t\t\t        \xdf\xdf\xdf\xdf\xdf\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t      \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb \xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t    \xdf\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\t\t\t    \xdb\xdb\xdb\xdb\xdb\xdb\xb0\xb1\xdb\xdb\xdb\xdb\xdb\xdb\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\n");
    usleep(10000);

    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);


    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t      \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\n\n\n\n");
    usleep(10000);


    system("cls");
    printf("\n\n");
    printf("\t\t\t  Turno do Jogador 2\n\n");
    printf("\t\t\t        \xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\t\t\t      \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdc\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdc\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdb\xb1\xb1\xb1\xb1 \xb1\xb1 \xb1\xb1\xb1\xb1\xdb\n");
    printf("\t\t\t    \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\t\t\t      \xdf\xdb\xb1\xb1\xb1\xb1\xb1\xb1\xdb\xdf\n");
    printf("\t\t\t        \xdf\xdf\xdf\xdf\xdf\xdf\n");
    printf("\n\n\n\n");
    sleep(2);
    }


void P1win()
    {
    system("cls");
        printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("P1 Vidas: %d\t\t\t\t\t\t\t\tP2 Vidas: %d", P1vida, P2vida);
        printf("\n%s\t\t\t\t\t\t\t%s", P1capacete, P2capacete);
        printf("\n%s %d%c\t\t\t\t\t\t\t%s %d%c", P1armadura, P1armaduradur, 37, P2armadura, P2armaduradur, 37);
        printf("\n%s com %s e %s",P1arma, P1acc1, P1acc2);
        length=strlen(P1arma)+strlen(P1acc1)+strlen(P1acc2);
        if(length>39)
                {
                printf("\t\t\t");
                }else if(length>=32)
                    {printf("\t\t\t\t");}else{printf("\t\t\t\t\t");}

        printf("%s com %s e %s", P2arma, P2acc1, P2acc2);
        printf("\nSorte: %d%c\t\t\t\t\t\t\t\tSorte: %d%c",P1sorte ,37 , P2sorte, 37);
        printf("\nDefesa: %d\t\t\t\t\t\t\t\tDefesa: %d\n",P1defesa, P2defesa);
        printf("\n/////////////////////////////////////////////////Player 1 Ganhou!!//////////////////////////////////////////////////////\n\n");
        printf("\n\n    \xdc\xdb\xdb\xdc\t\t\t\t\t\t\t\t\t\t\t\t\n");
        printf("     \xdb\xdb\t\t\t\t\t\t\t\t\t\t\t\t\n");
        printf("     \xdb\t\t\t\t\t\t\t\t\t\t\t\t        \xdc\xdb\xdb\xdc  \n");
        printf("     \xdb\t\t\t\t\t\t\t\t\t\t\t\t         \xdb\xdb  \n");
        printf("     \xdb\t\t\t\t\t\t\t\t\t\t\t\t          \xdb  \n");
        printf("    \xdb \xdb\t\t\t\t\t\t\t\t\t\t\t\t          \xdb  \n");
        printf("    \xdb  \xdb\t\t\t\t\t\t\t\t\t\t\t\t  \xdb  \n");
        printf("    \xdf\xdf \xdf\xdf\t\t\t\t\t\t\t\t\t\t\t\t  \xdf\xdf\xdf\xdb\n");
sleep(1);
            system("cls");
        printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("P1 Vidas: %d\t\t\t\t\t\t\t\tP2 Vidas: %d", P1vida, P2vida);
        printf("\n%s\t\t\t\t\t\t\t%s", P1capacete, P2capacete);
        printf("\n%s %d%c\t\t\t\t\t\t\t%s %d%c", P1armadura, P1armaduradur, 37, P2armadura, P2armaduradur, 37);
        printf("\n%s com %s e %s",P1arma, P1acc1, P1acc2);
        length=strlen(P1arma)+strlen(P1acc1)+strlen(P1acc2);
        if(length>39)
                {
                printf("\t\t\t");
                }else if(length>=32)
                    {printf("\t\t\t\t");}else{printf("\t\t\t\t\t");}

        printf("%s com %s e %s", P2arma, P2acc1, P2acc2);
        printf("\nSorte: %d%c\t\t\t\t\t\t\t\tSorte: %d%c",P1sorte ,37 , P2sorte, 37);
        printf("\nDefesa: %d\t\t\t\t\t\t\t\tDefesa: %d\n",P1defesa, P2defesa);
        printf("\n/////////////////////////////////////////////////Player 1 Ganhou!!//////////////////////////////////////////////////////\n\n");
        printf("\n\n      \xdc\xdb\xdb\xdc\n");
        printf("       \xdb\xdb    Ja tombaste nabo!\n");
        printf("    \xdc\xdc\xdc\xdb\xdc\xdc\xdc\n");
        printf("       \xdb\n");
        printf("       \xdb\n");
        printf("       \xdb\n");
        printf("       \xdb\n");
        printf("       \xdf\xdf\t\t\t\t\t\t\t\t\t\xdf\xdb\xdb\xdf   \xdb\xdb\xdb\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdb\n");
    }

void P2win()
    {
    system("cls");
        printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("P1 Vidas: %d\t\t\t\t\t\t\t\tP2 Vidas: %d", P1vida, P2vida);
        printf("\n%s\t\t\t\t\t\t\t%s", P1capacete, P2capacete);
        printf("\n%s %d%c\t\t\t\t\t\t\t%s %d%c", P1armadura, P1armaduradur, 37, P2armadura, P2armaduradur, 37);
        printf("\n%s com %s e %s",P1arma, P1acc1, P1acc2);
        length=strlen(P1arma)+strlen(P1acc1)+strlen(P1acc2);
        if(length>39)
                {
                printf("\t\t\t");
                }else if(length>=32)
                    {printf("\t\t\t\t");}else{printf("\t\t\t\t\t");}

        printf("%s com %s e %s", P2arma, P2acc1, P2acc2);
        printf("\nSorte: %d%c\t\t\t\t\t\t\t\tSorte: %d%c",P1sorte ,37 , P2sorte, 37);
        printf("\nDefesa: %d\t\t\t\t\t\t\t\tDefesa: %d\n",P1defesa, P2defesa);
        printf("\n/////////////////////////////////////////////////Player 2 Ganhou!!//////////////////////////////////////////////////////\n\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\xdc\xdb\xdb\xdc\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t \xdb\xdb\n");
        printf("   \xdc\xdb\xdb\xdc\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf("    \xdb\xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf("    \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf("    \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf("    \xdb\t\t\t\t\t\t\t\t\t\t\t\t\t  \xdb\n");
        printf(" \xdb\xdf\xdf\xdf\t\t\t\t\t\t\t\t\t\t\t\t\t \xdf\xdf\n");
sleep(1);
            system("cls");
        printf("////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("P1 Vidas: %d\t\t\t\t\t\t\t\tP2 Vidas: %d", P1vida, P2vida);
        printf("\n%s\t\t\t\t\t\t\t%s", P1capacete, P2capacete);
        printf("\n%s %d%c\t\t\t\t\t\t\t%s %d%c", P1armadura, P1armaduradur, 37, P2armadura, P2armaduradur, 37);
        printf("\n%s com %s e %s",P1arma, P1acc1, P1acc2);
        length=strlen(P1arma)+strlen(P1acc1)+strlen(P1acc2);
        if(length>39)
                {
                printf("\t\t\t");
                }else if(length>=32)
                    {printf("\t\t\t\t");}else{printf("\t\t\t\t\t");}

        printf("%s com %s e %s", P2arma, P2acc1, P2acc2);
        printf("\nSorte: %d%c\t\t\t\t\t\t\t\tSorte: %d%c",P1sorte ,37 , P2sorte, 37);
        printf("\nDefesa: %d\t\t\t\t\t\t\t\tDefesa: %d\n",P1defesa, P2defesa);
        printf("\n/////////////////////////////////////////////////Player 2 Ganhou!!//////////////////////////////////////////////////////\n\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t  \xdc\xdb\xdb\xdc\n");
        printf("\t\t\t\t\t\t\t\t\t      Ja tombaste nabo!    \xdb\xdb\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t \xdc\xdc\xdc\xdb\xdc\xdc\xdc\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t    \xdb\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t    \xdb\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t    \xdb\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t    \xdb\n");
        printf(" \xdb\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdb\xdb\xdb      \xdf\xdb\xdb\xdf\t\t\t\t\t\t\t\t\t   \xdf\xdf\n");
    }

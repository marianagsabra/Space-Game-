#include <stdio.h>
#include <ncurses.h> 
#include <time.h> 
#include <stdlib.h>
#include <unistd.h>

#define t 20 // número maximo de pontos

int main(void)
{

int x=10; // inicio em x
int x_o; // inicio da comida
int y=10; // inicio em y
int y_o; // inicio da comida
int objeto=1; // objeto
int posicao_objeto; // posicao que recebe variaveis aleatorias
int j=1;
int ponto_inicial=1; //quantidade de pontos
int movimento = 0; // teclas saida apos receber letra
int velocidade_movimento; // velocidade
int teclado; // teclas
int c_nova = 0;
int mod_x[t]; // x modificado
int mod_y[t]; // y modificado
int rastro_x; // rastro x
int rastro_y; // rastro y
    
char fim_ou_loop=0; // determinal quando acaba o loop
char EA=0; 
char vazio=0; 
char nome[2];

initscr();
keypad(stdscr, true);
cbreak();
noecho();
curs_set(0);

    move(1,0); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 1        

    move(1, 100); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 100

    move(1, 70);
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 70
        
    mvprintw(1,0,"-----------------------------------------------------------------------------------------------------");
    mvprintw(20,0,"-----------------------------------------------------------------------------------------------------");

    mvprintw(10,30, "Space Game");
    mvprintw(12,13, "criado por Mariana Sabra e Yasmin Kioko");
    
    getch();
    
    mvprintw(10,20, "                                       ");
    mvprintw(12,10, "Neste jogo, iremos ajudar a Apollo 11 à chegar na Lua!");
    
 
   getch();
    
    srand((unsigned)time(NULL)); // inicia aleatoriedade

       mvprintw(5,88, "Sair - ESC"); // imprime mensagem na linha 2 e coluna 110
       mvprintw(3,74, "Pressione para iniciar"); 
       
       mvprintw(5,75, "w"); 
       mvprintw(6,73, "a   d");
       mvprintw(7,75, "s");


 curs_set(1); // esconde cursor
 echo();
 
mvprintw(12,10,"                                                            ");
mvprintw(10,10,"                                                            ");
mvprintw(10,15,"Escolha a velocidade inicial (0-9):");
mvscanw(10,51,"%i",&velocidade_movimento);

mvprintw(11,15,"Digite sua inicial:");
mvscanw(11,35,"%s",&nome);

mvprintw(11,15,"                              ");



velocidade_movimento = (235000/j++) - (velocidade_movimento * 20000); // decide qual sera a velocidade inicial

curs_set(0);
noecho();
nodelay(stdscr,1);

mvprintw(10,15,"                                               "); // apaga o que esta escrito


    while(fim_ou_loop==0) // loop ate que fim_ou_loop==1
{
        mod_x[(c_nova)] = x;  // armazerna em c_nova o valor de x
        mod_y[(c_nova)] = y; //  armazerna em c_nova o valor de y
        
        rastro_x = mod_x[(c_nova)]; 
        rastro_y = mod_y[(c_nova)];
        c_nova++;
        
if(c_nova==t)
{
c_nova=0;
}

mvprintw(7,88,"Objetos: 1 ");
mvprintw(7,88,"Objetos: %i ",ponto_inicial);
        
teclado=getch();

switch(teclado)
{
    
case 's':
    movimento = 1;
break;

case 'w':
    movimento = 2;
break;

case 'd':
    movimento = 3;
break;

case 'a':
    movimento = 4;
break;

case 27:
    fim_ou_loop = 1; // sai do jogo
break;

default:
break;
}

switch (movimento)
{
case 1:
x++;
vazio=1;
usleep(velocidade_movimento);
break;

case 2:
x--;
vazio=1;
usleep(velocidade_movimento);
break;

case 3:
y++;
vazio=1;
usleep(velocidade_movimento - 10000);
break;

case 4:
y--;
vazio=1;
usleep(velocidade_movimento - 10000);
break;

default:
break;
}

// imprimindo EA
if (EA!=1)
{
mvprintw(x,y,"%s",nome);
}

//apagando EA

if (vazio!=0) // apaga o rastro
{
mvprintw(rastro_x,rastro_y," ");
}
            
// encostar no objeto

if (x==x_o && y==y_o)
{
objeto=1;
ponto_inicial++;
puts("\a");
}


//objeto

while (objeto==1 && vazio==1)
{
x_o = rand () % 18 + 2; 
y_o = rand () % 69 + 1;
            
if (posicao_objeto == 0)
{
mvprintw(x_o,y_o,"*");
objeto=0; 
}

posicao_objeto = 0; 

}

// FASES

if (ponto_inicial == 5)
{

mvprintw(10,75, "    ___");
mvprintw(11,75, "  //o o\\\\ ");
mvprintw(12,75, "  \\\\_v_// ");
mvprintw(13,75, "  /|   |\\ ");
mvprintw(14,75, " / |___| \\ ");
mvprintw(15,75, " OO| | |OO ");
mvprintw(16,75, "   | | | ");
mvprintw(17,75, "   @@|@@ ");
}

if (ponto_inicial == 10)
{
mvprintw(10,75, "     /\\");
mvprintw(11,75, "    /  \\ ");
mvprintw(12,75, "   /____\\ ");
mvprintw(13,75, "   |    | ");
mvprintw(14,75, "  /| O  |\\ ");
mvprintw(15,75, " / | O  | \\");
mvprintw(16,75, "/__|    |__\\ ");
mvprintw(17,75, "   |____|    ");



}

if (ponto_inicial == 15)
{

mvprintw(10,75, "     /\\");
mvprintw(11,75, "    /  \\ ");
mvprintw(12,75, "   /____\\ ");
mvprintw(13,75, "   |    | ");
mvprintw(14,75, "  /| O  |\\ ");
mvprintw(15,75, " / | O  | \\");
mvprintw(16,75, "/__|    |__\\ ");
mvprintw(17,75, "   |____|    ");
mvprintw(18,75, "    ****    ");
mvprintw(19,75, "    ****     ");


}

// GANHAR

if (ponto_inicial == t-1)
{
    
clear();
getch();

    move(1,0); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 1        

    move(1, 100); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 100
    
mvprintw(1,0,"-----------------------------------------------------------------------------------------------------");
mvprintw(20,0,"-----------------------------------------------------------------------------------------------------");

mvprintw(10,40,"Você conseguiu %s!", nome);

mvprintw(11,40,"Você pegou %i elementos.", t);
mvprintw(12,40,"E ajudou nossos astronautas a chegarem na Lua!");
            
nodelay(stdscr, FALSE);
getch();
fim_ou_loop=1;
            
}

// PERDER

if (x == 1) // se encostar na barra inicial, perde
{
clear();
getch();

    move(1,0); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 1        

    move(1, 100); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 100
    
mvprintw(1,0,"-----------------------------------------------------------------------------------------------------");
mvprintw(20,0,"-----------------------------------------------------------------------------------------------------");

mvprintw(10,40,"Nao foi dessa vez!!");
mvprintw(12,40,"Tente novamente");
nodelay(stdscr, FALSE);
            
getch();
fim_ou_loop=1; // sai do jogo
}

else if (x == 20)
{
clear();
getch();

    move(1,0); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 1        

    move(1, 100); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 100

mvprintw(1,0,"-----------------------------------------------------------------------------------------------------");
mvprintw(20,0,"-----------------------------------------------------------------------------------------------------");

mvprintw(10,40,"Nao foi dessa vez!!");
mvprintw(12,40,"Tente novamente");
nodelay(stdscr, FALSE);
            
getch();
fim_ou_loop=1; // sai do jogo
}

else if (y == 70)
{
clear();
getch();

    move(1,0); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 1        

    move(1, 100); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 100

mvprintw(1,0,"-----------------------------------------------------------------------------------------------------");
mvprintw(20,0,"-----------------------------------------------------------------------------------------------------");
    
mvprintw(10,40,"Nao foi dessa vez!!");
mvprintw(12,40,"Tente novamente");
nodelay(stdscr, FALSE);
            
getch();
fim_ou_loop=1; // sai do jogo
}

else if (y == 0)
{
clear();
getch();


move(1,0); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 1        

    move(1, 100); 
    vline(ACS_VLINE, 20); // inclui linha do tamanho 20 na linha 1 e coluna 100
mvprintw(1,0,"-----------------------------------------------------------------------------------------------------");
mvprintw(20,0,"-----------------------------------------------------------------------------------------------------");

mvprintw(10,40,"Nao foi dessa vez!!");
mvprintw(12,40,"Tente novamente");
nodelay(stdscr, FALSE);
            
getch();
fim_ou_loop=1; // sai do jogo
}

}

endwin();
return 0;
}

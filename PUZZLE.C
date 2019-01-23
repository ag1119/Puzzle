#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

char a[21][60],k,l; int b[5],c[9],n=5,m=10,o=11,p=4,r=7,s=8;
int i,j,moves=0;

void ini()
{
for(i=0;i<21;i++)
{for(j=0;j<60;j++)
a[i][j]=' '; }
for(i=1;i<5;i++){b[i]=n;n=n+4;}
for(i=1;i<8;i=i+2){c[i]=m;m=m+6;}
for(i=2;i<9;i=i+2){c[i]=o;o=o+6;}
for(i=3;i<20;i=i+4)for(j=8;j<33;j++)a[i][j]=16;
for(i=8;i<38;i=i+6)for(j=3;j<20;j++)a[j][i]=31;

a[b[1]][c[1]]=48;a[b[1]][c[2]]=49;      a[b[1]][c[3]]=48;a[b[1]][c[4]]=52;
a[b[1]][c[5]]=49;a[b[1]][c[6]]=53;      a[b[1]][c[7]]=48;a[b[1]][c[8]]=55;

a[b[2]][c[1]]=48;a[b[2]][c[2]]=56;      a[b[2]][c[3]]=49;a[b[2]][c[4]]=48;
a[b[2]][c[5]]=48;a[b[2]][c[6]]=50;      a[b[2]][c[7]]=49;a[b[2]][c[8]]=49;

a[b[3]][c[1]]=49;a[b[3]][c[2]]=52;      a[b[3]][c[3]]=48;a[b[3]][c[4]]=51;
a[b[3]][c[5]]=48;a[b[3]][c[6]]=54;      a[b[3]][c[7]]=49;a[b[3]][c[8]]=51;

a[b[4]][c[1]]=49;a[b[4]][c[2]]=50;      a[b[4]][c[3]]=48;a[b[4]][c[4]]=57;
a[b[4]][c[5]]=48;a[b[4]][c[6]]=53;      a[b[4]][c[7]]=' ';a[b[4]][c[8]]=' ';


}

void gen()
{ for(i=0;i<21;i++)
{for(j=0;j<60;j++)
printf("%c",a[i][j]); printf("\n");
}gotoxy(50,3);printf("moves=%d",moves); }


int navigate(int d)
{switch(d)
{
case 72:if(p>1) {;k=a[b[p]][c[r]];a[b[p]][c[r]]=a[b[p-1]][c[r]];a[b[p-1]][c[r]]=k;
l=a[b[p]][c[s]];a[b[p]][c[s]]=a[b[p-1]][c[s]];a[b[p-1]][c[s]]=l;p=p-1;moves++;}
else {sound(800);delay(500);nosound();}
break;

case 80:if(p<4){k=a[b[p]][c[r]];a[b[p]][c[r]]=a[b[p+1]][c[r]];a[b[p+1]][c[r]]=k;
l=a[b[p]][c[s]];a[b[p]][c[s]]=a[b[p+1]][c[s]];a[b[p+1]][c[s]]=k;p=p+1;moves++;}
else {sound(800);delay(500);nosound();}
break;

case 75:if(r>1&&s>2){k=a[b[p]][c[r-2]];a[b[p]][c[r-2]]=a[b[p]][c[r]];a[b[p]][c[r]]=k;
l=a[b[p]][c[s-2]];a[b[p]][c[s-2]]=a[b[p]][c[s]];a[b[p]][c[s]]=l;r=r-2;s=s-2;moves++;}
else {sound(800);delay(500);nosound();}
break;

case 77:if(r<7&&s<8){k=a[b[p]][c[r+2]];a[b[p]][c[r+2]]=a[b[p]][c[r]];a[b[p]][c[r]]=k;
l=a[b[p]][c[s+2]];a[b[p]][c[s+2]]=a[b[p]][c[s]];a[b[p]][c[s]]=l;r=r+2;s=s+2;moves++;}
else {sound(800);delay(500);nosound();}
break;
case 27:exit(0);
}return 0;}



int getkey()
{int ch;
ch=getch();
if(ch==0)
{ch=getch();
return ch;}
return ch;
}

void result()
{if(
a[5][10]==' '&&a[5][11]==' '&&a[5][16]==48&&a[5][17]==49
&&a[5][22]==48&&a[5][23]==50&&a[5][28]==48&&a[5][29]==51

&&a[9][10]==48&&a[9][11]==52&&a[9][16]==48&&a[9][17]==53
&&a[9][22]==48&&a[9][23]==54&&a[9][28]==48&&a[9][29]==55

&&a[13][10]==48&&a[13][11]==56&&a[13][16]==48&&a[13][17]==57
&&a[13][22]==49&&a[13][23]==48&&a[13][28]==49&&a[13][29]==49

&&a[17][10]==49&&a[17][11]==50&&a[17][16]==49&&a[17][17]==51
&&a[17][22]==49&&a[17][23]==52&&a[17][28]==49&&a[17][29]==53)
{gotoxy(11,14);printf("BINGO! YOU SOLVED THE PUZZLE");
gotoxy(13,14);printf("YOU SOLVED IT IN %d MOVES",moves);delay(5000);
exit(0); }}


void main()
{int d;
clrscr();
textbackground(YELLOW);
textcolor(BLACK);
ini();
v:
clrscr();
gen();
d=getkey();
navigate(d);
result();
goto v;
 }
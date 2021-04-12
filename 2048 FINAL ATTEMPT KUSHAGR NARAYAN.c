#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//__________________________________
int field[5][5]={};
//________________________________________________________________________________________________________________________________________________________


//MAIN MENU

void ts()
{

   printf("\n\t\t\t\t\t\t2048\n");
   printf("\t\t\t\t\t\t1.PLAY\n");
   printf("\t\t\t\t\t\t2. EXIT\n");
   printf("\n\n\n\n\nINSTRUCTIONS:THE DIRECTION IS CONTROLLED BY \nW->UP\nS->DOWN\nA->RIGHT\nD->LEFT");


}
//________________________________________________________________________________________________________________________________________________________
//NUMBER SPAWNER AND PRINTER

void spawn(int a[][5])
{ int c1,c2,b[2]={2,4};

    do
    {srand((time(0)));
    c1=rand()%5;
    c2=rand()%5; //GENERATE COORDINATES TO PLACE NEW NUMBER
    if(a[c1][c2]==0)
    {
        a[c1][c2]=b[rand()%2];//PLACES 2 OR 4 AT THAT POINT
         break;
    }
    }while(1);

   for(int i=0;i<5;i++)
    {

       printf("\n----------\n");//CREATES LINES

   for(int j=0;j<5;j++)
   {
       if(c1==i&&c2==j)
        printf("|%d",a[c1][c2]);
       else                      //CREATES THE STRUCTURE
       {
        if(a[i][j]>0)
        printf("|%d",a[i][j]);
        else
            printf("| ");
       }
   }
    }
printf("\n----------\n");
}
//___________________________________________________________________________________________________________________________________________________________

//COMBINERS AND MOVERS

//UP COMBINER                 ??UP WAS PRESSED AND NOW THIS CODE COMBINES!!!!!!!! COMBINES!!!!COMBINES THERE SHOULD BE A FUNCTION WHICH MOVES THESE TILES!!
 void upc(int a[][5])
 {for(int j=0;j<5;j++)
  { for(int i=0;i<4;i++)
   {
      if(a[i][j]==a[i+1][j]&&a[i][j]!=0)
      {
         a[i][j] =2*a[i][j];                  //COMBINES THE 2 EQUAL NUMBERS NEXT TO EACH OTHER
          if(i=3)
            a[i+1][j]=0;
            else
          {for(int m=i+1;m<4;m++)
          {
              a[m][j]=a[m+1][j];           //UNEQUAL NUMBERS MOVE UP BY ONE SPOT
              a[m+1][j]=0;                 //EMPTY TRAY=0,NOTHING SPAWNS

          }
      }
      }}}}
//_________________________________________________________________________________________________________________________________________________________

//PRESS UP
void pw(char w)
{
 /* OK so this should work if there is nothing in the way it should move the number up but if there is something
  blocking the way then it should not move up*/
  /*This works of the w command and function should end by calling w function*/
  for(int j=0;j<5;j++)
  {for(int i=1;i<=4;i++)
   {for(int v=i;v>0;v--) //controls the cycle
   {  int y=v; //changes itself
     if(field[y-1][j]>0)
        break;         //CANNOT MOVE SPCAE IF THERE IS NUMBER
       else
     {field[y-1][j]=field[y][j];
     field[y][j]=0;
       y--;  //MOVES sPACE SINCE CLEAR
     }
   }
   upc(field);
   break; //TRIGGERS COMBINE AND EXITS THE LOOP
   }

  }}
//_________________________________________________________________________________________________________________________________________________________PLEASE WORK

//DOWN COMBINER
//NEXT TO EACH OTHER AFTER PRESSING DOWN
 void downc(int a[][5])
 {for(int j=0;j<5;j++)
  { for(int i=4;i>0;i--)
   {
      if(a[i][j]==a[i-1][j]&&a[i][j]!=0)
      {
         a[i][j] =2*a[i][j];                  //COMBINES THE 2 EQUAL NUMBERS NEXT TO EACH OTHER
          if(i=1)
            a[i-1][j]=0;
            else
          {for(int m=i-1;m>0;m--)
          {
              a[m][j]=a[m-1][j];           //UNEQUAL NUMBERS MOVE DOWN BY ONE SPOT
              a[m-1][j]=0;                 //EMPTY TRAY=0,NOTHING SPAWNS

          }
      }
      }}}}
//___________________________________________________________________________________________________________________________________________________________

//press Down

void ps(char s)
{
     for(int j=0;j<5;j++)
  {for(int i=3;i>=0;i--)
   {for(int v=4-i;v>0;v--) //controls the cycle
   {  int y=i; //changes itself
     if(field[y+1][j]>0)
        break;         //CANNOT MOVE SPCAE IF THERE IS NUMBER
       else
     {field[y+1][j]=field[y][j];
     field[y][j]=0;
       y++;  //MOVES sPACE SINCE CLEAR
     }
   }
   downc(field);
   break; //TRIGGERS COMBINE AND EXITS THE LOOP
   }

  }}
//________________________________________________________________________________________________________________________________________________________________
//RIGHT COMBINER
//NEXT TO EACH OTHER AFTER PRESSING RIGHT
 void rightc(int a[][5])
 {for(int i=0;i<5;i++)
  { for(int j=4;j>0;j--)
   {
      if(a[i][j]==a[i][j-1]&&a[i][j]!=0)
      {
         a[i][j] =2*a[i][j];                  //COMBINES THE 2 EQUAL NUMBERS NEXT TO EACH OTHER
          if(i=1)
            a[i][j-1]=0;
            else
          {for(int m=j-1;m>0;m--)
          {
              a[i][m]=a[i][m-1];           //UNEQUAL NUMBERS MOVE RIGHT BY ONE SPOT
              a[i][m-1]=0;                 //EMPTY TRAY=0,NOTHING SPAWNS

          }
      }
      }}}}

//___________________________________________________________________________________________________________________________________________________________
//press right
void pd(char d)
{
 for(int i=0;i<5;i++)
  {for(int j=3;j>=0;j--)
   {for(int v=4-j;v>0;v--) //controls the cycle
   {  int y=j; //changes itself
     if(field[i][y+1]>0)
        break;         //CANNOT MOVE SPCAE IF THERE IS NUMBER
       else
     {field[i][y+1]=field[i][y];
     field[i][y]=0;
       y++;  //MOVES sPACE SINCE CLEAR
     }
   }
   rightc(field);
   break; //TRIGGERS COMBINE AND EXITS THE LOOP
   }

  }
}
 //_________________________________________________________________________________________________________________________________________________________\
 //press left
  void pa(char a)
  {
       for(int i=0;i<5;i++)
  {for(int j=1;j<=4;j++)
   {for(int v=i;v>0;v--) //controls the cycle
   {  int y=v; //changes itself
     if(field[i][y-1]>0)
        break;         //CANNOT MOVE SPCAE IF THERE IS NUMBER
       else
     {field[i][y-1]=field[i][y];
     field[i][y]=0;
       y--;  //MOVES sPACE SINCE CLEAR
     }
   }
   leftc(field);
   break; //TRIGGERS COMBINE AND EXITS THE LOOP
   }

  }
  }
//______________________________________________________________________________________________________________________________________________
//COMBINERS AND MOVERS

//LEFT COMBINER                 //UP WAS PRESSED AND NOW THIS CODE COMBINES!!!!!!!! COMBINES!!!!COMBINES THERE SHOULD BE A FUNCTION WHICH MOVES THESE TILES!!
 void leftc(int a[][5])
 {for(int i=0;i<5;i++)
  { for(int j=0;j<4;j++)
   {
      if(a[i][j]==a[i][j+1]&&a[i][j]!=0)
      {
         a[i][j] =2*a[i][j];                  //COMBINES THE 2 EQUAL NUMBERS NEXT TO EACH OTHER
          if(i=3)
            a[i][j+1]=0;
            else
          {for(int m=j+1;m<4;m++)
          {
              a[i][m]=a[i][m+1];           //UNEQUAL NUMBERS MOVE LEFT BY one SPOT
              a[i][m+1]=0;                 //EMPTY TRAY=0,NOTHING SPAWNS

          }
      }
      }}}}
//_________________________________________________________________________________________________________________________________________________________


//__________________________________________________________________________________________________________________________________________________________
//___________________________________________________________________

/* int field[5][5];
 void ts();
void spawn(a[][5])
void upc(int a[][5]);
void downc(int a[][5]);
void leftc(int a[][5]);
void rightc(int a[][5]);            //REMINDER OF ALL FUNCTIONS USED
void pw(char w);
void ps(char s);
void pa(char a);
void pd(char d);

*/
//________________________________________________________________________

int main()
{
int flag=1;
char c; int w;
    ts();
    scanf("%d",&w);
 if(w==1)
 {
   while(flag==1)
   {
       system("cls");
    spawn(field);

       scanf("%c",&c);
        if(c=='w'||c=='W')
         pw(c);
   else if(c=='s'||c=='S')
       ps(c);
   else if(c=='a'||c=='A')
       pa(c);
   else if(c=='d'||c=='D')
        pd(c);

for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
    {
        if(field[i][j]==0)
        {
            flag=1;


        }
        else
            flag=0;

      if(flag==1)
                break;
    }
    if(flag==1)
        break;
}

   }
 }

 if(w=='2')
    printf("PRESS ANY BUTTON TO QUIT");
 system("pause");

return 0;


return 0;
}

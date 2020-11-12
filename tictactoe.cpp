#include <iostream>
#include<cstdlib>
using namespace std;
char plr;

char randpos()
{
  return  (char)((rand()%9)+97);
}

int check(char arr[][3])
{
   int c=0,q=0,k=0,l=0;
  for(int i=0;i<3;i++)
  {
   for(int j=0;j<3;j++)
    {
      if((arr[i][0]==arr[i][1]) && (arr[i][1]==arr[i][2])){
      plr=arr[i][0];
      return 1;
      }
      if((arr[i][j]==arr[i+1][j]) && (arr[i+1][j]==arr[i+2][j])){
      plr=arr[i][j];
      return 1;
      }
      if(( (arr[i][j]==arr[i+1][j-1]) && j>0) && ((arr[i+1][j-1]==arr[i+2][j-2]) && j>1)){
      plr=arr[i][j];
      l++;
      }
    }
    if(arr[i][i]==arr[i+1][i+1])
    {
     plr=arr[i][i];
     c++;
    }
  }

 if(c==2 || l==1)
 {
  return 1;
 }
 else
 {
 return 0;
 }
}

char check2(char arr[][3],char sel)
{
   for(int i=0;i<3;i++)
   {
    for(int j=0;j<3;j++)
    {
      if((arr[i][0]==sel) && (arr[i][0]==arr[i][1]) && (arr[i][2]!='x' && arr[i][2]!='o'))
        return arr[i][2];
      if((arr[i][1]==sel) && (arr[i][1]==arr[i][2]) && (arr[i][0]!='x' && arr[i][0]!='o'))
        return arr[i][0];
      if((arr[0][j]==sel) && (arr[0][j]==arr[1][j]) && (arr[2][j]!='x' && arr[2][j]!='o'))
        return arr[2][j];
      if((arr[1][j]==sel) && (arr[1][j]==arr[2][j]) && (arr[0][j]!='x' && arr[0][j]!='o'))
        return arr[0][j];
      if((arr[0][0]==sel) && (arr[0][0]==arr[1][1]) && (arr[2][2]!='x' && arr[2][2]!='o'))
        return arr[2][2];
      if((arr[1][1]==sel) && (arr[1][1]==arr[2][2]) && (arr[0][0]!='x' && arr[0][0]!='o'))
        return arr[0][0];
      if((arr[1][1]==sel) && (arr[1][1]==arr[0][2]) && (arr[2][0]!='x' && arr[2][0]!='o'))
        return arr[2][0];
      if((arr[2][0]==sel) && (arr[2][0]==arr[1][1]) && (arr[0][2]!='x' && arr[0][2]!='o'))
        return arr[0][2];
    }
   }

   return '\0' ;
}

int main()
{
    int i=0,j=0,count=97,loop=0,k=0,ch,status=0;
    char c='o',a[3][3],ctemp='x',pos='q';
    char currplr,sel,pc,rpos,notavailpos[9];

   cout << "welcome to tic-tac-toe:\n" ;

     cout << "\nrules:" << "\n" ;
     cout << "\n--- the given alphabets represents the positions ----- \n";
     cout << "--- to choose the position type the respective alphabet -----\n" ;

     for(i=0;i<3;i++)
      {
         for(j=0;j<3;j++)
         {
            a[i][j]=count++;
            cout << a[i][j] << " " ;
         }
          cout << "\n" ;
      }

     cout << "\n1.player vs player\n2.player vs pc\n" ;
     cout << "\nenter choice:";
     cin >> ch;

     if(ch==1)
     {
       cout << "player 1 : x\n";
       cout << "player 2 : o\n";
     }

     if(ch==2)
     {
       cout << "\nselect 'x' or 'o' to play\n";
       cin >> sel ;
       if(sel=='x')
       pc='o';
       else if(sel=='o')
       pc='x';
       currplr=sel;
     }

       while(ch==1)
       {
        cout << "choose the position to enter :\n";
        cin >> pos;

        cout << "enter x or o:\n";
        ctemp=c;
        cin>>c;
        if(loop==0)
        {
         if(c=='x')
         ctemp='o';
         else if(c=='o')
         ctemp='x';
        }

       if(c==ctemp)
       {
        cout << "consequitive plays not allowed\n" ;
        continue;
       }

       system("clear");

      if((c=='x' && ctemp=='o') || (c=='o' && ctemp=='x'))
      {
         for(i=0;i<3;i++)
         {
           for(j=0;j<3;j++)
           {
              if(a[i][j]==pos)
              {
                 a[i][j]=c;
              }
              cout << a[i][j] << "  ";
           }
             cout << "\n" << "-------\n" ;
         }
      }

      if(check(a)==1)
      {
        if(plr=='x')
        {
         cout << "\nplayer " << 1 << " wins\n";
         break;
        }
        else if(plr=='o')
        {
          cout << "\nplayer " << 2 << " wins\n";
          break;
        }
      }

      else if(check(a)==0 && loop==8)
      {
        cout << "its a draw\n";
        break;
      }
      loop++;

     }

    while(ch==2)
     {
          if(currplr==sel)
          {
           cout << "\nchoose the position to enter :\n";
           cin >> pos;
          }

         if(currplr==pc)
         {
           status=0;
            while(1)
            {
              rpos=check2(a,sel);

              if(rpos!='\0')
              {
                pos=rpos;
                break;
              }
               else
               {
                 rpos=randpos();
                 pos=rpos;
               } 
  
              if(pos<97 || pos>105)
                continue;

              for(i=0;i<k;i++)
              {
                if(rpos==notavailpos[i])
                {
                 status=0;
                 break;
                }
                else
                status=1;
              }

              if(status==1)
              {
               pos=rpos;
               break;
              }

            }
         }

        system("clear");

       for(i=0;i<3;i++)
       {
         for(j=0;j<3;j++)
         {
           if(a[i][j]==pos)
           {
             ctemp=a[i][j];
             notavailpos[k]=ctemp;
             k++;
             a[i][j]=currplr;
           }
           cout << a[i][j] << "  " ;
         }
           cout << "\n" << "-------\n" ;
       }

       if(check(a)==1)
       {
         if(plr==sel)
         {
          cout << "\nplayer " << "wins\n";
          break;
         }
         else if(plr==pc)
         {
           cout << "\npc " << "wins\n";
           break;
         }
       }

       else if(check(a)==0 && loop==8)
       {
         cout << "its a draw\n";
         break;
       }

       if(currplr==sel)
       currplr=pc;

       else if(currplr==pc)
       currplr=sel;

       loop++;
     }
}
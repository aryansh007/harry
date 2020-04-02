#include <bits/stdc++.h>
#include <math.h>
#include <windows.h>

using namespace std;


void two(int n)
{   cout<<"toss"<<endl;
    srand(time(0));
    Sleep(2000);
    int p1,p2,i = rand()%2;

    if(i==0)
        cout<<"Player 1 won toss"<<endl;
    else
        cout<<"Player 2 won toss"<<endl;

    cout<<"--------start--------"<<endl;


    while(1){

    Sleep(2000);

    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==1)
               cout<<"Player 1 lost "<<endl;
          else
               cout<<"Player 2 lost "<<endl;
      }
      if(n==1){
        if(i==0)
           cout<<"Player 1 lost "<<endl;
        else
           cout<<"Player 2 lost "<<endl;
      }
    break;
    }
  l: if(i==0)
       cout<<"Player 1 chance "<<endl;
    else
       cout<<"Player 2 chance "<<endl;

    cin>>p1;
    if(p1<4 && p1>=1)
    n=n-p1;
    else
    { cout<<"Invalid move"<<endl;
      goto l;
    }
     cout<<"Remaining Sticks :  "<<n<<endl;
    Sleep(2000);

    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==0)
               cout<<"Player 1 lost "<<endl;
          else
               cout<<"Player 2 lost "<<endl;
      }
      if(n==1){
        if(i==1)
           cout<<"Player 1 lost "<<endl;
        else
           cout<<"Player 2 lost "<<endl;
      }
    break;
    }

   k: if(i==1)
       cout<<"Player 1 chance "<<endl;
    else
       cout<<"Player 2 chance "<<endl;

    cin>>p2;
    if(p2<4 && p2>=1)
    n=n-p2;
    else
    { cout<<"Invalid move"<<endl;
      goto k;
    }

     cout<<"Remaining Sticks :  "<<n<<endl;
}
}
struct r{
  int v;
  int d;
  int i;

};

r t[54];
r f[54];

r minimax(int n,int depth,bool player,int alpha,int beta)
{  r g,j,k;
   j.v=0;j.d=0;j.i=0;
   if(n==1)
    {
        if(player)
        {
             g.v = -10;
             g.d = depth;
             g.i = 0;
             return g;
        }
        else
         {
             g.v = 10;
             g.d = depth;
             g.i =0;
             return g;
        }
    }
    int i;
    if(player)
    {  int mx=-999;
       int m=999;
        for(i=3;i>=1;i--)
        {  if(n-i>=1)
            {
            j= minimax(n-i,depth+1,false,alpha,beta);
            if(j.v>=mx && j.v!=0)
            {  if(j.v==mx)
                { if(j.d<m)
                    {
                    g.v=j.v;
                    g.d=j.d;
                    g.i = i;
                    }
                }
               else
                   {
                    mx=j.v;
                    g.v=j.v;
                    g.d=j.d;
                    g.i = i;
                    }
                if(j.v==10)
                    break;
            }
            alpha=max(alpha,j.v);
            if(beta<alpha)
                break;
           }
        }
     return g;
    }
    else
    {
        int m =999;
       int mx=999;
        for(i=3;i>=1;i--)
        { if(n-i>=1)
            {
              j= minimax(n-i,depth+1,true,alpha,beta);
           if(j.v<=mx && j.v!=0)
            {  if(j.v==mx)
                { if(j.d<m)
                    {
                    g.v=j.v;
                    g.d=j.d;
                    g.i = i;
                    }
                }
               else
                   {
                    mx=j.v;
                    g.v=j.v;
                    g.d=j.d;
                    g.i = i;
                    }
                if(g.v==-10)
                    break;
            }
            beta=min(beta,j.v);

            if(beta < alpha )
                break;

           }
        }

     return g;
    }
}
void one(int n)
{
    cout<<"toss"<<endl;
    srand(time(0));
    Sleep(2000);
    int p1,p2,cpu,i = rand()%2;

    if(i==0)
        cout<<"Player won toss"<<endl;
    else
        cout<<"CPU won toss"<<endl;

    cout<<"--------start--------"<<endl;

 while(1){
    Sleep(2000);
    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==1)
               cout<<"Player lost "<<endl;
          else
               cout<<"CPU lost "<<endl;
      }
      if(n==1){
        if(i==0)
           cout<<"Player lost "<<endl;
        else
           cout<<"CPU lost "<<endl;
      }
    break;
    }
    if(i==0)
     {
        l:cout<<"Player chance "<<endl;
        cin>>p1;
        if(p1<4 && p1>=1)
        n=n-p1;
        else
        { cout<<"Invalid move"<<endl;
          goto l;
        }
     }
     else
       {
        r res;
        cout<<"CPU chance "<<endl;
        res = minimax(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU selects : "<<res.i<<endl;
        n=n-res.i;
       }

     cout<<"Remaining Sticks :  "<<n<<endl;
    Sleep(2000);
    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==0)
               cout<<"Player lost "<<endl;
          else
               cout<<"CPU lost "<<endl;
      }
      if(n==1){
        if(i==1)
           cout<<"Player lost "<<endl;
        else
           cout<<"CPU lost "<<endl;
      }
    break;
    }


   if(i==1)
     {
        k:cout<<"Player chance "<<endl;
        cin>>p2;
        if(p2<4 && p2>=1)
        n=n-p2;
        else
        { cout<<"Invalid move"<<endl;
          goto k;
        }
     }
     else
       {
        r res;
        cout<<"CPU chance "<<endl;
        res = minimax(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU selects : "<<res.i<<endl;
        n=n-res.i;
       }

        cout<<"Remaining Sticks :  "<<n<<endl;
  }


}


void autoplay(int n)
{
    cout<<"toss"<<endl;
    srand(time(0));
    Sleep(2000);
    int p1,cpu,i = rand()%2;

    if(i==0)
        cout<<"CPU 1 won toss"<<endl;
    else
        cout<<"CPU 2 won toss"<<endl;

    cout<<"-----------------------------start-----------------------------"<<endl;

 while(1){

    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==1)
               cout<<"CPU 1 lost "<<endl;
          else
               cout<<"CPU 2 lost "<<endl;
      }
      if(n==1){
        if(i==0)
           cout<<"CPU 1 lost "<<endl;
        else
           cout<<"CPU 2 lost "<<endl;
      }
    break;
    }
    if(i==0)
     {
        cout<<"CPU 1 chance "<<endl;
        r res;
        res = minimax(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU 1 selects : "<<res.i<<endl;
        n=n-res.i;
        cout<<"Remaining Sticks :  "<<n<<endl;
     }
     else
       {
        r res;
        cout<<"CPU 2 chance "<<endl;
        res = minimax(n,0,true,INT_MIN,INT_MAX);
        cout<<"CPU 2 selects : "<<res.i<<endl;
        n=n-res.i;
         cout<<"Remaining Sticks :  "<<n<<endl;
       }


    Sleep(2000);
    if(n==1 || n==0)
    { if(n==0)
      {
          if(i==0)
               cout<<"CPU 1 lost "<<endl;
          else
               cout<<"CPU 2 lost "<<endl;
      }
      if(n==1){
        if(i==1)
           cout<<"CPU 1 lost "<<endl;
        else
           cout<<"CPU 2 lost "<<endl;
      }
    break;
    }


   if(i==1)
     {
           r res;
        cout<<"CPU 1 chance "<<endl;
        res = minimax(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU 1 selects : "<<res.i<<endl;
        n=n-res.i;
         cout<<"Remaining Sticks :  "<<n<<endl;
     }
     else
       {
        r res;
        cout<<"CPU 2 chance "<<endl;
        res = minimax(n,0,false,INT_MIN,INT_MAX);
        cout<<"CPU 2 selects : "<<res.i<<endl;
        n=n-res.i;
         cout<<"Remaining Sticks :  "<<n<<endl;
       }
  }

}


int main()
{ int i,j,n,l;
  cout<<"------------------------------GAME----------------------------"<<endl;
  cout<<"Choose 1 option"<<endl;
  cout<<"1. Two Players"<<endl;
  cout<<"2. One player"<<endl;
  cout<<"3. AI vs AI"<<endl;
  cin>>i;
  for(n=0;n<54;n++)
    {f[n].v=20;
    t[n].v=20;}

  cout<<"Enter no. of Sticks"<<endl;
  cin>>n;
  r k;
  Sleep(2000);
  cout<<"RULE :  Enter no. between 1 and 3"<<endl;
  if(i==1)
     {
         two(n);
         cout<<"-------------------GAME OVER---------------"<<endl;

     }
  if(i==2)
     {
        one(n);
         cout<<"-------------------GAME OVER---------------"<<endl;
     }

  if(i==3)
  {
      autoplay(n);
       cout<<"-------------------GAME OVER---------------"<<endl;
  }

  return 0;
}

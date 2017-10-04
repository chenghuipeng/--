#include<stdio.h>
#include<string.h>
#include<ctype.h>


#include <algorithm>
#define maxn 10005


 const int LEN=5;
  const int MAX=100;
  const int y[]={0,0,1,-1};
  const int x[]={-1,1,0,0};
  char map[LEN][LEN];
  int tra[110];
  bool legal(int pos){
     return 0<=pos&&pos<LEN;
 }
 void Pmap(){
     for(int cow=0;cow<LEN;cow++)
        {
         printf("%c",map[cow][0]);
         for(int col=1;col<LEN;col++)
             printf(" %c",map[cow][col]);
         printf("\n");
     }
 }
 int main(){
 		freopen("data.in","r",stdin);
     tra['A']=0;
     tra['B']=1;
     tra['R']=2;
     tra['L']=3;

     bool first=true;
     int Case=0;
     int bx,by;
     while(gets(map[0])){
         if(map[0][0]=='Z')break;
         for(int col=1;col<LEN;col++)
             gets(map[col]);
         for(int i=0;i<LEN;i++)
             for(int j=0;j<LEN;j++)
                 if(map[i][j]==' '){
                     bx=i;by=j;
                 }
         bool ok=true;
         char c;
         while(scanf(" %c",&c),c!='0'){
             if(!ok)continue;
             int nx=bx+x[tra[c]],ny=by+y[tra[c]];
             if(!legal(nx)||!legal(ny)){
                 ok=false;
                 continue;
             }
             map[bx][by]=map[nx][ny];
             map[nx][ny]=' ';
             bx=nx;by=ny;
         }
         getchar();
         if(first)
             first=false;
         else
             printf("\n");
         printf("Puzzle #%d:\n",++Case);
         if(ok)
             Pmap();
         else
             printf("This puzzle has no final configuration.\n");
     }
     return 0;
 }


int solve3(){	
	freopen("data.in","r",stdin);
 	int cases =0;
 	bool line = false;
 	char initial [5][7];
 	while(gets(initial[0])){
	 	if(strcmp(initial[0],"Z") == 0)
	 		return 0;
	 	  gets(initial[1]);//读一行 
          gets(initial[2]);
          gets(initial[3]);
   	      gets(initial[4]);
			int blank_x,blank_y;
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<5;j++){
					if(initial[i][j] == ' ')
					{   blank_x = i;blank_y=j;
						i=j=5;
					}
				}
			}
		char command[1000];
		bool valid=true;
		bool exit_koro=false;
		while(!exit_koro && gets(command)){
			for(int i=0;command[i]!=0;i++){
				if(command[i]=='0' || !valid){
					exit_koro=true;
					break;
				}
				switch(command[i]){
					case 'A':
						if(blank_x==0)//最顶部 
							valid =false;
						else{
							initial[blank_x][blank_y] = initial[blank_x-1][blank_y];
						    initial[blank_x-1][blank_y]=' ';
						    blank_x--;
						}
						    
					break;
					case 'B':
						if(blank_x==4) //到最低部了 
							valid =false;
						else{
							initial[blank_x][blank_y] = initial[blank_x+1][blank_y];
						    initial[blank_x+1][blank_y]=' ';
						    blank_x++;
						}
					
					break;					
					case 'L':
						if(blank_y==0)//左边 
							valid =false;
						else{
							initial[blank_x][blank_y] = initial[blank_x][blank_y-1];
						    initial[blank_x][blank_y-1]=' ';
						    blank_y--;
						}
					break;					
					case 'R':
						if(blank_y==4)
							valid =false;
						else{
							initial[blank_x][blank_y] = initial[blank_x][blank_y+1];
						    initial[blank_x][blank_y+1]=' ';
						    blank_y++;
						}
					break;
				}
			}		
		}
		if(line) printf("\n");
		line = true;
		printf("Puzzle #%d:\n",++cases);
		if(valid){
  			for ( int i = 0; i < 5; i++ ) {
				  printf ("%c %c %c %c %c\n", initial [i] [0], initial [i] [1],
                        initial [i] [2], initial [i] [3], initial [i] [4]); 
  			}
		}
		else
		 printf ("This puzzle has no final configuration.\n");	
	 }
	    
}

 
void solve2(){
	char s[81];
	scanf("%s",s);
	int len = strlen(s);
	for(int i=1;i<=len;i++)  //假设i为最小周期串 
	{
		if(len%i == 0)
		{
			int ok =1;
			for(int j=i;j<len;j++)
		 		if(s[j]!=s[j%i])
			 	{
 					ok = 0;break;
		     	}
		    if(ok)	 
			{
				printf("%d\n",i);break;
			}
		
		}
	}

}

void solve1(){
	char s[1000];
char num[10];
		memset(s,0,sizeof(s));
	memset(num,0,sizeof(num));
	int t;
    scanf("%d",&t);
    while (t--) {
  	  scanf("%s",s);
  	  for(int i=0;s[i];i++)
  	  	num[s[i]-'0']++;
 	for(int i =0 ;i<10;i++)
 	  printf("%d ",num[i]);
    }
    printf("\n");
}
//3-2 分子量 
void solve(){
		const char name[] = "CHON";
	double weight[] = {12.01, 1.008, 16.00, 14.01};
	int t;
    char s[81];
	memset(s,0,sizeof(s));
    scanf("%d",&t);
    while (t--) {
  		scanf("%s",s);
        int num;
		double sum;
		int i=0;
		while(s[i]){
			int j;
			for(j=0;j<4;j++){
				if(s[i]==name[j]) break;
			}
			i++;
			num=1;
			if(isdigit(s[i])) num=(s[i++]-'0');
			if(isdigit(s[i])) num=num*10+(s[i++]-'0');	
			sum+=num*weight[j];	
		} 
       printf("%.3lf\n",sum);
    }
}




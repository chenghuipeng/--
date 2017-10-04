#include<cstring>  
#include<cstdlib>  
#include<cstdio>  
#include<cctype>  
#include<cmath>  
using namespace std;  
#define maxn 12


int main(){
	
	
	
	return 0;
}




void solve1(){
	//uva232 纵横字谜 
   char s[maxn][maxn];
   char ss[maxn][maxn];

	freopen("data.in","rb",stdin);
	int m,n,i,j,cas=0;
	while(scanf("%d %d",&m,&n)==2 && m)
	{
		memset(ss,0,sizeof(ss));
		int bh=0;
		for(i=0;i<m;i++) scanf("%s",s[i]);
		if(cas>0)printf("\n");
		printf("puzzle #%d:\nAcross",++cas);				
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				//边界，非黑，左边，上边 
				if(s[i][j]!='*' && (i==0||j==0||s[i-1][j]=='*'||s[i][j-1]=='*'))
					ss[i][j]=++bh;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++){
			 	if(ss[i][j]>0 && (j==0||s[i][j-1]=='*'))
 					printf("\n%3d.%c",ss[i][j],s[i][j]);
			 	else if(s[i][j]!='*')
			    	printf("%c",s[i][j]);
			}			 
		  printf("\nDown"); 
		  for(i=0;i<m;i++)
			for(j=0;j<n;j++){
				if(ss[i][j]>0&&(i==0||s[i-1][j]=='*'))
				{
					printf("\n%3d.%c",ss[i][j],s[i][j]);
					int a=1;
					while((i+a<m)&&(s[i+a][j]!='*'))
				 	{
 						printf("%c",s[i+a][j]);a++;	
 					}
				}	
			}  
			printf("\n");
	}
}










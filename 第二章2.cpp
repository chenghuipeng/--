#include<stdio.h>
#include<time.h>
#define INF 1000000

void solve(){
	
	int a,b,c;
	int k=0;
	FILE * fin,*fout;
	fin = fopen("data.in","rb");
	
	fout = fopen("data.out","wb");
	
	while(fscanf(fin,"%d %d %d",&a,&b,&c)==3)
	{
		for(int x=10;x<=100;x++)		
		{
			if(x%3==a && x%5==b && x%7== c)
			{
				k++;
				fprintf(fout,"case %d: %d\n",k,x); 
				break;
			}else if(x==100){
				k++; 
				fprintf(fout,"case %d: No answer\n",k);
			}
		}
	}
	fclose(fin);
	fclose(fout);
}

void solve2(){
	//子序列的和（subsequence）
   int n,m;
	int k=0;
	while(scanf("%d %d",&n,&m)==2 &&n&&m)
	{
		double sum=0;
		for(int i=n;i<=m;i++)
		{
			sum=sum+1.0/i/i;		
		}
		k++;
		printf("case %d:%.5f\n",k,sum);
		
	}
}
void solve3(){
	//分数化小数 问题 
	int a,b,c;
	int k=0;
	//注意代码中对第c+1位四舍五入的处理
	while(scanf("%d %d %d",&a,&b,&c)==3 &&a&&b&&c)
	{
		
		k++;
		printf("case %d: %d.",k,a/b);
		a%=b;
		while(c--)
		{
			a*=10;
			int t = a/b;
			if(c==0 && (a%b)*10/b >=5) 
				t++;
			printf("%d",t);
			a%=b;	 		
		}
		printf("\n");
	}
}
int main()
{
  //freopen("data.in","r",stdin);
  //freopen("data.out","w",stdout);
  //排列问题
	  int abc;
  for(abc = 123; abc <= 329; abc++) {
    int def = abc*2;
    int ghi = abc*3;
    int big = abc*1000000+def*1000+ghi;
    int d,ok=1;
    for(d=1;d<=9;d++)
   	{
   		int n =big;
   		int seen=0;
   		while(n>0){
		   	if(n%10 == d)  seen =1;
   		   n/=10;
	   }
	   if(!seen){
   		ok =0;
		   break;
	   } 
	   	
  	}
  	if(ok)
  	 	printf("%d %d %d\n", abc, def, ghi);
  
    
  }
  return 0;	 


	

} 

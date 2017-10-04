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
				k=k+1;
				fprintf(fout,"case %d: %d\n",k,x); 
				break;
			}else if(x==100){
				k=k+1; 
				fprintf(fout,"case %d: No answer\n",k);
			}
		}
	}
	fclose(fin);
	fclose(fout);
}


int main()
{
	
		solve();
		return 0;
} 

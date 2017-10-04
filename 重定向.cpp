
#define LOCAL
#include<stdio.h>
#include<time.h>

#define INF 1000000
void solve(){
	int x,n=0,min = INF,max = -INF;
	int s=0;
	while(scanf	("%d",&x) == 1){
		s+=x;
		if(x<min)
		 	min =x;
	    if(x>max)
     		max=x;
		n++;	
	//	printf("x=%d, min=%d, max=%d\n",x,min,max);
	}
	printf("%d %d %.3f\n",min,max,(double)s/n);	
}

int main()
{
	#ifdef LOCAL
		//输入 输出重定向 
		freopen("data.in","r",stdin);
		freopen("data.out","w",stdout);
	#endif	
		solve();
		return 0;
} 

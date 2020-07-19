#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int c[1441]={0},j[1441]={0}, test_cases, n, s[1000], e[1000], flag=0, cfl =0, jfl =0, temp[1000],t1,t2,t3;
	char ch[1000], t[1000];
	cin>>test_cases;

	for(int i=0; i<test_cases; i++){
		memset(ch, 0, sizeof ch);
		memset(t, 0, sizeof t);
		memset(c, 0, sizeof c);
		memset(j, 0, sizeof j);
		flag=0;
		cin>>n;

		for(int p =0; p<n; p++){
			cin>>s[p]>>e[p];
			temp[p]=p;
		}

		for(int i=0;i< n-1;i++)
			for (int j = 0; j < n-i-1; j++)
			{
				if(s[j] >  s[j+1]){
					t1 = s[j];
					t2 = e[j];
					t3 = temp[j];

					s[j] = s[j+1];
					e[j] = e[j+1];
					temp[j]=temp[j+1];
					s[j+1] = t1;
					e[j+1] = t2;
					temp[j+1] = t3;
				}
			}
		ch[0] = 'C';
		int cnt=1;

		// for(int j=1;j<n;j++){
		// 	for(int k=0;k<=j;k++){
		// 		flag =0;
		// 		if(s[j]>e[k]){
		// 			ch[j]=ch[j-1];
		// 			//cnt++;
		// 			continue;
		// 		}

		// 		if(s[j]<e[k] || e[j]<e[k]){
		// 			if(ch[k] == 'C')
		// 				ch[j] = 'J';
		// 			else
		// 				ch[j] = 'C';
		// 		}
		// 		else flag =1;
				
		// 	}
		// }





		for(int k=s[0];k<e[0];k++){
			c[k] = 1;
			
		}
		ch[0] = 'C';

		for(int l=s[1]; l<e[1]; l++){
			j[l] = 1;
			
		}
		ch[1] = 'J';
		for(int x = 2;x<n;x++){
			ch[x] = '\0';
			flag =0; cfl=0; jfl=0;
			for(int y =s[x];y<e[x];y++){
				//ch[x] ='\0';
				if(c[y]== 1){
					cfl=1;
					
					break;
				}
					else{
						c[y] = 1;
						ch[x] ='C';
					}
			}
		
			if(cfl == 1){
				for(int y =s[x];y<e[x];y++){
					//ch[x] ='\0';
					if(j[y]== 1){
						jfl=1;

						break;
					}
					else{
						j[y] = 1;
						ch[x] ='J';
					}
				}
			}
			if(jfl==1 && cfl==1)
				flag =1;
		}
		

		for(int i=0;i<n;i++){
			t[temp[i]] = ch[i];
		}
		if(flag == 1){
			cout<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;
		}
		else{
			cout<<"Case #"<<i+1<<": ";
			puts(t);
		}
	}

}
#include<iostream>
using namespace std;

int main()
{
	int test_case, n, i, j, k, nm[100][100], flag =0, cr=0, cc=0, trace, l, tempr[100]={0},tempc[100]={0};
	cin>>test_case;

	for(k=0;k<test_case;k++){
		cin>>n;
		flag =0;
		cr=0;
		cc=0;
		trace=0;
		for(int i=0;i<n;i++){
			for(j= 0;j<n;j++){
				cin>>nm[i][j];
			}
		}

		for(i=0;i<n;i++){
			for(int t=0;t<=n;t++)
				tempr[t] = {0};
			for(j=0;j<n;j++){
				tempr[nm[i][j]]++;

			}
			for(l=0;l<n;l++){
				if(tempr[l+1]>1){
					cr++;
					break;
				}
				
			}

		}

		for(j=0;j<n;j++){
			for(int t=0;t<=n;t++)
				tempc[t] = {0};
			for(i=0;i<n;i++){
				tempc[nm[i][j]]++;
			}
			for(l=0;l<n;l++){
				if(tempc[l+1]>1){
					cc++;
					break;
				}
			}
	
		}

		for(i=0;i<n;i++){
			trace+=nm[i][i];
		}

		cout<<"Case #"<<k+1<<": "<<trace<<" "<<cr<<" "<<cc<<endl;
	}

}


	
					
	
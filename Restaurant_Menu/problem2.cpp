#include<iostream>
#include<cstdio>
using namespace std;


int main()
{
	int t[100], c[100], test_cases, diff;
	string str;
	cin>>test_cases;
	for(int i=0;i<test_cases;i++){
		cin>>str;

		cout<<"Case #"<<i<<": ";
		int l=str.size();
		int temp=(int)str[0]-48;
		for(int j=0;j<temp;j++)
			cout<<'(';

		for(int j=0;j<l;j++)
			t[j]=(int)str[j]-48;

		for(int j=1;j<l;j++){
			if(t[j]<t[j-1]){
				cout<<t[j-1];
				temp++;
				diff = t[j-1]-t[j];
				for(int x = temp; x<temp+diff; x++)
					cout<< ')';
				temp+=diff;
			}

			if(t[j]>t[j-1]){
				cout<<t[j-1];
				temp++;
				diff = t[j]-t[j-1];
				for(int x = temp+1; x<temp+1+diff; x++)
					cout<<'(';
				temp+=diff;
			}

			if(t[j]==t[j-1])
				cout<<t[j];
		}
		cout<<str[l-1];
		int t1 = (int)str[l-1]-48;
		for(int y = 0;y< t1;y++)
			cout<<')';
		cout<<endl;
	}

	

}
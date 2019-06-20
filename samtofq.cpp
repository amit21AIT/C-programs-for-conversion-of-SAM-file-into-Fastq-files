// To convert SAM file to two fastq files

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("output.sam");
	ofstream f1("fastq1.fq",ios::out|ios::app);
	ofstream f2("fastq2.fq",ios::out|ios::app);
	string line;
	map <string , vector <string> > cmp;          // hash table to store the read contents until both the reads appear
	map <string,int> vis;
	
	while(getline(in,line))
	{
		stringstream iterator(line);
		
		string head,seq,qs,flag,x;				// declarations
		int cnt = 0;
		
		while(iterator>>x)
		{
			cnt++;
			if(cnt==1)
			head = x;							// initializing head
			else if(cnt==2)
			flag = x;							// initializing flag
			else if(cnt==10)
			seq = x;							// initializing sequence
			else if(cnt==11)
			qs = x;								// initializing quality score 
			
		}
		if(vis[head]==1)
		{
			if(flag>cmp[head][0])
			{
				f2<<head<<"\n";
				f2<<seq<<"\n";
				f2<<"+\n";
				f2<<qs<<"\n";
				
				f1<<head<<"\n";
				f1<<cmp[head][1]<<"\n";
				f1<<"+\n";
				f1<<cmp[head][2]<<"\n";
			}
			else 
			{
				f1<<head<<"\n";
				f1<<seq<<"\n";
				f1<<"+\n";
				f1<<qs<<"\n";
				
				f2<<head<<"\n";
				f2<<cmp[head][1]<<"\n";
				f2<<"+\n";
				f2<<cmp[head][2]<<"\n";
			}
		}
		else 
		{
			vis[head]=1;								
			cmp[head].push_back(flag);					// storing the sequence, flag and the quality score of the first read 
			cmp[head].push_back(seq);
			cmp[head].push_back(qs);
		}
		
		
		
	}
	f1.close();
	f2.close();
	in.close();
}

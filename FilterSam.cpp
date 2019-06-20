// this code writes unwanted reads onto the garbage.sam file and good reads into output.sam file

#include <bits/stdc++.h>
#include <fstream> 
using namespace std;
int main()
{
    ifstream in("input.sam");
    ofstream f1("output.sam",ios::out|ios::app);
    ofstream f2("garbage.sam",ios::out|ios::app);
    
    string record;
    
    while(getline(in,record))
    {
    	if(record.size()<100)                           // to ignore the starting lines in sam files which are not required in fastq
    	continue;
        stringstream iterator(record);					//  making a stream of input string so that we can extract one word at a time 
        
		int cnt = 0,num;
        string x,seq,qs;					// declarations
        
        while(iterator>>x)                        
        {
			cnt++;
			if(cnt==2)
			{
				stringstream s(x);                   // to convert string to integer
			    s>>num;								// flag
			}
			else if(cnt==10)					    // DNA sequence
			seq = x;
			else if(cnt==11)						// quality score
			qs = x;
		}
		if(cnt>=11 && seq.size()==qs.size() && num<256)            // if seq size and quality score size are equal and flag <256 then only write into the file
			f1<<record<<"\n";
		else 
			f2<<record<<"\n";										// else data goes in the garbage file
		
        
    }
    
    in.close();
    f1.close();
    f2.close();
}

#include <iostream> 
#include <stdio.h>
#include <regex>
#include <string>
#include <regex>
using namespace std;

//Fonction pour parser mon fichier vampire.txt en plusieurs parties par classes 
/*

FILE *openforwrite(int filecounter) {
	char fileoutputname[15];

	sprintf(fileoutputname, "file_part%d.txt", filecounter);
	return fopen(fileoutputname, "w");
}

int main() {
	FILE *ptr_readfile;
	FILE *ptr_writefile;
	char line [1000]; // or some other suitable maximum line size 
	int filecounter=1, linecounter=1;

	ptr_readfile = fopen("vampire.txt","r");
	if (!ptr_readfile) //si l'ouverture se déroule correctement 
		return 1;

	ptr_writefile = openforwrite(filecounter);

	
	while (fgets(line, sizeof line, ptr_readfile)!=NULL) { //s'excute j'usqua que y a plus de ligne dans notre fichier 
	
		regex pattern { "#### ([^C]+)" };		
		string pattern1 { line }; 		
		bool result = regex_match(pattern1 , pattern); 
		if (result == 1) {
			fclose(ptr_writefile);
			linecounter = 1;
			filecounter++;
			ptr_writefile = openforwrite(filecounter);	
			if (!ptr_writefile)
			return 1;
		}
		fprintf(ptr_writefile,"%s\n", line);
		linecounter++;
	}
	fclose(ptr_readfile);
	return 0;
}
*/








#include <iostream> 
#include <stdio.h>
#include <fstream>

#include <map>
#include <string>

#include <boost/algorithm/string.hpp>
#include <cstddef>
#include "strtk.hpp"

#include <utility>
#include <vector>

#include <functional>

#include <deque> 
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

/*

int main()
{
	
			
	regex pattern { "--.+(Merit)" };	
	string pattern1 { "--zjerkjzreiuhelMerit" };	
	bool result = regex_match(pattern1 , pattern); 	

	if (result == 1) 
	{
		cout << "true" << endl;			
	}	    
	else
	{
		cout << "false" << endl;	
	}
	return 0 ;
}

*/

int main()
{
	deque<string> liste;	
 	string line;
 	regex pattern { "--.+(Merit\\))" };
 	fstream fichier("file_part11.txt");
	if ( !fichier ) cout << "fichier inexistant";
	else 
	{	
		while(!fichier.eof())
		{
			getline(fichier, line);	
			if (line.find("--") == 0)
			{
				//line.erase(line.begin()-0);
				//line.erase(line.begin()-0);				
				//liste_nature.push_back(line);
				bool result = regex_match(line , pattern); 	
				if (result == 1) 
				{
					line.erase(line.begin()-0);
					line.erase(line.begin()-0);	
					line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();line.pop_back();
					
			
					liste.push_back(line);			
				}
			}
		
		}
		
	}			
			

	return 0 ;
}


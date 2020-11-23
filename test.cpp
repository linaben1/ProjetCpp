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
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <cstddef>


#include <utility>
#include <vector>

#include <functional>
#include "strtk.hpp"
#include <deque> 
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;


int main(){

	deque<string> liste;
	
 	string line;

 	fstream fichier("file_part2.txt");
	if ( !fichier ) cout << "fichier inexistant";
	else {	
		while(!fichier.eof())
		{
			getline(fichier, line);
	
			if (line.find("--") == 0)
			{
				line.erase(line.begin()-0);
				line.erase(line.begin()-0);				
				liste.push_back(line);
			}
		}
	    }
	    
	 for (int i = 0 ; i < liste.size() ; i ++) {
	
		cout << liste[i] << endl ; 	


		
	}
	

	
	
	
	
	return 0 ;

}



/*
 * main.cpp
 *
 *  Created on: Jul 26, 2019
 *      Author: huy
 */
#include"System.h"
//#include"Library.h"
int main(){
	System SYSTEM;
	//SYSTEM.get_files_name();
	/*SYSTEM.InputFiles();
	SYSTEM.load_synonym();
	SYSTEM.load_stop_word();
	SYSTEM.build_trie();*/
	while(1){
		SYSTEM.inputSearch();
		SYSTEM.history();
		string query=SYSTEM.getSearch();
		query=" "+query;
		vector<string > word;
		word.clear();
		for (auto it: query){
			if (it==' ') word.push_back("");
			else word.back()+=it;
		}
		//7
		int ok=0;
		for (auto it:word){
			if (it[0]=='$'){
				ok=1;
				for (int i=1;i<it.size();++i)
					if (it[i]=='$') ok=0;
			}
		}
		if (ok) {
			SYSTEM.process_a_price();
			cout<<7<<"\n";
			continue;
		}
		//8
		if (query[1]=='#'){
			SYSTEM.process_hashtag();
			cout<<8<<"\n";
			continue;
		}
		//9 10
		ok=1;
		if (query[1]=='"'){
			for (auto it:word)
				if(it=="*") ok=0;
			if(ok){
				SYSTEM.process_exact_match();
				cout<<9<<"\n";
				continue;
			}x
			else {
				SYSTEM.process_unknown_word();
				cout<<10<<"\n";
				continue;
			}
		}
		//12
		if (query[1]=='~') {
			SYSTEM.process_synonyms();
			cout<<12<<"\n";
			continue;
		}
		SYSTEM.process_range_number();
		cout<<11<<"\n";
	}
	//system("pause");
	return 0;
}





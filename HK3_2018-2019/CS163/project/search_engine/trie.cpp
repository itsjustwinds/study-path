/*
 * trie.cpp
 *
 *  Created on: Jul 26, 2019
 *      Author: huy
 */

#include"trie.h"
using namespace std;

int Node::get_id(char w){
	for (int i=0;i<(int)had.size();++i)
		if (had[i]==w) return i;
	return -1;
}

int Node::get_node(int id){
	return Next[id];
}

vector<string > Node::get_files(){
	return files;
}

int data::get_root(){
	return root;
}

void data::add_word(string S,string file){
	int Now=get_root();
	for (auto w: S){
		int id=trie[Now].get_id(w);
		if (id==-1){
			id=trie[Now].had.size();
			trie[Now].had.push_back(w);
			trie[Now].Next.push_back(trie.size());
			trie.push_back(Node());
		}
		Now=trie[Now].Next[id];
	}
	trie[Now].files.push_back(file);
}

vector<string > data::get_files_from_word(string S){
	int Now=get_root();
	for (auto w: S){
		int id=trie[Now].get_id(w);
		if (id==-1){
			vector<string > tmp;
			tmp.clear();
			return tmp;
		}
		Now=trie[Now].Next[id];
	}
	return trie[Now].files;
}

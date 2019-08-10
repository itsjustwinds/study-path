/*
 * trie.h
 *
 *  Created on: Jul 26, 2019
 *      Author: huy
 */
#pragma once
#ifndef TRIE_H_
#define TRIE_H_
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Node{
	vector<char > had;
	vector<int > Next;
	vector<string > files;
	Node(){
		had.clear();
		Next.clear();
		files.clear();
	}
	int get_id(char w);
	int get_node(int id);
	vector<string > get_files();
};

struct data{
	vector<Node > trie;
	int root;
	data(){
		root=0;
		trie.push_back(Node());
	}
	void add_word(string S,string file);
	int get_root();
	vector<string > get_files_from_word(string S);
	int check_link(string s);
};


#endif /* TRIE_H_ */

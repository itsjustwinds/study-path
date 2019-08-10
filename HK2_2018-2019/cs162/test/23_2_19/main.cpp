#include<iostream>
#include<fstream>
using namespace std;
struct Node{
	int val;
	Node *Next;
};
void input(ifstream &fin,Node *&root);
void display(ofstream &fout,Node *&root);
void delete_all(Node *&root);
void Reverse_root(Node *&root);
int main(){
	Node *root=nullptr;
	ifstream fin;
	fin.open("input.txt");
	input(fin,root);
	fin.close();
	ofstream fout;
	fout.open("output1.txt");
	display(fout,root);
	fout.close();
	Reverse_root(root);
	fout.open("output2.txt");
	display(fout,root);
	fout.close();
	Reverse_root(root);
	fout.open("output3.txt");
	display(fout,root);
	fout.close();
	delete_all(root);
}

void input(ifstream &fin,Node *&root){
	Node *cur=root;
	while(1){
		int x;
		fin>>x;
		if (x==0) break;
		Node *tmp=new Node;
		tmp->val=x;
		tmp->Next=nullptr;
		if (root==nullptr) {
			root=tmp;
			cur=root;
		}
		else {
			cur->Next=tmp;
			cur=cur->Next;
		}
	}
}

void display(ofstream &fout,Node *&root){
	if (root==nullptr){
		fout<<0;
		return;
	}
	fout<<root->val<<" ";
	display(fout,root->Next);
}

void delete_all(Node *&root){
	if (root==nullptr) return;
	delete_all(root);
	delete root;
}

void Reverse_root(Node *&root){
	if (root==nullptr) return;
	Node *cur=root->Next;
	root->Next=nullptr;
	while(cur!=nullptr){
		Node *tmp=cur->Next;
		cur->Next=root;
		root=cur;
		cur=tmp;
	}
}
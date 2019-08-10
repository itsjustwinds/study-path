/*
 * 18125130_Ex02.cpp
 *
 *  Created on: Jun 11, 2019
 *      Author: huy
 */
#include<iostream>
#include<fstream>

using namespace std;

struct Node {
	int val1, val2;
	Node* Left, *Mid, *Right, *parent;
	int n;

	Node(int x) {
		val1 = x;
		Left = Mid = Right = parent = NULL;
		n = 1;
	}

	Node(int x, Node* pre) {
		val1 = x;
		Left = Mid = Right = NULL;
		parent = pre;
		n = 1;
	}
};

void insert_to_tree(Node* &Root, int data);
void addValue(Node* Root, int x);
int compare(Node* Root, int x);
void splitLeaf(Node* Root, int data);
void push_to_parent(Node*Root, Node* item);
void splitThreeNode(Node* Root, Node* item);
void delete_tree(Node* & Root);

int main() {
	ifstream fin;
	fin.open("input.txt");

	int n;
	fin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) fin >> a[i];

	Node* Root = NULL;
	for (int i = 0; i < n; i++) {
		insert_to_tree(Root, a[i]);
	}


	delete_tree(Root);

	delete[]a;
	fin.close();
	return 0;
}

void insert_to_tree(Node* &Root, int data) {
	if (Root == NULL) {
		Root = new Node(data);
		return;
	}


	//Case: Node is leaf
	if (Root->Left == NULL && Root->Right == NULL && Root->Mid == NULL) {
		if (Root->n == 1) { //Leaf has 1 item
			if (data > Root->val1) {
				Root->val2 = data;
				Root->n = 2;
			}
			else {
				Root->val2 = Root->val1;
				Root->val1 = data;
				Root->n = 2;
			}
		}
		else { //Leaf has 2 item and needs split
			splitLeaf(Root, data);
			if (Root->parent != NULL) {
				push_to_parent(Root->parent, Root);
			}
		}
		return;
	}

	//On travesal

	if (data < Root->val1) {
		insert_to_tree(Root->Left, data);
 		if (Root->Left) Root->Left->parent = Root;
	}
	else {
		if (Root->n == 1) { //2 children
			insert_to_tree(Root->Right, data);
			if (Root->Right) Root->Right->parent = Root;
		}
		else { //3 children
			if (data < Root->val2)
			{
				insert_to_tree(Root->Mid, data);
				if (Root->Mid) Root->Mid->parent = Root;
			}
			else
			{
				insert_to_tree(Root->Right, data);
				if (Root->Right) Root->Right->parent = Root;
			}

		}
	}
}

void addValue(Node* Root, int x) {
	Root->val2 = x;
	if (Root->val1 > Root->val2) swap(Root->val1, Root->val2);
}

int compare(Node* Root, int x) {

	if (x < Root->val1) return 1;

	if (Root->n == 2) {
		if (Root->val1 < x && x < Root->val2) return  0;
		if (x > Root->val2) return -1;
	}
}

void splitLeaf(Node* Root, int data) {


	if (data < Root->val1) {
		Root->Left = new Node(data, Root);
		Root->Right = new Node(Root->val2, Root);
		Root->n = 1;
	}
	else
	if (Root->n == 2 && Root->val1 < data && data < Root->val2) {
		Root->Left = new Node(Root->val1, Root);
		Root->Right = new Node(Root->val2, Root);
		Root->n = 1;
		Root->val1 = data;
	}
	else
	if (Root->n == 2 && data > Root->val2) {
		Root->Left = new Node(Root->val1, Root);
		Root->Right = new Node(data,Root);
		Root->n = 1;
		Root->val1 = Root->val2;
	}
}

void push_to_parent(Node*Root, Node* item) {
	if (Root->n == 1) {//1 item in parent Node
		Root->n = 2;
		if (item->val1 < Root->val1) {
			Root->val2 = Root->val1;
			Root->val1 = item->val1;
			Root->Left = item->Left;
			Root->Left->parent = Root;
			Root->Mid = item->Right;
			Root->Mid->parent = Root;
		}
		else {
			Root->val2 = item->val1;
			Root->Mid = item->Left;
			Root->Mid->parent = Root;
			Root->Right = item->Right;
			Root->Right->parent = Root;
		}

	}
	else {
		splitThreeNode(Root, item);
		if (Root->parent != NULL) {
			push_to_parent(Root->parent, Root);
		}
	}
}

void splitThreeNode(Node* Root, Node* item) {

	Node* Temp = NULL;

	if (item->val1 < Root->val1) { //item is Left Node of Root
		Root->Left = item;
		Root->Left->parent = Root;
		Temp = new Node(Root->val2, Root);
		Root->n = 1;
		Temp->Left = Root->Mid;
		Temp->Left->parent = Temp;
		Temp->Right = Root->Right;
		Temp->Right->parent = Temp;
		Root->Right = Temp;
		Root->Right->parent = Root;
		Root->Mid = NULL;
	}
	else
	if (Root->val1 < item->val1 && item->val1 < Root->val2) {// item is Mid Node
		Temp = new Node(Root->val1, Root);
		Temp->Left = Root->Left;
		Temp->Left->parent = Temp;
		Temp->Right = item->Left;
		Temp->Right->parent = Temp;
		Root->Left = Temp;

		Temp = new Node(Root->val2, Root);
		Temp->Left = item->Right;
		Temp->Left->parent = Temp;
		Temp->Right = Root->Right;
		Temp->Right->parent = Temp;
		Root->Right = Temp;

		Root->val1 = item->val1;
		Root->Mid = NULL;
		Root->n = 1;
	}
	else {//item is Right Node
		Root->Right = item;
		Root->Right->parent = Root;
		Temp = new Node(Root->val1, Root);
		Temp->Left = Root->Left;
		Temp->Left->parent = Temp;
		Temp->Right = Root->Mid;
		Temp->Right->parent = Temp;
		Root->Left = Temp;
		Root->Left->parent = Root;
		Root->n = 1;
		Root->Mid = NULL;
		Root->val1 = Root->val2;
	}
}

void delete_tree(Node* & Root) {
	if (Root == NULL) return;
	if (Root->Mid == NULL && Root->Left == NULL && Root->Right == NULL) {
		cout <<Root->val1 << " ";
		if (Root->n == 2)  cout <<Root->val2 << " ";
	}
	else
	if (Root->n == 1) {
		delete_tree(Root->Left);
		cout << Root->val1 << " ";
		delete_tree(Root->Right);
	}
	else
	if (Root->n == 2) {
		delete_tree(Root->Left);
		cout << Root->val1 << " ";
		delete_tree(Root->Mid);
		cout << Root->val2 << " ";
		delete_tree(Root->Right);
	}
}




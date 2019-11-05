/*
-----Binary Search Trees-----
A library/class about binary search trees and various methods
to manipulate/traverse them.

Notes:
-All BSTs start with one node (on instantiation, root pointer created and linked to first node)
-TODO: edge cases (empty tree, etc.)

Created by Nicolas Layne (11/2019)
*/

#pragma once
#include <iostream>

template <class type>
class BinarySearchTree {
private:
	struct Node {
		type value;
		Node* left, * right;
	};
	Node* root;

	void deleteTree(Node*& root);
	void inOrderTraversal(Node* root);
	void preOrderTraversal(Node* root);
	void postOrderTraversal(Node* root);

public:
	//Initialize root
	BinarySearchTree(type firstNodeValue);
	//Delete all nodes/entire tree
	~BinarySearchTree();

	//Standard functions
	void insertNode(type value);
	void removeNode(type value);
	bool isInTree(type value);
	void balanceTree();

	//Traversal methods
	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();
	

};

template <class type>
BinarySearchTree<type>::BinarySearchTree(type firstNodeValue) {
	root = new Node;
	root->value = firstNodeValue;
	root->left = nullptr;
	root->right = nullptr;
}

template <class type>
BinarySearchTree<type>::~BinarySearchTree() {
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

template <class type>
void BinarySearchTree<type>::deleteTree(Node*& root) {
	if (root != nullptr) {
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}
}

template <class type>
void BinarySearchTree<type>::inOrderTraversal() {
	if (root != nullptr) {
		inOrderTraversal(root->left);
		std::cout << root->value << " ";
		inOrderTraversal(root->right);
	}
	std::cout << std::endl;
}

template <class type>
void BinarySearchTree<type>::inOrderTraversal(Node* root) {
	if (root != nullptr) {
		inOrderTraversal(root->left);
		std::cout << root->value << " ";
		inOrderTraversal(root->right);
	}
	std::cout << std::endl;
}

template <class type>
void BinarySearchTree<type>::preOrderTraversal() {
	if (root != nullptr) {
		std::cout << root->value << " ";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
	std::cout << std::endl;
}

template <class type>
void BinarySearchTree<type>::preOrderTraversal(Node* root) {
	if (root != nullptr) {
		std::cout << root->value << " ";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
	std::cout << std::endl;
}

template <class type>
void BinarySearchTree<type>::postOrderTraversal() {
	if (root != nullptr) {
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		std::cout << root->value << " ";
	}
	std::cout << std::endl;
}

template <class type>
void BinarySearchTree<type>::postOrderTraversal(Node* root) {
	if (root != nullptr) {
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		std::cout << root->value << " ";
	}
	std::cout << std::endl;
}

template <class type>
void BinarySearchTree<type>::insertNode(type value) {
	Node* temp = root;
	
	if (root == nullptr) {
		root = new Node;
		root->value = value;
		root->left = nullptr;
		root->right = nullptr;
	}

	while (temp != nullptr) {
		if (value == temp->value) {
			std::cout << "Value already in tree." << std::endl;
			return;
		}
		else if (value < temp->value) {
			if (temp->left == nullptr) {
				temp->left = new Node;
				temp = temp->left;
				temp->value = value;
				temp->left = nullptr;
				temp->right = nullptr;
				return;
			}
			else
				temp = temp->left;
		}
		else {
			if (temp->right == nullptr) {
				temp->right = new Node;
				temp = temp->right;
				temp->value = value;
				temp->left = nullptr;
				temp->right = nullptr;
				return;
			}
			else
			temp = temp->right;
		}
	}
}

template <class type>
void BinarySearchTree<type>::removeNode(type value) {

}

template <class type>
bool BinarySearchTree<type>::isInTree(type value) {
	Node* temp = root;
	
	while (temp != nullptr) {
		if (value == temp->value)
			return true;
		else if (value < temp->value)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return false;
}

template <class type>
void BinarySearchTree<type>::balanceTree() {

}
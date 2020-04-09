/* 
 * File:   SearchTreeString.hpp
 * Author: helmuth
 *
 * Created on 9 de abril de 2020, 10:03
 */

#ifndef SEARCHTREE_HPP
#define SEARCHTREE_HPP
#include "Node.hpp"
#include <iostream>
#include <cstring>
using namespace std;

class SearchTreeString {
   
    public:
        SearchTreeString();
        SearchTreeString(Node<string>* root);
        void setRoot(Node<string>* root);
        Node<string>* getRoot();
        bool isEmpty();
        Node<string>* search(string value);
        void insert(string value);
        void remove(string value);
        void preOrder();
        void inOrder();
        void postOrder();
        virtual ~SearchTreeString();
        
    private:
        Node<string>* root;
        Node<string>* search(Node<string>* subRoot, string value);
        Node<string>* insert(Node<string>* subRoot, string value);
        Node<string>* remove(Node<string>* subRoot, string value);
        Node<string>* replace(Node<string>* currentNode);
        void preOrder(Node<string>* root);
        void inOrder(Node<string>* root);
        void postOrder(Node<string>* root);
        char* valueToCharArray(string value);
};
#endif /* SEARCHTREE_HPP */


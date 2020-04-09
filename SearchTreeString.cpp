/* 
 * File:   SearchTreeString.cpp
 * Author: helmuth
 * 
 * Created on 9 de abril de 2020, 10:03
 */

#include "SearchTreeString.hpp"

//Constructores de la clase.
SearchTreeString::SearchTreeString(){
    root = NULL;
}

SearchTreeString::SearchTreeString(Node<string>* root){
    this->root = root;
}

//Setter de la clase.
void SearchTreeString::setRoot(Node<string>* root){
    this->root = root;
}

//Getters de la clase.
Node<string>* SearchTreeString::getRoot(){
    return root;
}

/*
 * Metodo encargado de valida si el arbol se encuentra vacio. Devuelve un valor boleano
 * dependiendo si la raiz apunta o no a null.
 */
bool SearchTreeString::isEmpty(){
    return root == NULL;
}

/*
 * Metodo encargado de insertar un nuevo dato dentro del arbol.
 */
void SearchTreeString::insert(string value){
    root = insert(root, value);
}

/*
 * Metodo encargado de realizar la insercion.
 * Si la subRaiz es nula se crea un nuevo nodo dentro de la misma.
 * Si el valor es menor al valor contenido dentro la hoja actual, se crea un nuevo nodo 
 * y se llama recursivamente al metodo enviando como subRaiz la referencia al nodo izquierdo
 * de la hoja actual, por ultimo se establece el hijo izquierdo de la hoja actual al nodo 
 * recien creado.
 * Si el valor es mayor al valor contenido dentro la hoja actual, se crea un nuevo nodo 
 * y se llama recursivamente al metodo enviando como subRaiz la referencia al nodo derecho
 * de la hoja actual, por ultimo se establece el hijo derecho de la hoja actual al nodo 
 * recien creado.
 * Si no se cumple con ninguno de los criterios anteriores se lanza una excepcion.
 */
Node<string>* SearchTreeString::insert(Node<string>* subRoot, string value){    
    if(subRoot == NULL){
        subRoot = new Node<string>(value);
    } 
    else if(strcmp(value.c_str(), subRoot->getValue().c_str()) < 0){
        Node<string>* left;
        left = insert(subRoot->getLeft(), value);
        subRoot->setLeft(left);
    }
    else if(strcmp(value.c_str(), subRoot->getValue().c_str()) > 0){
        Node<string>* rigth;
        rigth = insert(subRoot->getRigth(), value);
        subRoot->setRigth(rigth);    
    } 
    else{
        std::string msg = "Nodo duplicado";
        throw  msg;
        return subRoot;
    }
    return subRoot;
}

/*
 * Metodo encargado de buscar un dato dentro del arbol. Devuelve la referencia del nodo que
 * contiene el dato buscado.
 */
Node<string>* SearchTreeString::search(string value){
    return search(root, value);
}

/*
 * Metodo encargado de realizar una busqueda.
 * Si la subRaiz es nula se retorna null.
 * Si el valor es igual al valor de la hoja actual, se retorna un referencia a la hoja actual.
 * Si el valor es menor al valor contenido dentro la hoja actual, se retorna un llamado recursivo
 * al metodo enviando como parametros el hijo izquierdo de la hoja actual y el valor buscado.
 * Si no se cumple con ninguno de los criterios anteriores se retorna un llamado recursivo
 * al metodo enviando como parametros el hijo derecho de la hoja actual y el valor buscado.
 */
Node<string>* SearchTreeString::search(Node<string>* subRoot, string value){
    if(subRoot == NULL){
        return NULL;
    }
    else if(strcmp(value.c_str(), subRoot->getValue().c_str()) == 0){
        return subRoot;
    }
    else if(strcmp(value.c_str(), subRoot->getValue().c_str()) < 0){
        return search(subRoot->getLeft(), value);
    }
    else{ 
        return search(subRoot->getRigth(), value);
    } 
}

/*
 * Metodo encargado de remover un dato dentro del arbol.
 */
void SearchTreeString::remove(string value){
    root = remove(root, value);
}

/*
 * Metodo encargado de eliminar un nodo del arbol.
 * Realiza una busqueda del nodo que se desea eliminar.
 * Al encontrarlo establece si es un nodo son un solo hijo izquierdo, con un solo hijo 
 * derecho o con ambos hijos.
 *  Hijo izquierdo: Establece el valor del nodo actual al valor de hijo izquierdo del mismo.
 *  Hijo derecho: Establece el valor del nodo actual al valor de hijo derecho del mismo. 
 *  Ambos hijos: Llama al metodo replace enviando como parametro el nodo actual.
 */
Node<string>* SearchTreeString::remove(Node<string>* subRoot, string value){ 
    if(subRoot == NULL){
        std::string msg = "No se encontro ningun nodo con ese valor";
        throw  msg;
    }
    else if(strcmp(value.c_str(), subRoot->getValue().c_str()) < 0){
        Node<string>* left;
        left = remove(subRoot->getLeft(), value);
        subRoot->setLeft(left);
    }
    else if(strcmp(value.c_str(), subRoot->getValue().c_str()) > 0){
        Node<string>* rigth;
        rigth = remove(subRoot->getRigth(), value);
        subRoot->setRigth(rigth);    
    }
    //Nodo encontrado
    else{
        Node<string>* node;
        node = subRoot;
        if(node->getLeft() == NULL){
            subRoot = node->getRigth();
        }
        else if(node->getRigth() == NULL){
            subRoot = node->getLeft();
        }
        //Nodo con hijos derechos e izquierdos
        else{
            node = replace(node);
        } 
        node = NULL;
        return subRoot;
    }
}

/*
 * Metodo encargado de eliminar un nodo con dos hijos y modificar la estructura del
 * arbol para que cumpla con los criterios de un arbol de busqueda.
 */
Node<string>* SearchTreeString::replace(Node<string>* currentNode){
    Node<string>* auxNode;
    Node<string>* node;
    node = currentNode;
    auxNode = currentNode->getLeft();
    while(auxNode->getRigth() != NULL){
        node = auxNode;
        auxNode = auxNode->getRigth();
    }
    currentNode->setValue(auxNode->getValue());
    if(node == currentNode){
        node->setLeft(auxNode->getLeft());
    }
    else{
        node->setRigth(auxNode->getLeft());
    }
}

/*
 * Recorrido pre-Orden del arbol.
 */
void SearchTreeString::preOrder(){
    preOrder(root);
    std::cout<<"\n";
}

void SearchTreeString::preOrder(Node<string>* root){
    if(root != NULL){
        std::cout<<root->getValue()<<" ";
        preOrder(root->getLeft());
        preOrder(root->getRigth());
    }
}

/*
 * Recorrido in-Orden del arbol.
 */
void SearchTreeString::inOrder(){
    inOrder(root);
    std::cout<<"\n";
}

void SearchTreeString::inOrder(Node<string>* root){
    if(root != NULL){
        inOrder(root->getLeft());
        std::cout<<root->getValue()<<" ";
        inOrder(root->getRigth());
    }
}

/*
 * Recorrido post-Orden del arbol.
 */
void SearchTreeString::postOrder(){
    postOrder(root);
    std::cout<<"\n";
}

void SearchTreeString::postOrder(Node<string>* root){
    if(root != NULL){
        postOrder(root->getLeft());
        postOrder(root->getRigth());
        std::cout<<root->getValue()<<" ";
    }
}

SearchTreeString::~SearchTreeString(){
    delete root;
}
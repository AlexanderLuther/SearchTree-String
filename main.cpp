/* 
 * File:   main.cpp
 * Author: helmuth
 *
 * Created on 9 de abril de 2020, 10:02
 */
#include <cstdlib>
#include "SearchTreeString.hpp"
using namespace std;

int main() {
    try{
        SearchTreeString tree;
        tree.insert("hola");
        tree.insert("HOLA");
        tree.insert("asdfk");
        tree.insert("d");
        tree.insert("E");
        tree.inOrder();
    }
    catch(string e){
        cout<<e;   
    }
    return 0;
}


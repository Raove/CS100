#ifndef RSHELL_TREE_HPP
#define RSHELL_TREE_HPP

#include "../header/Token.hpp"
#include "Paren.hpp"
#include "../header/Command.hpp"
#include <vector>

using namespace std;

class StackNode {
public:
    Token* treeNode;
    StackNode *next;
    StackNode(Token* treeNode)
    {
        this->treeNode = treeNode;
        next = NULL;
    }
};

class Tree {
private:
    StackNode* top;
public:
    vector<Token*> Prefix;
    vector<Token*> Postfix;
    Tree(){
        top = NULL;
    };
    Tree(vector<Token*> Token_vector){
        Postfix = Token_vector;
        vector<Token*> temp;
        for(int i = Token_vector.size(); i > 0; i--){
            temp.push_back(Token_vector[i - 1]);
        }
        Prefix = temp;
    }

    void startTree(){
        if(Prefix.size() >= 2) {
            buildTree();
            evaluate();
        } else{
            Executable *one = new Executable();
            one->makechar(Prefix[0]);
            one->exe();
        }
        return;
    }
    void MichaelScreamsAtMe(){
        if(Postfix.size() >= 2) {
            vector<Token*> root;
            for(int i = 0; i < Postfix.size(); i++){
                if(Postfix[i]->getType() == "CNT"){
                    Token *connect = (Token*)Postfix[i];
                    for(int j = i; j > 0; j--){
                        if(Postfix[j] != nullptr) {
                            connect->right = Postfix[j];
                            Postfix[j] = nullptr;
                        }
                        if(Postfix[j] != nullptr) {
                            connect->left = Postfix[j];
                            Postfix[j] = nullptr;
                        }
                    }
                    root.push_back(connect);
                }
            }
            for(int i = 0; i < root.size(); i++) {
                root[i]->run();
            }
        }
        else{
            Executable *one = new Executable();
            one->makechar(Postfix[0]);
            one->exe();
        }
    }
    /////////////////////////////////////////////
/*               SEMI WORKING TREE
 * ////////////////////////////////////////////////////////////////////////
 *
 * I LEARNED HOW TO DO THE TREE HERE, SO THE CODE IS VERY SIMILAR
 *
 * https://www.sanfoundry.com/cpp-program-implement-expression-tree-prefix/
 *
 */////////////////////////////////////////////////////////////////////////

    void push(Token *ptr)
    {
        if (top == NULL)
            top = new StackNode(ptr);
        else
        {
            StackNode *nptr = new StackNode(ptr);
            nptr->next = top;
            top = nptr;
        }
    }
    Token *pop()
    {
        if (top == NULL)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            Token *ptr = top->treeNode;
            top = top->next;
            return ptr;
        }
    }
    Token *peek()
    {
        return top->treeNode;
    }
    void insert(Token* val)
    {
        if (val->getType() == "CMD")
        {
            push(val);
        }
        else if (val->getType() == "CNT")
        {
            Token* nptr;
            if(val->getToken() == "&&")
                nptr = new And();
            else if(val->getToken() == "||")
                nptr = new Or();
            else if(val->getToken() == ";")
                nptr = new Semicolon();
            nptr->left = pop();
            nptr->right = pop();
            push(nptr);
        }
    }
    void buildTree()
    {
        for (int i = Prefix.size() - 1; i >= 0; i--)
            insert(Prefix[i]);
    }
    void evaluate()
    {
        evaluate(peek());
        return;
    }
    Token* evaluate(Token *ptr) {
        if (ptr->left == NULL && ptr->right == NULL)
            return ptr;
        else {
            Token *right = evaluate(ptr->right);
            Token *left = evaluate(ptr->left);
            if (ptr->getToken() == "&&") {
                Executable *one = new Executable();
                one->makechar(right);
                bool succeeded = one->exe();
                if (!succeeded) {
                    Executable *two = new Executable();
                    two->makechar(left);
                    two->exe();
                }
            } else if (ptr->getToken() == "||") {
                Executable *one = new Executable();
                one->makechar(right);
                bool failed = one->exe();
                if (failed) {
                    Executable *two = new Executable();
                    two->makechar(left);
                    two->exe();
                }
            } else if (ptr->getToken() == ";") {
                Executable *one = new Executable();
                one->makechar(right);
                one->exe();
                    Executable *two = new Executable();
                    two->makechar(left);
                    two->exe();
            }
        }
        Token* exitToken = new And();
        return exitToken;
    }

};

#endif //RSHELL_TREE_HPP

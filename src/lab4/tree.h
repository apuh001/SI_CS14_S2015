#ifndef __TREE_H__
#define __TREE_H__
 
#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class Tree {
    private:
        struct Node {
            T data;
            Node *right;
            Node *left;
            Node():     data(0), right(0), left(0) { }
            Node(T d):  data(d), right(0), left(0) { }
        };
 
        Node* root;
    
        Node* push_(T val, Node* n) {
            if(!n) n = new Node(val);
            else if(val < n->data) n->left = push_(val, n->left);
            else if(val > n->data) n->right = push_(val, n->right);
            else n->data = val; //if val is equal to data
            
            return n;
        }
        
        //Helper for total
        T getSum(Node* n)
        {
            //Base case: If n is 0 return default value
            if(n == 0)
                return T();
            if(n->left == 0 && n->right == 0)
                return n->data;
        
            return n->data + getSum(n->left) + getSum(n->right);
        }
        
        void burnTree(Node* n)
        {
            if(n == 0)
                return;
            if(n->left == 0 && n->right == 0)
            {
                cout << "Deleting " << n->data << endl;
                delete n;
                return;
            }
            
            burnTree(n->left);
            burnTree(n->right);
            cout << "Deleting " << n->data << endl;
            delete n;
        }
    
    public:
        Tree():root(0) { }
        
        ~Tree()
        {
            if(root == 0)
                return;
            burnTree(root);
        }
        
        //MY WORK
        Node* min()
        {
            //Empty
            if(root == 0)
                return root;
            
            Node* curr = root;
            for(; curr->left != 0; curr = curr->left);
            return curr;
        }
        
        Node* max()
        {
            //Empty
            if(root == 0)
                return root;
            
            Node* curr = root;
            for(; curr->right != 0; curr = curr->right);
            return curr;
        }
        
        Node* find(T val)
        {
            //If root is null
            if(root == 0)
                return 0;
            
            Node* curr = root;
            while (curr != 0)
            {
                if(val < curr->data)
                {
                    if(curr->left != 0)
                        curr = curr->left; 
                    else return 0;
                }    
                else if(val > curr->data)
                {
                    if(curr->right != 0)
                        curr = curr->right;
                    else return 0;
                }
                else if(val == curr->data)
                    return curr;
            }
            
            cout << "blah" << endl;
            
            //Return null pointer
            return 0;
        }
        
        
        T total()
        {
            if(root == 0)
                return T();
            return root->data + getSum(root->left) + getSum(root->right);
        }
        
        /*
        int print_ascending()
        {
            
        }
        
        int print_descending(){
            
        }
        */
        
        //END OF MY WORK
        Node* get_root() { return root; }
    
        void push(T val) { root = push_(val, root); }
    
        void print() {
            typedef std::pair<const Node*,int> node_level;
            std::queue<node_level> q;
            q.push(node_level(root, 1));
            int level = 1;
            
            while (!q.empty()) {
                node_level nl = q.front();
                q.pop();
                const Node *n = nl.first;
                if (!n) { continue; }
                
                if (level != nl.second) {
                    std::cout << std::endl << std::endl;
                    level = nl.second;
                }
                std::cout << n->data << ' ';
                q.push(node_level(n->left,  1 + level));
                q.push(node_level(n->right, 1 + level));
            
            }
            std::cout << std::endl;
        }
};
 
 
#endif
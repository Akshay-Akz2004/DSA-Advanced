/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> reg;
    void dfs(Node*clone,Node*og){

        for(auto i:og->neighbors){
            if(reg[i->val]==NULL){
                Node*n=new Node(i->val);
                reg[n->val]=n;
                clone->neighbors.push_back(n);
                dfs(n,i);
            }
            else clone->neighbors.push_back(reg[i->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        Node* clone=new Node(node->val);
        reg.resize(101,NULL);
        reg[clone->val]=clone;
        dfs(clone,node);
        return clone;
    }
};
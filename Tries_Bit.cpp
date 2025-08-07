struct Node{
    Node* links[2];
    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }
    bool containskey(int bit){
        return (links[bit]!=NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
};
class Trie{
    private:
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insertnum(int num){
        Node* node = root;
        for(int i =31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containskey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }


    int getmax(int num){
        Node* node = root;
        int maxnum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containskey(1 - bit)){
                maxnum = maxnum | (1<<i);
                node = node->get(1- bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxnum;
    }
};
#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

class HuffmanNode{
    public:
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data,int frequency):
        data(data),
        frequency(frequency),
        right(nullptr),
        left(nullptr){}

    bool operator>(const HuffmanNode& other )const{
        return frequency > other.frequency;
    }    
};

void buildCodes(HuffmanNode* node ,const string& code, map<char,string>& huffmanCodes){
    if(node==nullptr) return;
    if(node->left==nullptr && node->right==nullptr){
        huffmanCodes[node->data]=code;
    }
    buildCodes(node->left,code+"0",huffmanCodes);
    buildCodes(node->right,code+"1",huffmanCodes);
}

map<char,string>buildHuffmanCodes(const string& text){
    map<char,int>charFreq;
    for(char c:text){
        charFreq[c]++;
    }
    priority_queue<HuffmanNode,vector<HuffmanNode>,greater<HuffmanNode>>priorityQueue;
    for(const auto& entry:charFreq){
        priorityQueue.push(HuffmanNode(entry.first,entry.second));
    }

    while(priorityQueue.size()>1){
        HuffmanNode* left=new HuffmanNode(priorityQueue.top());
        priorityQueue.pop();
        HuffmanNode* right=new HuffmanNode(priorityQueue.top());
        priorityQueue.pop();
        HuffmanNode* combined=new HuffmanNode('\0',left->frequency+right->frequency );
        combined->left=left;
        combined->right=right;
        priorityQueue.push(*combined);
    }
    HuffmanNode root=priorityQueue.top();
    map<char,string>huffmanCodes;
    buildCodes(&root,"",huffmanCodes);
    return huffmanCodes;
}


int main(){
    string text;
    cout<<"Enter Text: ";
    cin>>text;

    map<char,string> HuffmanCode =buildHuffmanCodes(text);
    cout<<"HuffmanCodes: "<<endl;
    for(const auto& i: HuffmanCode){
        cout<<i.first<<" : "<<i.second<<endl;
    }
    return 0;
}

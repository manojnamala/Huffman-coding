#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct HuffmanNode {
    char ch;
    int frequency;
    HuffmanNode *left, *right;
    
    HuffmanNode(char c, int f) : ch(c), frequency(f), left(nullptr), right(nullptr) {}
};

struct NodeCompare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

void generateHuffmanCodes(HuffmanNode* root, string code) {
    if (!root) return;
    
    // Leaf node: print the code
    if (!root->left && !root->right) {
        cout << code << " ";
        return;
    }
    
    generateHuffmanCodes(root->left, code + "0");
    generateHuffmanCodes(root->right, code + "1");
}

// Function to build Huffman tree and print codes
void buildHuffmanTree(string chars, int freq[], int size) {
    // Initialize min-heap
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, NodeCompare> minHeap;
    
    // Add all characters as leaf nodes
    for (int i = 0; i < size; i++) {
        minHeap.push(new HuffmanNode(chars[i], freq[i]));
    }
    
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();
        
        HuffmanNode* parent = new HuffmanNode('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        minHeap.push(parent);
    }
    
    generateHuffmanCodes(minHeap.top(), "");
}

int main() {
    string chars = "abcdef";
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = chars.length();
    
    buildHuffmanTree(chars, freq, size);
    cout << endl;
    
    return 0;
}
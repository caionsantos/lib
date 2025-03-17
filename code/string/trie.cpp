#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node{
    int next[26];
    int subtree = 0;
};

void add(string s, vector<Node> &trie){
    int curr = 0;

    for(auto c : s){
        if(trie[curr].next[c - 'a'] == 0){
            trie[curr].next[c - 'a'] = trie.size();
            trie.push_back(Node());        
        }

        trie[curr].subtree += 1;
        curr = trie[curr].next[c - 'a'];
    }
    trie[curr].subtree += 1;
}

int query(string s, vector<Node> &trie){
    int curr = 0;

    for(auto c : s){
        if(trie[curr].next[c - 'a'] == 0){
            return 0;
        }
        curr = trie[curr].next[c - 'a'];
    }
    return trie[curr].subtree;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Node> trie(1);
    //trie pode ser modificada com DFS para propagar mudancas
    //TRIE DE XOR -> max(busca diferentes) e min(busca igual)

    return 0;
}

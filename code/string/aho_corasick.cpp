#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct AhoCorasick {
    static const int K = 26; //tamanho do alfabeto
    static const char offset = 'a';

    struct Node {
        int next[K];
        bool isword = false;
        int sflink = -1; //aponta para no do maior sufixo que eh prefixo de alguma palavra do dicionario
        int exlink = -1; //aponta para no do maior sufixo que eh uma palavra do dicionario
        vector<int> idxs; //indices da palavra (se forem unicas trocar pra int)
        int cnt = 0;

        Node() {
            fill(begin(next), end(next), -1);
        }
    };

    vector<Node> trie;

    AhoCorasick(){
        trie.push_back(Node());
    }

    void add(string &s, int id){
        int curr = 0;
        for(auto c : s){
            if(trie[curr].next[c-offset] == -1){
                trie[curr].next[c-offset] = trie.size();
                trie.push_back(Node());
            }
            curr = trie[curr].next[c-offset];
        }

        trie[curr].isword = true;
        trie[curr].cnt++;
        trie[curr].idxs.push_back(id);
    }

    void build(){
        queue<int> fila;

        for(int i =0; i < K; i++){
            if(trie[0].next[i] == -1){
                trie[0].next[i] = 0;
            } else{
                trie[trie[0].next[i]].sflink = 0;
                trie[trie[0].next[i]].exlink = 0;
                fila.push(trie[0].next[i]);
            }
        }

        while(!fila.empty()){
            auto v = fila.front();
            fila.pop();

            int go = trie[v].sflink;
            if(trie[go].isword){
                trie[v].exlink = go;
            } else{
                trie[v].exlink = trie[go].exlink;
            }

            //usar build para acumular coisas pra query
            //como dp
            //exemplo: quantidade de ocorrenciais
            trie[v].cnt += trie[trie[v].sflink].cnt;

            for(int i = 0; i < K; i++){
                if(trie[v].next[i] == -1){
                    trie[v].next[i] = trie[trie[v].sflink].next[i];
                } else{
                    trie[trie[v].next[i]].sflink = trie[trie[v].sflink].next[i];
                    fila.push(trie[v].next[i]);
                }
            }
        }
    }

    //exemplo: quantidade de matches
    ll query_matches(string &s){
        ll ans = 0;
        int curr = 0;

        for(auto c : s){
            curr = trie[curr].next[c-offset];
            ans += trie[curr].cnt;
        }

        return ans;
    }

    //exemplo: indices dos matches
    vector<int> query_indexes(string &s){
        vector<int> ans;

        vector<bool> vis(trie.size());
        int curr = 0;

        for(auto c : s){
            curr = trie[curr].next[c-offset];

            int up = curr;
            while((up > 0) && !vis[up]){
                vis[up] = true;

                if(trie[up].isword){
                    for(auto id : trie[up].idxs){
                        ans.push_back(id);
                    }
                }

                up = trie[up].exlink;
            }
        }

        return ans;
    }

};


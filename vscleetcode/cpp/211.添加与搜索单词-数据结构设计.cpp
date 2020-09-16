/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class Trie {
    string word = "";
    Trie *childs[26];
    Trie() {
        for (int i = 0; i < childs.size(); i++) {
            childs[i] = new Trie();
        }
    }
};
class WordDictionary {
private:
    Trie *trie;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie->word = "";
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto node = trie;
        for (auto c : word) {
            if (node->childs[c - 'a'] == nullptr) {
                node->childs[c - 'a'] = new Trie();
            }
            node = node->childs[c - 'a'];
        }
        node->word = word;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie_search(word, trie, 0);
    }

    bool trie_search(string word, Trie *node, int idx) {
        for (auto c : word) {
            if (c == '.') return search(word)
            if (node->childs[c - 'a'] == nullptr) {
                return false;
            }
            node = node->childs[c - 'a'];
        }

        return node->word != "";
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end


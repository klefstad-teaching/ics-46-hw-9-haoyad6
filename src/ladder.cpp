#include "ladder.h"
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    
    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        
        for (const string& word : word_list) {
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
                vector<string> new_ladder = ladder;
                new_ladder.push_back(word);
                
                if (word == end_word) {
                    return new_ladder;
                }
                ladder_queue.push(new_ladder);
                visited.insert(word);
            }
        }
    }
    return {};
}

bool is_adjacent(const string& word1, const string& word2) {
    int len1 = word1.size(), len2 = word2.size();
    if (abs(len1 - len2) > 1) return false;
    
    int diff = 0, i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (word1[i] != word2[j]) {
            if (++diff > 1) return false;
            if (len1 > len2) ++i;
            else if (len1 < len2) ++j;
            else { ++i; ++j; }
        } else {
            ++i; ++j;
        }
    }
    return true;
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout << "No word ladder found.\n";
        return;
    }
    for (const string& word : ladder) {
        cout << word << " ";
    }
    cout << endl;
}

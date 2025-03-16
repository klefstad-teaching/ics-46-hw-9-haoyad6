#include <gtest/gtest.h>
#include "dijkstras.h"
#include "ladder.h"

TEST(DijkstraTest, ShortestPathSmall) {
    Graph G;
    file_to_graph("small.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    EXPECT_EQ(distances[1], 5);
    EXPECT_EQ(distances[2], 8);
    EXPECT_EQ(distances[3], 1);
}

TEST(DijkstraTest, ShortestPathMedium) {
    Graph G;
    file_to_graph("medium.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    EXPECT_EQ(distances[1], 5);
    EXPECT_EQ(distances[2], 6);
    EXPECT_EQ(distances[3], 9);
}

TEST(WordLadderTest, BasicLadder) {
    set<string> word_list;
    load_words(word_list, "words.txt");
    vector<string> ladder = generate_word_ladder("cat", "dog", word_list);
    EXPECT_EQ(ladder.size(), 4);
}

TEST(WordLadderTest, ComplexLadder) {
    set<string> word_list;
    load_words(word_list, "words.txt");
    vector<string> ladder = generate_word_ladder("car", "cheat", word_list);
    EXPECT_EQ(ladder.size(), 4);
}

TEST(WordLadderTest, NoLadder) {
    set<string> word_list;
    load_words(word_list, "words.txt");
    vector<string> ladder = generate_word_ladder("aaaaa", "zzzzz", word_list);
    EXPECT_TRUE(ladder.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

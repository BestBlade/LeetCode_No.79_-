/* ------------------------------------------------------------------|
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 

提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	dfs法
*
*	执行用时：76 ms, 在所有 C++ 提交中击败了52.33%的用户
*	内存消耗：11.8 MB, 在所有 C++ 提交中击败了51.35%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool searchWord(vector<vector<char>>& board, vector<vector<int>>& visited,string& word, int i,int j,int k) {
    if (k == word.size()) {
        return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
        return false;
    }
    if (board[i][j] != word[k]) {
        return false;
    }
    if (visited[i][j]) {
        return false;
    }

    visited[i][j] = true;
    if (searchWord(board, visited, word, i - 1, j, k + 1)) {
        return true;
    }
    if (searchWord(board, visited, word, i, j - 1, k + 1)) {
        return true;
    }
    if (searchWord(board, visited, word, i + 1, j, k + 1)) {
        return true;
    }
    if (searchWord(board, visited, word, i, j + 1, k + 1)) {
        return true;
    }
    //如果都没成功返回状态
    visited[i][j] = false;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();
    int len = word.size();
    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (searchWord(board, visited, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
    string word = "ABCCED";

    bool flag = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            flag = searchWord(board, word, { i, j });
            if (flag) {
                return true;
            }
        }
    }
}
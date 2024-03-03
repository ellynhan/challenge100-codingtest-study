#include <vector>

using namespace std;

vector<vector<int>> solution(int n, int m, vector<int> fold, vector<vector<int>> cut) {
    // Initialize the colored paper with all 1s
    vector<vector<int>> coloredPaper(n, vector<int>(m, 1));

    // Simulate folding
    for (int i : fold) {
        if (i == 1) {
            // Fold horizontally
            n /= 2;
        } else if (i == -1) {
            // Fold vertically
            m /= 2;
        }
    }

    // Mark the cut areas as 0
    for (const vector<int>& c : cut) {
        coloredPaper[c[0] - 1][c[1] - 1] = 0;
    }

    // Reverse the folding operations
    for (int i = fold.size() - 1; i >= 0; i--) {
        if (fold[i] == 1) {
            // Unfold horizontally
            n *= 2;
            vector<vector<int>> temp(n, vector<int>(m, 1));
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    temp[j][k] = coloredPaper[j / 2][k];
                }
            }
            coloredPaper = temp;
        } else if (fold[i] == -1) {
            // Unfold vertically
            m *= 2;
            vector<vector<int>> temp(n, vector<int>(m, 1));
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    temp[j][k] = coloredPaper[j][k / 2];
                }
            }
            coloredPaper = temp;
        }
    }

    return coloredPaper;
}

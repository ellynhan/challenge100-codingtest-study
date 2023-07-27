#include "timebomb.h"
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> compareResults;

int findMax(vector<int> index)
{
  int len = index.size();

  if (len == 2){
    return box_comp(index[0], index[1]) > 0 ? index[0] : index[1];
  }

  vector<int> new_index(len / 2 + len % 2);

  int i;
  for (i = 0; i < len - 1; i += 2){
    new_index[i / 2] = box_comp(index[i], index[i + 1]) > 0 ? index[i] : index[i + 1];
  }
  if (i == len - 1){
    new_index[i / 2] = index[i];
  }

  compareResults.push_back(new_index);
  return findMax(new_index);
}

int findSecond(int maxIndex, int depth, int winner)
{
  vector<int>& compareResult = compareResults[depth];

  int N = compareResult.size();
  int maxIndexPos = find(compareResult.begin(), compareResult.end(), maxIndex) - compareResult.begin();
  
  int challenger;
  if (maxIndexPos % 2) challenger = compareResult[maxIndexPos - 1];
  else                 challenger = maxIndexPos == N - 1 ? -1 : compareResult[maxIndexPos + 1];

  if      (winner == -1)     winner = challenger;
  else if (challenger == -1) winner = winner;
  else                       winner = box_comp(winner, challenger) > 0 ? winner : challenger;

  if (depth == compareResults.size() - 1) {
    return winner;
  }

  return findSecond(maxIndex, depth + 1, winner);
}

int main()
{
  int N, maxIndex, secondIndex;
  box_ready();
  N = box_size();
  vector<int> index(N);
  for (int i = 0; i < N; i++) {
    index[i] = i + 1;
  }
  maxIndex = findMax(index);

  int winner;
  if (maxIndex % 2) winner = maxIndex == N ? -1 : maxIndex + 1;
  else              winner = maxIndex - 1;
  secondIndex = findSecond(maxIndex, 0, winner);

  box_report(secondIndex);

  return 0;
}
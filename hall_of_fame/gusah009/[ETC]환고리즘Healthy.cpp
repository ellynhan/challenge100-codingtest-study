#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321
#define MAX_N 50
#define FOOD_COUNT 4
#define ull unsigned long long

int N;
int m[FOOD_COUNT];
int totalFoodSum[MAX_N][FOOD_COUNT] = {0};
typedef struct _foodType {
 int index;
 int foodSum;
 int food[FOOD_COUNT];
 int price;
 int lastChoice = 0;
 ull isChoice = 0;
} foodType;

foodType foods[MAX_N];
foodType answer;

struct compare {
	bool operator()(const foodType& food1, const foodType& food2) {
  return food1.foodSum < food2.foodSum;
	}
};

bool compare2(const foodType& food1, const foodType& food2) {
 return (double)food1.foodSum / food1.price > (double)food2.foodSum / food2.price;
}
priority_queue<foodType, vector<foodType>, compare> pq;

void input()
{
 cin >> N;

 FOR(i, FOOD_COUNT) {
  cin >> m[i];
 }

 FOR(n, N) {
  FOR(i, FOOD_COUNT) {
   cin >> foods[n].food[i];
  }
  foods[n].index = n;
  cin >> foods[n].price;
 }

 sort(foods, foods + N, compare2);

 FOR(n, N) {
  FOR(i, FOOD_COUNT) {
   foods[n].foodSum += foods[n].food[i];
  }
  foods[n].isChoice |= (1LL << n);
  foods[n].lastChoice = n;
  FOR(i, n) {
   FOR(j, FOOD_COUNT) {
    totalFoodSum[i][j] += foods[n].food[j];
   }
  }
 }
 answer.foodSum = INF;
 answer.price = INF;
}

bool answerComp(foodType &food1, foodType &food2) {
 if (food1.price == food2.price) {
  if (food1.foodSum == food2.foodSum) {
   string s1 = "", s2 = "";
   FOR(n, N) {
    if (food1.isChoice & (1LL << n)) s1 += n;
    if (food2.isChoice & (1LL << n)) s2 += n;
   }
   return s1 < s2;
  }
  return food1.foodSum > food2.foodSum;
 }
 return food1.price < food2.price;
}

void setAnswer(foodType &food) {
 cout << pq.size() << ' ' << answer.price << '\n';
 if (answerComp(food, answer)) answer = food;
}

void BFS()
{
 int i, j, n;
 foodType cur;
 while (!pq.empty()) {
  cur = pq.top();
  pq.pop();

  for (j = 0; j < FOOD_COUNT; j++) {
   if (cur.food[j] + totalFoodSum[cur.lastChoice][j] < m[j]) break;
  }
  if (j != FOOD_COUNT) continue;

  for (i = 0; i < FOOD_COUNT; i++) {
   if (cur.food[i] < m[i]) break;
  }

  if (i == FOOD_COUNT) {
   setAnswer(cur);
   continue;
  }

  for (n = cur.lastChoice + 1; n < N; n++) {
   if (answer.price >= cur.price + foods[n].price) {
    foodType next;
    next.price = cur.price + foods[n].price;
    next.foodSum = cur.foodSum + foods[n].foodSum;
    FOR(i, FOOD_COUNT) {
     next.food[i] = cur.food[i] + foods[n].food[i];
    }
    next.isChoice = cur.isChoice | (1LL << n);
    next.lastChoice = n;
    pq.push(next);
   }
  }
 }
}

void solve()
{
 FOR(n, N) {
  pq.push(foods[n]);
 }

 BFS();
}

void print()
{
 set<int> ans;
 FOR(n, N) {
  if(answer.isChoice & (1LL << n)) {
   ans.insert(foods[n].index);
  }
 }
 if (ans.empty()) {
  cout << '0';
 } else {
  for (auto it = ans.begin(); it != ans.end(); it++) cout << *it + 1 << ' ';
 }
 cout << '\n';
}

int main()
{
 ios_base :: sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
 input();
 solve();
 print();
}
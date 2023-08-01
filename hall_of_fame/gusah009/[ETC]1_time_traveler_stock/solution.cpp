#include <algorithm>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_STOCK_NUM 6
#define FOR(i, j) for (int i = 0; i < j; i++)

struct buyOrder
{
  int mNumber, mQuantity, mPrice;

  buyOrder(const int &mNumber, const int &mQuantity, const int &mPrice)
      : mNumber(mNumber),
        mQuantity(mQuantity),
        mPrice(mPrice) {}

  bool operator<(const buyOrder &otherBuyOrder) const
  {
    if (mPrice == otherBuyOrder.mPrice)
    {
      return mNumber < otherBuyOrder.mNumber;
    }
    else
      return mPrice > otherBuyOrder.mPrice;
  }

  bool operator==(const buyOrder &otherBuyOrder) const
  {
    return mNumber == otherBuyOrder.mNumber;
  }
} typedef BuyOrder;

struct sellOrder
{
  int mNumber, mQuantity, mPrice;

  sellOrder(const int &mNumber, const int &mQuantity, const int &mPrice)
      : mNumber(mNumber),
        mQuantity(mQuantity),
        mPrice(mPrice) {}

  bool operator<(const sellOrder &otherSellOrder) const
  {
    if (mPrice == otherSellOrder.mPrice)
    {
      return mNumber < otherSellOrder.mNumber;
    }
    else
      return mPrice < otherSellOrder.mPrice;
  }
  bool operator==(const sellOrder &otherSellOrder) const
  {
    return mNumber == otherSellOrder.mNumber;
  }
} typedef SellOrder;

set<BuyOrder> buyOrders[MAX_STOCK_NUM];
set<SellOrder> sellOrders[MAX_STOCK_NUM];
vector<int> tradeHistory[MAX_STOCK_NUM];

void init()
{
  FOR(mStock, MAX_STOCK_NUM)
  {
    set<BuyOrder> emptyBuyOrder;
    swap(buyOrders[mStock], emptyBuyOrder);
    set<SellOrder> emptySellOrder;
    swap(sellOrders[mStock], emptySellOrder);
    vector<int> emptyTradeHistory;
    swap(tradeHistory[mStock], emptyTradeHistory);
  }
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
  while (!sellOrders[mStock].empty() &&
         mPrice >= sellOrders[mStock].begin()->mPrice &&
         mQuantity > 0)
  {
    tradeHistory[mStock].push_back(sellOrders[mStock].begin()->mPrice);
    if (mQuantity >= sellOrders[mStock].begin()->mQuantity)
    {
      mQuantity -= sellOrders[mStock].begin()->mQuantity;
      sellOrders[mStock].erase(sellOrders[mStock].begin());
    }
    else
    {
      SellOrder tmp = *(sellOrders[mStock].begin());
      sellOrders[mStock].erase(sellOrders[mStock].begin());
      tmp.mQuantity -= mQuantity;
      sellOrders[mStock].insert(tmp);
      mQuantity = 0;
    }
  }
  if (mQuantity != 0)
  {
    buyOrders[mStock].insert({mNumber, mQuantity, mPrice});
  }
  return mQuantity;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
  while (!buyOrders[mStock].empty() &&
         mPrice <= buyOrders[mStock].begin()->mPrice &&
         mQuantity > 0)
  {
    tradeHistory[mStock].push_back(buyOrders[mStock].begin()->mPrice);
    if (mQuantity >= buyOrders[mStock].begin()->mQuantity)
    {
      mQuantity -= buyOrders[mStock].begin()->mQuantity;
      buyOrders[mStock].erase(buyOrders[mStock].begin());
    }
    else
    {
      BuyOrder tmp = *(buyOrders[mStock].begin());
      buyOrders[mStock].erase(buyOrders[mStock].begin());
      tmp.mQuantity -= mQuantity;
      buyOrders[mStock].insert(tmp);
      mQuantity = 0;
    }
  }
  if (mQuantity != 0)
  {
    sellOrders[mStock].insert({mNumber, mQuantity, mPrice});
  }
  return mQuantity;
}

void cancel(int mNumber)
{
  BuyOrder tmpBuyOrder = {mNumber, 0, 0};
  SellOrder tmpSellOrder = {mNumber, 0, 0};
  bool isFind = false;
  FOR(mStock, MAX_STOCK_NUM)
  {
    if (isFind) break;
    for (auto buyIter = buyOrders[mStock].begin(); buyIter != buyOrders[mStock].end(); buyIter++) {
      if (buyIter->mNumber == mNumber) {
        buyOrders[mStock].erase(buyIter);
        isFind = true;
        break;
      }
    }
    for (auto sellIter = sellOrders[mStock].begin(); sellIter != sellOrders[mStock].end(); sellIter++) {
      if (sellIter->mNumber == mNumber) {
        sellOrders[mStock].erase(sellIter);
        isFind = true;
        break;
      }
    }
  }
}

int bestProfit(int mStock)
{
  int minTrade = tradeHistory[mStock][0];
  int curTrade = tradeHistory[mStock][0];
  int maxTrade = 0;
  FOR(trade, tradeHistory[mStock].size()) {
    minTrade = min(minTrade, tradeHistory[mStock][trade]);
    curTrade = tradeHistory[mStock][trade];
    maxTrade = max(maxTrade, curTrade - minTrade);
  }
  return maxTrade;
}
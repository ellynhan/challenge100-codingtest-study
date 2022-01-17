// [ETC] 시간여행자의 주식 / 난이도:? / 하루
// 2022 삼성 dx 동계 대학생 알고리즘 특강 테스트 1번 문제

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#define MAX_PRICE 1000000

using namespace std;

class Order // 매출/매도 주문 저장 클래스
{
public:
    Order(int, int, int, int);
    int getNumber(void);
    int getPrice(void);
    int getQuantity(void);
    int getStock(void);
    void setQuantity(int);

private:
    int number;
    int stock;
    int quantity;
    int price;
};

Order::Order(int mNumber, int mStock, int mQuantity, int mPrice)
    : number(mNumber), stock(mStock), quantity(mQuantity), price(mPrice) {}

int Order::getNumber(void) { return number; }
int Order::getPrice(void) { return price; }
int Order::getQuantity(void) { return quantity; }
int Order::getStock(void) { return stock; }
void Order::setQuantity(int quantitySet) { quantity = quantitySet; }

struct greaterPrice // 작은 price를 top으로
{
    bool operator()(vector<Order>::iterator t, vector<Order>::iterator u)
    {
        int tPrice = t->getPrice();
        int uPrice = u->getPrice();

        if (tPrice == uPrice)
            return t->getNumber() > u->getNumber();

        return tPrice > uPrice;
    }
};

struct lessPrice // 큰 price를 top으로
{
    bool operator()(vector<Order>::iterator t, vector<Order>::iterator u)
    {
        int tPrice = t->getPrice();
        int uPrice = u->getPrice();

        if (tPrice == uPrice)
            return t->getNumber() > u->getNumber();
        // cout << tPrice << "<" << uPrice << endl;
        return tPrice < uPrice;
    }
};

bool cmp(pair<int, int> t, pair<int, int> u)
{
    return t.second < u.second;
}

struct profitSaved // 이득 정보 저장 구조체
{
    int minPrice = MAX_PRICE;
    int maxProfit = 0;
    int index = 0;
};

vector<Order> buyOrderVector;
vector<Order> sellOrderVector;
vector<vector<int>> dealPriceVector(6);
vector<profitSaved> profitContainer(6, profitSaved());

void init()
{
    // 모든 vector clear
    buyOrderVector.clear();
    sellOrderVector.clear();
    profitContainer.clear();
    for (int i = 0; i < 6; i++)
    {
        dealPriceVector[i].clear();
        profitContainer[i] = profitSaved();
    }
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    Order buyOrder(mNumber, mStock, mQuantity, mPrice);
    priority_queue<Order, vector<vector<Order>::iterator>, greaterPrice> buyQueue; // 구매예정목록
    for (vector<Order>::iterator it = sellOrderVector.begin();
         it != sellOrderVector.end();)
    {
        if (it->getQuantity() == 0) // 수량이 없어진 주문은 queue에 넣기전에 vector에서 삭제
        {
            // cout << "price : " << it->getPrice() << endl;
            sellOrderVector.erase(it);
            continue;
        }
        if ((it->getStock() == buyOrder.getStock()) && (it->getPrice() <= buyOrder.getPrice()))
        {
            buyQueue.push(it); // priority queue에 가격이 우선되도록 저장
            // cout << "stock : " << it->getStock() << " price : " << it->getPrice() << endl;
        }
        it++;
    }

    if (!buyQueue.empty())
    {
        int dealResult;
        // cout << "top : " << buyQueue.top()->getPrice() << endl;
        do
        {
            dealResult = buyOrder.getQuantity() - buyQueue.top()->getQuantity();

            dealPriceVector[buyOrder.getStock()].push_back(buyQueue.top()->getPrice()); // 거래가 된 주문의 가격을 vector에 저장

            if (dealResult > 0)
            { // 거래량이 남음
                // sellOrderVector.erase(buyQueue.top());
                buyQueue.top()->setQuantity(0);
                buyQueue.pop();
                buyOrder.setQuantity(dealResult);
            }

            if (dealResult == 0)
            { // 거래가 맞아떨어짐
                // sellOrderVector.erase(buyQueue.top());
                buyQueue.top()->setQuantity(0);
                buyQueue.pop();
                buyOrder.setQuantity(0);
            }

            if (dealResult < 0)
            { // 거래량 부족
                buyQueue.top()->setQuantity(-1 * dealResult);
                buyOrder.setQuantity(0);
            }
        } while (!buyQueue.empty() && dealResult > 0);

        if (dealResult > 0)
            buyOrderVector.push_back(buyOrder); // queue를 다 돌아보고도 수량이 남으면 vector에 저장
    }
    else
    {
        buyOrderVector.push_back(buyOrder); // queue가 비어있으면 그냥 vector에 저장
    }
    // cout << "my ans : " << buyOrder.getQuantity() << endl;
    return buyOrder.getQuantity();
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
    Order sellOrder(mNumber, mStock, mQuantity, mPrice);

    priority_queue<Order, vector<vector<Order>::iterator>, lessPrice> sellQueue; // 판매예정목록

    for (vector<Order>::iterator it = buyOrderVector.begin();
         it != buyOrderVector.end();)
    {
        if (it->getQuantity() == 0)
        {
            // cout << "price : " << it->getPrice() << endl;
            buyOrderVector.erase(it);
            continue;
        }
        if (it->getStock() == sellOrder.getStock() && it->getPrice() >= sellOrder.getPrice())
        {
            sellQueue.push(it);
            // cout << "push : " << it.<< " : " << it->getPrice() << endl;
        }
        it++;
    }

    if (!sellQueue.empty())
    {
        int dealResult;

        do
        {
            dealResult = sellOrder.getQuantity() - sellQueue.top()->getQuantity();

            dealPriceVector[sellOrder.getStock()].push_back(sellQueue.top()->getPrice());

            if (dealResult > 0)
            { // 거래량이 남음
                // cout << sellOrder.getQuantity() << " - " << sellQueue.top()->getQuantity() << endl;
                // buyOrderVector.erase(sellQueue.top());
                sellQueue.top()->setQuantity(0);
                sellQueue.pop();
                sellOrder.setQuantity(dealResult);
            }

            if (dealResult == 0)
            { // 거래가 맞아떨어짐
                // buyOrderVector.erase(sellQueue.top());
                sellQueue.top()->setQuantity(0);
                sellQueue.pop();
                sellOrder.setQuantity(0);
            }

            if (dealResult < 0)
            { // 거래량 부족
                // cout << sellQueue.top()->getQuantity() << " - " << sellOrder.getQuantity() << endl;
                sellQueue.top()->setQuantity(-1 * dealResult);
                // cout << "topq : " << sellQueue.top()->getQuantity() << endl;
                sellOrder.setQuantity(0);
            }
        } while (!sellQueue.empty() && dealResult > 0);

        if (dealResult > 0)
            sellOrderVector.push_back(sellOrder);
    }
    else
    {
        sellOrderVector.push_back(sellOrder);
    }

    return sellOrder.getQuantity();
}

void cancel(int mNumber)
{
    bool eraseFindFlag = false;

    for (vector<Order>::iterator it = buyOrderVector.begin();
         it != buyOrderVector.end(); it++)
    {
        if (it->getNumber() == mNumber)
        {
            eraseFindFlag = true;
            buyOrderVector.erase(it);
            break;
        }
    }

    if (!eraseFindFlag) // 매수 목록에서 못 찾았으면 매도 목록에서 찾기
    {
        for (vector<Order>::iterator it = sellOrderVector.begin();
             it != sellOrderVector.end(); it++)
        {
            if (it->getNumber() == mNumber)
            {
                eraseFindFlag = true;
                sellOrderVector.erase(it);
                break;
            }
        }
    }
}

int bestProfit(int mStock)
{
    int presentPrice;
    int presentProfit;
    int presentIndex = 0;
    int minDealPrice = profitContainer[mStock].minPrice; // 이 stock에 저장한 최소가격, 무조건 index보다는 전 시점의 가격
    int maxProfit = profitContainer[mStock].maxProfit;   // 이 stock에 저장한 최대이익

    for (vector<int>::iterator it = dealPriceVector[mStock].begin() + profitContainer[mStock].index;
         it != dealPriceVector[mStock].end(); it++)
    {
        presentPrice = *it;
        if (presentPrice < minDealPrice)
            minDealPrice = presentPrice;

        presentProfit = presentPrice - minDealPrice;

        if (presentProfit > maxProfit)
            maxProfit = presentProfit;

        presentIndex++;
    }

    profitContainer[mStock].minPrice = minDealPrice;
    profitContainer[mStock].maxProfit = maxProfit;
    profitContainer[mStock].index += presentIndex; // 돌아본 for의 횟수만큼 누적되도록

    return maxProfit;
}
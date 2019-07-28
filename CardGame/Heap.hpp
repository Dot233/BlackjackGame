//
//  Heap.hpp
//  CardGame
//
//  Created by 陈远方 on 2019/7/27.
//  Copyright © 2019 陈远方. All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp

#include <vector>
#include <algorithm>

#include "Card.hpp"

class Heap {
public:
    Card operator[](int index);                     //支持数组下标操作:heap[]
    bool insert(Card card);                         //插入一张牌,检测是否有重复,成功返回true
    Card giveOut(int index);                        //根据编号提取一张牌
    Card giveOut(Number number, Color color);       //根据牌面提取一张牌
    Card giveOut();                                 //从牌顶提取一张牌
    bool isEmpty();                                 //牌堆是否为空
    int  getNumber();                               //牌堆总牌数
    int  getCardIndex(Number number, Color color);  //通过牌面获取牌编号
    void clear();                                   //清空牌堆
    
    void initialize();                              //初始化牌堆52张牌,并打乱
private:
    std::vector<Card> _cards;
};

#endif /* Heap_hpp */

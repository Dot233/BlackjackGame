//
//  Card.h
//  CardGame
//
//  Created by 陈远方 on 2019/7/27.
//  Copyright © 2019 陈远方. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

enum Color {//花色
    black = 0,//黑
    red = 1,//红
    flower = 2,//梅
    rect = 3,//方
    black_joker,
    red_joker,
    null
};

enum Status {//状态
    hiden,//非明牌
    shown //明牌
};

enum Number {//数值
    nA = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5, n6 = 6, n7 = 7,
    n8 = 8,n9 = 9, n10 = 10, nJ = 11, nQ = 12, nK = 13
};

typedef struct {
    Color  color;
    Status status;
    Number number;
} Card;

const Card NULL_CARD = {null, hiden, nA};//默认的空卡片

#endif /* Card_hpp */

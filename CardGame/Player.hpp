//
//  Player.hpp
//  CardGame
//
//  Created by 陈远方 on 2019/7/28.
//  Copyright © 2019 陈远方. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <string>

#include "Heap.hpp"
#include "Input.hpp"

class Player {
public:
    Player(Input *input, std::string name);//初始化(本类不管理Input指针的生命周期)
    Command getCommand();//获取行动(由Game类调用)
    void update();//更新状态(由Game类调用)
    std::string getName();//获取名称
    void giveCard(Card card);//接收发牌
    //Heap getHand();//获取手牌的引用
    void clear();//清空手牌
    int getPoint();//计算点数

private:
    Heap _hand;
    Command _command;
    Input *_input;
    std::string _name;
};

#endif /* Player_hpp */

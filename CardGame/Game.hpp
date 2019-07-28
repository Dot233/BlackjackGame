//
//  Game.hpp
//  CardGame
//
//  Created by 陈远方 on 2019/7/27.
//  Copyright © 2019 陈远方. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>

#include "Heap.hpp"
#include "Player.hpp"
#include "LocalInput.hpp"

class Game {
public:
    Game();         //初始化资源
    ~Game();        //释放资源
    void start();   //主循环
    bool isWin();   //判断游戏是否结束
    bool getWin();  //获取赢家,平局默认p1
private:
    Heap       _mainHeap;
    Player     *_p1,   *_p2;
    Command    _last1, _last2;
    LocalInput *_l1,   *_l2;
};

#endif /* Game_hpp */

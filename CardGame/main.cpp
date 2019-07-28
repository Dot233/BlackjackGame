//
//  main.cpp
//  CardGame
//
//  Created by 陈远方 on 2019/7/27.
//  Copyright © 2019 陈远方. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Game.hpp"

int main(int argc, const char * argv[]) {
    srand((unsigned int)(time(NULL)));//随即种子
    
    Game game;
    game.start();
    
    return 0;
}

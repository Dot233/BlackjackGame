//
//  Game.cpp
//  CardGame
//
//  Created by 陈远方 on 2019/7/28.
//  Copyright © 2019 陈远方. All rights reserved.
//

#include "Game.hpp"

bool Game::getWin() {
    if (_last1 == Command::stop && _last2 == Command::stop) {
        if (_p1->getPoint() <= 21 && _p2->getPoint() <= 21) {
            return (_p1->getPoint() >= _p2->getPoint()) ? true : false;
        } else if (_p1->getPoint() > 21 && _p2->getPoint() > 21) {
            return (_p1->getPoint() < _p2->getPoint()) ? true : false;
        } else {
            return _p1->getPoint() <= 21 ? true : false;
        }
    }
    return true;
}

bool Game::isWin() {
    return (_last1 == Command::stop && _last2 == Command::stop) || _mainHeap.isEmpty();
}

void Game::start() {
    _mainHeap.initialize();
    bool turnFlag = true;
    while (true) {
        _p1->update();
        _p2->update();
        
        Command c;
        if (turnFlag) {
            c = _p1->getCommand();
            if (c != Command::no) {
                if (c == Command::get) {
                    _p1->giveCard(_mainHeap.giveOut());
                } else {
                    turnFlag = !turnFlag;
                }
            }
            _last1 = c;
        } else {
            c = _p2->getCommand();
            if (c != Command::no) {
                if (c == Command::get) {
                    _p2->giveCard(_mainHeap.giveOut());
                } else {
                    turnFlag = !turnFlag;
                }
            }
            _last2 = c;
        }
        
        if (isWin()) {
            if (_p1->getPoint() == _p2->getPoint() || _mainHeap.isEmpty()) {
                std::cout << "平局!!" << std::endl;
            } else {
                if (getWin()) {
                    std::cout << _p1->getName() << "胜利!点数是:" << _p1->getPoint() << std::endl;
                } else {
                    std::cout << _p2->getName() << "胜利!点数是:" << _p2->getPoint() << std::endl;
                }
            }
            
            std::cout << "重新开始?(Yes/no)" << std::endl;
            std::string s;
            std::cin >> s;
            
            if (s != "no") {
                turnFlag = true;
                _p1->clear();
                _p2->clear();
                _mainHeap.clear();
                _mainHeap.initialize();
            } else {
                break;
            }
        }
    }
}

Game::Game() {
    _l1 = new LocalInput;
    _l2 = new LocalInput;
    
    _l1->setName("Player1");
    _l2->setName("Player2");
    
    _p1 = new Player(_l1, "Player1");
    _p2 = new Player(_l2, "Player2");
}

Game::~Game() {
    delete _p1;
    delete _p2;
    
    delete _l1;
    delete _l2;
}

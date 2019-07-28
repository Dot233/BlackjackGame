//
//  Player.cpp
//  CardGame
//
//  Created by 陈远方 on 2019/7/28.
//  Copyright © 2019 陈远方. All rights reserved.
//

#include "Player.hpp"

Player::Player(Input *input, std::string name) : _input(input), _name(name) {}

Command Player::getCommand() {
    return _input->getCommand();
}

void Player::update() {
    _input->update();
}

std::string Player::getName() {
    return _name;
}

void Player::giveCard(Card card) {
    if (_hand.getNumber() == 0) {
        card.status = Status::hiden;
    } else {
        card.status = Status::shown;
    }
    _hand.insert(card);
}

/*
 Heap Player::getHand() {
    return _hand;
}
 */

void Player::clear() {
    _hand.clear();
    _command = Command::no;
}

int Player::getPoint() {
    int sum = 0, anum = 0;
    for (int i = 0; i < _hand.getNumber(); i++) {
        switch (_hand[i].number) {
            case Number::nJ:
            case Number::nQ:
            case Number::nK:
                sum+=10;
                break;
            case Number::nA:
                anum++;
                break;
            default:
                sum+=(int)_hand[i].number;
                break;
        }
    }
    
    for (int i = 0; i < anum; i++) {
        if (sum + 11 <= 21) {
            sum += 11;
        } else {
            sum += 1;
        }
    }
    
    return sum;
}

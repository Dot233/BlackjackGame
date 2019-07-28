//
//  Heap.cpp
//  CardGame
//
//  Created by 陈远方 on 2019/7/27.
//  Copyright © 2019 陈远方. All rights reserved.
//

#include "Heap.hpp"

bool Heap::insert(Card card) {
    for (auto it : _cards) {
        if (it.number == card.number && it.color == card.color) {
            return false;
        }
    };
    _cards.push_back(card);
    return true;
}

Card Heap::operator[](int index) { 
    if (index < _cards.size() && index >= 0) {
        return _cards[index];
    } else {
        return NULL_CARD;
    }
}

int Heap::getNumber() { 
    return (int)_cards.size();
}

bool Heap::isEmpty() { 
    return _cards.empty();
}

Card Heap::giveOut() {
    if (!_cards.empty()) {
        Card last = _cards.back();
        _cards.pop_back();
        return last;
    } else {
        return NULL_CARD;
    }
}

Card Heap::giveOut(int index) {
    if (_cards.size() > index && index >= 0) {
        Card c = _cards[index];
        auto it = _cards.begin() + index;
        _cards.erase(it);
        return c;
    } else {
        return NULL_CARD;
    }
}

Card Heap::giveOut(Number number, Color color) { 
    return giveOut(getCardIndex(number, color));
}

int Heap::getCardIndex(Number number, Color color) { 
    for (int i = 0; i < (int)_cards.size(); i++) {
        Card it = _cards[i];
        if (it.number == number && it.color == color) {
            return i;
        }
    }
    return -1;
}

void Heap::clear() { 
    _cards.clear();
    _cards.shrink_to_fit();
}

void Heap::initialize() {
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            Card card = {(Color)i, Status::hiden, (Number)j};
            _cards.push_back(card);
        }
    }
    std::random_shuffle(_cards.begin(), _cards.end());
}

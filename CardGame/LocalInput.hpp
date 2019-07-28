//
//  LocalInput.hpp
//  CardGame
//
//  Created by 陈远方 on 2019/7/28.
//  Copyright © 2019 陈远方. All rights reserved.
//

#ifndef LocalInput_hpp
#define LocalInput_hpp

#include <iostream>
#include <string>

#include "Input.hpp"

class LocalInput : public Input {
public:
    void setName(std::string name) {
        _name = name;
    }
    
    void update() override {}
    
    void updateCommand() override {
        int i = 0;
        while (i != 1 && i != 2 && i != 3) {
            std::cout << _name << " --> 请输入行动:(1.抽牌, 2.停牌, 3.再想想)" << std::endl;
            std::cin >> i;
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (i) {
            case 1:
                setCommand(Command::get);
                break;
            case 2:
                setCommand(Command::stop);
                break;
            case 3:
                setCommand(Command::no);
                break;
        }
    }
private:
    std::string _name;
};

#endif /* LocalInput_hpp */

//
//  Input.hpp
//  CardGame
//
//  Created by 陈远方 on 2019/7/28.
//  Copyright © 2019 陈远方. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

enum Command {//行动
    get,//抽卡
    stop,//停牌
    no//行动未确定
};

class Input {
public:
    Input() : _command(Command::no){}

    virtual void update() = 0;

    Command getCommand() {
        updateCommand();
        
        Command last = _command;
        _command = Command::no;
        return last;
    }

private:
    Command _command;

protected:
    void setCommand(Command command) {
        _command = command;
    }
    Command getCommandWithoutDelete() {
        return _command;
    }
    virtual void updateCommand() = 0;
};

#endif /* Input_hpp */

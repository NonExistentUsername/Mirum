#pragma once

template<class T>
class Command {
private:
    T command;
public:
    Command(T command): command(command) {}

    T execute() {
        return command();
    }
};

template<class T, class... Args> class Command<T(Args...)>;
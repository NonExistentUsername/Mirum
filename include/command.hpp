#pragma once

template<class T, class... Args>
class Command {
private:
    T(Args...) command;
public:
    Command(T(Args...) command): command(command) {}

    T execute() {
        return command();
    }
};

template<class T, class... Args> class Command<T(Args...)>;
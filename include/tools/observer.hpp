#pragma once

////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////

template<class T>
class Observer {
public:
    virtual void notify(T message) = 0;
    virtual ~Observer() {}
};

////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////

#include <memory>

template<class T> class ObserversManager;

template<class T>
class ObserverNode {
protected:
    using _unique_node_ptr = std::unique_ptr<ObserverNode<T>>;
    using _weak_node_ptr = ObserverNode<T>*;

    using _unique_observer_ptr = std::unique_ptr<Observer<T>>;

    _unique_node_ptr next = nullptr;
    _weak_node_ptr previous = nullptr;

    _unique_observer_ptr observer;

    ObserverNode(_unique_observer_ptr observer):
        observer(std::move(observer)) {}

    friend class ObserversManager<T>;
};

////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////

template<class T> class ObserverKey;

template<class T>
class ObserversManager : public Observer<T> {
private:
    using _unique_node_ptr = std::unique_ptr<ObserverNode<T>>;
    using _weak_node_ptr = ObserverNode<T>*;

    using _unique_observer_ptr = std::unique_ptr<Observer<T>>;

    _unique_node_ptr first;
    _weak_node_ptr last = nullptr;

    _weak_node_ptr current = nullptr;
    bool current_to_delete = false;

    void create_head(_unique_observer_ptr observer) {
        first.reset(new ObserverNode<T>(std::move(observer)));
        last = first.get();
    }
    
    void remove_node(_weak_node_ptr node) {
        if(node->next)
            node->next->previous = node->previous;
        if(node->previous)
            node->previous->next = std::move(node->next);
    }
protected:
    void remove(_weak_node_ptr node) {
        if(node == current)
            current_to_delete = true;
        else {
            remove_node(node);
        }
    }

    friend class ObserverKey<T>;
public:
    ObserverKey<T> add(_unique_observer_ptr observer) {
        if(last == nullptr)
            create_head(std::move(observer));
        else {
            last->next.reset(
                new ObserverNode<T>(
                    std::move(observer)
                    )
                );
            last->next->previous = last;
            last = last->next.get();
        }
        return ObserverKey<T>(this, last);
    }

    void notify(T message) override {
        current = first.get();
        while(current) {
            current->observer->notify(message);

            if(current_to_delete)
                remove_node(current);
            
            current = current->next.get();
        }
    }
};

////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////

template<class T>
class ObserverKey {
private:
    using _weak_node_ptr = ObserverNode<T>*;
    using _weak_observers_manager_ptr = ObserversManager<T>*;

    _weak_observers_manager_ptr manager = nullptr;
    _weak_node_ptr node = nullptr;
protected:
    ObserverKey(_weak_observers_manager_ptr manager, _weak_node_ptr node): 
        manager(manager), node(node) {}

    friend class ObserversManager<T>;
public:
    void remove() {
        this->manager->remove(node);
    }
};

////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
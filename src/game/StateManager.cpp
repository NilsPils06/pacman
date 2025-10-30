#include "StateManager.h"

StateManager::StateManager(std::unique_ptr<State> initial) {
    states.push(std::move(initial));
}
void StateManager::push(std::unique_ptr<State> s) {
    states.push(std::move(s));
}
void StateManager::pop() {
    states.pop();
}
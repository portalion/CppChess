#pragma once
#include <stack>

class State
{
protected:
	std::stack<State*>* stateStack;
public:
	State(std::stack<State*>* stateStack);
	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void draw() const = 0;
};


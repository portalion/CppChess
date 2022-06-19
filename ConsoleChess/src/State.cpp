#include "State.h"

State::State(std::stack<State*>* stateStack)
	:stateStack(stateStack)
{
}

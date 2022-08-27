#pragma once

#include <utility>

using Position = std::pair<size_t, size_t>;

class Cell
{
public:
	enum class State { BLACK, WHITE, BLANK,       h1,h2,h3,h4,h5,h6,h7,h8,       w0,w1,w2,w3,w4,w5,w6,w7,w8,w9 };//днаюбхкх EDGE

	Cell(State st);
	~Cell();

	State getState() const { return mState; }
	void setState(State st) { mState = st; }

private:
	State mState;
};


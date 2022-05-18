#pragma once
class Object
{
	static unsigned int count;
public:
	static unsigned int getCount() { return count; }
	Object();
	~Object();
};
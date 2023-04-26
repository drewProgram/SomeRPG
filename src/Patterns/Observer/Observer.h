#pragma once

#include "IObserver.h"

class Observer : public IObserver
{
public:
	Observer();
	virtual ~Observer();

	void OnNotify(const Actor& actor, Event event) override;

private:

};
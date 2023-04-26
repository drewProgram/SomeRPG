#pragma once

#include "Actor.h"
#include "Event.h"

class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void OnNotify(const Actor& actor, Event event) = 0;
};
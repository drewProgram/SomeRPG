#pragma once

#include <list>

#include "ISubject.h"

class Subject : public ISubject
{
public:
	virtual ~Subject();

	void Attach(IObserver* observer) override;
	void Detach(IObserver* observer) override;
	void Notify() override;

private:
	std::list<IObserver*> m_ListObserver;
};
#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include "World.h"


class Behaviour {
public:
	virtual ~Behaviour() {}
	virtual bool tick(World &world, Entity &owner) = 0;
};

#endif
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include "solid.h"
#include "hitRecord.h"

class scene
{
public:
	scene() {}

	const void addSolid(std::shared_ptr<solid> s)
	{
		solids.push_back(s);
	}

	const hitRecord sendRay(ray& ray) const
	{

	}

private:
	std::vector<std::shared_ptr<solid>> solids;
};

#endif SCENE_H
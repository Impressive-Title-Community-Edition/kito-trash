#ifndef __HeightFunction_h_
#define __HeightFunction_h_
#pragma once
//This provides functions that can be used to easily get the height of Ogre's terrain at any x/z point.
//Simply call HeightFunction::initialize(), then use HeightFunction::getTerrainHeight() as needed.

//This file is used by the PagedGeometry examples to place trees on the terrain.

#include "Ogre.h"
using namespace Ogre;

namespace HeightFunction
{
	TerrainGroup *mTerrainGroup;

	//Initializes the height function. Call this before calling getTerrainHeight()
	void initialize(TerrainGroup *TrGroup){
			mTerrainGroup = TrGroup;
	}

	//Gets the height of the terrain at the specified x/z coordinate
	//The userData parameter isn't used in this implementation of a height function, since
	//there's no need for extra data other than the x/z coordinates.
	inline float getTerrainHeight(const float x, const float z, void *userData = NULL){
		Ray ray;
		ray.setOrigin(Vector3(x, 10000, z));
		ray.setDirection(Vector3::NEGATIVE_UNIT_Y);
		TerrainGroup::RayResult rayResult = mTerrainGroup->rayIntersects(ray);
		if(rayResult.hit)
			return rayResult.position.y;
		return 0;
	}
}
#endif
#ifndef __MagixWorldEditor_h_
#define __MagixWorldEditor_h_
//#pragma once
using namespace Ogre;

#include "PagedGeometry.h"
#include "GrassLoader.h"
#include "BatchPage.h"
#include "ImpostorPage.h"
#include "TreeLoader2D.h"
#include "TreeLoader3D.h"
#include "HeightFunction.h"
#include "terrainmaterial.hpp"
#include "MagixGUI.h"
#include "MagixWorld.h"
#include <OgreTerrain.h>
#include <OgreTerrainGroup.h>
#include <OgreStreamSerialiser.h>


using namespace OgreBulletCollisions;
using namespace OgreBulletDynamics;

using namespace Forests;
using namespace Ogre;

#define MAX_LIGHTS 3

class MagixWorldEditor
{
protected:
	MagixExternalDefinitions *mDef;
	MagixGameStateManager *mGameStateManager;
	MagixSoundManager *mSoundManager;
	MagixCollisionManager *mCollisionManager;
	MagixSkyManager *mSkyManager;
	SceneManager *mSceneMgr;
	RenderWindow *mWindow;
	MagixCamera *mCamera;
	MagixWorld *mWorld;
	MagixGUI *mGui;
	Real mBrushSizeTerrainSpace;
	SceneNode* mEditNode;
	Entity* mEditMarker;
	bool mModifierActive;
	bool mModifierRaise;
	enum Mode
	{
		MODE_NORMAL = 0,
		MODE_EDIT_HEIGHT = 1,
		MODE_EDIT_BLEND = 2,
		MODE_COUNT = 3
	};
	Mode mMode;
	Real mHeightUpdateCountDown;
	Real mHeightUpdateRate;
	Ogre::uint8 mLayerEdit;
	OverlayElement *mInfoBox;
	OverlayElement *mInfoBoxText;
	bool mTerrainsImported;
public:
	MagixWorldEditor()
	{
		mDef = 0;
		mGameStateManager = 0;
		mSoundManager = 0;
		mCollisionManager = 0;
		mSkyManager = 0;
		mSceneMgr = 0;
		mWindow = 0;
		mWorld = 0;
		mGui = 0;
		mBrushSizeTerrainSpace = 0.02;
		mModifierActive = false;
		mModifierRaise = false;
		mMode = MODE_EDIT_HEIGHT;
		mHeightUpdateCountDown = 0;
		mHeightUpdateRate = 1.0 / 20.0;
		mLayerEdit = 1; // blend layer
		mInfoBox = 0;
		mInfoBoxText = 0;
		mTerrainsImported = false;
	}
	~MagixWorldEditor()
	{
		//mWorld->unloadWorld();
	}
	void initialize(SceneManager *sceneMgr, RenderWindow *window, MagixExternalDefinitions *def, MagixGameStateManager *gameStateMgr, MagixSoundManager *soundMgr, MagixCollisionManager *collisionMgr, MagixSkyManager *skyMgr, MagixCamera *camera, MagixWorld *world, MagixGUI *gui)
	{
		mSceneMgr = sceneMgr;
		mWindow = window;
		mDef = def;
		mCamera = camera;
		mGameStateManager = gameStateMgr;
		mSoundManager = soundMgr;
		mCollisionManager = collisionMgr;
		mSkyManager = skyMgr;
		mWorld = world;
		mGui = gui;

		mEditMarker = mSceneMgr->createEntity("editMarker", "sphere.mesh");
		mEditNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		mEditNode->attachObject(mEditMarker);
		mEditNode->setScale(0.05, 0.05, 0.05);

		OverlayManager::getSingleton().getByName("GUIOverlay/WorldEditorInfo")->hide();
		mInfoBox = OverlayManager::getSingleton().getOverlayElement("GUI/WorldEditorInfoBox");
		mInfoBoxText = OverlayManager::getSingleton().getOverlayElement("GUI/WorldEditorInfoBoxText");
	}
	void reset()
	{
		mWorld->reset();
	}
	void update(const FrameEvent &evt)
	{
		const Ray mouseRay = mCamera->getCamera()->getCameraToViewportRay(mGui->getMouseX(),mGui->getMouseY());
		TerrainGroup::RayResult rayResult = mWorld->getTerrainGroup()->rayIntersects(mouseRay);
		if (rayResult.hit)
		{
			mEditMarker->setVisible(true);
			mEditNode->setPosition(rayResult.position);

			// figure out which terrains this affects
			TerrainGroup::TerrainList terrainList;
			Real brushSizeWorldSpace = mWorld->getWorldSize().x * mBrushSizeTerrainSpace;
			Sphere sphere(rayResult.position, brushSizeWorldSpace);
			mWorld->getTerrainGroup()->sphereIntersects(sphere, &terrainList);

			for (TerrainGroup::TerrainList::iterator ti = terrainList.begin();
				ti != terrainList.end(); ++ti)
				doTerrainModify(*ti, rayResult.position, evt.timeSinceLastFrame);
		}
		else
		{
			mEditMarker->setVisible(false);
		}

		if (mHeightUpdateCountDown > 0)
		{
			mHeightUpdateCountDown -= evt.timeSinceLastFrame;
			if (mHeightUpdateCountDown <= 0)
			{
				mWorld->getTerrainGroup()->update();
				mHeightUpdateCountDown = 0;

			}

		}

		if (mWorld->getTerrainGroup()->isDerivedDataUpdateInProgress())
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/WorldEditorInfo")->show();
			if (mTerrainsImported)
			{
				mInfoBoxText->setCaption("Building terrain, please wait...");
			}
			else
			{
				mInfoBoxText->setCaption("Updating textures, patience...");
			}

		}
		else
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/WorldEditorInfo")->hide();
			if (mTerrainsImported)
			{
				//saveTerrains(true);
				mTerrainsImported = false;
			}
		}
	}
	void setCurrentModifier(const bool active=false, const bool raise=false)
	{
		mModifierActive = active;
		mModifierRaise = raise;
	}
	void doTerrainModify(Terrain* terrain, const Vector3& centrepos, Real timeElapsed)
	{
		Vector3 tsPos;
		terrain->getTerrainPosition(centrepos, &tsPos);
		if (mModifierActive)
		{
			switch(mMode)
			{
			case MODE_EDIT_HEIGHT:
				{
					// we need point coords
					Real terrainSize = (terrain->getSize() - 1);
					long startx = (tsPos.x - mBrushSizeTerrainSpace) * terrainSize;
					long starty = (tsPos.y - mBrushSizeTerrainSpace) * terrainSize;
					long endx = (tsPos.x + mBrushSizeTerrainSpace) * terrainSize;
					long endy= (tsPos.y + mBrushSizeTerrainSpace) * terrainSize;
					startx = std::max(startx, 0L);
					starty = std::max(starty, 0L);
					endx = std::min(endx, (long)terrainSize);
					endy = std::min(endy, (long)terrainSize);
					for (long y = starty; y <= endy; ++y)
					{
						for (long x = startx; x <= endx; ++x)
						{
							Real tsXdist = (x / terrainSize) - tsPos.x;
							Real tsYdist = (y / terrainSize)  - tsPos.y;

							Real weight = std::min((Real)1.0, 
								Math::Sqrt(tsYdist * tsYdist + tsXdist * tsXdist) / Real(0.5 * mBrushSizeTerrainSpace));
							weight = 1.0 - (weight * weight);

							float addedHeight = weight * 250.0 * timeElapsed;
							float newheight;
							if (mModifierRaise)
								newheight = terrain->getHeightAtPoint(x, y) + addedHeight;
							else
								newheight = terrain->getHeightAtPoint(x, y) - addedHeight;
							terrain->setHeightAtPoint(x, y, newheight);

						}
					}
					if (mHeightUpdateCountDown == 0)
						mHeightUpdateCountDown = mHeightUpdateRate;
				}
				break;
			case MODE_EDIT_BLEND:
				{
					TerrainLayerBlendMap* layer = terrain->getLayerBlendMap(mLayerEdit);
					// we need image coords
					Real imgSize = terrain->getLayerBlendMapSize();
					long startx = (tsPos.x - mBrushSizeTerrainSpace) * imgSize;
					long starty = (tsPos.y - mBrushSizeTerrainSpace) * imgSize;
					long endx = (tsPos.x + mBrushSizeTerrainSpace) * imgSize;
					long endy= (tsPos.y + mBrushSizeTerrainSpace) * imgSize;
					startx = std::max(startx, 0L);
					starty = std::max(starty, 0L);
					endx = std::min(endx, (long)imgSize);
					endy = std::min(endy, (long)imgSize);
					for (long y = starty; y <= endy; ++y)
					{
						for (long x = startx; x <= endx; ++x)
						{
							Real tsXdist = (x / imgSize) - tsPos.x;
							Real tsYdist = (y / imgSize)  - tsPos.y;

							Real weight = std::min((Real)1.0, 
								Math::Sqrt(tsYdist * tsYdist + tsXdist * tsXdist) / Real(0.5 * mBrushSizeTerrainSpace));
							weight = 1.0 - (weight * weight);

							float paint = weight * timeElapsed;
							size_t imgY = imgSize - y;
							float val;
							if (mModifierRaise)
								val = layer->getBlendValue(x, imgY) + paint;
							else
								val = layer->getBlendValue(x, imgY) - paint;
							val = Math::Clamp(val, 0.0f, 1.0f);
							layer->setBlendValue(x, imgY, val);

						}
					}

					layer->update();
				}
				break;
            case MODE_NORMAL:
            case MODE_COUNT:
                break;
			};
		}
	}
	void loadWorld(const String &name)
	{
		mWorld->loadWorld(name);
	}
	void unloadWorld()
	{
		mWorld->unloadWorld();
	}
	void addWaterPlane(const Vector3 &position, const Real &scaleX, const Real &scaleZ, const String &matName="Terrain/CalmWater", const String &playSound="")
	{
		
	}
	void addObject(const String &meshName, const Vector3 &position, const Vector3 &scale, const Real &pitch, const Real &yaw, const Real &roll, const String &playSound="", const String &matName="")
	{
		
	}
	void addParticle(const String &sysName, const Vector3 &position, const String &playSound="")
	{
		
	}
	void addLight(const Vector3 &position, const ColourValue &colour)
	{
		
	}
	void addBillboard(const Vector3 &position, const Vector2 &scale, const String &matName)
	{
		
	}
	void addStaticGeometry(Entity *ent, const Vector3 &position, const Quaternion &orientation, const Vector3 &scale)
	{
		
	}
	void doInMapEditorLeftclick()
	{

	}
};

#endif
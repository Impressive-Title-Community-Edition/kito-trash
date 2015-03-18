#ifndef __MagixHandler_h_
#define __MagixHandler_h_

enum QueryFlags
{
	OBJECT_MASK = 1<<0,
    UNIT_MASK = 1<<1,
    SKY_MASK = 1<<2,
	WORLDOBJECT_MASK = 1<<3,
	EFFECT_MASK = 1<<4,
	ITEM_MASK = 1<<5,
	CRITTER_MASK = 1<<6,
	AUTOCOLLISION_MASK = 1<<7
};

#include "MagixNetworkDefines.h"
#include "MagixGameStateManager.h"
#include "MagixSoundManager.h"
#include "MagixGUI.h"

using namespace Ogre;

class MagixHandler
{
protected:
	// Regular IT
	SceneManager *mSceneMgr;
	RenderWindow *mWindow;
	MagixGameStateManager *mGameStateManager;
	MagixGUI *mGui;
	MagixSoundManager *mSoundManager;
	String mDebugText;
	bool initialized;

public:
	MagixHandler()
	{
		mSceneMgr = 0;
		mWindow = 0;
		mDebugText = "";
		initialized = false;

		mGameStateManager = new MagixGameStateManager();
		mGui = new MagixGUI();
		mSoundManager = new MagixSoundManager();
	}
	~MagixHandler()
	{
		delete mGui;
		delete mSoundManager;
		delete mGameStateManager;
	}
	void initialize(SceneManager *sceneMgr, RenderWindow *window)
	{
		if(mSceneMgr)return;
		mSceneMgr = sceneMgr;
		mWindow = window;

		mGameStateManager->initialize();
		mSoundManager->initialize();
		mGui->initialize(sceneMgr, window, mGameStateManager, mSoundManager);

		initialized = true;
	}
	void shutdown()
	{
		if(!initialized)return;
	}
	void resetScene(bool startScene=false, const String &mapChange="")
	{
		if(!startScene)mSoundManager->reset();
		mGui->reset();
	}
	bool update(const FrameEvent &evt)
	{
		bool contFlag = true;

		switch(mGameStateManager->getGameState())
		{
			case GAMESTATE_INITIALIZE:
				mSoundManager->playMusic(MUSIC_TITLE);
				mGameStateManager->setGameState(GAMESTATE_STARTSCREEN);
			break;
			case GAMESTATE_STARTSCREEN:
				updateStartScreen(evt);
			break;
			case GAMESTATE_QUIT:
				mGameStateManager->setGameState(mGameStateManager->getTempGameState());
				contFlag = false;
			break;
		}

		return contFlag;
	}
	void updateLogo(const FrameEvent &evt)
	{
		mGui->update(evt);
	}
	void updateStartScreen(const FrameEvent &evt)
	{
		mGui->update(evt);
	}
	String getDebugText()
	{
		return mDebugText;
	}
	MagixGUI* getMagixGUI()
	{
		return mGui;
	}
	MagixInputManager* getInputManager()
	{
		return mGui->getInputManager();
	}
	unsigned short getInputMode()
	{
		return getInputManager()->getInputMode();
	}
	MagixGameStateManager* getGameState()
	{
		return mGameStateManager;
	}
};

#endif
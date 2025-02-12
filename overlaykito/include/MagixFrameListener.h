/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2006 Torus Knot Software Ltd
Also see acknowledgements in Readme.html

You may use this sample code for anything you like, it is not covered by the
LGPL like the rest of the engine.
-----------------------------------------------------------------------------
*/
/*
-----------------------------------------------------------------------------
Filename:    ExampleFrameListener.h
Description: Defines an example frame listener which responds to frame events.
This frame listener just moves a specified camera around based on
keyboard and mouse movements.
Mouse:    Freelook
W or Up:  Forward
S or Down:Backward
A:        Step left
D:        Step right
             PgUp:     Move upwards
             PgDown:   Move downwards
             F:        Toggle frame rate stats on/off
			 R:        Render mode
             T:        Cycle texture filtering
                       Bilinear, Trilinear, Anisotropic(8)
             P:        Toggle on/off display of camera position / orientation
-----------------------------------------------------------------------------
*/

#ifndef __MagixFrameListener_H__
#define __MagixFrameListener_H__

#include "Ogre.h"
#include "OgreStringConverter.h"
#include "OgreException.h"

//Use this define to signify OIS will be used as a DLL
//(so that dll import/export macros are in effect)
#define OIS_DYNAMIC_LIB
#include <OIS.h>

using namespace Ogre;

class MagixFrameListener: public FrameListener, public WindowEventListener
{
protected:
	void updateStats(void)
	{
		static String currFps = "Current FPS: ";
		static String avgFps = "Average FPS: ";
		static String bestFps = "Best FPS: ";
		static String worstFps = "Worst FPS: ";
		static String tris = "Triangle Count: ";
		static String batches = "Batch Count: ";

		// update stats when necessary
		try {
			OverlayElement* guiAvg = OverlayManager::getSingleton().getOverlayElement("Core/AverageFps");
			OverlayElement* guiCurr = OverlayManager::getSingleton().getOverlayElement("Core/CurrFps");
			OverlayElement* guiBest = OverlayManager::getSingleton().getOverlayElement("Core/BestFps");
			OverlayElement* guiWorst = OverlayManager::getSingleton().getOverlayElement("Core/WorstFps");

			const RenderTarget::FrameStats& stats = mWindow->getStatistics();
			guiAvg->setCaption(avgFps + StringConverter::toString(stats.avgFPS));
			guiCurr->setCaption(currFps + StringConverter::toString(stats.lastFPS));
			guiBest->setCaption(bestFps + StringConverter::toString(stats.bestFPS)
				+" "+StringConverter::toString(stats.bestFrameTime)+" ms");
			guiWorst->setCaption(worstFps + StringConverter::toString(stats.worstFPS)
				+" "+StringConverter::toString(stats.worstFrameTime)+" ms");

			OverlayElement* guiTris = OverlayManager::getSingleton().getOverlayElement("Core/NumTris");
			guiTris->setCaption(tris + StringConverter::toString(stats.triangleCount));

			OverlayElement* guiBatches = OverlayManager::getSingleton().getOverlayElement("Core/NumBatches");
			guiBatches->setCaption(batches + StringConverter::toString(stats.batchCount));

			OverlayElement* guiDbg = OverlayManager::getSingleton().getOverlayElement("Core/DebugText");
			guiDbg->setCaption(mDebugText);
		}
		catch(...) { /* ignore */ }
	}

public:
	// Constructor takes a RenderWindow because it uses that to determine input context
	MagixFrameListener(MagixHandler *magixHandler, RenderWindow* win, Camera* cam, bool bufferedKeys = true, bool bufferedMouse = true) :
		mMagixHandler(magixHandler), /*mCamera(cam), mTranslateVector(Vector3::ZERO),*/ mWindow(win), isStatsOn(false), /*mNumScreenShots(0),
		mMoveScale(0.0f), mRotScale(0.0f), mTimeUntilNextToggle(0), mFiltering(TFO_BILINEAR),
		mAniso(1), mSceneDetailIndex(0), mMoveSpeed(100), mRotateSpeed(36),*/ mDebugOverlay(0),
		mInputManager(0), mMouse(0), mKeyboard(0)
	{
		using namespace OIS;

		mDebugOverlay = OverlayManager::getSingleton().getByName("Core/DebugOverlay");

		LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
		ParamList pl;
		size_t windowHnd = 0;
		std::ostringstream windowHndStr;

		win->getCustomAttribute("WINDOW", &windowHnd);
		windowHndStr << windowHnd;
		pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

		bool useWindowsCursor = false;
		std::ifstream inFile("useWindowsCursor.dat");
		if(inFile.good())useWindowsCursor = true;
		inFile.close();

		if(useWindowsCursor)
		{
			#if defined OIS_WIN32_PLATFORM
			pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
			pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
			//pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
			//pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
			#elif defined OIS_LINUX_PLATFORM
			pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
			pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
			//pl.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
			//pl.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
			#endif
			if(ShowCursor(false)<-1)ShowCursor(true);
		}

		mInputManager = InputManager::createInputSystem( pl );

		//Create all devices (We only catch joystick exceptions here, as, most people have Key/Mouse)
		mKeyboard = static_cast<Keyboard*>(mInputManager->createInputObject( OISKeyboard, bufferedKeys ));
		mMouse = static_cast<Mouse*>(mInputManager->createInputObject( OISMouse, bufferedMouse ));

		//Set initial mouse clipping size
		windowResized(mWindow);

		showDebugOverlay(false);

		//Register as a Window listener
		WindowEventUtilities::addWindowEventListener(mWindow, this);
	}

	//Adjust mouse clipping area
	virtual void windowResized(RenderWindow* rw)
	{
		unsigned int width, height, depth;
		int left, top;
		rw->getMetrics(width, height, depth, left, top);

		const OIS::MouseState &ms = mMouse->getMouseState();
		ms.width = width;
		ms.height = height;
	}

	//Unattach OIS before window shutdown (very important under Linux)
	virtual void windowClosed(RenderWindow* rw)
	{
		//Only close for window that created OIS (the main window in these demos)
		if( rw == mWindow )
		{
			if( mInputManager )
			{
				mInputManager->destroyInputObject( mMouse );
				mInputManager->destroyInputObject( mKeyboard );

				OIS::InputManager::destroyInputSystem(mInputManager);
				mInputManager = 0;
			}
		}
	}

	virtual ~MagixFrameListener()
	{
		//Remove ourself as a Window listener
		WindowEventUtilities::removeWindowEventListener(mWindow, this);
		windowClosed(mWindow);
	}

	void showDebugOverlay(bool show)
	{
		if (mDebugOverlay)
		{
			if (show)
			{
				mDebugOverlay->show();
				isStatsOn = true;
			}
			else
			{
				mDebugOverlay->hide();
				isStatsOn = false;
			}
		}
	}

	// Override frameStarted event to process that (don't care about frameEnded)
	bool frameStarted(const FrameEvent& evt)
	{
		using namespace OIS;

		if(mWindow->isClosed())	return false;

		mContinue = true;
		if(mMagixHandler->getDebugText()!="")mDebugText = mMagixHandler->getDebugText();

		//Need to capture/update each device
		mKeyboard->capture();
		mMouse->capture();

		return mContinue;
	}

	bool frameEnded(const FrameEvent& evt)
	{
		if(mDebugOverlay->isVisible())updateStats();
		return true;
	}



protected:
	//Camera* mCamera;

	//Vector3 mTranslateVector;
	RenderWindow* mWindow;
	bool isStatsOn;

	std::string mDebugText;

	//unsigned int mNumScreenShots;
	//float mMoveScale;
	//Degree mRotScale;
	// just to stop toggles flipping too fast
	//Real mTimeUntilNextToggle ;
	//Radian mRotX, mRotY;
	//TextureFilterOptions mFiltering;
	//int mAniso;

	//int mSceneDetailIndex ;
	//Real mMoveSpeed;
	//Degree mRotateSpeed;
	Overlay* mDebugOverlay;

	//OIS Input devices
	OIS::InputManager* mInputManager;
	OIS::Mouse*    mMouse;
	OIS::Keyboard* mKeyboard;

	MagixHandler *mMagixHandler;
	bool mContinue;
};

#endif

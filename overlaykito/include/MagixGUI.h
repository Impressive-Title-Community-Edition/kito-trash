#ifndef __MagixGUI_h_
#define __MagixGUI_h_

#define MAX_BOXES 30
#define MAX_BUTTONS 89
#define MAX_SIZERS 1
#define MAX_MOVERS 8
#define MAX_SCROLLERS 14
#define MAX_CHECKBOXES 1
#define MAX_CHARSCREENTEXT 4
#define MAX_CREATEACCOUNTINFO 6
#define MAX_EDITACCOUNTINFO 4


#include "MagixInputManager.h"
#include "MagixGameStateManager.h"
#include "MagixSoundManager.h"

#ifndef ISKITO
#define ISKITO false
#endif

#define SIZEDIR_TOP 1
#define SIZEDIR_BOTTOM 2
#define SIZEDIR_LEFT 3
#define SIZEDIR_RIGHT 4

enum GUIBOX
{
	GUI_OPTIONS,
	GUI_SETTINGS,
	GUI_INTERFACE,
	GUI_LISTSELECTBOX,
	GUI_SELECTBOX,
	GUI_TEXTINPUT,
	GUI_TEXTOUTPUT,
	GUI_STARTSCREENBOX,
	GUI_CHARSCREENBOX,
	GUI_CAMPAIGNBOX, // 10
	GUI_SERVERBOX,
	GUI_MULTIPLAYER,
	GUI_FRIENDBOX,
	GUI_BIOBOX,
	GUI_TARGETBIOBOX,
	GUI_HOMEBOX,
	GUI_EMOTEBOX,
	GUI_ITEMBOX,
	GUI_LOGONBOX,
	GUI_CREATEACCOUNTBOX, // 20
	GUI_EDITACCOUNTBOX,
	GUI_PARTYBOX,
	GUI_STASHBOX,
	GUI_TOOLSSCREENBOX,
	GUI_WORLDEDITORBOX,
	GUI_WORLDEDITORBOXPANEL1,
	GUI_WORLDEDITORBOXPANEL2,
	GUI_WORLDEDITORBOXPANEL3,
	GUI_WORLDEDITORBOXPANEL4,
	GUI_WORLDEDITORBOXPANEL5 //30
};

enum BUTTON
{
 BUTTON_TEXTINPUT,
 BUTTON_TEXTINPUT2,
 BUTTON_TEXTINPUT3,
 BUTTON_TEXTOUTPUT,
 BUTTON_LISTSELECT1,
 BUTTON_LISTSELECT2,
 BUTTON_LISTSELECT3,
 BUTTON_SELECTBOX1,
 BUTTON_SELECTBOX2,
 BUTTON_SELECTBOX3, //10
 BUTTON_SELECTBOX4,
 BUTTON_NEWGAME,
 BUTTON_MULTIPLAYER,
 BUTTON_QUIT,
 BUTTON_CHARSCREEN_L1,
 BUTTON_CHARSCREEN_R1,
 BUTTON_CHARSCREEN_L2,
 BUTTON_CHARSCREEN_R2,
 BUTTON_CHARSCREEN_L3,
 BUTTON_CHARSCREEN_R3,//20
 BUTTON_CHARSCREEN_L4,
 BUTTON_CHARSCREEN_R4,
 BUTTON_CHARSCREENBACK,
 BUTTON_CHARSCREENNEXT,
 BUTTON_CHARSCREENDELETE,
 BUTTON_OPTIONRESUME,
 BUTTON_OPTIONSETTINGS,
 BUTTON_OPTIONINTERFACE,
 BUTTON_OPTIONRESTART,
 BUTTON_OPTIONQUIT,//30
 BUTTON_SETTINGS1,
 BUTTON_SETTINGS2,
 BUTTON_SETTINGS3,
 BUTTON_SETTINGSBACK,
 BUTTON_INTERFACE1,
 BUTTON_INTERFACE2,
 BUTTON_INTERFACE3,
 BUTTON_INTERFACE4,
 BUTTON_INTERFACE5,
 BUTTON_INTERFACE6,//40
 BUTTON_INTERFACE7,
 BUTTON_INTERFACE8,
 BUTTON_INTERFACEBACK,
 BUTTON_CAMPAIGNBACK,
 BUTTON_CAMPAIGNNEXT,
 BUTTON_CAMPAIGN1,
 BUTTON_CAMPAIGN2,
 BUTTON_CAMPAIGN3,
 BUTTON_GAMEOVERCONTINUE,
 BUTTON_GAMEOVERQUIT,//50
 BUTTON_SERVER1,
 BUTTON_SERVER2,
 BUTTON_MINIMAP1,
 BUTTON_MINIMAP2,
 BUTTON_MULTIPLAYER1,
 BUTTON_MULTIPLAYER2,
 BUTTON_MULTIPLAYER3,
 BUTTON_MULTIPLAYER4,
 BUTTON_MULTIPLAYER5,
 BUTTON_MULTIPLAYER6,//60
 BUTTON_FRIENDBOX,
 BUTTON_BIOBOX,
 BUTTON_TARGETBIOBOX,
 BUTTON_HOMEBOX,
 BUTTON_HOMEBOX1,
 BUTTON_HOMEBOX2,
 BUTTON_HOMEBOX3,
 BUTTON_HOMEBOX4,
 BUTTON_EMOTEBOX,
 BUTTON_ITEMBOX,//70
 BUTTON_ITEMBOX1,
 BUTTON_LOGON1,
 BUTTON_NEWACCOUNT,
 BUTTON_EDITACCOUNT,
 BUTTON_LOGONBACK,
 BUTTON_CREATEACCOUNT1,
 BUTTON_CREATEACCOUNTBACK,
 BUTTON_EDITACCOUNT1,
 BUTTON_EDITACCOUNTBACK,
 BUTTON_PARTYBOX,//80
 BUTTON_PARTYBOX1,
 BUTTON_PARTYBOX2,
 BUTTON_PARTYBOX3,
 BUTTON_STASHBOX,
 BUTTON_TOOLS,
 BUTTON_WORLDEDITOR,
 BUTTON_SKYEDITOR,
 BUTTON_TOOLSBACK,
 BUTTON_WORLDEDITORSCREEN //89
};

#define SIZER_TEXTOUTPUT 0

enum MOVER
{
 MOVER_FRIENDBOX,
 MOVER_BIOBOX,
 MOVER_TARGETBIOBOX,
 MOVER_HOMEBOX,
 MOVER_EMOTEBOX,
 MOVER_ITEMBOX,
 MOVER_PARTYBOX,
 MOVER_STASHBOX
};

enum SCROLLER
{
 SCROLLER_TEXTOUTPUT,
 SCROLLER_CHARSCREEN1,
 SCROLLER_CHARSCREEN2,
 SCROLLER_CHARSCREEN3,
 SCROLLER_SETTINGS1,
 SCROLLER_SETTINGS2,
 SCROLLER_SETTINGS3,
 SCROLLER_SETTINGS4,
 SCROLLER_INTERFACE1,
 SCROLLER_FRIENDBOX,
 SCROLLER_BIOBOX,
 SCROLLER_TARGETBIOBOX,
 SCROLLER_EMOTEBOX,
 SCROLLER_STASHBOX
};

enum CHECKBOX
{
 CHECKBOX_LOGON
};

enum LISTBUTTON
{
 LISTBUTTON_NONE,
 LISTBUTTON_ONLINEFRIEND,
 LISTBUTTON_OFFLINEFRIEND,
 LISTBUTTON_BLOCKED,
 LISTBUTTON_EMOTE
};

enum GUITYPE
{
	GUITYPE_NONE,
	GUITYPE_BUTTON,
	GUITYPE_SIZER,
	GUITYPE_MOVER,
	GUITYPE_SCROLLER,
	GUITYPE_CHECKBOX
};

using namespace Ogre;

class MagixGUI
{
protected:
	SceneManager *mSceneMgr;
	RenderWindow *mWindow;
	MagixGameStateManager *mGameStateManager;
	MagixInputManager *mInputManager;
	MagixSoundManager *mSoundManager;

	OverlayElement *mFader;
	OverlayElement *mCursor;
	OverlayElement *mBackdrop;
	OverlayElement *mListSelectHighlight;

	OverlayElement *mBox[MAX_BOXES];
	OverlayElement *mBoxText[MAX_BOXES];
	OverlayElement *mButton[MAX_BUTTONS];
	OverlayElement *mButtonText[MAX_BUTTONS];
	OverlayElement *mSizer[MAX_SIZERS];
	OverlayElement *mMover[MAX_MOVERS];
	OverlayElement *mScroller[MAX_SCROLLERS];
	OverlayElement *mScrollerMarker[MAX_SCROLLERS];
	bool isScrollerHorz[MAX_SCROLLERS];
	OverlayElement *mCharScreenText[MAX_CHARSCREENTEXT];
	OverlayElement *mCheckBox[MAX_CHECKBOXES];

	OverlayElement *mHoverButton;
	unsigned char hoverButtonType;
	OverlayElement *mHoverWindow;
	OverlayElement *mHeldButtonWindow;
	OverlayElement *mMoverWindow;
	OverlayElement *mListSelectTarget;
	OverlayElement *mCurrentWindow;
	String mDebugText;
	Real cursorX;
	Real cursorY;
	bool leftClick;
	bool rightClick;
	RaySceneQuery *mRayQuery;
	SceneNode *mCurrentObject;
	unsigned short sizeWindowDir;
	Real dragStartX;
	Real dragStartY;
	Real sizeWindowWidth;
	Real sizeWindowHeight;
	Real sizeWindowLeft;
	Real sizeWindowTop;
	Real sizeWindowMinWidth;
	Real sizeWindowMinHeight;
	short scrollerHeldID;
	Real logoCount;
	
	bool isTabletFlag;
	Real mouseSensitivity;
	bool isGUIVisible;
	bool doChannelBlink;
	bool wasGUIVisible;
	bool useWindowsCursor;

	Real faderTimeout;
	Real faderTimeoutMax;
	ColourValue faderColour;
	Real cinematicBarsTimeout;
	Real cinematicCaptionTimeout;
	Real pickupTextTimeout;
	Real buttonBlinkTimeout;
	Real selectPanelTimeout;

	BillboardSet *mTargetIndicator;
	SceneNode *mTargetIndicatorNode;

	String commandLine;
	String commandLineParam;
	String listButtonData;
	unsigned short listButtonType;
	unsigned short listButtonLine;

	bool isCreateAccount;
	bool isEditAccount;
	String logonUsername;
	String logonPassword;
	OverlayElement *mCreateAccountTextBox[MAX_CREATEACCOUNTINFO];
	String createAccountInfo[MAX_CREATEACCOUNTINFO];
	OverlayElement *mEditAccountTextBox[MAX_EDITACCOUNTINFO];
	String editAccountInfo[MAX_EDITACCOUNTINFO];

	int mOldPanel;

public:
	MagixGUI()
	{
		mSceneMgr = 0;
		mWindow = 0;
		mGameStateManager = 0;
		mSoundManager = 0;
		mFader = 0;
		mCursor = 0;
		mBackdrop = 0;
		mInputManager = new MagixInputManager();
		for(int i=0;i<MAX_BOXES;i++)
		{
			mBox[i] = 0;
			mBoxText[i] = 0;
		}
		for(int i=0;i<MAX_BUTTONS;i++)
		{
			mButton[i] = 0;
			mButtonText[i] = 0;
		}
		for(int i=0;i<MAX_SIZERS;i++)mSizer[i] = 0;
		for(int i=0;i<MAX_MOVERS;i++)mMover[i] = 0;
		for(int i=0;i<MAX_SCROLLERS;i++)
		{
			mScroller[i] = 0;
			mScrollerMarker[i] = 0;
			isScrollerHorz[i] = false;
		}
		for(int i=0;i<MAX_CHARSCREENTEXT;i++)mCharScreenText[i] = 0;
		for(int i=0;i<MAX_CHECKBOXES;i++)mCheckBox[i] = 0;
		mHoverButton = 0;
		hoverButtonType = GUITYPE_NONE;
		mHoverWindow = 0;
		mHeldButtonWindow = 0;
		mMoverWindow = 0;
		mListSelectTarget = 0;
		mCurrentWindow = 0;

		mDebugText = "";
		cursorX = 0;
		cursorY = 0;
		leftClick = false;
		mRayQuery = 0;
		mCurrentObject = 0;
		sizeWindowDir = 0;
		dragStartX = 0;
		dragStartY = 0;
		sizeWindowWidth = 0;
		sizeWindowHeight = 0;
		sizeWindowLeft = 0;
		sizeWindowTop = 0;
		sizeWindowMinWidth = 0;
		sizeWindowMinHeight = 0;
		scrollerHeldID = -1;
		logoCount = 0;
		
		isTabletFlag = false;
		mouseSensitivity = 0.5;
		isGUIVisible = true;
		wasGUIVisible = false;
		useWindowsCursor = false;

		faderTimeout = 0;
		faderTimeoutMax = 0;
		faderColour = ColourValue(0,0,0);
		cinematicBarsTimeout = 0;
		cinematicCaptionTimeout = 0;
		pickupTextTimeout = 0;
		buttonBlinkTimeout = 0;
		selectPanelTimeout = 0;

		mTargetIndicator = 0;
		mTargetIndicatorNode = 0;

		commandLine = "";
		commandLineParam = "";
		listButtonData = "";
		listButtonType = 0;
		listButtonLine = 0;
		mListSelectTarget = 0;

		mOldPanel = 0;
	}
	~MagixGUI()
	{
		delete mInputManager;
	}//                           sceneMgr,               window,                          mDef,                   mGameStateManager,                  mItemManager,                 mCritterManager,                  mUnitManager,                     mNetworkManager,             mCamera,               mSoundManager,                 mEffectsManager,                   mCollisionManager,            mWorld
	void initialize(SceneManager *sceneMgr, RenderWindow *window, MagixGameStateManager *gameStateMgr, MagixSoundManager *soundMgr)
	{
		mSceneMgr = sceneMgr;
		mWindow = window;
		mGameStateManager = gameStateMgr;
		mSoundManager = soundMgr;

		//Cursor
		mCursor = OverlayManager::getSingleton().getOverlayElement("GUI/Cursor");
		mCursor->setPosition(400,300);
		cursorX = 0.5;
		cursorY = 0.5;

		showCursorOverlay(false);

		//StartScreenGUI
		mBox[GUI_STARTSCREENBOX] = OverlayManager::getSingleton().getOverlayElement("GUI/StartScreenBox");

		showStartScreenOverlay(false);

		//Fader
		mFader = OverlayManager::getSingleton().getOverlayElement("GUI/Fader");
		fadeOut(0);
		showFaderOverlay(false);

		//Backdrop
		mBackdrop = OverlayManager::getSingleton().getOverlayElement("GUI/Backdrop");
		OverlayManager::getSingleton().getOverlayElement("GUI/CinematicCaption")->hide();

		showBackdropOverlay(true,false);

		//WorldEditorGUI
		mBox[GUI_WORLDEDITORBOX] = OverlayManager::getSingleton().getOverlayElement("WorldEditorScreen/MultiPanel");
		mBox[GUI_WORLDEDITORBOXPANEL1] = OverlayManager::getSingleton().getOverlayElement("WorldEditorScreen/Page1Panel");
		mBox[GUI_WORLDEDITORBOXPANEL2] = OverlayManager::getSingleton().getOverlayElement("WorldEditorScreen/Page2Panel");
		mBox[GUI_WORLDEDITORBOXPANEL3] = OverlayManager::getSingleton().getOverlayElement("WorldEditorScreen/Page3Panel");
		mBox[GUI_WORLDEDITORBOXPANEL4] = OverlayManager::getSingleton().getOverlayElement("WorldEditorScreen/Page4Panel");
		mBox[GUI_WORLDEDITORBOXPANEL5] = OverlayManager::getSingleton().getOverlayElement("WorldEditorScreen/Page5Panel");

		showWorldEditorOverlay(false);
		showWorldEditorPanel(0);
	}
	void showCursorOverlay(bool flag)
	{
		if(flag)
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/Cursor")->show();
			//mCursor->show();
		}
		else
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/Cursor")->hide();
			mCursor->hide();
		}
	}
	void showBackdropOverlay(bool flag, bool showLoadingText=false, const String &loadingCaption="Loading...")
	{
		if(flag)
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/Backdrop")->show();
			mBackdrop->show();
			if(showLoadingText)
			{
				OverlayManager::getSingleton().getOverlayElement("GUI/LoadingText")->show();
				OverlayManager::getSingleton().getOverlayElement("GUI/LoadingText")->setCaption(loadingCaption);
			}
			else
				OverlayManager::getSingleton().getOverlayElement("GUI/LoadingText")->hide();
		}
		else 
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/Backdrop")->hide();
			mBackdrop->hide();
			OverlayManager::getSingleton().getOverlayElement("GUI/LoadingText")->hide();
		}
	}
	void toggleWorldEditorOverlay()
	{
		showWorldEditorOverlay(!mBox[GUI_WORLDEDITORBOX]->isVisible());
	}
	void fadeOut(const Real &duration, const ColourValue &colour=ColourValue(0,0,0))
	{
		if(duration==0)
		{
			if(!mFader->isVisible())showFaderOverlay(true);
			mFader->setCustomParameter(1,Vector4(colour.r,colour.g,colour.b,1));
			#pragma warning(push)
			#pragma warning(disable : 4482)
			if(mFader->getTechnique()->getName()=="2")
			{
				mFader->getTechnique()->getPass(0)->getTextureUnitState(0)->setColourOperationEx(LayerBlendOperationEx::LBX_SOURCE1,
																									LayerBlendSource::LBS_MANUAL,
																									LayerBlendSource::LBS_CURRENT,
																									ColourValue(colour.r,colour.g,colour.b));
				mFader->getTechnique()->getPass(0)->getTextureUnitState(0)->setAlphaOperation(LayerBlendOperationEx::LBX_SOURCE1,
																								LayerBlendSource::LBS_MANUAL,
																								LayerBlendSource::LBS_CURRENT,
																								1);
			}
			#pragma warning(pop)
			faderTimeout = 0;
		}
		else
		{
			faderTimeout = -duration;
			faderTimeoutMax = duration;
			faderColour = colour;
		}
	}
	void showWorldEditorOverlay(bool flag)
	{
		if(flag)
		{ // GUIOverlay/WorldEditorScreen
			OverlayManager::getSingleton().getByName("GUIOverlay/WorldEditorScreen")->show();
			mBox[GUI_WORLDEDITORBOX]->show();
			mBox[GUI_WORLDEDITORBOXPANEL1]->show();
			mBox[GUI_WORLDEDITORBOXPANEL2]->show();
			mBox[GUI_WORLDEDITORBOXPANEL3]->show();
			mBox[GUI_WORLDEDITORBOXPANEL4]->show();
			mBox[GUI_WORLDEDITORBOXPANEL5]->show();
		}
		else
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/WorldEditorScreen")->hide();
			mBox[GUI_WORLDEDITORBOX]->hide();
			mBox[GUI_WORLDEDITORBOXPANEL1]->hide();
			mBox[GUI_WORLDEDITORBOXPANEL2]->hide();
			mBox[GUI_WORLDEDITORBOXPANEL3]->hide();
			mBox[GUI_WORLDEDITORBOXPANEL4]->hide();
			mBox[GUI_WORLDEDITORBOXPANEL5]->hide();
			showWorldEditorPanel(0);
		}
	}
	void showWorldEditorPanel(int panel)
	{
		if(mOldPanel == panel && panel != 0)
			return;
		switch(mOldPanel)
		{
		case 1:
			{
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL1])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->hide();
				}
			}
			break;
		case 2:
			{
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL2])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->hide();
				}
			}
			break;
		case 3:
			{
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL3])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->hide();
				}
			}
			break;
		case 4:
			{
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL4])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->hide();
				}
			}
			break;
		case 5:
			{
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL5])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->hide();
				}
			}
			break;
		default:
			break;
		}
		mOldPanel = panel;
		switch(panel)
		{
		case 1:
			{
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL1])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->show();
				}
			}
			break;
		case 2:
			{
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL2])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->show();
				}
			}
			break;
		case 3:
			{
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL3])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->show();
				}
			}
			break;
		case 4:
			{
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL4])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->show();
				}
			}
			break;
		case 5:
			{
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL5])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->show();
				}
			}
			break;
		default:
			{
				mBox[GUI_WORLDEDITORBOXPANEL1]->hide();
				mBox[GUI_WORLDEDITORBOXPANEL2]->hide();
				mBox[GUI_WORLDEDITORBOXPANEL3]->hide();
				mBox[GUI_WORLDEDITORBOXPANEL4]->hide();
				mBox[GUI_WORLDEDITORBOXPANEL5]->hide();
				// Hide children
				OverlayContainer::ChildIterator it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL1])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->hide();
				}
				it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL2])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->hide();
				}
				it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL3])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->hide();
				}
				it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL4])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->hide();
				}
				it = static_cast<OverlayContainer*>(mBox[GUI_WORLDEDITORBOXPANEL5])->getChildIterator();
				while (it.hasMoreElements())
				{
					it.getNext()->hide();
				}
			}
			break;
		}
	}
	void scrollMouse(int x, int y, int winWidth, int winHeight, bool setPosition=false)
	{
		if(setPosition)mCursor->setPosition((Ogre::Real)x,(Ogre::Real)y);
		else mCursor->setPosition(mCursor->getLeft()+x,mCursor->getTop()+y);
		
		mCursor->setPosition( (mCursor->getLeft()<0 ? 0 : (mCursor->getLeft()>winWidth ? winWidth : mCursor->getLeft())),
								(mCursor->getTop()<0 ? 0 : (mCursor->getTop()>winHeight ? winHeight : mCursor->getTop())) );

		cursorX = mCursor->getLeft()/winWidth;
		cursorY = mCursor->getTop()/winHeight;

		//Sizer buttons
		if(sizeWindowDir && mHoverButton)
		{
			const Real dX = cursorX - dragStartX;
			const Real dY = cursorY - dragStartY;
			const Real tWidth = mHoverButton->getParent()->getWidth();
			const Real tHeight = mHoverButton->getParent()->getHeight();

			switch(sizeWindowDir)
			{
				case SIZEDIR_TOP:
					mHoverButton->getParent()->setHeight(sizeWindowHeight - dY);
					mHoverButton->getParent()->setTop(sizeWindowTop + dY);
				break;
				case SIZEDIR_BOTTOM:
					mHoverButton->getParent()->setHeight(sizeWindowHeight + dY);
				break;
				case SIZEDIR_LEFT:
					mHoverButton->getParent()->setWidth(sizeWindowWidth - dY);
					mHoverButton->getParent()->setLeft(sizeWindowLeft + dY);
				break;
				case SIZEDIR_RIGHT:
					mHoverButton->getParent()->setWidth(sizeWindowWidth + dY);
				break;
			}

			if(sizeWindowMinWidth!=0 && mHoverButton->getParent()->getWidth()<sizeWindowMinWidth)
			{
				if(SIZEDIR_LEFT)mHoverButton->getParent()->setLeft(mHoverButton->getParent()->getLeft()+(mHoverButton->getParent()->getWidth()-sizeWindowMinWidth));
				mHoverButton->getParent()->setWidth(sizeWindowMinWidth);
			}
			if(sizeWindowMinHeight!=0 && mHoverButton->getParent()->getHeight()<sizeWindowMinHeight)
			{
				if(SIZEDIR_TOP)mHoverButton->getParent()->setTop(mHoverButton->getParent()->getTop()+(mHoverButton->getParent()->getHeight()-sizeWindowMinHeight));
				mHoverButton->getParent()->setHeight(sizeWindowMinHeight);
			}

			//Update scrollbars
			resizeScrollbarByParent(mHoverButton->getParent(),tWidth,tHeight);
		}
		//Movers
		if(mMoverWindow)
		{
			mMoverWindow->setPosition(cursorX-dragStartX,cursorY-dragStartY);
		}
		//Scrollers
		if(scrollerHeldID != -1)
		{
			doScroll(true,scrollerHeldID);

			//Scroller actions
			if(scrollerHeldID==SCROLLER_CHARSCREEN1||scrollerHeldID==SCROLLER_CHARSCREEN2||scrollerHeldID==SCROLLER_CHARSCREEN3)	//charscreen sliders
			{
			}
			else if(scrollerHeldID==SCROLLER_SETTINGS1)	//music volume
			{
			}
			else if(scrollerHeldID==SCROLLER_SETTINGS2)	//guisound volume
			{
			}
			else if(scrollerHeldID==SCROLLER_SETTINGS3)	//sound volume
			{
			}
			else if(scrollerHeldID==SCROLLER_SETTINGS4)	//view distance
			{
			}
		}
	}
	bool isTablet()
	{
		return isTabletFlag;
	}
	void showMouse(bool flag)
	{
		if(flag)
		{
			if(!mCursor->isVisible())mCursor->show();
		}
		else 
		{
			if(mCursor->isVisible())mCursor->hide();
		}
	}
	const Real getMouseX()
	{
		return cursorX;
	}
	const Real getMouseY()
	{
		return cursorY;
	}
	void reset()
	{
		showMouse(true);
		isGUIVisible = true;
	}
	void showStartScreenOverlay(bool flag)
	{
		if(flag)
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/StartScreen")->show();
			mBox[GUI_STARTSCREENBOX]->show();
		}
		else
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/StartScreen")->hide();
			mBox[GUI_STARTSCREENBOX]->hide();
		}
	}
	void showFaderOverlay(bool flag)
	{
		if(flag)
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/Fader")->show();
			mFader->show();
		}
		else
		{
			OverlayManager::getSingleton().getByName("GUIOverlay/Fader")->hide();
			mFader->hide();
		}
	}
	void update(const FrameEvent &evt)
	{
		showFaderOverlay(false);
		showStartScreenOverlay(true);
		showCursorOverlay(true);
		mCursor->show();
		updateHover();
		mInputManager->update(evt);
//		updateFader(evt);
//		updateCompositors();

	}
	void updateHover()
	{
		if(mHoverWindow)
			if(!mHoverWindow->isVisible())mHoverWindow = 0;
		if(!mHoverWindow)
		{
			for(int i=0;i<MAX_BOXES;i++)
			{
				if(mBox[i])
				if(isCursorOverWindow(mBox[i]))
				{
					mHoverWindow = mBox[i];
					break;
				}
				else if(mBox[i]==mHoverWindow)mHoverWindow = 0;
			}
		}
		//Priority boxes
		else
		{
			if(isCursorOverWindow(mBox[GUI_OPTIONS]))mHoverWindow = mBox[GUI_OPTIONS];
			else if(isCursorOverWindow(mBox[GUI_SETTINGS]))mHoverWindow = mBox[GUI_SETTINGS];
			else if(isCursorOverWindow(mBox[GUI_INTERFACE]))mHoverWindow = mBox[GUI_INTERFACE];
		}
		for(int i=0;i<MAX_BUTTONS;i++)
		{
			if(mButton[i])
			if(isCursorOverButton(mButton[i]) && (mButton[i]->getParent()==mHoverWindow||!mHoverWindow))
			{
				//special "hold to click" buttons
				if(mHoverButton!=mButton[i] && leftClick && mButton[i]->getParent()==mHeldButtonWindow)
				{
					mHoverButton = mButton[i];
					mSoundManager->playGUISound(SOUND_CLICK);
					hoverButtonType = GUITYPE_BUTTON;
				}
				//Hover
				else if(!mHoverButton)
				{
					mButton[i]->setMaterialName("GUIMat/ButtonOver");
					//not held before hovering
					if(!leftClick)
					{
						mHoverButton = mButton[i];
						hoverButtonType = GUITYPE_BUTTON;
					}
				}
				//for cases where: hovered, held, unhovered, hovered again
				else if(mHoverButton==mButton[i] && leftClick)
				{
					mButton[i]->setMaterialName("GUIMat/ButtonDown");
				}
			}
			else 
			{
				//Unhover
				if(mButton[i]->getMaterialName()!="GUIMat/ButtonUp" && mButton[i]->getMaterialName()!="GUIMat/ButtonHighlight")mButton[i]->setMaterialName("GUIMat/ButtonUp");
				//unhovered and not held
				if(mHoverButton==mButton[i] && !leftClick)mHoverButton = 0;
				//special "hold to click" buttons
				if(mButton[i]==mHoverButton && mButton[i]->getParent()==mHeldButtonWindow)mHoverButton = 0;
			}
		}
		for(int i=0;i<MAX_SIZERS;i++)
		{
			if(mSizer[i])
			if(isCursorOverButton(mSizer[i]) && (mSizer[i]->getParent()==mHoverWindow||!mHoverWindow))
			{
				//Hover
				if(!mHoverButton)
				{
					mSizer[i]->setMaterialName("GUIMat/ButtonOver");
					//not held before hovering
					if(!leftClick)
					{
						mHoverButton = mSizer[i];
						hoverButtonType = GUITYPE_SIZER;
					}
				}
				//for cases where: hovered, held, unhovered, hovered again
				else if(mHoverButton==mSizer[i] && leftClick)
				{
					mSizer[i]->setMaterialName("GUIMat/ButtonDown");
				}
			}
			else 
			{
				//Unhover
				if(mSizer[i]->getMaterialName()!="GUIMat/ButtonUp")mSizer[i]->setMaterialName("GUIMat/ButtonUp");
				//unhovered and not held
				if(mHoverButton==mSizer[i] && !leftClick)mHoverButton = 0;
			}
		}
		for(int i=0;i<MAX_MOVERS;i++)
		{
			if(mMover[i])
			if(isCursorOverButton(mMover[i]) && (!mHoverWindow||mHoverWindow->getZOrder()<=mMover[i]->getZOrder()))
			{
				//Hover
				if(!mHoverButton)
				{
					mMover[i]->setMaterialName("GUIMat/ButtonOver");
					//not held before hovering
					if(!leftClick)
					{
						mHoverButton = mMover[i];
						hoverButtonType = GUITYPE_MOVER;
					}
				}
				//for cases where: hovered, held, unhovered, hovered again
				else if(mHoverButton==mMover[i] && leftClick)
				{
					mMover[i]->setMaterialName("GUIMat/ButtonDown");
				}
			}
			else 
			{
				//Unhover
				if(mMover[i]->getMaterialName()!="GUIMat/ButtonUp")mMover[i]->setMaterialName("GUIMat/ButtonUp");
				//unhovered and not held
				if(mHoverButton==mMover[i] && !leftClick)mHoverButton = 0;
			}
		}
		for(int i=0;i<MAX_SCROLLERS;i++)
		{
			if(mScroller[i])
			if((isCursorOverButton(mScroller[i])||isCursorOverButton(mScrollerMarker[i])) && (mScrollerMarker[i]->getParent()==mHoverWindow||!mHoverWindow))
			{
				//Hover
				if(!mHoverButton)
				{
					mScrollerMarker[i]->setMaterialName("GUIMat/ButtonOver");
					//not held before hovering
					if(!leftClick)
					{
						mHoverButton = mScrollerMarker[i];
						hoverButtonType = GUITYPE_SCROLLER;
					}
				}
				//for cases where: hovered, held, unhovered, hovered again
				else if(mHoverButton==mScrollerMarker[i] && leftClick)
				{
					mScrollerMarker[i]->setMaterialName("GUIMat/ButtonDown");
				}
			}
			else 
			{
				//Unhover
				if(mScrollerMarker[i]->getMaterialName()!="GUIMat/ButtonUp" && !leftClick)mScrollerMarker[i]->setMaterialName("GUIMat/ButtonUp");
				//unhovered and not held
				if(mHoverButton==mScrollerMarker[i] && !leftClick)mHoverButton = 0;
			}
		}
		for(int i=0;i<MAX_CHECKBOXES;i++)
		{
			if(mCheckBox[i])
			if(isCursorOverButton(mCheckBox[i]) && (mCheckBox[i]->getParent()==mHoverWindow||!mHoverWindow))
			{
				//Hover
				if(!mHoverButton)
				{
					//not held before hovering
					if(!leftClick)
					{
						mHoverButton = mCheckBox[i];
						hoverButtonType = GUITYPE_CHECKBOX;
					}
				}
			}
			else 
			{
				//unhovered and not held
				if(mHoverButton==mCheckBox[i] && !leftClick)mHoverButton = 0;
			}
		}
	}
	bool isCursorOverButton(OverlayElement *button, bool ignoreParent=false)
	{
		if(!button)return false;
		if(!mCursor->isVisible())return false;
		if(!button->isVisible())return false;

		if(ignoreParent)
		{
			return (cursorX >= button->getLeft() && cursorX <= button->getLeft()+button->getWidth()
				&& cursorY >= button->getTop() && cursorY <= button->getTop()+button->getHeight() );
		}

		if(!button->getParent())return false;
		if(!button->getParent()->isVisible())return false;
		return (cursorX >= (button->getLeft()+button->getParent()->getLeft()) && cursorX <= (button->getLeft()+button->getWidth()+button->getParent()->getLeft())
				&& cursorY >= (button->getTop()+button->getParent()->getTop()) && cursorY <= (button->getTop()+button->getHeight()+button->getParent()->getTop()) );
	}
	bool isCursorOverWindow(OverlayElement *window)
	{
		if(!window)return false;
		if(!mCursor->isVisible())return false;
		if(!window->isVisible())return false;
		return (cursorX >= (window->getLeft()) && cursorX <= (window->getLeft()+window->getWidth())
				&& cursorY >= (window->getTop()) && cursorY <= (window->getTop()+window->getHeight())
				&& window->isVisible() );
	}
	void setLeftClick(bool flag)
	{
		if(!leftClick && flag){mouseLeftDown();}
		else if(leftClick && !flag){mouseLeftUp();}
		leftClick = flag;
	}
	void setRightClick(bool flag)
	{
		if(!rightClick && flag){mouseRightDown();}
		else if(rightClick && !flag){mouseRightUp();}
		rightClick = flag;
	}
	void mouseLeftDown()
	{
		//release input mode on left click (except for chat & chage dimension)
		//redetermine mHoverWindow
		if(mHoverWindow && (!mHoverButton || mHoverButton->getParent()!=mHoverWindow) && !isCursorOverWindow(mHoverWindow))
		{
			mHoverWindow = 0;
			updateHover();
		}
		

		if(mHoverButton)
		{
			mSoundManager->playGUISound(SOUND_CLICK);
			setCurrentWindow(mHoverButton->getParent());
			if(hoverButtonType==GUITYPE_CHECKBOX)
			{
				toggleCheckBox(mHoverButton);
				return;
			}
			else mHoverButton->setMaterialName("GUIMat/ButtonDown");

			//Sizer actions
			if(mHoverButton==mSizer[SIZER_TEXTOUTPUT])	//Size chatbox
			{
				sizeWindowDrag(SIZEDIR_TOP, 0, 0.06);
				return;
			}

			//Mover actions
			mMoverWindow = getMoverWindow(mHoverButton); //check if it's a mover
			if(mMoverWindow)
			{
				doMove(true);
				return;
			}

			//Scroller actions
			short scrollerID = getScrollerID(mHoverButton); //check if it's a scroller
			if(scrollerID!=-1)doScroll(true,scrollerID);

			return;
		}

		if(mHoverWindow)
		{
			setCurrentWindow(mHoverWindow);
			//Window actions
			
			if(mHoverWindow==mBox[GUI_WORLDEDITORBOXPANEL1])	//Try to change panel
			{
				showWorldEditorPanel(1);
				return;
			}
			if(mHoverWindow==mBox[GUI_WORLDEDITORBOXPANEL2])	//Try to change panel
			{
				showWorldEditorPanel(2);
				return;
			}
			if(mHoverWindow==mBox[GUI_WORLDEDITORBOXPANEL3])	//Try to change panel
			{
				showWorldEditorPanel(3);
				return;
			}
			if(mHoverWindow==mBox[GUI_WORLDEDITORBOXPANEL4])	//Try to change panel
			{
				showWorldEditorPanel(4);
				return;
			}
			if(mHoverButton==mBox[GUI_WORLDEDITORBOXPANEL5])	//Try to change panel
			{
				showWorldEditorPanel(5);
				return;
			}
			//No further actions if clicked on window
			return;
		}

	}
	void toggleCheckBox(OverlayElement *checkBox)
	{
		if(!checkBox)return;
		if(checkBox->getMaterialName()!="GUIMat/CheckBoxTrue" && checkBox->getMaterialName()!="GUIMat/CheckBoxFalse")return;
		if(isCheckBoxTrue(checkBox))checkBox->setMaterialName("GUIMat/CheckBoxFalse");
		else checkBox->setMaterialName("GUIMat/CheckBoxTrue");
	}
	void mouseLeftUp()
	{
		if(sizeWindowDir)sizeWindowDrag(0);
		if(mMoverWindow)doMove(false);
		if(scrollerHeldID!=-1)doScroll(false);

		if(mHoverButton)
		if(isCursorOverButton(mHoverButton))
		{
			if(hoverButtonType!=GUITYPE_CHECKBOX)mHoverButton->setMaterialName("GUIMat/ButtonOver");
			else return;
			
			//Button actions
			if(mHoverButton==mButton[BUTTON_WORLDEDITORSCREEN])	//World Editor Screen
			{
				toggleWorldEditorOverlay();
				return;
			}
		}
		if(mHoverButton)
		{
			//Scroller actions
			short scrollerID = getScrollerID(mHoverButton);
			if(scrollerID==SCROLLER_INTERFACE1)	//mouse sensitivity
			{
				mouseSensitivity = getScroll(SCROLLER_INTERFACE1);
				return;
			}
		}
	}
	void mouseRightDown()
	{
	}
	void mouseRightUp()
	{
	}
	const String getDebugText()
	{
		return mDebugText;
	}
	void toggleInputMode(bool isEnter, OverlayElement *inputBox=0, String defaultCaption="Say: ", unsigned short charLimit=256, bool clearAtReturn=true, String startText="", bool allowTempStorage=true, bool allowNewLine=false, bool hideText=false)
	{
		if(mInputManager->getInputMode()==INPUT_CONTROL)
		{
			if(!inputBox)
			{
				inputBox = mBoxText[GUI_TEXTINPUT];
				String tCaption = mBoxText[GUI_TEXTINPUT]->getCaption();
				tCaption.erase(0,5);
				startText = tCaption;
			}

			mInputManager->setInputBox(inputBox,defaultCaption,charLimit,clearAtReturn,startText,allowTempStorage,allowNewLine,hideText);

		}
	}
	bool selectCurrentObject(SceneNode *object, const unsigned int &flags=0, bool isRightClick=false)
	{
		if(object)
		{
			
		}
		else
		{
			mCurrentObject = 0;
		}
		return false;
	}
	void processSelectBoxClick()
	{
		if(!mHoverButton)return;
		const OverlayElement* tButtonText = static_cast<OverlayContainer*>(mHoverButton)->getChildIterator().getNext();
		if(!tButtonText)return;
		const String tFunction = tButtonText->getCaption();
			
	}
	void sizeWindowDrag(unsigned short sizeDir, const Real &minWidth=0, const Real &minHeight=0)
	{
		sizeWindowDir = sizeDir;
		if(sizeDir!=0 && mHoverButton)
		{
			dragStartX = cursorX;
			dragStartY = cursorY;
			sizeWindowWidth = mHoverButton->getParent()->getWidth();
			sizeWindowHeight = mHoverButton->getParent()->getHeight();
			sizeWindowLeft = mHoverButton->getParent()->getLeft();
			sizeWindowTop = mHoverButton->getParent()->getTop();
			sizeWindowMinWidth = minWidth;
			sizeWindowMinHeight = minHeight;
		}
	}
	void doScroll(bool flag, short iID=0)
	{
		if(!flag)
		{
			scrollerHeldID = -1;
			return;
		}
		if(!mScroller[iID] || !mScrollerMarker[iID])return;
		scrollerHeldID = iID;

		if(isScrollerHorz[iID])
		{
			mScrollerMarker[iID]->setLeft(cursorX - mScroller[iID]->getParent()->getLeft());
			if(mScrollerMarker[iID]->getLeft()<mScroller[iID]->getLeft())mScrollerMarker[iID]->setLeft(mScroller[iID]->getLeft());
			if(mScrollerMarker[iID]->getLeft()>mScroller[iID]->getLeft()+mScroller[iID]->getWidth())mScrollerMarker[iID]->setLeft(mScroller[iID]->getLeft()+mScroller[iID]->getWidth());
			mScrollerMarker[iID]->setLeft(mScrollerMarker[iID]->getLeft()-mScrollerMarker[iID]->getWidth()/2);
		}
		else
		{
			mScrollerMarker[iID]->setTop(cursorY - mScroller[iID]->getParent()->getTop());
			if(mScrollerMarker[iID]->getTop()<mScroller[iID]->getTop())mScrollerMarker[iID]->setTop(mScroller[iID]->getTop());
			if(mScrollerMarker[iID]->getTop()>mScroller[iID]->getTop()+mScroller[iID]->getHeight())mScrollerMarker[iID]->setTop(mScroller[iID]->getTop()+mScroller[iID]->getHeight());
			mScrollerMarker[iID]->setTop(mScrollerMarker[iID]->getTop()-mScrollerMarker[iID]->getHeight()/2);
		}
	}
	void doMove(bool flag)
	{
		if(flag && mMoverWindow)
		{
			dragStartX = cursorX - mMoverWindow->getLeft();
			dragStartY = cursorY - mMoverWindow->getTop();
		}
		else
		{
			dragStartX = 0;
			dragStartY = 0;
			mMoverWindow = 0;
		}
	}
	const Real getScroll(unsigned short iID)
	{
		if(!mScroller[iID] || !mScrollerMarker[iID])return 0;

		if(isScrollerHorz[iID])
		{
			return (mScrollerMarker[iID]->getLeft() + mScrollerMarker[iID]->getWidth()/2 - mScroller[iID]->getLeft())/mScroller[iID]->getWidth();
		}
		else
		{
			return (mScrollerMarker[iID]->getTop() + mScrollerMarker[iID]->getHeight()/2 - mScroller[iID]->getTop())/mScroller[iID]->getHeight();
		}
	}
	void setScroll(unsigned short iID, Real ratio)
	{
		if(!mScroller[iID] || !mScrollerMarker[iID])return;

		if(isScrollerHorz[iID])
		{
			mScrollerMarker[iID]->setLeft(mScroller[iID]->getLeft() + mScroller[iID]->getWidth()*ratio - mScrollerMarker[iID]->getWidth()/2);
		}
		else
		{
			mScrollerMarker[iID]->setTop(mScroller[iID]->getTop() + mScroller[iID]->getHeight()*ratio - mScrollerMarker[iID]->getHeight()/2);
		}
	}
	void resizeScrollbarByParent(OverlayElement *parent, const Real &dwidth, const Real &dheight)
	{
		for(int i=0;i<MAX_SCROLLERS;i++)
		{
			if(mScroller[i])
			if(mScroller[i]->getParent()==parent)
			{
				Real tRatio = getScroll(i);
				if(isScrollerHorz[i])
				{
					mScroller[i]->setWidth(mScroller[i]->getWidth()+(parent->getWidth()-dwidth));
				}
				else
				{
					mScroller[i]->setHeight(mScroller[i]->getHeight()+(parent->getHeight()-dheight));
				}
				setScroll(i,tRatio);
				return;
			}
		}
	}
	const short getScrollerID(OverlayElement *scroller)
	{
		for(int i=0;i<MAX_SCROLLERS;i++)
			if(mScrollerMarker[i]&& mScrollerMarker[i]==scroller)return i;
		return -1;
	}
	void updateBoxScrollerCaption(const unsigned short &boxID, const unsigned short &scrollerID, const vector<String>::type &captionList)
	{
		if(boxID>=MAX_BOXES)return;
		if(!mBox[boxID] || !mBoxText[boxID])return;
		
		const Real tCharHeight = StringConverter::parseReal(mBoxText[boxID]->getParameter("char_height"));
		if(tCharHeight==0)return;
		const Real tLines = (mBox[boxID]->getHeight()-mBoxText[boxID]->getTop())/tCharHeight - 1;

		int start = (int)(getScroll(scrollerID)* (int(captionList.size()) - Math::IFloor(tLines)));
		if(start<0)start = 0;
		String tCaption = "";
		unsigned short tCaptionLines = 0;
		for(int i=start;i<int(captionList.size());i++)
		{
			tCaption += (i==start?"":"\n");
			tCaption += captionList[i];
			tCaptionLines += 1;
			if(tCaptionLines>=tLines)break;
		}
		mBoxText[boxID]->setCaption(tCaption);
	}
	const short getListButtonLine(const unsigned short &boxID, const unsigned short &scrollerID, const unsigned short &listLines, Real &fontHeight, short &apparentLine)
	{
		if(boxID>=MAX_BOXES)return -1;
		if(!mBox[boxID] || !mBoxText[boxID])return -1;
		
		const Real tCharHeight = StringConverter::parseReal(mBoxText[boxID]->getParameter("char_height"));
		if(tCharHeight==0)return -1;
		else fontHeight = tCharHeight;
		const Real tLines = (mBox[boxID]->getHeight()-mBoxText[boxID]->getTop())/tCharHeight - 1;

		int start = (int)(getScroll(scrollerID)* (listLines - Math::IFloor(tLines)));
		if(start<0)start = 0;
		
		const Real tY = cursorY - mBox[boxID]->getTop();
		apparentLine = (short)(tY/tCharHeight);
		return short(apparentLine + start);
	}
	const short getListButtonLine(const unsigned short &boxID, Real &fontHeight, short &apparentLine)
	{
		if(boxID>=MAX_BOXES)return -1;
		if(!mBox[boxID] || !mBoxText[boxID])return -1;
		
		const Real tCharHeight = StringConverter::parseReal(mBoxText[boxID]->getParameter("char_height"));
		if(tCharHeight==0)return -1;
		else fontHeight = tCharHeight;
		const Real tLines = (mBox[boxID]->getHeight()-mBoxText[boxID]->getTop())/tCharHeight - 1;
		
		const Real tY = cursorY - mBox[boxID]->getTop();
		apparentLine = (short)(tY/tCharHeight);
		return short(apparentLine);
	}
	OverlayElement* getMoverWindow(OverlayElement *mover)
	{
		for(int i=0;i<MAX_MOVERS;i++)
			if(mMover[i]&& mMover[i]==mover)return mMover[i]->getParent();
		return 0;
	}
	void toggleShowOptions()
	{
	}
	bool isOptionsVisible()
	{
		return (mBox[GUI_OPTIONS]->isVisible()||mBox[GUI_SETTINGS]->isVisible()||mBox[GUI_INTERFACE]->isVisible());
	}
	void toggleUseWindowsCursor(bool dontShowAlert=false)
	{
		const bool tOn = (mButtonText[BUTTON_INTERFACE8]->getCaption()=="On");
		mButtonText[BUTTON_INTERFACE8]->setCaption((!tOn?"On":"Off"));
	}
	bool getUseWindowsCursor()
	{
		return useWindowsCursor;
	}
	const Real getMouseSensitivity()
	{
		return mouseSensitivity;
	}
	void toggleShowGUI()
	{
		if(isGUIVisible)
		{
			showGUI(false);
			return;
		}
		if(!isGUIVisible)
		{
			showGUI(true);
			return;
		}
	}
	void showGUI(bool flag)
	{
		isGUIVisible = flag;
	}
	bool getWasGUIVisible()
	{
		return wasGUIVisible;
	}
	MagixInputManager* getInputManager()
	{
		return mInputManager;
	}
	void setCurrentWindow(OverlayElement *window)
	{
		if(!window)return;
		if(window->getZOrder()!=48700)return;
		if(getParentOverlay(mCurrentWindow))getParentOverlay(mCurrentWindow)->setZOrder(487);
		mCurrentWindow = window;
		if(getParentOverlay(mCurrentWindow))getParentOverlay(mCurrentWindow)->setZOrder(488);
		mHoverWindow = mCurrentWindow;
	}
	Overlay* getParentOverlay(OverlayElement *element)
	{
		if(!element)return 0;
		if(element==mBox[GUI_TEXTINPUT]||element==mBox[GUI_TEXTOUTPUT])return OverlayManager::getSingleton().getByName("GUIOverlay/Chat");
		String tName = element->getName();
		if(tName.length()<4)return 0;
		tName.erase(0,3);
		return OverlayManager::getSingleton().getByName("GUIOverlay"+tName);
	}
	void setBackdrop(const String &name, bool resetSize)
	{
		mBackdrop->setMaterialName(name);
		if(resetSize)
		{
			mBackdrop->setDimensions(1,1);
			mBackdrop->setPosition(0,0);
		}
	}
	bool isCheckBoxTrue(OverlayElement *checkBox)
	{
		if(!checkBox)return false;
		return (checkBox->getMaterialName()=="GUIMat/CheckBoxTrue");
	}
};

#endif

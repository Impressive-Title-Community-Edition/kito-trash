#ifndef __MagixSkyManager_h_
#define __MagixSkyManager_h_
#include <OgreTerrainGroup.h>
#include <SkyX.h>
using namespace Ogre;

//#define MAX_CLOUDS 10
#define MAX_STARS 277
#define NORTH Vector3::UNIT_Z
#define EAST Vector3::NEGATIVE_UNIT_X
#define SOUTH Vector3::NEGATIVE_UNIT_Z
#define WEST Vector3::UNIT_X
#define DAYSPEED 10//0.5
#define DEFAULT_FOG_COLOUR ColourValue(192.0f/255, 229.0f/255, 253.0f/255)
#define DEFAULT_SUNLIGHT_COLOUR ColourValue(1.0, 1.0, 0.8)
#define DEFAULT_MOONLIGHT_COLOUR ColourValue(0.01, 0.01, 0.01)
#define FOG_DENSITY .0001
//#define FOG_START 1000 //500
//#define FOG_END 2500 //1500

/** SkyX settings struct
    @remarks These just are the most important SkyX parameters, not all SkyX parameters.
 */
struct SkyXSettings
{
	/** Constructor
	    @remarks Skydome + vol. clouds + lightning settings
	 */
	SkyXSettings(const Ogre::Vector3 t, const Ogre::Real& tm, const Ogre::Real& mp, const SkyX::AtmosphereManager::Options& atmOpt,
		const bool& lc, const bool& vc, const Ogre::Real& vcws, const bool& vcauto, const Ogre::Radian& vcwd, 
		const Ogre::Vector3& vcac, const Ogre::Vector4& vclr,  const Ogre::Vector4& vcaf, const Ogre::Vector2& vcw,
		const bool& vcl, const Ogre::Real& vclat, const Ogre::Vector3& vclc, const Ogre::Real& vcltm)
		: time(t), timeMultiplier(tm), moonPhase(mp), atmosphereOpt(atmOpt), layeredClouds(lc), volumetricClouds(vc), vcWindSpeed(vcws)
		, vcAutoupdate(vcauto), vcWindDir(vcwd), vcAmbientColor(vcac), vcLightResponse(vclr), vcAmbientFactors(vcaf), vcWheater(vcw)
		, vcLightnings(vcl), vcLightningsAT(vclat), vcLightningsColor(vclc), vcLightningsTM(vcltm)
	{}

	/** Constructor
	    @remarks Skydome + vol. clouds
	 */
	SkyXSettings(const Ogre::Vector3 t, const Ogre::Real& tm, const Ogre::Real& mp, const SkyX::AtmosphereManager::Options& atmOpt,
		const bool& lc, const bool& vc, const Ogre::Real& vcws, const bool& vcauto, const Ogre::Radian& vcwd, 
		const Ogre::Vector3& vcac, const Ogre::Vector4& vclr,  const Ogre::Vector4& vcaf, const Ogre::Vector2& vcw)
		: time(t), timeMultiplier(tm), moonPhase(mp), atmosphereOpt(atmOpt), layeredClouds(lc), volumetricClouds(vc), vcWindSpeed(vcws)
		, vcAutoupdate(vcauto), vcWindDir(vcwd), vcAmbientColor(vcac), vcLightResponse(vclr), vcAmbientFactors(vcaf), vcWheater(vcw), vcLightnings(false)
	{}

	/** Constructor
	    @remarks Skydome settings
	 */
	SkyXSettings(const Ogre::Vector3 t, const Ogre::Real& tm, const Ogre::Real& mp, const SkyX::AtmosphereManager::Options& atmOpt, const bool& lc)
		: time(t), timeMultiplier(tm), moonPhase(mp), atmosphereOpt(atmOpt), layeredClouds(lc), volumetricClouds(false), vcLightnings(false)
	{}

	/// Time
	Ogre::Vector3 time;
	/// Time multiplier
	Ogre::Real timeMultiplier;
	/// Moon phase
	Ogre::Real moonPhase;
	/// Atmosphere options
	SkyX::AtmosphereManager::Options atmosphereOpt;
	/// Layered clouds?
	bool layeredClouds;
	/// Volumetric clouds?
	bool volumetricClouds;
	/// VClouds wind speed
	Ogre::Real vcWindSpeed;
	/// VClouds autoupdate
	bool vcAutoupdate;
	/// VClouds wind direction
	Ogre::Radian vcWindDir;
	/// VClouds ambient color
	Ogre::Vector3 vcAmbientColor;
	/// VClouds light response
	Ogre::Vector4 vcLightResponse;
	/// VClouds ambient factors
	Ogre::Vector4 vcAmbientFactors;
	/// VClouds wheater
	Ogre::Vector2 vcWheater;
	/// VClouds lightnings?
	bool vcLightnings;
	/// VClouds lightnings average aparition time
	Ogre::Real vcLightningsAT;
	/// VClouds lightnings color
	Ogre::Vector3 vcLightningsColor;
	/// VClouds lightnings time multiplier
	Ogre::Real vcLightningsTM;
};

/** Demo presets
    @remarks The best way of determinate each parameter value is by using a real-time editor.
			 These presets have been quickly designed using the Paradise Editor, which is a commercial solution.
			 At the time I'm writting these lines, SkyX 0.1 is supported by Ogitor. Hope that the Ogitor team will 
			 support soon SkyX 0.3, this way you all are going to be able to quickly create cool SkyX configurations.
 */
SkyXSettings mPresets[] = {
	// Sunset
	SkyXSettings(Ogre::Vector3(8.85f, 7.5f, 20.5f),  -0.08f, 0, SkyX::AtmosphereManager::Options(9.77501f, 10.2963f, 0.01f, 0.0022f, 0.000675f, 30, Ogre::Vector3(0.57f, 0.52f, 0.44f), -0.991f, 3, 4), false, true, 300, false, Ogre::Radian(270), Ogre::Vector3(0.63f,0.63f,0.7f), Ogre::Vector4(0.35, 0.2, 0.92, 0.1), Ogre::Vector4(0.4, 0.7, 0, 0), Ogre::Vector2(0.8,1)),
	// Clear
	SkyXSettings(Ogre::Vector3(17.16f, 7.5f, 20.5f), 0, 0, SkyX::AtmosphereManager::Options(9.77501f, 10.2963f, 0.01f, 0.0017f, 0.000675f, 30, Ogre::Vector3(0.57f, 0.54f, 0.44f), -0.991f, 2.5f, 4), false),
	// Thunderstorm 1
	SkyXSettings(Ogre::Vector3(12.23, 7.5f, 20.5f),  0, 0, SkyX::AtmosphereManager::Options(9.77501f, 10.2963f, 0.01f, 0.00545f, 0.000375f, 30, Ogre::Vector3(0.55f, 0.54f, 0.52f), -0.991f, 1, 4), false, true, 300, false, Ogre::Radian(0), Ogre::Vector3(0.63f,0.63f,0.7f), Ogre::Vector4(0.25, 0.4, 0.5, 0.1), Ogre::Vector4(0.45, 0.3, 0.6, 0.1), Ogre::Vector2(1,1), true, 0.5, Ogre::Vector3(1,0.976,0.92), 2),
	// Thunderstorm 2
	SkyXSettings(Ogre::Vector3(10.23, 7.5f, 20.5f),  0, 0, SkyX::AtmosphereManager::Options(9.77501f, 10.2963f, 0.01f, 0.00545f, 0.000375f, 30, Ogre::Vector3(0.55f, 0.54f, 0.52f), -0.991f, 0.5, 4), false, true, 300, false, Ogre::Radian(0), Ogre::Vector3(0.63f,0.63f,0.7f), Ogre::Vector4(0, 0.02, 0.34, 0.24), Ogre::Vector4(0.29, 0.3, 0.6, 1), Ogre::Vector2(1,1), true, 0.5, Ogre::Vector3(0.95,1,1), 2),
	// Desert
	SkyXSettings(Ogre::Vector3(7.59f, 7.5f, 20.5f), 0, -0.8f, SkyX::AtmosphereManager::Options(9.77501f, 10.2963f, 0.01f, 0.0072f, 0.000925f, 30, Ogre::Vector3(0.71f, 0.59f, 0.53f), -0.997f, 2.5f, 1), true),
	// Night
	SkyXSettings(Ogre::Vector3(21.5f, 7.5, 20.5), 0.03, -0.25, SkyX::AtmosphereManager::Options(), true)
};

class MagixSkyManager
{
protected:
	MagixExternalDefinitions *mDef;
	MagixCamera *mCamera;
	MagixSoundManager *mSoundManager;
	TerrainGlobalOptions *mTerrainGlobals;
	SceneManager *mSceneMgr;
//	SceneNode *mSkyNode;
//	Entity *mSkyDome;
	//BillboardSet *mCloudSet;
//	BillboardSet *mSun;
//	BillboardSet *mSunRadiance;
//	BillboardSet *mMoon;
//	BillboardSet *mStars;
	Light *mSunLight;
	Light *mMoonLight;
	//Real cloudSpeed[MAX_CLOUDS];
	Real skyDayTime;
	bool dayTimeFrozen;
	Real frozenDayTime;
	SceneNode *mWeatherNode;
	ParticleSystem *mWeatherSystem;
	Real weatherTime;
	bool weatherLocked;
	String weatherType;
	String weatherCycle;
	ColourValue weatherSkyShader;
	//ColourValue weatherSkyAdder;
	String weatherEffect;
	Real weatherEffectCountdown;
	vector<const WeatherEvent>::type weatherCycleEventList;
	bool hasWeatherSound;
	bool interiorSky;
	Real FOG_START, FOG_END;
	// kito
	SkyX::SkyX* mSkyX;
	SkyX::BasicController* mBasicController;
public:
	MagixSkyManager()
	{
		mDef = 0;
		mCamera = 0;
		mSoundManager = 0;
		mSceneMgr = 0;
//		mSkyNode = 0;
//		mSkyDome = 0;
		//mCloudSet = 0;
//		mSun = 0;
//		mSunRadiance = 0;
//		mMoon = 0;
//		mStars = 0;
		mSunLight = 0;
		mMoonLight = 0;
		//for(int i=0;i<MAX_CLOUDS;i++)cloudSpeed[i] = 0;
		skyDayTime = 500;
		dayTimeFrozen = false;
		frozenDayTime = 0;

		mWeatherNode = 0;
		mWeatherSystem = 0;
		weatherTime = 0;
		weatherLocked = false;
		weatherType = "";
		weatherCycle = "";
		weatherSkyShader = ColourValue::White;
		//weatherSkyAdder = ColourValue::Black;
		weatherEffect = "";
		weatherEffectCountdown = 0;
		weatherCycleEventList.clear();
		hasWeatherSound = false;

		interiorSky = false;

		FOG_START = 1000;
		FOG_END = 2500;
		mSkyX = 0;
		mBasicController = 0;
	}
	~MagixSkyManager()
	{
		weatherCycleEventList.clear();
	}
	void initialize(SceneManager *sceneMgr, MagixExternalDefinitions *def, MagixCamera *camera, MagixSoundManager *soundMgr, TerrainGlobalOptions* TerrainGlobals)
	{
		mSceneMgr = sceneMgr;
		mDef = def;
		mCamera = camera;
		mSoundManager = soundMgr;
		mTerrainGlobals = TerrainGlobals;

		// kito - skyX
		mBasicController = new SkyX::BasicController();
		mSkyX = new SkyX::SkyX(mSceneMgr, mBasicController);
		mSkyX->create();

		mBasicController->setMoonPhase(0.75f);

/*		mSkyDome = mSceneMgr->createEntity("Sky", "Semidome.mesh");
		mSkyDome->setCastShadows(false);
		mSkyDome->setQueryFlags(SKY_MASK);

		Entity *cloudDome = mSceneMgr->createEntity("CloudDome", "Semidome.mesh");
		cloudDome->setCastShadows(false);
		cloudDome->setMaterialName("Sky/CloudDome");
		cloudDome->setQueryFlags(SKY_MASK);
*/
		/*mCloudSet = mSceneMgr->createBillboardSet("Clouds");
		for(int i=0;i<MAX_CLOUDS;i++)
		{
			Real tYZ = Math::RangeRandom(0,100);
			Billboard *cloud = mCloudSet->createBillboard(Vector3(Math::RangeRandom(-500,500),100-tYZ,tYZ*(Math::RangeRandom(0,10)>5?1:-1) ));
			cloudSpeed[i] = Math::RangeRandom(10,50);
		}
		mCloudSet->setCastShadows(false);
		mCloudSet->setDefaultDimensions(20,8);
		mCloudSet->setBillboardType(BBT_ORIENTED_COMMON);
		mCloudSet->setCommonDirection(Vector3::UNIT_Y);
		mCloudSet->setMaterialName("cloudMat");
		mCloudSet->setVisible(true);*/
/*
		mSun = mSceneMgr->createBillboardSet("Sun",1);
		mSun->setCastShadows(false);
		mSun->setMaterialName("Sky/SunMat");
		mSun->setDefaultDimensions(40,40);
		mSun->createBillboard(Vector3(-100,100,0),ColourValue(1,1,1,0.95));
		mSun->setQueryFlags(SKY_MASK);
		mSunRadiance = mSceneMgr->createBillboardSet("SunRadiance",1);
		mSunRadiance->setCastShadows(false);
		mSunRadiance->setMaterialName("Sky/SunRadiance");
		mSunRadiance->setDefaultDimensions(100,100);
		mSunRadiance->createBillboard(Vector3(-100,100,0),ColourValue(1,1,1,0.95));
		mSunRadiance->setQueryFlags(SKY_MASK);

		mMoon = mSceneMgr->createBillboardSet("Moon",1);
		mMoon->setCastShadows(false);
		mMoon->setDefaultDimensions(40,40);
		mMoon->setMaterialName("Sky/MoonMat");
		mMoon->createBillboard(Vector3(100,100,0),ColourValue(1,1,1,0.90));
		mMoon->setQueryFlags(SKY_MASK);

		mStars = mSceneMgr->createBillboardSet("Stars",MAX_STARS);
		mStars->setCastShadows(false);
		mStars->setDefaultDimensions(1,1);
		mStars->setMaterialName("Sky/StarMat");
		mStars->setQueryFlags(SKY_MASK);
		for(int i=0;i<MAX_STARS;i++)mStars->createBillboard(Vector3(Math::RangeRandom(-200,200),Math::RangeRandom(50,100),Math::RangeRandom(-200,200)));

		mSkyNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		mSkyNode->attachObject(mSkyDome);
		mSkyNode->attachObject(cloudDome);
		mSkyNode->attachObject(mSun);
		mSkyNode->attachObject(mSunRadiance);
		mSkyNode->attachObject(mMoon);
		mSkyNode->attachObject(mStars);
		//mSkyNode->attachObject(mCloudSet);
		mSkyNode->setScale(150,150,150);
		*/
		mSunLight = mSceneMgr->createLight("SunLight");
		mSunLight->setType(Light::LT_DIRECTIONAL);
		mSunLight->setDiffuseColour(ColourValue(DEFAULT_SUNLIGHT_COLOUR));
		mSunLight->setSpecularColour(ColourValue(DEFAULT_SUNLIGHT_COLOUR));
		mSunLight->setDirection(Vector3( 0.25, -0.75, 0 ));
		mSunLight->setVisible(true);

		mMoonLight = mSceneMgr->createLight("MoonLight");
		mMoonLight->setType(Light::LT_DIRECTIONAL);
		mMoonLight->setDiffuseColour(ColourValue(DEFAULT_MOONLIGHT_COLOUR));
		mMoonLight->setSpecularColour(ColourValue(DEFAULT_MOONLIGHT_COLOUR));
		mMoonLight->setDirection(Vector3( -0.25, -0.75, 0 ));
		mMoonLight->setVisible(false);

		// Set ambient light
		mSceneMgr->setAmbientLight(ColourValue(0.2, 0.2, 0.2));
		//mSceneMgr->setShadowTechnique(SHADOWTYPE_NONE);
		//mSceneMgr->setShadowFarDistance(300);
		//mSceneMgr->setShadowTextureSize(1024);

		mWeatherNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		mWeatherNode->createChildSceneNode("WeatherOffsetNode");
		mWeatherNode->createChildSceneNode("WeatherEffectNode");

		showSky(false);
	}
	/*void updateClouds(const FrameEvent &evt)
	{
		for(int i=0;i<MAX_CLOUDS;i++)
		{
			mCloudSet->getBillboard(i)->setPosition(mCloudSet->getBillboard(i)->getPosition()+Vector3(cloudSpeed[i],0,0)*evt.timeSinceLastFrame);
			if(mCloudSet->getBillboard(i)->getPosition().x > 100)
			{
				Real tYZ = Math::RangeRandom(0,500);
				mCloudSet->getBillboard(i)->setPosition(Vector3(-500,100-tYZ,tYZ*(Math::RangeRandom(0,10)>5?1:-1) ));
			}
		}
	}*/
	void updateSky()
	{
		if(mSceneMgr->getCamera("PlayerCam")->isAttached())
		{
//			mSkyNode->setPosition(mSceneMgr->getCamera("PlayerCam")->getDerivedPosition());
			mWeatherNode->setPosition(mSceneMgr->getCamera("PlayerCam")->getDerivedPosition());
		}
		else 
		{
//			mSkyNode->setPosition(mSceneMgr->getCamera("PlayerCam")->getPosition());
			mWeatherNode->setPosition(mSceneMgr->getCamera("PlayerCam")->getPosition());
		}
	}
	void resetSky()
	{
		if (!mSkyX->getVCloudsManager()->isCreated())
		{
			// SkyX::MeshManager::getSkydomeRadius(...) works for both finite and infinite(=0) camera far clip distances
			mSkyX->getVCloudsManager()->create(mSkyX->getMeshManager()->getSkydomeRadius(mCamera->getCamera()));
		}return;
		const ColourValue tFogColour = mSceneMgr->getFogColour();
		weatherSkyShader = ColourValue::White;
		//weatherSkyAdder = ColourValue::Black;
		destroyWeather();
//		mSkyDome->getSubEntity(0)->setCustomParameter(1,Vector4(1,1,1,1));
		//mSkyDome->getSubEntity(0)->setCustomParameter(2,Vector4(0,0,0,0));
		mSceneMgr->setFog( FOG_LINEAR, ColourValue(), FOG_DENSITY, FOG_START, FOG_END);
		mSunLight->setDiffuseColour(ColourValue(DEFAULT_SUNLIGHT_COLOUR));
		mSunLight->setSpecularColour(ColourValue(DEFAULT_SUNLIGHT_COLOUR));
		mMoonLight->setDiffuseColour(ColourValue(DEFAULT_SUNLIGHT_COLOUR));
		mMoonLight->setSpecularColour(ColourValue(DEFAULT_SUNLIGHT_COLOUR));
		updateCelestials(dayTimeFrozen?frozenDayTime:skyDayTime);
		if(interiorSky)setInteriorSky(true,tFogColour);
	}
	void updateCelestials(const Real &dayTime)
	{return;
		if(interiorSky)return;
		FOG_END = mDef->viewDistance*2083 + 417;
		FOG_START = mDef->viewDistance*833 + 167;
		#pragma warning(push)
		#pragma warning(disable : 4482)
		//Day
		if(dayTime>=600 && dayTime<1800)
		{
//			if(!mSun->isVisible())mSun->setVisible(true);
//			if(!mSunRadiance->isVisible())mSunRadiance->setVisible(true);
//			if(mMoon->isVisible())mMoon->setVisible(false);
//			if(mStars->isVisible())mStars->setVisible(false);
			if(!mSunLight->isVisible())mSunLight->setVisible(true);
			if(mMoonLight->isVisible())mMoonLight->setVisible(false);

			//Sun movement
			if(dayTime<=1200)
			{
//				mSun->getBillboard(0)->setPosition(Vector3(-(1200-dayTime)*100/600,(dayTime-600)*100/600,0));
//				mSunRadiance->getBillboard(0)->setPosition(Vector3(-(1200-dayTime)*100/600,(dayTime-600)*100/600,0));
			}
			else
			{
//				mSun->getBillboard(0)->setPosition(Vector3((dayTime-1200)*100/600,(1800-dayTime)*100/600,0));
//				mSunRadiance->getBillboard(0)->setPosition(Vector3((dayTime-1200)*100/600,(1800-dayTime)*100/600,0));
			}

			mSunLight->setDirection((dayTime-1200)*(Ogre::Real)-0.75/(Ogre::Real)600, -0.75, 0);

			ColourValue skyColour = ColourValue(1,1,1,1) *weatherSkyShader;
			ColourValue fadeColour = DEFAULT_FOG_COLOUR *weatherSkyShader;
			ColourValue sunLightColour = DEFAULT_SUNLIGHT_COLOUR;
			ColourValue cloudColour = ColourValue(1,1,1,1);
			ColourValue sunRadianceColour = ColourValue(0,0,0,1);
			//post dawn
			if(dayTime<=700)
			{
				const Real tFade = (dayTime-600)*(Ogre::Real)1.0/(Ogre::Real)100;
				//skyColour = skyColour * ColourValue(1,0.9+tFade*0.1,0.75+tFade*0.25,1);
				skyColour = skyColour * ColourValue((float)(0.5+0.5*tFade),(float)(0.5+0.5*tFade),(float)(0.5+0.5*tFade),1);
				//fadeColour = fadeColour * ColourValue(1,0.9+tFade*0.1,0.75+tFade*0.25,1);
				fadeColour = fadeColour * ColourValue((float)(0.5+0.5*tFade),(float)(0.5+0.5*tFade),(float)(0.5+0.5*tFade),1);
				sunLightColour = sunLightColour * ColourValue(1,(float)(0.9+tFade*0.1),(float)(-0.25+tFade*1.25),1);
				cloudColour = ColourValue(1,(float)(0.8+tFade*0.2),(float)(0.1+tFade*0.9),1);
				sunRadianceColour = ColourValue((float)((1-tFade)*1.0),(float)((1-tFade)*0.8),0,1);
			}
			//pre dusk
			if(dayTime>=1700)
			{
				const Real tFade = (1800-dayTime)*(Ogre::Real)1.0/(Ogre::Real)100;
				//skyColour = skyColour * ColourValue(1,0.8+tFade*0.2,0.7+tFade*0.3,1);
				skyColour = skyColour * ColourValue((float)(0.5+0.5*tFade),(float)(0.5+0.5*tFade),(float)(0.5+0.5*tFade),1);
				//fadeColour = fadeColour * ColourValue(1,0.8+tFade*0.2,0.7+tFade*0.3,1);
				fadeColour = fadeColour * ColourValue((float)(0.5+0.5*tFade),(float)(0.5+0.5*tFade),(float)(0.5+0.5*tFade),1);
				sunLightColour = sunLightColour * ColourValue(1,(float)(0.8+tFade*0.2),(float)(-0.3+tFade*1.2),1);
				cloudColour = ColourValue(1,(float)(0.75+tFade*0.25),(float)(0.1+tFade*0.9),1);
				sunRadianceColour = ColourValue((float)((1-tFade)*1.0),(float)((1-tFade)*0.7),0,1);
			}
			//fadeColour += weatherSkyAdder;
			//fadeColour.saturate();
			if(mSceneMgr->getFogColour() != fadeColour || mSceneMgr->getFogEnd()!=FOG_END)
			{
//				mSkyDome->getSubEntity(0)->setCustomParameter(1,Vec4(skyColour));
				//mSkyDome->getSubEntity(0)->setCustomParameter(2,Vec4(weatherSkyAdder));
//				if(mSkyDome->getSubEntity(0)->getTechnique()->getName()=="2")
				{
//					mSkyDome->getSubEntity(0)->getTechnique()->getPass(0)->getTextureUnitState(1)->setColourOperationEx(LayerBlendOperationEx::LBX_MODULATE,
//																														LayerBlendSource::LBS_MANUAL,
//																														LayerBlendSource::LBS_CURRENT,
//																														ColourValue(mSkyDome->getSubEntity(0)->getCustomParameter(1).x,
//																																	mSkyDome->getSubEntity(0)->getCustomParameter(1).y,
//																																	mSkyDome->getSubEntity(0)->getCustomParameter(1).z));
					/*mSkyDome->getSubEntity(0)->getTechnique()->getPass(0)->getTextureUnitState(2)->setColourOperationEx(LayerBlendOperationEx::LBX_ADD,
																														LayerBlendSource::LBS_MANUAL,
																														LayerBlendSource::LBS_CURRENT,
																														ColourValue(mSkyDome->getSubEntity(0)->getCustomParameter(2).x,
																																	mSkyDome->getSubEntity(0)->getCustomParameter(2).y,
																																	mSkyDome->getSubEntity(0)->getCustomParameter(2).z));*/
				}
				mSceneMgr->setFog( FOG_LINEAR, fadeColour, FOG_DENSITY, FOG_START, FOG_END);
				mSunLight->setDiffuseColour(sunLightColour);
				mSunLight->setSpecularColour(sunLightColour);
//				mSun->getBillboard(0)->setColour(ColourValue(1,1,1,0.95));
				cloudColour = cloudColour * weatherSkyShader;
				//cloudColour += weatherSkyAdder;
				//cloudColour.saturate();
				static_cast<MaterialPtr>(MaterialManager::getSingleton().getByName("Sky/CloudDome")).get()->setSelfIllumination(cloudColour);
				static_cast<MaterialPtr>(MaterialManager::getSingleton().getByName("Sky/SunRadiance")).get()->setSelfIllumination(sunRadianceColour);
			}
			mTerrainGlobals->setLightMapDirection(mSunLight->getDerivedDirection());
			mTerrainGlobals->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
			mTerrainGlobals->setCompositeMapDiffuse(mSunLight->getDiffuseColour());
			return;
		}
		//Dusk
		if(dayTime>=1800 && dayTime<1900)
		{
//			if(!mSun->isVisible())mSun->setVisible(true);
//			if(!mSunRadiance->isVisible())mSunRadiance->setVisible(true);
//			if(!mMoon->isVisible())mMoon->setVisible(true);
//			if(!mStars->isVisible())mStars->setVisible(true);
			if(!mSunLight->isVisible())mSunLight->setVisible(true);
			if(!mMoonLight->isVisible())mMoonLight->setVisible(true);
			if(mMoonLight->getCastShadows())mMoonLight->setCastShadows(false);

//			mSun->getBillboard(0)->setPosition(Vector3((dayTime-1200)*100/600,(1800-dayTime)*100/600,0));
//			mSunRadiance->getBillboard(0)->setPosition(Vector3((dayTime-1200)*100/600,(1800-dayTime)*100/600,0));

//			mSun->getBillboard(0)->setColour(ColourValue((float)((1900-dayTime)*1.0/100),(float)((1900-dayTime)*1.0/100),(float)((1900-dayTime)*1.0/100),(float)((1900-dayTime)*0.95/100)));
//			mMoon->getBillboard(0)->setColour(ColourValue((float)((dayTime-1800)*1.0/100),(float)((dayTime-1800)*1.0/100),(float)((dayTime-1800)*1.0/100),(float)((dayTime-1800)*0.90/100)));
			for(int i=0;i<MAX_STARS;i++)
			{
				const Real tBlink = Math::RangeRandom(0,(dayTime-1800)*(Ogre::Real)1.0/100);
//				mStars->getBillboard(i)->setColour(ColourValue(tBlink,tBlink,tBlink,tBlink));
			}

			ColourValue sunLightColour = DEFAULT_SUNLIGHT_COLOUR * ColourValue(1,0.8,-0.3,1);
			sunLightColour *= (1900-dayTime)/100;
			mSunLight->setDiffuseColour(sunLightColour);
			mSunLight->setSpecularColour(sunLightColour);
			mSunLight->setDirection(-0.75, -0.75, 0);

			ColourValue moonLightColour = DEFAULT_MOONLIGHT_COLOUR;
			moonLightColour *= (dayTime-1800)/100;
			mMoonLight->setDiffuseColour(moonLightColour);
			mMoonLight->setSpecularColour(moonLightColour);

			const Real tFade = (1900-dayTime)*(Ogre::Real)1.0/(Ogre::Real)100;
			Vector4 skyFade(tFade*(Ogre::Real)0.5,tFade*(Ogre::Real)0.5,tFade*(Ogre::Real)0.5,1);
			/*Vector4 skyFade(0.4+tFade*0.6,0.4+tFade*0.6,0.5+tFade*0.5,1);
			skyFade *= Vector4(1,1-tFade*0.2,1-tFade*0.3,1);
			skyFade *= Vec4(weatherSkyShader);*/
//			mSkyDome->getSubEntity(0)->setCustomParameter(1,skyFade);
			//mSkyDome->getSubEntity(0)->setCustomParameter(2,Vec4(weatherSkyAdder));
//			if(mSkyDome->getSubEntity(0)->getTechnique()->getName()=="2")
			{
/*				mSkyDome->getSubEntity(0)->getTechnique()->getPass(0)->getTextureUnitState(1)->setColourOperationEx(LayerBlendOperationEx::LBX_MODULATE,
																													LayerBlendSource::LBS_MANUAL,
																													LayerBlendSource::LBS_CURRENT,
																													ColourValue(skyFade.x,
																																skyFade.y,
																																skyFade.z));
*/				/*mSkyDome->getSubEntity(0)->getTechnique()->getPass(0)->getTextureUnitState(2)->setColourOperationEx(LayerBlendOperationEx::LBX_ADD,
																													LayerBlendSource::LBS_MANUAL,
																													LayerBlendSource::LBS_CURRENT,
																													ColourValue(mSkyDome->getSubEntity(0)->getCustomParameter(2).x,
																																mSkyDome->getSubEntity(0)->getCustomParameter(2).y,
																																mSkyDome->getSubEntity(0)->getCustomParameter(2).z));*/
			}

			ColourValue fadeColour = DEFAULT_FOG_COLOUR;
			fadeColour = fadeColour * ColourValue((float)(0.1+tFade*0.4),(float)(0.1+tFade*0.4),(float)(0.1+tFade*0.4),1);
			//fadeColour = fadeColour * ColourValue(0.4+tFade*0.5,0.4+tFade*0.5,0.5+tFade*0.4,1);
			//fadeColour = fadeColour * ColourValue(1,1-tFade*0.2,1-tFade*0.3,1);
			//fadeColour = fadeColour * weatherSkyShader;
			//fadeColour += weatherSkyAdder;
			//fadeColour.saturate();
			mSceneMgr->setFog( FOG_LINEAR, fadeColour, FOG_DENSITY, FOG_START, FOG_END);

			ColourValue cloudColour = ColourValue((float)(0.1+tFade*0.9),(float)(0.1+tFade*0.65),0.1);
			cloudColour = cloudColour * weatherSkyShader;
			//cloudColour += weatherSkyAdder;
			//cloudColour.saturate();
			static_cast<MaterialPtr>(MaterialManager::getSingleton().getByName("Sky/CloudDome")).get()->setSelfIllumination(cloudColour);
			static_cast<MaterialPtr>(MaterialManager::getSingleton().getByName("Sky/SunRadiance")).get()->setSelfIllumination(tFade*(Ogre::Real)1.0,tFade*(Ogre::Real)0.7,0);
			mTerrainGlobals->setLightMapDirection(mSunLight->getDerivedDirection());
			mTerrainGlobals->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
			mTerrainGlobals->setCompositeMapDiffuse(mSunLight->getDiffuseColour());
			return;
		}
		//Night
		if(dayTime>=1900 || dayTime<500)
		{
//			if(mSun->isVisible())mSun->setVisible(false);
//			if(mSunRadiance->isVisible())mSunRadiance->setVisible(false);
//			if(!mMoon->isVisible())mMoon->setVisible(true);
//			if(!mStars->isVisible())mStars->setVisible(true);
			if(mSunLight->isVisible())mSunLight->setVisible(false);
			if(!mMoonLight->isVisible())mMoonLight->setVisible(true);
			if(!mMoonLight->getCastShadows())mMoonLight->setCastShadows(true);

			for(int i=0;i<MAX_STARS;i++)
			{
				const Real tBlink = Math::RangeRandom(0,1.0);
//				mStars->getBillboard(i)->setColour(ColourValue(tBlink,tBlink,tBlink,tBlink));
			}

			ColourValue fadeColour = DEFAULT_FOG_COLOUR;
			fadeColour = fadeColour * ColourValue(0.1,0.1,0.1,1);
			fadeColour = fadeColour * weatherSkyShader;
			//fadeColour += weatherSkyAdder;
			//fadeColour.saturate();
			if(mSceneMgr->getFogColour()!= fadeColour || mSceneMgr->getFogEnd()!=FOG_END)
			{
//				mSkyDome->getSubEntity(0)->setCustomParameter(1,Vector4(0.0,0.0,0.0,1) *Vec4(weatherSkyShader));
				//mSkyDome->getSubEntity(0)->setCustomParameter(2,Vec4(weatherSkyAdder));
//				if(mSkyDome->getSubEntity(0)->getTechnique()->getName()=="2")
				{
/*					mSkyDome->getSubEntity(0)->getTechnique()->getPass(0)->getTextureUnitState(1)->setColourOperationEx(LayerBlendOperationEx::LBX_MODULATE,
																														LayerBlendSource::LBS_MANUAL,
																														LayerBlendSource::LBS_CURRENT,
																														ColourValue(mSkyDome->getSubEntity(0)->getCustomParameter(1).x,
																																	mSkyDome->getSubEntity(0)->getCustomParameter(1).y,
																																	mSkyDome->getSubEntity(0)->getCustomParameter(1).z));
*/					/*mSkyDome->getSubEntity(0)->getTechnique()->getPass(0)->getTextureUnitState(2)->setColourOperationEx(LayerBlendOperationEx::LBX_ADD,
																													LayerBlendSource::LBS_MANUAL,
																													LayerBlendSource::LBS_CURRENT,
																													ColourValue(mSkyDome->getSubEntity(0)->getCustomParameter(2).x,
																																mSkyDome->getSubEntity(0)->getCustomParameter(2).y,
																																mSkyDome->getSubEntity(0)->getCustomParameter(2).z));*/
				}
				mSceneMgr->setFog( FOG_LINEAR, fadeColour, FOG_DENSITY, FOG_START, FOG_END);
//				mMoon->getBillboard(0)->setColour(ColourValue(1,1,1,0.9));
				ColourValue cloudColour = ColourValue(0.1,0.1,0.1);
				cloudColour = cloudColour * weatherSkyShader;
				//cloudColour += weatherSkyAdder;
				//cloudColour.saturate();
				static_cast<MaterialPtr>(MaterialManager::getSingleton().getByName("Sky/CloudDome")).get()->setSelfIllumination(cloudColour);
			}
			mTerrainGlobals->setLightMapDirection(mMoonLight->getDerivedDirection());
			mTerrainGlobals->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
			mTerrainGlobals->setCompositeMapDiffuse(mMoonLight->getDiffuseColour());
			return;
		}
		//Dawn
		if(dayTime>=500 && dayTime<600)
		{
//			if(!mSun->isVisible())mSun->setVisible(true);
//			if(!mSunRadiance->isVisible())mSunRadiance->setVisible(true);
//			if(!mMoon->isVisible())mMoon->setVisible(true);
//			if(!mStars->isVisible())mStars->setVisible(true);
			if(!mSunLight->isVisible())mSunLight->setVisible(true);
			if(!mMoonLight->isVisible())mMoonLight->setVisible(true);
			if(mMoonLight->getCastShadows())mMoonLight->setCastShadows(false);

//			mSun->getBillboard(0)->setPosition(Vector3(-(1200-dayTime)*100/600,(dayTime-600)*100/600,0));
//			mSunRadiance->getBillboard(0)->setPosition(Vector3(-(1200-dayTime)*100/600,(dayTime-600)*100/600,0));

//			mSun->getBillboard(0)->setColour(ColourValue((float)((dayTime-500)*1.0/100),(float)((dayTime-500)*1.0/100),(float)((dayTime-500)*1.0/100),(float)((dayTime-500)*0.95/100)));
//			mMoon->getBillboard(0)->setColour(ColourValue((float)((600-dayTime)*1.0/100),(float)((600-dayTime)*1.0/100),(float)((600-dayTime)*1.0/100),(float)((600-dayTime)*0.90/100)));
			for(int i=0;i<MAX_STARS;i++)
			{
				const Real tBlink = Math::RangeRandom(0,(600-dayTime)*(Ogre::Real)1.0/(Ogre::Real)100);
//				mStars->getBillboard(i)->setColour(ColourValue(tBlink,tBlink,tBlink,tBlink));
			}

			ColourValue sunLightColour = DEFAULT_SUNLIGHT_COLOUR * ColourValue(1,0.9,-0.25,1);
			sunLightColour *= (dayTime-500)/100;
			mSunLight->setDiffuseColour(sunLightColour);
			mSunLight->setSpecularColour(sunLightColour);
			mSunLight->setDirection(0.75, -0.75, 0);

			ColourValue moonLightColour = DEFAULT_MOONLIGHT_COLOUR;
			moonLightColour *= (600-dayTime)/100;
			mMoonLight->setDiffuseColour(moonLightColour);
			mMoonLight->setSpecularColour(moonLightColour);

			const Real tFade = (dayTime-500)*(Ogre::Real)1.0/(Ogre::Real)100;
			Vector4 skyFade(tFade*(Ogre::Real)0.5,tFade*(Ogre::Real)0.5,tFade*(Ogre::Real)0.5,1);
			/*Vector4 skyFade(0.4+tFade*0.6,0.4+tFade*0.6,0.5+tFade*0.5,1);
			skyFade *= Vector4(1,1-tFade*0.1,1-tFade*0.25,1);
			skyFade *= Vec4(weatherSkyShader);*/
//			mSkyDome->getSubEntity(0)->setCustomParameter(1,skyFade);
			//mSkyDome->getSubEntity(0)->setCustomParameter(2,Vec4(weatherSkyAdder));
//			if(mSkyDome->getSubEntity(0)->getTechnique()->getName()=="2")
			{
/*				mSkyDome->getSubEntity(0)->getTechnique()->getPass(0)->getTextureUnitState(1)->setColourOperationEx(LayerBlendOperationEx::LBX_MODULATE,
																													LayerBlendSource::LBS_MANUAL,
																													LayerBlendSource::LBS_CURRENT,
																													ColourValue(skyFade.x,
																																skyFade.y,
																																skyFade.z));
*/				/*mSkyDome->getSubEntity(0)->getTechnique()->getPass(0)->getTextureUnitState(2)->setColourOperationEx(LayerBlendOperationEx::LBX_ADD,
																													LayerBlendSource::LBS_MANUAL,
																													LayerBlendSource::LBS_CURRENT,
																													ColourValue(mSkyDome->getSubEntity(0)->getCustomParameter(2).x,
																																mSkyDome->getSubEntity(0)->getCustomParameter(2).y,
																																mSkyDome->getSubEntity(0)->getCustomParameter(2).z));*/
			}

			ColourValue fadeColour = DEFAULT_FOG_COLOUR;
			fadeColour = fadeColour * ColourValue((float)(0.1+tFade*0.5),(float)(0.1+tFade*0.5),(float)(0.1+tFade*0.5),1);
			//fadeColour = fadeColour * ColourValue(1,1-tFade*0.1,1-tFade*0.25,1);
			//fadeColour = fadeColour * weatherSkyShader;
			//fadeColour += weatherSkyAdder;
			//fadeColour.saturate();
			mSceneMgr->setFog( FOG_LINEAR, fadeColour, FOG_DENSITY, FOG_START, FOG_END);

			ColourValue cloudColour = ColourValue((Ogre::Real)0.1+tFade*(Ogre::Real)0.9,(Ogre::Real)0.1+tFade*(Ogre::Real)0.7,(Ogre::Real)0.1);
			cloudColour = cloudColour * weatherSkyShader;
			//cloudColour += weatherSkyAdder;
			//cloudColour.saturate();

			static_cast<MaterialPtr>(MaterialManager::getSingleton().getByName("Sky/CloudDome")).get()->setSelfIllumination(cloudColour);
			static_cast<MaterialPtr>(MaterialManager::getSingleton().getByName("Sky/SunRadiance")).get()->setSelfIllumination(tFade*(Ogre::Real)1.0,tFade*(Ogre::Real)0.8,0);
			
			mTerrainGlobals->setLightMapDirection(mSunLight->getDerivedDirection());
			mTerrainGlobals->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
			mTerrainGlobals->setCompositeMapDiffuse(mSunLight->getDiffuseColour());
			return;
		}
		#pragma warning(pop)
	}
	void updateWeather()
	{return;
		weatherSkyShader = ColourValue::White;
		//weatherSkyAdder = ColourValue::Black;

		for(int i=0;i<(int)weatherCycleEventList.size();i++)
		{
			const WeatherEvent weatherEvent = weatherCycleEventList[i];
			if(weatherTime>=weatherEvent.start && weatherTime<weatherEvent.end)
			{
				//Constant Effect
				if(weatherEvent.isConstant)
				{
					weatherSkyShader = weatherEvent.skyShader;
					//weatherSkyAdder = weatherEvent.skyAdder;
					if(weatherEvent.type==""&&mWeatherSystem)destroyWeather();
					else if(weatherType!=weatherEvent.type)
					{
						setWeather(weatherEvent.type);
						if(mWeatherSystem)mWeatherSystem->getEmitter(0)->setEmissionRate(weatherEvent.rate);
						if(hasWeatherSound)mSoundManager->setAmbientSoundVolume(0.8);
					}
					if(weatherEvent.effect.size()!=0)
					{
						if(weatherEffect=="" && Math::UnitRandom()<weatherEvent.effectFrequency)
						{
							const Real tRandom = Math::UnitRandom();
							for(int j=1;j<=(int)weatherEvent.effect.size();j++)
							{
								if(j==(int)weatherEvent.effect.size())setWeatherEffect(weatherEvent.effect[j-1]);
								else if(tRandom>1-(j/(int)weatherEvent.effect.size()))setWeatherEffect(weatherEvent.effect[j-1]);
							}
						}
					}
				}
				//Transitioning Effect
				else
				{
					//Sky Colour
					if(weatherEvent.skyShader!=ColourValue::White)
					{
						Real tFade = 0;
						if(weatherTime<=(weatherEvent.start+100))
						{
							tFade = ((weatherEvent.start+100) - weatherTime)/100;
						}
						else if(weatherTime>=(weatherEvent.end-100))
						{
							tFade = (weatherTime - (weatherEvent.end-100))/100;
						}
						weatherSkyShader = ColourValue(weatherEvent.skyShader.r + tFade*(1-weatherEvent.skyShader.r), weatherEvent.skyShader.g + tFade*(1-weatherEvent.skyShader.g), weatherEvent.skyShader.b + tFade*(1-weatherEvent.skyShader.b));
					}
					/*if(weatherEvent.skyAdder!=ColourValue::Black)
					{
						Real tFade = 0;
						if(weatherTime<=(weatherEvent.start+100))
						{
							tFade = ((weatherEvent.start+100) - weatherTime)/100;
						}
						else if(weatherTime>=(weatherEvent.end-100))
						{
							tFade = (weatherTime - (weatherEvent.end-100))/100;
						}
						weatherSkyAdder = ColourValue((1-tFade)*weatherEvent.skyAdder.r, (1-tFade)*weatherEvent.skyAdder.g, (1-tFade)*weatherEvent.skyAdder.b);
					}*/

					//Weather Particles
					if(weatherEvent.type==""&&mWeatherSystem)destroyWeather();
					else
					{
						if(weatherTime>=(weatherEvent.start+100) && weatherType!=weatherEvent.type)setWeather(weatherEvent.type);

						if(!mWeatherSystem)return;
						if(weatherTime<=(weatherEvent.start+200))
						{
							mWeatherSystem->getEmitter(0)->setEmissionRate((weatherEvent.rate/100) * (weatherTime-(weatherEvent.start+100)));
							if(hasWeatherSound)mSoundManager->setAmbientSoundVolume((weatherTime-(weatherEvent.start+100))*(Ogre::Real)0.008);
						}
						else if(weatherTime>=(weatherEvent.end-200) && weatherTime<(weatherEvent.end-100))
						{
							mWeatherSystem->getEmitter(0)->setEmissionRate((weatherEvent.rate/100) * ((weatherEvent.end-100)-weatherTime));
							if(hasWeatherSound)mSoundManager->setAmbientSoundVolume(((weatherEvent.end-100)-weatherTime)*(Ogre::Real)0.008);
						}
						else if(weatherTime>=(weatherEvent.end-100))
						{
							mWeatherSystem->getEmitter(0)->setEmissionRate(0);
							if(hasWeatherSound)mSoundManager->setAmbientSoundVolume(0);
						}
						else
						{
							mWeatherSystem->getEmitter(0)->setEmissionRate(weatherEvent.rate);
							if(hasWeatherSound)mSoundManager->setAmbientSoundVolume(0.8);
						}
					}

					//Weather Effect
					if(weatherEvent.effect.size()!=0)
					{
						if(weatherTime>=(weatherEvent.start+100) && weatherTime<=(weatherEvent.end-100))
						{
							if(weatherEffect=="" && Math::UnitRandom()<weatherEvent.effectFrequency)
							{
								const Real tRandom = Math::UnitRandom();
								for(int j=1;j<=(int)weatherEvent.effect.size();j++)
								{
									if(j==(int)weatherEvent.effect.size())setWeatherEffect(weatherEvent.effect[j-1]);
									else if(tRandom>1-(j/(int)weatherEvent.effect.size()))setWeatherEffect(weatherEvent.effect[j-1]);
								}
							}
						}
					}
				}
				return;
			}
		}
		if(mWeatherSystem)destroyWeather();

	}
	void updateWeatherEffect(const Real &timeElapsed, bool clearEffect=false)
	{return;
		if(weatherEffectCountdown==0&&!clearEffect)return;
		weatherEffectCountdown -= timeElapsed;
		if(weatherEffectCountdown<0 || clearEffect)weatherEffectCountdown = 0;

		if(weatherEffect=="Lightning")
		{
			if(weatherEffectCountdown>0.2)weatherSkyShader = ColourValue(0.9,0.9,0.9);
			else if(weatherEffectCountdown<0.15 && weatherEffectCountdown>0.1)weatherSkyShader = ColourValue(0.9,0.9,0.9);
			else if(weatherEffectCountdown<0.03)weatherSkyShader = ColourValue(0.9,0.9,0.9);
		}
		else if(weatherEffect=="Thunder")
		{
			if(weatherEffectCountdown==0)
			{
				SceneNode *tWeatherEffectNode = mSceneMgr->getSceneNode("WeatherEffectNode");
				tWeatherEffectNode->setPosition((5+Math::UnitRandom()*45)*(Math::UnitRandom()>0.5?1:-1),0,(5+Math::UnitRandom()*45)*(Math::UnitRandom()>0.5?1:-1));
				mSoundManager->playSound((Math::UnitRandom()>0.2?SOUND_THUNDER1:SOUND_THUNDER2),tWeatherEffectNode);
			}
		}
		else if(weatherEffect=="LightningThunder")
		{
			if(weatherEffectCountdown>2.3)weatherSkyShader = ColourValue(0.9,0.9,0.9);
			else if(weatherEffectCountdown<2.25 && weatherEffectCountdown>2.2)weatherSkyShader = ColourValue(0.9,0.9,0.9);
			else if(weatherEffectCountdown<2.15 && weatherEffectCountdown>2.12)weatherSkyShader = ColourValue(0.9,0.9,0.9);
			else if(weatherEffectCountdown==0)
			{
				SceneNode *tWeatherEffectNode = mSceneMgr->getSceneNode("WeatherEffectNode");
				tWeatherEffectNode->setPosition((5+Math::UnitRandom()*45)*(Math::UnitRandom()>0.5?1:-1),0,(5+Math::UnitRandom()*45)*(Math::UnitRandom()>0.5?1:-1));
				mSoundManager->playSound((Math::UnitRandom()>0.2?SOUND_THUNDER1:SOUND_THUNDER2),tWeatherEffectNode);
			}
		}
		else if(weatherEffect=="Earthquake" || weatherEffect=="Earthquake2")
		{
			if(weatherEffectCountdown==0)
			{
				mSoundManager->stopLoopedSoundByNode(mWeatherNode,SOUND_EARTHQUAKE);
				mCamera->doQuake(false,true);
			}
		}

		if(weatherEffectCountdown==0)weatherEffect = "";
	}
	void update(const FrameEvent &evt)
	{
		mSkyX->update(evt.timeSinceLastFrame);
		mSkyX->notifyCameraRender(mCamera->getCamera());
		Ogre::Vector3 lightDir = mSkyX->getVCloudsManager()->getVClouds()->getSunDirection();
		//Ogre::Vector3 sunPos = mCamera->getDerivedPosition() - lightDir*mSkyX->getMeshManager()->getSkydomeRadius()*0.1;
		mTerrainGlobals->setLightMapDirection(lightDir);
		Vector3 aColor = mSkyX->getVCloudsManager()->getVClouds()->getAmbientColor();
		Vector3 sColor = mSkyX->getVCloudsManager()->getVClouds()->getSunColor();
		mTerrainGlobals->setCompositeMapAmbient(ColourValue(aColor.x, aColor.y, aColor.z));
		mTerrainGlobals->setCompositeMapDiffuse(ColourValue(sColor.x, sColor.y, sColor.z));
return;
		skyDayTime += DAYSPEED*evt.timeSinceLastFrame;
		if(skyDayTime>=2400)skyDayTime = 0;
		updateSky();
		updateCelestials(dayTimeFrozen?frozenDayTime:skyDayTime);
		if(!weatherLocked)
		{
			weatherTime += DAYSPEED*evt.timeSinceLastFrame;
			if(weatherTime>=7000)weatherTime = 0;
			updateWeather();
			updateWeatherEffect(evt.timeSinceLastFrame);
		}
		if(mWeatherSystem)
		{
			if(mCamera->getIsUnderwater() && isWeatherVisible())showWeather(false);
			else if(!mCamera->getIsUnderwater() && !isWeatherVisible())showWeather(true);
		}
		//updateClouds(evt);
	}
	void showSky(bool flag)
	{
//		mSkyNode->setVisible(flag);
		mWeatherNode->setVisible(flag);
	}
	void showWeather(bool flag)
	{
//		if(!flag || mSkyDome->isVisible())mWeatherNode->setVisible(flag);
	}
	bool isWeatherVisible()
	{
		if(!mWeatherSystem)return false;
		return (mWeatherSystem->isVisible());
	}
	void setDayTime(const Real &time)
	{
		skyDayTime = time;return;
		resetSky();
	}
	const Real getDayTime()
	{
		return skyDayTime;
	}
	const Real getWeatherTime()
	{
		return weatherTime;
	}
	void freezeDayTime(bool flag, const Real &time=0)
	{
		dayTimeFrozen = flag;
		if(flag)frozenDayTime = time;
	}
	void setWeatherTime(const Real &time)
	{return;
		if(weatherLocked)return;
		weatherTime = time;
		updateWeather();
	}
	void lockWeather(bool flag)
	{
		weatherLocked = flag;
	}
	void setWeather(const String &type)
	{
		return;
		weatherType = type;
		String tTypeName = "";
		Vector3 tOffset = Vector3::ZERO;
		String tSoundName = "";
		/*switch(type)
		{
		case WEATHER_RAIN: tTypeName="Weather/Rain"; tOffset=Vector3(0,400,0); tSoundName=SOUND_RAIN1; break;
		case WEATHER_SNOW: tTypeName="Weather/Snow"; tOffset=Vector3(-400,700,-600); break;
		case WEATHER_STARFALL: tTypeName="Weather/Starfall"; tOffset=Vector3(800,1200,1200); break;
		case WEATHER_FIREWORKS: tTypeName="Weather/Fireworks"; tOffset=Vector3(-1000,500,-1000); break;
		}*/
		mDef->loadWeather(type,tTypeName,tOffset,tSoundName);
		destroyWeather();
		hasWeatherSound = (tSoundName!="");
		if(tSoundName!="")mSoundManager->playAmbientSound(tSoundName.c_str(),0);
		if(tTypeName=="")return;
		mWeatherSystem = mSceneMgr->createParticleSystem("WeatherSystem",tTypeName);
		mWeatherSystem->setQueryFlags(SKY_MASK);
		SceneNode *tWeatherOffsetNode = mSceneMgr->getSceneNode("WeatherOffsetNode");
		tWeatherOffsetNode->attachObject(mWeatherSystem);
		tWeatherOffsetNode->setPosition(tOffset);
	}
	void destroyWeather()
	{return;
		weatherEffect = "";
		weatherEffectCountdown = 0;
		if(hasWeatherSound)mSoundManager->stopLoopedSoundByNode(mWeatherNode);
		hasWeatherSound = false;
		if(!mWeatherSystem)return;
		SceneNode *tWeatherOffsetNode = mSceneMgr->getSceneNode("WeatherOffsetNode");
		tWeatherOffsetNode->detachObject(mWeatherSystem);
		mSceneMgr->destroyParticleSystem(mWeatherSystem);
		mWeatherSystem = 0;
		weatherType = "";
		mSoundManager->stopAmbientSound();
	}
	const Vector4 Vec4(const ColourValue &colour)
	{
		return Vector4(colour.r,colour.g,colour.b,colour.a);
	}
	void setWeatherEffect(const String &type)
	{return;
		if(weatherEffect!="")updateWeatherEffect(0,true);
		weatherEffect = type;
		if(type=="Lightning")weatherEffectCountdown = 0.25;
		else if(type=="Thunder")weatherEffectCountdown = 1;
		else if(type=="LightningThunder")weatherEffectCountdown = 2.35;
		else if(type=="Earthquake")
		{
			weatherEffectCountdown = 5;
			mSoundManager->playLoopedSound(SOUND_EARTHQUAKE,mWeatherNode,1,0.5);
			mCamera->doQuake(true,true);
		}
		else if(type=="Earthquake2")
		{
			weatherEffectCountdown = 0.5;
			mSoundManager->playLoopedSound(SOUND_EARTHQUAKE,mWeatherNode,1,0.5);
			mCamera->doQuake(true,true);
		}
		else
		{
			weatherEffect = "";
			weatherEffectCountdown = 0;
		}
	}
	void setInteriorSky(bool flag, const ColourValue &fogColour=ColourValue(0.06,0.05,0.07))
	{mSceneMgr->setAmbientLight(ColourValue(0.3, 0.3, 0.3));return;
		interiorSky = flag;
//		mSkyNode->setVisible(!flag);
		if(flag)
		{
			mSceneMgr->setFog( FOG_LINEAR, fogColour, .01, 100, 1200);
//			mSunLight->setVisible(false);
//			mMoonLight->setVisible(false);
			mSceneMgr->setAmbientLight(ColourValue(0.01, 0.01, 0.01));
		}
		else 
		{
			mSceneMgr->setAmbientLight(ColourValue(0.2, 0.2, 0.2));
			updateCelestials(dayTimeFrozen?frozenDayTime:skyDayTime);
		}
	}
	void setWeatherCycle(const String &type)
	{
		srand( (unsigned)time( NULL ) );
		int nPreset = rand() % 5 + 1;
		SkyXSettings preset = mPresets[nPreset];

		// Layered clouds
		if (preset.layeredClouds)
		{
			// Create layer cloud
			if (mSkyX->getCloudsManager()->getCloudLayers().empty())
			{
				mSkyX->getCloudsManager()->add(SkyX::CloudLayer::Options(/* Default options */));
			}
		}
		else
		{
			// Remove layer cloud
			if (!mSkyX->getCloudsManager()->getCloudLayers().empty())
			{
				mSkyX->getCloudsManager()->removeAll();
			}
		}
		
		mSkyX->setTimeMultiplier(preset.timeMultiplier);
		mBasicController->setTime(preset.time);
		mBasicController->setMoonPhase(preset.moonPhase);
		mSkyX->getAtmosphereManager()->setOptions(preset.atmosphereOpt);

		mSkyX->getVCloudsManager()->setWindSpeed(preset.vcWindSpeed);
		mSkyX->getVCloudsManager()->setAutoupdate(preset.vcAutoupdate);

		SkyX::VClouds::VClouds* vclouds = mSkyX->getVCloudsManager()->getVClouds();

		vclouds->setWindDirection(preset.vcWindDir);
		vclouds->setAmbientColor(preset.vcAmbientColor);
		vclouds->setLightResponse(preset.vcLightResponse);
		vclouds->setAmbientFactors(preset.vcAmbientFactors);
		vclouds->setWheater(preset.vcWheater.x, preset.vcWheater.y, false);

		vclouds->getLightningManager()->setEnabled(preset.vcLightnings);
		vclouds->getLightningManager()->setAverageLightningApparitionTime(preset.vcLightningsAT);
		vclouds->getLightningManager()->setLightningColor(preset.vcLightningsColor);
		vclouds->getLightningManager()->setLightningTimeMultiplier(preset.vcLightningsTM);
		return;
		/*if(type=="None")setWeatherCycle(WEATHERCYCLE_NONE);
		else if(type=="Rain")setWeatherCycle(WEATHERCYCLE_RAIN);
		else if(type=="Snow")setWeatherCycle(WEATHERCYCLE_SNOW);
		else if(type=="Redsky")setWeatherCycle(WEATHERCYCLE_RED);
		else if(type=="HeavyRain")setWeatherCycle(WEATHERCYCLE_HEAVYRAIN);
		else if(type=="Starfall")setWeatherCycle(WEATHERCYCLE_STARFALL);
		else if(type=="RainStarfall")setWeatherCycle(WEATHERCYCLE_RAINSTARFALL);
		else if(type=="Thunderstorm")setWeatherCycle(WEATHERCYCLE_THUNDERSTORM);
		else if(type=="ThunderstormRain")setWeatherCycle(WEATHERCYCLE_THUNDERSTORMRAIN);
		else if(type=="Fireworks")setWeatherCycle(WEATHERCYCLE_FIREWORKS);*/
		if(type!="" && type!="None")mDef->loadWeatherCycle(type,weatherCycleEventList);
		else weatherCycleEventList.clear();
		weatherCycle = type=="None"?"":type;
	}
};

#endif
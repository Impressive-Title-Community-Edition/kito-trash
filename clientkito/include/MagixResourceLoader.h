#include "OgreResource.h"
#include "OgreResourceGroupManager.h"
#include "OgreException.h"
#include "OgreArchive.h"
#include "OgreArchiveManager.h"

using namespace Ogre;

/*
Description: Listens for .mesh files to load and checks if they're encrypted as 
they are loaded and applies decryption as needed
*/
typedef boost::shared_ptr<MemoryDataStream> dsPtr;
class MagixResourceLoader : public ResourceLoadingListener//, public ResourceGroupManager
{
protected:
	ResourceGroupManager *mResourceGroupManagerPtr;
    uint16 HEADER_STREAM_ID;
    uint16 OTHER_ENDIAN_HEADER_STREAM_ID;
	std::vector<dsPtr>         ds_vector;

public:
	MagixResourceLoader() {
		mResourceGroupManagerPtr = 0;
		HEADER_STREAM_ID = 0x1000;
		OTHER_ENDIAN_HEADER_STREAM_ID = 0x0010;
	}
	virtual ~MagixResourceLoader(){}

	/** 
	 * Init listening for resources to load
	 */
	virtual void start()
	{
		mResourceGroupManagerPtr = ResourceGroupManager::getSingletonPtr();
		// self is listener
		ResourceGroupManager::getSingleton().setLoadingListener(this);
	}

	void resourceStreamOpened(const String &name, const String &group, Resource *resource, DataStreamPtr& dataStream)
	{
		// function to modify the stream if needed
		String cmp = ".emesh"; // it is encrypted
		if (StringUtil::endsWith(name, cmp))
		{
			// know it is encrypted
			char * buffer;
			buffer = new char[dataStream->size()];
			dataStream->seek(0);
			// Read everything into memory
			dataStream->read(buffer, dataStream->size());
			for (size_t i=0; i<dataStream->size(); i++)
			{
				buffer[i] ^= 85;
			}
			dataStream->seek(0);

			dsPtr ds_ptr( OGRE_NEW MemoryDataStream(dataStream->getName(),buffer,dataStream->size(),false,!dataStream->isWriteable()) );
			ds_vector.push_back( ds_ptr );
			dataStream->close();
			dataStream.setNull();
			MemoryDataStream* stream = 0;
			stream = (ds_ptr.get());
			dataStream.bind(stream);
		}
	}

	DataStreamPtr resourceLoading(const String &resourceName, const String &groupName, Resource *resourceBeingLoaded)
	{
		DataStreamPtr ptr;
		return ptr;
	}

	bool resourceCollision(Resource *resource, ResourceManager *resourceManager)
	{
		return false;
	}
};


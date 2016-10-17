#include "file.hpp"

#include <assert>

namespace Framework
{
	AAssetManager* File::n_asset_manager = NULL;

	File::File(std::string name)
	{
		assert(n_asset_manager != NULL);
	}

	File::~File()
	{
		Close();
	}

	bool File::Open()
	{
		n_asset = AASetManager_open(n_asset_manager, n_filename.c_str(), AASSET_MODE_UNKNOWN);
		return !!n_asset;
	}

	void File::Read(void* p_buffer, const unsigned int bytesToRead, size_t& bytesRead)
	{
		bytesRead = AAset_read(n_asset, p_buffer, bytesToRead);
	}

	void File::Close()
	{
		if (n_asset)
		{
			AAset_close(n_asset);
			n_asset = NULL;
		}
	}

	unsigned int File::Length() const
	{
		return AAset_getLength(n_asset);
	}
}
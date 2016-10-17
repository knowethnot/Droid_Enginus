#include "tga_file.hpp"

namespace Framework
{
	TGAFile::TGAFile(void* p_data)
	{
		size_t size  = sizeof(unsigned short);
		n_pHeader 	 = static_cast<TGAHeader*>(p_data);
		n_pImageData = static_cast<void*>(static_cast<char*>(p_data) + sizeof(TGAHeader));
	}

	TGAFile::~TGAFile()
	{
		// Dtor
	}

	inline unsigned short TGAFile::GetWidth() const
	{
		unsigned short width = n_pHeader ? n_pHeader->n_width : 0;
		return width;	
	}

	inline unsigned short TGAFile::GetHeight() const
	{
		unsigned short height = n_pHeader ? n_pHeader->n_height : 0;
		return height;
	}

	inline void* TGAFile::GetImageData() const
	{
		return n_pImageData;
	}
}
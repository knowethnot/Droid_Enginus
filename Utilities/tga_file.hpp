#ifndef __TGA_FILE_HPP__
#define __TGA_FILE_HPP__

#include "file.hpp"

namespace Framework
{
	class TGAFile
	{
		public:
			struct TGAHeader
			{
				unsigned char 	n_idSize;
				unsigned char 	n_colorMapType;
				unsigned char 	n_imageType;

				unsigned short 	n_palleteStart;
				unsigned short 	n_palleteLength;
				unsigned char 	n_palleteBits;

				unsigned short  n_xOrigin;
				unsigned short  n_yOrigin;
				unsigned short  n_width;
				unsigned short  n_height;

				unsigned char   n_bpp;
				unsigned char 	n_descriptor;

			} __attribute__ ((packed));

			TGAFile(void* p_data);
			virtual ~TGAFile();

			unsigned short GetWidth() const;
			unsigned short GetHeight() const;

			void* GetImageData() const;

		private:
			TGAHeader* n_pHeader;
			void*      n_pImageData;
	};
}

#endif // __TGA_FILE_HPP__
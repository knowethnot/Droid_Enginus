#ifndef __FILE_HPP__
#define __FILE_HPP__

#include <string>

namespace Framework
{
	class File
	{
		public:
			explicit File(std::string name);
			~File();

			bool Open();

			unsigned int Length() const;

			void Read(void* p_buffer, const unsigned int bytesToRead, size_t& bytesRead);
			void Close();

			unsigned int Length() const;

			static const size_t READ_FAILED = 0xFFFFFFFF;

			static void SetAssetManager(AAssetManager* p_AssetManager)
			{
				n_asset_manager = p_AssetManager;
			}

		private:
			std::string 		  n_filename;
			static AAssetManager* n_asset_manager;
			AAsset*				  n_asset;
	};
}

#endif // __FILE_HPP__
#ifndef __TEXTURE_SHADER_HPP__
#define __TEXTURE_SHADER_HPP__

#include "shader.hpp"

#include "renderable.hpp"	// put these in the .cpp file
#include "texture.hpp"		// if the system acts up in accord

namespace Framework
{
	// class Texture;

	class TextureShader : public Shader
	{
		public:
			TextureShader();
			virtual ~TextureShader();

			virtual void Link();
			virtual void Setup(Renderable& renderable);

			void SetTexture(Texture* p_texture);

			Texture* GetTexture();

		private:
			Texture* n_pTexture;
			GLint    n_positionAttributeHandle;
			GLint    n_textCoordAttributeHandle;
			GLint 	 n_samplerHandle;	
	};
}

#endif // __TEXTURE_SHADER_HPP__
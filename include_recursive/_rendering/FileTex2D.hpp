#ifndef DCG_STBI_TEX_2D_INCLUDED
#define DCG_STBI_TEX_2D_INCLUDED

#include "util.hpp"

//#include "SOIL/SOIL.h"
#include "FreeImage.h"

#include <cstdint>
#include <algorithm>

namespace glob{

class BGRAImage2D : public GLImage2D{
public:
	struct Pixel{
		byte_t r, g, b, a;
		Pixel() : Pixel((byte_t) 0, (byte_t) 0, (byte_t) 0, (byte_t) 0) {}
		Pixel(byte_t r, byte_t g, byte_t b, byte_t a) :
			r(r), g(g), b(b), a(a)
		{}
	};
	int W, H;
	s_ptr<vector<Pixel>> pixels;

public:
	BGRAImage2D(s_ptr<vector<Pixel>> pixels, int W, int H) : 
		GLImage2D(W, H, ImageFormat::BGRA, PixelDataType::UNSIGNED_BYTE),
		//GLImage2D(W, H, BaseInternalFormat::RGBA, PixelDataType::UNSIGNED_BYTE),
		pixels(pixels),
		W(W),
		H(H)
	{
		assert(W*H == pixels->size());
	}

	BGRAImage2D(string filename) : 
		GLImage2D(0, 0, ImageFormat::BGRA, PixelDataType::UNSIGNED_BYTE)
	{
		FREE_IMAGE_FORMAT formato = FreeImage_GetFileType(filename.c_str(), 0);//Automatocally detects the format(from over 20 formats!)
		FIBITMAP* imagen = FreeImage_Load(formato, filename.c_str());
		//
		FIBITMAP* temp = imagen;
		imagen = FreeImage_ConvertTo32Bits(imagen);
		FreeImage_Unload(temp);
		//
		W = GLImage::dims[0] = FreeImage_GetWidth(imagen);
		H = GLImage::dims[1] = FreeImage_GetHeight(imagen);
		//
		void* bits = FreeImage_GetBits(imagen);
		pixels = make_shared<vector<Pixel>>(
			(Pixel*) bits,
			((Pixel*) bits) + (W*H)
		);
		//
		FreeImage_Unload(imagen);
	}

	virtual byte_t* getData(){ return((byte_t*) pixels->data()); }
};


class FileTex2D : public Texture2D{
private:
	s_ptr<BGRAImage2D> img;
	bool b_mipmap;

public:
	FileTex2D(Context& context, string filename, bool b_mipmap) : 
		Texture2D(context, SizedInternalFormat::RGBA8)
	{
		img = make_shared<BGRAImage2D>(filename);
		image();
	}

	//void bind(){ Texture2D::bind(); }
	//bool isBound(){ Texture2D::isBound(); }

private:
	void image(){
		Texture2D::image(img);
		//Texture2D::mipmap();
	}
};

}

#endif















































/*


namespace glob{

class RGBAImage2D : public GLImage2D{
public:
	struct Pixel{
		byte_t r, g, b, a;
		Pixel() : Pixel((byte_t) 0, (byte_t) 0, (byte_t) 0, (byte_t) 0) {}
		Pixel(byte_t r, byte_t g, byte_t b, byte_t a) :
			r(r), g(g), b(b), a(a)
		{}
	};
	int W, H;
	s_ptr<vector<Pixel>> pixels;

public:
	RGBAImage2D(s_ptr<vector<Pixel>> pixels, int W, int H) : 
		GLImage2D(W, H, BaseInternalFormat::RGBA, PixelDataType::UNSIGNED_BYTE),
		pixels(pixels),
		W(W),
		H(H)
	{
		assert(W*H == pixels->size());
	}

	RGBAImage2D(string filename) : 
		GLImage2D(0, 0, BaseInternalFormat::RGBA, PixelDataType::UNSIGNED_BYTE)
	{
		int channels;
		unsigned char* img = SOIL_load_image(
			filename.c_str(), 
			&W, &H, &channels,
			SOIL_LOAD_RGBA
		);
		assert(channels == 4);
		GLImage::dims[0] = W;
		GLImage::dims[1] = H;
		//
		pixels->resize(W*H);
		std::copy(pixels->begin(), pixels->begin() + (W*H), (Pixel*) img);
		//
		SOIL_free_image_data(img);
	}

	virtual byte_t* getData(){ return((byte_t*) pixels->data()); }
};

class SoilTex2D : private Texture2D{
private:
	s_ptr<RGBAImage2D> img;
	bool b_mipmap;

public:
	SoilTex2D(Context& context, string filename, bool b_mipmap) : 
		Texture2D(context, SizedInternalFormat::RGBA8)
	{
		img = make_shared<RGBAImage2D>(filename);
		image();
	}

	void bind(){ Texture2D::bind(); }
	bool isBound(){ Texture2D::isBound(); }

private:
	void image(){
		Texture2D::image(img);
		Texture2D::mipmap();
	}
};

}


*/




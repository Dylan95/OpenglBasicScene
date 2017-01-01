#ifndef DCG_OFFSCREEN_RENDERER_INCLUDED
#define DCG_OFFSCREEN_RENDERER_INCLUDED

#include "util.hpp"

namespace glob{

//used for rendering data offscreen and getting it into system memory.
/*class OffscreenRenderer{
public:
	Viewport* viewport;
private:
	FrameBuffer* fb;
	//
	uint W, H;
	uint maxW, maxH;
	//
	//short lastReadIndex;
	//unsigned short readIndex;
	//unsigned short renderIndex;

public:
	//OffscreenRenderer(uint W, uint H, TransRot cameraOrientation, vector<bool> activeLayers);
	OffscreenRenderer(
		uint W, 
		uint H, 
		Transform cameraOrientation, 
		vector<bool> activeLayers
	);

	byte_t* render();

	void resize(int W, int H);

	//

	uint getW(){ return(W); }
	uint getH(){ return(H); }
};*/

}

#endif

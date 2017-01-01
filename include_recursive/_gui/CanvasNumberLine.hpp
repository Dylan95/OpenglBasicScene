#ifndef DCG_NUMBER_LINE_INCLUDED
#define DCG_NUMBER_LINE_INCLUDED

#include "util.hpp"

namespace glob{

struct FloatLine{
	float start;
	float length;

	FloatLine(float start, float length){
		this->start = start;
		this->length = length;
	}

	float end(){
		return(start + length);
	}
};

class CanvasNumberLine{
private:
	float size;
	float usedArea;//area not taken by resizableAreas.
	std::vector<FloatLine> resizableAreas;//they don't overlap

public:
	CanvasNumberLine(float size){
		this->size = size;
		usedArea = 0;
		resizableAreas.push_back(FloatLine(0, size));
	}

	//removes any freespace between (start) and (start+length).
	void addLine(float start, float length){
		for(std::vector<FloatLine>::iterator it = resizableAreas.begin(); it != resizableAreas.end(); it++){
			float itEnd = it->end();
			//
			std::vector<FloatLine>::iterator newLineIt;
			bool b_startInside = inRange(start, it->start, it->end());
			bool b_endInside = inRange(start+length, it->start, it->end());
			//
			if((start < it->start) && (start+length > it->end())){
				usedArea += it->length;
				resizableAreas.erase(it);
			}
			else{
				if(b_startInside && b_endInside){
					usedArea += length;
					it->length = start - it->start;
					resizableAreas.insert(it+1, FloatLine(start+length, itEnd - (start+length)));
					break;
				}
				else if(b_startInside){
					usedArea += it->end() - start;
					it->length = it->start - start;
				}
				else if(b_endInside){
					usedArea += (start+length) - it->start;
					it->start = start+length;
					it->length = it->end() - it->start;
					break;
				}
			}
		}
	}

	//expands a line if it overlaps it.
	float getOverlap(float start, float length){
		float result = 0;
		//
		for(std::vector<FloatLine>::iterator it = resizableAreas.begin(); it != resizableAreas.end(); it++){
			bool b_startInside = inRange(start, it->start, it->end());
			bool b_endInside = inRange(start+length, it->start, it->end());
			//
			//cout << b_startInside << " " << b_endInside << endl;
			if((start < it->start) && (start+length > it->end())){
				result += it->length;
				//cout << "entire area\n";
			}
			else{
				if(b_startInside && b_endInside){
					//cout << "enclosed\n";
					result = length;
					break;
				}
				else if(b_startInside){
					result = it->end() - start;
					//cout << result << endl;
				}
				else if(b_endInside){
					result += start+length - it->start;
					break;
				}
			}
		}
		//cout << result << " " << length << endl;
		return(result);
	}

	//gets the amount of freespace before the start of the targeted area.
	float getFreespaceBefore(float start){
		float result = 0;
		//
		for(std::vector<FloatLine>::iterator it = resizableAreas.begin(); it != resizableAreas.end(); it++){
			if(it->start < start){
				if(it->end() <= start){
					result += it->length;
				}
				else{
					result += start - it->start;
				}
			}
		}
		return(result);
	}

	float getUsedArea(){
		return(usedArea);
	}

	float getFreeArea(){
		return(size - usedArea);
	}
};

}

#endif

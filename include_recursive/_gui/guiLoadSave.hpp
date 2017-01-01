#ifndef DCG_GUI_LOAD_SAVE_INCLUDED
#define DCG_GUI_LOAD_SAVE_INCLUDED

#include "util.hpp"

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"

namespace glob{

using rapidjson::Document;
using rapidjson::Value;
using rapidjson::GenericValue;
using rapidjson::SizeType;

void saveGui(string fileName);
void loadGui(string configFile);

}



#endif

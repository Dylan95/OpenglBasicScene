#include "guiLoadSave.hpp"
//
#include <stack>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cassert>
#include <stdio.h>
//
#include "Rect.hpp"
//
#include "rapidjson/document.h"
#include "rapidjson/error/error.h"

#include "dcg/dcg.hpp"

using namespace glob;

using rapidjson::Document;
using rapidjson::Value;
using rapidjson::GenericValue;
using rapidjson::SizeType;

char* json = NULL;

static float getFloat(const Value& value);
static const Value& getObject(const Value& data);
static int getInt(const Value& data);
static double getDouble(const Value& data);
static bool getBool(const Value& data);
namespace test{
static string getString(const Value& data);
static string getString(){return("");}
}


namespace dcg{
namespace gui{

const std::string CONTENT_PANE_COLOR = "color";
const std::string CONTENT_PANE_TERMINAL = "terminal";
const std::string CONTENT_PANE_OPENGL = "opengl";

void loadGui(string configFile){
}

static float getFloat(const Value& value){
	return((float) getDouble(value));
}

//
//example: getFloat(root["z"]);

}
}

static const Value& getObject(const Value& data){
	assert(data.IsObject());
	return(data);
}
static int getInt(const Value& data){
	assert(data.IsInt());
	return(data.GetInt());
}
static double getDouble(const Value& data){
	assert(data.IsDouble());
	return(data.GetDouble());
}
static bool getBool(const Value& data){
	assert(data.IsBool());
	return(data.GetBool());
}
static string getString(const Value& data){
	assert(data.IsString());
	return(data.GetString());
}

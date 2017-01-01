#ifndef GLOB_DIRTY_TARGET_INCLUDED
#define GLOB_DIRTY_TARGET_INCLUDED

#include "util.hpp"
#include <vector>

namespace glob{

namespace detail{

class BuildNode{
	bool b_dirty;
	//
	//beware of circular dependancies, this class will not check for them.
	//nodes that require this one to build.
	//references only, not responsible for ownership, be very carefull.
	std::vector<BuildNode*> targets;

public:
	BuildNode() : b_dirty(true) {}

	//since targets are stored as pointers to BuildNode,
	//BuildNode objects probably shouldn't be copied.
	//use shared pointers to them instead.
	BuildNode(const BuildNode& other) = delete;

	void addTarget(BuildNode* target){
		targets.push_back(target);
		markDirty();
	}

protected:
	void markDirty(){
		this->b_dirty = true;
		for(auto target : targets){ 
			//cout << "memory " << target << endl;
			if(! target->isDirty()){
				target->markDirty();
			}
		}
	}

	void markClean(){ this->b_dirty = false; }

public:
	bool isDirty(){ return(b_dirty); }
};

}


template<class T>
class BuildNode_t : public detail::BuildNode{
private:
	T val;

public:
	BuildNode_t() :
		detail::BuildNode()
	{}

	T getBuildVal(){
		if(detail::BuildNode::isDirty()){
			val = makeBuildVal();
			detail::BuildNode::markClean();
		}
		return(val); 
	}

protected:
	virtual T makeBuildVal() = 0;
};


//a leaf node that becomes dirty when assigned to something
//usefull for basic data types.
template<class T>
class BuildNode_Assign : public detail::BuildNode{
private:
	T val;

public:
	explicit BuildNode_Assign(T val) : 
		detail::BuildNode(),
		val(val)
	{
		detail::BuildNode::markClean();
	}

	//todo: assignment operator instead?
	void set(T val){
		this->val = val;
		detail::BuildNode::markDirty();
		detail::BuildNode::markClean();
	}
	//todo: () operator instead?
	const T& get(){
		return(val);
	}

	void operator=(T val){ return(set(val)); }
};

}

#endif























/*


















class BuildNode{
	bool b_dirty;

private:
	//beware of circular dependancies, this class will not check for them.
	//nodes that require this one to build.
	vector<BuildNode&> targets;
	//nodes that are needed for this one to build.
	vector<BuildNode&> dependancies;

protected:
	BuildNode(bool b_dirty = true) : b_dirty(b_dirty)
	{
		for(auto dep : dependancies){ dep.addTarget(*this); }
	}

	BuildNode(
		vector<BuildNode&> dependancies, 
		bool b_dirty = true
	) : 
		dependancies(dependancies), 
		b_dirty(b_dirty)
	{
		for(auto dep : dependancies){ dep.addTarget(*this); }
	}
	
	//should not be called by other classes
	void addTarget(BuildNode& target){ targets.push_back(target); }

	void addDependancy(BuildNode& dep){ 
		dependancies.push_back(dep);
		dep.addTarget(*this);
	}

	void markDirty(){
		this->b_dirty = true;
		for(auto target : targets){ 
			if(! node->isDirty()){
				dep->markDirty(b_dirty);
			}
		}
	}

	void buildAll(){
		if(b_dirty){
			this->b_dirty = false;
			for(auto dep : dependancies){ 
				if(target->isDirty()){
					target->buildAll();
				}
			}
			buildNode();
		}
	}
	
	virtual void buildNode() = 0;

	bool isDirty(){ return(b_dirty); }
};


template<class T>
class BuildNode_t : public BuildNode{
private:
	T val;

public:
	T getBuildVal(){ return(val); }

private:
	virtual T makeBuildVal() = 0;

	virtual buildNode(){
		val = makeBuildVal();
	}
};


class BuildNode_Leaf : public BuildNode{
public:
	BuildNode_Leaf(T t, bool b_dirty) : BuildNode({}, b_dirty) {}

private:
	virtual void buildNode(){}
};


//a leaf node that becomes dirty when assigned to something
template<class T>
class BuildNode_Assign : public BuildNode_Leaf{
protected:
	T t;

public:
	BuildNode_Value(T t, bool b_dirty) : t(t), BuildNode_Leaf(b_dirty) {}

	//implicit
	float operator=(float x) { 
		this->x = x;
		BuildNode::markDirty();
	}
	//implicit
	float operator(){ return(x); }
};





















//a leaf node that checks whether or not it's dirty by comparing
//it's value to it's last value.
class BuildNode_Compare
	bool initialized;
protected:
	T t;

public
	BuildNode_Value(T t, bool b_dirty) : t(t), BuildNode_Leaf(b_dirty) {}

	virtual bool isDirty(){
	
	}
}*/


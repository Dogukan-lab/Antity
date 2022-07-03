#pragma once
#include <map>
#include <string>
#include <memory>
#include "Model.h"

class ObjectLoader
{
public:

	static std::shared_ptr<Model> getModel(const std::string& fileName);

private:
	static std::map<std::string, std::shared_ptr<Model>> modelCache;
};
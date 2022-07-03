#include "ObjectLoader.h"

std::map<std::string, std::shared_ptr<Model>> ObjectLoader::modelCache = std::map<std::string, std::shared_ptr<Model>>();

std::shared_ptr<Model> ObjectLoader::getModel(const std::string& fileName)
{

	auto fileItem = modelCache.find(fileName);

	if (fileItem != modelCache.end()) return fileItem->second;

	auto model = std::make_shared<Model>(fileName);
	modelCache.insert({fileName, model});

	return model;
}

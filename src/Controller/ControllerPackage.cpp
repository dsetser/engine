#include "ControllerPackage.h"

ControllerPackage::ControllerPackage(GraphicsManager* const graphicsManager, InputManager* const inputManager, SoundManager* const soundManager)
: graphicsManager(graphicsManager),
inputManager(inputManager),
soundManager(soundManager)
{
	
}

ControllerPackage::~ControllerPackage()
{
	delete this->graphicsManager;
	delete this->inputManager;
	delete this->soundManager;
}

GraphicsManager* const ControllerPackage::GetGraphicsManager()
{
	return this->graphicsManager;
}


InputManager* const ControllerPackage::GetInputManager()
{
	return this->inputManager;
}

SoundManager* const ControllerPackage::GetSoundManager()
{
	return this->soundManager;
}

void ControllerPackage::CopyFrom(ControllerPackage* copy)
{
	this->graphicsManager->CopyFrom(copy->graphicsManager);
	this->inputManager->CopyFrom(copy->inputManager);
	this->soundManager->CopyFrom(copy->soundManager);
}
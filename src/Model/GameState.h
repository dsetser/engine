#ifndef Core_GameState_h
#define Core_GameState_h

#include "GameStateManager.h"
class GameStateManager;

/**
 * Contains logic for managing underlying functions used by the GameStateManager
 * for management of states.  When these virtual methods are overriden, the base
 * should ALWAYS be called at the beginning of the method.
 *
 * Currently provides nothing special.
 */
class GameState
{
public:
    /**
     * Initializes the GameState with the given GameStateManager.
     */
    virtual void Initialize(GameStateManager* manager, ControllerPackage* controllerPackage)
    {
        this->manager = manager;
		this->controllerPackage = controllerPackage;
    }
    
    /**
     * Updates this State.
     */
	virtual void Update() = 0;
    
    /**
     * Pauses this State to be resumed later.
     */
    virtual void Pause() { }
    
    /**
     * Resumes this State after being paused.
     */
    virtual void Resume() { }
    
    /**
     * Destroys this State because it won't be used again.
     */
    virtual void Destroy() { }
    
protected:
    /**
     * The GameStateManager managing this State.
     */
    GameStateManager* manager;

	/**
	 * Pointer to the ControllerPackage for the state
	 */
	ControllerPackage* controllerPackage;
    
};

#endif
#ifndef Core_Controller_h
#define Core_Controller_h

#include <GLFW/glfw3.h>
#include <algorithm>
#include <thread>

#include "GraphicsView.h"
#include "GameStateManager.h"
#include "InitialState.h"
#include "ControllerPackage.h"

class Controller
{
public:
    /**
     * Default constructor that creates a new instance of a Controller.
     */
    Controller();
    
    /**
     * Starts the game. Initializes systems and starts updating them.
     */
    void Start();

	void SetCP(ControllerPackage* cp)
	{
		this->controllerPackage = cp;
	}
    
private:
    // Private constructors to disallow access.
    Controller(Controller const &other);
    Controller operator=(Controller other);
    
    /**
     * The method that udpates all game logic.
     */
    void gameLoop();
    
    /**
     * Helper method that initializes the GLFW window.
     */
    GLFWwindow* initializeGraphics();
    
    /**
     * The method that updates the GraphicsView.
     */
    void graphicsLoop(GLFWwindow* window);
    
    /**
     * How quickly the game logic updates. 1 over the number of updates per second.
     */
    const double UPDATE_RATE = 1 / 60.0;
    
    /**
     * How quickly the graphics are updated. 1 over the number of frames per second.
     */
    const double FRAMERATE = 1 / 60.0;

    /**
     * Boolean that represents whether the game should exit or not.
     */
    bool shouldExit;
    
	/**
	 * The package containing all the data owned by the controller
	 */
	ControllerPackage* controllerPackage;
};

#endif

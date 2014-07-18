#ifndef Common_InputManager_h
#define Common_InputManager_h

#include "InputView.h"
#include "IKeyPressEventHandler.h"
#include "IKeyReleaseEventHandler.h"
#include "InputState.h"
#include "InputCode.h"
#include "vector"
#include "unordered_map"
#include "set"

class InputView;
class KeyPressEvent;
class KeyReleaseEvent;
class InputManager : IKeyPressEventHandler, IKeyReleaseEventHandler
{
public:

    /**
     * Default constructor that creates a new instance of a InputManager.
     */
    InputManager();

    /**
     * Associate an InputView with this InputManager. The InputView specified here will fire input
     * events to this InputManager and will be used to poll input state. 
     * Only one InputView may be associated with an InputManager at a time.
     */
    void SetView(InputView* inputView);

    /**
     * Register a KeyPressEventHandler to receive KeyPressEvents.
     * @param[in] handler Pointer to the KeyPressEventHandler to register. If
     * the handler does not have an existing registration with this InputManager,
     * a new registration will be created. If the handler has an existing 
     * registration with this InputManager, the existing registration will be modified.
     * @param[in] keyCodes Vector of key codes corresponding to keyboard keys
     * that should cause KeyPressEvents to be fired when pressed. If the handler does not
     * have an existing registration with this InputManager, the new registration will
     * be initialized with the contents of this vector. If the handler has an existing
     * registration with this InputManager, the registration will be updated with the 
     * set union of the contents of this vector and the key codes in the existing
     * registration.
     */
    void RegisterKeyPressEventHandler(IKeyPressEventHandler* handler, std::vector<KeyCode> keyCodes);

    /**
     * Deregister a KeyPressEventHandler which will no longer receive KeyPressEvents.
     * @param[in] handler Pointer to the KeyPressEventHandler to deregister. 
     * If the handler does not have an existing registration with this InputManager, 
     * this function has no effect. 
     * @param[in] keyCodes Vector of key codes corresponding to keyboard keys
     * that should no longer cause KeyPressEvents to be fired when pressed. If the handler
     * has an existing registration with this InputManager, the registration will be updated
     * with the relative complement of the contents of this vector with respect to the key codes
     * in the existing registration. If the result of this operation is an empty set, the handler's
     * registration will be removed from this InputManager.
     */
    void DeregisterKeyPressEventHandler(IKeyPressEventHandler* handler, std::vector<KeyCode> keyCodes);

    /**
     * Register a KeyReleaseEventHandler to receive KeyReleaseEvents.
     * @param[in] handler Pointer to the KeyReleaseEventHandler to register. If
     * the handler does not have an existing registration with this InputManager,
     * a new registration will be created. If the handler has an existing 
     * registration with this InputManager, the existing registration will be modified.
     * @param[in] keyCodes Vector of key codes corresponding to keyboard keys
     * that should cause KeyReleaseEvents to be fired when released. If the handler does not
     * have an existing registration with this InputManager, the new registration will
     * be initialized with the contents of this vector. If the handler has an existing
     * registration with this InputManager, the registration will be updated with the 
     * set union of the contents of this vector and the key codes in the existing
     * registration.
     */
    void RegisterKeyReleaseEventHandler(IKeyReleaseEventHandler* handler, std::vector<KeyCode> keyCodes);

    /**
     * Deregister a KeyReleaseEventHandler which will no longer receive KeyReleaseEvents.
     * @param[in] handler Pointer to the KeyReleaseEventHandler to deregister. 
     * If the handler does not have an existing registration with this InputManager, 
     * this function has no effect. 
     * @param[in] keyCodes Vector of key codes int values corresponding to keyboard keys
     * that should no longer cause KeyReleaseEvents to be fired when released. If the handler
     * has an existing registration with this InputManager, the registration will be updated
     * with the relative complement of the contents of this vector with respect to the key codes
     * in the existing registration. If the result of this operation is an empty set, the handler's
     * registration will be removed from this InputManager.
     */
    void DeregisterKeyReleaseEventHandler(IKeyReleaseEventHandler* handler, std::vector<KeyCode> keyCodes);

    /**
     * Poll the current state of a key.
     * @param keyCode Key code corresponding to a keyboard key.
     * @return InputState indicating the current state of a key.
     * If an invalid key code was passed, KeyState::Invalid is returned.
     */
    InputState GetKeyState(KeyCode keyCode);

    void OnKeyPressEvent(KeyPressEvent* event);

    void OnKeyReleaseEvent(KeyReleaseEvent* event);

    void Update();

private:
    // Private constructors to disallow access.
    InputManager(InputManager const &other);
    InputManager operator=(InputManager other);

    // InputView which fires input events.
    InputView* inputView;
   
    // Maps of registered keys and their associated handlers. 
    // C++ strong enums are not usable as map keys, so a cast to int is required.
    std::unordered_map<int, std::set<IKeyPressEventHandler*>> registeredKeyPressEventHandlers;
    std::unordered_map<int, std::set<IKeyReleaseEventHandler*>> registeredKeyReleaseEventHandlers;
};

#endif

#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"

// forward declaration of classes
namespace PlayFab
{
    class UPlayFabAdminAPI;
}

typedef TSharedPtr<class PlayFab::UPlayFabAdminAPI> PlayFabAdminPtr;

/**
* The public interface to this module.  In most cases, this interface is only public to sibling modules
* within this plugin.
*/
class IPlayFabAdminModuleInterface : public IModuleInterface
{
public:

    /**
    * Singleton-like access to this module's interface.  This is just for convenience!
    * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
    *
    * @return Returns singleton instance, loading the module on demand if needed
    */
    static inline IPlayFabAdminModuleInterface& Get()
    {
        return FModuleManager::LoadModuleChecked< IPlayFabAdminModuleInterface >("PlayFabAdmin");
    }

    /**
    * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
    *
    * @return True if the module is loaded and ready to use
    */
    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("PlayFabAdmin");
    }
  
    virtual PlayFabAdminPtr GetAdminAPI() const = 0;
};

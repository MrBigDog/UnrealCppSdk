# Unreal 4 C++ SDK for PlayFab README

!!WARNING!!

THIS SDK HAS BEEN DISCONTINUED!

Please switch to the [UnrealBlueprintSDK](https://github.com/PlayFab/UnrealBlueprintSDK) using our [Upgrade Guide](https://github.com/PlayFab/UnrealBlueprintSDK/blob/master/UnrealCppSdkUpgradeGuide.md)

This repository will be made private and/or deleted at an unspecified point in the future.  It is also no longer updated with the latest PlayFab API changes, and it does not support Unreal versions greater than 4.15 (meaning it's two versions out of date).

## 1. Overview:

Unreal 4.9, 4.12, 4.13, 4.14, 4.15 C++ SDKs for PlayFab

The Unreal C++ SDK includes:

* PlayFabSDK Folder: Unreal SDK-Plugin - Put this plugin in your new or existing project to utilize PlayFab
* ExampleProject Folder: Unreal SDK ExampleProject - Use this project to start your new game, or demo/test the PlayFab system.

This sdk contains a settings option to set developerSecretKey.  For the security of your title, this must be blank for client builds.


## 2. Prerequisites:

* Users should be very familiar with the topics covered in our [getting started guide](https://api.playfab.com/docs/general-getting-started).

To connect to the PlayFab service, your machine must be running TLS v1.2 or better.
* For Windows, this means Windows 7 and above
* [Official Microsoft Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/aa380516%28v=vs.85%29.aspx)
* [Support for SSL/TLS protocols on Windows](http://blogs.msdn.com/b/kaushal/archive/2011/10/02/support-for-ssl-tls-protocols-on-windows.aspx)


## 3. Installation:

The following instructions apply to each of the three SDKs provided in the Unreal SDK-Collection.

Assumptions

* Windows operating system
* [Microsoft Visual Studio](https://www.visualstudio.com/en-us/products/visual-studio-community-vs.aspx) already installed
* [Unreal Engine](https://www.unrealengine.com/dashboard) already installed

A new project can be built directly from the example project included with each SDK:

* Extract the Unreal SDK package to {UnrealPackageLocation}
* Navigate to {UnrealPackageLocation}/ExampleProject
* Right click on ExampleProject.uproject, and "Generate Visual Studio project files" - This process may take several minutes
* Once finished, open {UnrealPackageLocation}/PlayFabClientSDK/ExampleProject/ExampleProject.sln in Visual Studio
* In Visual Studio, "Rebuild Solution" - This process may take several minutes
* You should now be able to utilize the PlayFab API

Existing Projects:
* Extract the Unreal SDK package to {UnrealPackageLocation}
* Navigate to {UnrealPackageLocation}/PlayFabSDK
* Copy the PlayFab folder into the "Plugins" directory in your existing Unreal project (If the "Plugins" folder does not exist, create it)
* Right click on ExampleProject.uproject, and "Generate Visual Studio project files" - This process may take several minutes
* Once finished, open your *.sln project file with Visual Studio
* In Visual Studio, "Rebuild Solution" - This process may take several minutes
* You should now be able to utilize the PlayFab API

Once the plugin is properly installed, run the Unreal Engine environment editor.
Navigate to the dropdown menus:  Edit -> Project Settings
On the left menu, scroll to the bottom, find Plugins -> PlayFab
Fill in the TitleId with the approriate value from your project, found in the PlayFab [Game Manager](https://developer.playfab.com/en-us/studios)
If this is a server process, you can also fill in the developerSecretKey.  For the security of your title, this must be blank for client builds.


## 4. Troubleshooting:

If you experience this error:
Plugin 'PlayFab' failed to load because module 'PlayFab' could not be found.  Please ensure the plugin is properly installed, otherwise consider disabling the plugin for this project.

Your Unreal project is not set up to be a C++ project.  Here is a tutorial that will help fix this problem.
http://idkudk.blogspot.com/2015/02/how-to-get-plugins-to-package-correctly.html


General troubleshooting:

For a complete list of available APIs, check out the [online documentation](http://api.playfab.com/Documentation/).

#### Contact Us
We love to hear from our developer community!
Do you have ideas on how we can make our products and services better?

Our Developer Success Team can assist with answering any questions as well as process any feedback you have about PlayFab services.

[Forums, Support and Knowledge Base](https://community.playfab.com/index.html)


## 5. Acknowledgements

The PlayFab Unreal C++ SDK was built by [Phoenix Labs](http://www.phoenixlabs.ca/), and submitted to PlayFab November, 2015


## 6. Copyright and Licensing Information:

  Apache License --
  Version 2.0, January 2004
  http://www.apache.org/licenses/

  Full details available within the LICENSE file.


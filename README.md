# HideUI
Hides most UI labels on a keypress. If there is one that is not hidden, download https://geode-sdk.org/mods/geode.devtools, then press F11 while in a level (it also works while paused), and find where the UI element is. It will likely be somewhere under PlayLayer. Once you think you found it, click on attributes, check the visible checkbox, and see if it disappears. If it does, then share that on the github for this mod. 

This mod also provides an API to allow other mods to hide the UI. To use this, first put 
```	
    "dependencies": {
        "legowiifun.hide_ui": {
			"version": ">=1.2.0",
			"importance": "required"
		}
	}
```
in mod.json. Then, at the top of your code, put 
```
#include<legowiifun.hide_ui/src/api/hideUIAPI.hpp>
```
Finally, in the method itself, where you want to use the API, put
```
hideUIAPI::toggleUI();
```
This will toggle the UI when the method call is reached. You can check the visible properties of the various affected nodes if you specifically need them toggled on or off
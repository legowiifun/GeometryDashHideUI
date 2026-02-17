# HideUI
Hides most UI labels on a keypress. If there is one that is not hidden, download https://geode-sdk.org/mods/geode.devtools, then press F11 while in a level (it also works while paused), and find where the UI element is. It will likely be somewhere under PlayLayer. Once you think you found it, click on attributes, check the visible checkbox, and see if it disappears. If it does, then share that on the github for this mod. 

This mod also provides an API to allow other mods to hide the UI. To use this, first put 
```	
    "dependencies": {
        "legowiifun.hide_ui": {
			"version": ">=1.3.0",
			"required": true
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
This will toggle the UI when the method call is reached. There are also methods to turn it on or off no matter what. 
```
hideUIAPI::turnOffUI();
hideUIAPI::turnOnUI();
```

If you are a mod developer adding an object to the UI, and you want it to be automatically hidden, there are two approaches. First, you can put it in UILayer. This is automatically hidden. There is also an optional API you can use. 
First put 
```	
    "dependencies": {
        "legowiifun.hide_ui": {
			"version": ">=1.3.0",
			"required": false
		}
	}
```
in your mod.json. If you are already using the full dependency, this step is not needed. 

Next, at the top of your file, put 
```
#include<legowiifun.hide_ui/src/api/hideUIAPI.hpp>
```
Then, after creating your UI element, make sure it has a Node ID using this code
```
node->setID("MyNode"_spr);
```
Finally, use the API to add it to the list. 
```
hide_ui_events::addUIElementEvent(node->getID(), "PlayLayer");
```
What you put in the second parameter depends on where your node is. If it is a direct child of PlayLayer, put "PlayLayer". If it is a sibling, or a child of a sibling of PlayLayer, put "Sibling". If it is nested within a child of PlayLayer, put "Nested".

Examples of both of these APIs can be found here: https://github.com/legowiifun/Geometry-Dash-API-Test
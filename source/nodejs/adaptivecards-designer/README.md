# Adaptive Card Designer (Beta)

The Adaptive Card Designer provides a rich, interactive design-time experience for authoring [adaptive cards](https://adaptivecards.io). 

Try it out at [https://adaptivecards.io/designer](https://adaptivecards.io/designer)

![Designer Screenshot](https://adaptivecards.io/images/designer.png)

## What is this package?

This package allows you to easily integrate the adaptive cards designer into your own experiences. 

## Beta notice 

**NOTE**: The designer is currently considered beta and **may have breaking changes** in the public API as we get feedback.

## Usage

There are two simple ways to consume the designer: CDN script reference or importing the module and using webpack.

### Option 1: CDN script references

The simplest way to get started it to include 3 script tags in your page. 

1. **monaco-editor** - provides a rich JSON-editing experience
2. **markdown-it** - [optional] automatic markdown support for the designer and cards

To load the designer component you have 2 options:

3. 
   * **adaptivecards-designer** - the designer component, with default Microsoft hosts included (Teams, Outlook, Cortana, etc)
   * **adaptivecards-designer-standalone** - the standalone designer component, without any standard Host Config containers

```html
<!-- OPTIONAL: markdown-it isn't required but enables out-of-the-box markdown support -->
<script src="https://unpkg.com/markdown-it@8.4.0/dist/markdown-it.min.js"></script>

<!-- REQUIRED: monaco-editor is required for the designer to work -->
<script src="https://unpkg.com/monaco-editor@0.17.1/min/vs/loader.js"></script>

<!-- DESIGNER OPTION A: Card Designer + Standard Hosts -->
<script src="https://unpkg.com/adaptivecards-designer@0.7.0/dist/adaptivecards-designer.min.js"></script>

<!-- DESIGNER OPTION B: Standalone Card Designer, without standard Hosts -->
<!--<script src="https://unpkg.com/adaptivecards-designer@0.7.0/dist/adaptivecards-designer-standalone.min.js"></script>-->

<script type="text/javascript">
	window.onload = function() {

		let hostContainers = [];

		// Optional: add the default Microsoft Host Apps (see docs below)
		// hostContainers.push(new ACDesigner.WebChatContainer("Bot Framework WebChat", "containers/webchat-container.css"));
		 
		let designer = new ACDesigner.CardDesigner(hostContainers);

		// The designer requires various CSS and image assets to work properly, 
		// If you've loaded the script from a CDN it needs to know where these assets are located
		designer.assetPath = "https://unpkg.com/adaptivecards-designer@0.7.0/dist";

		// Initialize monaco-editor for the JSON-editor pane. The simplest way to do this is use the code below
		require.config({ paths: { 'vs': 'https://unpkg.com/monaco-editor@0.17.1/min/vs' } });
		require(['vs/editor/editor.main'], function () {
			designer.monacoModuleLoaded();
		});

		designer.attachTo(document.getElementById("designerRootHost"));
	};
</script>

<body>
   <div id="designerRootHost"></div>
</body>
```

### Option 2: Node + webpack

If you already use webpack and want to to bundle the designer, you need a few packages. **adaptivecards-designer**, **monaco-editor** for the JSON editor, and **markdown-it** for markdown handling. You can use another markdown processor if you choose.

```console
npm install adaptivecards-designer monaco-editor markdown-it
```

You also need some development dependencies to bundle monaco, and copy some CSS+image files into your output.

```console
npm install copy-webpack-plugin monaco-editor-webpack-plugin css-loader style-loader
```

Then in your app, use the following imports and API. The code below was authored in TypeScript, but can be easily modified to plain JS. 

```js
import * as monaco from "monaco-editor";
import * as markdownit from "markdown-it";
import * as ACDesigner from "adaptivecards-designer";

// if you want to bundle the designer CSS using something like mini-css-loader:
import "adaptivecards-designer/dist/adaptivecards-designer.css";

// Uncomment below if you choose to pass an empty hostContainers array
//import "adaptivecards-designer/dist/adaptivecards-defaulthost.css";

window.onload = function() {

	ACDesigner.CardDesigner.onProcessMarkdown = (text, result) => {
		result.outputHtml = new markdownit().render(text);
		result.didProcess = true;
	}

	let hostContainers = [];
	hostContainers.push(new ACDesigner.WebChatContainer("Bot Framework WebChat", "containers/webchat-container.css"));

	let designer = new ACDesigner.CardDesigner(hostContainers);
	designer.attachTo(document.getElementById("designerRootHost"));
	designer.monacoModuleLoaded(monaco);
};

```

#### Webpack.config.js

The following plugins and configuration should be enough to boostrap the designer and dependencies.

* **monaco-editor-webpack-plugin** - makes it easy to use monaco with webpack
* **copy-webpack-plugin** [OPTIONAL] - If you use any of the default Host Configs, then the designer requires a few CSS and image assets be available. This plugin as described below copies them from the designer package into your output bundle

```js
...
const MonacoWebpackPlugin = require('monaco-editor-webpack-plugin');
const CopyWebpackPlugin = require('copy-webpack-plugin');

module.exports = {
	...
	module: {
		rules: [
			{
				test: /\.css$/,
				use: [
					'style-loader',
					'css-loader'
				]
			}
		]
	},
	plugins: [
		new CopyWebpackPlugin([{
			from: 'node_modules/adaptivecards-designer/dist/containers/*',
			to: 'containers/',
			flatten: true
		}]),
		new MonacoWebpackPlugin({
			languages: ['json']
		})
	]
};
```

## Open Sample button

The Designer makes it easy to load a sample from a catalog. Simply create a file on your web host with the following structure

```json
[
	{
		"displayName": "My Sample Payload",
		"cardPayloadUrl": "url/to/the/payload.json"
	}
]
```

And then set the `sampleCatalogueUrl` to the location of that file:

```js
	/* Configure "Open Sample" tooobar button */
	designer.sampleCatalogueUrl = window.location.origin + "/sample-catalogue.json";
```

If you don't want to load via a sample, you can hide the toolbar button

```js
	/* Hide the "Open Sample" toolbar button */
	designer.toolbar.getElementById(ACDesigner.CardDesigner.ToolbarCommands.OpenPayload).isVisible = false;
```

## Advanced configuration

For advanced configuration of the designer use the following APIs.

```js

    // Configure toolbox titles
    ACDesigner.Strings.toolboxes.cardEditor.title = "Custom card editor title";
    ACDesigner.Strings.toolboxes.cardStructure.title = "Custom card structure title";
    ACDesigner.Strings.toolboxes.dataStructure.title = "Custom data structure title";
    ACDesigner.Strings.toolboxes.propertySheet.title = "Custom property sheet title";
    ACDesigner.Strings.toolboxes.sampleDataEditor.title = "Custom sample data editor title";
    ACDesigner.Strings.toolboxes.toolPalette.title = "Custom tool palette title";

	/* Add the default Microsoft Host Apps 	*/ 
 
	hostContainers.push(new ACDesigner.WebChatContainer("Bot Framework WebChat", "containers/webchat-container.css"));
	hostContainers.push(new ACDesigner.CortanaContainer("Cortana Skills", "containers/cortana-container.css"));
	hostContainers.push(new ACDesigner.OutlookContainer("Outlook Actionable Messages", "containers/outlook-container.css"));
	hostContainers.push(new ACDesigner.TimelineContainer("Windows Timeline", "containers/timeline-container.css"));
	hostContainers.push(new ACDesigner.DarkTeamsContainer("Microsoft Teams - Dark", "containers/teams-container-dark.css"));
	hostContainers.push(new ACDesigner.LightTeamsContainer("Microsoft Teams - Light", "containers/teams-container-light.css"));
	hostContainers.push(new ACDesigner.BotFrameworkContainer("Bot Framework Other Channels (Image render)", "containers/bf-image-container.css"));
	hostContainers.push(new ACDesigner.ToastContainer("Windows Notifications (Preview)", "containers/toast-container.css"));


	/* Modify the toolbar */
    let myButton = new Designer.ToolbarButton(
        "myButton",
        "My button",
        null,
        (sender) => { alert("My button was clicked"); });
    myButton.separator = true;
    designer.toolbar.insertElementAfter(myButton, Designer.CardDesigner.ToolbarCommands.HostAppPicker);

	/* Collapse certain panes by default (BEFORE designer attached)	*/
	designer.treeViewPane.collapse();
	designer.jsonEditorPane.collapse();
	

	/* Set the card payload in the designer: (AFTER designer attached) */ 
	designer.setCard(
		{
			type: "AdaptiveCard",
			version: "1.0",
			body: [
				{
					type: "TextBlock",
					text: "Hello world"
				}
			]
		}
	);
};
```
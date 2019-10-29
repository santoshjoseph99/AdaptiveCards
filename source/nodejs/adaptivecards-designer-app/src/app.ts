// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
import * as monaco from "monaco-editor";
import * as markdownit from "markdown-it";
import * as ACDesigner from "adaptivecards-designer";
import "adaptivecards-designer/dist/adaptivecards-designer.css";
import "./app.css";

// Uncomment below if you plan to use an empty hostContainers array
// import "adaptivecards-designer/dist/adaptivecards-defaulthost.css";

window.onload = function() {
    // Uncomment to enabled preview features such as data binding
    /*
    ACDesigner.GlobalSettings.showVersionPicker = true;
    ACDesigner.GlobalSettings.enableDataBindingSupport = true;
    // Note the below two flags are ignored if enableDataBindingSupport is set to false
    ACDesigner.GlobalSettings.showDataStructureToolbox = true;
    ACDesigner.GlobalSettings.showSampleDataEditorToolbox = true;
    */

    // Uncomment to configure default toolbox titles
    /*
    ACDesigner.Strings.toolboxes.cardEditor.title = "Custom title";
    ACDesigner.Strings.toolboxes.cardStructure.title = "Custom title";
    ACDesigner.Strings.toolboxes.dataStructure.title = "Custom title";
    ACDesigner.Strings.toolboxes.propertySheet.title = "Custom title";
    ACDesigner.Strings.toolboxes.sampleDataEditor.title = "Custom title";
    ACDesigner.Strings.toolboxes.toolPalette.title = "Custom title";
    */

	ACDesigner.CardDesigner.onProcessMarkdown = (text: string, result: { didProcess: boolean, outputHtml: string }) => {
		result.outputHtml = new markdownit().render(text);
		result.didProcess = true;
	}

	if (!ACDesigner.SettingsManager.isLocalStorageAvailable) {
		console.log("Local storage is not available.");
	}

	let hostContainers: Array<ACDesigner.HostContainer> = [];
	hostContainers.push(new ACDesigner.WebChatContainer("Bot Framework WebChat", "containers/webchat-container.css"));
	hostContainers.push(new ACDesigner.CortanaContainer("Cortana Skills", "containers/cortana-container.css"));
	hostContainers.push(new ACDesigner.OutlookContainer("Outlook Actionable Messages", "containers/outlook-container.css"));
	hostContainers.push(new ACDesigner.TimelineContainer("Windows Timeline", "containers/timeline-container.css"));
	hostContainers.push(new ACDesigner.DarkTeamsContainer("Microsoft Teams - Dark", "containers/teams-container-dark.css"));
	hostContainers.push(new ACDesigner.LightTeamsContainer("Microsoft Teams - Light", "containers/teams-container-light.css"));
	hostContainers.push(new ACDesigner.BotFrameworkContainer("Bot Framework Other Channels (Image render)", "containers/bf-image-container.css"));
	hostContainers.push(new ACDesigner.ToastContainer("Windows Notifications (Preview)", "containers/toast-container.css"));

    let designer = new ACDesigner.CardDesigner(hostContainers);

    designer.sampleCatalogueUrl = window.location.origin + "/sample-catalogue.json";
    designer.attachTo(document.getElementById("designerRootHost"));
    
    /* Uncomment to test a custom palette item example
    let exampleSnippet = new ACDesigner.SnippetPaletteItem("Custom", "Example");
    exampleSnippet.snippet = {
        type: "ColumnSet",
        columns: [
            {
                width: "auto",
                items: [
                    {
                        type: "Image",
                        size: "Small",
                        style: "Person",
                        url: "https://pbs.twimg.com/profile_images/3647943215/d7f12830b3c17a5a9e4afcc370e3a37e_400x400.jpeg"
                    }
                ]
            },
            {
                width: "stretch",
                items: [
                    {
                        type: "TextBlock",
                        text: "John Doe",
                        weight: "Bolder",
                        wrap: true
                    },
                    {
                        type: "TextBlock",
                        spacing: "None",
                        text: "Additional information",
                        wrap: true
                    }
                ]
            }
        ]
    };

    designer.customPaletteItems = [ exampleSnippet ];
    */

	designer.monacoModuleLoaded(monaco);

	let sampleData = {
		firstName: "John",
		lastName: "Doe",
		age: 45,
		isMarried: true,
		address: {
			street: "1234 555th Ave NE",
			city: "Redmond",
			state: "WA",
			countryOrRegion: "USA"
		},
		children: [
			{
				firstName: "Jennifer",
				lastName: "Doe",
				age: 9
			},
			{
				firstName: "James",
				lastName: "Doe",
				age: 13
			}
		]
	};
	
	designer.dataStructure = ACDesigner.FieldDefinition.create(sampleData);
	designer.sampleData = sampleData;
}

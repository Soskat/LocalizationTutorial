# Localization Dashboard overview
On this page you can find broader explanation of the Localization Dashboard itself and its elements. If you need just a quick guide for setting up localization in your project, see the page [Setting up localization for your project](Setting-up-localization-for-your-project).

---
## What is the Localization Dashboard?
The Localization Dashboard is an editor window, where you can mange manage settings of localization targets that your project uses.

Localization Dashboard window consists of two parts: 
- a left-side column **(A)**, where you can create, delete and manage globally all existing localization targers
- a right-side column **(B)**, where you can edit settings of the selected localization targets.

![alt text](localization_dashboard_window.png "Localization Dashboard window.")

---
## Adding a new localization target
If your project needs localization, you will have to create a new localization target that enable you to gather localizable texts and manage their translations. You can choose between two separate categories of localization targets: **game** targets and **editor** ones. Generally there's no difference between them, however you should rather go with the game category for clarity.

![alt text](localization_dashboard_adding_new_target.png "Options for creating new and managing existing localization targets.")

In order to add a new localization target to the project, you need to click on the `Add New Target` button at the bottom of targets section. This will add a new entry in the list of existing targets. You can have a few separated localization targets at the same time. This might be helpful while working on some DLCs for which you have separated localization data.

In this section you can also perform a bulk operations on all existing localization targets. You can execute them by using buttons above the list with targets.

---
## Target settings
In this section you can change localization target name and its loading policy.

![alt text](localization_dashboard_target.png "Target general settings.")

Loading policy determines when that specific localization target should be used. Available options here are: *Never*, *Always*, *Editor*, *Game*, *Property Names* and *Tooltips*. From the game project perspective you can go either with *Always* or *Game*.

---
## Gather texts
This section contains various settings for the text gatherer program. This program searches all specified locations with text files and packages in order to collect all localizable texts. All collected texts, along with some localization related data, are then stored inside a `[localization_target_name].manifest` file, that you can find inside *Content/Localization/[localization_target_name]* folder. The `*.manifest` file is a json file with some custom formatting, that can be read by Unreal class `FTextLocalizationResourceGenerator`.

<p>
<details>
<summary>Click here to see an example *.manifest file (SomeDLC.manifest).</summary>
<pre><code>
{
	"FormatVersion": 1,
	"Namespace": "",
	"Subnamespaces": [
		{
			"Namespace": "Cpp_Namespace_3",
			"Children": [
				{
					"Source":
					{
						"Text": "This is the third text literal created in code."
					},
					"Keys": [
						{
							"Key": "Cpp_TextLiteral_3",
							"Path": "Source/LocalizationTutorial/SomeDLC/LocMacroSomeDLCExampleWidget.cpp:12"
						}
					]
				}
			]
		},
		{
			"Namespace": "ST_Shapes",
			"Children": [
				{
					"Source":
					{
						"Text": "circle"
					},
					"Keys": [
						{
							"Key": "st_cpp_shapes_circle",
							"Path": "Localization/StringTablesCSV/ST_Shapes.csv",
							"MetaData":
							{
								"Info":
								{
									"Comments": "This is a circle."
								}
							}
						}
					]
				},
				{
					"Source":
					{
						"Text": "rectangle"
					},
					"Keys": [
						{
							"Key": "st_cpp_shapes_rectangle",
							"Path": "Localization/StringTablesCSV/ST_Shapes.csv",
							"MetaData":
							{
								"Info":
								{
									"Comments": "This is a rectangle."
								}
							}
						}
					]
				}
			]
		}
	]
}
</code></pre>
</details></p>

### Gather from Text Files

![alt text](localization_dashboard_gather_from_text.png "Gather from Text Files settings.")

In case of Text Files, the Text Gatherer program will be searching for all uses of the localization macros (we're talking about `LOCTEXT` and `LOCTABLE` macro families) - and **ONLY** those macros. If you use directly `FStringTableRegistry::Internal_LocTableFromFile` function for creating CSV-based String Tables, **those function calls won't be recognized, therefore texts from those Sting Tables won't be gathered**.

`Search Directories` - here you can specify in which directories Text Gatherer should look for localizable texts. You can also specify which directories should be excluded from search in `Exclude Path Wildcards` setting. In `File Extensions` section contains all file types, that should be analysed - `*.h`, `*.cpp` and `*.ini` extensions are listed here as default ones.

### Gather from Packages

![alt text](localization_dashboard_gather_from_packages.png "Gather from Packages settings.")

In case of gathering texts from packages, the Text Gatherer will be searching all FText properies with text content set to localizable.

As you can see, this section is similar to the previous one for Text Files, but contains some asset-related options. In most cases you don't need to edit any settings other than `Include Path Wildcards` (aka `Search Directories` from previous section) and `Exclude Path Wildcards`. In `File Extensions` setting the default file types are: `*.umap` and `*.uasset`.

---
## Export Text
This section is dedicated for settings used when you export gathered text data to a PO file. You don't need to change anything here. In fact, you might never use this export text option.

![alt text](localization_dashboard_export_text.png "Export Text settings.")

---
## Compile Text
Here you can find some checkboxes for enabling/disabling additional logic used during compiling text data into localization binaries. All three properties have self-explanatory tooltips. You can leave here default values.

![alt text](localization_dashboard_compile_text.png "Compile Text settings.")

---
## Import Dialogue
This section is dedicated for setting up localization for dialogue audio files. The localizing dialogues topis is covered in page [Localizing Dialogues](../6_LocalizingDialogues/Localizing-Dialogues-in-Unreal.md).

![alt text](localization_dashboard_import_dialogue.png "Import Dialogue settings.")

---
## Cultures
Along with Text Gatherer settings, this section is the most important and useful part of the Localization Dashboard, as here you can specify which cultures will be used in your project; update texts translations and compile localization data.

![alt text](localization_dashboard_cultures.png "Cultures settings.")

### Adding new Culture
This is simple and straightforward - click the `Add New Culture` button, and then select desired Culture from the dropdown list that will appear. Notice that you can choose a Culture not only from the main languages, but also from a specific dialects from a certain language family.

### Gathering Texts and creating text localization binaries
When you're happy with your choices of Cultures, it's time to prepare text for translations. The general approach is to gather texts, translate them and then compile all text data into localization binaries. You can performed each step by using appropriate option button visible above the list of used Cultures.

![alt text](localization_dashboard_localizing_texts.png "Steps to perform while localizing texts.")

1. Firstly, you need to gather all localizable texts from your project. In order to do that, click `Gather text` option button **(1)**. This will list all localizable texts and create a bunch of custom JSON files: a described earlier `[localization_target_name].manifest` file + one `[localization_target_name].archive` file with text translations per each Culture.

<p>
<details>
<summary>Click here to see an example *.archive file (SomeDLC.archive for German).</summary>
<pre><code>
{
	"FormatVersion": 2,
	"Namespace": "",
	"Subnamespaces": [
		{
			"Namespace": "Cpp_Namespace_3",
			"Children": [
				{
					"Source":
					{
						"Text": "This is the third text literal created in code."
					},
					"Translation":
					{
						"Text": "Dies ist das dritte im Code erstellte Textliteral."
					},
					"Key": "Cpp_TextLiteral_3"
				}
			]
		},
		{
			"Namespace": "ST_Shapes",
			"Children": [
				{
					"Source":
					{
						"Text": "circle"
					},
					"Translation":
					{
						"Text": "Kreis"
					},
					"Key": "st_cpp_shapes_circle"
				},
				{
					"Source":
					{
						"Text": "rectangle"
					},
					"Translation":
					{
						"Text": "Rechteck"
					},
					"Key": "st_cpp_shapes_rectangle"
				}
			]
		}
	]
}
</code></pre>
</details>
</p>

2. Now you should prepare text translations for each Culture your project use. You can do it either insinde Unreal or in external software.

   1. If you want to do it inside Unreal, you can edit translation in Tranlation Editor window, that you can open by clicking left-most option available per each Culture **(2)**. In that window you can edit translation for each manually, as well as inspect text context and history. Note, that from that windo you can use export/import PO files options as well (these are described in the next point). ![alt text](localization_dashboard_translations_editor.png "Translations editor for selected Culture.")

   2. In order to prepare translations in external software, you need to export texts data. Unreal provides an option to export those data to PO files. You can do that by clicking export text option separately per each Culture **(3)**, or for all Cultures at the same time **(4)**. This will create a `[localization_target_name].po` file that contains information about translations for each text listed in `*.archive` file for a specific Culture. `*.PO` file type is the standard for working with translations. You can edit this with either commercial software or the free one like [poedit](https://poedit.net/).
   When all translations will be finished, you can import them back to the Unreal by using analogical options: **(5)** per each Culture or **(6)** for all of them.

3. Final step is to compile text translations into localization binaries. Before that you can use `Count Words` option **(7)** to make sure all texts have been translated. When you're ready, simply use `Compile Text` option available per each culture **(8)** separately, or for all of them at once **(9)**.

That's it - your text translations are loaded into project! One last thing is to tell the Unreal, what localization binaries should be packed with your project build.

---
## Packaging localization data
Localization data isn't attached to the build by defauls; you need to add them manually.

Go to the *Project Settings/Packaging/Localizations to Package* options. In advanced options set, find the `Localizations to Package` section. Here you can specify what localizations data will be added to your project packages during build. To make things easier, you can narrow the available options to only existing localization by selecting `Show Localized` toggle.

![alt text](localization_packaging_settings_detailed.png "Translations editor for selected Culture.")

The list of packaged localizations can be also edited directly in `DefaultGame.ini` file. In order to add specific cultures to staging use `+CulturesToStage=` command under `ProjectPackagingSettings` category:

```ini
[/Script/UnrealEd.ProjectPackagingSettings]
...
+CulturesToStage=en
+CulturesToStage=es
+CulturesToStage=de
+CulturesToStage=pl
```

---
Prev: [Setting up localizable texts in Unreal](3_SettingUpLocalizableTexts/Setting-up-localizable-texts-in-Unreal.md)

Next: [Setting up texts localization for your project](4_LocalizationDashboard/Setting-up-texts-localization-for-your-project.md)
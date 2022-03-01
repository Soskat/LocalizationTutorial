# Debugging localization errors in Unreal

In this page you can find some tips for debugging and fixing localization-related bugs. All examples are taken from my own experience. This list desn't exhaust the topic and may be updated with new finds in the future.

Below you can learn about possible problems, that may occur, followed by their potential solutions.

---
## Problem: translation for specific text doesn't work

We've got our source texts gathered, translated and loaded in the Localization Dashboard. Still, some of the translations aren't visible in runtime.

---
### Solution #1 - make sure that FText property is binded with localizable text.

During early stages of development of any project, placeholders are often used. It's easy to forget about putting the final asset in some places. Just make sure you at some point initializes a FText property with localizable text (either from teh editor level or straight in code).

See section [Setting up localizable texts in Unreal](../3_SettingUpLocalizableTexts/Setting-up-localizable-texts-in-Unreal.md).

---
### Solution #2 - make sure the translation in question is used in project data.
In order for translations to be used in a project, they must be included in compiled localization data. That means after loading all translations you must execute the `Compile Texts` option available in Localization Dashboard.

TL;DR: **You can't forget any of the steps in `Gather Texts > Add Texts Translations > Compile Texts with Translations`!**

For more information see topics [Localization Dashboard overview](../4_LocalizationDashboard/Localization-Dashboard-Overview.md) or [Setting up texts localization for your project](../4_LocalizationDashboard/Setting-up-texts-localization-for-your-project.md).

---
### Solution #3 - make sure that Source of given text is the same in both `*.manifest` and `*.archive` files.

Unreal Localization system is very sensitive when it comes to recognizing whether a translation for a particular text exist or not. If. for a given text ID, the associated Source property in `*.archive` file contains a different text that the Source property in `*.manifest` file, then Unreal comes to a conclusion that existing translation in `*.archive` file doesn't match to this text and that translation won't be used.

Let's look at the following example.

Following fragment of SomeDLC.manifest file contains information about text that uses ID `st_cpp_shapes_circle`:
```
(...)
"Namespace": "ST_Shapes",
Children": [
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
(...)
```
Now, take a look on the German translation for this text, that can be found inside `./de/SomeDLC.archive` file:
```
(...)
"Namespace": "ST_Shapes",
"Children": [
	{
		"Source":
		{
			"Text": "circle."
		},
		"Translation":
		{
			"Text": "Kreis"
		},
		"Key": "st_cpp_shapes_circle"
	},
(...)
```
At this point, the German translation for `st_cpp_shapes_circle` is broken, because Source text `circle.` from the `.archive` file isn't equal to Source text `circle` from the `.manifest` file.

After changing Source text in `.archive` file to `circle` (without a dot at the end) and recompiling German localization data everything should work correctly.

---
## Problem: translations work in PIE Standalone mode, but not in build

Inside the editor everything worked fine. But after building the project some translations are missing.

---
### Solution #1 - localizable data isn't added to build in packaging settings

Localization data isn't packed into build by default; it needs to be added manually.

You need to verify, if all cultures of your choice are set to be staged in *Project Settings/Packaging/Localizations to Package* options or in the `DefaultGame.ini` file.

For more information see section `Packaging localization data` of [Localization Dashboard overview](../4_LocalizationDashboard/Localization-Dashboard-Overview.mdd).

---
## Problem: rich text formatting tags that are broken only for certain Cultures

For some cultures formatting tags for rich text works perfectly, but for others they're broken.

---
### Solution #1 - be concious, that certain languages have special characters or rules and lear how to deal with it

Yes, some languages have rules or special characters you've never dreamed about and will take you by surprise by ruining your formatting tags. The good news are that you'll propably fairly easy can find a solution or a walkarount of the problem and fix it. I learned that while I was working with Turkish translations.

Let's say you want to display some rich text with an embedded image inside:
```html
"Hello there! <img id="SmileyFace"/>"
```
You want this text to be capitalized in your UI, so you execute FText::ToUpper() method and the end result will be like this:
```html
"HELLO THERE! 🙂"
```
The source text is ready, now you send it to the localization company for Turkish translation. Of course you've mentioned them to do not translate words inside brackets as those are formatting tags.

After some time you get back translations and loads them into your project. They look just fine:
```html
"Selamlar! <img id="SmileyFace"/>"
```
but when this text is being capitalized, the catastrophe happens and the formatting tags for embedded image are visible:
```html
"SELAMLAR! <İMG İD="SMİLEYFACE"/>"
```
The problem lies in the `i` letter. It turns out that in Turkish language there are two kinds of this letter - [dotted and dotless I](https://en.wikipedia.org/wiki/Dotted_and_dotless_I). Although the English `i` and the Turkish dotted `i` looks the same, they are recognized as different characters. That means, the formatting tag `<img id="...">` suddently stops being recognized by the parsing program as it desn't contains the correct `i` letter!

In this case the solution was simple as replacing the dotted `i` with its dottless version in all formattings tags was sufficient to make them work again. But getting there took me a couple of hours until I realized that capitalized, broken formatting tags in Turkish look odd :X...

---
Prev: [Localizing Dialogues](../6_LocalizingDialogues/Localizing-Dialogues-in-Unreal.md)
# Introduction to the localization topic

## Why we need to localize texts and assets
The answer is simple - by translating the content of our project (game, application, animation, ect.) we're maximizing its recipents.

------
## Pros and cons of Unreal Localization system
You may wonder, whether you should use Unreal's localization system or go with something else. I can't decide for yourself, however below I've put a list of some pros and cons for using it. Of course it's only my biased opinion based on my experiences with Unreal.
### Pros:
- it's build-in and ready-to-use system within the Unreal engine
- build-in == compatible with the Unreal, so you don't need to worry if it'll work every time when you upgrades engine version in your project
- also, build-in == without additional fees
- ready-to-use == you don't need to waste time of creating your own solution
- despite being marked as 'experimental', it's stable and works well
- it's easy to learn and use
- it supports exporting text translations to .PO files, which are a standarized file type, that is dedicated for localization companies
### Cons:
- localization data needs to be recompiled with every change of text translations...
- ...that means you can't change translations on the fly -> no support for fan translations
- compiled localization data is binary data, so it can't be merged. That make it hard to work on certain localization data paralelly with other people 
- if your localization company doesn't want to work with .PO files, then you need to prepare your own solution for loading text translations to your game

---
Next: [Basics of text localization in Unreal](2_TextLocalizationBasics/Basics-of-text-localization-in-Unreal.md)
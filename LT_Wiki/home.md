# Localization Tutorial Wiki

Welcome to the wiki dedicated to the Localization Tutorial project.

Following pages describe different aspects localization process in Unreal Engine localization system and localization in general. You don't need to follow those posts in any particular order, although I've arranged them from the most basic topics to the most sophisticated ones.

Before you go further here are some valuable resources to chek up:
- [Official Unreal docummentation for Localization system](https://docs.unrealengine.com/4.26/en-US/ProductionPipelines/Localization/)
- [Unreal live stream about using Localization system](https://www.youtube.com/watch?v=UD2_TEgxkqs)
- [Unreal Gems' Localization tutorial on YouTube](https://www.youtube.com/playlist?list=PLh0J3NckZPo-RM_TKeWM5WZIyHlaLy2zY)
- [BenUI blog - tons of knowledge related to UI, coding and Localization in Unreal](https://benui.ca/tags/#localization)
- [UNICODE tables for ordinal formats](https://www.unicode.org/cldr/cldr-aux/charts/29/supplemental/language_plural_rules.html)

---
## Pros and cons of Unreal Localization system
You may wonder, whether you should use Unreal's localization system or go with something else. I can't decide for yourself, however below I've put a list of some pros and cons for using it. Of course it's only my biased opinion based on my experiences with Unreal.
### Pros:
- it's build-in and ready-to-use system within the Unreal engine;
- build-in == compatible with the Unreal, so you don't need to worry if it'll work every time when you upgrades engine version in your project;
- also, build-in == without additional fees;
- ready-to-use == you don't need to waste time of creating your own solution;
- despite being marked as 'experimental', it's stable and works well;
- it's easy to learn and use;
- it supports exporting text translations to .PO files, which are a standarized file type, that is dedicated for localization companies.
### Cons:
- localization data needs to be recompiled with every change of text translations...
- ...that means you can't change translations on the fly without additional effort in order to support fan translations;
- compiled localization data is binary data, so it can't be merged. That make it hard to work on certain localization data paralelly with other people;
- if your localization company doesn't want to work with .PO files, then you need to prepare your own solution for loading text translations to your game.

---
## Table of Contents:
- [Introduction to the localization topic](1_Introduction/Introduction-to-the-localization.md)
   - Why should we bother to localize content of our product?
   - Basic concepts.
   - Unreal Engine localization system.
- [Localization Dashboard quick start](2_LocalizationDashboard/Localization-Dashboard-Quick-Start.md)
   - What is the Localization Dashboard and how to access its window.
- [Localization Dashboard overview](2_LocalizationDashboard/Localization-Dashboard-Overview.md)
   - Detailed description of the Localization Dashboard.
- [Setting up texts localization for your project](2_LocalizationDashboard/Setting-up-texts-localization-for-your-project.md)
   -  A short manual for setting up a localization target.
- [Basics of text localization in Unreal](3_TextLocalizationBasics/Basics-of-text-localization-in-Unreal.md)
   - Unreal tools for text localization.
   - How to prepare texts for localization.
- [Setting up localizable texts in Unreal](4_SettingUpLocalizableTexts/Setting-up-localizable-texts-in-Unreal.md)
   - Examples of creating localizable texts.
- [Localizing non-text assets in Unreal](5_LocalizingNonTextAssets/Localizing-non-text-assets-in-Unreal.md)
   - Unreal pipeline for localizing binary assets.
- [Localizing Dialogues](6_LocalizingDialogues/Localizing-Dialogues-in-Unreal.md)
   - Unreal pipeline for localizing dialogues audio files and subtitles.
- [Debugging localization errors in Unreal](../LT_Wiki/7_DebuggingLocalizationErrors/Debugging-localization-errors-in-Unreal.md)
   - A bunch of advices for debugging localization related bugs.
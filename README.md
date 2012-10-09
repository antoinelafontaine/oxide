Oxide
=====

A Haml theme engine for Drupal.

The original work is based on the _Peroxide_ project of Kyle Cunningham: https://github.com/codeincarnate/peroxide but the goal is now limited to only providing Haml templates support to Drupal.

Dependencies
============

Requires a copy of MtHaml Haml parser to be placed in _sites/all/libraries_ or _sites/[domain]/libraries_ of your Drupal installation.

MtHaml project page on github: https://github.com/arnaud-lb/MtHaml


Usage guidelines
================

The engine needs to first be placed in the _sites/all/themes/engine_ or the _sites/[domain]_ variant folder.

Then you need to declare that you'll be using _oxide_ as your theme engine in your theme info file.

```
name = My Oxide based theme
description = An Haml powered theme
package = Core
version = VERSION
core = 7.x

engine = oxide
```

Your all set to use haml template files for your new theme! Happy theming!


Notes
=====

The engine saves rendered parsed haml files in the sites files folder in order to speed up rendering.

These can be located under _sites/default/files/oxide/[theme name]/

A small drush command - drush oxide-clear-cache (occ) - has been defined for emptying that cache folder whenever you rename or move a template file when developing. 
You can also safely remove that folder manualy and the engine will recreate it when required.
.   
.   
.   

Create README02.md
---

README02.md  

.   
.   
.   

README--a2-135.md  
---


This is a secondary README file, contains info on the mods of this specific branch, a2-135.  

Please bear in mind, I'm still learning/playing with this Git, GitHub, GitHub Desktop, PuppyGit thingy ...   

If you try to compile from this source, it may not work as intended, or it may NOT work at all. 


.   
.   
.   

Edit README--a2-135.md  
---

2025-02-19   

OK, let's get it going...   

This specific branch is anduril2 with some mods.  


Heavy mods, maybe.   
But it has the same file structure as   
The OG [ToyKeeper Anduril2](https://github.com/ToyKeeper/anduril). 


For comparison, the other branches, a-325, has different file structure.

I don't know anything else other than anduril/ in the ui/ directory.
I moved anduril/ directory up to the source root and deleted everything else inside ui/, and deleted the ui/ directory.

I moved dfp/ dir up from arch/ dir, up to the repo(source) root.

The hw/ dir structure is also different. I moved buil-target directories up one level from the "vendor", to the root of hw/. So, it's hw/  --> ts10/ , ts11/ , ts21/ , etc. Kind of bypassing the wurkkos/ directory.

I had to make a lot of changes in some files to make it work.
It became a simpler structure.
I learned a lot in doing that project.
But, I think moving forward I'm gonna stick to the standard structure.

I cloned/copied/moved 
a2-325 to another repo and deleted from this anduril2 repo.
That other repo is vygr-1/a2mods. 

I use PuppyGit on my android phone.
I tried GitHub Desktop and Git GUI on my laptop but then settled with GitKraken. I prefer GitKraken. I haven't tried SourceTree yet. Maybe I'll try it sometime soon, maybe not. 
I really like GitKraken.

PuppyGit is the only git gui client available for android. It's good. I'd like try something else but there's none. 

I learned from the list of GUI Clients on the git website.
[GUI Clients](https://git-scm.com/downloads/guis).



.   
.   
.   

2025-02-22 05:59

accessing through Git GUI on Desktop

.   

Checks 

2025-02-22 07.09.28

2025-02-22 07.10.57


.   
.   
.   

New Files  
---


There are two new files, ver-check-mode,  
custom version check mode in blinky group 
-  ui/anduril/ver-check-mode.c  
-  ui/anduril/ver-check-mode.h  

.   
. 
  
Modified Files
---


-  bin/build.sh 
-  bin/build-all.sh 
-  bin/version-string.sh 

.   

-  ui/anduril/anduril.c  

.   

More aux patterns, using SammysHP's files: 
-  ui/anduril/aux-leds.c  
-  ui/anduril/aux-leds.h  


Mod, supporting more aux patterns:  
-  ui/anduril/lockout-mode.c  
-  ui/anduril/off-mode.c  

.   

Mod, supporting VER_CHECK_MODE : 
-  ui/anduril/battcheck-mode.c 
-  ui/anduril/beacon-mode.c  
-  ui/anduril/tempcheck-mode.c  
-  ui/anduril/sos-mode.c  

.  

candle-mode with more adjustments, using starryalley's candle-mode.c: 
-  ui/anduril/candle-mode.c  

.   

BIG-DEAL button mapping:   
OFF or ON, 3C : strobe-modes  
OFF, 5C : battcheck-mode (blinky group)   
Mod files:   
-  ui/anduril/lockout-mode.c  
-  ui/anduril/off-mode.c  
-  ui/anduril/ramp-mode.c  

.   

Custom strobe-modes   
-  ui/anduril/strobe-modes.c   
-  ui/anduril/strobe-modes.h  
-  ui/anduril/strobe-modes-fsm.h  

-  ui/anduril/load-save-config.h  
-  ui/anduril/load-save-config-fsm.h   

.   

Custom version-check-mode.h 
-  ui/anduril/version-check-mode.h  

.   
.   
.   



###  This is a rough outline / plan, the actual features implementation are TBD   




# CUSTOM FEATURES   


- disable momentary mode   
- disable POVD   
- disable extra digit for the battcheck-mode:   
    4.1 Volt , not 4.18 Volt 
- disable Simple UI   
- disable SOS mode   



## ver-check-mode

 - This is a custom version-check-mode added into the blinky group.  

 - Similar to the default (OFF, 13H) **version-check-mode**.  

 - The default **version-check-mode** runs only once. This custom **ver-check-mode** runs repeatedly. 

 - 1C to turn OFF (off-mode)  
  2C to cycle the modes:  
  **battcheck-mode**  --> **temp-check-mode**  -->  **ver-check-mode**  -->  **beacon-mode**.  

 - Extra files in the **anduril** directory:  
   **ver-check-mode.c** and **ver-check-mode.h**, which are basically copies of the OG version-check-mode files, with some mods.

.   

##   Button clicks for blinky group


OFF, **5C**: activate **battcheck-mode** (OG is 3C)   

**1C**: turn off  

**2C**: rotate through blinky group:  
   - **battcheck-mode**
   - **tempcheck-mode**  
   - **ver-check-mode**  
   - **beacon-mode**   

.  
.  
.   


## Strobe group with extra strobe modes

   - bike flasher
   - party strobe
   - tatical strobe
   - police color strobe 
   - lightning mode
   - candle mode
     
   - fireworks mode (new)
   - lighthouse mode (new)
   - broken fluorescent mode (new)
  

Extra strobe modes are inspired by and copied   
from [SiteRelEnby anduril branch](https://github.com/SiteRelEnby/anduril)   
and [starryalley anduril branch](https://github.com/starryalley/anduril) 


.  
.  
.  


## strobe-modes, remap button clicks 

OFF or ON, **3C**: activate strobe-modes (OG is 3H)  

**1C**: off  
**2C**: rotate through strobe/flasher modes  
**3C**: rotate backward through strobe/flasher modes  

.  

**1H** :  
    -  party strobe faster  
    -  tactical strobe faster  
    -  biking mode brighter  
    -  broken fluorescent mode brighter  

**2H**:   
    -  party strobe faster  
    -  tactical strobe slower  
    -  biking mode dimmer  
    -  broken fluorescent dimmer  

.  

**4C**:  
    -  turning lightning mode busy factor,   
    -  or turning down firework brightness by 12,  
    -  or decrease lighthouse delay by 1 sec  

**5C**:   
    -   turning up lightning mode busy factor,   
    -   or turning up firework brightness by 12,  
    -   or increasing lighthouse delay by 1 sec  

**6C**:    
    -   reset lightning mode busy factor to default,  
    -   or reset firework brightness to default  
    -   or reset lighthouse delay to default  

.  

**7C**:  
    -   rotate through channel modes for the current strobe  


.   
.   
.   


## Extended aux patterns


- EXTENDED_INDICATOR_PATTERNS from [SammysHP Anduril  (https://github.com/SammysHP/anduril/tree/more-aux-patterns)](https://github.com/SammysHP/anduril/tree/more-aux-patterns) 


**more-aux-patterns** 

```
Add more aux LED patterns like short low intensity blinks, short high intensity blinks or no aux LEDs at all (but keep the switch LED enabled). Works for classic and RGB aux LEDs. Also fixes some edge cases of aux handling.

```



- The OG aux patterns:   
   - Off 
   - Low
   - High 
   - Blinking (fancy blinking) 

- Extended aux patterns:   
   - Off 
   - Low
   - High 
   - Blinking (fancy blinking) 
   - Low blinking 
   - High blinking 



.   
.   
.   


.   
.   
.   


.   
.   
.   


Checks checks 

2025/02/18 20:42

2025/02/19 12:23

2025/02/19 16:42

2025-02-21

2025-02-21... 

2025-02-21 022254

2025-02-21 18.03.42




.   
.   
.   


.   
.   
.   

Create README02.md
---

README02.md  

This is a secondary README file, contains info on the mods of this specific branch, a2-105.  
There's some chaos, I'm still learning/playing with this Git, GitHub, GitHub Desktop, puppygit thingy ...  

.   
.   
.   

Edit README--a2-105.md  
---

2025-02-19   

OK, let's get it going...   
This specific branch is anduril2 with some mods.  
a2-105, not as heavy-mods as the a2-325?   

Heavy It may be, but it has the same file structure as the OG [ToyKeeper Anduril2](https://github.com/ToyKeeper/anduril). 

.   
.   
.   

.   
.   
.   

.   
.   
.   


This is a rough outline / plan, the actual features implemented are TBD   
---



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




.   
.   
.   


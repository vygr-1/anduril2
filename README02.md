
.   
.   
.   

## Create README02.md

2025-02-19 

README02.md.  

This is a secondary README file, contains info on the mods of this specific branch.
now it's empty though, kinda a placeholder, I'm still learning/playing with this Git, GitHub, GitHub Desktop thingy ...  

.   
.   
.   

2025-02-16   

OK, let's get it going...   
This specific branch is anduril2 with many mods. 

.   
.   
.   

.   
.   
.   

# CUSTOM FEATURES   


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
.   
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



.   
.   
.   



.   
.   
.   



2025/02/18 20:42




.   
.   
.   


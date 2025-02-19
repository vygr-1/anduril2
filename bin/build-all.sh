#!/usr/bin/env bash
# Anduril / FSM build wrapper script
# Copyright (C) 2017-2023 Selene ToyKeeper
# SPDX-License-Identifier: GPL-3.0-or-later

# Usage: build-all.sh [pattern]
# If pattern given, only build targets which match.

# enable "**" for recursive glob (requires bash)
shopt -s globstar



function main {

    if [ "$#" -gt 0 ]; then
        # multiple search terms with "AND"
        SEARCH=( "$@" )
        # memes
        [ "$1" = "me" ] && shift && shift && echo "Make your own $*." && exit 1
    fi

    # TODO: detect UI from $0 and/or $*
    UI=anduril

    mkdir -p hex

    make-version-h  # generate a version.h file

    PASS=0
    FAIL=0
    PASSED=''
    FAILED=''

    # build targets are hw/$vendor/$model/**/$ui.h
    for TARGET in hw/*/*/**/"$UI".h ; do

        # friendly name for this build
        NAME=$(echo "$TARGET" | perl -ne 's|/|-|g; /hw-(.*)-'"$UI"'.h/ && print "$1\n";')

        # limit builds to searched patterns, if given
        SKIP=0
        if [ ${#SEARCH[@]} -gt 0 ]; then
            for text in "${SEARCH[@]}" ; do
                if ! echo "$NAME $TARGET" | grep -i -- "$text" > /dev/null ; then
                    SKIP=1
                fi
            done
        fi
        if [ 1 = $SKIP ]; then continue ; fi



        ##  build announcement, a little mod 
        # announce what we're going to build
        ##  OG: echo "===== $UI $REV : $NAME ====="
        ###  mod:  
        echo "   "
        echo "   "
        echo "###   ###   ###   ###   ###   ###   ###   ###   ###   ###"
        echo "   "
        echo "   "
        echo "===== $UI $REV : $NAME ====="
        echo "   "



        ##  adding BUILDDATE to the hex file name 
        BUILDDATE=$( date -d '7 hours' '+%y%m%d.%H%M%S' )

        # try to compile, track result, and rename compiled files
        if bin/build.sh "$TARGET" ; then

            ##  OG:  HEX_OUT="hex/$UI.$NAME.hex"
            ##  custom name, with build date 
            HEX_OUT="hex/a2.$BUILDDATE.$NAME.hex"

            mv -f "ui/$UI/$UI".hex "$HEX_OUT"

            MD5=$(md5sum "$HEX_OUT" | cut -d ' ' -f 1)

            ##  OG:  echo "  # $MD5"
            ##  OG:  echo "  > $HEX_OUT"

            ###  mod:  
            echo "   "
            echo "  # $MD5"
            echo "  > $HEX_OUT"
            echo "   "
            echo "  OK: $NAME build succeeded"



            PASS=$((PASS + 1))
            PASSED="$PASSED $NAME."



        else

            ##  OG:  echo "ERROR: build failed"

            ##  mod:  
            echo "   "
            echo "  ERROR: build failed"


            FAIL=$((FAIL + 1))
            FAILED="$FAILED $NAME."
        fi

    done





    # summary
    ##  OG:  echo "===== $PASS builds succeeded, $FAIL failed ====="

    ###  mod:  
    echo "   "
    echo "   "
    echo "###   ###   ###   ###   ###   ###   ###   ###   ###   ###"
    echo "   "
    echo "   "
    echo "===== $PASS builds succeeded, $FAIL failed ====="
    echo "   "
    echo "   "



    ##  OG:  #echo "PASS: $PASSED"
    ##  OG:  if [ 0 != $FAIL ]; then
        ##  OG:  echo "FAIL:$FAILED"
        ##  OG:  exit 1
    ##  OG:  fi
##  OG:  }

    ###  mod:  

    ## PASS
    if [ 0 != $PASS ]; then

        echo "SUCCEEDED: $PASSED"
        echo "   "
        echo "   "

    fi

    ## FAIL
    if [ 0 != $FAIL ]; then

        echo "FAILED   : $FAILED"
        echo "   "
        echo "   "

    fi



    ##  end / border
    echo "###   ###   ###   ###   ###   ###   ###   ###   ###   ###"
    echo "   "
    echo "   "
    echo "   "

    exit 1

}





function make-version-h {
    # old: version = build date
    #date '+#define VERSION_NUMBER "%Y-%m-%d"' > ui/$UI/version.h

    REV=$(bin/version-string.sh c)
    # save the version name to version.h
    mkdir -p ".build/$UI"
    echo '#define VERSION_NUMBER "'"$REV"'"' > ".build/$UI/version.h"
}

main "$@"





###   ###   ###   ###   ###   ###   ###   ###   ###
###   ###   ###   ###   ###   ###   ###   ###   ###
###   ###   ###   ###   ###   ###   ###   ###   ###



##  END



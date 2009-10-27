#!/usr/local/bin/bash
#< Basic LOLCODE to BASH converter - see http://lolcode.com ;-)

AWK="/usr/bin/awk"
BASH="/usr/local/bin/bash"
CHMOD="/bin/chmod"
ECHO="/bin/echo"
GREP="/usr/bin/grep"
SED="/usr/bin/sed"

function print_error {
  ${ECHO} "OMG: $@" >&2
}

function do_lol_code {
   LINECOUNT=0
   while read LINE; do
      (( LINECOUNT = LINECOUNT + 1 )) 
      if [ "${LINECOUNT}" -eq "1" ]; then
         if [ "${LINE}" != "HAI" ]; then
            print_error "SO IM LIKE WHEREZ YOUR HAI?"
            exit 1
         else
            ${ECHO} "#!${BASH}" > ${TMPFILE}
         fi
      else
         # BTW THIS IS A COMMENT
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*BTW " >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            ${ECHO} "# ${LINE}" >> ${TMPFILE}
         fi
         # CAN HAS MODULE?
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*CAN HAS " >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            MODULE=$( ${ECHO} "${LINE}" | ${SED} 's/^[ 	]*CAN HAS \([^?]*\)\?$/\1/' )
            MODULE="${MODULE}.lol"
            if [ ! -e "${MODULE}" -o "${MODULE}" = "STDIO" ]; then
               print_error "UR BAD CANT FIND TEH MODULE ${MODULE}"
               exit 1
            fi 
         fi
         # I HAS A VARIABLE ITZ VALUE
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*I HAS A " >/dev/null 2>&1 
         if [ "$?" -eq "0" ]; then
            VARIABLE=$( ${ECHO} "${LINE}" | ${AWK} '{print $4}' )
            VALUE=$( ${ECHO} "${LINE}" | ${AWK} '{ if ( NF == 6 ) {print $6} else {print 0} }' )
            ${ECHO} "${VARIABLE}=${VALUE}" >> ${TMPFILE}
         fi 
         # [IN]VISIBLE SOMETHING &VARIABLE& VALUE !
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*(IN|)VISIBLE " >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*INVISIBLE" >/dev/null 2>&1
            if [ "$?" -eq "0" ]; then
               REDIR=" >&2"
            else
               REDIR=""
            fi
            ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*VISIBLE FILE" >/dev/null 2>&1
            if [ "$?" -eq "0" ]; then
               ${ECHO} "cat ${FILE_TO_OPEN}" >> ${TMPFILE}
            else
               LINE_TO_ECHO=$( ${ECHO} "${LINE}" | ${SED} 's/^[ 	]*[I]\{0,1\}[N]\{0,1\}VISIBLE \(.*\)$/\1/' )
               LINE_TO_ECHO=$( ${ECHO} "${LINE_TO_ECHO}" | ${SED} 's/\&\([^&]*\)\&/\$\1/g' )
               LAST_CHAR=$( ${ECHO} "${LINE_TO_ECHO}" | ${SED} 's/^.*\(.\)$/\1/' )
               if [ "${LAST_CHAR}" = "!" ]; then
                  LINE_TO_ECHO=$( ${ECHO} "${LINE_TO_ECHO}" | ${SED} 's/.$//' )
                  ${ECHO} "echo -n \"${LINE_TO_ECHO}\"${REDIR}" >> ${TMPFILE}
               else
                  ${ECHO} "echo -e \"${LINE_TO_ECHO}\"${REDIR}" >> ${TMPFILE}
               fi
            fi
         fi
         # IM IN YR.... OMG.... - need to count and check for closure
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*IM IN YR " >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            ${ECHO} "while [ true ]; do" >> ${TMPFILE}
         fi
         # IM OUTTA YR 
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*IM OUTTA YR " >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            ${ECHO} "done" >> ${TMPFILE}
         fi
         # UPZ VAR!!1 - todo: check that var has been assigned
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*UPZ " >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            VARNAME=$( ${ECHO} "${LINE}" | ${SED} 's/^[ 	]*UPZ \([^!]*\)!!1/\1/' )
            ${ECHO} "(( ${VARNAME} = ${VARNAME} + 1 ))" >> ${TMPFILE}
         fi
         # IZ VARNAME BIGR THAN 20? GTFO. KTHX
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*IZ.*GTFO\..*" >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            VARNAME=$( ${ECHO} "${LINE}" | ${AWK} '{print $2}' )
            ACTION=$( ${ECHO} "${LINE}" | ${AWK} '{print $3}' )
            VALUE=$( ${ECHO} "${LINE}" | ${AWK} '{print $5}' | ${SED} 's/\?$//' )
            ${ECHO} "(( ${VARNAME} > ${VALUE} )) && break" >> ${TMPFILE}
         fi
         # IZ VARNAME BIGR|SMLR THAN VAL?
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*IZ.*\?$" >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            VARNAME=$( ${ECHO} "${LINE}" | ${AWK} '{print $2}' )
            COMPARE=$( ${ECHO} "${LINE}" | ${AWK} '{print $3}' )
            case "${COMPARE}" in
               "BIGR" ) COMPARE="-gt" ;;
               "BIGGER" ) COMPARE="-gt" ;;
               "SMLR" ) COMPARE="-lt" ;;
               "SMALLER" ) COMPARE="-lt" ;;
            esac
            VALUE=$( ${ECHO} "${LINE}" | ${AWK} '{print $5}' | ${SED} 's/\?$//' )
            ${ECHO} "if [ \"\${${VARNAME}}\" ${COMPARE} \"${VALUE}\" ]; then" >> ${TMPFILE}
         fi
         # YARLY - this is the default if case so we can ignore it
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*YARLY" > /dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            :
         fi
         # NOWAI
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*NOWAI" > /dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            ${ECHO} "else" >> ${TMPFILE}
         fi
         # KTHX - We only use this with "if/else" in this implementation
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*KTHX$" > /dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            ${ECHO} "fi" >> ${TMPFILE}
         fi
         # GIMMEH
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*GIMMEH" >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            VARNAME=$( ${ECHO} "${LINE}" | ${AWK} '{print $NF}' )
            ${ECHO} "read ${VARNAME}" >> ${TMPFILE}
         fi
         # PLZ OPEN
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*PLZ OPEN " >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            THING_TO_OPEN=$( ${ECHO} "${LINE}" | ${AWK} '{print $3}' )
            case "${THING_TO_OPEN}" in 
               "FILE" ) ;;
               "EYES" ) ${ECHO} "8-)" ;;
               *      ) print_error "HAI I CANNOT OPEN DIZ ${THING_TO_OPEN}" && exit 1
            esac
            FILE_TO_OPEN=$( ${ECHO} "${LINE}" | ${AWK} '{print $NF}' | ${SED} 's/\?$//' )
            # Keep hold of FILE_TO_OPEN - we'll check that in our AWSUM THX and O NOES blocks
         fi
         # AWSUM THX
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*AWSUM THX" >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            ${ECHO} "if [ -e \"${FILE_TO_OPEN}\" ]; then" >> ${TMPFILE}
         fi
         # O NOES
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*O NOES" >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            ${ECHO} "elif [ ! -e \"${FILE_TO_OPEN}\" ]; then" >> ${TMPFILE}
         fi
         # KTHXBYE
         ${ECHO} "${LINE}" | ${GREP} -E "^[[:space:]]*KTHXBYE" >/dev/null 2>&1
         if [ "$?" -eq "0" ]; then
            ${ECHO} "exit 0" >> ${TMPFILE}
         fi
      fi
   done < ${INPUTFILE}
}

if [ "$#" -ne "1" ]; then
   print_error "YR BAD - WHEREZ YR CODEZ?"
   exit 1
fi

INPUTFILE=$1

if [ ! -e "${INPUTFILE}" ]; then
   print_error "YR BAD - I COULDNT FIND DEEZ CODEZ"
   exit 1
fi

TMPFILE="${INPUTFILE%%.*}.sh"

do_lol_code

${CHMOD} +x ${TMPFILE}

${ECHO} "IM IN UR CPU INTERPRETING UR CODEZ!"

./${TMPFILE}

exit 0

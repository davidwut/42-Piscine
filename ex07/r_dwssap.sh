cat /etc/passwd | tail -n +11 | awk "(NR+1)%2" | awk -F : '{print $1}' | rev | sort -r | head -n $FT_LINE2 | tail -n +$FT_LINE1 |  tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./g'
# cat /etc/passwd       -> original output
# tail -n +11           -> remove the boxed comment 11 lines long
# awk "(NR+1)%2"        -> keep every other line starting from the 2nd
# awk -F : '{print $1}' -> change the delimiter to ":" and keep the 1st item of each line
# rev                   -> reverse the string of each line
# sort -r               -> sort by reverse alphabetical order
# head -n $FT_LINE2     -> keep first $FT_LINE2 lines
# tail -n +$FT_LINE1    -> keep lines starting from $FT_LINE1
# tr '\n' ','           -> replace newlines with a comma
# sed 's/,/, /g'        -> replace ',' with ', '
# sed 's/, $/./g'       -> replace the last ', ' with ','
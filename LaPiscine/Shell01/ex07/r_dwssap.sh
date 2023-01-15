cat /etc/passwd | sed '/^#/'d | awk 'NR%2==0' | cut -d ':' -f 1 | rev| sort -r| awk -v a=$FT_LINE1 -v  b=$FT_LINE2 'NR>=a && NR<=b' | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./g'| tr -d '\n'

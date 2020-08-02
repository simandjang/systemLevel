<<<<<<< HEAD
fun with scripting tools

1.grep -v 'ATOM\|CONECT\|HETATM\|TER\|END' 4HKD.pdb
-> -v option in grep command invert the sense of matching, to select non-matching lines.
   It print all other headers except ATOM, CONECT, HETATM, TER, and END.

2-a.sed ‘s/HETATM/ATOM  /g’ 4HKD.pdb
-> I changed all HETATM to ATOM with two spaces after ATOM with sed command in 4HKD.pdb file.

2-b.sed ‘s/MSE/MET/g’ 4HKD.pdb
-> I changed all MSE to MET with sec command in 4HKD.pdb file.

3.

#!/bin/bash

awk 'BEGIN {max = -1; min = 100}
        $1 =="ATOM" {
                max = max<$7 ? $7:max;
                min= (min==100||min>$7 ? $7 : min)
        }
         END { printf"max of x = %3.f\nmin of x = %.3f\n",max,min}' 4HKD.pdb

awk 'BEGIN {max = -1; min = 100}
        $1 =="ATOM" {
                max = max<$8 ? $8:max;
                min= (min==100||min>$8 ? $8 : min)
        }
         END { printf"max of y = %3.f\nmin of y = %.3f\n",max,min}' 4HKD.pdb
awk 'BEGIN {max = -1; min = 100}
        $1 =="ATOM" {
                max = max<$9 ? $9:max;
                min= (min==100||min>$9 ? $9 : min)
        }
         END { printf"max of z = %3.f\nmin of z = %.3f\n",max,min}' 4HKD.pdb
-> I made a script named "max_min_finder" to find maximum number and minimum number of each of 7th, 8th, and 9th field for the ATOM's. With awk command, I set max is -1 and min is 100. $1 =="ATOM" means when the first column is ATOM. If max is smaller than 7th number, the 7th number updated to max number.If min number is bigger then 7th number, the min number updated to 7th number. finally, it print max number and min number of 7th column in ATOM. 8th and 9th column did same with the 7th column.

 
4. 

#!/bin/bash
awk '/HETATM/ {sum += $7; count++}

        END {printf("mean value of x = %3.f\n",sum/count)}' 4HKD.pdb

awk '/HETATM/ {sum += $8; count++}

        END {printf("mean value of y = %3.f\n",sum/count)}' 4HKD.pdb

awk '/HETATM/ {sum += $9; count++}

        END {printf("mean value of z = %3.f\n",sum/count)}' 4HKD.pdb
->   I made a script named "mean_finder" to find mean value of the each 7th, 8th, and 9th field for the HETATM. With awk command, I found HETATM. I add all the 7th column in variable sum, and count the HETATM column. Finally, I print mean value of HETATM with sum/count. Doing 8th and 9th mean value for the HETATM are the same way with 7th column.

5.sed ‘s/HOH/WAT/g’ 4HKD.pdb
-> I changed all HOH to WAT in the 4HKD.pdb file.

6.awk '/ATOM/ {print}' 4HKD.pdb | sort -nk11
-> I use awk command to print the column which has ATOM in 4HKD.pdb file, and use sort command to sort by the column with 11th position of ATOM lines.

Lab Work

1. string2nuts.sh
 
I created awk script named string2knuts to convert a string of the form +- g/s/k into an absolute number of knuts.
I use split in awk to print the values without "/", and I made variable flag to check whether the first column is negative integer or positive integer. Then, I made all negative integer to positive integer with gsub. and print the absolute number of knuts with the sign.

2. knuts2string.sh

I created another awk script named knuts2string to generate a string of the form +- g/s/k from the absolute number of knuts. I made a variable named flag to consider the sign. Then, I changed all the negative sign to positive sith gsub. Finally, calculate the number of each knuts, sickle, and galleon with the form and formula.

3. sum of the total number of knuts and form with slash

I put the lab3data.txt in the string2knuts.sh file, so I don't need to write again in the command line. I just need to sum-up all of the knuts from the string2knuts.sh file.

Second one is harder than first one for me. I did same with the first one, but I add the same of the awk command line with knuts2string.sh at the end of the command line.
=======
# systemLevel
>>>>>>> 523cae5b9a40630ac177f8ef871b92aed8df7cf8

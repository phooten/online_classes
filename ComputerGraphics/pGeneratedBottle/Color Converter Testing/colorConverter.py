#!/usr/bin/python

# Python Version: 3.8.10

import sys  # don't know what this does
import re

def convToFloat(num):
    ans = float(num) / 255
    return ans

def convToByte(num):
    ans = float(num) * 255
    return int(round(ans))

def main():
    # Input text file 
    filename = sys.argv[1]
    if (filename != "byte.txt") and (filename != "float.txt"):
        quit()


    # Parce text file
    readfile = open(filename, 'r')
    for line in readfile:
        line = line.replace(',', "")
        line = line.split(' ')


    # Sort by Bytes and Floats
    kind = line[0]
    oString = ""
    oList = ['']
    if kind == "bytes":
        for curr in range(len(line)):
            if line[curr].isnumeric():
                oList.append(str(round(convToFloat(line[curr]),2)))
                oList.append(", ")

    elif kind == "floats":
        for curr in range(len(line)):
            line[curr] = line[curr].strip('\n') 
            line[curr] = line[curr].strip('f')
            if re.match(r'^-?\d+(?:\.\d+)$', line[curr]) is None:
                error = 1;                                              # Can't leave this blank and don't know how to inverse the ifstatement so the else is in the if
            else:
                oList.append(str(convToByte(line[curr])))
                oList.append(", ")


    oString = "".join(oList)
    oString = oString.rstrip(oString[-1])
    oString = oString.rstrip(oString[-1])

    print(oString)

    return 0



main()
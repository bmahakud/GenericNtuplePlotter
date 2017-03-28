fp = open("ClassReadSig.h")
import sys
sys.stdout = open('ClassReadSig.cc', 'w')

start1 = 0
start2 = 0
start3 = 0
for i, line in enumerate(fp):
    if "class ClassReadSig {" in line:
        #print "line number is = ",i
        start1 = 1
    if start1 == 1:
        print line
        if "}" in line:
            start1 = 0

    if "ClassReadSig::Init(" in line:
        #print "line number is = ",i
        start2 = 1
    if start2 == 1:
        print line
        if "}" in line:
            start2 = 0
    if "ClassReadSig::~ClassReadSig()" in line:
        start3 = 1
    if start3 == 1:
        print line
        if "}" in line:
            start3 = 0
fp.close()











































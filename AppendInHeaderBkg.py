


with open("ClassReadBkg.cc", "a") as f:
    f.write("ClassReadBkg::ClassReadBkg(TTree *tree)\n")
    f.write("{\n\tInit(tree);\n}")

with open("ClassReadBkg.cc", "r+") as f:
    old = f.read() # read everything in the file
    f.seek(0) # rewind
    f.write('#include<iostream>\n#include <TROOT.h>\n#include <TChain.h>\n#include <TFile.h>\n#include "TLorentzVector.h"\n#include<vector>\n#include "TTree.h"\nusing namespace std;\n\n' + old)









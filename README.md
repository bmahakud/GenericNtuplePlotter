This will provide all the info to use the generic plotter

Step1. Edit the InputDetails.dat file according to your need

Step2. Execute the following command to create a class using which you will read the Ntuple.The command is below
./Main.sh InputROOTfile.root  TreeMaker2/PreSelection

Step3. python MakeMasterReader.py
Above command will create a ROOT macro named MasterReader.C which will contain relevant lines of code to read the set of Input files that have been given in InputDetails.dat

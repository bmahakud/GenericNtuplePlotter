This will provide all the info to use the generic plotter

Step1. Edit the InputDetails.dat file according to your need

Step2. Execute the following command to create a ClassReadTree.cc using which you will read the Ntuple.The command is below
```
./Main.sh InputROOTfile.root  TreeMaker2/PreSelection
```
In the above command "TreeMaker2" is the directory name inside the root file and "PreSelection" is the Tree name.If you do not have any directory inside root file ..then give only the Tree name
Step3.
```
python MakeMasterReader.py
```
Above command will create a ROOT macro named MasterReader.C which will contain relevant lines of code to read the set of Input files that have been given in InputDetails.dat

Step4.
Now you can run the MasterReader.C in your terminal by executing the following command 

```
root -l MasterReader.C
```

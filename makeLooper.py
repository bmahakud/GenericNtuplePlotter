def getVarFromFile(filename):
    import imp
    f = open(filename)
    global data
    data = imp.load_source('data', '', f)
    f.close()

getVarFromFile('InputDetails.dat')
import os

import sys

sys.stdout = open('Looper.C','w')



print 'template <class classInst, class HistogramCreater> class Looper{'   

print 'public:\n'

print 'void Loop(TChain *tr,classInst& read,HistogramCreater hs, string ProcessName);\n'

print 'bool Baseline(TChain *tr,classInst& read,string ProcessName,int iEvent);\n'

print 'bool ProcessCuts(TChain *tr,classInst& read,string ProcessName,int iEvent);\n'

print '};\n'

print 'template <class classInst,class HistogramCreater> void Looper<classInst,HistogramCreater>::Loop(TChain *tr,classInst& read,HistogramCreater hs,string ProcessName)\n'
print '{//looper definition\n'

print 'string processes[%i]={'%(len(data.list_mc_sigNames)+len(data.list_mc_bkgNames)+len(data.list_dataNames)),
for name in data.list_mc_sigNames+data.list_mc_bkgNames+data.list_dataNames:
  print '"%s" '%(name),
  if name !=(data.list_mc_sigNames+data.list_mc_bkgNames+data.list_dataNames)[-1]:
      print ',',
print '};'

print 'string dataprocesses[%i]={'%(len(data.list_dataNames)),
for name in data.list_dataNames:
  print '"%s" '%(name),
  if name !=(data.list_dataNames)[-1]:
      print ',',
print '};'


print 'const int processesSize=%i;'%(len(data.list_mc_sigNames)+len(data.list_mc_bkgNames)+len(data.list_dataNames))
print '            auto it=std::find(processes,processes+processesSize,ProcessName);'
print '            int processInt=it-processes;'

print '       std::cout<<"Total number of entries: "<<tr->GetEntries()<<std::endl;\n'
print '       for(int iEv=0;iEv<tr->GetEntries();iEv++){// event loop\n'
print '       tr->GetEntry(iEv);\n'
print '          if(iEv % 1000==0)std::cout<<"Running on "<<ProcessName<<" event no: "<<iEv<<"---completed : "<<(float(iEv)/float(tr->GetEntries()))*100<<" %"<<std::endl;\n'

print '            if(Baseline(tr,read,ProcessName,iEv)  && ProcessCuts(tr,read,ProcessName, iEv)){ //Baseline for this processn\n'
print '            double EventWeight=1;'

#print '            bool exists = std::find(std::begin(dataprocesses), std::end(dataprocesses), ProcessName) != std::end(dataprocesses);'
print '            EventWeight=read.Weight;'


for icutvar in range(0, len(data.list_Categories)):
   for ivar in range(0, len(data.list_oneVariables)):
       
       print '         hs.h_[%i][processInt][%i]->Fill(read.%s,EventWeight); '%(ivar,icutvar,data.list_VarsFill[ivar]) 



print '               }//Baseline for this process\n'
print '       }//event loop\n'

print '}//looper definition\n'

print 'template <class classInst,class HistogramCreater> bool Looper<classInst,HistogramCreater>::Baseline(TChain *tr,classInst& read,string ProcessName,int iEvent){\n'

if (len(data.list_Baseline_cuts)==0):
   print 'return true;'

if(len(data.list_Baseline_cuts)>0):
    print 'if('
    for iCuts in range(0, len(data.list_Baseline_cuts)):
        print'read.',data.list_Baseline_cuts[iCuts]    
    print '){\n'

    print 'return true;\n'

    print '}'
    print 'else{'
    print 'return false;\n'
    print '}'


print '}\n'






print 'template <class classInst,class HistogramCreater> bool Looper<classInst,HistogramCreater>::ProcessCuts(TChain *tr,classInst& read,string ProcessName,int iEvent){\n'


for key in data.list_mc_sigNames_cuts:
   print 'if(ProcessName=="%s"){\n'%(key)
   if(len(data.list_mc_sigNames_cuts[key])>0):
      print 'if('
      for icutvars in range(0,len(data.list_mc_sigNames_cuts[key])):
          print 'read.',data.list_mc_sigNames_cuts[key][icutvars]
      print '){// cuts\n' 
   print 'return true;'
   if (len(data.list_mc_sigNames_cuts[key])>0):
       print '}\n// cuts'
   print '}\n'
   
for key in data.list_mc_bkgNames_cuts:
   print 'if(ProcessName=="%s"){\n'%(key)
   if(len(data.list_mc_bkgNames_cuts[key])>0):
      print 'if('
      for icutvars in range(0,len(data.list_mc_bkgNames_cuts[key])):
          print 'read.',data.list_mc_bkgNames_cuts[key][icutvars]
      print '){// cuts\n'
   print 'return true;'
   if (len(data.list_mc_bkgNames_cuts[key])>0):
       print '}\n// cuts'
   print '}\n'

for key in data.list_dataNames_cuts:
   print 'if(ProcessName=="%s"){\n'%(key)
   if(len(data.list_dataNames_cuts[key])>0):
      print 'if('
      for icutvars in range(0,len(data.list_dataNames_cuts[key])):
          print 'read.',data.list_dataNames_cuts[key][icutvars]
      print '){// cuts\n'
   print 'return true;'
   if (len(data.list_dataNames_cuts[key])>0):
       print '}\n// cuts'
   print '}\n'








print 'return false;'


print '}\n'




















sys.stdout.close()

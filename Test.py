def getVarFromFile(filename):
    import imp
    f = open(filename)
    global data
    data = imp.load_source('data', '', f)
    f.close()

getVarFromFile('InputDetails.dat')
import os

import sys


'''
for iname in data.list_VarsFill:
    if "UserDef_" in iname:
        print 'template <class classInst,class HistogramCreater> double Looper_sig<classInst,HistogramCreater>::%s(TChain *tr,classInst& read,string ProcessName,int iEvent){\n'%(iname),
        print 'return true;'
        print '}\n'



for iname in data.list_VarsFill:
    print iname
    if "UserDef_" in iname:
        print 'double %s(TChain *tr,classInst& read,string ProcessName,int iEvent);'%(iname)

'''


for icutvar in range(0, len(data.list_Categories)):
   #print 'if(%s(tr,read,ProcessName,iEv)){'%(data.list_Categories[icutvar])
   for ivar in range(0, len(data.list_oneVariables)):
       print data.list_VarsFill[ivar]
       if "UserDef_" not in str(data.list_VarsFill[ivar]):
           print 'TIFR1'#         hs.h_[%i][processInt][%i]->Fill(read.%s,EventWeight); '%(ivar,icutvar,data.list_VarsFill[ivar])
       elif "UserDef_" in data.list_VarsFill[ivar]:
           print 'TIFR2'#hs.h_[%i][processInt][%i]->Fill(%s(tr,read,ProcessName,iEv); '%(ivar,icutvar,data.list_VarsFill[ivar])
   print '};'













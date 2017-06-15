def getVarFromFile(filename):
    import imp
    f = open(filename)
    global data
    data = imp.load_source('data', '', f)
    f.close()

getVarFromFile('InputDetails.dat')
import os





   #print content

import sys
sys.stdout = open('Loader.C','w')

print 'class Loader{\n '


print 'public:'


print 'TChain *Load(string ProcessName);'


 
print '};'

print 'TChain *Loader::Load(string ProcessName="TTJets"){'



for isig in range(0,len(data.list_mc_sig)):
   cdir=os.getcwd()
   fileN="cd "+data.fileLocation_sig+" && ls -1 "+data.list_mc_sig[isig]+" > "+cdir+"/Sig.dat"
   os.system(fileN)
   with open("Sig.dat") as f:
      FNameList = f.readlines()
   FNameList = [x.strip() for x in FNameList] 
   create ="./MainSig.sh %s%s %s %s"%(data.fileLocation_sig,FNameList[0],data.treeName_sig,"ClassReadSig")
   os.system(create)
   print 'if(ProcessName=="%s"){'%(data.list_mc_sigNames[isig])
   print 'TChain *tr_%s=new TChain("%s");'%(data.list_mc_sigNames[isig],data.treeName_sig)
   for ifn in range(0,len(FNameList)):
      print 'tr_%s->Add("%s%s");'%(data.list_mc_sigNames[isig],data.store_mc_sig,FNameList[ifn])
   print 'cout<<"Total events present in process %s: "<<tr_%s->GetEntries()<<endl;'%(data.list_mc_sigNames[isig],data.list_mc_sigNames[isig])
   print 'return tr_%s;'%(data.list_mc_sigNames[isig])
   print '\n}'

Del= "rm Sig.dat"
os.system(Del)

for ibkg in range(0,len(data.list_mc_bkg)):
   cdir=os.getcwd()
   fileN="cd "+data.fileLocation_bkg+" && ls -1 "+data.list_mc_bkg[ibkg]+" > "+cdir+"/Bkg.dat"
   os.system(fileN)
   with open("Bkg.dat") as f:
      FNameList = f.readlines()
   FNameList = [x.strip() for x in FNameList] 
   create ="./MainBkg.sh %s%s %s %s"%(data.fileLocation_bkg,FNameList[0],data.treeName_bkg,"ClassReadBkg")
   os.system(create)
   print 'if(ProcessName=="%s"){'%(data.list_mc_bkgNames[ibkg])
   print 'TChain *tr_%s=new TChain("%s");'%(data.list_mc_bkgNames[ibkg],data.treeName_bkg)
   for ifn in range(0,len(FNameList)):
      print 'tr_%s->Add("%s%s");'%(data.list_mc_bkgNames[ibkg],data.store_mc_bkg,FNameList[ifn])
   print 'cout<<"Total events present in process %s: "<<tr_%s->GetEntries()<<endl;'%(data.list_mc_bkgNames[ibkg],data.list_mc_bkgNames[ibkg])
   print 'return tr_%s;'%(data.list_mc_bkgNames[ibkg])
   print '\n}'

Del= "rm Bkg.dat"
os.system(Del)

for idata in range(0,len(data.list_data)):
   cdir=os.getcwd()
   fileN="cd "+data.fileLocation_data+" && ls -1 "+data.list_data[idata]+" > "+cdir+"/Data.dat"
   os.system(fileN)
   with open("Data.dat") as f:
      FNameList = f.readlines()
   FNameList = [x.strip() for x in FNameList] 
   create ="./MainData.sh %s%s %s %s"%(data.fileLocation_data,FNameList[0],data.treeName_data,"ClassReadData")
   os.system(create)
   print 'if(ProcessName=="%s"){'%(data.list_dataNames[idata])
   print 'TChain *tr_%s=new TChain("%s");'%(data.list_dataNames[idata],data.treeName_data)
   for ifn in range(0,len(FNameList)):
      print 'tr_%s->Add("%s%s");'%(data.list_dataNames[idata],data.store_data,FNameList[ifn])
   print 'cout<<"Total events present in process %s: "<<tr_%s->GetEntries()<<endl;'%(data.list_dataNames[idata],data.list_dataNames[idata])
   print 'return tr_%s;'%(data.list_dataNames[idata])
   print '\n}'



print 'else{\n'
print 'throw std::invalid_argument( "You have provided an in valid argument , Try to look into the Inputdetails.dat and put a correct argument" );\n'
print '\n}'



print '}'

remove="./Remove.sh"
os.system(remove)

Del= "rm Data.dat"
os.system(Del)

sys.stdout.close()


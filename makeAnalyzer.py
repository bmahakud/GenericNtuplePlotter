def getVarFromFile(filename):
    import imp
    f = open(filename)
    global data
    data = imp.load_source('data', '', f)
    f.close()

getVarFromFile('InputDetails.dat')
import os

import sys

sys.stdout = open('Analyzer.C','w')

############    include Header files    ##########################
print '#include<iostream>\n#include <TROOT.h>\n#include <TChain.h>\n#include <TFile.h>\n#include "TLorentzVector.h"\n#include<vector>\n#include "TTree.h" \n#include "TH1F.h"\n#include "TPaveText.h"\n#include "ClassReadSig.cc"\n#include "ClassReadBkg.cc"\n#include "ClassReadData.cc"\n#include "Loader.C"\n#include "Looper_sig.C"\n#include "Looper_bkg.C"\n#include "Looper_data.C"\n#include "stackPlotter.C"\n#include "HistCreater.C"\nusing namespace std;\n\n'

#for icut in range(0,len(data.Categories)):


print 'void Analyzer(){\n '


print 'Loader L;'
print '\n\n'
print 'TFile *f=new TFile("Histograms.root","RECREATE");'
print 'HistCreater hs;'

if(len(data.list_mc_sigNames)>0):
   print 'Looper_sig<ClassReadSig,HistCreater> loop_s;'

print '\n\n'
for isg in range(0,len(data.list_mc_sigNames)):
   print 'TChain *tree_%s=L.Load("%s");'%(data.list_mc_sigNames[isg],data.list_mc_sigNames[isg])
   print 'ClassReadSig %s(tree_%s);'%(data.list_mc_sigNames[isg],data.list_mc_sigNames[isg])
   print 'loop_s.Loop(tree_%s,%s,hs,"%s");'%(data.list_mc_sigNames[isg],data.list_mc_sigNames[isg],data.list_mc_sigNames[isg])
   print '\n\n'

print '\n\n\n'

if(len(data.list_mc_bkgNames)>0):
   print 'Looper_bkg<ClassReadBkg,HistCreater> loop_b;'
for ibk in range(0,len(data.list_mc_bkgNames)):
   print 'TChain *tree_%s=L.Load("%s");'%(data.list_mc_bkgNames[ibk],data.list_mc_bkgNames[ibk])
   print 'ClassReadBkg %s(tree_%s);'%(data.list_mc_bkgNames[ibk],data.list_mc_bkgNames[ibk])
   print 'loop_b.Loop(tree_%s,%s,hs,"%s");'%(data.list_mc_bkgNames[ibk],data.list_mc_bkgNames[ibk],data.list_mc_bkgNames[ibk])
   print '\n\n'

print '\n\n\n'



if(len(data.list_dataNames)>0):
   print 'Looper_data<ClassReadData,HistCreater> loop_d;'
for ida in range(0,len(data.list_dataNames)):
   print 'TChain *tree_%s=L.Load("%s");'%(data.list_dataNames[ida],data.list_dataNames[ida])
   print 'ClassReadData %s(tree_%s);'%(data.list_dataNames[ida],data.list_dataNames[ida])
   print 'loop_d.Loop(tree_%s,%s,hs,"%s");'%(data.list_dataNames[ida],data.list_dataNames[ida],data.list_dataNames[ida])
   print '\n\n'



print '//sample tav text could be used as argument to the stack plotter  '


print 'TPaveText *tpav_txt = new TPaveText(0.57043478,0.548342,0.8652174,0.9210471,"brNDC");'

print '    tpav_txt->SetBorderSize(0);'
print '    tpav_txt->SetFillStyle(0);'
print '    tpav_txt->SetTextAlign(11);'
print '    tpav_txt->SetTextFont(42);'
print '    tpav_txt->SetTextSize(0.04);'
print '    tpav_txt->AddText("HT >500");'
print '    tpav_txt->AddText("#gamma p_{T} > 100 ");'
print '    tpav_txt->AddText("NJets >=4");'
print '    tpav_txt->AddText("MHT>200");'
print '    tpav_txt->AddText("BTags=0");'





print '//Example of how to use stack plotter'

print 'StackPlotter stack;\n'
print '//uncomment the following line. put histogram names correctly'
print '//sample arguments if you want to plot one signal,5 background and no data then use the function plotS1B5D0'
print '//if you want to use data then use the function plotS1B5D1, this way you can use all possible combinations '


print '//use following procees nums'

for ipro in range(0,len(data.list_mc_sigNames+data.list_mc_bkgNames+data.list_dataNames)):
    print "//",(data.list_mc_sigNames+data.list_mc_bkgNames+data.list_dataNames)[ipro],"-",ipro,"  ",
print '\n'
print 'stack.plotS1B3D0("HT(GeV)",tpav_txt,hs.h_[0][0][0],"ZH_mG750",hs.h_[0][3][0],"ZJets",hs.h_[0][4][0],"QCD",hs.h_[0][5][0],"TTJets");'

print '\n'
print 'f->Write();'

print '\n}'


sys.stdout.close()



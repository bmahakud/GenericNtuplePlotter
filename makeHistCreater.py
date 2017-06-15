def getVarFromFile(filename):
    import imp
    f = open(filename)
    global data
    data = imp.load_source('data', '', f)
    f.close()

getVarFromFile('InputDetails.dat')
import os

import sys


sys.stdout = open("HistCreater.C",'w')
print '#include "TH1F.h"'
print '\n'
print 'class HistCreater{\n'
print 'public:'

print 'TH1F *h_[%i][%i][%i];'%(len(data.list_oneVariables),len(data.list_mc_sigNames)+len(data.list_mc_bkgNames)+len(data.list_dataNames),len(data.list_Categories));
#print 'TH1F *hbkg_[%i][%i][%i];'%(len(data.list_oneVariables),len(data.list_mc_bkgNames),len(data.list_Categories));
#print 'TH1F *hdata_[%i][%i][%i];'%(len(data.list_oneVariables),len(data.list_dataNames),len(data.list_Categories));

print 'HistCreater();'



print '};'


print 'HistCreater::HistCreater(){'

for ivar in range(0, len(data.list_oneVariables)):
          listN='list_%s_range'%(data.list_oneVariables[ivar])
          varRange = getattr(data, listN)
          Nbins=len(varRange)-1
          print 'int nBins_%s = %i;'%(data.list_oneVariables[ivar],Nbins)
          print 'double %s_range[%i] = {'%(data.list_oneVariables[ivar],len(varRange)),
          for ir in range(0,len(varRange)):
            if ir !=0:
               print ',',
            print '%f'%(varRange[ir]),
          print '};'
          for isig in range(0,len(data.list_mc_sigNames)):
             for icut in range(0,len(data.list_Categories)):
                print 'h_[%i][%i][%i] =new TH1F("h_%s_%s_%s","h_%s_%s_%s",nBins_%s,%s_range);'%(ivar,isig,icut,data.list_oneVariables[ivar],data.list_mc_sigNames[isig],data.list_Categories[icut],data.list_oneVariables[ivar],data.list_mc_sigNames[isig],data.list_Categories[icut],data.list_oneVariables[ivar],data.list_oneVariables[ivar])
          for ibkg in range(0,len(data.list_mc_bkgNames)):
             for icut in range(0,len(data.list_Categories)):
                print 'h_[%i][%i][%i] =new TH1F("h_%s_%s_%s","h_%s_%s_%s",nBins_%s,%s_range);'%(ivar,len(data.list_mc_sigNames)+ibkg,icut,data.list_oneVariables[ivar],data.list_mc_bkgNames[ibkg],data.list_Categories[icut],data.list_oneVariables[ivar],data.list_mc_bkgNames[ibkg],data.list_Categories[icut],data.list_oneVariables[ivar],data.list_oneVariables[ivar])
          for idata in range(0,len(data.list_dataNames)):
             for icut in range(0,len(data.list_Categories)):
                print 'h_[%i][%i][%i] =new TH1F("h_%s_%s_%s","h_%s_%s_%s",nBins_%s,%s_range);'%(ivar,len(data.list_mc_sigNames)+len(data.list_mc_bkgNames)+idata,icut,data.list_oneVariables[ivar],data.list_dataNames[idata],data.list_Categories[icut],data.list_oneVariables[ivar],data.list_dataNames[idata],data.list_Categories[icut],data.list_oneVariables[ivar],data.list_oneVariables[ivar])



print '\n}'
sys.stdout.close()

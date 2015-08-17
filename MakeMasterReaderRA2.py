import sys
sys.stdout = open('MasterReader.C','w')

############    include Header files    ##########################
print '#include<iostream>\n#include "computeBin.C"\n#include <TROOT.h>\n#include <TChain.h>\n#include <TFile.h>\n#include "TLorentzVector.h"\n#include<vector>\n#include "TTree.h"\n#include "ClassReadTree.cc"\nusing namespace std;\n\n'



print 'void MasterReader(){\n '

############    Start:: Reading the input file where variables stored    ##########################

def getVarFromFile(filename):
    import imp
    f = open(filename)
    global data
    data = imp.load_source('data', '', f)
    f.close()

getVarFromFile('InputDetails.dat')








for a in range(0,len(data.list_mc_sig)):
    print '\tTChain* t%i_mc_sig = new TChain("%s");'% (a, data.treeName)
    print '\t\tt%i_mc_sig->Add("%s%s");'%(a, data.store_mc_sig, data.list_mc_sig[a])
    print '\t\tClassReadTree mc_sig_%i(t%i_mc_sig);'%(a, a)
    print '\t\tfor(int iEv_%i_mc_sig=0;iEv_%i_mc_sig < t%i_mc_sig->GetEntries();iEv_%i_mc_sig++){'%(a, a, a, a)
    print '\t\t\tt%i_mc_sig->GetEntry(iEv_%i_mc_sig);'%(a, a)   
    print 'if(mc_sig_%i.Baseline( mc_sig_%i.HTclean, mc_sig_%i.MHTclean , mc_sig_%i.NJetsclean, mc_sig_%i.DeltaPhi1 ,mc_sig_%i.DeltaPhi2 ,mc_sig_%i.DeltaPhi3)){'%(a, a, a, a, a, a, a)
    print 'std::cout<<"got an event after base line "<<std::endl;'
    print 'int i_iEv_%i_mc_sig=mc_sig_%i.JetID; '%(a ,a)
    print 'if(i_iEv_%i_mc_sig==1){'%(a)
    print 'if(mc_sig_%i.photonCands->size()==1){//photon loop'%(a)
    print 'if(mc_sig_%i.photon_isEB->at(0)==1  ){//barrel photon'%(a)






    print '\n}//barrel photon'
    print '\n}//photon loop'
    print '\n}'
    print '\n}'
    print '\t\t}'
    print '\n'

for a in range(0,len(data.list_mc_bkg)):
    print '\tTChain* t%i_mc_bkg = new TChain("%s");'%(a, data.treeName)
    print '\t\tt%i_mc_bkg->Add("%s%s");'%(a, data.store_mc_bkg, data.list_mc_bkg[a])
    print '\t\tClassReadTree mc_bkg_%i(t%i_mc_bkg);'%(a, a)
    print '\t\tfor(int iEv_%i_mc_bkg=0;iEv_%i_mc_bkg < t%i_mc_bkg->GetEntries();iEv_%i_mc_bkg++){'%(a, a, a, a)
    print '\t\t\tt%i_mc_bkg->GetEntry(iEv_%i_mc_bkg);'%(a, a)   
    print 'if(mc_bkg_%i.Baseline(mc_bkg_%i.HTclean, mc_bkg_%i.MHTclean , mc_bkg_%i.NJetsclean, mc_bkg_%i.DeltaPhi1 ,mc_bkg_%i.DeltaPhi2 ,mc_bkg_%i.DeltaPhi3)){'%(a, a, a, a, a, a, a)
    print 'int i_iEv_%i_mc_bkg=mc_sig_%i.JetID; '%(a ,a)
    print 'if(i_iEv_%i_mc_bkg==1){'%(a)
    print 'if(mc_bkg_%i.photonCands->size()==1){//photon loop'%(a)
    print 'if(mc_bkg_%i.photon_isEB->at(0)==1  ){//barrel photon'%(a)






    print '\n}//barrel photon'
    print '\n}//photon loop'

    print '\n}'


    print '\n}'
    print '\t\t}'
    print '\n'

for a in range(0,len(data.list_data)):
    print '\tTChain* t%i_data = new TChain("%s");'%(a, data.treeName)
    print '\t\tt%i_data->Add("%s%s");'%(a, data.store_data, data.list_data[a])
    print '\t\tClassReadTree mc_data_%i(t%i_data);'%(a, a)
    print '\t\tfor(int iEv_%i_data=0;iEv_%i_data < t%i_data->GetEntries();iEv_%i_data++){'%(a, a, a, a)
    print '\t\t\tt%i_data->GetEntry(iEv_%i_data);'%(a, a)  
    print '\t\t}'
    print '\n'






print '\n}'



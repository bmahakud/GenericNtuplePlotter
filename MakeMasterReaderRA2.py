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


print 'TFile *fsie=new TFile("SigmaIetaIeta.root","RECREATE");'
   
numSigf=len(data.list_mc_sig)
numBkgf=len(data.list_mc_bkg)

print 'TH1F  *h_Sig_bins[72][%i];'%(numSigf)
print 'TH1F  *h_Bkg_bins[72][%i];'%(numBkgf)

print 'char h_sig[100];'
print 'char h_bkg[100];'


print 'for(int i=0;i<72;i++){//loop bins'
print 'for(int j=0;j<%i;j++){//loop files signal'%(numSigf)

print 'sprintf(h_sig,"sigmaIeta_sig_%i_%i",i,j);'
print 'h_Sig_bins[i][j]=new TH1F(h_sig,h_sig,100,0,0.04);'

print '\n}//loop files signal'

print 'for(int j=0;j<%i;j++){//loop files bkg'%(numBkgf)
print 'sprintf(h_bkg,"sigmaIeta_bkg_%i_%i",i,j);'
print 'h_Bkg_bins[i][j]=new TH1F(h_bkg,h_bkg,100,0,0.04);'


print '\n}//loop files bkg'
print '\n}//loop bins'



for a in range(0,len(data.list_mc_sig)):
    print '\tTChain* t%i_mc_sig = new TChain("%s");'% (a, data.treeName)
    print '\t\tt%i_mc_sig->Add("%s%s");'%(a, data.store_mc_sig, data.list_mc_sig[a])
    print '\t\tClassReadTree mc_sig_%i(t%i_mc_sig);'%(a, a)
    print '\t\tfor(int iEv_%i_mc_sig=0;iEv_%i_mc_sig < t%i_mc_sig->GetEntries();iEv_%i_mc_sig++){'%(a, a, a, a)
    print 'if( iEv_%i_mc_sig  5000 == 0 ) cout << "event: " << iEv_%i_mc_sig << endl;'%(a, a)
    print '\t\t\tt%i_mc_sig->GetEntry(iEv_%i_mc_sig);'%(a, a)   
    print 'if(mc_sig_%i.Baseline( mc_sig_%i.HTclean, mc_sig_%i.MHTclean , mc_sig_%i.NJetsclean, mc_sig_%i.DeltaPhi1 ,mc_sig_%i.DeltaPhi2 ,mc_sig_%i.DeltaPhi3)){'%(a, a, a, a, a, a, a)
    #print 'std::cout<<"got an event after base line "<<std::endl;'
    print 'int i_iEv_%i_mc_sig=mc_sig_%i.JetID; '%(a ,a)
    print 'if(i_iEv_%i_mc_sig==1){'%(a)
    print 'if(mc_sig_%i.photonCands->size()==1){//photon loop'%(a)
    print 'if(mc_sig_%i.photon_isEB->at(0)==1  ){//barrel photon'%(a)
    print 'if(mc_sig_%i.PassSBIso(mc_sig_%i.photon_pfChargedIsoRhoCorr->at(0),mc_sig_%i.photon_pfNeutralIsoRhoCorr->at(0),mc_sig_%i.photon_pfGammaIsoRhoCorr->at(0),mc_sig_%i.photonCands->at(0).Pt())){//side band photon'%(a, a, a, a, a)
   
    print 'if(mc_sig_%i.photon_nonPrompt->at(0)==0){//prompt photons'%(a)
   
    #print 'cout<<"got prompt photons from signal region"<<endl;'

    print 'unsigned int bin_sig=computeBin(mc_sig_%i.MHTclean,mc_sig_%i.HTclean,mc_sig_%i.NJetsclean,mc_sig_%i.BTagsclean,k13TeV);'%(a, a, a, a)

    print 'h_Sig_bins[bin_sig][%i]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(0));'%(a, a) 

    print '\n}//prompt photons'
    print '\n}//side band photon'
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
    print 'if( iEv_%i_mc_bkg  5000 == 0 ) cout << "event: " << iEv_%i_mc_bkg << endl;'%(a, a)
    print '\t\t\tt%i_mc_bkg->GetEntry(iEv_%i_mc_bkg);'%(a, a)   
    print 'if(mc_bkg_%i.Baseline(mc_bkg_%i.HTclean, mc_bkg_%i.MHTclean , mc_bkg_%i.NJetsclean, mc_bkg_%i.DeltaPhi1 ,mc_bkg_%i.DeltaPhi2 ,mc_bkg_%i.DeltaPhi3)){'%(a, a, a, a, a, a, a)
    print 'int i_iEv_%i_mc_bkg=mc_bkg_%i.JetID; '%(a ,a)
    print 'if(i_iEv_%i_mc_bkg==1){'%(a)
    print 'if(mc_bkg_%i.photonCands->size()==1){//photon loop'%(a)
    print 'if(mc_bkg_%i.photon_isEB->at(0)==1  ){//barrel photon'%(a)
    print 'if(mc_bkg_%i.PassSBIso(mc_bkg_%i.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_%i.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_%i.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_%i.photonCands->at(0).Pt())){//side band photon'%(a, a, a, a, a)
   
    print 'if(mc_bkg_%i.photon_nonPrompt->at(0)==1){//non prompt photons'%(a)
   
    print 'cout<<"got prompt photons from signal region"<<endl;'

    print 'int bin_bkg=computeBin(mc_bkg_%i.MHTclean,mc_bkg_%i.HTclean,mc_bkg_%i.NJetsclean,mc_bkg_%i.BTagsclean,k13TeV);'%(a, a, a, a)
    print 'h_Bkg_bins[bin_bkg][%i]->Fill(mc_bkg_%i.photon_sigmaIetaIeta->at(0));'%(a, a)

    print '\n}//non prompt photons'
    print '\n}//side band photon'
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





print 'fsie->Write();'
print '\n}'



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

print 'TH1F  *h_Sig_bins[%i][60];'%(numSigf)
print 'TH1F  *h_Bkg_bins[%i][60];'%(numBkgf)

print 'char h_sig[100];'
print 'char h_bkg[100];'


print 'for(int i=0;i<60;i++){//loop bins'
print 'for(int j=0;j<%i;j++){//loop files signal'%(numSigf)

print 'sprintf(h_sig,"SiIeta_sig_%i_%i_h",i,j);'
print 'h_Sig_bins[j][i]=new TH1F(h_sig,h_sig,200,0,0.05);'

print '\n}//loop files signal'

print 'for(int j=0;j<%i;j++){//loop files bkg'%(numBkgf)
print 'sprintf(h_bkg,"SiIeta_bkg_%i_%i_h",i,j);'
print 'h_Bkg_bins[j][i]=new TH1F(h_bkg,h_bkg,200,0,0.05);'


print '\n}//loop files bkg'
print '\n}//loop bins'




for a in range(0,len(data.list_mc_sig)):
    print '\tTChain* t%i_mc_sig = new TChain("%s");'% (a, data.treeName)

    print '\t\tt%i_mc_sig->Add("%s%s");'%(a, data.store_mc_sig, data.list_mc_sig[a])

    print '\t\tClassReadTree mc_sig_%i(t%i_mc_sig);'%(a, a)

    print '\t\tfor(int iEv_%i_mc_sig=0;iEv_%i_mc_sig < t%i_mc_sig->GetEntries();iEv_%i_mc_sig++){//event loop signal'%(a, a, a, a)

    print '\t\tif( iEv_%i_mc_sig  5000 == 0 ) cout << "event: " << iEv_%i_mc_sig << endl;'%(a, a)

    print '\t\t\tt%i_mc_sig->GetEntry(iEv_%i_mc_sig);'%(a, a)   
   
    print '\t\tint iPh_%i=-1;'%(a)
    print '\t\tfloat PhPt_%i=0;'%(a)

    print  'for(int iPh=0;iPh<mc_sig_%i.photonCands->size();iPh++){//photon loop'%(a)
    print  'if(mc_sig_%i.photonCands->at(iPh).Pt() > PhPt_%i){'%(a, a)
    print  'PhPt_%i=mc_sig_%i.photonCands->at(iPh).Pt();'%(a, a)       
    print  'iPh_%i=iPh;'%(a)
    print  '}'
    print  ' }//photon loop'

    print '//////////////////'
 
    print  'if(iPh_%i !=-1  && mc_sig_%i.photon_isEB->at(iPh_%i)==1){//Leading Pt Photon'%(a, a, a)
    print  'if(mc_sig_%i.PassSigFull(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][0]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBFull(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][1]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCut(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][2]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCut(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][3]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    
    print  'if(mc_sig_%i.PassSigFullPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][4]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_sig_%i.PassSBFullPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][5]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCutPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][6]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCutPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][7]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)

    print  'if(mc_sig_%i.PassSigFullNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][8]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_sig_%i.PassSBFullNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][9]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCutNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][10]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCutNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][11]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)


    print  'if(mc_sig_%i.PassNJetslow()){//low Njet'%(a)
    print  'if(mc_sig_%i.PassSigFull(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][12]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBFull(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][13]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCut(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][14]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCut(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][15]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
 
    print  'if(mc_sig_%i.PassSigFullPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][16]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_sig_%i.PassSBFullPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][17]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCutPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][18]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCutPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][19]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)

    print  'if(mc_sig_%i.PassSigFullNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][20]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_sig_%i.PassSBFullNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][21]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCutNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][22]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCutNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][23]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)


    print  '}//low Njet'

    print  'if(mc_sig_%i.PassNJetshigh()){//high Njet'%(a)
    print  'if(mc_sig_%i.PassSigFull(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][24]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBFull(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][25]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCut(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][26]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCut(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][27]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    
    print  'if(mc_sig_%i.PassSigFullPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][28]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_sig_%i.PassSBFullPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][29]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCutPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][30]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCutPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][31]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)

    print  'if(mc_sig_%i.PassSigFullNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][32]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_sig_%i.PassSBFullNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][33]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCutNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][34]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCutNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][35]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)  

    print '}//high Njet'

     
    print  'if(mc_sig_%i.PassHTlow()){//low HT'%(a)

    print  'if(mc_sig_%i.PassSigFull(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][36]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBFull(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][37]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCut(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][38]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCut(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][39]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    
    print  'if(mc_sig_%i.PassSigFullPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][40]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_sig_%i.PassSBFullPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][41]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCutPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][42]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCutPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][43]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)

    print  'if(mc_sig_%i.PassSigFullNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][44]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_sig_%i.PassSBFullNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][45]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCutNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][46]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCutNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][47]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)


    print   '}//low HT'
    print  'if(mc_sig_%i.PassHThigh()){//high HT'%(a)

    print  'if(mc_sig_%i.PassSigFull(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][48]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBFull(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][49]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCut(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][50]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCut(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][51]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    
    print  'if(mc_sig_%i.PassSigFullPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][52]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_sig_%i.PassSBFullPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][53]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCutPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][54]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCutPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][55]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)

    print  'if(mc_sig_%i.PassSigFullNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][56]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_sig_%i.PassSBFullNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][57]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSigCutNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][58]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_sig_%i.PassSBCutNonPrompt(iEv_%i_mc_sig,iPh_%i)){h_Sig_bins[%i][59]->Fill(mc_sig_%i.photon_sigmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    
    print   '}//high HT'

    print '}//Leading Pt Photon'








    print '\t\t\n}//event loop signal'




for a in range(0,len(data.list_mc_bkg)):
    print '\tTChain* t%i_mc_bkg = new TChain("%s");'% (a, data.treeName)

    print '\t\tt%i_mc_bkg->Add("%s%s");'%(a, data.store_mc_bkg, data.list_mc_bkg[a])

    print '\t\tClassReadTree mc_bkg_%i(t%i_mc_bkg);'%(a, a)

    print '\t\tfor(int iEv_%i_mc_bkg=0;iEv_%i_mc_bkg < t%i_mc_bkg->GetEntries();iEv_%i_mc_bkg++){//event loop bkg_%i'%(a, a, a, a, a)

    print '\t\tif( iEv_%i_mc_bkg  5000 == 0 ) cout << "event: " << iEv_%i_mc_bkg << endl;'%(a, a)

    print '\t\t\tt%i_mc_bkg->GetEntry(iEv_%i_mc_bkg);'%(a, a)   
   

    print '\t\tint iPh_%i=-1;'%(a)
    print '\t\tfloat PhPt_%i=0;'%(a)

    print  'for(int iPh=0;iPh<mc_bkg_%i.photonCands->size();iPh++){//photon loop'%(a)
    print  'if(mc_bkg_%i.photonCands->at(iPh).Pt() > PhPt_%i){'%(a, a)
    print  'PhPt_%i=mc_bkg_%i.photonCands->at(iPh).Pt();'%(a, a)       
    print  'iPh_%i=iPh;'%(a)
    print  '}'
    print  ' }//photon loop'


 
     
    print  'if(iPh_%i !=-1  && mc_bkg_%i.photon_isEB->at(iPh_%i)==1){//Leading Pt Photon'%(a, a, a)
    print  'if(mc_bkg_%i.PassSigFull(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][0]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBFull(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][1]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCut(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][2]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCut(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][3]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    
    print  'if(mc_bkg_%i.PassSigFullPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][4]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_bkg_%i.PassSBFullPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][5]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCutPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][6]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCutPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][7]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)

    print  'if(mc_bkg_%i.PassSigFullNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][8]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_bkg_%i.PassSBFullNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][9]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCutNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][10]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCutNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][11]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)


    print  'if(mc_bkg_%i.PassNJetslow()){//low Njet'%(a)
    print  'if(mc_bkg_%i.PassSigFull(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][12]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBFull(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][13]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCut(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][14]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCut(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][15]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
 
    print  'if(mc_bkg_%i.PassSigFullPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][16]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_bkg_%i.PassSBFullPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][17]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCutPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][18]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCutPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][19]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)

    print  'if(mc_bkg_%i.PassSigFullNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][20]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_bkg_%i.PassSBFullNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][21]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCutNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][22]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCutNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][23]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)


    print  '}//low Njet'

    print  'if(mc_bkg_%i.PassNJetshigh()){//high Njet'%(a)
    print  'if(mc_bkg_%i.PassSigFull(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][24]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBFull(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][25]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCut(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][26]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCut(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][27]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    
    print  'if(mc_bkg_%i.PassSigFullPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][28]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_bkg_%i.PassSBFullPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][29]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCutPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][30]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCutPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][31]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)

    print  'if(mc_bkg_%i.PassSigFullNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][32]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_bkg_%i.PassSBFullNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][33]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCutNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][34]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCutNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][35]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)  

    print '}//high Njet'

     

    print  'if(mc_bkg_%i.PassHTlow()){//low HT'%(a)

    print  'if(mc_bkg_%i.PassSigFull(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][36]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBFull(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][37]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCut(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][38]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCut(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][39]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    
    print  'if(mc_bkg_%i.PassSigFullPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][40]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_bkg_%i.PassSBFullPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][41]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCutPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][42]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCutPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][43]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)

    print  'if(mc_bkg_%i.PassSigFullNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][44]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_bkg_%i.PassSBFullNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][45]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCutNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][46]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCutNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][47]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)


    print   '}//low HT'
    print  'if(mc_bkg_%i.PassHThigh()){//high HT'%(a)

    print  'if(mc_bkg_%i.PassSigFull(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][48]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBFull(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][49]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCut(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][50]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCut(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][51]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    
    print  'if(mc_bkg_%i.PassSigFullPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][52]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_bkg_%i.PassSBFullPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][53]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCutPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][54]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCutPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][55]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)

    print  'if(mc_bkg_%i.PassSigFullNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][56]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)    
    print  'if(mc_bkg_%i.PassSBFullNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][57]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSigCutNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][58]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    print  'if(mc_bkg_%i.PassSBCutNonPrompt(iEv_%i_mc_bkg,iPh_%i)){h_Bkg_bins[%i][59]->Fill(mc_bkg_%i.photon_bkgmaIetaIeta->at(iPh_%i));}'%(a, a, a, a, a, a)
    
    print   '}//high HT'

    print '}//Leading Pt Photon'
   



    print '\t\t\n}//event loop bkg_%i'%(a)














print '\t\n}'

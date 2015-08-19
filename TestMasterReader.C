#include<iostream>
#include "computeBin.C"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include<vector>
#include "TTree.h"
#include "ClassReadTree.cc"
using namespace std;


void TestMasterReader(){

//





/////////////////////////////////////

  TFile *fh=new TFile("SigmaIetaIetaAll.root","RECREATE");

 TChain* t = new TChain("TreeMaker2/PreSelection");
 t->Add("/home/bibhu/Desktop/PhD/DevelopingMakeClassCode/GenericNtuplePlotter/Ntuples/Spring15.GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root");



  ClassReadTree GJ(t);

  int passEvent=0;
  //int EvPass[60]={0};

  TH1F *EvPass[60];
  
  char hevPass[100];
   

 for(int j=0;j<60;j++){
 sprintf(hevPass,"h_Sigma%i_eta",j);
  EvPass[j]=new TH1F(hevPass,hevPass,200,0,0.05);

  }

  cout<<"Total events present : "<<t->GetEntries()<<endl;

 for(int iEv=0;iEv<400000;iEv++){
    t->GetEntry(iEv);
    
   if( iEv  % 5000 == 0 ) cout << "event: " << iEv << endl;
    
    int iPh=-1;
    float PhPt=0;
                  for(int iPh1=0;iPh1<GJ.photonCands->size();iPh1++){//photon loop
                  if(GJ.photonCands->at(iPh1).Pt() > PhPt){
                  PhPt=GJ.photonCands->at(iPh1).Pt();       
                  iPh=iPh1;
                    }
                    }//photon loop
   


   if(iPh !=-1  && GJ.photon_isEB->at(iPh)==1){//Leading Pt Photon
   if(GJ.PassSigFull(iEv,iPh)){EvPass[0]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBFull(iEv,iPh)){EvPass[1]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCut(iEv,iPh)){EvPass[2]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCut(iEv,iPh)){EvPass[3]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
    
   if(GJ.PassSigFullPrompt(iEv,iPh)){EvPass[4]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}    
   if(GJ.PassSBFullPrompt(iEv,iPh)){EvPass[5]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCutPrompt(iEv,iPh)){EvPass[6]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCutPrompt(iEv,iPh)){EvPass[7]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}

   if(GJ.PassSigFullNonPrompt(iEv,iPh)){EvPass[8]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}    
   if(GJ.PassSBFullNonPrompt(iEv,iPh)){EvPass[9]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCutNonPrompt(iEv,iPh)){EvPass[10]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCutNonPrompt(iEv,iPh)){EvPass[11]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}


   if(GJ.PassNJetslow()){//low Njet
   if(GJ.PassSigFull(iEv,iPh)){EvPass[12]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBFull(iEv,iPh)){EvPass[13]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCut(iEv,iPh)){EvPass[14]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCut(iEv,iPh)){EvPass[15]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
 
   if(GJ.PassSigFullPrompt(iEv,iPh)){EvPass[16]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}    
   if(GJ.PassSBFullPrompt(iEv,iPh)){EvPass[17]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCutPrompt(iEv,iPh)){EvPass[18]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCutPrompt(iEv,iPh)){EvPass[19]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}

   if(GJ.PassSigFullNonPrompt(iEv,iPh)){EvPass[20]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}    
   if(GJ.PassSBFullNonPrompt(iEv,iPh)){EvPass[21]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCutNonPrompt(iEv,iPh)){EvPass[22]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCutNonPrompt(iEv,iPh)){EvPass[23]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}


     }//low Njet

   if(GJ.PassNJetshigh()){//high Njet
   if(GJ.PassSigFull(iEv,iPh)){EvPass[24]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBFull(iEv,iPh)){EvPass[25]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCut(iEv,iPh)){EvPass[26]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCut(iEv,iPh)){EvPass[27]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
    
   if(GJ.PassSigFullPrompt(iEv,iPh)){EvPass[28]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}    
   if(GJ.PassSBFullPrompt(iEv,iPh)){EvPass[29]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCutPrompt(iEv,iPh)){EvPass[30]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCutPrompt(iEv,iPh)){EvPass[31]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}

   if(GJ.PassSigFullNonPrompt(iEv,iPh)){EvPass[32]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}    
   if(GJ.PassSBFullNonPrompt(iEv,iPh)){EvPass[33]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCutNonPrompt(iEv,iPh)){EvPass[34]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCutNonPrompt(iEv,iPh)){EvPass[35]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}  

     }//high Njet

     //////////////HT

   if(GJ.PassHTlow()){//low HT

   if(GJ.PassSigFull(iEv,iPh)){EvPass[36]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBFull(iEv,iPh)){EvPass[37]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCut(iEv,iPh)){EvPass[38]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCut(iEv,iPh)){EvPass[39]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
    
   if(GJ.PassSigFullPrompt(iEv,iPh)){EvPass[40]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}    
   if(GJ.PassSBFullPrompt(iEv,iPh)){EvPass[41]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCutPrompt(iEv,iPh)){EvPass[42]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCutPrompt(iEv,iPh)){EvPass[43]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}

   if(GJ.PassSigFullNonPrompt(iEv,iPh)){EvPass[44]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}    
   if(GJ.PassSBFullNonPrompt(iEv,iPh)){EvPass[45]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCutNonPrompt(iEv,iPh)){EvPass[46]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCutNonPrompt(iEv,iPh)){EvPass[47]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}


     }//low HT
   if(GJ.PassHThigh()){//high HT

   if(GJ.PassSigFull(iEv,iPh)){EvPass[48]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBFull(iEv,iPh)){EvPass[49]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCut(iEv,iPh)){EvPass[50]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCut(iEv,iPh)){EvPass[51]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
    
   if(GJ.PassSigFullPrompt(iEv,iPh)){EvPass[52]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}    
   if(GJ.PassSBFullPrompt(iEv,iPh)){EvPass[53]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCutPrompt(iEv,iPh)){EvPass[54]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCutPrompt(iEv,iPh)){EvPass[55]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}

   if(GJ.PassSigFullNonPrompt(iEv,iPh)){EvPass[56]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}    
   if(GJ.PassSBFullNonPrompt(iEv,iPh)){EvPass[57]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSigCutNonPrompt(iEv,iPh)){EvPass[58]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
   if(GJ.PassSBCutNonPrompt(iEv,iPh)){EvPass[59]->Fill(GJ.photon_sigmaIetaIeta->at(iPh));}
    
     }//high HT

    }//Leading Pt Photon


}


//cout<<"events passed : "<<passEvent<<endl;



for(int i=0;i<60;i++){
EvPass[i]->Scale(1.5);

}

EvPass[0]->Draw("E0");
fh->Write();


}

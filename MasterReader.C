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


void MasterReader(){
 
TFile *fsie=new TFile("SigmaIetaIeta.root","RECREATE");
TH1F  *h_Sig_bins[72][1];
TH1F  *h_Bkg_bins[72][1];
char h_sig[100];
char h_bkg[100];
for(int i=0;i<72;i++){//loop bins
for(int j=0;j<1;j++){//loop files signal
sprintf(h_sig,"sigmaIeta_sig_%i_%i",i,j);
h_Sig_bins[i][j]=new TH1F(h_sig,h_sig,100,0,0.04);

}//loop files signal
for(int j=0;j<1;j++){//loop files bkg
sprintf(h_bkg,"sigmaIeta_bkg_%i_%i",i,j);
h_Bkg_bins[i][j]=new TH1F(h_bkg,h_bkg,100,0,0.04);

}//loop files bkg

}//loop bins
	TChain* t0_mc_sig = new TChain("TreeMaker2/PreSelection");
		t0_mc_sig->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_40_RA2AnalysisTree.root");
		ClassReadTree mc_sig_0(t0_mc_sig);
		for(int iEv_0_mc_sig=0;iEv_0_mc_sig < t0_mc_sig->GetEntries();iEv_0_mc_sig++){
			t0_mc_sig->GetEntry(iEv_0_mc_sig);
if(mc_sig_0.Baseline( mc_sig_0.HTclean, mc_sig_0.MHTclean , mc_sig_0.NJetsclean, mc_sig_0.DeltaPhi1 ,mc_sig_0.DeltaPhi2 ,mc_sig_0.DeltaPhi3)){
std::cout<<"got an event after base line "<<std::endl;
int i_iEv_0_mc_sig=mc_sig_0.JetID; 
if(i_iEv_0_mc_sig==1){
if(mc_sig_0.photonCands->size()==1){//photon loop
if(mc_sig_0.photon_isEB->at(0)==1  ){//barrel photon
if(mc_sig_0.PassSBIso(mc_sig_0.photon_pfChargedIsoRhoCorr->at(0),mc_sig_0.photon_pfNeutralIsoRhoCorr->at(0),mc_sig_0.photon_pfGammaIsoRhoCorr->at(0),mc_sig_0.photonCands->at(0).Pt())){//side band photon
if(mc_sig_0.photon_nonPrompt->at(0)==0){//prompt photons
cout<<"got prompt photons from signal region"<<endl;
unsigned int bin_sig=computeBin(mc_sig_0.MHTclean,mc_sig_0.HTclean,mc_sig_0.NJetsclean,mc_sig_0.BTagsclean,k13TeV);
h_Sig_bins[bin_sig][0]->Fill(mc_sig_0.photon_sigmaIetaIeta->at(0));

}//prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t0_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t0_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_40_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_0(t0_mc_bkg);
		for(int iEv_0_mc_bkg=0;iEv_0_mc_bkg < t0_mc_bkg->GetEntries();iEv_0_mc_bkg++){
			t0_mc_bkg->GetEntry(iEv_0_mc_bkg);
if(mc_bkg_0.Baseline(mc_bkg_0.HTclean, mc_bkg_0.MHTclean , mc_bkg_0.NJetsclean, mc_bkg_0.DeltaPhi1 ,mc_bkg_0.DeltaPhi2 ,mc_bkg_0.DeltaPhi3)){
int i_iEv_0_mc_bkg=mc_sig_0.JetID; 
if(i_iEv_0_mc_bkg==1){
if(mc_bkg_0.photonCands->size()==1){//photon loop
if(mc_bkg_0.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_0.PassSBIso(mc_bkg_0.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_0.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_0.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_0.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_0.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_0.MHTclean,mc_bkg_0.HTclean,mc_bkg_0.NJetsclean,mc_bkg_0.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][0]->Fill(mc_bkg_0.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


fsie->Write();

}

#include<iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include<vector>
#include "TTree.h"
#include "ClassReadTree.cc"
using namespace std;


void MasterReader(){
 
	TChain* t0_mc_sig = new TChain("TreeMaker2/PreSelection");
		t0_mc_sig->Add("Spring15.GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_40_RA2AnalysisTree.root");
		ClassReadTree mc_sig_0(t0_mc_sig);
		for(int iEv_0_mc_sig=0;iEv_0_mc_sig < t0_mc_sig->GetEntries();iEv_0_mc_sig++){
			t0_mc_sig->GetEntry(iEv_0_mc_sig);
std::cout<<"got an event "<<std::endl;
		}


	TChain* t0_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t0_mc_bkg->Add("Spring15.GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_40_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_0(t0_mc_bkg);
		for(int iEv_0_mc_bkg=0;iEv_0_mc_bkg < t0_mc_bkg->GetEntries();iEv_0_mc_bkg++){
			t0_mc_bkg->GetEntry(iEv_0_mc_bkg);
		}



}

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
 
	TChain* t0_mc_sig = new TChain("TreeMaker2/PreSelection");
		t0_mc_sig->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_sig_0(t0_mc_sig);
		for(int iEv_0_mc_sig=0;iEv_0_mc_sig < t0_mc_sig->GetEntries();iEv_0_mc_sig++){
			t0_mc_sig->GetEntry(iEv_0_mc_sig);
if(mc_sig_0.Baseline( mc_sig_0.HTclean, mc_sig_0.MHTclean , mc_sig_0.NJetsclean, mc_sig_0.DeltaPhi1 ,mc_sig_0.DeltaPhi2 ,mc_sig_0.DeltaPhi3)){
std::cout<<"got an event after base line "<<std::endl;
int i_iEv_0_mc_sig=mc_sig_0.JetID; 
if(i_iEv_0_mc_sig==1){
if(mc_sig_0.photonCands->size()==1){//photon loop
if(mc_sig_0.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t1_mc_sig = new TChain("TreeMaker2/PreSelection");
		t1_mc_sig->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_sig_1(t1_mc_sig);
		for(int iEv_1_mc_sig=0;iEv_1_mc_sig < t1_mc_sig->GetEntries();iEv_1_mc_sig++){
			t1_mc_sig->GetEntry(iEv_1_mc_sig);
if(mc_sig_1.Baseline( mc_sig_1.HTclean, mc_sig_1.MHTclean , mc_sig_1.NJetsclean, mc_sig_1.DeltaPhi1 ,mc_sig_1.DeltaPhi2 ,mc_sig_1.DeltaPhi3)){
std::cout<<"got an event after base line "<<std::endl;
int i_iEv_1_mc_sig=mc_sig_1.JetID; 
if(i_iEv_1_mc_sig==1){
if(mc_sig_1.photonCands->size()==1){//photon loop
if(mc_sig_1.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t0_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t0_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_0(t0_mc_bkg);
		for(int iEv_0_mc_bkg=0;iEv_0_mc_bkg < t0_mc_bkg->GetEntries();iEv_0_mc_bkg++){
			t0_mc_bkg->GetEntry(iEv_0_mc_bkg);
if(mc_bkg_0.Baseline(mc_bkg_0.HTclean, mc_bkg_0.MHTclean , mc_bkg_0.NJetsclean, mc_bkg_0.DeltaPhi1 ,mc_bkg_0.DeltaPhi2 ,mc_bkg_0.DeltaPhi3)){
int i_iEv_0_mc_bkg=mc_sig_0.JetID; 
if(i_iEv_0_mc_bkg==1){
if(mc_bkg_0.photonCands->size()==1){//photon loop
if(mc_bkg_0.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t1_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t1_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_1800to2400_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_1(t1_mc_bkg);
		for(int iEv_1_mc_bkg=0;iEv_1_mc_bkg < t1_mc_bkg->GetEntries();iEv_1_mc_bkg++){
			t1_mc_bkg->GetEntry(iEv_1_mc_bkg);
if(mc_bkg_1.Baseline(mc_bkg_1.HTclean, mc_bkg_1.MHTclean , mc_bkg_1.NJetsclean, mc_bkg_1.DeltaPhi1 ,mc_bkg_1.DeltaPhi2 ,mc_bkg_1.DeltaPhi3)){
int i_iEv_1_mc_bkg=mc_sig_1.JetID; 
if(i_iEv_1_mc_bkg==1){
if(mc_bkg_1.photonCands->size()==1){//photon loop
if(mc_bkg_1.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t2_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t2_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_470to600_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_2(t2_mc_bkg);
		for(int iEv_2_mc_bkg=0;iEv_2_mc_bkg < t2_mc_bkg->GetEntries();iEv_2_mc_bkg++){
			t2_mc_bkg->GetEntry(iEv_2_mc_bkg);
if(mc_bkg_2.Baseline(mc_bkg_2.HTclean, mc_bkg_2.MHTclean , mc_bkg_2.NJetsclean, mc_bkg_2.DeltaPhi1 ,mc_bkg_2.DeltaPhi2 ,mc_bkg_2.DeltaPhi3)){
int i_iEv_2_mc_bkg=mc_sig_2.JetID; 
if(i_iEv_2_mc_bkg==1){
if(mc_bkg_2.photonCands->size()==1){//photon loop
if(mc_bkg_2.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t3_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t3_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_3(t3_mc_bkg);
		for(int iEv_3_mc_bkg=0;iEv_3_mc_bkg < t3_mc_bkg->GetEntries();iEv_3_mc_bkg++){
			t3_mc_bkg->GetEntry(iEv_3_mc_bkg);
if(mc_bkg_3.Baseline(mc_bkg_3.HTclean, mc_bkg_3.MHTclean , mc_bkg_3.NJetsclean, mc_bkg_3.DeltaPhi1 ,mc_bkg_3.DeltaPhi2 ,mc_bkg_3.DeltaPhi3)){
int i_iEv_3_mc_bkg=mc_sig_3.JetID; 
if(i_iEv_3_mc_bkg==1){
if(mc_bkg_3.photonCands->size()==1){//photon loop
if(mc_bkg_3.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t4_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t4_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_2400to3200_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_4(t4_mc_bkg);
		for(int iEv_4_mc_bkg=0;iEv_4_mc_bkg < t4_mc_bkg->GetEntries();iEv_4_mc_bkg++){
			t4_mc_bkg->GetEntry(iEv_4_mc_bkg);
if(mc_bkg_4.Baseline(mc_bkg_4.HTclean, mc_bkg_4.MHTclean , mc_bkg_4.NJetsclean, mc_bkg_4.DeltaPhi1 ,mc_bkg_4.DeltaPhi2 ,mc_bkg_4.DeltaPhi3)){
int i_iEv_4_mc_bkg=mc_sig_4.JetID; 
if(i_iEv_4_mc_bkg==1){
if(mc_bkg_4.photonCands->size()==1){//photon loop
if(mc_bkg_4.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t5_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t5_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_600to800_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_5(t5_mc_bkg);
		for(int iEv_5_mc_bkg=0;iEv_5_mc_bkg < t5_mc_bkg->GetEntries();iEv_5_mc_bkg++){
			t5_mc_bkg->GetEntry(iEv_5_mc_bkg);
if(mc_bkg_5.Baseline(mc_bkg_5.HTclean, mc_bkg_5.MHTclean , mc_bkg_5.NJetsclean, mc_bkg_5.DeltaPhi1 ,mc_bkg_5.DeltaPhi2 ,mc_bkg_5.DeltaPhi3)){
int i_iEv_5_mc_bkg=mc_sig_5.JetID; 
if(i_iEv_5_mc_bkg==1){
if(mc_bkg_5.photonCands->size()==1){//photon loop
if(mc_bkg_5.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t6_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t6_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_1400to1800_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_6(t6_mc_bkg);
		for(int iEv_6_mc_bkg=0;iEv_6_mc_bkg < t6_mc_bkg->GetEntries();iEv_6_mc_bkg++){
			t6_mc_bkg->GetEntry(iEv_6_mc_bkg);
if(mc_bkg_6.Baseline(mc_bkg_6.HTclean, mc_bkg_6.MHTclean , mc_bkg_6.NJetsclean, mc_bkg_6.DeltaPhi1 ,mc_bkg_6.DeltaPhi2 ,mc_bkg_6.DeltaPhi3)){
int i_iEv_6_mc_bkg=mc_sig_6.JetID; 
if(i_iEv_6_mc_bkg==1){
if(mc_bkg_6.photonCands->size()==1){//photon loop
if(mc_bkg_6.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t7_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t7_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_7(t7_mc_bkg);
		for(int iEv_7_mc_bkg=0;iEv_7_mc_bkg < t7_mc_bkg->GetEntries();iEv_7_mc_bkg++){
			t7_mc_bkg->GetEntry(iEv_7_mc_bkg);
if(mc_bkg_7.Baseline(mc_bkg_7.HTclean, mc_bkg_7.MHTclean , mc_bkg_7.NJetsclean, mc_bkg_7.DeltaPhi1 ,mc_bkg_7.DeltaPhi2 ,mc_bkg_7.DeltaPhi3)){
int i_iEv_7_mc_bkg=mc_sig_7.JetID; 
if(i_iEv_7_mc_bkg==1){
if(mc_bkg_7.photonCands->size()==1){//photon loop
if(mc_bkg_7.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t8_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t8_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_800to1000_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_8(t8_mc_bkg);
		for(int iEv_8_mc_bkg=0;iEv_8_mc_bkg < t8_mc_bkg->GetEntries();iEv_8_mc_bkg++){
			t8_mc_bkg->GetEntry(iEv_8_mc_bkg);
if(mc_bkg_8.Baseline(mc_bkg_8.HTclean, mc_bkg_8.MHTclean , mc_bkg_8.NJetsclean, mc_bkg_8.DeltaPhi1 ,mc_bkg_8.DeltaPhi2 ,mc_bkg_8.DeltaPhi3)){
int i_iEv_8_mc_bkg=mc_sig_8.JetID; 
if(i_iEv_8_mc_bkg==1){
if(mc_bkg_8.photonCands->size()==1){//photon loop
if(mc_bkg_8.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t9_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t9_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_9(t9_mc_bkg);
		for(int iEv_9_mc_bkg=0;iEv_9_mc_bkg < t9_mc_bkg->GetEntries();iEv_9_mc_bkg++){
			t9_mc_bkg->GetEntry(iEv_9_mc_bkg);
if(mc_bkg_9.Baseline(mc_bkg_9.HTclean, mc_bkg_9.MHTclean , mc_bkg_9.NJetsclean, mc_bkg_9.DeltaPhi1 ,mc_bkg_9.DeltaPhi2 ,mc_bkg_9.DeltaPhi3)){
int i_iEv_9_mc_bkg=mc_sig_9.JetID; 
if(i_iEv_9_mc_bkg==1){
if(mc_bkg_9.photonCands->size()==1){//photon loop
if(mc_bkg_9.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t10_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t10_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_3200toInf_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_10(t10_mc_bkg);
		for(int iEv_10_mc_bkg=0;iEv_10_mc_bkg < t10_mc_bkg->GetEntries();iEv_10_mc_bkg++){
			t10_mc_bkg->GetEntry(iEv_10_mc_bkg);
if(mc_bkg_10.Baseline(mc_bkg_10.HTclean, mc_bkg_10.MHTclean , mc_bkg_10.NJetsclean, mc_bkg_10.DeltaPhi1 ,mc_bkg_10.DeltaPhi2 ,mc_bkg_10.DeltaPhi3)){
int i_iEv_10_mc_bkg=mc_sig_10.JetID; 
if(i_iEv_10_mc_bkg==1){
if(mc_bkg_10.photonCands->size()==1){//photon loop
if(mc_bkg_10.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t11_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t11_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_11(t11_mc_bkg);
		for(int iEv_11_mc_bkg=0;iEv_11_mc_bkg < t11_mc_bkg->GetEntries();iEv_11_mc_bkg++){
			t11_mc_bkg->GetEntry(iEv_11_mc_bkg);
if(mc_bkg_11.Baseline(mc_bkg_11.HTclean, mc_bkg_11.MHTclean , mc_bkg_11.NJetsclean, mc_bkg_11.DeltaPhi1 ,mc_bkg_11.DeltaPhi2 ,mc_bkg_11.DeltaPhi3)){
int i_iEv_11_mc_bkg=mc_sig_11.JetID; 
if(i_iEv_11_mc_bkg==1){
if(mc_bkg_11.photonCands->size()==1){//photon loop
if(mc_bkg_11.photon_isEB->at(0)==1  ){//barrel photon

}//barrel photon

}//photon loop

}

}
		}



}

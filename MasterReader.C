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
TH1F  *h_Sig_bins[72][2];
TH1F  *h_Bkg_bins[72][12];
char h_sig[100];
char h_bkg[100];
for(int i=0;i<72;i++){//loop bins
for(int j=0;j<2;j++){//loop files signal
sprintf(h_sig,"sigmaIeta_sig_%i_%i",i,j);
h_Sig_bins[i][j]=new TH1F(h_sig,h_sig,100,0,0.04);

}//loop files signal
for(int j=0;j<12;j++){//loop files bkg
sprintf(h_bkg,"sigmaIeta_bkg_%i_%i",i,j);
h_Bkg_bins[i][j]=new TH1F(h_bkg,h_bkg,100,0,0.04);

}//loop files bkg

}//loop bins
	TChain* t0_mc_sig = new TChain("TreeMaker2/PreSelection");
		t0_mc_sig->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_sig_0(t0_mc_sig);
		for(int iEv_0_mc_sig=0;iEv_0_mc_sig < t0_mc_sig->GetEntries();iEv_0_mc_sig++){
if( iEv_0_mc_sig  % 5000 == 0 ) cout << "event: " << iEv_0_mc_sig << endl;
			t0_mc_sig->GetEntry(iEv_0_mc_sig);
if(mc_sig_0.Baseline( mc_sig_0.HTclean, mc_sig_0.MHTclean , mc_sig_0.NJetsclean, mc_sig_0.DeltaPhi1 ,mc_sig_0.DeltaPhi2 ,mc_sig_0.DeltaPhi3)){
int i_iEv_0_mc_sig=mc_sig_0.JetID; 
if(i_iEv_0_mc_sig==1){
if(mc_sig_0.photonCands->size()==1){//photon loop
if(mc_sig_0.photon_isEB->at(0)==1  ){//barrel photon
if(mc_sig_0.PassSBIso(mc_sig_0.photon_pfChargedIsoRhoCorr->at(0),mc_sig_0.photon_pfNeutralIsoRhoCorr->at(0),mc_sig_0.photon_pfGammaIsoRhoCorr->at(0),mc_sig_0.photonCands->at(0).Pt())){//side band photon
if(mc_sig_0.photon_nonPrompt->at(0)==0){//prompt photons
unsigned int bin_sig=computeBin(mc_sig_0.MHTclean,mc_sig_0.HTclean,mc_sig_0.NJetsclean,mc_sig_0.BTagsclean,k13TeV);
h_Sig_bins[bin_sig][0]->Fill(mc_sig_0.photon_sigmaIetaIeta->at(0));

}//prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t1_mc_sig = new TChain("TreeMaker2/PreSelection");
		t1_mc_sig->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_sig_1(t1_mc_sig);
		for(int iEv_1_mc_sig=0;iEv_1_mc_sig < t1_mc_sig->GetEntries();iEv_1_mc_sig++){
if( iEv_1_mc_sig  % 5000 == 0 ) cout << "event: " << iEv_1_mc_sig << endl;
			t1_mc_sig->GetEntry(iEv_1_mc_sig);
if(mc_sig_1.Baseline( mc_sig_1.HTclean, mc_sig_1.MHTclean , mc_sig_1.NJetsclean, mc_sig_1.DeltaPhi1 ,mc_sig_1.DeltaPhi2 ,mc_sig_1.DeltaPhi3)){
int i_iEv_1_mc_sig=mc_sig_1.JetID; 
if(i_iEv_1_mc_sig==1){
if(mc_sig_1.photonCands->size()==1){//photon loop
if(mc_sig_1.photon_isEB->at(0)==1  ){//barrel photon
if(mc_sig_1.PassSBIso(mc_sig_1.photon_pfChargedIsoRhoCorr->at(0),mc_sig_1.photon_pfNeutralIsoRhoCorr->at(0),mc_sig_1.photon_pfGammaIsoRhoCorr->at(0),mc_sig_1.photonCands->at(0).Pt())){//side band photon
if(mc_sig_1.photon_nonPrompt->at(0)==0){//prompt photons
unsigned int bin_sig=computeBin(mc_sig_1.MHTclean,mc_sig_1.HTclean,mc_sig_1.NJetsclean,mc_sig_1.BTagsclean,k13TeV);
h_Sig_bins[bin_sig][1]->Fill(mc_sig_1.photon_sigmaIetaIeta->at(0));

}//prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t0_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t0_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_0(t0_mc_bkg);
		for(int iEv_0_mc_bkg=0;iEv_0_mc_bkg < t0_mc_bkg->GetEntries();iEv_0_mc_bkg++){
if( iEv_0_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_0_mc_bkg << endl;
			t0_mc_bkg->GetEntry(iEv_0_mc_bkg);
if(mc_bkg_0.Baseline(mc_bkg_0.HTclean, mc_bkg_0.MHTclean , mc_bkg_0.NJetsclean, mc_bkg_0.DeltaPhi1 ,mc_bkg_0.DeltaPhi2 ,mc_bkg_0.DeltaPhi3)){
int i_iEv_0_mc_bkg=mc_bkg_0.JetID; 
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


	TChain* t1_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t1_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_1(t1_mc_bkg);
		for(int iEv_1_mc_bkg=0;iEv_1_mc_bkg < t1_mc_bkg->GetEntries();iEv_1_mc_bkg++){
if( iEv_1_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_1_mc_bkg << endl;
			t1_mc_bkg->GetEntry(iEv_1_mc_bkg);
if(mc_bkg_1.Baseline(mc_bkg_1.HTclean, mc_bkg_1.MHTclean , mc_bkg_1.NJetsclean, mc_bkg_1.DeltaPhi1 ,mc_bkg_1.DeltaPhi2 ,mc_bkg_1.DeltaPhi3)){
int i_iEv_1_mc_bkg=mc_bkg_1.JetID; 
if(i_iEv_1_mc_bkg==1){
if(mc_bkg_1.photonCands->size()==1){//photon loop
if(mc_bkg_1.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_1.PassSBIso(mc_bkg_1.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_1.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_1.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_1.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_1.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_1.MHTclean,mc_bkg_1.HTclean,mc_bkg_1.NJetsclean,mc_bkg_1.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][1]->Fill(mc_bkg_1.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t2_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t2_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_2(t2_mc_bkg);
		for(int iEv_2_mc_bkg=0;iEv_2_mc_bkg < t2_mc_bkg->GetEntries();iEv_2_mc_bkg++){
if( iEv_2_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_2_mc_bkg << endl;
			t2_mc_bkg->GetEntry(iEv_2_mc_bkg);
if(mc_bkg_2.Baseline(mc_bkg_2.HTclean, mc_bkg_2.MHTclean , mc_bkg_2.NJetsclean, mc_bkg_2.DeltaPhi1 ,mc_bkg_2.DeltaPhi2 ,mc_bkg_2.DeltaPhi3)){
int i_iEv_2_mc_bkg=mc_bkg_2.JetID; 
if(i_iEv_2_mc_bkg==1){
if(mc_bkg_2.photonCands->size()==1){//photon loop
if(mc_bkg_2.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_2.PassSBIso(mc_bkg_2.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_2.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_2.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_2.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_2.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_2.MHTclean,mc_bkg_2.HTclean,mc_bkg_2.NJetsclean,mc_bkg_2.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][2]->Fill(mc_bkg_2.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t3_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t3_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_3(t3_mc_bkg);
		for(int iEv_3_mc_bkg=0;iEv_3_mc_bkg < t3_mc_bkg->GetEntries();iEv_3_mc_bkg++){
if( iEv_3_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_3_mc_bkg << endl;
			t3_mc_bkg->GetEntry(iEv_3_mc_bkg);
if(mc_bkg_3.Baseline(mc_bkg_3.HTclean, mc_bkg_3.MHTclean , mc_bkg_3.NJetsclean, mc_bkg_3.DeltaPhi1 ,mc_bkg_3.DeltaPhi2 ,mc_bkg_3.DeltaPhi3)){
int i_iEv_3_mc_bkg=mc_bkg_3.JetID; 
if(i_iEv_3_mc_bkg==1){
if(mc_bkg_3.photonCands->size()==1){//photon loop
if(mc_bkg_3.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_3.PassSBIso(mc_bkg_3.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_3.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_3.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_3.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_3.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_3.MHTclean,mc_bkg_3.HTclean,mc_bkg_3.NJetsclean,mc_bkg_3.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][3]->Fill(mc_bkg_3.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t4_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t4_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_470to600_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_4(t4_mc_bkg);
		for(int iEv_4_mc_bkg=0;iEv_4_mc_bkg < t4_mc_bkg->GetEntries();iEv_4_mc_bkg++){
if( iEv_4_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_4_mc_bkg << endl;
			t4_mc_bkg->GetEntry(iEv_4_mc_bkg);
if(mc_bkg_4.Baseline(mc_bkg_4.HTclean, mc_bkg_4.MHTclean , mc_bkg_4.NJetsclean, mc_bkg_4.DeltaPhi1 ,mc_bkg_4.DeltaPhi2 ,mc_bkg_4.DeltaPhi3)){
int i_iEv_4_mc_bkg=mc_bkg_4.JetID; 
if(i_iEv_4_mc_bkg==1){
if(mc_bkg_4.photonCands->size()==1){//photon loop
if(mc_bkg_4.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_4.PassSBIso(mc_bkg_4.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_4.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_4.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_4.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_4.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_4.MHTclean,mc_bkg_4.HTclean,mc_bkg_4.NJetsclean,mc_bkg_4.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][4]->Fill(mc_bkg_4.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t5_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t5_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_600to800_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_5(t5_mc_bkg);
		for(int iEv_5_mc_bkg=0;iEv_5_mc_bkg < t5_mc_bkg->GetEntries();iEv_5_mc_bkg++){
if( iEv_5_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_5_mc_bkg << endl;
			t5_mc_bkg->GetEntry(iEv_5_mc_bkg);
if(mc_bkg_5.Baseline(mc_bkg_5.HTclean, mc_bkg_5.MHTclean , mc_bkg_5.NJetsclean, mc_bkg_5.DeltaPhi1 ,mc_bkg_5.DeltaPhi2 ,mc_bkg_5.DeltaPhi3)){
int i_iEv_5_mc_bkg=mc_bkg_5.JetID; 
if(i_iEv_5_mc_bkg==1){
if(mc_bkg_5.photonCands->size()==1){//photon loop
if(mc_bkg_5.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_5.PassSBIso(mc_bkg_5.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_5.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_5.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_5.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_5.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_5.MHTclean,mc_bkg_5.HTclean,mc_bkg_5.NJetsclean,mc_bkg_5.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][5]->Fill(mc_bkg_5.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t6_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t6_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_800to1000_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_6(t6_mc_bkg);
		for(int iEv_6_mc_bkg=0;iEv_6_mc_bkg < t6_mc_bkg->GetEntries();iEv_6_mc_bkg++){
if( iEv_6_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_6_mc_bkg << endl;
			t6_mc_bkg->GetEntry(iEv_6_mc_bkg);
if(mc_bkg_6.Baseline(mc_bkg_6.HTclean, mc_bkg_6.MHTclean , mc_bkg_6.NJetsclean, mc_bkg_6.DeltaPhi1 ,mc_bkg_6.DeltaPhi2 ,mc_bkg_6.DeltaPhi3)){
int i_iEv_6_mc_bkg=mc_bkg_6.JetID; 
if(i_iEv_6_mc_bkg==1){
if(mc_bkg_6.photonCands->size()==1){//photon loop
if(mc_bkg_6.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_6.PassSBIso(mc_bkg_6.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_6.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_6.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_6.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_6.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_6.MHTclean,mc_bkg_6.HTclean,mc_bkg_6.NJetsclean,mc_bkg_6.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][6]->Fill(mc_bkg_6.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t7_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t7_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_7(t7_mc_bkg);
		for(int iEv_7_mc_bkg=0;iEv_7_mc_bkg < t7_mc_bkg->GetEntries();iEv_7_mc_bkg++){
if( iEv_7_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_7_mc_bkg << endl;
			t7_mc_bkg->GetEntry(iEv_7_mc_bkg);
if(mc_bkg_7.Baseline(mc_bkg_7.HTclean, mc_bkg_7.MHTclean , mc_bkg_7.NJetsclean, mc_bkg_7.DeltaPhi1 ,mc_bkg_7.DeltaPhi2 ,mc_bkg_7.DeltaPhi3)){
int i_iEv_7_mc_bkg=mc_bkg_7.JetID; 
if(i_iEv_7_mc_bkg==1){
if(mc_bkg_7.photonCands->size()==1){//photon loop
if(mc_bkg_7.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_7.PassSBIso(mc_bkg_7.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_7.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_7.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_7.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_7.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_7.MHTclean,mc_bkg_7.HTclean,mc_bkg_7.NJetsclean,mc_bkg_7.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][7]->Fill(mc_bkg_7.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t8_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t8_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_1400to1800_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_8(t8_mc_bkg);
		for(int iEv_8_mc_bkg=0;iEv_8_mc_bkg < t8_mc_bkg->GetEntries();iEv_8_mc_bkg++){
if( iEv_8_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_8_mc_bkg << endl;
			t8_mc_bkg->GetEntry(iEv_8_mc_bkg);
if(mc_bkg_8.Baseline(mc_bkg_8.HTclean, mc_bkg_8.MHTclean , mc_bkg_8.NJetsclean, mc_bkg_8.DeltaPhi1 ,mc_bkg_8.DeltaPhi2 ,mc_bkg_8.DeltaPhi3)){
int i_iEv_8_mc_bkg=mc_bkg_8.JetID; 
if(i_iEv_8_mc_bkg==1){
if(mc_bkg_8.photonCands->size()==1){//photon loop
if(mc_bkg_8.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_8.PassSBIso(mc_bkg_8.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_8.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_8.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_8.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_8.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_8.MHTclean,mc_bkg_8.HTclean,mc_bkg_8.NJetsclean,mc_bkg_8.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][8]->Fill(mc_bkg_8.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t9_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t9_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_1800to2400_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_9(t9_mc_bkg);
		for(int iEv_9_mc_bkg=0;iEv_9_mc_bkg < t9_mc_bkg->GetEntries();iEv_9_mc_bkg++){
if( iEv_9_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_9_mc_bkg << endl;
			t9_mc_bkg->GetEntry(iEv_9_mc_bkg);
if(mc_bkg_9.Baseline(mc_bkg_9.HTclean, mc_bkg_9.MHTclean , mc_bkg_9.NJetsclean, mc_bkg_9.DeltaPhi1 ,mc_bkg_9.DeltaPhi2 ,mc_bkg_9.DeltaPhi3)){
int i_iEv_9_mc_bkg=mc_bkg_9.JetID; 
if(i_iEv_9_mc_bkg==1){
if(mc_bkg_9.photonCands->size()==1){//photon loop
if(mc_bkg_9.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_9.PassSBIso(mc_bkg_9.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_9.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_9.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_9.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_9.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_9.MHTclean,mc_bkg_9.HTclean,mc_bkg_9.NJetsclean,mc_bkg_9.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][9]->Fill(mc_bkg_9.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t10_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t10_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_2400to3200_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_10(t10_mc_bkg);
		for(int iEv_10_mc_bkg=0;iEv_10_mc_bkg < t10_mc_bkg->GetEntries();iEv_10_mc_bkg++){
if( iEv_10_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_10_mc_bkg << endl;
			t10_mc_bkg->GetEntry(iEv_10_mc_bkg);
if(mc_bkg_10.Baseline(mc_bkg_10.HTclean, mc_bkg_10.MHTclean , mc_bkg_10.NJetsclean, mc_bkg_10.DeltaPhi1 ,mc_bkg_10.DeltaPhi2 ,mc_bkg_10.DeltaPhi3)){
int i_iEv_10_mc_bkg=mc_bkg_10.JetID; 
if(i_iEv_10_mc_bkg==1){
if(mc_bkg_10.photonCands->size()==1){//photon loop
if(mc_bkg_10.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_10.PassSBIso(mc_bkg_10.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_10.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_10.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_10.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_10.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_10.MHTclean,mc_bkg_10.HTclean,mc_bkg_10.NJetsclean,mc_bkg_10.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][10]->Fill(mc_bkg_10.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


	TChain* t11_mc_bkg = new TChain("TreeMaker2/PreSelection");
		t11_mc_bkg->Add("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/DPSproductionPatch1/Spring15.QCD_Pt_3200toInf_TuneCUETP8M1_13TeV_pythia8_*_RA2AnalysisTree.root");
		ClassReadTree mc_bkg_11(t11_mc_bkg);
		for(int iEv_11_mc_bkg=0;iEv_11_mc_bkg < t11_mc_bkg->GetEntries();iEv_11_mc_bkg++){
if( iEv_11_mc_bkg  % 5000 == 0 ) cout << "event: " << iEv_11_mc_bkg << endl;
			t11_mc_bkg->GetEntry(iEv_11_mc_bkg);
if(mc_bkg_11.Baseline(mc_bkg_11.HTclean, mc_bkg_11.MHTclean , mc_bkg_11.NJetsclean, mc_bkg_11.DeltaPhi1 ,mc_bkg_11.DeltaPhi2 ,mc_bkg_11.DeltaPhi3)){
int i_iEv_11_mc_bkg=mc_bkg_11.JetID; 
if(i_iEv_11_mc_bkg==1){
if(mc_bkg_11.photonCands->size()==1){//photon loop
if(mc_bkg_11.photon_isEB->at(0)==1  ){//barrel photon
if(mc_bkg_11.PassSBIso(mc_bkg_11.photon_pfChargedIsoRhoCorr->at(0),mc_bkg_11.photon_pfNeutralIsoRhoCorr->at(0),mc_bkg_11.photon_pfGammaIsoRhoCorr->at(0),mc_bkg_11.photonCands->at(0).Pt())){//side band photon
if(mc_bkg_11.photon_nonPrompt->at(0)==1){//non prompt photons
cout<<"got prompt photons from signal region"<<endl;
int bin_bkg=computeBin(mc_bkg_11.MHTclean,mc_bkg_11.HTclean,mc_bkg_11.NJetsclean,mc_bkg_11.BTagsclean,k13TeV);
h_Bkg_bins[bin_bkg][11]->Fill(mc_bkg_11.photon_sigmaIetaIeta->at(0));

}//non prompt photons

}//side band photon

}//barrel photon

}//photon loop

}

}
		}


fsie->Write();

}

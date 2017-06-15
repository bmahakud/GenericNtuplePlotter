#include<iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include<vector>
#include "TTree.h"
#include "ClassReadSig.cc"
#include "ClassReadBkg.cc"
#include "ClassReadData.cc" 
#include "Loader.C"
 #include "Looper_sig.C"
#include "Looper_bkg.C" 
#include "Looper_data.C"
  #include "HistCreater.C"
using namespace std;


void Analyzer(){
 
Loader L;



TFile *f=new TFile("Histograms.root","RECREATE");
HistCreater hs;
Looper_sig<ClassReadSig,HistCreater> loop_s;



TChain *tree_T5qqqqZH_mG750=L.Load("T5qqqqZH_mG750");
ClassReadSig T5qqqqZH_mG750(tree_T5qqqqZH_mG750);
loop_s.Loop(tree_T5qqqqZH_mG750,T5qqqqZH_mG750,hs,"T5qqqqZH_mG750");



TChain *tree_T5qqqqZH_mG2100=L.Load("T5qqqqZH_mG2100");
ClassReadSig T5qqqqZH_mG2100(tree_T5qqqqZH_mG2100);
loop_s.Loop(tree_T5qqqqZH_mG2100,T5qqqqZH_mG2100,hs,"T5qqqqZH_mG2100");



TChain *tree_T5qqqqZH_mG1700=L.Load("T5qqqqZH_mG1700");
ClassReadSig T5qqqqZH_mG1700(tree_T5qqqqZH_mG1700);
loop_s.Loop(tree_T5qqqqZH_mG1700,T5qqqqZH_mG1700,hs,"T5qqqqZH_mG1700");







Looper_bkg<ClassReadBkg,HistCreater> loop_b;
TChain *tree_QCD=L.Load("QCD");
ClassReadBkg QCD(tree_QCD);
loop_b.Loop(tree_QCD,QCD,hs,"QCD");



TChain *tree_WJets=L.Load("WJets");
ClassReadBkg WJets(tree_WJets);
loop_b.Loop(tree_WJets,WJets,hs,"WJets");



TChain *tree_TTJets=L.Load("TTJets");
ClassReadBkg TTJets(tree_TTJets);
loop_b.Loop(tree_TTJets,TTJets,hs,"TTJets");



TChain *tree_ZJets=L.Load("ZJets");
ClassReadBkg ZJets(tree_ZJets);
loop_b.Loop(tree_ZJets,ZJets,hs,"ZJets");







Looper_data<ClassReadData,HistCreater> loop_d;
TChain *tree_HTMHT=L.Load("HTMHT");
ClassReadData HTMHT(tree_HTMHT);
loop_d.Loop(tree_HTMHT,HTMHT,hs,"HTMHT");



TChain *tree_jetHT=L.Load("jetHT");
ClassReadData jetHT(tree_jetHT);
loop_d.Loop(tree_jetHT,jetHT,hs,"jetHT");





f->Write();

}

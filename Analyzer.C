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
 #include "HistCreater.C" 
using namespace std;


void Analyzer(){
 
Loader L;


HistCreater hs;

cout<<"Entries: "<<hs.h_HT_T5qqqqZH_mG750->GetEntries()<<endl;
//All the histograms are already created , you can access them with hs.h_variableName_processName as shown above


TChain *tree_T5qqqqZH_mG750=L.Load("T5qqqqZH_mG750");
ClassReadSig T5qqqqZH_mG750(tree_T5qqqqZH_mG750);



TChain *tree_T5qqqqZH_mG2100=L.Load("T5qqqqZH_mG2100");
ClassReadSig T5qqqqZH_mG2100(tree_T5qqqqZH_mG2100);



TChain *tree_T5qqqqZH_mG1700=L.Load("T5qqqqZH_mG1700");
ClassReadSig T5qqqqZH_mG1700(tree_T5qqqqZH_mG1700);







TChain *tree_QCD=L.Load("QCD");
ClassReadBkg QCD(tree_QCD);



TChain *tree_WJets=L.Load("WJets");
ClassReadBkg WJets(tree_WJets);



TChain *tree_TTJets=L.Load("TTJets");
ClassReadBkg TTJets(tree_TTJets);



TChain *tree_ZJets=L.Load("ZJets");
ClassReadBkg ZJets(tree_ZJets);







TChain *tree_HTMHT=L.Load("HTMHT");
ClassReadData HTMHT(tree_HTMHT);



TChain *tree_jetHT=L.Load("jetHT");
ClassReadData jetHT(tree_jetHT);




}

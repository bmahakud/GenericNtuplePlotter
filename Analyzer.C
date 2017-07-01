#include<iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include<vector>
#include "TTree.h" 
#include "TH1F.h"
#include "TPaveText.h"
#include "ClassReadSig.cc"
#include "ClassReadBkg.cc"
#include "ClassReadData.cc"
#include "Loader.C"
#include "Looper_sig.C"
#include "Looper_bkg.C"
#include "Looper_data.C"
#include "stackPlotter.C"
#include "HistCreater.C"
using namespace std;


void Analyzer(){
 
Loader L;



TFile *f=new TFile("Histograms.root","RECREATE");
HistCreater hs;
Looper_sig<ClassReadSig,HistCreater> loop_s;



TChain *tree_T5qqqqZH_mG1300=L.Load("T5qqqqZH_mG1300");
ClassReadSig T5qqqqZH_mG1300(tree_T5qqqqZH_mG1300);
loop_s.Loop(tree_T5qqqqZH_mG1300,T5qqqqZH_mG1300,hs,"T5qqqqZH_mG1300");



TChain *tree_T5qqqqZH_mG1700=L.Load("T5qqqqZH_mG1700");
ClassReadSig T5qqqqZH_mG1700(tree_T5qqqqZH_mG1700);
loop_s.Loop(tree_T5qqqqZH_mG1700,T5qqqqZH_mG1700,hs,"T5qqqqZH_mG1700");







Looper_bkg<ClassReadBkg,HistCreater> loop_b;
TChain *tree_QCD=L.Load("QCD");
ClassReadBkg QCD(tree_QCD);
loop_b.Loop(tree_QCD,QCD,hs,"QCD");



TChain *tree_TTJets=L.Load("TTJets");
ClassReadBkg TTJets(tree_TTJets);
loop_b.Loop(tree_TTJets,TTJets,hs,"TTJets");



TChain *tree_ZJets=L.Load("ZJets");
ClassReadBkg ZJets(tree_ZJets);
loop_b.Loop(tree_ZJets,ZJets,hs,"ZJets");



TChain *tree_WJets=L.Load("WJets");
ClassReadBkg WJets(tree_WJets);
loop_b.Loop(tree_WJets,WJets,hs,"WJets");







Looper_data<ClassReadData,HistCreater> loop_d;
TChain *tree_HTMHT=L.Load("HTMHT");
ClassReadData HTMHT(tree_HTMHT);
loop_d.Loop(tree_HTMHT,HTMHT,hs,"HTMHT");



//sample tav text could be used as argument to the stack plotter  
TPaveText *tpav_txt = new TPaveText(0.57043478,0.548342,0.8652174,0.9210471,"brNDC");
    tpav_txt->SetBorderSize(0);
    tpav_txt->SetFillStyle(0);
    tpav_txt->SetTextAlign(11);
    tpav_txt->SetTextFont(42);
    tpav_txt->SetTextSize(0.04);
    tpav_txt->AddText("HT >500");
    tpav_txt->AddText("#gamma p_{T} > 100 ");
    tpav_txt->AddText("NJets >=4");
    tpav_txt->AddText("MHT>200");
    tpav_txt->AddText("BTags=0");
//Example of how to use stack plotter
StackPlotter stack;

//uncomment the following line. put histogram names correctly
//sample arguments if you want to plot one signal,5 background and no data then use the function plotS1B5D0
//if you want to use data then use the function plotS1B5D1, this way you can use all possible combinations 
//use following procees nums
// T5qqqqZH_mG1300 - 0    // T5qqqqZH_mG1700 - 1    // QCD - 2    // TTJets - 3    // ZJets - 4    // WJets - 5    // HTMHT - 6    

stack.plotS1B3D0("HT(GeV)",tpav_txt,hs.h_[0][0][0],"ZH_mG750",hs.h_[0][3][0],"ZJets",hs.h_[0][4][0],"QCD",hs.h_[0][5][0],"TTJets");


f->Write();

}

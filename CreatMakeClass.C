
#include <iostream>
#include "TROOT.h"


void CreatMakeClass(const char * RootFile, const char * treeName, const char *GeneralprocessName)
{
    TFile * f1 = new TFile(RootFile,"READ");
    //TFile * f1 = new TFile("PHYS14.GJets_HT-400to600_Tune4C_13TeV-madgraph-tauola_105_RA2AnalysisTree.root","READ");

    TTree * t1 = (TTree*)f1->Get(treeName);

    //gROOT->ProcessLine("PreSelection->MakeClass(\"makerootmacro\")");
    t1->MakeClass(GeneralprocessName);
}

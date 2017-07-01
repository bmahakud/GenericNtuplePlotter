#include<iostream>
#include "TStyle.h"
#include "TH1F.h"
using namespace std;

class StackPlotter{

public:
TH1F *hsig[10]={NULL};

TH1F *hbkg[10]={NULL};

TH1F *hdata=NULL;


void plot();








};



void StackPlotter::plot(TH1F *signal[],TH1F *bkg[],TH1F *data){

//int a[5];
size_t size_sig = (sizeof &signal / sizeof &signal[0]);
size_t size_bkg = (sizeof &bkg / sizeof &bkg[0]);




std::cout<<"Number of signal histograms: "<<size_sig<<std::endl;
std::cout<<"Number of background histograms: "<<size_bkg<<std::endl;


bkg[1]->Draw();




}



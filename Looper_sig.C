template <class classInst, class HistogramCreater> class Looper_sig{
public:

void Loop(TChain *tr,classInst& read,HistogramCreater hs, string ProcessName);

bool Baseline(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ProcessCuts(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool OneTag(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool TwoTag(TChain *tr,classInst& read,string ProcessName,int iEvent);

};

template <class classInst,class HistogramCreater> void Looper_sig<classInst,HistogramCreater>::Loop(TChain *tr,classInst& read,HistogramCreater hs,string ProcessName)

{//looper definition

string processes[9]={ "T5qqqqZH_mG750"  , "T5qqqqZH_mG2100"  , "T5qqqqZH_mG1700"  , "QCD"  , "WJets"  , "TTJets"  , "ZJets"  , "HTMHT"  , "jetHT"  };
string dataprocesses[2]={ "HTMHT"  , "jetHT"  };
const int processesSize=9;
            auto it=std::find(processes,processes+processesSize,ProcessName);
            int processInt=it-processes;
       std::cout<<"Total number of entries: "<<tr->GetEntries()<<std::endl;

       for(int iEv=0;iEv<tr->GetEntries();iEv++){// event loop

       tr->GetEntry(iEv);

          if(iEv % 1000==0)std::cout<<"Running on "<<ProcessName<<" event no: "<<iEv<<"---completed : "<<(float(iEv)/float(tr->GetEntries()))*100<<" %"<<std::endl;

            if(Baseline(tr,read,ProcessName,iEv)  && ProcessCuts(tr,read,ProcessName, iEv)){ //Baseline for this processn

            double EventWeight=1;
            EventWeight=read.Weight;
if(OneTag(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][0]->Fill(read.HT,EventWeight); 
         hs.h_[1][processInt][0]->Fill(read.MHT,EventWeight); 
         hs.h_[2][processInt][0]->Fill(read.NJets,EventWeight); 
         hs.h_[3][processInt][0]->Fill(read.BTags,EventWeight); 
         hs.h_[4][processInt][0]->Fill(read.DeltaPhi1,EventWeight); 
         hs.h_[5][processInt][0]->Fill(read.Jets->at(0).Pt(),EventWeight); 
};
if(TwoTag(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][1]->Fill(read.HT,EventWeight); 
         hs.h_[1][processInt][1]->Fill(read.MHT,EventWeight); 
         hs.h_[2][processInt][1]->Fill(read.NJets,EventWeight); 
         hs.h_[3][processInt][1]->Fill(read.BTags,EventWeight); 
         hs.h_[4][processInt][1]->Fill(read.DeltaPhi1,EventWeight); 
         hs.h_[5][processInt][1]->Fill(read.Jets->at(0).Pt(),EventWeight); 
};
               }//Baseline for this process

       }//event loop

}//looper definition

template <class classInst,class HistogramCreater> bool Looper_sig<classInst,HistogramCreater>::Baseline(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(
read. HT>500 && 
read. MHT>200 && 
read. NJets>=4 && 
read. Jets->size()>0 && 
read. Jets->at(0).Pt() > 200.
){

return true;

}
else{
return false;

}
}

template <class classInst,class HistogramCreater> bool Looper_sig<classInst,HistogramCreater>::ProcessCuts(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(ProcessName=="T5qqqqZH_mG750"){

return true;
}

if(ProcessName=="T5qqqqZH_mG1700"){

return true;
}

if(ProcessName=="T5qqqqZH_mG2100"){

return true;
}

if(ProcessName=="WJets"){

return true;
}

if(ProcessName=="ZJets"){

return true;
}

if(ProcessName=="TTJets"){

return true;
}

if(ProcessName=="QCD"){

return true;
}

if(ProcessName=="HTMHT"){

return true;
}

if(ProcessName=="jetHT"){

return true;
}

return false;
}

template <class classInst,class HistogramCreater> bool Looper_sig<classInst,HistogramCreater>::OneTag(TChain *tr,classInst& read,string ProcessName,int iEvent){

return true;
}

template <class classInst,class HistogramCreater> bool Looper_sig<classInst,HistogramCreater>::TwoTag(TChain *tr,classInst& read,string ProcessName,int iEvent){

return true;
}


template <class classInst, class HistogramCreater> class Looper_data{
public:

void Loop(TChain *tr,classInst& read,HistogramCreater hs, string ProcessName);

bool Baseline(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ProcessCuts(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZ(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZH(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool HH(TChain *tr,classInst& read,string ProcessName,int iEvent);

double UserDef_MT2(TChain *tr,classInst& read,string ProcessName,int iEvent);
};

template <class classInst,class HistogramCreater> void Looper_data<classInst,HistogramCreater>::Loop(TChain *tr,classInst& read,HistogramCreater hs,string ProcessName)

{//looper definition

string processes[7]={ "T5qqqqZH_mG1300"  , "T5qqqqZH_mG1700"  , "QCD"  , "TTJets"  , "ZJets"  , "WJets"  , "HTMHT"  };
string dataprocesses[1]={ "HTMHT"  };
const int processesSize=7;
            auto it=std::find(processes,processes+processesSize,ProcessName);
            int processInt=it-processes;
       std::cout<<"Total number of entries: "<<tr->GetEntries()<<std::endl;

       for(int iEv=0;iEv<tr->GetEntries();iEv++){// event loop

       tr->GetEntry(iEv);

          if(iEv % 1000==0)std::cout<<"Running on "<<ProcessName<<" event no: "<<iEv<<"---completed : "<<(float(iEv)/float(tr->GetEntries()))*100<<" %"<<std::endl;

            if(Baseline(tr,read,ProcessName,iEv)  && ProcessCuts(tr,read,ProcessName, iEv)){ //Baseline for this processn

            double EventWeight=1;
if(ZZ(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][0]->Fill(read.HT,EventWeight); 
         hs.h_[1][processInt][0]->Fill(read.MET,EventWeight); 
         hs.h_[2][processInt][0]->Fill(read.NJets,EventWeight); 
         hs.h_[3][processInt][0]->Fill(read.BTags,EventWeight); 
         hs.h_[4][processInt][0]->Fill(read.DeltaPhi1,EventWeight); 
         hs.h_[5][processInt][0]->Fill(read.DeltaPhi2,EventWeight); 
         hs.h_[6][processInt][0]->Fill(read.DeltaPhi3,EventWeight); 
         hs.h_[7][processInt][0]->Fill(read.DeltaPhi4,EventWeight); 
         hs.h_[8][processInt][0]->Fill(read.JetsAK8->at(0).Pt(),EventWeight); 
         hs.h_[9][processInt][0]->Fill(read.JetsAK8->at(0).M(),EventWeight); 
         hs.h_[10][processInt][0]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[11][processInt][0]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[12][processInt][0]->Fill(read.JetsAK8_doubleBDiscriminator->at(0),EventWeight); 
         hs.h_[13][processInt][0]->Fill(read.JetsAK8->at(1).Pt(),EventWeight); 
         hs.h_[14][processInt][0]->Fill(read.JetsAK8->at(1).M(),EventWeight); 
         hs.h_[15][processInt][0]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[16][processInt][0]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
         hs.h_[17][processInt][0]->Fill(read.JetsAK8_doubleBDiscriminator->at(1),EventWeight); 
         hs.h_[18][processInt][0]->Fill(UserDef_MT2(tr,read,ProcessName,iEv),EventWeight); 
}

if(ZH(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][1]->Fill(read.HT,EventWeight); 
         hs.h_[1][processInt][1]->Fill(read.MET,EventWeight); 
         hs.h_[2][processInt][1]->Fill(read.NJets,EventWeight); 
         hs.h_[3][processInt][1]->Fill(read.BTags,EventWeight); 
         hs.h_[4][processInt][1]->Fill(read.DeltaPhi1,EventWeight); 
         hs.h_[5][processInt][1]->Fill(read.DeltaPhi2,EventWeight); 
         hs.h_[6][processInt][1]->Fill(read.DeltaPhi3,EventWeight); 
         hs.h_[7][processInt][1]->Fill(read.DeltaPhi4,EventWeight); 
         hs.h_[8][processInt][1]->Fill(read.JetsAK8->at(0).Pt(),EventWeight); 
         hs.h_[9][processInt][1]->Fill(read.JetsAK8->at(0).M(),EventWeight); 
         hs.h_[10][processInt][1]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[11][processInt][1]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[12][processInt][1]->Fill(read.JetsAK8_doubleBDiscriminator->at(0),EventWeight); 
         hs.h_[13][processInt][1]->Fill(read.JetsAK8->at(1).Pt(),EventWeight); 
         hs.h_[14][processInt][1]->Fill(read.JetsAK8->at(1).M(),EventWeight); 
         hs.h_[15][processInt][1]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[16][processInt][1]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
         hs.h_[17][processInt][1]->Fill(read.JetsAK8_doubleBDiscriminator->at(1),EventWeight); 
         hs.h_[18][processInt][1]->Fill(UserDef_MT2(tr,read,ProcessName,iEv),EventWeight); 
}

if(HH(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][2]->Fill(read.HT,EventWeight); 
         hs.h_[1][processInt][2]->Fill(read.MET,EventWeight); 
         hs.h_[2][processInt][2]->Fill(read.NJets,EventWeight); 
         hs.h_[3][processInt][2]->Fill(read.BTags,EventWeight); 
         hs.h_[4][processInt][2]->Fill(read.DeltaPhi1,EventWeight); 
         hs.h_[5][processInt][2]->Fill(read.DeltaPhi2,EventWeight); 
         hs.h_[6][processInt][2]->Fill(read.DeltaPhi3,EventWeight); 
         hs.h_[7][processInt][2]->Fill(read.DeltaPhi4,EventWeight); 
         hs.h_[8][processInt][2]->Fill(read.JetsAK8->at(0).Pt(),EventWeight); 
         hs.h_[9][processInt][2]->Fill(read.JetsAK8->at(0).M(),EventWeight); 
         hs.h_[10][processInt][2]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[11][processInt][2]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[12][processInt][2]->Fill(read.JetsAK8_doubleBDiscriminator->at(0),EventWeight); 
         hs.h_[13][processInt][2]->Fill(read.JetsAK8->at(1).Pt(),EventWeight); 
         hs.h_[14][processInt][2]->Fill(read.JetsAK8->at(1).M(),EventWeight); 
         hs.h_[15][processInt][2]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[16][processInt][2]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
         hs.h_[17][processInt][2]->Fill(read.JetsAK8_doubleBDiscriminator->at(1),EventWeight); 
         hs.h_[18][processInt][2]->Fill(UserDef_MT2(tr,read,ProcessName,iEv),EventWeight); 
}

               }//Baseline for this process

       }//event loop

}//looper definition

template <class classInst,class HistogramCreater> bool Looper_data<classInst,HistogramCreater>::Baseline(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(
read. HT>200 && 
read. MET>200 && 
read. NJets>=2 && 
read. JetsAK8->size()>1 && 
read. DeltaPhi1>0.5 && 
read. DeltaPhi2>0.5 && 
read. DeltaPhi3>0.3 && 
read. DeltaPhi4>0.3 && 
read. Muons->size() == 0 && 
read. Electrons->size() == 0 && 
read. isoMuonTracks == 0 && 
read. isoElectronTracks == 0 && 
read. isoPionTracks == 0
){

return true;

}
else{
return false;

}
}

template <class classInst,class HistogramCreater> bool Looper_data<classInst,HistogramCreater>::ProcessCuts(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(ProcessName=="T5qqqqZH_mG1700"){

return true;
}

if(ProcessName=="T5qqqqZH_mG1300"){

return true;
}

if(ProcessName=="TTJets"){

return true;
}

if(ProcessName=="ZJets"){

return true;
}

if(ProcessName=="WJets"){

return true;
}

if(ProcessName=="QCD"){

return true;
}

if(ProcessName=="HTMHT"){

return true;
}

return false;
}

template <class classInst,class HistogramCreater> bool Looper_data<classInst,HistogramCreater>::ZZ(TChain *tr,classInst& read,string ProcessName,int iEvent){

return true;
}

template <class classInst,class HistogramCreater> bool Looper_data<classInst,HistogramCreater>::ZH(TChain *tr,classInst& read,string ProcessName,int iEvent){

return true;
}

template <class classInst,class HistogramCreater> bool Looper_data<classInst,HistogramCreater>::HH(TChain *tr,classInst& read,string ProcessName,int iEvent){

return true;
}

template <class classInst,class HistogramCreater> double Looper_data<classInst,HistogramCreater>::UserDef_MT2(TChain *tr,classInst& read,string ProcessName,int iEvent){
return 1.0;
}


class Loader{
 
public:
TChain *Load(string ProcessName);
};
TChain *Loader::Load(string ProcessName="TTJets"){
if(ProcessName=="T5qqqqZH_mG1300"){
TChain *tr_T5qqqqZH_mG1300=new TChain("TreeMaker2/PreSelection");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_10_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_11_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_12_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_1_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_2_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_3_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_4_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_5_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_6_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_7_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_8_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1300->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_9_RA2AnalysisTree.root");
cout<<"Total events present in process T5qqqqZH_mG1300: "<<tr_T5qqqqZH_mG1300->GetEntries()<<endl;
return tr_T5qqqqZH_mG1300;

}
if(ProcessName=="T5qqqqZH_mG1700"){
TChain *tr_T5qqqqZH_mG1700=new TChain("TreeMaker2/PreSelection");
tr_T5qqqqZH_mG1700->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1700->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_1_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1700->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_2_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1700->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_3_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1700->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_4_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1700->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_5_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1700->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_6_RA2AnalysisTree.root");
tr_T5qqqqZH_mG1700->Add("root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_7_RA2AnalysisTree.root");
cout<<"Total events present in process T5qqqqZH_mG1700: "<<tr_T5qqqqZH_mG1700->GetEntries()<<endl;
return tr_T5qqqqZH_mG1700;

}
if(ProcessName=="QCD"){
TChain *tr_QCD=new TChain("tree");
tr_QCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_QCD_HT-1000to1500.root");
tr_QCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_QCD_HT-1500to2000.root");
tr_QCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_QCD_HT-2000toInf.root");
tr_QCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_QCD_HT-200to300.root");
tr_QCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_QCD_HT-300to500.root");
tr_QCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_QCD_HT-500to700.root");
tr_QCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_QCD_HT-700to1000.root");
cout<<"Total events present in process QCD: "<<tr_QCD->GetEntries()<<endl;
return tr_QCD;

}
if(ProcessName=="TTJets"){
TChain *tr_TTJets=new TChain("tree");
tr_TTJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_TTJets_HT-1200to2500.root");
tr_TTJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_TTJets_HT-2500toInf.root");
tr_TTJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_TTJets_HT-600to800.root");
tr_TTJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_TTJets_HT-800to1200.root");
cout<<"Total events present in process TTJets: "<<tr_TTJets->GetEntries()<<endl;
return tr_TTJets;

}
if(ProcessName=="ZJets"){
TChain *tr_ZJets=new TChain("tree");
tr_ZJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_ZJetsToNuNu_HT-100to200.root");
tr_ZJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_ZJetsToNuNu_HT-1200to2500.root");
tr_ZJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_ZJetsToNuNu_HT-200to400.root");
tr_ZJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_ZJetsToNuNu_HT-2500toInf.root");
tr_ZJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_ZJetsToNuNu_HT-400to600.root");
tr_ZJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_ZJetsToNuNu_HT-600to800.root");
tr_ZJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_ZJetsToNuNu_HT-800to1200.root");
cout<<"Total events present in process ZJets: "<<tr_ZJets->GetEntries()<<endl;
return tr_ZJets;

}
if(ProcessName=="WJets"){
TChain *tr_WJets=new TChain("tree");
tr_WJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_WJetsToLNu_HT-100to200.root");
tr_WJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_WJetsToLNu_HT-1200to2500.root");
tr_WJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_WJetsToLNu_HT-200to400.root");
tr_WJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_WJetsToLNu_HT-2500toInf.root");
tr_WJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_WJetsToLNu_HT-400to600.root");
tr_WJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_WJetsToLNu_HT-600to800.root");
tr_WJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_WJetsToLNu_HT-800to1200.root");
cout<<"Total events present in process WJets: "<<tr_WJets->GetEntries()<<endl;
return tr_WJets;

}
if(ProcessName=="HTMHT"){
TChain *tr_HTMHT=new TChain("tree");
tr_HTMHT->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_HTMHT_re2016B.root");
tr_HTMHT->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_HTMHT_re2016C.root");
tr_HTMHT->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_HTMHT_re2016D.root");
tr_HTMHT->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_HTMHT_re2016E.root");
tr_HTMHT->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_HTMHT_re2016F.root");
tr_HTMHT->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_HTMHT_re2016G.root");
tr_HTMHT->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_HTMHT_re2016H2.root");
tr_HTMHT->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/tree_HTMHT_re2016H3.root");
cout<<"Total events present in process HTMHT: "<<tr_HTMHT->GetEntries()<<endl;
return tr_HTMHT;

}
else{

throw std::invalid_argument( "You have provided an in valid argument , Try to look into the Inputdetails.dat and put a correct argument" );


}
}

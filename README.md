GenericNtuplePlotter are a set of codes that can be used to plot various things from Ntuple. The code assumes the root file have simple objects int, double, float,bool, TLorentzVector, vector<double>, vector<int>, vector<TLorentzVector> etc. Only you have to edit is the InputDetails.dat file to specify the root file locations, variables you want to plot and several other details. The code will automatically create the histograms and codes to fill them. It will also create member functions to create stacked plots.  

The code is tested in CMSLPC machine. But supposed work in other machines as well. Minor errors related to version compatibility may arise in other machines

Step0. Execute the following command to copy the code to your area
```
git clone https://github.com/bmahakud/GenericNtuplePlotter/
```

Step1. Edit the InputDetails.dat file according to your need

Specify the names of trees (folders if any) for signal, background and data files

```
####    Name of tree    #####
treeName_sig="TreeMaker2/PreSelection"
treeName_bkg="tree"
treeName_data="tree"

```
Specify the location of the files separately for signal, background and data. It should be just pwd output  of the directories 

```
#
fileLocation_sig="/eos/uscms/store/user/usarkar/Summer16/SUSYT5Signals/"
fileLocation_bkg="/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/"
fileLocation_data="/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/"
#
```

In the following specify the paths of the file the way you want all the files to be added in the TChain. If you are running on local laptop you may not need the root:://cmseos.fnal.gov 
```


####incase you are putting xrootrd path below put the filelocation above without xrootdpath
store_mc_sig = "root://cmseos.fnal.gov//store/user/usarkar/Summer16/SUSYT5Signals/"
store_mc_bkg = "root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/"
store_data = "root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV12/tree_signal/"
#
#
```
provide the names of the input files . You provide a * if a number of files repeat with a number

```


#####    Name of samples #####
#
#
list_mc_sig = ["Summer16.SMS-T5qqqqZH-mGluino1300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root","Summer16.SMS-T5qqqqZH-mGluino1700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_*_RA2AnalysisTree.root"]

```
Provide the short string names for signals
```

list_mc_sigNames =["T5qqqqZH_mG1300","T5qqqqZH_mG1700"]

```
If there are any process dependent cuts for example filter cuts etc. which can just be applied from the tree variables, you can put those directly here. Otherwise leave it blank
```
sig_cuts=[]
list_mc_sigNames_cuts ={"T5qqqqZH_mG1300":[],"T5qqqqZH_mG1700":[],}


```
Please do the same steps for bkg
```
#
#
#
list_mc_bkg = ["tree_QCD_HT-*.root","tree_TTJets_HT-*.root","tree_ZJetsToNuNu_HT*.root","tree_WJetsToLNu_HT-*.root"]
list_mc_bkgNames = ["QCD","TTJets","ZJets","WJets"]
bkg_cuts=[]
list_mc_bkgNames_cuts ={"QCD":[],"TTJets":bkg_cuts,"ZJets":[],"WJets":[]}

#
#
#
```
Please do all the steps as you did for sig and bkg
```


list_data = ["tree_HTMHT_re*.root"]
list_dataNames = ["HTMHT"]
data_cuts=[]
list_dataNames_cuts ={"HTMHT":data_cuts}

```
Mention just the name of the variables you want to plot. It may not be necessarily same as the names in the trees. If you want to plot some variable which is not in the tree and you want to calculate that variable using some algorithm and then fill in the histogram , then name the variable with a UserDef_ before it. For example UserDef_MT2. The code will create a member function with this name. Later after setting up the code you have to define what this function will do. By default it will Fill 1 in the corresponding histogram.

```


list_oneVariables=["HT","MET","NJets","BTags","DeltaPhi1","DeltaPhi2","DeltaPhi3","DeltaPhi4","LeadJetPt","LeadJetMass","LeadJetprunedMass","LeadNsubjettiness","LeaddoubleBDiscriminator","subLeadJetPt","subLeadJetMass","subLeadJetprunedMass","subLeadNsubjettiness","subLeaddoubleBDiscriminator","UserDef_MT2"]
```
You can directly tell the code how to fill the above set of variables. For the user defined function just write UserDef_VarName. Example UserDef_MT2. The length of the list below should the same as the list above 
```

list_VarsFill=["HT","MET","NJets","BTags","DeltaPhi1","DeltaPhi2","DeltaPhi3","DeltaPhi4","JetsAK8->at(0).Pt()","JetsAK8->at(0).M()","JetsAK8_prunedMass->at(0)","JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)","JetsAK8_doubleBDiscriminator->at(0)","JetsAK8->at(1).Pt()","JetsAK8->at(1).M()","JetsAK8_prunedMass->at(1)","JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)","JetsAK8_doubleBDiscriminator->at(1)","UserDef_MT2"]

```

Please specify if there are any baseline cuts . These cuts will be applied to both data and MC.
```

list_Baseline_cuts=["HT>200 && ","MET>200 && ","NJets>=2 && ","JetsAK8->size()>1 && ","DeltaPhi1>0.5 && ","DeltaPhi2>0.5 && ","DeltaPhi3>0.3 && ","DeltaPhi4>0.3 && ","Muons->size() == 0 && ","Electrons->size() == 0 && ","isoMuonTracks == 0 && ","isoElectronTracks == 0 && " ,"isoPionTracks == 0"]

```
If you want to categorize your search to many different sections. Please mention here. The code will create a set of same histograms for each category. It will also create member functions named with the category names. You have to tell the Looper_sig.C, Looper_bkg.C and Looper_data.C codes what these category means. By default it will return true for all categories.

```

list_Categories =["ZZ","ZH","HH"];


Usedefcategories="No"
#No
                                                                                                                                                                                                                           
 list_defCategories = ["HT>200","HT>200","HT>200"]


```

You have to provide the range of all the variables you want to plot. Otherwise the code will show error
```

list_HT_range=[200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3100,3200,3300,3400,3500]

list_MET_range=[200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,1650,1700,1750,1800,1850,1900,1950,2000]

list_NJets_range=[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]

list_BTags_range=[0,1,2,3,4,5,6,7]

list_DeltaPhi1_range=[0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0]

list_DeltaPhi2_range=[0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0]

list_DeltaPhi3_range=[0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0]

list_DeltaPhi4_range=[0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0]

list_LeadJetPt_range=[0,25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,450,475,500,525,550,575,600,625,650,675,700,725,750,775,800,825,850,875,900,925,950,975,1000,1025,1050,1075,1100,1125,1150,1175,1200]

list_LeadJetMass_range=[0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500]

list_LeadJetprunedMass_range=[0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500]

list_LeadNsubjettiness_range=[0,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09,0.10,0.11,0.12,0.13,0.14,0.15,0.16,0.17,0.18,0.19,0.20,0.21,0.22,0.23,0.24,0.25,0.26,0.27,0.28,0.29,0.30,0.31,0.32,0.33,0.34,0.35,0.36,0.37,0.38,0.39,0.40,0.41,0.42,0.43,0.44,0.45,0.46,0.47,0.48,0.49,0.50,0.51,0.52,0.53,0.54,0.55,0.56,0.57,0.58,0.59,0.60,0.61,0.62,0.63,0.64,0.65,0.66,0.67,0.68,0.69,0.70,0.71,0.72,0.73,0.74,0.75,0.76,0.77,0.78,0.79,0.80,0.81,0.82,0.83,0.84,0.85,0.86,0.87,0.88,0.89,0.90,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99,1.00]


list_LeaddoubleBDiscriminator_range=[0,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09,0.10,0.11,0.12,0.13,0.14,0.15,0.16,0.17,0.18,0.19,0.20,0.21,0.22,0.23,0.24,0.25,0.26,0.27,0.28,0.29,0.30,0.31,0.32,0.33,0.34,0.35,0.36,0.37,0.38,0.39,0.40,0.41,0.42,0.43,0.44,0.45,0.46,0.47,0.48,0.49,0.50,0.51,0.52,0.53,0.54,0.55,0.56,0.57,0.58,0.59,0.60,0.61,0.62,0.63,0.64,0.65,0.66,0.67,0.68,0.69,0.70,0.71,0.72,0.73,0.74,0.75,0.76,0.77,0.78,0.79,0.80,0.81,0.82,0.83,0.84,0.85,0.86,0.87,0.88,0.89,0.90,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99,1.00]


list_subLeadJetPt_range=[0,25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,450,475,500,525,550,575,600,625,650,675,700,725,750,775,800,825,850,875,900,925,950,975,1000,1025,1050,1075,1100,1125,1150,1175,1200]

list_subLeadJetMass_range=[0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500]

list_subLeadJetprunedMass_range=[0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500]

list_subLeadNsubjettiness_range=[0,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09,0.10,0.11,0.12,0.13,0.14,0.15,0.16,0.17,0.18,0.19,0.20,0.21,0.22,0.23,0.24,0.25,0.26,0.27,0.28,0.29,0.30,0.31,0.32,0.33,0.34,0.35,0.36,0.37,0.38,0.39,0.40,0.41,0.42,0.43,0.44,0.45,0.46,0.47,0.48,0.49,0.50,0.51,0.52,0.53,0.54,0.55,0.56,0.57,0.58,0.59,0.60,0.61,0.62,0.63,0.64,0.65,0.66,0.67,0.68,0.69,0.70,0.71,0.72,0.73,0.74,0.75,0.76,0.77,0.78,0.79,0.80,0.81,0.82,0.83,0.84,0.85,0.86,0.87,0.88,0.89,0.90,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99,1.00]


list_subLeaddoubleBDiscriminator_range=[0,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09,0.10,0.11,0.12,0.13,0.14,0.15,0.16,0.17,0.18,0.19,0.20,0.21,0.22,0.23,0.24,0.25,0.26,0.27,0.28,0.29,0.30,0.31,0.32,0.33,0.34,0.35,0.36,0.37,0.38,0.39,0.40,0.41,0.42,0.43,0.44,0.45,0.46,0.47,0.48,0.49,0.50,0.51,0.52,0.53,0.54,0.55,0.56,0.57,0.58,0.59,0.60,0.61,0.62,0.63,0.64,0.65,0.66,0.67,0.68,0.69,0.70,0.71,0.72,0.73,0.74,0.75,0.76,0.77,0.78,0.79,0.80,0.81,0.82,0.83,0.84,0.85,0.86,0.87,0.88,0.89,0.90,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99,1.00]
                                                                                                                                                                                                                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                           

```














Step2. Execute the following command to create Analyzer.C that you will use for various purposes
```
./Setup
```

Step3.
```
root -l Analyzer.C
```

You can define various histograms inside Analyzer.C and do your analysis



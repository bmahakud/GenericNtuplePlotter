def getVarFromFile(filename):
    import imp
    f = open(filename)
    global data
    data = imp.load_source('data', '', f)
    f.close()

getVarFromFile('InputDetails.dat')
import os



import sys
sys.stdout = open('stackPlotter.C','w')

print '#include "SetStyle.C"\n'
print '#include "TH1F.h"\n'
print '#include "TPaveText.h"\n'
print '#include "TLegend.h"\n'
print '#include "TCanvas.h"\n'
print '#include "THStack.h"\n'
print '#include <string>\n'
print '#include <iostream>\n'

print 'class StackPlotter{\n '


print 'public:'



for isig in range(0,len(data.list_mc_sig)+1):
    for ibkg in range(0,len(data.list_mc_bkg)+1):
       print 'void plotS%iB%iD0('%(isig,ibkg),
       if isig>0 or ibkg>0:
           print 'string VarName,TPaveText *txtGen ,',
       for ihs in range(0,isig):
           print 'TH1F *hs%i'%(ihs+1),
           print ',', 
           print 'string sig_proc%s'%(ihs+1),
           if ihs+1 < isig:
              print ',', 
           
       for ihb in range(0,ibkg):
           if isig>0:
               print ',',
           print ' TH1F *hb%i '%(ihb+1),
           print ',', 
           print 'string bkg_proc%s'%(ihb+1),
           if isig==0 and ihb+1 < ibkg: 
              print ',',
       print ');'


       print 'void plotS%iB%iD1('%(isig,ibkg),
       print 'string VarName,TPaveText *txtGen ,',
       for ihs in range(0,isig):
           print 'TH1F *hs%i, '%(ihs+1),
           print 'string sig_proc%s, '%(ihs+1),
       for ihb in range(0,ibkg):
           print 'TH1F *hb%i, '%(ihb+1),
           print 'string bkg_proc%s, '%(ihb+1),
       print 'TH1F *hd, string proc_data);'








print '};'


for isig in range(0,len(data.list_mc_sig)+1):
    for ibkg in range(0,len(data.list_mc_bkg)+1):
       print 'void StackPlotter::plotS%iB%iD0('%(isig,ibkg),
       if isig>0 or ibkg>0:
           print 'string VarName,TPaveText *txtGen ,',
       for ihs in range(0,isig):
           print 'TH1F *hs%i'%(ihs+1),
           print ',', 
           print 'string sig_proc%s'%(ihs+1)
           if ihs+1 < isig:
              print ',',
       for ihb in range(0,ibkg):
           if isig>0:
               print ',',
           print ' TH1F *hb%i '%(ihb+1),
           print ',', 
           print 'string bkg_proc%s'%(ihb+1),
           if isig==0 and ihb+1 < ibkg:
              print ',',
       print '){'
       print 'using namespace std;'
           
       print 'TStyle *gStyle = new TStyle("gStyle","Style for P-TDR");'
       print 'SetStyle st;'
       print 'st.SetPars(gStyle);'
       if isig>0 or ibkg >0:
         print 'char Variable[100];'
         print 'char Cname[100];'
         print 'const char *Var_Name;'
         print 'Var_Name=VarName.c_str();'
         print 'sprintf(Variable," ;%s; Events",Var_Name);'
         print 'sprintf(Cname,"%s",Var_Name);'
       print 'TPaveText *pCMS = new TPaveText(0.132107,0.9308003,0.8327759,0.9923583,"brNDC");'

       print 'pCMS->SetBorderSize(0);'
       print 'pCMS->SetFillStyle(0);'
       print 'pCMS->SetTextAlign(11);'
       print 'pCMS->SetTextFont(42);'
       print 'pCMS->SetTextSize(0.04);'
       print 'pCMS->AddText("CMS #it{Preliminary}                   36 fb^{-1}, #sqrt{s}= 13 TeV");' 
       
       print 'TLegend *leg=new TLegend(0.3582943,0.7051483,0.55025753,0.9049564,NULL,"brNDC");'
       print 'leg->SetTextFont(62);'
       print 'leg->SetLineColor(1);'
       print 'leg->SetLineStyle(1);'
       print 'leg->SetLineWidth(3);'
       print 'leg->SetFillColor(0);'
       print 'leg->SetFillStyle(1001);'
       print 'leg->SetShadowColor(0);'
       print 'leg->SetDrawOption(0);'
       print 'leg->SetBorderSize(0);'
       print 'leg->SetTextSize(0.03);'



       if isig > 0 or ibkg >0:
           print 'THStack *hallbkg=new THStack("hallbkg",Variable);'
       else:
           print 'THStack *hallbkg=new THStack("hallbkg","a;x;y");'
       for ihb in range(0,ibkg):
           print 'hb%i->SetFillColor(%i);'%(ihb+1,ihb+2)
           print 'hb%i->SetLineColor(%i);'%(ihb+1,1) 
           print 'hallbkg->Add(hb%i);'%(ihb+1)
           print 'char h%sL_bkg[100];'%(ihb+1)
           print 'const char *h%s_L_bkg;'%(ihb+1)
           print 'h%s_L_bkg=bkg_proc%s.c_str();'%(ihb+1,ihb+1)
           print 'sprintf(h%sL_bkg,"%s",h%s_L_bkg);'%(ihb+1,"%s",ihb+1)
           print 'leg->AddEntry(hb%i,h%sL_bkg,"f");'%(ihb+1,ihb+1)

       for ihs in range(0,isig):
           print 'hs%i->SetFillStyle(1);'%(ihs+1)
           print 'hs%i->SetLineColor(%i);'%(ihs+1,1)
           print 'char h%sL_sig[100];'%(ihs+1)
           print 'const char *h%s_L_sig;'%(ihs+1)
           print 'h%s_L_sig=sig_proc%s.c_str();'%(ihs+1,ihs+1)
           print 'sprintf(h%sL_sig,"%s",h%s_L_sig);'%(ihs+1,"%s",ihs+1)
           print 'leg->AddEntry(hs%i,h%sL_sig,"l");'%(ihs+1,ihs+1)


       if isig> 0 or ibkg>0:
           print 'TCanvas *c=new TCanvas(Cname,Cname);'
       else:
           print 'TCanvas *c=new TCanvas("c","c");'
       print 'c->cd();'
       print 'hallbkg->Draw("hist");'
       print 'hallbkg->GetYaxis()->SetTitle("Events");'
       print 'hallbkg->Draw("hist");'
       for ihs in range(0,isig):
          print 'hs%i->Draw("same");'%(ihs+1)
       if isig >0 or ibkg >0:
          print 'txtGen->Draw();'
       print 'pCMS->Draw();'
       print 'leg->Draw();'
       print 'c->Write();'
      # print 'h1->Draw("P,E1 SAME");'




       print '}\n'


       print 'void StackPlotter::plotS%iB%iD1('%(isig,ibkg),
       print 'string VarName,TPaveText *txtGen ,',
       for ihs in range(0,isig):
           print 'TH1F *hs%i, '%(ihs+1),
           print 'string sig_proc%s, '%(ihs+1)
       for ihb in range(0,ibkg):
           print 'TH1F *hb%i, '%(ihb+1),
           print 'string bkg_proc%s, '%(ihb+1)
       print 'TH1F *hd, string proc_data){'
       print 'using namespace std;'
       print 'TStyle *gStyle = new TStyle("gStyle","Style for P-TDR");'
       print 'SetStyle st;'
       print 'st.SetPars(gStyle);'
       print 'TPaveText *pCMS = new TPaveText(0.132107,0.9308003,0.8327759,0.9923583,"brNDC");'

       print 'pCMS->SetBorderSize(0);'
       print 'pCMS->SetFillStyle(0);'
       print 'pCMS->SetTextAlign(11);'
       print 'pCMS->SetTextFont(42);'
       print 'pCMS->SetTextSize(0.04);'
       print 'pCMS->AddText("CMS #it{Preliminary}                   36 fb^{-1}, #sqrt{s}= 13 TeV");' 

       print 'TLegend *leg=new TLegend(0.3582943,0.7051483,0.55025753,0.9049564,NULL,"brNDC");'
       print 'leg->SetTextFont(62);'
       print 'leg->SetLineColor(1);'
       print 'leg->SetLineStyle(1);'
       print 'leg->SetLineWidth(3);'
       print 'leg->SetFillColor(0);'
       print 'leg->SetFillStyle(1001);'
       print 'leg->SetShadowColor(0);'
       print 'leg->SetDrawOption(0);'
       print 'leg->SetBorderSize(0);'
       print 'leg->SetTextSize(0.03);'



       print 'char Variable[100];'
       print 'char Cname[100];'
       print 'const char *Var_Name;'
       print 'Var_Name=VarName.c_str();'
       print 'sprintf(Variable," ;%s;Events",Var_Name);'
       print 'sprintf(Cname,"%s",Var_Name);'

       print 'THStack *hallbkg=new THStack("hallbkg",Variable);'
       for ihb in range(0,ibkg):
           print 'hb%i->SetFillColor(%i);'%(ihb+1,ihb+2)
           print 'hb%i->SetLineColor(%i);'%(ihb+1,1)
           print 'hallbkg->Add(hb%i);'%(ihb+1)
           print 'char h%sL_bkg[100];'%(ihb+1)
           print 'const char *h%s_L_bkg;'%(ihb+1)
           print 'h%s_L_bkg=bkg_proc%s.c_str();'%(ihb+1,ihb+1)
           print 'sprintf(h%sL_bkg,"%s",h%s_L_bkg);'%(ihb+1,"%s",ihb+1)
           print 'leg->AddEntry(hb%i,h%sL_bkg,"f");'%(ihb+1,ihb+1)
       for ihs in range(0,isig):
           print 'hs%i->SetFillStyle(1);'%(ihs+1)
           print 'hs%i->SetLineColor(%i);'%(ihs+1,1)
           print 'char h%sL_sig[100];'%(ihs+1)
           print 'const char *h%s_L_sig;'%(ihs+1)
           print 'h%s_L_sig=sig_proc%s.c_str();'%(ihs+1,ihs+1)
           print 'sprintf(h%sL_sig,"%s",h%s_L_sig);'%(ihs+1,"%s",ihs+1)
           print 'leg->AddEntry(hs%i,h%sL_sig,"l");'%(ihs+1,ihs+1)

       print 'hd->SetLineColor(1);'
       print 'hd->SetMarkerStyle(20);'
       print 'char hL_data[100];'
       print 'const char *h_L_data;'
       print 'h_L_sig=proc_data.c_str();'
       print 'sprintf(hL_data,"%s",h_L_sig);'
       print 'leg->AddEntry(hd,hL_data,"p");'


       print 'TCanvas *c=new TCanvas(Cname,Cname);'
       print 'c->cd();'
       print 'hallbkg->Draw("hist");'
       print 'hallbkg->GetYaxis()->SetTitle("Events");'
       print 'hallbkg->Draw("hist");'
       for ihs in range(0,isig):
          print 'hs%i->Draw("same");'%(ihs+1)

       print 'hd->Draw("P,E1 SAME");'
       print 'txtGen->Draw();'
       print 'pCMS->Draw();'
       print 'leg->Draw();'
       print 'c->Write();'
       print '}\n'




















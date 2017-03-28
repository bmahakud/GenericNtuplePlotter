class HistoCreater{

int x,y,z;




HistoCreater::HistoCreater(int a,int b,int c){
x=a;
y=b;
z=c;


}


HistoCreater::Input(string trVarName, string VarName);



};



HistoCreater::Input(string trVarName, string VarName,double range[]){


cout<<"print: "<<trVarName<<","<<VarName<<range[0]<<endl;

TH1F *h=new TH1F("h","h",100,0,100);
h->Fill(1);
h->Fill(2);
}



















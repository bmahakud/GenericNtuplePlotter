sed -i 's/tree=0/tree/' ClassReadSig.cc
sed -i 's/virtual Int_t    Cut(Long64_t entry);//' ClassReadSig.cc
sed -i 's/virtual Int_t    GetEntry(Long64_t entry);//' ClassReadSig.cc
sed -i 's/virtual Long64_t LoadTree(Long64_t entry);//' ClassReadSig.cc
sed -i 's/virtual void     Loop();//' ClassReadSig.cc
sed -i 's/virtual Bool_t   Notify();//' ClassReadSig.cc
sed -i 's/virtual void     Show(Long64_t entry = -1);//' ClassReadSig.cc
sed -i 's/Notify();//' ClassReadSig.cc

rm ClassReadSig.h ClassReadSig.C




sed -i 's/tree=0/tree/' ClassReadBkg.cc
sed -i 's/virtual Int_t    Cut(Long64_t entry);//' ClassReadBkg.cc
sed -i 's/virtual Int_t    GetEntry(Long64_t entry);//' ClassReadBkg.cc
sed -i 's/virtual Long64_t LoadTree(Long64_t entry);//' ClassReadBkg.cc
sed -i 's/virtual void     Loop();//' ClassReadBkg.cc
sed -i 's/virtual Bool_t   Notify();//' ClassReadBkg.cc
sed -i 's/virtual void     Show(Long64_t entry = -1);//' ClassReadBkg.cc
sed -i 's/Notify();//' ClassReadBkg.cc

rm ClassReadBkg.h ClassReadBkg.C

sed -i 's/tree=0/tree/' ClassReadData.cc
sed -i 's/virtual Int_t    Cut(Long64_t entry);//' ClassReadData.cc
sed -i 's/virtual Int_t    GetEntry(Long64_t entry);//' ClassReadData.cc
sed -i 's/virtual Long64_t LoadTree(Long64_t entry);//' ClassReadData.cc
sed -i 's/virtual void     Loop();//' ClassReadData.cc
sed -i 's/virtual Bool_t   Notify();//' ClassReadData.cc
sed -i 's/virtual void     Show(Long64_t entry = -1);//' ClassReadData.cc
sed -i 's/Notify();//' ClassReadData.cc

rm ClassReadData.h ClassReadData.C

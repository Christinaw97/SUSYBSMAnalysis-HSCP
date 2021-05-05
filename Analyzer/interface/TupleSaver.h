#include "SUSYBSMAnalysis/Analyzer/interface/Tuple.h"

struct Tuple;

class TupleSaver{
   public:
      TupleSaver();
      ~TupleSaver();

      void initializeTuple(Tuple* &tuple, TFileDirectory &dir, bool SkipSelectionPlot, int TypeMode, bool isSignal, unsigned int NCuts, unsigned int NCuts_Flip, double PtHistoUpperBound, double MassHistoUpperBound, int MassNBins, double IPbound, int PredBins, int EtaBins, double dEdxS_UpLim, double dEdxM_UpLim, int DzRegions, double GlobalMinPt, double GlobalMinTOF);

      void fillTreeBranches(Tuple* &tuple, unsigned int Trig, unsigned int Run, unsigned int Event,unsigned int Lumi, unsigned int Hscp, double Charge, double Pt,double PtErr, double I, double Ih, double Ick, double TOF, double Mass, double dZ, double dXY, double dR, double eta, double phi, unsigned int noh, int noph,double fovh,unsigned int nomh,double fovhd, unsigned int nom, double weight, double genid, double gencharge, double genmass, double genpt, double geneta, double genphi);

      void fillControlAndPredictionHist(const susybsm::HSCParticle& hscp, const reco::DeDxData* dedxSObj, const reco::DeDxData* dedxMObj, const reco::MuonTimeExtra* tof, Tuple* &tuple, int TypeMode, double GlobalMinTOF,float Event_Weight, bool isCosmicSB, float DTRegion, const int MaxPredBins, bool isMCglobal, double DeDxK, double DeDxC, std::vector<double> CutPt, std::vector<double> CutI, std::vector<double> CutTOF, std::vector<double> CutPt_Flip, std::vector<double> CutI_Flip, std::vector<double>CutTOF_Flip);
};

//=============================================================
//
//     Create histograms, tree variables and branches
//
//=============================================================


void TupleSaver::initializeTuple(Tuple* &tuple, TFileDirectory &dir, bool SkipSelectionPlot, int TypeMode, bool isSignal, unsigned int NCuts, unsigned int NCuts_Flip, double PtHistoUpperBound, double MassHistoUpperBound, int MassNBins, double IPbound, int PredBins, int EtaBins, double dEdxS_UpLim, double dEdxM_UpLim, int DzRegions, double GlobalMinPt, double GlobalMinTOF){

   std::string Name;

   Name = "IntLumi";  tuple->IntLumi = dir.make<TProfile>(Name.c_str(), Name.c_str(),  1    , 0,  1);
   Name = "TotalE";   tuple->TotalE  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "TotalEPU"; tuple->TotalEPU= dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);
   Name = "TotalTE";  tuple->TotalTE = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "Total";    tuple->Total   = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "V3D";      tuple->V3D     = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "Chi2";     tuple->Chi2    = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "Qual";     tuple->Qual    = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "TNOH";     tuple->TNOH    = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "TNOM";     tuple->TNOM    = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);
   Name = "nDof";     tuple->nDof    = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "tofError"; tuple->tofError= dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);
   Name = "Pterr";    tuple->Pterr   = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "TIsol";    tuple->TIsol   = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "EIsol";    tuple->EIsol   = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "SumpTOverpT";  tuple->SumpTOverpT = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "MPt";      tuple->MPt     = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "MI";       tuple->MI      = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "MTOF";     tuple->MTOF    = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);     
   Name = "Pt";       tuple->Pt      = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);     
   Name = "I";        tuple->I       = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);     
   Name = "TOF";      tuple->TOF     = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);     tuple->TOF    ->Sumw2();
   Name = "HSCPE";    tuple->HSCPE   = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);     tuple->HSCPE    ->Sumw2();
   Name = "NVTrack";  tuple->NVTrack = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);
   Name = "Stations"; tuple->Stations= dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);
   Name = "Dxy";      tuple->Dxy     = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);
   Name = "Dz";       tuple->Dz      = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);
   Name = "SegSep";   tuple->SegSep  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);
   Name = "FailDz";   tuple->FailDz  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);
   Name = "Basic";    tuple->Basic   = dir.make<TH1F>(Name.c_str(), Name.c_str(),  1    , 0,  1);

   Name = "HSCPE_SystP";    tuple->HSCPE_SystP  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);    tuple->HSCPE_SystP    ->Sumw2();
   Name = "HSCPE_SystI";    tuple->HSCPE_SystI  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);    tuple->HSCPE_SystI    ->Sumw2();
   Name = "HSCPE_SystM";    tuple->HSCPE_SystM  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);    tuple->HSCPE_SystM    ->Sumw2();
   Name = "HSCPE_SystT";    tuple->HSCPE_SystT  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);    tuple->HSCPE_SystT    ->Sumw2();
   Name = "HSCPE_SystPU";   tuple->HSCPE_SystPU = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);    tuple->HSCPE_SystPU    ->Sumw2();
   Name = "HSCPE_SystHUp";      tuple->HSCPE_SystHUp  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);    tuple->HSCPE_SystHUp    ->Sumw2();
   Name = "HSCPE_SystHDown";    tuple->HSCPE_SystHDown  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  NCuts, 0,  NCuts);    tuple->HSCPE_SystHDown    ->Sumw2();

   
   Name = "Mass";     tuple->Mass     = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->Mass    ->Sumw2();
   Name = "MassTOF";  tuple->MassTOF  = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassTOF ->Sumw2();
   Name = "MassComb"; tuple->MassComb = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassComb->Sumw2();
   Name = "MaxEventMass";     tuple->MaxEventMass     = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MaxEventMass    ->Sumw2();

   Name = "Mass_SystP";     tuple->Mass_SystP     = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->Mass_SystP    ->Sumw2();
   Name = "MassTOF_SystP";  tuple->MassTOF_SystP  = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassTOF_SystP ->Sumw2();
   Name = "MassComb_SystP"; tuple->MassComb_SystP = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassComb_SystP->Sumw2();
   Name = "MaxEventMass_SystP";     tuple->MaxEventMass_SystP = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound); tuple->MaxEventMass_SystP->Sumw2();

   Name = "Mass_SystI";     tuple->Mass_SystI     = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->Mass_SystI    ->Sumw2();
   Name = "MassTOF_SystI";  tuple->MassTOF_SystI  = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassTOF_SystI ->Sumw2();
   Name = "MassComb_SystI"; tuple->MassComb_SystI = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassComb_SystI->Sumw2();
   Name = "MaxEventMass_SystI";     tuple->MaxEventMass_SystI = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound); tuple->MaxEventMass_SystI->Sumw2();

   Name = "Mass_SystM";     tuple->Mass_SystM     = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->Mass_SystM    ->Sumw2();
   Name = "MassTOF_SystM";  tuple->MassTOF_SystM  = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassTOF_SystM ->Sumw2();
   Name = "MassComb_SystM"; tuple->MassComb_SystM = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassComb_SystM->Sumw2();
   Name = "MaxEventMass_SystM";     tuple->MaxEventMass_SystM = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound); tuple->MaxEventMass_SystM->Sumw2();

   Name = "Mass_SystT";     tuple->Mass_SystT     = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->Mass_SystT    ->Sumw2();
   Name = "MassTOF_SystT";  tuple->MassTOF_SystT  = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassTOF_SystT ->Sumw2();
   Name = "MassComb_SystT"; tuple->MassComb_SystT = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassComb_SystT->Sumw2();
   Name = "MaxEventMass_SystT";     tuple->MaxEventMass_SystT = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound); tuple->MaxEventMass_SystT->Sumw2();

   Name = "Mass_SystPU";    tuple->Mass_SystPU     = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->Mass_SystPU    ->Sumw2();
   Name = "MassTOF_SystPU"; tuple->MassTOF_SystPU  = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassTOF_SystPU ->Sumw2();
   Name = "MassComb_SystPU";tuple->MassComb_SystPU = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassComb_SystPU->Sumw2();
   Name = "MaxEventMass_SystPU";  tuple->MaxEventMass_SystPU = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);tuple->MaxEventMass_SystPU->Sumw2();

   Name = "Mass_SystHUp";     tuple->Mass_SystHUp     = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->Mass_SystHUp    ->Sumw2();
   Name = "MassTOF_SystH";  tuple->MassTOF_SystH  = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassTOF_SystH ->Sumw2();
   Name = "MassComb_SystHUp"; tuple->MassComb_SystHUp = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassComb_SystHUp->Sumw2();
   Name = "MaxEventMass_SystHUp";     tuple->MaxEventMass_SystHUp = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);tuple->MaxEventMass_SystHUp->Sumw2();

   Name = "Mass_SystHDown";     tuple->Mass_SystHDown     = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->Mass_SystHDown    ->Sumw2();
   Name = "MassComb_SystHDown"; tuple->MassComb_SystHDown = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassComb_SystHDown->Sumw2();
   Name = "MaxEventMass_SystHDown";     tuple->MaxEventMass_SystHDown = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);tuple->MaxEventMass_SystHDown->Sumw2();


   Name = "Mass_Flip";     tuple->Mass_Flip     = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->Mass_Flip    ->Sumw2();
   Name = "MassTOF_Flip";  tuple->MassTOF_Flip  = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassTOF_Flip ->Sumw2();
   Name = "MassComb_Flip"; tuple->MassComb_Flip = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts, MassNBins, 0, MassHistoUpperBound);   tuple->MassComb_Flip->Sumw2();

   if(SkipSelectionPlot)return;
   
   Name = "Gen_DecayLength"  ; tuple->Gen_DecayLength  = dir.make<TH1F>(Name.c_str(), Name.c_str(),               1000, 0,1000); tuple->Gen_DecayLength  ->Sumw2();
   Name = "Beta_Gen"         ; tuple->Beta_Gen         = dir.make<TH1F>(Name.c_str(), Name.c_str(),                 20, 0,  1);  tuple->Beta_Gen         ->Sumw2();
   Name = "Beta_GenChaged"   ; tuple->Beta_GenCharged  = dir.make<TH1F>(Name.c_str(), Name.c_str(),                 20, 0,  1);  tuple->Beta_GenCharged  ->Sumw2();
   Name = "Beta_Triggered"   ; tuple->Beta_Triggered   = dir.make<TH1F>(Name.c_str(), Name.c_str(),                 20, 0,  1);  tuple->Beta_Triggered   ->Sumw2();
   Name = "Beta_Matched"     ; tuple->Beta_Matched     = dir.make<TH1F>(Name.c_str(), Name.c_str(),                 20, 0,  1);  tuple->Beta_Matched     ->Sumw2();
   Name = "Beta_PreselectedA"; tuple->Beta_PreselectedA= dir.make<TH1F>(Name.c_str(), Name.c_str(),                 20, 0,  1);  tuple->Beta_PreselectedA->Sumw2();
   Name = "Beta_PreselectedB"; tuple->Beta_PreselectedB= dir.make<TH1F>(Name.c_str(), Name.c_str(),                 20, 0,  1);  tuple->Beta_PreselectedB->Sumw2();
   Name = "Beta_PreselectedC"; tuple->Beta_PreselectedC= dir.make<TH1F>(Name.c_str(), Name.c_str(),                 20, 0,  1);  tuple->Beta_PreselectedC->Sumw2();
   Name = "Beta_SelectedP"   ; tuple->Beta_SelectedP   = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts,   20, 0,  1);  tuple->Beta_SelectedP   ->Sumw2();
   Name = "Beta_SelectedI"   ; tuple->Beta_SelectedI   = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts,   20, 0,  1);  tuple->Beta_SelectedI   ->Sumw2();
   Name = "Beta_SelectedT"   ; tuple->Beta_SelectedT   = dir.make<TH2F>(Name.c_str(), Name.c_str(),NCuts,0,NCuts,   20, 0,  1);  tuple->Beta_SelectedT   ->Sumw2();

   Name = "BS_V3D"  ; tuple->BS_V3D   = dir.make<TH1F>(Name.c_str(), Name.c_str(),  150,  0,  IPbound);                tuple->BS_V3D->Sumw2();
   Name = "BS_Chi2" ; tuple->BS_Chi2  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  20,  0,  20);                tuple->BS_Chi2->Sumw2();
   Name = "BS_Qual" ; tuple->BS_Qual  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  20,  0, 20);                tuple->BS_Qual->Sumw2();
   Name = "BS_TNOH" ; tuple->BS_TNOH  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50,  0,  40);                tuple->BS_TNOH->Sumw2();
   Name = "BS_TNOH_PUA" ; tuple->BS_TNOH_PUA  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50,  0,  40);                tuple->BS_TNOH_PUA->Sumw2();
   Name = "BS_TNOH_PUB" ; tuple->BS_TNOH_PUB  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50,  0,  40);                tuple->BS_TNOH_PUB->Sumw2();
   Name = "BS_TNOHFraction" ; tuple->BS_TNOHFraction  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50,  0,  1);                tuple->BS_TNOHFraction->Sumw2();
   Name = "BS_TNOPH" ; tuple->BS_TNOPH  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  16,  0,  8);                tuple->BS_TNOPH->Sumw2();
   Name = "BS_TNOHFractionTillLast" ; tuple->BS_TNOHFractionTillLast  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50,  0,  1);                tuple->BS_TNOHFractionTillLast->Sumw2();
   Name = "BS_TNOMHTillLast" ; tuple->BS_TNOMHTillLast  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  20,  0,  20);                tuple->BS_TNOMHTillLast->Sumw2();
   Name = "BS_Eta" ; tuple->BS_Eta  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50,  -2.6,  2.6);                tuple->BS_Eta->Sumw2();
   Name = "BS_TNOM" ; tuple->BS_TNOM  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  40,  0, 40);                tuple->BS_TNOM->Sumw2();
   Name = "BS_TNOM_PUA" ; tuple->BS_TNOM_PUA  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  40,  0, 40);                tuple->BS_TNOM_PUA->Sumw2();
   Name = "BS_TNOM_PUB" ; tuple->BS_TNOM_PUB  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  40,  0, 40);                tuple->BS_TNOM_PUB->Sumw2();
   Name = "BS_nDof" ; tuple->BS_nDof  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  20,  0, 40);                tuple->BS_nDof->Sumw2();
   Name = "BS_TOFError" ; tuple->BS_TOFError  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  25,  0, 0.25);                tuple->BS_TOFError->Sumw2();
   Name = "BS_PtErr"; tuple->BS_Pterr = dir.make<TH1F>(Name.c_str(), Name.c_str(),  40,  0,  1);                tuple->BS_Pterr->Sumw2();
   Name = "BS_MPt"  ; tuple->BS_MPt   = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50,  0, PtHistoUpperBound); tuple->BS_MPt->Sumw2();
   Name = "BS_MIs"  ; tuple->BS_MIs   = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50,  0, dEdxS_UpLim);       tuple->BS_MIs->Sumw2();
   Name = "BS_MIm"  ; tuple->BS_MIm   = dir.make<TH1F>(Name.c_str(), Name.c_str(),  200,  0, dEdxM_UpLim);       tuple->BS_MIm->Sumw2();
   Name = "BS_MTOF" ; tuple->BS_MTOF  = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50, -2, 5);                 tuple->BS_MTOF->Sumw2();
   Name = "BS_TIsol"; tuple->BS_TIsol = dir.make<TH1F>(Name.c_str(), Name.c_str(),  25,  0, 100);               tuple->BS_TIsol->Sumw2();
   Name = "BS_EIsol"; tuple->BS_EIsol = dir.make<TH1F>(Name.c_str(), Name.c_str(),  25,  0, 1.5);               tuple->BS_EIsol->Sumw2();
   Name = "BS_SumpTOverpT";  tuple->BS_SumpTOverpT = dir.make<TH1F>(Name.c_str(), Name.c_str(), 80, 0.0,  2.0);  tuple->BS_SumpTOverpT    ->Sumw2();
   Name = "BS_LastHitDXY"    ; tuple->BS_LastHitDXY     = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   75, 0, 150); tuple->BS_LastHitDXY->Sumw2();
   Name = "BS_LastHitD3D"    ; tuple->BS_LastHitD3D     = dir.make<TH1F>(Name.c_str(), Name.c_str(),                  175, 0, 350); tuple->BS_LastHitD3D->Sumw2();
   Name = "BS_P"    ; tuple->BS_P     = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound); tuple->BS_P->Sumw2();
   Name = "BS_Pt"   ; tuple->BS_Pt    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound); tuple->BS_Pt->Sumw2();
   Name = "BS_Pt_PUA"   ; tuple->BS_Pt_PUA    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound); tuple->BS_Pt_PUA->Sumw2();
   Name = "BS_Pt_PUB"   ; tuple->BS_Pt_PUB    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound); tuple->BS_Pt_PUB->Sumw2();
   Name = "BS_Pt_Cosmic"   ; tuple->BS_Pt_Cosmic    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound); tuple->BS_Pt_Cosmic->Sumw2();
   Name = "BS_Pt_DT"   ; tuple->BS_Pt_DT    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound); tuple->BS_Pt_DT->Sumw2();
   Name = "BS_Pt_CSC"   ; tuple->BS_Pt_CSC    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound); tuple->BS_Pt_CSC->Sumw2();
   Name = "BS_Is"   ; tuple->BS_Is    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   100, 0, dEdxS_UpLim);       tuple->BS_Is->Sumw2();
   Name = "BS_Is_PUA"   ; tuple->BS_Is_PUA    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   100, 0, dEdxS_UpLim);       tuple->BS_Is_PUA->Sumw2();
   Name = "BS_Is_PUB"   ; tuple->BS_Is_PUB    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   100, 0, dEdxS_UpLim);       tuple->BS_Is_PUB->Sumw2();
   Name = "BS_Is_Cosmic"   ; tuple->BS_Is_Cosmic    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   100, 0, dEdxS_UpLim);       tuple->BS_Is_Cosmic->Sumw2();
   Name = "BS_Im"   ; tuple->BS_Im    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   200, 0, dEdxM_UpLim);       tuple->BS_Im->Sumw2();
   Name = "BS_Im_PUA"   ; tuple->BS_Im_PUA    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   200, 0, dEdxM_UpLim);       tuple->BS_Im_PUA->Sumw2();
   Name = "BS_Im_PUB"   ; tuple->BS_Im_PUB    = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   200, 0, dEdxM_UpLim);       tuple->BS_Im_PUB->Sumw2();
   Name = "BS_TOF"  ; tuple->BS_TOF   = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   150, -1, 5);                 tuple->BS_TOF->Sumw2();
   Name = "BS_TOF_PUA"  ; tuple->BS_TOF_PUA   = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   150, -1, 5);                 tuple->BS_TOF_PUA->Sumw2();
   Name = "BS_TOF_PUB"  ; tuple->BS_TOF_PUB   = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   150, -1, 5);                 tuple->BS_TOF_PUB->Sumw2();
   Name = "BS_TOF_DT"  ; tuple->BS_TOF_DT   = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   150, -1, 5);                 tuple->BS_TOF_DT->Sumw2();
   Name = "BS_TOF_CSC"  ; tuple->BS_TOF_CSC   = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   150, -1, 5);                 tuple->BS_TOF_CSC->Sumw2();
   Name = "BS_dR_NVTrack"  ; tuple->BS_dR_NVTrack = dir.make<TH1F>(Name.c_str(), Name.c_str(), 40, 0, 1); tuple->BS_dR_NVTrack->Sumw2();
   Name = "BS_MatchedStations"  ; tuple->BS_MatchedStations= dir.make<TH1F>(Name.c_str(), Name.c_str(),                   8, -0.5, 7.5); tuple->BS_MatchedStations->Sumw2();
   Name = "BS_InnerInvPtDiff"  ; tuple->BS_InnerInvPtDiff = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   120, -4, 4); tuple->BS_InnerInvPtDiff->Sumw2();
   Name = "BS_Phi"  ; tuple->BS_Phi = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, -3.14, 3.14); tuple->BS_Phi->Sumw2();
   Name = "BS_TimeAtIP"  ; tuple->BS_TimeAtIP = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, -100, 100); tuple->BS_TimeAtIP->Sumw2();
   Name = "BS_OpenAngle"  ; tuple->BS_OpenAngle = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, -0.3, 3.15); tuple->BS_OpenAngle->Sumw2();
   Name = "BS_OpenAngle_Cosmic"  ; tuple->BS_OpenAngle_Cosmic = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, -0.3, 3.15); tuple->BS_OpenAngle_Cosmic->Sumw2();

   Name = "BS_NVertex";  tuple->BS_NVertex = dir.make<TH1F>(Name.c_str(), Name.c_str(), 50, 0,  50);  tuple->BS_NVertex    ->Sumw2();
   Name = "BS_NVertex_NoEventWeight";    tuple->BS_NVertex_NoEventWeight = dir.make<TH1F>(Name.c_str(), Name.c_str(), 50, 0, 50);     tuple->BS_NVertex_NoEventWeight    ->Sumw2();
   Name = "BS_PV"  ; tuple->BS_PV = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   60, 0, 60); tuple->BS_PV->Sumw2();
   Name = "BS_PV_NoEventWeight"  ; tuple->BS_PV_NoEventWeight = dir.make<TH1F>(Name.c_str(), Name.c_str(),                   60, 0, 60); tuple->BS_PV_NoEventWeight->Sumw2();
   Name = "BS_NOMoNOHvsPV"  ; tuple->BS_NOMoNOHvsPV = dir.make<TProfile>(Name.c_str(), Name.c_str(),                   60, 0, 60); tuple->BS_NOMoNOHvsPV->Sumw2();
   Name = "BS_dzAll";      tuple->BS_dzAll = dir.make<TH1F>(Name.c_str(), Name.c_str(),200, -10, 10);          tuple->BS_dzAll->Sumw2();
   Name = "BS_dxyAll";     tuple->BS_dxyAll = dir.make<TH1F>(Name.c_str(), Name.c_str(),200, -10, 10);         tuple->BS_dxyAll->Sumw2();
   Name = "BS_dzMinv3d";   tuple->BS_dzMinv3d = dir.make<TH1F>(Name.c_str(), Name.c_str(),200, -10, 10);       tuple->BS_dzMinv3d->Sumw2();
   Name = "BS_dxyMinv3d";  tuple->BS_dxyMinv3d = dir.make<TH1F>(Name.c_str(), Name.c_str(),200, -10, 10);      tuple->BS_dxyMinv3d->Sumw2();

   Name = "BS_SegSep"  ; tuple->BS_SegSep= dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, 0, 2.5); tuple->BS_SegSep->Sumw2();
   Name = "BS_SegMinEtaSep"  ; tuple->BS_SegMinEtaSep= dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, -1., 1.); tuple->BS_SegMinEtaSep->Sumw2();
   Name = "BS_SegMinPhiSep"  ; tuple->BS_SegMinPhiSep= dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, -3.3, 3.3); tuple->BS_SegMinPhiSep->Sumw2();
   Name = "BS_SegMinEtaSep_FailDz"  ; tuple->BS_SegMinEtaSep_FailDz= dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, -1., 1.); tuple->BS_SegMinEtaSep_FailDz->Sumw2();
   Name = "BS_SegMinEtaSep_PassDz"  ; tuple->BS_SegMinEtaSep_PassDz= dir.make<TH1F>(Name.c_str(), Name.c_str(),                   50, -1., 1.); tuple->BS_SegMinEtaSep_PassDz->Sumw2();
   Name = "BS_Dz_FailSep"; tuple->BS_Dz_FailSep   = dir.make<TH1F>(Name.c_str(), Name.c_str(), 50,  -150,  150); tuple->BS_Dz_FailSep->Sumw2();

   Name = "BS_Dxy"; tuple->BS_Dxy   = dir.make<TH1F>(Name.c_str(), Name.c_str(), 150,  -IPbound,  IPbound); tuple->BS_Dxy->Sumw2();
   Name = "BS_Dxy_Cosmic"; tuple->BS_Dxy_Cosmic   = dir.make<TH1F>(Name.c_str(), Name.c_str(), 150,  -IPbound,  IPbound); tuple->BS_Dxy_Cosmic->Sumw2();
   Name = "BS_Dz"; tuple->BS_Dz   = dir.make<TH1F>(Name.c_str(), Name.c_str(), 150,  -IPbound,  IPbound); tuple->BS_Dz->Sumw2();
   Name = "BS_Dz_Cosmic"; tuple->BS_Dz_Cosmic   = dir.make<TH1F>(Name.c_str(), Name.c_str(), 150,  -IPbound,  IPbound); tuple->BS_Dz_Cosmic->Sumw2();
   Name = "BS_Dz_CSC"; tuple->BS_Dz_CSC = dir.make<TH1F>(Name.c_str(), Name.c_str(), 150,  -IPbound,  IPbound); tuple->BS_Dz_CSC->Sumw2();
   Name = "BS_Dz_DT"; tuple->BS_Dz_DT=dir.make<TH1F>(Name.c_str(), Name.c_str(), 150,  -IPbound,  IPbound); tuple->BS_Dz_DT->Sumw2();
   Name = "BS_Pt_FailDz"; tuple->BS_Pt_FailDz = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50, 0, PtHistoUpperBound); tuple->BS_Pt_FailDz->Sumw2();
   Name = "BS_Pt_FailDz_DT"; tuple->BS_Pt_FailDz_DT = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50, 0, PtHistoUpperBound); tuple->BS_Pt_FailDz_DT->Sumw2();
   Name = "BS_Pt_FailDz_CSC"; tuple->BS_Pt_FailDz_CSC = dir.make<TH1F>(Name.c_str(), Name.c_str(),  50, 0, PtHistoUpperBound); tuple->BS_Pt_FailDz_CSC->Sumw2();
   Name = "BS_TOF_FailDz"; tuple->BS_TOF_FailDz = dir.make<TH1F>(Name.c_str(), Name.c_str(),  150, -1, 5); tuple->BS_TOF_FailDz->Sumw2();
   Name = "BS_TOF_FailDz_DT"; tuple->BS_TOF_FailDz_DT = dir.make<TH1F>(Name.c_str(), Name.c_str(),  150, -1, 5); tuple->BS_TOF_FailDz_DT->Sumw2();
   Name = "BS_TOF_FailDz_CSC"; tuple->BS_TOF_FailDz_CSC = dir.make<TH1F>(Name.c_str(), Name.c_str(),  150, -1, 5); tuple->BS_TOF_FailDz_CSC->Sumw2();
   Name = "genrecopT"; tuple->genrecopT = dir.make<TH2F>(Name.c_str(), Name.c_str(),            50, 0, PtHistoUpperBound, 50, 0, PtHistoUpperBound);    tuple->genrecopT->Sumw2();

   Name = "genlevelpT";    tuple->genlevelpT = dir.make<TH1F>(Name.c_str(), Name.c_str(), 50, 0, PtHistoUpperBound);    tuple->genlevelpT->Sumw2();
   Name = "genleveleta";   tuple->genleveleta = dir.make<TH1F>(Name.c_str(), Name.c_str(), 60, -3, 3);                  tuple->genleveleta->Sumw2();
   Name = "genlevelbeta";  tuple->genlevelbeta = dir.make<TH1F>(Name.c_str(), Name.c_str(), 20, 0,  1);                 tuple->genlevelbeta->Sumw2();

   //Initialize histograms for number of bins.  For everything but muon only PredBins=0 so no histograms created
   for(int i=0; i<PredBins; i++) {
     char Suffix[1024];
     sprintf(Suffix,"_%i",i);
     Name = "BS_Pt_Binned"; Name.append(Suffix); tuple->BS_Pt_Binned[std::to_string(i)] = dir.make<TH1F>(Name.c_str(), Name.c_str(), 50, 0, PtHistoUpperBound); tuple->BS_Pt_Binned[std::to_string(i)]->Sumw2();
     Name = "BS_TOF_Binned"; Name.append(Suffix); tuple->BS_TOF_Binned[std::to_string(i)] = dir.make<TH1F>(Name.c_str(), Name.c_str() ,150, -1, 5); tuple->BS_TOF_Binned[std::to_string(i)]->Sumw2();
   }

   Name = "AS_Eta_RegionA" ; tuple->AS_Eta_RegionA  = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts,  52,  -2.6,  2.6);           tuple->AS_Eta_RegionA->Sumw2();
   Name = "AS_Eta_RegionB" ; tuple->AS_Eta_RegionB  = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts,  52,  -2.6,  2.6);           tuple->AS_Eta_RegionB->Sumw2();
   Name = "AS_Eta_RegionC" ; tuple->AS_Eta_RegionC  = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts,  52,  -2.6,  2.6);           tuple->AS_Eta_RegionC->Sumw2();
   Name = "AS_Eta_RegionD" ; tuple->AS_Eta_RegionD  = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts,  52,  -2.6,  2.6);           tuple->AS_Eta_RegionD->Sumw2();
   Name = "AS_Eta_RegionE" ; tuple->AS_Eta_RegionE  = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts,  52,  -2.6,  2.6);           tuple->AS_Eta_RegionE->Sumw2();
   Name = "AS_Eta_RegionF" ; tuple->AS_Eta_RegionF  = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts,  52,  -2.6,  2.6);           tuple->AS_Eta_RegionF->Sumw2();
   Name = "AS_Eta_RegionG" ; tuple->AS_Eta_RegionG  = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts,  52,  -2.6,  2.6);           tuple->AS_Eta_RegionG->Sumw2();
   Name = "AS_Eta_RegionH" ; tuple->AS_Eta_RegionH  = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts,  52,  -2.6,  2.6);           tuple->AS_Eta_RegionH->Sumw2();

   Name = "AS_P"    ; tuple->AS_P     = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50, 0, PtHistoUpperBound); tuple->AS_P->Sumw2();
   Name = "AS_Pt"   ; tuple->AS_Pt    = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50, 0, PtHistoUpperBound); tuple->AS_Pt->Sumw2();
   Name = "AS_Is"   ; tuple->AS_Is    = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50, 0, dEdxS_UpLim);       tuple->AS_Is->Sumw2();
   Name = "AS_Im"   ; tuple->AS_Im    = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts,100, 0, dEdxM_UpLim);       tuple->AS_Im->Sumw2();
   Name = "AS_TOF"  ; tuple->AS_TOF   = dir.make<TH2F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50, 1, 5);                 tuple->AS_TOF->Sumw2();


   Name = "BS_EtaIs"; tuple->BS_EtaIs = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50,-3, 3, 50, 0, dEdxS_UpLim);
   Name = "BS_EtaIm"; tuple->BS_EtaIm = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50,-3, 3,100, 0, dEdxM_UpLim);
   Name = "BS_EtaP" ; tuple->BS_EtaP  = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50,-3, 3, 50, 0, PtHistoUpperBound);
   Name = "BS_EtaPt"; tuple->BS_EtaPt = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50,-3, 3, 50, 0, PtHistoUpperBound);
   Name = "BS_EtaTOF" ; tuple->BS_EtaTOF = dir.make<TH2F> (Name.c_str(), Name.c_str(),               50,-3, 3, 50, 0, 3);
   Name = "BS_EtaNBH" ; tuple->BS_EtaNBH = dir.make<TH2F> (Name.c_str(), Name.c_str(),               60,-3, 3, 24, 0,24);
   Name = "BS_EtaDz"; tuple->BS_EtaDz  = dir.make<TH2F>(Name.c_str(), Name.c_str(),                 50,-3, 3, 50, -IPbound, IPbound);
   Name = "BS_PIs"  ; tuple->BS_PIs   = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound, 100, 0, dEdxS_UpLim);
   Name = "BS_PImHD"; tuple->BS_PImHD = dir.make<TH2F>(Name.c_str(), Name.c_str(),                  500, 0, PtHistoUpperBound,1000, 0, dEdxM_UpLim);
   Name = "BS_PIm"  ; tuple->BS_PIm   = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound, 100, 0, dEdxM_UpLim);
   Name = "BS_PtIs" ; tuple->BS_PtIs  = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound,  50, 0, dEdxS_UpLim);
   Name = "BS_PtIm" ; tuple->BS_PtIm  = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound, 100, 0, dEdxM_UpLim);
   Name = "BS_PtTOF" ; tuple->BS_PtTOF= dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50, 0, PtHistoUpperBound,50, 0, 5);
   //   Name = "BS_TOFIs"; tuple->BS_TOFIs = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   100, 1, 5, 100, 0, dEdxS_UpLim);
   Name = "BS_TOFIs"; tuple->BS_TOFIs = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50, 0, 5, 50, 0, dEdxS_UpLim);
   //   Name = "BS_TOFIm"; BS_TOFIm = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   100, 1, 5, 200, 0, dEdxM_UpLim);
   Name = "BS_TOFIm"; tuple->BS_TOFIm = dir.make<TH2F>(Name.c_str(), Name.c_str(),                   50, 0, 5, 100, 0, dEdxM_UpLim);

   //   Name = "AS_EtaIs"; AS_EtaIs = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50,-3, 3, 50, 0, dEdxS_UpLim);
   //   Name = "AS_EtaIm"; AS_EtaIm = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50,-3, 3,100, 0, dEdxM_UpLim);
   //   Name = "AS_EtaP" ; AS_EtaP  = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50,-3, 3, 50, 0, PtHistoUpperBound);
   //   Name = "AS_EtaPt"; AS_EtaPt = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50,-3, 3, 50, 0, PtHistoUpperBound);
   //   Name = "AS_EtaTOF"; AS_EtaTOF = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50,-3, 3, 50, 0, 3);
   Name = "AS_PIs"  ; tuple->AS_PIs   = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50, 0, PtHistoUpperBound, 50, 0, dEdxS_UpLim);
   Name = "AS_PIm"  ; tuple->AS_PIm   = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50, 0, PtHistoUpperBound,100, 0, dEdxM_UpLim);
   Name = "AS_PtIs" ; tuple->AS_PtIs  = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50, 0, PtHistoUpperBound, 50, 0, dEdxS_UpLim);
   Name = "AS_PtIm" ; tuple->AS_PtIm  = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50, 0, PtHistoUpperBound,100, 0, dEdxM_UpLim);
   Name = "AS_TOFIs"; tuple->AS_TOFIs = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50, 0, 5, 50, 0, dEdxS_UpLim);
   Name = "AS_TOFIm"; tuple->AS_TOFIm = dir.make<TH3F>(Name.c_str(), Name.c_str(), NCuts, 0,  NCuts, 50, 0, 5,100, 0, dEdxM_UpLim);

   Name = "H_D_DzSidebands"; tuple->H_D_DzSidebands = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, DzRegions, 0, DzRegions); tuple->H_D_DzSidebands->Sumw2();

   //Background prediction histograms don't need to be made for signal or individual MC samples
   if(!isSignal) {
      Name = "H_A"; tuple->H_A = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_A->Sumw2();
      Name = "H_B"; tuple->H_B = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_B->Sumw2();
      Name = "H_C"; tuple->H_C = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_C->Sumw2();
      Name = "H_D"; tuple->H_D = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_D->Sumw2();
      Name = "H_E"; tuple->H_E = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_E->Sumw2();
      Name = "H_F"; tuple->H_F = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_F->Sumw2();
      Name = "H_G"; tuple->H_G = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_G->Sumw2();
      Name = "H_H"; tuple->H_H = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_H->Sumw2();

      //Initialize histograms for number of bins.  For everything but muon only PredBins=0 so no histograms created
      for(int i=0; i<PredBins; i++) {
         char Suffix[1024];
         sprintf(Suffix,"_%i",i);
         Name = "H_B_Binned"; Name.append(Suffix); tuple->H_B_Binned[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_B_Binned[std::to_string(i)]->Sumw2();
         Name = "H_D_Binned"; Name.append(Suffix); tuple->H_D_Binned[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_D_Binned[std::to_string(i)]->Sumw2();
         Name = "H_F_Binned"; Name.append(Suffix); tuple->H_F_Binned[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_F_Binned[std::to_string(i)]->Sumw2();
         Name = "H_H_Binned"; Name.append(Suffix); tuple->H_H_Binned[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_H_Binned[std::to_string(i)]->Sumw2();
      }

      Name = "Hist_Is"; tuple->Hist_Is = dir.make<TH1D>(Name.c_str(), Name.c_str() ,200,0,dEdxS_UpLim); tuple->Hist_Is->Sumw2();
      Name = "Hist_Pt"; tuple->Hist_Pt = dir.make<TH1D>(Name.c_str(), Name.c_str() ,200,0,PtHistoUpperBound); tuple->Hist_Pt->Sumw2();
      Name = "Hist_TOF"; tuple->Hist_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str() ,200,-10,20); tuple->Hist_TOF->Sumw2();
      //The following are only used to create the predicted mass spectrum.  Memory intensive so don't initialize for analyses not doing mass fits
      if(TypeMode<3) {
         Name = "Pred_I"; tuple->Pred_I = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, 400,0,dEdxM_UpLim); tuple->Pred_I->Sumw2();
         Name = "Pred_EtaB"; tuple->Pred_EtaB = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins,-3,3); tuple->Pred_EtaB->Sumw2();
         Name = "Pred_EtaS"; tuple->Pred_EtaS = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins,-3,3); tuple->Pred_EtaS->Sumw2();
         Name = "Pred_EtaS2"; tuple->Pred_EtaS2 = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins,-3,3); tuple->Pred_EtaS2->Sumw2();
         Name = "Pred_EtaP"; tuple->Pred_EtaP = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, 200,GlobalMinPt,PtHistoUpperBound); tuple->Pred_EtaP->Sumw2();
         Name = "Pred_TOF"; tuple->Pred_TOF = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts,   200,GlobalMinTOF,5); tuple->Pred_TOF->Sumw2();
         //pz

         Name = "PDF_G_EtaP"; tuple->PDF_G_EtaP = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, 200,GlobalMinPt,PtHistoUpperBound); tuple->PDF_G_EtaP->Sumw2();
         Name = "PDF_C_EtaP"; tuple->PDF_C_EtaP = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, 200,GlobalMinPt,PtHistoUpperBound); tuple->PDF_C_EtaP->Sumw2();

         Name = "PDF_A_Eta"; tuple->PDF_A_Eta = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3); tuple->PDF_A_Eta->Sumw2();
         Name = "PDF_E_Eta"; tuple->PDF_E_Eta = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3); tuple->PDF_E_Eta->Sumw2();


         Name = "PDF_B_EtaICK"; tuple->PDF_B_EtaICK = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, 60,-2.,3.); tuple->PDF_B_EtaICK->Sumw2();
         Name = "PDF_F_EtaICK"; tuple->PDF_F_EtaICK = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, 60,-2.,3.); tuple->PDF_F_EtaICK->Sumw2();

         Name = "PDF_H_EtaMass"; tuple->PDF_H_EtaMass = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, MassNBins,0,MassHistoUpperBound); tuple->PDF_H_EtaMass->Sumw2();

         //pz FLIP
         Name = "PDF_G_EtaP_Flip"; tuple->PDF_G_EtaP_Flip = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, 200,GlobalMinPt,PtHistoUpperBound); tuple->PDF_G_EtaP_Flip->Sumw2();
         Name = "PDF_C_EtaP_Flip"; tuple->PDF_C_EtaP_Flip = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, 200,GlobalMinPt,PtHistoUpperBound); tuple->PDF_C_EtaP_Flip->Sumw2();

         Name = "PDF_A_Eta_Flip"; tuple->PDF_A_Eta_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3); tuple->PDF_A_Eta_Flip->Sumw2();
         Name = "PDF_E_Eta_Flip"; tuple->PDF_E_Eta_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3); tuple->PDF_E_Eta_Flip->Sumw2();


         Name = "PDF_B_EtaICK_Flip"; tuple->PDF_B_EtaICK_Flip = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, 60,-2.,3.); tuple->PDF_B_EtaICK_Flip->Sumw2();
         Name = "PDF_F_EtaICK_Flip"; tuple->PDF_F_EtaICK_Flip = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, 60,-2.,3.); tuple->PDF_F_EtaICK_Flip->Sumw2();

         Name = "PDF_H_EtaMass_Flip"; tuple->PDF_H_EtaMass_Flip = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, EtaBins, -3, 3, MassNBins,0,MassHistoUpperBound); tuple->PDF_H_EtaMass_Flip->Sumw2();      
      }

      Name = "RegionD_I"; tuple->RegionD_I = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, 400,0,dEdxM_UpLim); tuple->RegionD_I->Sumw2();
      Name = "RegionD_Ias"; tuple->RegionD_Ias = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, 100, 0, dEdxS_UpLim); tuple->RegionD_Ias->Sumw2();
      Name = "RegionD_P"; tuple->RegionD_P = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, 200,GlobalMinPt,PtHistoUpperBound); tuple->RegionD_P->Sumw2();
      Name = "RegionD_TOF"; tuple->RegionD_TOF = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, 200,GlobalMinTOF,5); tuple->RegionD_TOF->Sumw2();

      Name = "RegionH_Ias"; tuple->RegionH_Ias = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts, 100, 0, dEdxS_UpLim); tuple->RegionH_Ias->Sumw2();

      Name = "H_A_Flip"; tuple->H_A_Flip = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip); tuple->H_A_Flip->Sumw2();
      Name = "H_B_Flip"; tuple->H_B_Flip = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip); tuple->H_B_Flip->Sumw2();
      Name = "H_C_Flip"; tuple->H_C_Flip = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip); tuple->H_C_Flip->Sumw2();
      Name = "H_D_Flip"; tuple->H_D_Flip = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip); tuple->H_D_Flip->Sumw2();
      Name = "H_E_Flip"; tuple->H_E_Flip = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip); tuple->H_E_Flip->Sumw2();
      Name = "H_F_Flip"; tuple->H_F_Flip = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip); tuple->H_F_Flip->Sumw2();
      Name = "H_G_Flip"; tuple->H_G_Flip = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip); tuple->H_G_Flip->Sumw2();
      Name = "H_H_Flip"; tuple->H_H_Flip = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip); tuple->H_H_Flip->Sumw2();

      for(int i=0; i<PredBins; i++) {
         char Suffix[1024];
         sprintf(Suffix,"_%i",i);
         Name = "H_B_Binned_Flip"; Name.append(Suffix); tuple->H_B_Binned_Flip[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_B_Binned_Flip[std::to_string(i)]->Sumw2();
         Name = "H_D_Binned_Flip"; Name.append(Suffix); tuple->H_D_Binned_Flip[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_D_Binned_Flip[std::to_string(i)]->Sumw2();
         Name = "H_F_Binned_Flip"; Name.append(Suffix); tuple->H_F_Binned_Flip[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_F_Binned_Flip[std::to_string(i)]->Sumw2();
         Name = "H_H_Binned_Flip"; Name.append(Suffix); tuple->H_H_Binned_Flip[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,NCuts,0,NCuts); tuple->H_H_Binned_Flip[std::to_string(i)]->Sumw2();
      }

      //The following are only used to create the predicted mass spectrum.  Memory intensive so don't initialize for analyses not doing mass fits
      if(TypeMode<3) {
         Name = "Pred_I_Flip"; tuple->Pred_I_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip, 400,0,dEdxM_UpLim); tuple->Pred_I_Flip->Sumw2();
         Name = "Pred_EtaB_Flip"; tuple->Pred_EtaB_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip, EtaBins,-3,3); tuple->Pred_EtaB_Flip->Sumw2();
         Name = "Pred_EtaS_Flip"; tuple->Pred_EtaS_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip, EtaBins,-3,3); tuple->Pred_EtaS_Flip->Sumw2();
         Name = "Pred_EtaS2_Flip"; tuple->Pred_EtaS2_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip, EtaBins,-3,3); tuple->Pred_EtaS2_Flip->Sumw2();
         Name = "Pred_EtaP_Flip"; tuple->Pred_EtaP_Flip = dir.make<TH3D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip, EtaBins, -3, 3, 200,GlobalMinPt,PtHistoUpperBound); tuple->Pred_EtaP_Flip->Sumw2();
         Name = "Pred_TOF_Flip"; tuple->Pred_TOF_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip,   200,GlobalMinTOF,5); tuple->Pred_TOF_Flip->Sumw2();
      }

      Name = "RegionD_I_Flip"; tuple->RegionD_I_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip, 400,0,dEdxM_UpLim); tuple->RegionD_I_Flip->Sumw2();
      Name = "RegionD_Ias_Flip"; tuple->RegionD_Ias_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip, 100, 0, dEdxS_UpLim); tuple->RegionD_Ias_Flip->Sumw2();
      Name = "RegionD_P_Flip"; tuple->RegionD_P_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip, 200,GlobalMinPt,PtHistoUpperBound); tuple->RegionD_P_Flip->Sumw2();
      Name = "RegionD_TOF_Flip"; tuple->RegionD_TOF_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip, 200,-3,1); tuple->RegionD_TOF_Flip->Sumw2();

      Name = "RegionH_Ias_Flip"; tuple->RegionH_Ias_Flip = dir.make<TH2D>(Name.c_str(), Name.c_str() ,NCuts_Flip,0,NCuts_Flip, 100, 0, dEdxS_UpLim); tuple->RegionH_Ias_Flip->Sumw2();

      Name = "CtrlPt_S1_Is"; tuple->CtrlPt_S1_Is = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,dEdxS_UpLim); tuple->CtrlPt_S1_Is->Sumw2();
      Name = "CtrlPt_S2_Is"; tuple->CtrlPt_S2_Is = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,dEdxS_UpLim); tuple->CtrlPt_S2_Is->Sumw2();
      Name = "CtrlPt_S3_Is"; tuple->CtrlPt_S3_Is = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,dEdxS_UpLim); tuple->CtrlPt_S3_Is->Sumw2();
      Name = "CtrlPt_S4_Is"; tuple->CtrlPt_S4_Is = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,dEdxS_UpLim); tuple->CtrlPt_S4_Is->Sumw2();

      Name = "CtrlPt_S1_Im"; tuple->CtrlPt_S1_Im = dir.make<TH1D>(Name.c_str(), Name.c_str(),400,0,dEdxM_UpLim); tuple->CtrlPt_S1_Im->Sumw2();
      Name = "CtrlPt_S2_Im"; tuple->CtrlPt_S2_Im = dir.make<TH1D>(Name.c_str(), Name.c_str(),400,0,dEdxM_UpLim); tuple->CtrlPt_S2_Im->Sumw2();
      Name = "CtrlPt_S3_Im"; tuple->CtrlPt_S3_Im = dir.make<TH1D>(Name.c_str(), Name.c_str(),400,0,dEdxM_UpLim); tuple->CtrlPt_S3_Im->Sumw2();
      Name = "CtrlPt_S4_Im"; tuple->CtrlPt_S4_Im = dir.make<TH1D>(Name.c_str(), Name.c_str(),400,0,dEdxM_UpLim); tuple->CtrlPt_S4_Im->Sumw2();

      Name = "CtrlIs_S1_TOF"; tuple->CtrlIs_S1_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,5); tuple->CtrlIs_S1_TOF->Sumw2();
      Name = "CtrlIs_S2_TOF"; tuple->CtrlIs_S2_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,5); tuple->CtrlIs_S2_TOF->Sumw2();
      Name = "CtrlIs_S3_TOF"; tuple->CtrlIs_S3_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,5); tuple->CtrlIs_S3_TOF->Sumw2();
      Name = "CtrlIs_S4_TOF"; tuple->CtrlIs_S4_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,5); tuple->CtrlIs_S4_TOF->Sumw2();

      Name = "CtrlIm_S1_TOF"; tuple->CtrlIm_S1_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,5); tuple->CtrlIm_S1_TOF->Sumw2();
      Name = "CtrlIm_S2_TOF"; tuple->CtrlIm_S2_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,5); tuple->CtrlIm_S2_TOF->Sumw2();
      Name = "CtrlIm_S3_TOF"; tuple->CtrlIm_S3_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,5); tuple->CtrlIm_S3_TOF->Sumw2();
      Name = "CtrlIm_S4_TOF"; tuple->CtrlIm_S4_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,0,5); tuple->CtrlIm_S4_TOF->Sumw2();

      Name = "CtrlPt_S1_TOF"; tuple->CtrlPt_S1_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,-2,7); tuple->CtrlPt_S1_TOF->Sumw2();
      Name = "CtrlPt_S2_TOF"; tuple->CtrlPt_S2_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,-2,7); tuple->CtrlPt_S2_TOF->Sumw2();
      Name = "CtrlPt_S3_TOF"; tuple->CtrlPt_S3_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,-2,7); tuple->CtrlPt_S3_TOF->Sumw2();
      Name = "CtrlPt_S4_TOF"; tuple->CtrlPt_S4_TOF = dir.make<TH1D>(Name.c_str(), Name.c_str(),200,-2,7); tuple->CtrlPt_S4_TOF->Sumw2();

      for(int i=0; i<PredBins; i++) {
         char Suffix[1024];
         sprintf(Suffix,"_%i",i);
         Name = "CtrlPt_S1_TOF_Binned"; Name.append(Suffix); tuple->CtrlPt_S1_TOF_Binned[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,200,-2,7); tuple->CtrlPt_S1_TOF_Binned[std::to_string(i)]->Sumw2();
         Name = "CtrlPt_S2_TOF_Binned"; Name.append(Suffix); tuple->CtrlPt_S2_TOF_Binned[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,200,-2,7); tuple->CtrlPt_S2_TOF_Binned[std::to_string(i)]->Sumw2();
         Name = "CtrlPt_S3_TOF_Binned"; Name.append(Suffix); tuple->CtrlPt_S3_TOF_Binned[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,200,-2,7); tuple->CtrlPt_S3_TOF_Binned[std::to_string(i)]->Sumw2();
         Name = "CtrlPt_S4_TOF_Binned"; Name.append(Suffix); tuple->CtrlPt_S4_TOF_Binned[std::to_string(i)] = dir.make<TH1D>(Name.c_str(), Name.c_str() ,200,-2,7); tuple->CtrlPt_S4_TOF_Binned[std::to_string(i)]->Sumw2();
      }
   }

   tuple->Tree = dir.make<TTree>("HscpCandidates", "HscpCandidates");
   ///tuple->Tree->SetDirectory(0);
   tuple->Tree->Branch("Trig"    ,&tuple->Tree_Trig      ,"Trig/i");
   tuple->Tree->Branch("Run"     ,&tuple->Tree_Run       ,"Run/i");
   tuple->Tree->Branch("Event"   ,&tuple->Tree_Event     ,"Event/i");
   tuple->Tree->Branch("Lumi"    ,&tuple->Tree_Lumi      ,"Lumi/i");
   tuple->Tree->Branch("Hscp"    ,&tuple->Tree_Hscp      ,"Hscp/i");
   tuple->Tree->Branch("Charge"  ,&tuple->Tree_Charge    ,"Charge/F");
   tuple->Tree->Branch("Pt"      ,&tuple->Tree_Pt        ,"Pt/F");
   tuple->Tree->Branch("PtErr"   ,&tuple->Tree_PtErr     ,"PtErr/F");
   tuple->Tree->Branch("I"       ,&tuple->Tree_I         ,"I/F");
   tuple->Tree->Branch("Ih"      ,&tuple->Tree_Ih        ,"Ih/F");
   tuple->Tree->Branch("Ick"     ,&tuple->Tree_Ick       ,"Ick/F");
   tuple->Tree->Branch("TOF"     ,&tuple->Tree_TOF       ,"TOF/F");
   tuple->Tree->Branch("Mass"    ,&tuple->Tree_Mass      ,"Mass/F");
   tuple->Tree->Branch("dZ"      ,&tuple->Tree_dZ        ,"dZ/F");
   tuple->Tree->Branch("dXY"     ,&tuple->Tree_dXY       ,"dXY/F");
   tuple->Tree->Branch("dR"      ,&tuple->Tree_dR        ,"dR/F");
   tuple->Tree->Branch("eta"     ,&tuple->Tree_eta       ,"eta/F");
   tuple->Tree->Branch("phi"     ,&tuple->Tree_phi       ,"phi/F");
   tuple->Tree->Branch("NOH"     ,&tuple->Tree_NOH       ,"NOH/i");
   tuple->Tree->Branch("NOPH"    ,&tuple->Tree_NOPH      ,"NOPH/i");
   tuple->Tree->Branch("FOVH"    ,&tuple->Tree_FOVH      ,"FOVH/F");
   tuple->Tree->Branch("NOMH"    ,&tuple->Tree_NOMH      ,"NOMH/i");
   tuple->Tree->Branch("FOVHD"   ,&tuple->Tree_FOVHD     ,"FOVHD/F");
   tuple->Tree->Branch("NOM"     ,&tuple->Tree_NOM       ,"NOM/i");
   tuple->Tree->Branch("Weight"  ,&tuple->Tree_Weight    ,"Weight/F");
   tuple->Tree->Branch("GenId"   ,&tuple->Tree_GenId     ,"GenId/F");
   tuple->Tree->Branch("GenCharge",&tuple->Tree_GenCharge,"GenCharge/F");
   tuple->Tree->Branch("GenMass" ,&tuple->Tree_GenMass   ,"GenMass/F");
   tuple->Tree->Branch("GenPt"   ,&tuple->Tree_GenPt     ,"GenPt/F");
   tuple->Tree->Branch("GenEta"  ,&tuple->Tree_GenEta    ,"GenEta/F");
   tuple->Tree->Branch("GenPhi"  ,&tuple->Tree_GenPhi    ,"GenPhi/F");


   tuple->GenTree = dir.make<TTree>("GenHscpCandidates", "GenHscpCandidates");
   ////tuple->GenTree->SetDirectory(0);
   tuple->GenTree->Branch("Run"     ,&tuple->GenTree_Run       ,"Run/i");
   tuple->GenTree->Branch("Event"   ,&tuple->GenTree_Event     ,"Event/i");
   tuple->GenTree->Branch("Lumi"    ,&tuple->GenTree_Lumi      ,"Lumi/i");
   tuple->GenTree->Branch("Hscp"    ,&tuple->GenTree_Hscp      ,"Hscp/i");
   tuple->GenTree->Branch("Weight"  ,&tuple->GenTree_Weight    ,"Weight/F");
   tuple->GenTree->Branch("GenId"   ,&tuple->GenTree_GenId     ,"GenId/F");
   tuple->GenTree->Branch("GenCharge",&tuple->GenTree_GenCharge,"GenCharge/F");
   tuple->GenTree->Branch("GenMass" ,&tuple->GenTree_GenMass   ,"GenMass/F");
   tuple->GenTree->Branch("GenPt"   ,&tuple->GenTree_GenPt     ,"GenPt/F");
   tuple->GenTree->Branch("GenEta"  ,&tuple->GenTree_GenEta    ,"GenEta/F");
   tuple->GenTree->Branch("GenPhi"  ,&tuple->GenTree_GenPhi    ,"GenPhi/F");
   
}

//=============================================================
//
//     Fill branches of Tree
//
//=============================================================

void TupleSaver::fillTreeBranches(Tuple* &tuple, unsigned int Trig, unsigned int Run, unsigned int Event,unsigned int Lumi, unsigned int Hscp, double Charge, double Pt,double PtErr, double I, double Ih, double Ick, double TOF, double Mass, double dZ, double dXY, double dR, double eta, double phi, unsigned int noh, int noph,double fovh,unsigned int nomh,double fovhd, unsigned int nom, double weight, double genid, double gencharge, double genmass, double genpt, double geneta, double genphi){
   tuple->Tree_Trig   = Trig;
   tuple->Tree_Run   = Run;
   tuple->Tree_Event = Event;
   tuple->Tree_Lumi = Lumi;
   tuple->Tree_Hscp  = Hscp;
   tuple->Tree_Charge = Charge;
   tuple->Tree_Pt    = Pt;
   tuple->Tree_PtErr = PtErr;
   tuple->Tree_I     = I;
   tuple->Tree_Ih    = Ih;
   tuple->Tree_Ick   = Ick;
   tuple->Tree_TOF   = TOF;
   tuple->Tree_Mass  = Mass;
   tuple->Tree_dZ    = dZ;
   tuple->Tree_dXY   = dXY;
   tuple->Tree_dR    = dR;
   tuple->Tree_eta   = eta;
   tuple->Tree_phi   = phi;
   tuple->Tree_NOH   = noh;
   tuple->Tree_NOPH  = noph;
   tuple->Tree_FOVH  = fovh;
   tuple->Tree_NOMH  = nomh;
   tuple->Tree_FOVHD = fovhd;
   tuple->Tree_NOM   = nom;
   tuple->Tree_Weight   = weight;
   tuple->Tree_GenId    = genid;
   tuple->Tree_GenCharge = gencharge;
   tuple->Tree_GenMass  = genmass;
   tuple->Tree_GenPt    = genpt;
   tuple->Tree_GenEta   = geneta;
   tuple->Tree_GenPhi   = genphi;

   // Save in the tree
   //tuple->Tree->Fill();
}

//=============================================================
//
//     Fill of the ABCD related histograms -
//     -> this information will be used later in Step4 for the actual datadriven prediction
//
//=============================================================
void TupleSaver::fillControlAndPredictionHist(const susybsm::HSCParticle& hscp, const reco::DeDxData* dedxSObj, const reco::DeDxData* dedxMObj, const reco::MuonTimeExtra* tof, Tuple* &tuple, int TypeMode, double GlobalMinTOF,float Event_Weight, bool isCosmicSB, float DTRegion, const int MaxPredBins, bool isMCglobal, double DeDxK, double DeDxC, std::vector<double> CutPt, std::vector<double> CutI, std::vector<double> CutTOF, std::vector<double> CutPt_Flip, std::vector<double> CutI_Flip, std::vector<double>CutTOF_Flip){
    using namespace std;
	 reco::TrackRef   track;
         if(TypeMode!=3) track = hscp.trackRef();
         else {
	   reco::MuonRef muon = hscp.muonRef();
           if(muon.isNull()) return;
           track = muon->standAloneMuon();
         }

         double MuonTOF = GlobalMinTOF;
         if(tof){MuonTOF = tof->inverseBeta(); }

	 double Is=0; 	 if(dedxSObj) Is=dedxSObj->dEdx();
	 double Ih=0;	 if(dedxMObj) Ih=dedxMObj->dEdx();

         if(!isCosmicSB){
	 tuple->Hist_Pt->Fill(track->pt(),Event_Weight);
         tuple->Hist_Is->Fill(Is,Event_Weight);
         tuple->Hist_TOF->Fill(MuonTOF,Event_Weight);
         }

//          /\ I
//       /\  |----------------------------
//        |  |   |           |             |
//        |  |   |           |             |
//        |  |   |    B      |     D       |
//        |  |   |           |             |
//        |  ------------------------------
//        |  |   |           |             |
//        |  |   |    A      |     C       |
//        |  |   |           |             |
//        |  |---|-----------|-------------|
//        |  |   |           |             |
//        |  /--------------------------------> PT
//        | /       E       /    G  
//         /------------------------------->
//        /
//      TOF

         //Use different pt regions if using momentum from Stand Alone Muons
	 std::vector<double> PtLimits;
	 if(TypeMode!=3) {
	   PtLimits.push_back(100);
           PtLimits.push_back(80);
           PtLimits.push_back(60);
	 }
	 else {
           PtLimits.push_back(240);
           PtLimits.push_back(170);
           PtLimits.push_back(120);
	 }

	    //Muon only prediction binned depending on where in the detector the track is and how many muon stations it has
	    //Binning not used for other analyses
	    int bin=-1;
	    if(TypeMode==3) {
	      if(fabs(track->eta())<DTRegion) bin=muonStations(track->hitPattern())-2;
	      else bin=muonStations(track->hitPattern())+1;
	    }

         if(!isCosmicSB){
            if(track->pt()>PtLimits[0]){
               tuple->CtrlPt_S4_Is->Fill(Is, Event_Weight);
               tuple->CtrlPt_S4_Im->Fill(Ih, Event_Weight);
               if(tof) tuple->CtrlPt_S4_TOF->Fill(MuonTOF, Event_Weight);
               if(tof && bin>=0 && bin<MaxPredBins)tuple->CtrlPt_S4_TOF_Binned[to_string(bin)]->Fill(MuonTOF, Event_Weight);
            }else if(track->pt()>PtLimits[1]){
               tuple->CtrlPt_S3_Is->Fill(Is, Event_Weight);
               tuple->CtrlPt_S3_Im->Fill(Ih, Event_Weight);
               if(tof) tuple->CtrlPt_S3_TOF->Fill(MuonTOF, Event_Weight);
               if(tof && bin>=0 && bin<MaxPredBins)tuple->CtrlPt_S3_TOF_Binned[to_string(bin)]->Fill(MuonTOF, Event_Weight);
            }else if(track->pt()>PtLimits[2]){
               tuple->CtrlPt_S2_Is->Fill(Is, Event_Weight);
               tuple->CtrlPt_S2_Im->Fill(Ih, Event_Weight);
               if(tof) tuple->CtrlPt_S2_TOF->Fill(MuonTOF, Event_Weight);
               if(tof && bin>=0 && bin<MaxPredBins)tuple->CtrlPt_S2_TOF_Binned[to_string(bin)]->Fill(MuonTOF, Event_Weight);
            }else{
               tuple->CtrlPt_S1_Is->Fill(Is, Event_Weight);
               tuple->CtrlPt_S1_Im->Fill(Ih, Event_Weight);
               if(tof) tuple->CtrlPt_S1_TOF->Fill(MuonTOF, Event_Weight);
               if(tof && bin>=0 && bin<MaxPredBins)tuple->CtrlPt_S1_TOF_Binned[to_string(bin)]->Fill(MuonTOF, Event_Weight);
            }

            if(Is>0.2){           if(tof) tuple->CtrlIs_S4_TOF->Fill(MuonTOF, Event_Weight);
            }else if(Is>0.1){     if(tof) tuple->CtrlIs_S3_TOF->Fill(MuonTOF, Event_Weight);
            }else if(Is>0.05){    if(tof) tuple->CtrlIs_S2_TOF->Fill(MuonTOF, Event_Weight);
            }else{                if(tof) tuple->CtrlIs_S1_TOF->Fill(MuonTOF, Event_Weight);
            }

            if(Ih>4.4){           if(tof) tuple->CtrlIm_S4_TOF->Fill(MuonTOF, Event_Weight);
            }else if(Ih>4.1){     if(tof) tuple->CtrlIm_S3_TOF->Fill(MuonTOF, Event_Weight);
            }else if(Ih>3.8){     if(tof) tuple->CtrlIm_S2_TOF->Fill(MuonTOF, Event_Weight);
            }else{                if(tof) tuple->CtrlIm_S1_TOF->Fill(MuonTOF, Event_Weight);
            }
         }



	 //	 if(dedxMObj) Ih=dedxMObj->dEdx();
	 double Ick=0;  if(dedxMObj) Ick=GetIck(Ih,isMCglobal, DeDxK,DeDxC); //GetIck(double I, bool MC, double dEdxK, double dEdxC)


         for(unsigned int CutIndex=0;CutIndex<CutPt.size();CutIndex++){
 	    if(MuonTOF<GlobalMinTOF) continue;
            if(TypeMode==5 && isCosmicSB)continue;
            bool PassPtCut  = track->pt()>=CutPt[CutIndex];
            bool PassICut   = (Is>=CutI[CutIndex]);
            bool PassTOFCut = MuonTOF>=CutTOF[CutIndex];

            if(       PassTOFCut &&  PassPtCut &&  PassICut){   //Region D
               tuple->H_D      ->Fill(CutIndex,                Event_Weight);
               if(bin>-1 && bin<MaxPredBins) tuple->H_D_Binned[to_string(bin)]->Fill(CutIndex,                Event_Weight);
               tuple->RegionD_P  ->Fill(CutIndex,track->p(),     Event_Weight);
               tuple->RegionD_I  ->Fill(CutIndex,Ih,Event_Weight);
	       tuple->RegionD_Ias->Fill(CutIndex,Is,Event_Weight);
               tuple->RegionD_TOF->Fill(CutIndex,MuonTOF,        Event_Weight);
	       tuple->AS_Eta_RegionD->Fill(CutIndex,track->eta());
            }else if( PassTOFCut &&  PassPtCut && !PassICut){   //Region C
               tuple->H_C     ->Fill(CutIndex,                 Event_Weight);
               if(TypeMode<2)tuple->Pred_EtaP  ->Fill(CutIndex,track->eta(), track->p(),     Event_Weight);
               tuple->PDF_C_EtaP ->Fill(CutIndex,track->eta(), track->p(),     Event_Weight); //pz
               //Pred_TOF->Fill(CutIndex,MuonTOF,         Event_Weight);
               tuple->AS_Eta_RegionC->Fill(CutIndex,track->eta());
            }else if( PassTOFCut && !PassPtCut &&  PassICut){   //Region B
               tuple->H_B     ->Fill(CutIndex,                 Event_Weight);
               if(bin>-1 && bin<MaxPredBins) tuple->H_B_Binned[to_string(bin)]->Fill(CutIndex,                Event_Weight);
               if(TypeMode<2)tuple->Pred_I  ->Fill(CutIndex,Ih, Event_Weight);
               if(TypeMode<2)tuple->Pred_EtaS->Fill(CutIndex,track->eta(),         Event_Weight);
	       tuple->PDF_B_EtaICK ->Fill(CutIndex,track->eta(),Ick, Event_Weight); //pz
               //Pred_TOF->Fill(CutIndex,MuonTOF,         Event_Weight);
               tuple->AS_Eta_RegionB->Fill(CutIndex,track->eta());
            }else if( PassTOFCut && !PassPtCut && !PassICut){   //Region A
               tuple->H_A     ->Fill(CutIndex,                 Event_Weight);
               if(TypeMode==2)tuple->Pred_TOF->Fill(CutIndex,MuonTOF,         Event_Weight);
               if(TypeMode<2)tuple->Pred_EtaB->Fill(CutIndex,track->eta(),         Event_Weight);
               if(TypeMode==2)tuple->Pred_EtaS2->Fill(CutIndex,track->eta(),        Event_Weight);
               tuple->AS_Eta_RegionA->Fill(CutIndex,track->eta());
	       tuple->PDF_A_Eta->Fill(CutIndex,track->eta(),        Event_Weight);//pz

            }else if(!PassTOFCut &&  PassPtCut &&  PassICut){   //Region H
               tuple->H_H   ->Fill(CutIndex,          Event_Weight);
               if(bin>-1 && bin<MaxPredBins) tuple->H_H_Binned[to_string(bin)]->Fill(CutIndex,                Event_Weight);
	       tuple->RegionH_Ias->Fill(CutIndex,Is,Event_Weight);
	       if(TypeMode==2 && Ick>0)tuple->PDF_H_EtaMass ->Fill(CutIndex,track->eta(),track->p()*sqrt(Ick), Event_Weight); //pz
               //Pred_P->Fill(CutIndex,track->p(),        Event_Weight);
               //Pred_I->Fill(CutIndex,Ih,   Event_Weight);
               if(TypeMode==2)tuple->AS_Eta_RegionH->Fill(CutIndex,track->eta());
            }else if(!PassTOFCut &&  PassPtCut && !PassICut){   //Region G
               tuple->H_G     ->Fill(CutIndex,                 Event_Weight);
               if(TypeMode==2)tuple->Pred_EtaP  ->Fill(CutIndex,track->eta(),track->p(),     Event_Weight);
               tuple->AS_Eta_RegionG->Fill(CutIndex,track->eta());
               if(TypeMode==2)tuple->PDF_G_EtaP ->Fill(CutIndex,track->eta(), track->p(),     Event_Weight); //pz
            }else if(!PassTOFCut && !PassPtCut &&  PassICut){   //Region F
               tuple->H_F     ->Fill(CutIndex,                 Event_Weight);
               if(bin>-1 && bin<MaxPredBins) tuple->H_F_Binned[to_string(bin)]->Fill(CutIndex,                Event_Weight);
               if(TypeMode==2)tuple->Pred_I  ->Fill(CutIndex,Ih, Event_Weight);
               if(TypeMode==2)tuple->Pred_EtaS->Fill(CutIndex,track->eta(),         Event_Weight);
               tuple->AS_Eta_RegionF->Fill(CutIndex,track->eta());
	       if(TypeMode==2)tuple->PDF_F_EtaICK ->Fill(CutIndex,track->eta(),Ick, Event_Weight); //pz

            }else if(!PassTOFCut && !PassPtCut && !PassICut){   //Region E
               tuple->H_E     ->Fill(CutIndex,                 Event_Weight);
               if(TypeMode==2)tuple->Pred_EtaB->Fill(CutIndex,track->eta(),         Event_Weight);
               tuple->AS_Eta_RegionE->Fill(CutIndex,track->eta());
	       if(TypeMode==2)tuple->PDF_E_Eta->Fill(CutIndex,track->eta(),        Event_Weight);//pz

            }
         }

	 //Use events with low TOF to check accuracy of background prediction
         for(unsigned int CutIndex=0;CutIndex<CutPt_Flip.size();CutIndex++){
            if(TypeMode!=5 && MuonTOF>=GlobalMinTOF) continue;
            if(TypeMode==5 && !isCosmicSB)continue;

            bool PassPtCut  = track->pt()>=CutPt_Flip[CutIndex];
            bool PassICut   = (Is>=CutI_Flip[CutIndex]);
            bool PassTOFCut = MuonTOF<=CutTOF_Flip[CutIndex]; 


            if(TypeMode==5)PassTOFCut=true;

            if(       PassTOFCut &&  PassPtCut &&  PassICut){   //Region D
	      tuple->RegionD_P_Flip  ->Fill(CutIndex,track->p(),     Event_Weight);
	      tuple->RegionD_I_Flip  ->Fill(CutIndex,Ih,Event_Weight);
	      tuple->RegionD_Ias_Flip  ->Fill(CutIndex,Is,Event_Weight);
	      tuple->RegionD_TOF_Flip->Fill(CutIndex,MuonTOF,        Event_Weight);
               tuple->H_D_Flip->Fill(CutIndex,                Event_Weight);
               if(bin>-1 && bin<MaxPredBins) tuple->H_D_Binned_Flip[to_string(bin)]->Fill(CutIndex,                Event_Weight);
            }else if( PassTOFCut &&  PassPtCut && !PassICut){   //Region C
               tuple->H_C_Flip->Fill(CutIndex,                 Event_Weight);
               if(TypeMode<2)tuple->Pred_EtaP_Flip->Fill(CutIndex,track->eta(), track->p(),     Event_Weight);
               tuple->PDF_C_EtaP_Flip ->Fill(CutIndex,track->eta(), track->p(),     Event_Weight); //pz
               //Pred_TOF_Flip->Fill(CutIndex,MuonTOF,         Event_Weight);
            }else if( PassTOFCut && !PassPtCut &&  PassICut){   //Region B
               tuple->H_B_Flip->Fill(CutIndex,                 Event_Weight);
               if(bin>-1 && bin<MaxPredBins) tuple->H_B_Binned_Flip[to_string(bin)]->Fill(CutIndex,                Event_Weight);
               if(TypeMode<2)tuple->Pred_I_Flip->Fill(CutIndex,Ih, Event_Weight);
               if(TypeMode<2)tuple->Pred_EtaS_Flip->Fill(CutIndex,track->eta(),         Event_Weight);
	       tuple->PDF_B_EtaICK_Flip ->Fill(CutIndex,track->eta(),Ick, Event_Weight); //pz
               //Pred_TOF_Flip->Fill(CutIndex,MuonTOF,         Event_Weight);
            }else if( PassTOFCut && !PassPtCut && !PassICut){   //Region A
               tuple->H_A_Flip->Fill(CutIndex,                 Event_Weight);
               if(TypeMode==2)tuple->Pred_TOF_Flip->Fill(CutIndex,MuonTOF,         Event_Weight);
               if(TypeMode<2)tuple->Pred_EtaB_Flip->Fill(CutIndex,track->eta(),         Event_Weight);
               if(TypeMode==2)tuple->Pred_EtaS2_Flip->Fill(CutIndex,track->eta(),        Event_Weight);
	       tuple->PDF_A_Eta_Flip->Fill(CutIndex,track->eta(),        Event_Weight);//pz
            }else if(!PassTOFCut &&  PassPtCut &&  PassICut){   //Region H
               tuple->H_H_Flip->Fill(CutIndex,          Event_Weight);
               if(bin>-1 && bin<MaxPredBins) tuple->H_H_Binned_Flip[to_string(bin)]->Fill(CutIndex,                Event_Weight);
	       tuple->RegionH_Ias_Flip  ->Fill(CutIndex,Is,Event_Weight);
	       if(TypeMode==2 && Ick>0)tuple->PDF_H_EtaMass_Flip ->Fill(CutIndex,track->eta(),track->p()*sqrt(Ick), Event_Weight); //pz

	       //Pred_P_Flip->Fill(CutIndex,track->p(),        Event_Weight);
	       //Pred_I_Flip->Fill(CutIndex,Ih,   Event_Weight);
            }else if(!PassTOFCut &&  PassPtCut && !PassICut){   //Region G
               tuple->H_G_Flip->Fill(CutIndex,                 Event_Weight);
               if(TypeMode==2)tuple->Pred_EtaP_Flip->Fill(CutIndex,track->eta(),track->p(),     Event_Weight);
               if(TypeMode==2)tuple->PDF_G_EtaP_Flip ->Fill(CutIndex,track->eta(), track->p(),     Event_Weight); //pz

            }else if(!PassTOFCut && !PassPtCut &&  PassICut){   //Region F
               tuple->H_F_Flip->Fill(CutIndex,                 Event_Weight);
               if(bin>-1 && bin<MaxPredBins) tuple->H_F_Binned_Flip[to_string(bin)]->Fill(CutIndex,                Event_Weight);
               if(TypeMode==2)tuple->Pred_I_Flip->Fill(CutIndex,Ih, Event_Weight);
               if(TypeMode==2)tuple->Pred_EtaS_Flip->Fill(CutIndex,track->eta(),         Event_Weight);
	       if(TypeMode==2)tuple->PDF_F_EtaICK_Flip ->Fill(CutIndex,track->eta(),Ick, Event_Weight); //pz
            }else if(!PassTOFCut && !PassPtCut && !PassICut){   //Region E
               tuple->H_E_Flip->Fill(CutIndex,                 Event_Weight);
               if(TypeMode==2)tuple->Pred_EtaB_Flip->Fill(CutIndex,track->eta(),         Event_Weight);
	       if(TypeMode==2)tuple->PDF_E_Eta_Flip->Fill(CutIndex,track->eta(),        Event_Weight);//pz
            }
         }
}
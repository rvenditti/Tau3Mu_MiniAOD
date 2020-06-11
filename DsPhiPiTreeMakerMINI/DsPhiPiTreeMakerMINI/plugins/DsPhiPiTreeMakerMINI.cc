/*
 
 Description: [one line class summary]
 
 Implementation:
 [Notes on implementation]
 */
//
// Original Author:  Federica Simone
//
//


// system include files
#include <memory>
#include <algorithm>
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/EDGetToken.h"

#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include <DataFormats/MuonReco/interface/MuonFwd.h>
#include <DataFormats/MuonReco/interface/Muon.h>
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "TFile.h"
#include "TH1.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TH2.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"
#include "RecoBTag/SecondaryVertex/interface/SecondaryVertex.h"
#include "RecoVertex/AdaptiveVertexFit/interface/AdaptiveVertexFitter.h"


#include "RecoVertex/KinematicFit/interface/KinematicParticleVertexFitter.h"
#include "RecoVertex/KinematicFitPrimitives/interface/KinematicParticleFactoryFromTransientTrack.h"
#include "RecoVertex/KinematicFit/interface/MassKinematicConstraint.h"
#include "RecoVertex/KinematicFit/interface/KinematicParticleFitter.h"
#include "RecoVertex/KinematicFitPrimitives/interface/MultiTrackKinematicConstraint.h"
#include "RecoVertex/KinematicFit/interface/KinematicConstrainedVertexFitter.h"
#include "RecoVertex/KinematicFit/interface/TwoTrackMassKinematicConstraint.h"
#include "RecoVertex/KinematicFitPrimitives/interface/KinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/RefCountedKinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/TransientTrackKinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/KinematicTree.h"


#include "RecoVertex/KinematicFit/interface/KinematicParticleVertexFitter.h"
#include "RecoVertex/KinematicFit/interface/KinematicParticleFitter.h"
#include "RecoVertex/KinematicFit/interface/MassKinematicConstraint.h"
#include "RecoVertex/KinematicFitPrimitives/interface/KinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/RefCountedKinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/TransientTrackKinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/TransientTrackKinematicParticle.h"
#include "RecoVertex/KinematicFitPrimitives/interface/KinematicParticleFactoryFromTransientTrack.h"
#include "RecoVertex/AdaptiveVertexFit/interface/AdaptiveVertexFitter.h"


#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"

#include "TrackingTools/TransientTrack/interface/TransientTrackFromFTSFactory.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/PatternTools/interface/ClosestApproachInRPhi.h"

#include "DataFormats/Candidate/interface/VertexCompositeCandidateFwd.h"
#include "DataFormats/Candidate/interface/CompositeCandidate.h"

#include "RecoVertex/VertexPrimitives/interface/ConvertToFromReco.h"
#include "DataFormats/TrackReco/interface/TrackBase.h"
#include "RecoVertex/VertexTools/interface/VertexDistance3D.h"
#include "SimDataFormats/Vertex/interface/SimVertex.h"
#include "SimDataFormats/Vertex/interface/SimVertexContainer.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Common/interface/TriggerResultsByName.h"

#include "PhysicsTools/PatUtils/interface/TriggerHelper.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/PatCandidates/interface/TriggerFilter.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "DataFormats/Candidate/interface/OverlapChecker.h"
#include "TrackingTools/IPTools/interface/IPTools.h"

#include "CondFormats/L1TObjects/interface/L1GtTriggerMenu.h"
#include "CondFormats/DataRecord/interface/L1GtTriggerMenuRcd.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/L1TGlobal/interface/GlobalAlgBlk.h"
#include "L1Trigger/L1TGlobal/interface/L1TGlobalUtil.h"
#include "CondFormats/DataRecord/interface/L1TUtmTriggerMenuRcd.h"
#include "CondFormats/L1TObjects/interface/L1TUtmTriggerMenu.h"
#include "CondFormats/DataRecord/interface/L1TGlobalPrescalesVetosRcd.h"
#include "CondFormats/L1TObjects/interface/L1TGlobalPrescalesVetos.h"
OverlapChecker overlap;

////
class DsPhiPiTreeMakerMINI : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
public:
    explicit DsPhiPiTreeMakerMINI(const edm::ParameterSet&);
    ~DsPhiPiTreeMakerMINI();
    static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
    float dR(float eta1, float eta2, float phi1, float phi2);
    float dRtriggerMatch(pat::Muon m, std::vector<pat::TriggerObjectStandAlone> triggerObjects);
    float dRtriggerMatchTrk(reco::Track Trk, std::vector<pat::TriggerObjectStandAlone> triggerObjects);
    void beginRun(edm::Run const &, edm::EventSetup const&, edm::Event const&);
    
    
private:
    virtual void beginJob() override;
    virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
    // virtual void beginRun(edm::Run const &, edm::EventSetup const&) override;
    virtual void endJob() override;
    edm::EDGetTokenT<edm::View<pat::Muon> > muons_;
    edm::EDGetTokenT<edm::View<reco::Vertex> > vertex_;
    edm::EDGetTokenT<edm::View<reco::Track> > trackToken_;
    //edm::EDGetTokenT<edm::View<reco::CompositeCandidate> > Cand3Mu_;
    edm::EDGetTokenT<edm::View<reco::CompositeCandidate> > Cand2Mu1Track_;
    edm::EDGetTokenT<edm::View<reco::CompositeCandidate> > DiMuon_;
    edm::EDGetTokenT<edm::View<reco::GenParticle> > genParticles_;
    edm::EDGetTokenT<std::vector<PileupSummaryInfo> > puToken_ ;
    edm::EDGetTokenT<edm::TriggerResults> triggerToken_;
  //edm::EDGetTokenT<trigger::TriggerEvent> trigeventToken_;
    edm::EDGetToken algToken_;
    edm::EDGetTokenT<std::vector<pat::PackedCandidate> >srcCands_;
    edm::EDGetTokenT<std::vector<pat::TriggerObjectStandAlone> > triggerObjects_;
    bool is3Mu;
    bool isMc;
    bool isAna;
    bool is2016;
    bool is2017;
    bool is2018;
    bool isBParking;
    //  edm::EDGetTokenT<edm::TriggerResults> trigResultsToken;
    //  edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> trigObjCollToken;
    const TransientTrackBuilder* theTransientTrackBuilder_;
    HLTConfigProvider hltConfig;
    //  TPMERegexp* _re;
    
    edm::Service<TFileService> fs;
    l1t::L1TGlobalUtil* gtUtil_; 
    TH1F *hEvents;
    TH1F *hEventsAfterGoodCand;
    
    /*
     TH1F *hEvents_3Mu, *hEvents_MuFilter, *hEvents_DiMuonDz, * hEvent_TauCharge,  * hEvent_3MuonVtx, *  hEvent_3MuonMass, *hEvent_Valid3MuonVtx;
     
     TH1F *hGenMuonPt;  TH1F *hGenMuonEta;
     TH1F *hMuonPt;TH1F *hMuonP; TH1F *hMuonEta, *hGlobalMuonEta, *hTrackerMuonEta, *hLooseMuonEta, *hSoftMuonEta;
     TH1F *  hGlobalMuonPt,  *  hSoftMuonPt,  *  hLooseMuonPt, *  hTrackerMuonPt;
     TH1F *hMuonNumberOfValidHits;
     TH1F * hMuonDB;   TH1F * hMuonTime;   TH1F * hMuonTimeErr;
     TH1F  *hGenTauPt, *hDiMuonDz, *hDiMuonDR, *hGoodMuSize, *hMuonSize_GoodDiMu;
     TH1F  *hThreeMuonInvMass, *hThreeMuonCharge, * hVtxSize, * hTau_vFit_chi2 ,  *h3MuonMassVtxFit  ;
     TH2F * hMuonTimeVsP;
     */
    //tree
    TTree*      tree_;
    std::vector<float>  MuonPt, MuonEta, MuonPhi, MuonChi2P, MuonChi2LocalPosition, MuonGlbTrackProbability, MuonTrkRelChi2, MuonTrkKink;
    std::vector<double> MuonEnergy,  MuonCharge;
    
    std::vector<int> GenParticle_PdgId, GenParticle_MotherPdgId, GenParticle_isDs, GenParticle_isB, GenParticle_isBdecay;
    std::vector<double> GenParticle_Pt, GenParticle_Eta, GenParticle_Phi;
    
    //Vtx position
    std::vector<double>  Muon_vx,  Muon_vy,  Muon_vz;
    
    //MuonID
    std::vector<double>  Muon_isGlobal,  Muon_isTracker,  Muon_isSoft,  Muon_isLoose,  Muon_isPF,  Muon_isRPCMuon,  Muon_isStandAloneMuon,  Muon_isTrackerMuon,  Muon_isCaloMuon,  Muon_isQualityValid,  Muon_isTimeValid,  Muon_isIsolationValid,  Muon_numberOfMatchedStations,  Muon_numberOfMatches;
    
    //MuonTime
    std::vector<double>  Muon_timeAtIpInOut,Muon_timeAtIpInOutErr;
    
    //Muon inner + outer track
    std::vector<double>  Muon_GLnormChi2, Muon_GLhitPattern_numberOfValidMuonHits,  Muon_trackerLayersWithMeasurement,  Muon_Numberofvalidpixelhits,  Muon_outerTrack_p,  Muon_outerTrack_eta,
    Muon_outerTrack_phi,  Muon_outerTrack_normalizedChi2,  Muon_outerTrack_muonStationsWithValidHits,  Muon_innerTrack_p,  Muon_innerTrack_eta,  Muon_innerTrack_phi,  Muon_innerTrack_normalizedChi2,  Muon_QInnerOuter;
    
    std::vector<double>   Muon_combinedQuality_updatedSta,  Muon_combinedQuality_trkKink,  Muon_combinedQuality_glbKink,  Muon_combinedQuality_trkRelChi2,  Muon_combinedQuality_staRelChi2,  Muon_combinedQuality_chi2LocalPosition,  Muon_combinedQuality_chi2LocalMomentum,  Muon_combinedQuality_localDistance,  Muon_combinedQuality_globalDeltaEtaPhi,  Muon_combinedQuality_tightMatch,  Muon_combinedQuality_glbTrackProbability,  Muon_calEnergy_em,  Muon_calEnergy_emS9,  Muon_calEnergy_emS25,  Muon_calEnergy_had,  Muon_calEnergy_hadS9,  Muon_segmentCompatibility,  Muon_caloCompatibility,  Muon_ptErrOverPt;
    std::vector<int>  Muon_PdgId, Muon_MotherPdgId, Muon_simFlavour;

    std::vector<double> Track_pt, Track_eta, Track_phi, Track_charge, Track_normalizedChi2, Track_numberOfValidHits, Track_dxy, Track_dxyError, Track_dz, Track_dzError, Track_vx, Track_vy, Track_vz;

    std::vector<double>  Mu1_Pt,  Mu1_Eta,  Mu1_Phi,  Mu2_Pt,  Mu2_Eta,  Mu2_Phi,  Mu3_Pt,  Mu3_Eta,  Mu3_Phi, GenMatchMu1_SimPt, GenMatchMu2_SimPt, GenMatchMu3_SimPt,GenMatchMu1_SimEta, GenMatchMu2_SimEta, GenMatchMu3_SimEta, GenMatchMu1_SimPhi, GenMatchMu2_SimPhi, GenMatchMu3_SimPhi,  GenMatchMu1_Pt,  GenMatchMu2_Pt,  GenMatchMu3_Pt,  GenMatchMu1_Eta,  GenMatchMu2_Eta,  GenMatchMu3_Eta,  GenMatchMu1_Phi,  GenMatchMu2_Phi,  GenMatchMu3_Phi;
    
    std::vector<double>  Mu01_Pt,  Mu01_Eta,  Mu01_Phi,  Mu02_Pt,  Mu02_Eta,  Mu02_Phi, GenMatchMu01_SimPt, GenMatchMu02_SimPt, GenMatchMu01_SimEta, GenMatchMu02_SimEta, GenMatchMu01_SimPhi, GenMatchMu02_SimPhi, GenMatchMu01_Pt, GenMatchMu02_Pt, GenMatchMu01_Eta,  GenMatchMu02_Eta, GenMatchMu01_Phi,  GenMatchMu02_Phi,  GenMatchMu03_Phi;

    std::vector<float> Mu01_dRtriggerMatch, Mu02_dRtriggerMatch, Tr_dRtriggerMatch;
  std::vector<float> Mu1_dRtriggerMatch_Mu7, Mu2_dRtriggerMatch_Mu7, Mu3_dRtriggerMatch_Mu7;
  std::vector<float> Mu1_dRtriggerMatch_Mu8, Mu2_dRtriggerMatch_Mu8, Mu3_dRtriggerMatch_Mu8;
  std::vector<float> Mu1_dRtriggerMatch_Mu8_IP5, Mu1_dRtriggerMatch_Mu8_IP6, Mu1_dRtriggerMatch_Mu9_IP0, Mu1_dRtriggerMatch_Mu9_IP3, Mu1_dRtriggerMatch_Mu9_IP4, Mu1_dRtriggerMatch_Mu9_IP5, Mu1_dRtriggerMatch_Mu12_IP6, Mu1_dRtriggerMatch_Mu9_IP6;



    std::vector<double>  Tr_Pt, Tr_Phi, Tr_Eta;

    std::vector<double>     Muon_emEt03, Muon_hadEt03, Muon_nJets03, Muon_nTracks03, Muon_sumPt03, Muon_emEt05,    Muon_hadEt05, Muon_nJets05, Muon_nTracks05, Muon_sumPt05,
    Muon_hadVetoEt03,Muon_emVetoEt03,    Muon_trackerVetoPt03,    Muon_hadVetoEt05,    Muon_emVetoEt05,    Muon_trackerVetoPt05;
    //  Mu1_SimPt,  Mu1_SimEta,  Mu1_SimPhi,  Mu2_SimPt,  Mu2_SimEta,  Mu2_SimPhi, Mu3_SimPt,  Mu3_SimEta,  Mu3_SimPhi,
    
    //std::vector<int>  Mu1_TripletIndex,  Mu2_TripletIndex,  Mu3_TripletIndex;
    std::vector<int>  Mu01_TripletIndex,  Mu02_TripletIndex, Tr_TripletIndex, selectedTripletsIndex;
    std::vector<double>     Triplet_mindca_iso, Triplet_relativeiso;
 
    int TripletCollectionSize, TripletCollectionSize2, PVCollection_Size, MuonCollectionSize, SelectedTripletsSize;
    std::vector<double>  TripletVtx_x,  TripletVtx_y,  TripletVtx_z,  TripletVtx_Chi2,  TripletVtx_NDOF,  Triplet_Mass,  Triplet_Pt,  Triplet_Eta,  Triplet_Phi, Triplet_Charge;
    std::vector<double>  TripletVtx2_x,  TripletVtx2_y,  TripletVtx2_z,  TripletVtx2_Chi2,  TripletVtx2_NDOF,  Triplet2_Mass,  Triplet2_Pt,  Triplet2_Eta,  Triplet2_Phi, Triplet2_Charge;
    
    std::vector<double>  dxy_mu1,  dxy_mu2,  dxy_mu3,  dxyErr_mu1,  dxyErr_mu2,  dxyErr_mu3;
    
    std::vector<double>  RefittedPV_x, RefittedPV2_x;
    std::vector<double>  RefittedPV_y, RefittedPV2_y;
    std::vector<double>  RefittedPV_z, RefittedPV2_z;
    std::vector<double>  RefittedPV_NTracks, RefittedPV2_NTracks;
    std::vector<int>     RefittedPV_isValid, RefittedPV2_isValid;
    
    //RefittedPV_Chi2.push_back(PVertex.);
    
    std::vector<double>  FlightDistPVSV, FlightDistPVSV2;
    std::vector<double>  FlightDistPVSV_Err, FlightDistPVSV2_Err;
    std::vector<double>  FlightDistPVSV_Significance, FlightDistPVSV2_Significance;
    std::vector<double>  FlightDistPVSV_chi2, FlightDistPVSV2_chi2;
    
    std::vector<double> PV_x,  PV_y,  PV_z,  PV_NTracks;
    
    uint  evt, run, lumi, puN;
    std::vector<string>  Trigger_l1name;
    std::vector<int> Trigger_l1decision;
    std::vector<int> Trigger_l1prescale;
	
    std::vector<string>  Trigger_hltname;
    std::vector<int> Trigger_hltdecision;
    std::vector<int> NGoodTriplets;
  
  std::vector<double> MuonPt_HLT2017, MuonEta_HLT2017, MuonPhi_HLT2017, MuonPt_HLT_BPMu7, MuonEta_HLT_BPMu7, MuonPhi_HLT_BPMu7, MuonPt_HLT_BPMu8, MuonEta_HLT_BPMu8, MuonPhi_HLT_BPMu8, MuonPt_HLT_BPMu8_IP6,  MuonEta_HLT_BPMu8_IP6, MuonPhi_HLT_BPMu8_IP6, MuonPt_HLT_BPMu8_IP5, MuonEta_HLT_BPMu8_IP5, MuonPhi_HLT_BPMu8_IP5,   MuonPt_HLT_BPMu9_IP0, MuonEta_HLT_BPMu9_IP0, MuonPhi_HLT_BPMu9_IP0, MuonPt_HLT_BPMu3_IP3, MuonEta_HLT_BPMu3_IP3, MuonPhi_HLT_BPMu3_IP3, MuonPt_HLT_BPMu3_IP4,MuonEta_HLT_BPMu3_IP4,MuonPhi_HLT_BPMu3_IP4,MuonPt_HLT_BPMu3_IP5, MuonEta_HLT_BPMu3_IP5,MuonPhi_HLT_BPMu3_IP5,MuonPt_HLT_BPMu3_IP6,MuonEta_HLT_BPMu3_IP6,MuonPhi_HLT_BPMu3_IP6,MuonPt_HLT_BPMu12_IP6,MuonEta_HLT_BPMu12_IP6,MuonPhi_HLT_BPMu12_IP6;
  std::vector<double> MuonPt_HLT,  MuonEta_HLT,  MuonPhi_HLT;
  std::vector<double> Mu1_dRtriggerMatch_2017, Mu2_dRtriggerMatch_2017, Mu3_dRtriggerMatch_2017;
  std::vector<double>  Mu1_dRtriggerMatch,  Mu2_dRtriggerMatch,  Mu3_dRtriggerMatch;

  std::vector<double>  Triplet_IsoMu3, Triplet_IsoMu2, Triplet_IsoMu1;
  std::vector<double>  Mu1_NTracks03iso, Mu2_NTracks03iso, Mu3_NTracks03iso, Triplet_relativeiso2;

  std::vector<double> Muon_SoftMVA_Val,Muon_validMuonHitComb;
  std::vector<double>Muon_innerTrack_ValidFraction,Muon_innerTrack_highPurity,Muon_Numberofvalidtrackerhits;
  std::vector<int>  Track_pdgId;
    //SyncTree
    /*  TTree*      SyncTree_;
     std::vector<float>  allmuons_pt, leadmuon_pt, leadmuon_phi, leadmuon_eta;
     std::vector<float>  alltracks_pt, leadtrack_pt,  leadtrack_eta,  leadtrack_phi;
     uint nprimevtxs, nmuons, evt, run, lumi;
     */
    };
    
    
    
    DsPhiPiTreeMakerMINI::DsPhiPiTreeMakerMINI(const edm::ParameterSet& iConfig){
        edm::InputTag algInputTag_;
	isMc = iConfig.getUntrackedParameter<bool>("isMcLabel");
        isAna = iConfig.getUntrackedParameter<bool>("isAnaLabel");
        is2016 = iConfig.getUntrackedParameter<bool>("is2016Label");
        is2017= iConfig.getUntrackedParameter<bool>("is2017Label");
        is2018= iConfig.getUntrackedParameter<bool>("is2018Label");
        isMc = iConfig.getUntrackedParameter<bool>("isMcLabel");
        //is3Mu = iConfig.getUntrackedParameter<bool>("is3MuLabel");
        muons_ = consumes<edm::View<pat::Muon> >  (iConfig.getParameter<edm::InputTag>("muonLabel"));
        vertex_ = consumes<edm::View<reco::Vertex> > (iConfig.getParameter<edm::InputTag>("VertexLabel"));
        trackToken_ = consumes<edm::View<reco::Track> > (iConfig.getParameter<edm::InputTag>("TracksLabel"));
        genParticles_ = consumes<edm::View<reco::GenParticle>  > (iConfig.getParameter<edm::InputTag>("genParticleLabel"));
	srcCands_ = consumes<std::vector<pat::PackedCandidate> >(edm::InputTag("packedPFCandidates"));
        //Cand3Mu_ = consumes<edm::View<reco::CompositeCandidate> > (iConfig.getParameter<edm::InputTag>("Cand3MuLabel"));
        Cand2Mu1Track_ = consumes<edm::View<reco::CompositeCandidate> > (iConfig.getParameter<edm::InputTag>("Cand2Mu1TrackLabel"));
	DiMuon_ = consumes<edm::View<reco::CompositeCandidate> > (iConfig.getParameter<edm::InputTag>("DiMuonLabel"));
        puToken_ =   consumes<std::vector<PileupSummaryInfo> >(iConfig.getParameter<edm::InputTag>("pileupSummary"));
	triggerToken_ = consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("triggerResults"));
	//trigeventToken_ = consumes<trigger::TriggerEvent>(iConfig.getParameter<edm::InputTag>("triggerSummary"));
	algToken_ = consumes<BXVector<GlobalAlgBlk>>(iConfig.getParameter<edm::InputTag>("AlgInputTag"));
	gtUtil_ = new l1t::L1TGlobalUtil(iConfig, consumesCollector(), *this, algInputTag_, algInputTag_);
	triggerObjects_ = consumes<std::vector<pat::TriggerObjectStandAlone> >(iConfig.getParameter<edm::InputTag>("objects"));
        //tauToken_(consumes(iConfig.getParameter("taus"))),
        //metToken_(consumes(iConfig.getParameter("mets")))
        //tree_(0);
        //MuonPt(0);
    }
    DsPhiPiTreeMakerMINI::~DsPhiPiTreeMakerMINI()
    {
        
        // do anything here that needs to be done at desctruction time
        // (e.g. close files, deallocate resources etc.)
    }
    
    
    float DsPhiPiTreeMakerMINI::dR(float eta1, float eta2, float phi1, float phi2){
        float dphi=(phi1-phi2);
        float deta=(eta1-eta2);
        float deltaR= TMath::Sqrt(dphi*dphi + deta*deta);
        return deltaR;
    }

float DsPhiPiTreeMakerMINI::dRtriggerMatch(pat::Muon m, vector<pat::TriggerObjectStandAlone> triggerObjects) {
        float dRmin = 1.;
        for (unsigned int i = 0 ; i < triggerObjects.size() ; i++) {
            float deltaR = sqrt( reco::deltaR2(triggerObjects[i].eta(), triggerObjects[i].phi(), m.eta(), m.phi()));
            //float deltaR = sqrt( pow(triggerObjects[i].eta() - m.eta(), 2) + pow(acos(cos(triggerObjects[i].phi() - m.phi())), 2));
            if (deltaR < dRmin) dRmin = deltaR;
        }
        return dRmin;
    }
    
float DsPhiPiTreeMakerMINI::dRtriggerMatchTrk(reco::Track Trk, vector<pat::TriggerObjectStandAlone> triggerObjects) {
        float dRmin = 1.;
        for (unsigned int i = 0 ; i < triggerObjects.size() ; i++) {
            float deltaR = sqrt( reco::deltaR2(triggerObjects[i].eta(), triggerObjects[i].phi(), Trk.eta(), Trk.phi()));
            //float deltaR = sqrt( pow(triggerObjects[i].eta() - m.eta(), 2) + pow(acos(cos(triggerObjects[i].phi() - m.phi())), 2));
            if (deltaR < dRmin) dRmin = deltaR;
        }
        return dRmin;
    }
    
    bool isGoodTrack(const reco::Track &track) {
        if(track.pt()>1){
            if(std::fabs(track.eta())<2.4){
                if(track.hitPattern().trackerLayersWithMeasurement()>5){
                    if(track.hitPattern().pixelLayersWithMeasurement()>1) return true;
                }
            }
        }
        return false;
    }
    
    typedef std::map<const reco::Track*, reco::TransientTrack> TransientTrackMap;
    // auxiliary function to exclude tracks associated to tau lepton decay "leg"
    // from primary event vertex refit
    bool tracksMatchByDeltaR(const reco::Track* trk1, const reco::Track* trk2)
    {
        if ( reco::deltaR(*trk1, *trk2) < 1.e-2 && trk1->charge() == trk2->charge() ) return true;
        else return false;
    }
    
    void removeTracks(TransientTrackMap& pvTracks_toRefit, const std::vector<reco::Track*> svTracks)
    {
        for ( std::vector<reco::Track*>::const_iterator svTrack = svTracks.begin(); svTrack != svTracks.end(); ++svTrack ){
            //--- remove track from list of tracks included in primary event vertex refit
            //    if track matches by reference or in eta-phi
            //    any of the tracks associated to tau lepton decay "leg"
            for ( TransientTrackMap::iterator pvTrack = pvTracks_toRefit.begin(); pvTrack != pvTracks_toRefit.end(); ++pvTrack ) {
                if ( tracksMatchByDeltaR(pvTrack->first, *svTrack) ) {
                    pvTracks_toRefit.erase(pvTrack);
                    break;
                }
            }
        }
    }
    
bool tracksMatchByDeltaR2(const reco::TransientTrack trk1, const reco::Track* trk2)
{
  //cout<<" pv_t eta="<<trk1.track().eta()<<" sv_t eta="<<trk2->eta()<<" deltaR(tk1, tk2)="<<reco::deltaR(trk1.track(), *trk2)<<endl;                 
  if ( reco::deltaR(trk1.track(), *trk2) < 1.e-2 && trk1.track().charge() == trk2->charge() ) return true;
  else return false;
}


    
void removeTracks3(vector<reco::TransientTrack> pvTracks, const std::vector<reco::Track*> svTracks)
{
  // cout<<"Inside Remove Tracks: pvtracks="<<pvTracks.size()<<endl;                                                                                  
  for ( std::vector<reco::Track*>::const_iterator svTrack = svTracks.begin(); svTrack != svTracks.end(); ++svTrack ){
    for(uint f=0;f<pvTracks.size(); f++){
      if ( tracksMatchByDeltaR2(pvTracks.at(f), *svTrack) ) {
	//      cout<<" track to be erased position: "<<f<<" eta="<<pvTracks.at(f).track().eta()<<endl;                                               
        pvTracks.erase(pvTracks.begin()+f);
        break;
      }
    }
  }
}
    
    void DsPhiPiTreeMakerMINI::beginRun(edm::Run const& iRun, edm::EventSetup const& iSetup, const edm::Event& iEvent) {
        //edm::Handle<edm::TriggerResults> trigResults; //our trigger result object
        //edm::InputTag trigResultsTag("TriggerResults"," ","HLT"); //make sure have correct process on MC
        //iEvent.getByLabel(trigResultsTag,trigResults);
        /*
        bool changed = true;
        if (hltConfig.init(iRun, iSetup, trigResultsTag.process(), changed)) {
            // if init returns TRUE, initialisation has succeeded!
            std::cout << "HLT config with process name "<< trigResultsTag.process() << " successfully extracted"<<std::endl;
        }
        else {
            // if init returns FALSE, initialisation has NOT succeeded, which indicates a problem
            // with the file and/or code and needs to be investigated!
            std::cout << "Error! HLT config extraction with process name " << trigResultsTag.process() << " failed"<<std::endl;
            // In this case, all access methods will return empty values!
        }
       */ 
    }
    
    
    
    void
    DsPhiPiTreeMakerMINI::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
    {
        using namespace edm;
        using namespace std;
        using namespace reco;
        using std::vector;
        
        
        
        edm::Handle< edm::View<reco::Vertex> >vertices;
        iEvent.getByToken(vertex_, vertices);
        if (vertices->empty()) return; // skip the event if no PV found
        const reco::Vertex &PV = vertices->front();
        
        edm::Handle< edm::View<pat::Muon> > muons;
        iEvent.getByToken(muons_, muons);
        
       /* edm::Handle<edm::View<reco::CompositeCandidate> > Cand3Mu;
        iEvent.getByToken(Cand3Mu_, Cand3Mu);
        */
        edm::Handle<edm::View<reco::CompositeCandidate> > Cand2Mu1Track;
        iEvent.getByToken(Cand2Mu1Track_, Cand2Mu1Track);

	edm::Handle<edm::View<reco::CompositeCandidate> > DiMuon;
        iEvent.getByToken(DiMuon_, DiMuon);        


        edm::Handle< edm::View<reco::GenParticle> > genParticles;
        iEvent.getByToken(genParticles_, genParticles);
        
        edm::Handle<edm::View<reco::Track> > trackCollection;
        iEvent.getByToken(trackToken_, trackCollection);
        
       	Handle<TriggerResults> triggerResults;
	iEvent.getByToken(triggerToken_, triggerResults);
	
	//		Handle<trigger::TriggerEvent> triggerSummary;
	//	iEvent.getByToken(trigeventToken_, triggerSummary);

	Handle<std::vector<pat::TriggerObjectStandAlone> > triggerObjects;
        iEvent.getByToken(triggerObjects_, triggerObjects);
	
	edm::Handle<std::vector<pat::PackedCandidate> > PFCands;
        iEvent.getByToken(srcCands_,PFCands);

	Handle<BXVector<GlobalAlgBlk>> alg;
	iEvent.getByToken(algToken_,alg); 
        
        edm::ESHandle<TransientTrackBuilder> theTransientTrackBuilder;
        iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder",theTransientTrackBuilder);
        theTransientTrackBuilder_ = theTransientTrackBuilder.product();
        
        hEvents->Fill(1);

	///////////////Fill Trigger Vars, L1 and HLT///////////////
	gtUtil_->retrieveL1(iEvent, iSetup, algToken_);
	const vector<pair<string, bool> > initialDecisions = gtUtil_->decisionsInitial();
	
	if (!iEvent.isRealData())
	   {
	   for (size_t i_l1t = 0; i_l1t < initialDecisions.size(); i_l1t++) 
	      {
	      string l1tName = (initialDecisions.at(i_l1t)).first;
	      if(l1tName.find("DoubleMu") != string::npos || l1tName.find("TripleMu") != string::npos ||  l1tName.find("SingleMu")!= string::npos){
	         Trigger_l1name.push_back( l1tName );
		 Trigger_l1decision.push_back( initialDecisions.at(i_l1t).second );
		 Trigger_l1prescale.push_back( 1 );
	         }
	      }
           }
	else
	   {
	   ESHandle<L1TGlobalPrescalesVetos> psAndVetos;
	   auto psRcd = iSetup.tryToGet<L1TGlobalPrescalesVetosRcd>();
	   if(psRcd) psRcd->get(psAndVetos);
	   int columnN= gtUtil_->prescaleColumn();
	   for (size_t i_l1t = 0; i_l1t < initialDecisions.size(); i_l1t++) {
	      string l1tName = (initialDecisions.at(i_l1t)).first;
	      if(l1tName.find("DoubleMu") != string::npos || l1tName.find("TripleMu") != string::npos ||  l1tName.find("SingleMu")!= string::npos){
	   //    cout<<"L1Seed="<<l1tName<<" decision="<<initialDecisions.at(i_l1t).second<<" prescale="<<(psAndVetos->prescale_table_)[columnN][i_l1t]<<endl;
	         Trigger_l1name.push_back( l1tName );
		 Trigger_l1decision.push_back( initialDecisions.at(i_l1t).second );
		 Trigger_l1prescale.push_back( (psAndVetos->prescale_table_)[columnN][i_l1t]);
		 }
	      }
	   } 
	 const TriggerNames &triggerNames = iEvent.triggerNames( *triggerResults );
	 for (size_t i_hlt = 0; i_hlt != triggerResults->size(); ++i_hlt){
	    string hltName = triggerNames.triggerName(i_hlt);
	    if(hltName.find("HLT_DoubleMu") != string::npos || hltName.find("HLT_Mu8_IP") != string::npos || hltName.find("HLT_Mu7_IP") != string::npos || (hltName.find("HLT_Mu9_IP") != string::npos) || (hltName.find("HLT_Mu12_IP") != string::npos)){
	      //cout<<" HLTPath="<<hltName<<" isPassed="<<triggerResults->accept(i_hlt )<<endl;
	       Trigger_hltname.push_back(hltName);
	       Trigger_hltdecision.push_back(triggerResults->accept(i_hlt ));
	    }
          }


	 vector<pat::TriggerObjectStandAlone> TriggerObj_DsTau3Mu,  TriggerObj_DsTau3Mu2017;
	 vector<pat::TriggerObjectStandAlone> MuonsObjects_BPMu7, MuonsObjects_BPMu12_IP6, MuonsObjects_BPMu8, MuonsObjects_BPMu8_IP6,MuonsObjects_BPMu8_IP5,MuonsObjects_BPMu9_IP0, MuonsObjects_BPMu9_IP3, MuonsObjects_BPMu9_IP4, MuonsObjects_BPMu9_IP5, MuonsObjects_BPMu9_IP6;
	 
	 for (pat::TriggerObjectStandAlone obj : *triggerObjects) { // note: not "const &" since we want to call unpackPathNames                       
	   obj.unpackPathNames(triggerNames);
	   //std::cout << "\tTrigger object:  pt " << obj.pt() << ", eta " << obj.eta() << ", phi " << obj.phi() << std::endl;                         
	   //std::cout << "\t   Collection: " << obj.collection() << std::endl;                                                                        
	   //std::cout << "\t   Type IDs:   ";                                                                                                         
	   //for (unsigned h = 0; h < obj.filterIds().size(); ++h){                                                                                    
           //std::cout << " " << obj.filterIds()[h] ;                                                                                                 
	   //std::cout << "\t   Filters:    ";                                                                                                         
	   for (unsigned h = 0; h < obj.filterLabels().size(); ++h) {

	     if(obj.filterLabels()[h]=="hltdstau3muDisplaced3muFltr"){
	       //  std::cout << " Filter: " << obj.filterLabels()[h]<<endl;                                                                            
	       TriggerObj_DsTau3Mu.push_back(obj);
	     }
	     if(obj.filterLabels()[h]=="hltTau3muTkVertexFilter"){
	       TriggerObj_DsTau3Mu2017.push_back(obj);
	     }
	     if( isBParking){
	       if(obj.filterLabels()[h]=="hltL3fL1sMu22OrParkL1f0L2f10QL3Filtered8Q"){
		 MuonsObjects_BPMu8.push_back(obj);
	       }
	       if(obj.filterLabels()[h]=="hltL3fL1sMu22OrParkL1f0L2f10QL3Filtered7IP4Q"){
		 MuonsObjects_BPMu7.push_back(obj);
	       }
	       if(obj.filterLabels()[h]=="hltL3fL1sMu22OrParkL1f0L2f10QL3Filtered8IP6Q"){
		 MuonsObjects_BPMu8_IP6.push_back(obj);
	       }

	       if(obj.filterLabels()[h]=="hltL3fL1sMu22OrParkL1f0L2f10QL3Filtered8IP5Q"){
		 MuonsObjects_BPMu8_IP5.push_back(obj);
	       }

	       if(obj.filterLabels()[h]=="hltL3fL1sMu22OrParkL1f0L2f10QL3Filtered9IP0Q"){
		 MuonsObjects_BPMu9_IP0.push_back(obj);
	       }
	       if(obj.filterLabels()[h]=="hltL3fL1sMu22OrParkL1f0L2f10QL3Filtered9IP3Q"){
		 MuonsObjects_BPMu9_IP3.push_back(obj);}
	       if(obj.filterLabels()[h]=="hltL3fL1sMu22OrParkL1f0L2f10QL3Filtered9IP4Q"){
		 MuonsObjects_BPMu9_IP4.push_back(obj);
	       }
	       if(obj.filterLabels()[h]=="hltL3fL1sMu22OrParkL1f0L2f10QL3Filtered9IP5Q"){
		 MuonsObjects_BPMu9_IP5.push_back(obj);
	       }
	       if(obj.filterLabels()[h]=="hltL3fL1sMu22OrParkL1f0L2f10QL3Filtered9Q"){
		 MuonsObjects_BPMu9_IP6.push_back(obj);
	       }
	       if(obj.filterLabels()[h]=="hltL3fL1sMu22OrParkL1f0L2f10QL3Filtered12Q"){
		 MuonsObjects_BPMu12_IP6.push_back(obj);
	       }
	     }
	     //std::cout << "\tTrigger object:  pt " << obj.pt() << ", eta " << obj.eta() << ", phi " << obj.phi() << std::endl;                       
	     std::vector pathNamesAll = obj.pathNames(false);
	     std::vector pathNamesLast = obj.pathNames(true);
	   }

	   //}                                                                                                                                         
	 }
	 //      cout<<"TriggerObj_DsTau3Mu.size()="<<TriggerObj_DsTau3Mu.size()<<endl;                                                                
	 for(uint t=0; t<TriggerObj_DsTau3Mu.size();t++){
	   //cout<<" trig obj pt="<<TriggerObj_DsTau3Mu.at(t).pt()<<endl;                                                                              
	   MuonPt_HLT.push_back(TriggerObj_DsTau3Mu.at(t).pt());
	   MuonEta_HLT.push_back(TriggerObj_DsTau3Mu.at(t).eta());
	   MuonPhi_HLT.push_back(TriggerObj_DsTau3Mu.at(t).phi());
	 }

	 for(uint t=0; t<TriggerObj_DsTau3Mu2017.size();t++){
	   MuonPt_HLT2017.push_back(TriggerObj_DsTau3Mu2017.at(t).pt());
	   MuonEta_HLT2017.push_back(TriggerObj_DsTau3Mu2017.at(t).eta());
	   MuonPhi_HLT2017.push_back(TriggerObj_DsTau3Mu2017.at(t).phi());
	 }

	 for(uint t=0; t<MuonsObjects_BPMu7.size();t++){
	   MuonPt_HLT_BPMu7.push_back(MuonsObjects_BPMu7.at(t).pt());
	   MuonEta_HLT_BPMu7.push_back(MuonsObjects_BPMu7.at(t).eta());
	   MuonPhi_HLT_BPMu7.push_back(MuonsObjects_BPMu7.at(t).phi());
	 }


	 if( isBParking){
	   for(uint t=0; t<MuonsObjects_BPMu8.size();t++){
	     MuonPt_HLT_BPMu8.push_back(MuonsObjects_BPMu8.at(t).pt());
	     MuonEta_HLT_BPMu8.push_back(MuonsObjects_BPMu8.at(t).eta());
	     MuonPhi_HLT_BPMu8.push_back(MuonsObjects_BPMu8.at(t).phi());
	   }

	   for(uint t=0; t<MuonsObjects_BPMu8_IP6.size();t++){
	     MuonPt_HLT_BPMu8_IP6.push_back(MuonsObjects_BPMu8_IP6.at(t).pt());
	     MuonEta_HLT_BPMu8_IP6.push_back(MuonsObjects_BPMu8_IP6.at(t).eta());
	     MuonPhi_HLT_BPMu8_IP6.push_back(MuonsObjects_BPMu8_IP6.at(t).phi());
	   }

	   for(uint t=0; t<MuonsObjects_BPMu8_IP5.size();t++){
	     MuonPt_HLT_BPMu8_IP5.push_back(MuonsObjects_BPMu8_IP5.at(t).pt());
	     MuonEta_HLT_BPMu8_IP5.push_back(MuonsObjects_BPMu8_IP5.at(t).eta());
	     MuonPhi_HLT_BPMu8_IP5.push_back(MuonsObjects_BPMu8_IP5.at(t).phi());
	   }

	   for(uint t=0; t<MuonsObjects_BPMu9_IP0.size();t++){
	     MuonPt_HLT_BPMu9_IP0.push_back(MuonsObjects_BPMu9_IP0.at(t).pt());
	     MuonEta_HLT_BPMu9_IP0.push_back(MuonsObjects_BPMu9_IP0.at(t).eta());
	     MuonPhi_HLT_BPMu9_IP0.push_back(MuonsObjects_BPMu9_IP0.at(t).phi());
	   }

	   for(uint t=0; t< MuonsObjects_BPMu9_IP3.size();t++){
	     MuonPt_HLT_BPMu3_IP3.push_back(MuonsObjects_BPMu9_IP3.at(t).pt());
	     MuonEta_HLT_BPMu3_IP3.push_back(MuonsObjects_BPMu9_IP3.at(t).eta());
	     MuonPhi_HLT_BPMu3_IP3.push_back(MuonsObjects_BPMu9_IP3.at(t).phi());
	   }

	   for(uint t=0; t< MuonsObjects_BPMu9_IP4.size();t++){
	     MuonPt_HLT_BPMu3_IP4.push_back(MuonsObjects_BPMu9_IP4.at(t).pt());
	     MuonEta_HLT_BPMu3_IP4.push_back(MuonsObjects_BPMu9_IP4.at(t).eta());
	     MuonPhi_HLT_BPMu3_IP4.push_back(MuonsObjects_BPMu9_IP4.at(t).phi());

	   }

	   for(uint t=0; t< MuonsObjects_BPMu9_IP5.size();t++){
	     MuonPt_HLT_BPMu3_IP5.push_back(MuonsObjects_BPMu9_IP5.at(t).pt());
	     MuonEta_HLT_BPMu3_IP5.push_back(MuonsObjects_BPMu9_IP5.at(t).eta());
	     MuonPhi_HLT_BPMu3_IP5.push_back(MuonsObjects_BPMu9_IP5.at(t).phi());
	   }
	   for(uint t=0; t< MuonsObjects_BPMu9_IP6.size();t++){
	     MuonPt_HLT_BPMu3_IP6.push_back(MuonsObjects_BPMu9_IP6.at(t).pt());
	     MuonEta_HLT_BPMu3_IP6.push_back(MuonsObjects_BPMu9_IP6.at(t).eta());
	     MuonPhi_HLT_BPMu3_IP6.push_back(MuonsObjects_BPMu9_IP6.at(t).phi());

	   }

	   for(uint t=0; t< MuonsObjects_BPMu12_IP6.size();t++){
	     MuonPt_HLT_BPMu12_IP6.push_back(MuonsObjects_BPMu12_IP6.at(t).pt());
	     MuonEta_HLT_BPMu12_IP6.push_back(MuonsObjects_BPMu12_IP6.at(t).eta());
	     MuonPhi_HLT_BPMu12_IP6.push_back(MuonsObjects_BPMu12_IP6.at(t).phi());
	   }
	 }




	///////////////Fill GEN particles///////////////        
        if(isMc){
            uint j=0;
            uint ngenP=genParticles->size();
            
            cout<<"****************GenLevel Info Begin********************"<<endl;
            for(edm::View<reco::GenParticle>::const_iterator gp=genParticles->begin(); gp!=genParticles->end(), j<ngenP; ++gp , ++j){
                //if(fabs(gp->pdgId())==15) tauRaw = j;
                
                int isDs = -1; //-1:not Ds //0:is not prompt Ds//1:is prompt pp->Ds//2:is D from B decays
                int isB = -1; //-1:not B //0:is not prompt B//1:is prompt B
                int isBdecay = -1; //-1:not B //0:isB //1: is B to Ds//2: is B to anything else
                if ( fabs(gp->pdgId()) == 511 || fabs(gp->pdgId()) == 521 || fabs(gp->pdgId()) == 531 ) { //B0 or B+ or Bs found
		  //                  cout<<"B meson"<<endl;
                   isB=0;
                   isBdecay=0;
                   for(uint t=0; t<gp->numberOfMothers(); t++) {
                      cout<<"  gp->mother("<<t<<")->pdgId() = "<<gp->mother(t)->pdgId()<<endl;
                      if( fabs(gp->mother(t)->pdgId()) == 513 || fabs(gp->mother(t)->pdgId()) == 523 || fabs(gp->mother(t)->pdgId()) == 533 || fabs(gp->mother(t)->pdgId()) == 535 ) { //B*
                         for(uint i=0; i<gp->mother(t)->numberOfMothers(); i++) {
			   //        cout<<"    gp->mother("<<t<<")->mother("<<i<<")->pdgId() = "<<gp->mother(t)->mother(i)->pdgId()<<endl;
                            if(fabs(gp->mother(t)->mother(i)->pdgId())==5) { //b quark
			      //  cout<<"    prompt"<<endl;
                               isB=1;
                            }
                         }
                      }else{
                         if(fabs(gp->mother(t)->pdgId()) == 5){ //b quark
			   //cout<<"    prompt"<<endl;
                            isB=1;
                         }
                      }
                   }
                   cout<<"B->"<<endl;
                   for(uint b=0; b<gp->numberOfDaughters(); b++) {
                      if ( fabs(gp->daughter(b)->pdgId()) == 431 || fabs(gp->daughter(b)->pdgId()) == 433 || fabs(gp->daughter(b)->pdgId()) == 435 ) {
			//cout<<"   Ds"<<endl;
                         isBdecay=1;
                      }else isBdecay=2;
                   }
                }
                if ( fabs(gp->pdgId()) == 431 ) { //Ds
                   cout<<"D_s meson"<<endl;
                   isDs=0;
                   for(uint t=0; t<gp->numberOfMothers(); t++) {
                      cout<<"  gp->mother("<<t<<")->pdgId() = "<<gp->mother(t)->pdgId()<<endl;
                      if( fabs(gp->mother(t)->pdgId()) == 433 || fabs(gp->mother(t)->pdgId()) == 435 ) { //D*
                         for(uint i=0; i<gp->mother(t)->numberOfMothers(); i++) {
                            cout<<"    gp->mother("<<t<<")->mother("<<i<<")->pdgId() = "<<gp->mother(t)->mother(i)->pdgId()<<endl;
                            if(fabs(gp->mother(t)->mother(i)->pdgId())==3 || fabs(gp->mother(t)->mother(i)->pdgId())==4) { //s or c quark
                               cout<<"    prompt"<<endl;
                               isDs=1;
                            } else {
                               if(fabs(gp->mother(t)->mother(i)->pdgId())==521 || fabs(gp->mother(t)->mother(i)->pdgId())==511 || fabs(gp->mother(t)->mother(i)->pdgId())==531) {
                                  cout<<"    from B decay"<<endl;
                                  isDs=2;
                               }          
                            }
                         }
                      }else{
                         if(fabs(gp->mother(t)->pdgId())==3 || fabs(gp->mother(t)->pdgId())==4) { //s or c quark
                            cout<<"    prompt"<<endl;
                            isDs=1;
                         }else{
                            if(fabs(gp->mother(t)->pdgId())==521 || fabs(gp->mother(t)->pdgId())==511 || fabs(gp->mother(t)->pdgId())==531 ){
                               cout<<"    from B decay"<<endl;
                               isDs=2;
                            }
                         }
                      }
                   }
                }

                if(fabs(gp->pdgId())==13 || fabs(gp->pdgId())==15  || fabs(gp->pdgId())==11 || fabs(gp->pdgId())==211 || fabs(gp->pdgId())==321 ||  fabs(gp->pdgId())==12  || fabs(gp->pdgId())==14 || fabs(gp->pdgId())==16 || fabs(gp->pdgId())==431 || fabs(gp->pdgId())==333 || fabs(gp->pdgId())==511 || fabs(gp->pdgId())==521) {
                    GenParticle_PdgId.push_back(gp->pdgId());
                    GenParticle_Pt.push_back(gp->pt());
                    GenParticle_Eta.push_back(gp->eta());
                    GenParticle_Phi.push_back(gp->phi());
                    GenParticle_isDs.push_back(isDs);
                    GenParticle_isB.push_back(isB);
                    GenParticle_isBdecay.push_back(isBdecay);

                    if(fabs(gp->pdgId())==13 && gp->numberOfMothers() && fabs(gp->mother(0)->pdgId()) ==333 ){
		      //   cout<<"Mu from phi pt="<<gp->pt()<<" vz="<<gp->vz()<<endl;
                    
                    }
                    if (gp->numberOfMothers()) {GenParticle_MotherPdgId.push_back(gp->mother(0)->pdgId());
                    }else{
                        GenParticle_MotherPdgId.push_back(-99);
                    }
                
                }
            }
            
            
	    cout<<"****************GenLevel Info End ********************"<<endl;
        }


	uint kk=0;
	std::vector<uint> VtxIdV;
        cout<<"Number of PFCands="<<PFCands->size()<<endl;
	std::vector<uint> SelectedCandIdx;
        vector<pat::PackedCandidate> MyPFCands;
        for (std::vector<pat::PackedCandidate>::const_iterator cand = PFCands->begin(); cand != PFCands->end(), kk!= PFCands->size(); ++cand, ++kk) {

          if (cand->charge()==0) continue;
	  if (cand->vertexRef().isNull()) continue;
	  if (!(cand->hasTrackDetails()) ) continue;
	  /*	  	  

	  if( cand->pt()>2 && fabs(cand->eta())<2.4 && cand->hasTrackDetails()  && cand->trackerLayersWithMeasurement()>5 &&  cand->pixelLayersWithMeasurement() >0 ) {
	  Track_pt.push_back(cand->pt());
          Track_eta.push_back(cand->eta());
          Track_phi.push_back(cand->phi());
          //cout<<"Track loop: pt="<<track.pt()<<endl;                                                                                                
          //Track_normalizedChi2.push_back(cand->normalizedChi2_());
          Track_numberOfValidHits.push_back(cand->trackerLayersWithMeasurement());
          Track_charge.push_back(cand->charge());
          Track_dxy.push_back(cand->dxy());
          Track_dxyError.push_back(cand->dxyError());
          Track_dz.push_back(cand->dz());
          Track_dzError.push_back(cand->dzError());
          Track_vx.push_back(cand->vx());
          Track_vy.push_back(cand->vy());
          Track_vz.push_back(cand->vz());
	  Track_pdgId.push_back(cand->pdgId());
	  }
	  
	   if ( !(cand->bestTrack()) ) continue;
	  
          
          int quality = cand->pvAssociationQuality();

          //      if (quality != pat::PackedCandidate::UsedInFitTight)  continue;                                                                     
          //      if (quality != pat::PackedCandidate::UsedInFitLoose)  continue;                                                                     
          // cout<<kk<<" vtx ref key="<<key<<" cand pt="<<cand->pt()<<" vtx x="<<cand->vertexRef()->x()<<endl;                                        */
	  int key = cand->vertexRef().key();
          VtxIdV.push_back(key);
          SelectedCandIdx.push_back(kk);
          MyPFCands.push_back(*cand);
        } // loop over the PFCandidates                                                                                                               
	
                                                                                                                                                    
	//for(uint VtxIt =0;VtxIt<vertices->size();VtxIt++ ){                                                                                           
	//cout<<"Vtx id="<<VtxIt<<" x="<<(*vertices)[VtxIt].x()<<endl;                                                                                
	//}

        //cout<<" vtx id size="<<VtxIdV.size()<<endl;                                                                                                 
        sort( VtxIdV.begin(), VtxIdV.end() );
	VtxIdV.erase( unique(VtxIdV.begin(), VtxIdV.end() ),VtxIdV.end() );


	//        cout<<"After removing duplicates: vtx id size="<<VtxIdV.size()<<endl;
        /*                                                                                                                                                    for(uint i=0; i<VtxIdV.size();i++){                                                                                                         
	cout<<i<<" vtx id="<<VtxIdV.at(i)<<endl;                                                                                                    
	}*/

        uint mm=0;
        typedef vector<double> MyPt;
        vector<MyPt> AssoPtToVtx;
        vector<pat::PackedCandidate> SelPFCands;
	vector<vector<pat::PackedCandidate>> AssoCandToVtx;
	 
	
	for(uint i=0; i<VtxIdV.size();i++){
          vector<double> tmp_pt;
          vector<pat::PackedCandidate> tmp_cand;
          //vector<MyTrks> tmp_trks;                                                                                                                           //cout<<i<<"----------Stored Vtx id="<<VtxIdV.at(i)<<"---------------"<<endl;                                                               
          for (vector<pat::PackedCandidate>::const_iterator myc = MyPFCands.begin(); myc != MyPFCands.end(); ++myc) {

            //cout<<"cand vtx="<<myc->vertexRef().key()<<" cand pt="<<myc->pt()<<endl;                                                                
            if(myc->vertexRef().key()==VtxIdV.at(i)) {
              tmp_pt.push_back(myc->pt());
              tmp_cand.push_back(*myc);

            }
          }

	  AssoPtToVtx.push_back(tmp_pt);
	  AssoCandToVtx.push_back(tmp_cand);
        
	}
	//	cout<<" AssoCandToVtx.size()="<<AssoCandToVtx.size()<<endl;                                                                                 
	 	
	vector<vector<reco::TransientTrack>> transTracksAssoToVtx;
	 
	for(uint i=0; i<AssoCandToVtx.size();i++){
	  //cout<<i<<" vertex ID="<<VtxIdV.at(i)<<" with trk ass. n="<<AssoCandToVtx.at(i).size()<<endl;                                              
	  std::auto_ptr<reco::TrackCollection> newTrackCollection = std::auto_ptr<reco::TrackCollection>(new TrackCollection);

	  std::vector<reco::TransientTrack> transTracks;
	  std::vector<reco::TransientTrack> transTracks2;


	  for(vector<pat::PackedCandidate>::const_iterator c = AssoCandToVtx.at(i).begin(); c != AssoCandToVtx.at(i).end(); ++c) {
	    reco::Track myTrack =c->pseudoTrack();
	    reco::TransientTrack mytt = theTransientTrackBuilder->build(myTrack);
	    //if(mytt.isValid()){
	    //transTracks2.push_back(mytt);
	    // }
	    //cout<<" ----> dereferencing ="<< (c->bestTrack())  <<endl;                                                            
	    //newTrackCollection->push_back(*(c->bestTrack()));
	    //newTrackCollection->push_back((c->pseudoTrack()));
	    
	  }
	
	// cout<<i<<" vertex ID="<<VtxIdV.at(i)<<" newTrackCollection size="<<newTrackCollection->size()<<endl;   
	  /*	 	  	  
	  
          for (std::vector<reco::Track>::const_iterator iter = newTrackCollection->begin(); iter != newTrackCollection->end(); ++iter){
	    reco::TransientTrack tt = theTransientTrackBuilder->build(*iter);
	    if ( tt.isValid()){
	      transTracks.push_back(tt);
	    }
          }
	  */
          //transTracksAssoToVtx.push_back(transTracks);
          //transTracksAssoToVtx.push_back(transTracks2);
	 
	  
          //cout<<" trans Tracks size="<<transTracksAssoToVtx.at(i).size()<<endl;                                                                    
	  // for(uint f=0;f<transTracksAssoToVtx.at(i).size(); f++){                                                                                          //	    cout<<f<<" stored trtrk eta="<<transTracksAssoToVtx.at(i).at(f).track().eta()<<endl;}
	}

       
	/*
	
	std::vector<int> NTripl;
        bool is2Mu=true;

        if(is2Mu) {
          //Triplets  Loop
          cout<<"Number Of Triplets="<<Cand2Mu1Track->size()<<endl;
          TripletCollectionSize2 = Cand2Mu1Track->size();
          //int TripletIndex2 =-99; 
	  uint trIn2=0;
	  //vector<int> selectedTriplets;
          for(edm::View<reco::CompositeCandidate>::const_iterator PhiIt=Cand2Mu1Track->begin(); PhiIt!=Cand2Mu1Track->end(), trIn2<Cand2Mu1Track->size(); ++PhiIt, ++trIn2){
              
              
              //Daughter Kinematics at reco+gen level
              const Candidate * c1 = PhiIt->daughter(0)->masterClone().get();
              const pat::Muon *mu1 = dynamic_cast<const pat::Muon *>(c1);
              
              const Candidate * c2 = PhiIt->daughter(1)->masterClone().get();
              const pat::Muon *mu2 = dynamic_cast<const pat::Muon *>(c2);
              
              const Candidate * c3 = PhiIt->daughter(2)->masterClone().get(); 
              TrackRef trkref3 = c3->get<TrackRef>();
	      if(!(trkref3.isNonnull())) continue;
              const reco::TransientTrack transientTrack3=theTransientTrackBuilder_->build( trkref3 );
              reco::Track Track3 =transientTrack3.track();
              reco::Track* TrackRef3=&Track3;
	      //check overlap among the legs of the triplet
	      if(!(fabs(c1->eta()-c3->eta())>  1.e-6)) continue;
	      if(!(fabs(c2->eta()-c3->eta())>  1.e-6)) continue;
	      if(!(PhiIt->vertexChi2()>0)) continue;


              /////////////////VertexFit///////////////////////////////////
              TrackRef trk01, trk02;
              if (mu1->isGlobalMuon()) { trk01 = mu1->get<TrackRef,reco::CombinedMuonTag>();}
              else { trk01 = mu1->get<TrackRef>();}
              if (mu2->isGlobalMuon()) { trk02 = mu2->get<TrackRef,reco::CombinedMuonTag>();}
              else{ trk02 = mu2->get<TrackRef>();}
              //if (mu3->isGlobalMuon()) { trk3 = mu3->get<TrackRef,reco::CombinedMuonTag>();}
              //else{  trk3 = mu3->get<TrackRef>();}
              //cout<<" trk1 id="<<trk1.id()<<" tr2:"<<trk2.id()<<" trk3="<<trk3.id()<<endl;
              const reco::TransientTrack transientTrack1=theTransientTrackBuilder_->build( trk01 );
              const reco::TransientTrack transientTrack2=theTransientTrackBuilder_->build( trk02 );
              reco::Track Track1 =transientTrack1.track();
              reco::Track Track2 =transientTrack2.track();
              reco::Track* TrackRef1=&Track1;
              reco::Track* TrackRef2=&Track2;
              vector<reco::Track*> SVTrackRef2;
              SVTrackRef2.push_back(TrackRef1);
              SVTrackRef2.push_back(TrackRef2);
              SVTrackRef2.push_back(TrackRef3); //da sistemare con kin fit phi->2mu

              ///////////////PV taken as closest to candidate
	      reco::Vertex TripletVtx = reco::Vertex(PhiIt->vertex(), PhiIt->vertexCovariance(), PhiIt->vertexChi2(), PhiIt->vertexNdof(), PhiIt->numberOfDaughters() );
	      double dphi_pv = -1.0;
	      uint primaryvertex_index=0;
	      uint selVtxId;

              TLorentzVector ThreeCandidate;
 	      ThreeCandidate.SetPtEtaPhiM(PhiIt->pt(), PhiIt->eta(), PhiIt->phi(), PhiIt->mass());     

	      if(VtxIdV.size()>0 && vertices->size()>0) {
		for(uint VtxIt =0;VtxIt<vertices->size();VtxIt++ ){
		  for(uint k=0;k<VtxIdV.size();k++){
		    if(VtxIdV[k]==VtxIt){
		      TVector3 Dv3D_reco(TripletVtx.x() - (*vertices)[VtxIt].x(), TripletVtx.y() - (*vertices)[VtxIt].y(), TripletVtx.z() - (*vertices)[VtxIt].z());
		      double Cosdphi_3D = Dv3D_reco.Dot(ThreeCandidate.Vect())/(Dv3D_reco.Mag()*ThreeCandidate.Vect().Mag());
		      //cout<<"cosDPhi3D="<<Cosdphi_3D<<endl;                                                                             
		      if(Cosdphi_3D>dphi_pv){
			dphi_pv = Cosdphi_3D;
			primaryvertex_index=VtxIt;
			selVtxId=k;
		      }
		    }
		  }
		}


		//cout<<" trans trk coll before ref="<<transTracksAssoToVtx.at(selVtxId).size()<<endl;                                                    
		//      for(uint t=0; t<transTracksAssoToVtx.at(selVtxId).size(); t++){                                                                   
		//        cout<<"pv track eta="<<transTracksAssoToVtx.at(selVtxId).at(t).track().eta()<<endl;}     


	      std::vector<reco::TransientTrack> pvTracks_original;
 	      TransientTrackMap pvTrackMap_refit;
	      removeTracks3(transTracksAssoToVtx.at(selVtxId),  SVTrackRef2);
	      RefittedPV2_NTracks.push_back(transTracksAssoToVtx.at(selVtxId).size());

	      if(transTracksAssoToVtx.at(selVtxId).size() >1){

	      /////////////PV Refit//////////////////////////////

		KalmanVertexFitter PV_fitter (true);
		TransientVertex PVertex = PV_fitter.vertex(transTracksAssoToVtx.at(selVtxId)); //Kinematic?
                
		RefittedPV2_isValid.push_back(PVertex.isValid());
                
		cout<<"Valid Vtx ? ="<<PVertex.isValid()<<endl;
		if(PVertex.isValid() ){
		  
    
		  NTripl.push_back(1);
		  selectedTripletsIndex.push_back(trIn2);


		  Mu01_Pt.push_back(mu1->pt());
		  Mu01_Eta.push_back(mu1->eta());
		  Mu01_Phi.push_back(mu1->phi());
		  Mu01_TripletIndex.push_back(trIn2);
              
		  Mu02_Pt.push_back(mu2->pt());
		  Mu02_Eta.push_back(mu2->eta());
		  Mu02_Phi.push_back(mu2->phi());
		  Mu02_TripletIndex.push_back(trIn2);
              
		  Tr_Pt.push_back(Track3.pt());
		  Tr_Eta.push_back(Track3.eta());
		  Tr_Phi.push_back(Track3.phi());
		  Tr_TripletIndex.push_back(trIn2);
		  //cout<<trIn2<<"Triplet track"<<Track3.pt()<<" "<<endl;


		  //cout<<"Reco mu1 eta="<<mu1->eta()<<" mu2 eta="<<mu2->eta()<<" mu3 eta="<<c3->eta()<<endl;
		  //cout<<"Reco mu1 phi="<<mu1->phi()<<" mu2 pt="<<mu2->phi()<<" mu3 pt="<<c3->phi()<<endl;

		  //TransientVertex TransientTripletVtx = reco::Vertex(TauIt->vertex(), TauIt->vertexCovariance(), TauIt->vertexChi2(), TauIt->vertexNdof(), TauIt->numberOfDaughters() );
		  //cout<<" number of muons in triplet="<<TauIt->numberOfDaughters()<<endl;

              ///////////////Check Trigger Matching///////////////
              float dR1 = 999., dR2 = 999., dR3 = 999.;
	      float dR1_Mu7=999.,dR2_Mu7 = 999., dR3_Mu7 = 999.;
	      float dR1_Mu8=999.,dR2_Mu8 = 999., dR3_Mu8 = 999.;
	      float dR1_Mu8_IP6=999., dR1_Mu12_IP6=999, dR1_Mu8_IP5=999.;
	      float dR1_Mu9_IP0=999., dR1_Mu9_IP3=999.,  dR1_Mu9_IP4=999.,  dR1_Mu9_IP5=999., dR1_Mu9_IP6=999.;
	      float dR1_2017 = 999., dR2_2017 = 999., dR3_2017 = 999.;

	      dR1_2017 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, TriggerObj_DsTau3Mu2017);
	      dR2_2017 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu2, TriggerObj_DsTau3Mu2017);
	      dR3_2017 = DsPhiPiTreeMakerMINI::dRtriggerMatchTrk(Track3, TriggerObj_DsTau3Mu2017);
	      Mu1_dRtriggerMatch_2017.push_back(dR1_2017);                                                                                          
	      Mu2_dRtriggerMatch_2017.push_back(dR2_2017);
	      Mu3_dRtriggerMatch_2017.push_back(dR3_2017);


	      dR1 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, TriggerObj_DsTau3Mu);
	      dR2 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu2, TriggerObj_DsTau3Mu);
	      dR3 = DsPhiPiTreeMakerMINI::dRtriggerMatchTrk(Track3, TriggerObj_DsTau3Mu);
	      //cout<<"Trigger Matching: dR1="<<dR1<<" dR2="<<dR2<<" dR3="<<dR3<<endl;                                                               
	      Mu1_dRtriggerMatch.push_back(dR1);                                                                                                     
	      Mu2_dRtriggerMatch.push_back(dR2);                                                                                                     
	      Mu3_dRtriggerMatch.push_back(dR3);

	      if( isBParking){
		dR1_Mu8 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, MuonsObjects_BPMu8);
		dR2_Mu8 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu2, MuonsObjects_BPMu8);
		dR3_Mu8 = DsPhiPiTreeMakerMINI::dRtriggerMatchTrk(Track3, MuonsObjects_BPMu8);
		Mu1_dRtriggerMatch_Mu8.push_back(dR1_Mu8);
		Mu2_dRtriggerMatch_Mu8.push_back(dR2_Mu8);
		Mu3_dRtriggerMatch_Mu8.push_back(dR3_Mu8);

		dR1_Mu7 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, MuonsObjects_BPMu7);
		dR2_Mu7 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu2, MuonsObjects_BPMu7);
		dR3_Mu7 = DsPhiPiTreeMakerMINI::dRtriggerMatchTrk(Track3, MuonsObjects_BPMu7);

		Mu1_dRtriggerMatch_Mu7.push_back(dR1_Mu7);
		Mu2_dRtriggerMatch_Mu7.push_back(dR2_Mu7);
		Mu3_dRtriggerMatch_Mu7.push_back(dR3_Mu7);


		dR1_Mu8_IP5 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, MuonsObjects_BPMu8_IP5);

		Mu1_dRtriggerMatch_Mu8_IP5.push_back(dR1_Mu8_IP5);

		dR1_Mu8_IP6 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, MuonsObjects_BPMu8_IP6);

		Mu1_dRtriggerMatch_Mu8_IP6.push_back(dR1_Mu8_IP6);

		dR1_Mu9_IP0 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, MuonsObjects_BPMu9_IP0);

		Mu1_dRtriggerMatch_Mu9_IP0.push_back(dR1_Mu9_IP0);

		dR1_Mu9_IP3 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, MuonsObjects_BPMu9_IP3);

		Mu1_dRtriggerMatch_Mu9_IP3.push_back(dR1_Mu9_IP3);

		dR1_Mu9_IP4 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, MuonsObjects_BPMu9_IP4);

		Mu1_dRtriggerMatch_Mu9_IP4.push_back(dR1_Mu9_IP4);

		dR1_Mu9_IP5 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, MuonsObjects_BPMu9_IP5);

		Mu1_dRtriggerMatch_Mu9_IP5.push_back(dR1_Mu9_IP5);


		dR1_Mu9_IP6 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, MuonsObjects_BPMu9_IP6);

		Mu1_dRtriggerMatch_Mu9_IP6.push_back(dR1_Mu9_IP6);

		dR1_Mu12_IP6 = DsPhiPiTreeMakerMINI::dRtriggerMatch(*mu1, MuonsObjects_BPMu12_IP6);
		Mu1_dRtriggerMatch_Mu12_IP6.push_back(dR1_Mu12_IP6);
	      }
	      

              if(isMc){ //if is TauPhiPi Monte Carlo
		bool isMatch1=false; bool isMatch2=false; //bool isMatch3=false;
		if( (mu1->simType() == reco::MatchedMuonFromLightFlavour) && (fabs(mu1->simMotherPdgId()) == 333) ){ //chiedi mu 13 e richiesta su mother 333
		  isMatch1=true;
                      
		}
		if( (mu2->simType() == reco::MatchedMuonFromLightFlavour) && (fabs(mu2->simMotherPdgId()) == 333) ){
		  isMatch2=true;
		}
	      
                  
		// Cout<<trIn2<<"Triplet Mass:"<<PhiIt->mass()<<" pt="<<PhiIt->pt()<<" vtx.x="<<PhiIt->vx()<<" vtx x="<<TripletVtx.x()<<" chi2="<<PhiIt->vertexChi2()<<" ndof="<<PhiIt->vertexNdof()<<endl;
		//   cout<<trIn2<<"--Muon 1 pt="<<mu1->pt()<<" Muon2 pt="<<mu2->pt()<<" Mu3 pt="<<c3->pt()<<" "<<endl;
                  if( isMatch1 && isMatch2) {
		    //cout<<" Matched Di-muon mass="<<PhiIt->mass()<<endl;
                      GenMatchMu01_SimPt.push_back(mu1->simPt());
                      GenMatchMu02_SimPt.push_back(mu2->simPt());
                     // GenMatchMu3_SimPt.push_back(mu3->simPt());
                      
                      GenMatchMu01_SimEta.push_back(mu1->simEta());
                      GenMatchMu02_SimEta.push_back(mu2->simEta());
                     // GenMatchMu3_SimEta.push_back(mu3->simEta());
                      
                      GenMatchMu01_SimPhi.push_back(mu1->simPhi());
                      GenMatchMu02_SimPhi.push_back(mu2->simPhi());
                     // GenMatchMu3_SimPhi.push_back(mu3->simPhi());
                      
                      GenMatchMu01_Pt.push_back(mu1->pt());
                      GenMatchMu02_Pt.push_back(mu2->pt());
                     // GenMatchMu3_Pt.push_back(mu3->pt());
                      
                      GenMatchMu01_Eta.push_back(mu1->eta());
                      GenMatchMu02_Eta.push_back(mu2->eta());
                     // GenMatchMu3_Eta.push_back(mu3->eta());
                      
                      GenMatchMu01_Phi.push_back(mu1->phi());
                      GenMatchMu02_Phi.push_back(mu2->phi());
                     // GenMatchMu3_Phi.push_back(mu3->phi());
                      
                  }
              }//if is MC, then do gen-match    
	      //GenVtx vars to be added

	      //Triplets Vars
              TripletVtx2_x.push_back(PhiIt->vx());
              TripletVtx2_y.push_back(PhiIt->vy());
              TripletVtx2_z.push_back(PhiIt->vz());
              
              TripletVtx2_Chi2.push_back(PhiIt->vertexChi2());
              TripletVtx2_NDOF.push_back(PhiIt->vertexNdof());
              
              Triplet2_Mass.push_back(PhiIt->mass());
              Triplet2_Pt.push_back(PhiIt->pt());
              Triplet2_Eta.push_back(PhiIt->eta());
              Triplet2_Phi.push_back(PhiIt->phi());
              Triplet2_Charge.push_back(PhiIt->charge());
              //Matrix covariance to be added!!!!


              //Refitted Vars
              //vector < TransientTrack > ttrks = TripletVtx.refittedTracks();
              


              ////Defining ISO VAR related to the triplet
              math::XYZPoint SVertexPoint = math::XYZPoint(TripletVtx.x(), TripletVtx.y(), TripletVtx.z());
              TLorentzVector LV1=TLorentzVector( mu1->px(), mu1->py(), mu1->pz(), mu1->energy() );
              TLorentzVector LV2=TLorentzVector( mu2->px(), mu2->py(), mu2->pz(), mu2->energy() );
              TLorentzVector LV3=TLorentzVector( c3->px(), c3->py(), c3->pz(), c3->energy() );
              TLorentzVector LVDs = LV1 + LV2 + LV3;

              int nTracks03_mu1=0, nTracks03_mu2=0, nTracks03_trk3=0;
              double mindist=9999;
              double sumPtTrack1=0, sumPtTrack2=0, sumPtTrack3=0, maxSumPtTracks=0;
	      //	      int nTracks03_mu1=0, nTracks03_mu2=0, nTracks03_mu3=0;

	      for (std::vector<pat::PackedCandidate>::const_iterator cand = PFCands->begin(); cand != PFCands->end();++cand) {

		if(  (cand->pt()>1) && (fabs(cand->eta())<2.4) && (cand->trackerLayersWithMeasurement()>5) && (cand->pixelLayersWithMeasurement()>1)  )\
		  {
		    double dR1 = reco::deltaR2(Track1.eta(), cand->eta(), Track1.phi(), cand->phi() );
		    double dR2 = reco::deltaR2(Track2.eta(), cand->eta(), Track2.phi(), cand->phi() );
		    double dR3 = reco::deltaR2(Track3.eta(), cand->eta(), Track3.phi(), cand->phi() );

                    if (dR1 < 0.01 || dR2 < 0.01 || dR3 < 0.01) {  
		       //cout<<"Skip muon track"<<endl; 
		       continue;}
                    double dz = abs(cand->dz(SVertexPoint));
                    double dxy = abs(cand->dxy(SVertexPoint));
                    double dca_fv = sqrt(dz*dz+dxy*dxy);
                    if(dca_fv<mindist && dca_fv>0) { 
		       //cout<<"dca_fv"<<dca_fv<<endl; 
		       mindist = dca_fv;
		    }
                    //for eack track having pt>1, excluded the muon tracks,
                    //for each muon in the triplet, if deltaR<0.3 and the DCA is smaller than 1 mm
                    //the pt of the track is added -> I will take the largest total pt from the three muons
                    if (dca_fv < 0.1) {
                       if (dR1<0.3) {
                          sumPtTrack1+=cand->pt();
                          nTracks03_mu1++;
                       }
                       if (dR2<0.3) {
                          sumPtTrack2+=cand->pt();
                          nTracks03_mu2++;
                       }
                       if (dR3<0.3) {
                          sumPtTrack3+=cand->pt();
                          nTracks03_trk3++;
                       }
                   }
                } 
             }//endl loop on tracks

             Triplet_mindca_iso.push_back(mindist);
	     maxSumPtTracks = std::max(sumPtTrack1, std::max(sumPtTrack2,sumPtTrack3));
	     //cout<<TripletIndex<<" TauMass "<<TauIt->mass()<<" SumPt Tracks in cone="<<maxSumPtTracks<<" TauPt="<<TauIt->pt()<<endl;                 
	     double relativeiso = maxSumPtTracks/LVDs.Pt();
	     Triplet_relativeiso.push_back(relativeiso);

	     Mu1_NTracks03iso.push_back(nTracks03_mu1);
	     Mu2_NTracks03iso.push_back(nTracks03_mu2);
	     Mu3_NTracks03iso.push_back(nTracks03_trk3);

	     double sumPtTrackRel1=0, sumPtTrackRel2=0, sumPtTrackRel3=0, maxSumPtRelTracks =0;
	     sumPtTrackRel1=sumPtTrack1/LV1.Pt();
	     sumPtTrackRel2=sumPtTrack2/LV2.Pt();
	     sumPtTrackRel3=sumPtTrack3/LV3.Pt();
	     maxSumPtRelTracks = std::max(sumPtTrackRel1, std::max(sumPtTrackRel2,sumPtTrackRel3));
	     Triplet_relativeiso2.push_back(maxSumPtRelTracks);
	     Triplet_IsoMu1.push_back(sumPtTrack1);
	     Triplet_IsoMu2.push_back(sumPtTrack2);
	     Triplet_IsoMu3.push_back(sumPtTrack3);


	     //CachingVertex<5> fittedVertex = vertexFitter.vertex(tracksToVertex);
	     GlobalPoint PVertexPos  (PVertex.position());
	     GlobalPoint SVertexPos  (TripletVtx.x(), TripletVtx.y(), TripletVtx.z());
	     //cout<<" PV Coord after refit="<<PVertexPos.x()<<" y="<<PVertexPos.y()<<" z="<<PVertexPos.z()<<endl;
	     
	     double FlightDist = TMath::Sqrt( pow(( PVertexPos.x() -SVertexPos.x()),2)+ pow(( PVertexPos.y() -SVertexPos.y()),2) + pow(( PVertexPos.z() -SVertexPos.z()),2));
             
	     VertexDistance3D vertTool;
	     VertexState PVstate(PVertex.position(),PVertex.positionError());
	     //VertexState SVstate(SVertexPos,TripletVtx.position());
	     double distance = vertTool.distance(PVstate, TripletVtx).value();
	     double dist_err = vertTool.distance(PVstate, TripletVtx).error();
	     double dist_sign =vertTool.distance(PVstate, TripletVtx).significance();
	     double chi2 = vertTool.compatibility(PVstate, TripletVtx);
                      
                      ////
	     PV_x.push_back( (*vertices)[primaryvertex_index].x());
	     PV_y.push_back( (*vertices)[primaryvertex_index].y());
	     PV_z.push_back( (*vertices)[primaryvertex_index].z());
	     PV_NTracks.push_back(pvTracks_original.size());
	     
	     RefittedPV2_x.push_back(PVertexPos.x());
	     RefittedPV2_y.push_back(PVertexPos.y());
	     RefittedPV2_z.push_back(PVertexPos.z());
	     
	     //RefittedPV_Chi2.push_back(PVertex.);
             
	     FlightDistPVSV2.push_back(distance);
	     FlightDistPVSV2_Err.push_back(dist_err);
	     FlightDistPVSV2_Significance.push_back(dist_sign);
	     FlightDistPVSV2_chi2.push_back(chi2);
		      
		      //Add dxy info
	     GlobalVector dir1(mu1->px(), mu1->py(),  mu1->pz()); //To compute sign of IP
	     GlobalVector dir2(mu2->px(), mu2->py(),  mu2->pz()); //To compute sign of IP
	     GlobalVector dir3(c3->px(),  c3->py(),    c3->pz()); //To compute sign of IP
	     std::pair<bool,Measurement1D> signed_IP2D_mu1 = IPTools::signedTransverseImpactParameter(transientTrack1, dir1, PVertex);
	     std::pair<bool,Measurement1D> signed_IP2D_mu2 = IPTools::signedTransverseImpactParameter(transientTrack2, dir2, PVertex);
	     std::pair<bool,Measurement1D> signed_IP2D_mu3 = IPTools::signedTransverseImpactParameter(transientTrack3, dir3, PVertex);
	     //cout<<" IP mu1="<<signed_IP2D_mu1.second.value()<<" IP mu2="<<signed_IP2D_mu2.second.value()<<" IP mu3="<<signed_IP2D_mu3.second.value()<<endl;
	     dxy_mu1.push_back(signed_IP2D_mu1.second.value());
	     dxy_mu2.push_back(signed_IP2D_mu2.second.value());
	     dxy_mu3.push_back(signed_IP2D_mu3.second.value());
	     
	     dxyErr_mu1.push_back(signed_IP2D_mu1.second.error());
	     dxyErr_mu2.push_back(signed_IP2D_mu2.second.error());
	     dxyErr_mu3.push_back(signed_IP2D_mu3.second.error());
             
		}else{
		  
		  Mu01_dRtriggerMatch.push_back(-99);
		  Mu02_dRtriggerMatch.push_back(-99);
		  Tr_dRtriggerMatch.push_back(-99);
		  RefittedPV2_x.push_back(-99);
		  RefittedPV2_y.push_back(-99);
		  RefittedPV2_z.push_back(-99);
		  RefittedPV2_NTracks.push_back(-99);
		  //RefittedPV2_Chi2.push_back(PVertex.);
                      
		  FlightDistPVSV2.push_back(-99);
		  FlightDistPVSV2_Err.push_back(-99);
		  FlightDistPVSV2_Significance.push_back(-99);
		  FlightDistPVSV2_chi2.push_back(-99);
		  
		  dxy_mu1.push_back(-99);
		  dxy_mu2.push_back(-99);
		  dxy_mu3.push_back(-99);
		  
		  dxyErr_mu1.push_back(-99);
		  dxyErr_mu2.push_back(-99);
		  dxyErr_mu3.push_back(-99);
		      

		  PV_x.push_back(-99);
		  PV_y.push_back(-99);
		  PV_z.push_back(-99);
		  PV_NTracks.push_back(-99);
		  
		  Triplet_mindca_iso.push_back(-99);
		  Triplet_relativeiso.push_back(-99);
		  
		  GenMatchMu01_SimPt.push_back(-99);
		  GenMatchMu02_SimPt.push_back(-99);
		  // GenMatchMu3_SimPt.push_back(mu3->simPt());                                                                                                        
		  
		  GenMatchMu01_SimEta.push_back(-99);
		  GenMatchMu02_SimEta.push_back(-99);
		  
		  GenMatchMu01_SimPhi.push_back(-99);
		  GenMatchMu02_SimPhi.push_back(-99);
		  GenMatchMu01_Pt.push_back(-99);
		  GenMatchMu02_Pt.push_back(-99);
		  GenMatchMu01_Eta.push_back(-99);
		  GenMatchMu02_Eta.push_back(-99);
		  GenMatchMu01_Phi.push_back(-99);
		  GenMatchMu02_Phi.push_back(-99);
		  
		  TripletVtx2_x.push_back(-99);
		  TripletVtx2_y.push_back(-99);
		  TripletVtx2_z.push_back(-99);
		      
		  TripletVtx2_Chi2.push_back(-99);
		  TripletVtx2_NDOF.push_back(-99);
		  
		  Triplet2_Mass.push_back(-99);
		  Triplet2_Pt.push_back(-99);
		  Triplet2_Eta.push_back(-99);
		  Triplet2_Phi.push_back(-99);
		  Triplet2_Charge.push_back(-99);
		  
		  Mu01_Pt.push_back(-99);
		  Mu01_Eta.push_back(-99);
		  Mu01_Phi.push_back(-99);
		  Mu01_TripletIndex.push_back(-99);
		  
		  Mu02_Pt.push_back(-99);
		  Mu02_Eta.push_back(-99);
		  Mu02_Phi.push_back(-99);
		  Mu02_TripletIndex.push_back(-99);
		  
		  Tr_Pt.push_back(-99);
		  Tr_Eta.push_back(-99);
		  Tr_Phi.push_back(-99);
		  Tr_TripletIndex.push_back(-99);
		  

		  RefittedPV2_NTracks.push_back(-99);
		  RefittedPV2_isValid.push_back(-99);

    
		  selectedTripletsIndex.push_back(-99);
		  Mu1_dRtriggerMatch_Mu7.push_back(-99);
                  Mu2_dRtriggerMatch_Mu7.push_back(-99);
                  Mu3_dRtriggerMatch_Mu7.push_back(-99);


                  Mu1_dRtriggerMatch_Mu8.push_back(-99);
                  Mu2_dRtriggerMatch_Mu8.push_back(-99);
                  Mu3_dRtriggerMatch_Mu8.push_back(-99);

		  Mu1_dRtriggerMatch_Mu8_IP5.push_back(-99);
		  Mu1_dRtriggerMatch_Mu8_IP6.push_back(-99);
		  Mu1_dRtriggerMatch_Mu9_IP0.push_back(-99);
		  Mu1_dRtriggerMatch_Mu9_IP3.push_back(-99);
		  Mu1_dRtriggerMatch_Mu9_IP4.push_back(-99);
		  Mu1_dRtriggerMatch_Mu9_IP5.push_back(-99);
		  Mu1_dRtriggerMatch_Mu9_IP6.push_back(-99);
		  Mu1_dRtriggerMatch_Mu12_IP6.push_back(-99);

		  Mu1_dRtriggerMatch_2017.push_back(-99);
		  Mu2_dRtriggerMatch_2017.push_back(-99);
		  Mu3_dRtriggerMatch_2017.push_back(-99);


		}
	      }
	      
              }
	  }//loops on 2Mu+1track candidates
	  
	}//is2Mu
	NGoodTriplets.push_back(NTripl.size());
	if(NTripl.size()>0) hEventsAfterGoodCand->Fill(1);

        TripletCollectionSize2 = Cand2Mu1Track->size();
	SelectedTripletsSize = selectedTripletsIndex.size();        
	cout<<"***Number of triplets before selection="<<TripletCollectionSize2<<" after sel="<<SelectedTripletsSize<<endl;
        cout<<"***Number of Muons="<<muons->size()<<endl;
	
	
	 

	uint k=0;
        std::vector<int> MuFilter;
        vector<pat::Muon>    MyMu, MyMu2, SyncMu;
        double AllMuPt =0;
        MuonCollectionSize = muons->size();
        
        for(edm::View<pat::Muon>::const_iterator mu=muons->begin(); mu!=muons->end(), k<muons->size(); ++mu, ++k){
            
            MuFilter.push_back(1);
            MyMu.push_back(*mu);
            
            //Basic Kinematics
            MuonPt.push_back(mu->pt());
            MuonEta.push_back(mu->eta());
            MuonPhi.push_back(mu->phi());
            MuonEnergy.push_back(mu->energy());
            MuonCharge.push_back(mu->charge());
            
            Muon_PdgId.push_back(mu->simPdgId());
            Muon_MotherPdgId.push_back(mu->simMotherPdgId());
            Muon_simFlavour.push_back(mu->simFlavour());
            //Vtx position
            Muon_vx.push_back(mu->vx());
            Muon_vy.push_back(mu->vy());
            Muon_vz.push_back(mu->vz());
            
            //cout<<" Muon mother: "<<mu->simMotherPdgId()<<endl;
            
            //MuonID
            Muon_isGlobal.push_back(mu->isGlobalMuon());
            //Muon_isTracker.push_back(mu->isTrackerMuon());
            Muon_isSoft.push_back(mu->isSoftMuon(PV));
            Muon_isLoose.push_back(mu->isLooseMuon());
            Muon_isPF.push_back(mu->isPFMuon());
            Muon_isRPCMuon.push_back(mu->isRPCMuon());
            Muon_isStandAloneMuon.push_back(mu->isStandAloneMuon());
            Muon_isTrackerMuon.push_back(mu->isTrackerMuon());
            Muon_isCaloMuon.push_back(mu->isCaloMuon());
            Muon_isQualityValid.push_back(mu->isQualityValid());
            Muon_isTimeValid.push_back(mu->isTimeValid());
            Muon_isIsolationValid.push_back(mu->isIsolationValid());
            Muon_numberOfMatchedStations.push_back(mu->numberOfMatchedStations());
            Muon_numberOfMatches.push_back(mu->numberOfMatches(reco::Muon::SegmentArbitration));
            Muon_SoftMVA_Val.push_back(mu->softMvaValue());
	    MuonChi2P.push_back(mu->combinedQuality().chi2LocalMomentum);
            MuonChi2LocalPosition.push_back(mu->combinedQuality().chi2LocalPosition);
            MuonGlbTrackProbability.push_back(mu->combinedQuality().glbTrackProbability);
            MuonTrkRelChi2.push_back(mu->combinedQuality().trkRelChi2);
            MuonTrkKink.push_back(mu->combinedQuality().trkKink);
            
            Muon_timeAtIpInOut.push_back(mu->time().timeAtIpInOut);
            Muon_timeAtIpInOutErr.push_back(mu->time().timeAtIpInOutErr);
            
	    std::vector<int> fvDThits{0, 0, 0, 0};
	    std::vector<int> fvRPChits{0, 0, 0, 0};
	    std::vector<int> fvCSChits{0, 0, 0, 0};

            float kVMuonHitComb = 0;
            if (mu->isGlobalMuon()) {
	      reco::TrackRef gTrack = mu->globalTrack();
              const reco::HitPattern& gMpattern = gTrack->hitPattern();
              for (int i = 0; i < gMpattern.numberOfAllHits(reco::HitPattern::TRACK_HITS); i++) {
                uint32_t hit = gMpattern.getHitPattern(reco::HitPattern::TRACK_HITS, i);
                if (!gMpattern.validHitFilter(hit))
                  continue;

                int muStation0 = gMpattern.getMuonStation(hit) - 1;
                if (muStation0 >= 0 && muStation0 < 4) {
                  if (gMpattern.muonDTHitFilter(hit))
                    fvDThits[muStation0]++;
                  if (gMpattern.muonRPCHitFilter(hit))
                    fvRPChits[muStation0]++;
                  if (gMpattern.muonCSCHitFilter(hit))
                    fvCSChits[muStation0]++;
                }
              }

              for (unsigned int station = 0; station < 4; ++station) {
                kVMuonHitComb += (fvDThits[station]) / 2.;
                kVMuonHitComb += fvRPChits[station];

                if (fvCSChits[station] > 6) {
                  kVMuonHitComb += 6;
                } else {
                  kVMuonHitComb += fvCSChits[station];
                }
              }
	      Muon_validMuonHitComb.push_back(kVMuonHitComb);
            }else{
              Muon_validMuonHitComb.push_back(-99);
            }



            if (mu->isGlobalMuon()) {
                Muon_GLnormChi2.push_back(mu->globalTrack()->normalizedChi2());
                Muon_GLhitPattern_numberOfValidMuonHits.push_back(mu->globalTrack()->hitPattern().numberOfValidMuonHits());
            }else
            {
                Muon_GLnormChi2.push_back(-999);
                Muon_GLhitPattern_numberOfValidMuonHits.push_back(-999);
            }
            
            if (mu->innerTrack().isNonnull()){

	      Muon_trackerLayersWithMeasurement.push_back(mu->innerTrack()->hitPattern().trackerLayersWithMeasurement());
	      bool ishighq = mu->innerTrack()->quality(reco::Track::highPurity);
	      Muon_innerTrack_highPurity.push_back(ishighq);
	      Muon_Numberofvalidpixelhits.push_back(mu->innerTrack()->hitPattern().numberOfValidPixelHits());
	      Muon_innerTrack_ValidFraction.push_back( mu->innerTrack()->validFraction() );
	      Muon_Numberofvalidpixelhits.push_back(mu->innerTrack()->hitPattern().numberOfValidPixelHits());
	      Muon_Numberofvalidtrackerhits.push_back(mu->innerTrack()->hitPattern().numberOfValidTrackerHits());
	      Muon_innerTrack_p.push_back(mu->innerTrack()->p());
	      Muon_innerTrack_eta.push_back(mu->innerTrack()->eta());
	      Muon_innerTrack_phi.push_back(mu->innerTrack()->phi());
	      Muon_innerTrack_normalizedChi2.push_back(mu->innerTrack()->normalizedChi2());

            }else
            {

	      Muon_innerTrack_ValidFraction.push_back( -99);
              Muon_innerTrack_highPurity.push_back( -99);
              Muon_trackerLayersWithMeasurement.push_back(-999);
              Muon_Numberofvalidpixelhits.push_back(-999);
              Muon_Numberofvalidtrackerhits.push_back(-999);
	      Muon_trackerLayersWithMeasurement.push_back(-999);
	      Muon_Numberofvalidpixelhits.push_back(-999);
	      Muon_innerTrack_p.push_back(-999);
	      Muon_innerTrack_eta.push_back(-999);
	      Muon_innerTrack_phi.push_back(-999);
	      Muon_innerTrack_normalizedChi2.push_back(-999);

            }
            if (mu->outerTrack().isNonnull()){
                Muon_outerTrack_p.push_back(mu->outerTrack()->p());
                Muon_outerTrack_eta.push_back(mu->outerTrack()->eta());
                Muon_outerTrack_phi.push_back(mu->outerTrack()->phi());
                Muon_outerTrack_normalizedChi2.push_back(mu->outerTrack()->normalizedChi2());
                Muon_outerTrack_muonStationsWithValidHits.push_back(mu->outerTrack()->hitPattern().muonStationsWithValidHits());
            }else{
                Muon_outerTrack_p.push_back(-999);
                Muon_outerTrack_eta.push_back(-999);
                Muon_outerTrack_phi.push_back(-999);
                Muon_outerTrack_normalizedChi2.push_back(-999);
                Muon_outerTrack_muonStationsWithValidHits.push_back(-999);
            }
            if (mu->innerTrack().isNonnull() && mu->outerTrack().isNonnull()){
                Muon_QInnerOuter.push_back(mu->outerTrack()->charge()*mu->innerTrack()->charge());
            }else{
                Muon_QInnerOuter.push_back(-999);
            }
            
            
            Muon_combinedQuality_updatedSta.push_back(mu->combinedQuality().updatedSta);
            Muon_combinedQuality_trkKink.push_back(mu->combinedQuality().trkKink);
            Muon_combinedQuality_glbKink.push_back(mu->combinedQuality().glbKink);
            Muon_combinedQuality_trkRelChi2.push_back(mu->combinedQuality().trkRelChi2);
            Muon_combinedQuality_staRelChi2.push_back(mu->combinedQuality().staRelChi2);
            Muon_combinedQuality_chi2LocalPosition.push_back(mu->combinedQuality().chi2LocalPosition);
            Muon_combinedQuality_chi2LocalMomentum.push_back(mu->combinedQuality().chi2LocalMomentum);
            Muon_combinedQuality_localDistance.push_back(mu->combinedQuality().localDistance);
            Muon_combinedQuality_globalDeltaEtaPhi.push_back(mu->combinedQuality().globalDeltaEtaPhi);
            Muon_combinedQuality_tightMatch.push_back(mu->combinedQuality().tightMatch);
            Muon_combinedQuality_glbTrackProbability.push_back(mu->combinedQuality().glbTrackProbability);
            
            Muon_calEnergy_em.push_back(mu->calEnergy().em);
            Muon_calEnergy_emS9.push_back(mu->calEnergy().emS9);
            Muon_calEnergy_emS25.push_back(mu->calEnergy().emS25);
            Muon_calEnergy_had.push_back(mu->calEnergy().had);
            Muon_calEnergy_hadS9.push_back(mu->calEnergy().hadS9);
            
            Muon_segmentCompatibility.push_back(muon::segmentCompatibility(*mu));
            Muon_caloCompatibility.push_back(muon::caloCompatibility(*mu));
            
            Muon_ptErrOverPt.push_back( (mu->muonBestTrack()->ptError()/mu->muonBestTrack()->pt()) );
            
            const reco::MuonIsolation Iso03 = mu->isolationR03();
            const reco::MuonIsolation Iso05 = mu->isolationR05();
            if (mu->isIsolationValid()) {
                Muon_emEt03.push_back(Iso03.emEt);
                Muon_hadEt03.push_back(Iso03.hadEt);
                Muon_nJets03.push_back(Iso03.nJets);
                Muon_nTracks03.push_back(Iso03.nTracks);
                Muon_sumPt03.push_back(Iso03.sumPt);
                Muon_emVetoEt03.push_back(Iso03.emVetoEt);
                Muon_hadVetoEt03.push_back(Iso03.hadVetoEt);
                Muon_trackerVetoPt03.push_back(Iso03.trackerVetoPt);
                
                Muon_emEt05.push_back(Iso05.emEt);
                Muon_hadEt05.push_back(Iso05.hadEt);
                Muon_nJets05.push_back(Iso05.nJets);
                Muon_nTracks05.push_back(Iso05.nTracks);
                Muon_sumPt05.push_back(Iso05.sumPt);
                Muon_hadVetoEt05.push_back(Iso05.hadVetoEt);
                Muon_trackerVetoPt05.push_back(Iso05.trackerVetoPt);
                Muon_emVetoEt05.push_back(Iso05.emVetoEt);
                
            } else { // if isolation is not valid use -1 as default
                Muon_emEt03.push_back(-1);
                Muon_hadEt03.push_back(-1);
                Muon_nJets03.push_back(-1);
                Muon_nTracks03.push_back(-1);
                Muon_sumPt03.push_back(-1);
                
                Muon_hadVetoEt03.push_back(-1);
                Muon_emVetoEt03.push_back(-1);
                Muon_trackerVetoPt03.push_back(-1);
                
                Muon_emEt05.push_back(-1);
                Muon_hadEt05.push_back(-1);
                Muon_nJets05.push_back(-1);
                Muon_nTracks05.push_back(-1);
                Muon_sumPt05.push_back(-1);
                
                Muon_emVetoEt05.push_back(-1);
                Muon_trackerVetoPt05.push_back(-1);
                Muon_hadVetoEt05.push_back(-1);
            }
            
        }


        if (!iEvent.isRealData())
        {
            Handle<vector<PileupSummaryInfo> >  PupInfo;
            iEvent.getByToken(puToken_, PupInfo);
            puN = PupInfo->begin()->getTrueNumInteractions();
        }
	  */
        
        
        ////Synch Tree//////
        /*   double maxPt =0; double maxPhi=0, maxEta=0; vector<pat::Muon> SyncSortedMu ;
         double maxTrPt =0; double maxTrPhi=0, maxTrEta=0; vector<reco::Track> SyncSortedTr ;
         for(uint i=0; i<SyncMu.size();i++){
         if(SyncMu.at(i).pt() > maxPt){
         maxPt  = SyncMu.at(i).pt();
         maxPhi = SyncMu.at(i).phi();
         maxEta = SyncMu.at(i).eta();
         SyncSortedMu.push_back(SyncMu.at(i));
         }
         }
         
         allmuons_pt.push_back(AllMuPt);
         
         leadmuon_pt.push_back(maxPt);
         leadmuon_eta.push_back(maxEta);
         leadmuon_phi.push_back(maxPhi);
         nmuons = SyncMu.size();
         nprimevtxs =vertices->size();
         
         edm::View<reco::Track>::const_iterator trIt  = trackCollection->begin();
         edm::View<reco::Track>::const_iterator trEnd = trackCollection->end();
         
         double AllTrPt=0;
         for (; trIt != trEnd; ++trIt)
         {
         
         const reco::Track track = (*trIt);
         if(  (track.pt()>1) && (fabs(track.eta())<2.4) && (track.hitPattern().trackerLayersWithMeasurement()>5) && (track.hitPattern().pixelLayersWithMeasurement()>1)  ){
         AllTrPt +=trIt->pt();
         if(track.pt() > maxTrPt){
         maxTrPt = track.pt();
         maxTrEta = track.eta();
         maxTrPhi= track.phi();
         }
         }
         }
         
         alltracks_pt.push_back(AllTrPt);
         leadtrack_pt.push_back(maxTrPt);
         leadtrack_eta.push_back(maxTrEta);
         leadtrack_phi.push_back(maxTrPhi);
         
         evt   = iEvent.id().event();
         run = iEvent.id().run();
         lumi = iEvent.luminosityBlock();
         */
        ///////SyncTree
        
        
        
        evt   = iEvent.id().event();
        run = iEvent.id().run();
        lumi = iEvent.luminosityBlock();
        
        //  SyncTree_->Fill();
        tree_->Fill();
        
        /*
         allmuons_pt.clear();
         alltracks_pt.clear();
         leadmuon_pt.clear();
         leadmuon_phi.clear();
         leadmuon_eta.clear();
         allmuons_pt.clear();
         leadtrack_pt.clear();
         leadtrack_eta.clear();
         leadtrack_phi.clear();
         evt= -999;
         run= -999;
         lumi= -999;
         nmuons = -999;
         */
        run= -999;
        evt= -999;
	lumi= -999;
        puN= -99;
        
	NGoodTriplets.clear();  
      GenParticle_PdgId.clear();
        GenParticle_Pt.clear();
        GenParticle_Eta.clear();
        GenParticle_Phi.clear();
        GenParticle_isDs.clear();
        GenParticle_isB.clear();
        GenParticle_isBdecay.clear();
        GenParticle_MotherPdgId.clear();
        
        MuonCollectionSize =0;
        MuonPt.clear();
        MuonEta.clear();
        MuonPhi.clear();
        MuonChi2P.clear();
        MuonChi2LocalPosition.clear();
        MuonGlbTrackProbability.clear();
        MuonTrkRelChi2.clear();
        MuonTrkKink.clear();
        Muon_PdgId.clear();
        Muon_MotherPdgId.clear();
        Muon_simFlavour.clear();
        MuonEnergy.clear();
        MuonCharge.clear();
        
        //Vtx position
        Muon_vx.clear();
        Muon_vy.clear();
        Muon_vz.clear();
        
        //MuonID
        Muon_isGlobal.clear();
        //Muon_isTracker.clear();
        Muon_isSoft.clear();
        Muon_isLoose.clear();
        Muon_isPF.clear();
        Muon_isRPCMuon.clear();
        Muon_isStandAloneMuon.clear();
        Muon_isTrackerMuon.clear();
        Muon_isCaloMuon.clear();
        Muon_isQualityValid.clear();
        Muon_isTimeValid.clear();
        Muon_isIsolationValid.clear();
        Muon_numberOfMatchedStations.clear();
        Muon_numberOfMatches.clear();
        
        //MuonTime
        Muon_timeAtIpInOut.clear();
        Muon_timeAtIpInOutErr.clear();
        
        //Muon inner + outer track
        Muon_GLnormChi2.clear();
        Muon_GLhitPattern_numberOfValidMuonHits.clear();
        
        Muon_trackerLayersWithMeasurement.clear();
        Muon_Numberofvalidpixelhits.clear();
        
        Muon_outerTrack_p.clear();
        Muon_outerTrack_eta.clear();
        Muon_outerTrack_phi.clear();
        Muon_outerTrack_normalizedChi2.clear();
        Muon_outerTrack_muonStationsWithValidHits.clear();
        Muon_innerTrack_p.clear();
        Muon_innerTrack_eta.clear();
        Muon_innerTrack_phi.clear();
        Muon_innerTrack_normalizedChi2.clear();
        Muon_QInnerOuter.clear();
        
        
        Muon_combinedQuality_updatedSta.clear();
        Muon_combinedQuality_trkKink.clear();
        Muon_combinedQuality_glbKink.clear();
        Muon_combinedQuality_trkRelChi2.clear();
        Muon_combinedQuality_staRelChi2.clear();
        Muon_combinedQuality_chi2LocalPosition.clear();
        Muon_combinedQuality_chi2LocalMomentum.clear();
        Muon_combinedQuality_localDistance.clear();
        Muon_combinedQuality_globalDeltaEtaPhi.clear();
        Muon_combinedQuality_tightMatch.clear();
        Muon_combinedQuality_glbTrackProbability.clear();
        
        Muon_calEnergy_em.clear();
        Muon_calEnergy_emS9.clear();
        Muon_calEnergy_emS25.clear();
        Muon_calEnergy_had.clear();
        Muon_calEnergy_hadS9.clear();
        
        Muon_segmentCompatibility.clear();
        Muon_caloCompatibility.clear();
        
        Muon_ptErrOverPt.clear();
        
        Muon_emEt03.clear();
        Muon_hadEt03.clear();
        Muon_nJets03.clear();
        Muon_nTracks03.clear();
        Muon_sumPt03.clear();
        Muon_hadVetoEt03.clear();
        Muon_emVetoEt03.clear();
        Muon_trackerVetoPt03.clear();
        
        Muon_emEt05.clear();
        Muon_hadEt05.clear();
        Muon_nJets05.clear();
        Muon_nTracks05.clear();
        Muon_sumPt05.clear();
        Muon_hadVetoEt05.clear();
        Muon_emVetoEt05.clear();
        Muon_trackerVetoPt05.clear();
   
        Track_pt.clear();
        Track_eta.clear();
        Track_phi.clear();
        Track_normalizedChi2.clear();
        Track_numberOfValidHits.clear();
        Track_charge.clear();
        Track_dxy.clear();
        Track_dz.clear();
        Track_dxyError.clear();
        Track_dzError.clear();       
        Track_vx.clear();
        Track_vy.clear();
        Track_vz.clear();
 
        PV_x.clear();
        PV_y.clear();
        PV_z.clear();
        PV_NTracks.clear();
        
        Trigger_l1name.clear();
	Trigger_l1decision.clear();
	Trigger_l1prescale.clear();
	
	Trigger_hltname.clear();
	Trigger_hltdecision.clear();
        
       
        /*
         Mu1_SimPt.clear();
         Mu1_SimEta.clear();
         Mu1_SimPhi.clear();
         
         Mu2_SimPt.clear();
         Mu2_SimEta.clear();
         Mu2_SimPhi.clear();
         
         Mu3_SimPt.clear();
         Mu3_SimEta.clear();
         Mu3_SimPhi.clear();
         
        GenMatchMu1_SimPhi.clear();
        GenMatchMu2_SimPhi.clear();
        GenMatchMu3_SimPhi.clear();
        
        GenMatchMu1_SimPt.clear();
        GenMatchMu2_SimPt.clear();
        GenMatchMu3_SimPt.clear();
        
        GenMatchMu1_SimEta.clear();
        GenMatchMu2_SimEta.clear();
        GenMatchMu3_SimEta.clear();
        
        GenMatchMu1_Pt.clear();
        GenMatchMu2_Pt.clear();
        GenMatchMu3_Pt.clear();
        
        GenMatchMu1_Eta.clear();
        GenMatchMu2_Eta.clear();
        GenMatchMu3_Eta.clear();
        
        GenMatchMu1_Phi.clear();
        GenMatchMu2_Phi.clear();
        GenMatchMu3_Phi.clear();
        
        TripletCollectionSize = -99;
        
        TripletVtx_x.clear();
        TripletVtx_y.clear();
        TripletVtx_z.clear();
        
        TripletVtx_Chi2.clear();
        TripletVtx_NDOF.clear();
        
        Triplet_Mass.clear();
        Triplet_Pt.clear();
        Triplet_Eta.clear();
        Triplet_Phi.clear();
        Triplet_Charge.clear();
        
        RefittedPV_x.clear();
        RefittedPV_y.clear();
        RefittedPV_z.clear();
        RefittedPV_NTracks.clear();
        RefittedPV_isValid.clear();
        //RefittedPV_Chi2.push_back(PVertex.);
        
        FlightDistPVSV.clear();
        FlightDistPVSV_Err.clear();
        FlightDistPVSV_Significance.clear();
        FlightDistPVSV_chi2.clear();
        */
        Mu01_Pt.clear();
        Mu01_Eta.clear();
        Mu01_Phi.clear();
        
        Mu02_Pt.clear();
        Mu02_Eta.clear();
        Mu02_Phi.clear();
        
        Tr_Pt.clear();
        Tr_Eta.clear();
        Tr_Phi.clear();
       
        Mu01_TripletIndex.clear();
        Mu02_TripletIndex.clear();
        Tr_TripletIndex.clear();

        Mu01_dRtriggerMatch.clear();
        Mu02_dRtriggerMatch.clear();
        Tr_dRtriggerMatch.clear();
	Mu1_dRtriggerMatch_Mu8_IP5.clear();
	Mu1_dRtriggerMatch_Mu8_IP6.clear();
        Mu1_dRtriggerMatch_Mu9_IP0.clear();
        Mu1_dRtriggerMatch_Mu9_IP3.clear();
        Mu1_dRtriggerMatch_Mu9_IP4.clear();
        Mu1_dRtriggerMatch_Mu9_IP5.clear();
        Mu1_dRtriggerMatch_Mu9_IP6.clear();
        Mu1_dRtriggerMatch_Mu12_IP6.clear();

	Mu1_dRtriggerMatch_Mu7.clear();
        Mu1_dRtriggerMatch_Mu8.clear();
	Mu2_dRtriggerMatch_Mu7.clear();
        Mu2_dRtriggerMatch_Mu8.clear();
	Mu3_dRtriggerMatch_Mu7.clear();
        Mu3_dRtriggerMatch_Mu8.clear();

	selectedTripletsIndex.clear();
        GenMatchMu01_SimPhi.clear();
        GenMatchMu02_SimPhi.clear();
        
        GenMatchMu01_SimPt.clear();
        GenMatchMu02_SimPt.clear();
        
        GenMatchMu01_SimEta.clear();
        GenMatchMu02_SimEta.clear();
        
        GenMatchMu01_Pt.clear();
        GenMatchMu02_Pt.clear();
        
        GenMatchMu01_Eta.clear();
        GenMatchMu02_Eta.clear();
        
        GenMatchMu01_Phi.clear();
        GenMatchMu02_Phi.clear();
   
        Triplet_mindca_iso.clear();
        Triplet_relativeiso.clear();
     
        TripletCollectionSize2 = -99;
        SelectedTripletsSize = -99;
        TripletVtx2_x.clear();
        TripletVtx2_y.clear();
        TripletVtx2_z.clear();
        
        TripletVtx2_Chi2.clear();
        TripletVtx2_NDOF.clear();
		
        Triplet2_Mass.clear();
        Triplet2_Pt.clear();
        Triplet2_Eta.clear();
        Triplet2_Phi.clear();
        Triplet2_Charge.clear();
        dxy_mu1.clear();
	dxy_mu2.clear();
	dxy_mu3.clear();
	dxyErr_mu1.clear();
	dxyErr_mu2.clear();
	dxyErr_mu3.clear();
        RefittedPV2_x.clear();
        RefittedPV2_y.clear();
        RefittedPV2_z.clear();
        RefittedPV2_NTracks.clear();
        RefittedPV2_isValid.clear();
        //RefittedPV2_Chi2.push_back(PVertex.);
        
        FlightDistPVSV2.clear();
        FlightDistPVSV2_Err.clear();
        FlightDistPVSV2_Significance.clear();
        FlightDistPVSV2_chi2.clear();
        PVCollection_Size =0;

	
        Mu1_dRtriggerMatch_2017.clear();
        Mu2_dRtriggerMatch_2017.clear();
        Mu3_dRtriggerMatch_2017.clear();

	MuonPt_HLT2017.clear();
        MuonEta_HLT2017.clear();
	MuonPhi_HLT2017.clear();
	MuonPt_HLT_BPMu7.clear();
	MuonEta_HLT_BPMu7.clear();
	MuonPhi_HLT_BPMu7.clear();
	MuonPt_HLT_BPMu8.clear();
	MuonEta_HLT_BPMu8.clear();
	MuonPhi_HLT_BPMu8.clear();
	MuonPt_HLT_BPMu8_IP6.clear();
	MuonEta_HLT_BPMu8_IP6.clear();
	MuonPhi_HLT_BPMu8_IP6.clear();
	MuonPt_HLT_BPMu8_IP5.clear();
	MuonEta_HLT_BPMu8_IP5.clear();
	MuonPhi_HLT_BPMu8_IP5.clear();
	MuonPt_HLT_BPMu9_IP0.clear();
	MuonEta_HLT_BPMu9_IP0.clear();
	MuonPhi_HLT_BPMu9_IP0.clear();
	MuonPt_HLT_BPMu3_IP3.clear();
	MuonEta_HLT_BPMu3_IP3.clear();
	MuonPhi_HLT_BPMu3_IP3.clear();
	MuonPt_HLT_BPMu3_IP4.clear();
	MuonEta_HLT_BPMu3_IP4.clear();
	MuonPhi_HLT_BPMu3_IP4.clear();
	MuonPt_HLT_BPMu3_IP5.clear();
	MuonEta_HLT_BPMu3_IP5.clear();
	MuonPhi_HLT_BPMu3_IP5.clear();
	MuonPt_HLT_BPMu3_IP6.clear();
	MuonEta_HLT_BPMu3_IP6.clear();
	MuonPhi_HLT_BPMu3_IP6.clear();
	MuonPt_HLT_BPMu12_IP6.clear();
	MuonPhi_HLT_BPMu12_IP6.clear();
	Track_pdgId.clear();
	Muon_SoftMVA_Val.clear();
	Muon_validMuonHitComb.clear();
	Muon_innerTrack_ValidFraction.clear();
	Muon_Numberofvalidtrackerhits.clear();
	Muon_innerTrack_highPurity.clear();
	}
    
    
    // ------------ method called once each job just before starting event loop  ------------
    void
    DsPhiPiTreeMakerMINI::beginJob()
    {
        
        hEvents = fs->make<TH1F>("hEvents","hEvents",10,0,10);
        hEventsAfterGoodCand= fs->make<TH1F>("hEventsAfterGoodCand","hEventsAfterGoodCand",10,0,10);
        tree_ = fs->make<TTree>("ntuple","LFVTau ntuple");
        
        
        tree_->Branch("evt", &evt);
        tree_->Branch("run", &run);
        tree_->Branch("lumi", &lumi);
	tree_->Branch("NGoodTriplets", &NGoodTriplets);
        tree_->Branch("nPileUpInt", &puN);
        
        tree_->Branch("GenParticle_PdgId", &GenParticle_PdgId);
        tree_->Branch("GenParticle_Pt", &GenParticle_Pt);
        tree_->Branch("GenParticle_Eta", &GenParticle_Eta);
        tree_->Branch("GenParticle_Phi", &GenParticle_Phi);
        tree_->Branch("GenParticle_isDs", &GenParticle_isDs);
        tree_->Branch("GenParticle_isB", &GenParticle_isB);
        tree_->Branch("GenParticle_isBdecay", &GenParticle_isBdecay);
        tree_->Branch("GenParticle_MotherPdgId", &GenParticle_MotherPdgId);
        
        tree_->Branch("MuonCollectionSize",&MuonCollectionSize);
        tree_->Branch("MuonPt",&MuonPt);
        tree_->Branch("MuonEnergy", &MuonEnergy);
        tree_->Branch("MuonCharge", &MuonCharge);
        tree_->Branch("MuonEta",&MuonEta);
        tree_->Branch("MuonPhi",&MuonPhi);
        tree_->Branch("Muon_PdgId", &Muon_PdgId);
        tree_->Branch("Muon_MotherPdgId", &Muon_MotherPdgId);
        tree_->Branch("Muon_simFlavour", &Muon_simFlavour);
        
        tree_->Branch("MuonChi2P", &MuonChi2P);
        tree_->Branch("MuonChi2LocalPosition", &MuonChi2LocalPosition);
        tree_->Branch("MuonGlbTrackProbability", &MuonGlbTrackProbability);
        tree_->Branch("MuonTrkRelChi2", &MuonTrkRelChi2);
        tree_->Branch("MuonTrkKink", &MuonTrkKink);
        
        
        
        //Vtx position
        tree_->Branch("Muon_vx", &Muon_vx);
        tree_->Branch("Muon_vy", &Muon_vy);
        tree_->Branch("Muon_vz", &Muon_vz);
        
        //MuonID
        tree_->Branch("Muon_isGlobal", &Muon_isGlobal);
        //tree_->Branch("Muon_isTracker", &Muon_isTracker);
        tree_->Branch("Muon_isSoft", &Muon_isSoft);
        tree_->Branch("Muon_isLoose", &Muon_isLoose);
        tree_->Branch("Muon_isPF", &Muon_isPF);
        tree_->Branch("Muon_isRPCMuon", &Muon_isRPCMuon);
        tree_->Branch("Muon_isStandAloneMuon", &Muon_isStandAloneMuon);
        tree_->Branch("Muon_isTrackerMuon", &Muon_isTrackerMuon);
        tree_->Branch("Muon_isCaloMuon", &Muon_isCaloMuon);
        tree_->Branch("Muon_isQualityValid", &Muon_isQualityValid);
        tree_->Branch("Muon_isTimeValid", &Muon_isTimeValid);
        tree_->Branch("Muon_isIsolationValid", &Muon_isIsolationValid);
        tree_->Branch("Muon_numberOfMatchedStations", &Muon_numberOfMatchedStations);
        tree_->Branch("Muon_numberOfMatches", &Muon_numberOfMatches);
        

        tree_->Branch("Muon_timeAtIpInOut",&Muon_timeAtIpInOut);
        tree_->Branch("Muon_timeAtIpInOutErr",&Muon_timeAtIpInOutErr);
        //Muon inner + outer track                                                                                                                                                                   
        tree_->Branch("Muon_GLnormChi2", &Muon_GLnormChi2);
        tree_->Branch("Muon_GLhitPattern_numberOfValidMuonHits", &Muon_GLhitPattern_numberOfValidMuonHits);
        
        tree_->Branch("Muon_trackerLayersWithMeasurement", &Muon_trackerLayersWithMeasurement);
        tree_->Branch("Muon_Numberofvalidpixelhits", &Muon_Numberofvalidpixelhits);
        
        tree_->Branch("Muon_outerTrack_p", &Muon_outerTrack_p);
        tree_->Branch("Muon_outerTrack_eta", &Muon_outerTrack_eta);
        tree_->Branch("Muon_outerTrack_phi", &Muon_outerTrack_phi);
        tree_->Branch("Muon_outerTrack_normalizedChi2", &Muon_outerTrack_normalizedChi2);
        tree_->Branch("Muon_outerTrack_muonStationsWithValidHits", &Muon_outerTrack_muonStationsWithValidHits);
        tree_->Branch("Muon_innerTrack_p", &Muon_innerTrack_p);
        tree_->Branch("Muon_innerTrack_eta", &Muon_innerTrack_eta);
        
        tree_->Branch("Muon_innerTrack_phi", &Muon_innerTrack_phi);
        tree_->Branch("Muon_innerTrack_normalizedChi2", &Muon_innerTrack_normalizedChi2);
        tree_->Branch("Muon_QInnerOuter", &Muon_QInnerOuter);
        
        
        tree_->Branch("Muon_combinedQuality_updatedSta", &Muon_combinedQuality_updatedSta);
        tree_->Branch("Muon_combinedQuality_trkKink", &Muon_combinedQuality_trkKink);
        tree_->Branch("Muon_combinedQuality_glbKink", &Muon_combinedQuality_glbKink);
        tree_->Branch("Muon_combinedQuality_trkRelChi2", &Muon_combinedQuality_trkRelChi2);
        tree_->Branch("Muon_combinedQuality_staRelChi2", &Muon_combinedQuality_staRelChi2);
        tree_->Branch("Muon_combinedQuality_chi2LocalPosition", &Muon_combinedQuality_chi2LocalPosition);
        tree_->Branch("Muon_combinedQuality_chi2LocalMomentum", &Muon_combinedQuality_chi2LocalMomentum);
        tree_->Branch("Muon_combinedQuality_localDistance", &Muon_combinedQuality_localDistance);
        tree_->Branch("Muon_combinedQuality_globalDeltaEtaPhi", &Muon_combinedQuality_globalDeltaEtaPhi);
        tree_->Branch("Muon_combinedQuality_tightMatch", &Muon_combinedQuality_tightMatch); 
        tree_->Branch("Muon_combinedQuality_glbTrackProbability", &Muon_combinedQuality_glbTrackProbability);
        
        tree_->Branch("Muon_calEnergy_em", &Muon_calEnergy_em);
        tree_->Branch("Muon_calEnergy_emS9", &Muon_calEnergy_emS9);
        tree_->Branch("Muon_calEnergy_emS25", &Muon_calEnergy_emS25);
        tree_->Branch("Muon_calEnergy_had", &Muon_calEnergy_had);
        tree_->Branch("Muon_calEnergy_hadS9", &Muon_calEnergy_hadS9);
        
        tree_->Branch("Muon_segmentCompatibility", &Muon_segmentCompatibility);
        tree_->Branch("Muon_caloCompatibility", &Muon_caloCompatibility);
        
        tree_->Branch("Muon_ptErrOverPt", &Muon_caloCompatibility);
        
        tree_->Branch("Muon_emEt03", &Muon_emEt03);
        tree_->Branch("Muon_hadEt03", &Muon_hadEt03);
        tree_->Branch("Muon_nJets03", &Muon_nJets03);
        tree_->Branch("Muon_nTracks03", &Muon_nTracks03);
        tree_->Branch("Muon_sumPt03", &Muon_sumPt03);
        tree_->Branch("Muon_hadVetoEt03", &Muon_hadVetoEt03);
        tree_->Branch("Muon_emVetoEt03", &Muon_emVetoEt03);
        tree_->Branch("Muon_trackerVetoPt03", &Muon_trackerVetoPt03);

        
        tree_->Branch("Muon_emEt05", &Muon_emEt05);
        tree_->Branch("Muon_hadEt05", &Muon_hadEt05);
        tree_->Branch("Muon_nJets05", &Muon_nJets05);
        tree_->Branch("Muon_nTracks05", &Muon_nTracks05);
        tree_->Branch("Muon_sumPt05", &Muon_sumPt05);
        tree_->Branch("Muon_hadVetoEt05", &Muon_hadVetoEt05);
        tree_->Branch("Muon_emVetoEt05", &Muon_emVetoEt05);
        tree_->Branch("Muon_trackerVetoPt05", &Muon_trackerVetoPt05);

        tree_->Branch("Track_pt", &Track_pt); 
        tree_->Branch("Track_eta", &Track_eta); 
        tree_->Branch("Track_phi", &Track_phi); 
        tree_->Branch("Track_normalizedChi2", &Track_normalizedChi2);
        tree_->Branch("Track_numberOfValidHits", &Track_numberOfValidHits);
        tree_->Branch("Track_charge", &Track_charge);
        tree_->Branch("Track_dxy", &Track_dxy);
        tree_->Branch("Track_dxyError", &Track_dxyError);
        tree_->Branch("Track_dz", &Track_dz);
        tree_->Branch("Track_dzError", &Track_dzError);
        tree_->Branch("Track_vx", &Track_vx);
        tree_->Branch("Track_vy", &Track_vy);
        tree_->Branch("Track_vz", &Track_vz);
	tree_->Branch("Track_pdgId", &Track_pdgId);
        tree_->Branch("PVCollection_Size", &PVCollection_Size);
        tree_->Branch("PV_x", &PV_x);
        tree_->Branch("PV_y", &PV_y);
        tree_->Branch("PV_z", &PV_z);
        tree_->Branch("PV_NTracks", &PV_NTracks);

	tree_->Branch("Trigger_l1name", &Trigger_l1name);
	tree_->Branch("Trigger_l1decision",&Trigger_l1decision);
	tree_->Branch("Trigger_l1prescale",&Trigger_l1prescale);
	
	tree_->Branch("Trigger_hltname",&Trigger_hltname);
	tree_->Branch("Trigger_hltdecision",&Trigger_hltdecision);       


        
        tree_->Branch("TripletCollectionSize2", &TripletCollectionSize2);  
	tree_->Branch("SelectedTripletsSize", &SelectedTripletsSize);
        tree_->Branch("Mu01_Pt",&Mu01_Pt);
        tree_->Branch("Mu01_Eta", &Mu01_Eta);
        tree_->Branch("Mu01_Phi", &Mu01_Phi);
        tree_->Branch("Mu01_dRtriggerMatch", &Mu01_dRtriggerMatch);
        tree_->Branch("Mu01_TripletIndex", &Mu01_TripletIndex);
        
        tree_->Branch("Mu02_Pt", &Mu02_Pt);
        tree_->Branch("Mu02_Eta", &Mu02_Eta);
        tree_->Branch("Mu02_Phi", &Mu02_Phi);
        tree_->Branch("Mu02_dRtriggerMatch", &Mu02_dRtriggerMatch);
        tree_->Branch("Mu02_TripletIndex", &Mu02_TripletIndex); 
        
        tree_->Branch("Tr_Pt", &Tr_Pt);
        tree_->Branch("Tr_Eta", &Tr_Eta);
        tree_->Branch("Tr_Phi", &Tr_Phi);
        tree_->Branch("Tr_dRtriggerMatch", &Tr_dRtriggerMatch);
        tree_->Branch("Tr_TripletIndex", &Tr_TripletIndex); 
        tree_->Branch("selectedTripletsIndex", &selectedTripletsIndex);
     
        tree_->Branch("GenMatchMu01_SimPt", &GenMatchMu01_SimPt);
        tree_->Branch("GenMatchMu02_SimPt", &GenMatchMu02_SimPt);
        
        tree_->Branch("GenMatchMu01_SimEta", &GenMatchMu01_SimEta);
        tree_->Branch("GenMatchMu02_SimEta", &GenMatchMu02_SimEta);
        
        tree_->Branch("GenMatchMu01_SimPhi", &GenMatchMu01_SimPhi);
        tree_->Branch("GenMatchMu02_SimPhi", &GenMatchMu02_SimPhi);
        
        tree_->Branch("GenMatchMu01_Pt", &GenMatchMu01_Pt);
        tree_->Branch("GenMatchMu02_Pt", &GenMatchMu02_Pt);
        
        tree_->Branch("GenMatchMu01_Eta", &GenMatchMu01_Eta);
        tree_->Branch("GenMatchMu02_Eta", &GenMatchMu02_Eta);
        
        tree_->Branch("GenMatchMu01_Phi", &GenMatchMu01_Phi);
        tree_->Branch("GenMatchMu02_Phi", &GenMatchMu02_Phi);
       
        tree_->Branch("Triplet_mindca_iso", &Triplet_mindca_iso);
        tree_->Branch("Triplet_relativeiso", &Triplet_relativeiso);
 
        tree_->Branch("TripletVtx2_x", &TripletVtx2_x);
        tree_->Branch("TripletVtx2_y", &TripletVtx2_y);
        tree_->Branch("TripletVtx2_z", &TripletVtx2_z);
        
        tree_->Branch("TripletVtx2_Chi2", &TripletVtx2_Chi2);
        tree_->Branch("TripletVtx2_NDOF", &TripletVtx2_NDOF);
        
        tree_->Branch("Triplet2_Mass", &Triplet2_Mass);
        tree_->Branch("Triplet2_Pt", &Triplet2_Pt);
        tree_->Branch("Triplet2_Eta", &Triplet2_Eta);
        tree_->Branch("Triplet2_Phi", &Triplet2_Phi);
        tree_->Branch("Triplet2_Charge", &Triplet2_Charge);
        
        tree_->Branch("RefittedPV2_x", &RefittedPV2_x);
        tree_->Branch("RefittedPV2_y", &RefittedPV2_y);
        tree_->Branch("RefittedPV2_z", &RefittedPV2_z);
        tree_->Branch("RefittedPV2_NTracks", &RefittedPV2_NTracks);
        tree_->Branch("RefittedPV2_isValid", &RefittedPV2_isValid);
        //RefittedPV2_Chi2.push_back(PVertex2.);                                                                                                                                                     
	tree_->Branch("Triplet_relativeiso2", &Triplet_relativeiso);        
        tree_->Branch("FlightDistPVSV2", &FlightDistPVSV2);
        tree_->Branch("FlightDistPVSV2_Err", &FlightDistPVSV2_Err);
        tree_->Branch("FlightDistPVSV2_Significance", &FlightDistPVSV2_Significance);
        tree_->Branch("FlightDistPVSV2_chi2", &FlightDistPVSV2_chi2);

        tree_->Branch("dxy_mu1", &dxy_mu1);
	tree_->Branch("dxy_mu2", &dxy_mu2);
	tree_->Branch("dxy_mu3", &dxy_mu3);
	tree_->Branch("dxyErr_mu1", &dxyErr_mu1);
	tree_->Branch("dxyErr_mu2", &dxyErr_mu2);
	tree_->Branch("dxyErr_mu3", &dxyErr_mu3);


	tree_->Branch("Mu1_dRtriggerMatch_Mu7", &Mu1_dRtriggerMatch_Mu7);
        tree_->Branch("Mu1_dRtriggerMatch_Mu8", &Mu1_dRtriggerMatch_Mu8);
	tree_->Branch("Mu2_dRtriggerMatch_Mu7", &Mu2_dRtriggerMatch_Mu7);
	tree_->Branch("Mu2_dRtriggerMatch_Mu8", &Mu2_dRtriggerMatch_Mu8);
	tree_->Branch("Mu3_dRtriggerMatch_Mu7", &Mu3_dRtriggerMatch_Mu7);
	tree_->Branch("Mu3_dRtriggerMatch_Mu8", &Mu3_dRtriggerMatch_Mu8);

	tree_->Branch("Mu1_dRtriggerMatch_Mu8_IP5", &Mu1_dRtriggerMatch_Mu8_IP5);
	tree_->Branch("Mu1_dRtriggerMatch_Mu8_IP6", &Mu1_dRtriggerMatch_Mu8_IP6);
        tree_->Branch("Mu1_dRtriggerMatch_Mu9_IP0", &Mu1_dRtriggerMatch_Mu9_IP0);
        tree_->Branch("Mu1_dRtriggerMatch_Mu9_IP3", &Mu1_dRtriggerMatch_Mu9_IP3);
        tree_->Branch("Mu1_dRtriggerMatch_Mu9_IP4", &Mu1_dRtriggerMatch_Mu9_IP4);
        tree_->Branch("Mu1_dRtriggerMatch_Mu9_IP5", &Mu1_dRtriggerMatch_Mu9_IP5);
        tree_->Branch("Mu1_dRtriggerMatch_Mu9_IP6", &Mu1_dRtriggerMatch_Mu9_IP6);
        tree_->Branch("Mu1_dRtriggerMatch_Mu12_IP6", &Mu1_dRtriggerMatch_Mu12_IP6);


	tree_->Branch("Mu1_dRtriggerMatch_2017", &Mu1_dRtriggerMatch_2017);
        tree_->Branch("Mu2_dRtriggerMatch_2017", &Mu2_dRtriggerMatch_2017);
        tree_->Branch("Mu3_dRtriggerMatch_2017", &Mu3_dRtriggerMatch_2017);

	tree_->Branch("Muon_SoftMVA_Val", &Muon_SoftMVA_Val);
	tree_->Branch("Muon_validMuonHitComb", &Muon_validMuonHitComb);
	tree_->Branch("Muon_innerTrack_ValidFraction", &Muon_innerTrack_ValidFraction);
	tree_->Branch("Muon_Numberofvalidtrackerhits", &Muon_Numberofvalidtrackerhits);
	tree_->Branch("Muon_innerTrack_highPurity", &Muon_innerTrack_highPurity);


	if( isBParking){
	  tree_->Branch("MuonPt_HLT_BPMu7", &MuonPt_HLT_BPMu7);
	  tree_->Branch("MuonEta_HLT_BPMu7", &MuonEta_HLT_BPMu7);
	  tree_->Branch("MuonPhi_HLT_BPMu7", &MuonPhi_HLT_BPMu7);
	  tree_->Branch("MuonPt_HLT_BPMu8", &MuonPt_HLT_BPMu8);
	  tree_->Branch("MuonEta_HLT_BPMu8", &MuonEta_HLT_BPMu8);
	  tree_->Branch("MuonPhi_HLT_BPMu8", &MuonPhi_HLT_BPMu8);
	  tree_->Branch("MuonPt_HLT_BPMu8_IP6", &MuonPt_HLT_BPMu8_IP6);
	  tree_->Branch("MuonEta_HLT_BPMu8_IP6", &MuonEta_HLT_BPMu8_IP6);
	  tree_->Branch("MuonPhi_HLT_BPMu8_IP6", & MuonPhi_HLT_BPMu8_IP6);
	  tree_->Branch("MuonPt_HLT_BPMu8_IP5", &MuonPt_HLT_BPMu8_IP5);
	  tree_->Branch("MuonEta_HLT_BPMu8_IP5", &MuonEta_HLT_BPMu8_IP5);
	  tree_->Branch("MuonPhi_HLT_BPMu8_IP5", &MuonPhi_HLT_BPMu8_IP5);
	  tree_->Branch("MuonPt_HLT_BPMu9_IP0", &MuonPt_HLT_BPMu9_IP0);
	  tree_->Branch("MuonEta_HLT_BPMu9_IP0", &MuonEta_HLT_BPMu9_IP0);
	  tree_->Branch("MuonPhi_HLT_BPMu9_IP0", &MuonPhi_HLT_BPMu9_IP0);
	  tree_->Branch("MuonPt_HLT_BPMu3_IP3", &MuonPt_HLT_BPMu3_IP3);
	  tree_->Branch("MuonEta_HLT_BPMu3_IP3", &MuonEta_HLT_BPMu3_IP3);

	  tree_->Branch("MuonPhi_HLT_BPMu3_IP3", &MuonPhi_HLT_BPMu3_IP3);
	  tree_->Branch("MuonPt_HLT_BPMu3_IP4", &MuonPt_HLT_BPMu3_IP4);

	  tree_->Branch("MuonEta_HLT_BPMu3_IP4", &MuonEta_HLT_BPMu3_IP4);
	  tree_->Branch("MuonPhi_HLT_BPMu3_IP4", &MuonPhi_HLT_BPMu3_IP4);
	  tree_->Branch("MuonPt_HLT_BPMu3_IP5", &MuonPt_HLT_BPMu3_IP5);
	  tree_->Branch("MuonEta_HLT_BPMu3_IP5", &MuonEta_HLT_BPMu3_IP5);
	  tree_->Branch("MuonPhi_HLT_BPMu3_IP5", &MuonPhi_HLT_BPMu3_IP5);
	  tree_->Branch("MuonPt_HLT_BPMu3_IP6", &MuonPt_HLT_BPMu3_IP6);
	  tree_->Branch("MuonEta_HLT_BPMu3_IP6", &MuonEta_HLT_BPMu3_IP6);
	  tree_->Branch("MuonPhi_HLT_BPMu3_IP6", &MuonPhi_HLT_BPMu3_IP6);
	  tree_->Branch("MuonPt_HLT_BPMu12_IP6", &MuonPt_HLT_BPMu12_IP6);
	  tree_->Branch("MuonEta_HLT_BPMu12_IP6", &MuonEta_HLT_BPMu12_IP6);
	  tree_->Branch("MuonPhi_HLT_BPMu12_IP6", &MuonPhi_HLT_BPMu12_IP6);
	}

        /*  SyncTree_ = fs->make<TTree>("t","Sync ntuple");
         SyncTree_ ->Branch("allmuons_pt",&allmuons_pt);
         SyncTree_->Branch("leadmuon_pt",&leadmuon_pt);
         SyncTree_->Branch("leadmuon_phi",&leadmuon_phi);
         SyncTree_->Branch("leadmuon_eta",&leadmuon_eta);
         SyncTree_->Branch("nmuons",&nmuons);
         SyncTree_->Branch("nprimevtxs",&nprimevtxs); 
         
         SyncTree_->Branch("leadtrack_pt", &leadtrack_pt);
         SyncTree_->Branch("leadtrack_eta", &leadtrack_eta);
         SyncTree_->Branch("leadtrack_phi", &leadtrack_phi);
         SyncTree_->Branch("alltracks_pt", &alltracks_pt);
         SyncTree_->Branch("evt", &evt);
         SyncTree_->Branch("run", &run);
         SyncTree_->Branch("lumi", &lumi);
         */
        
        
        
    }
    
    
    // ------------ method called once each job just after ending the event loop  ------------
    void 
    DsPhiPiTreeMakerMINI::endJob() 
    {
        //  tree_->GetDirectory()->cd();
        tree_->Write();
        
        //  SyncTree_->GetDirectory()->cd();
        //  SyncTree_->Write();
        
    }
    
    // ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
    
    
    void DsPhiPiTreeMakerMINI::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
        //The following says we do not know what parameters are allowed so do no validation
        // Please change this to state exactly what you do use, even if it is no parameters
        edm::ParameterSetDescription desc;
        desc.setUnknown();
        descriptions.addDefault(desc);
    }
    //define this as a plug-in
    DEFINE_FWK_MODULE(DsPhiPiTreeMakerMINI);

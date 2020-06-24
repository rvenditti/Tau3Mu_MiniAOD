import FWCore.ParameterSet.Config as cms

import copy
from HLTrigger.HLTfilters.hltHighLevel_cfi import *
from PhysicsTools.PatAlgos.producersLayer1.genericParticleProducer_cfi import patGenericParticles
from PhysicsTools.PatAlgos.producersLayer1.muonProducer_cfi import patMuons
from PhysicsTools.PatAlgos.selectionLayer1.muonSelector_cfi import *
#from PhysicsTools.PatAlgos.triggerLayer1.triggerEventProducer_cfi import *
#from PhysicsTools.PatAlgos.triggerLayer1.triggerProducer_cfi import *
#from PhysicsTools.PatAlgos.tools.trigTools import *


Tau3MuHLTFilter = copy.deepcopy(hltHighLevel)
Tau3MuHLTFilter.throw = cms.bool(False)
Tau3MuHLTFilter.HLTPaths = ["HLT_Mu8*","HLT_Mu7*","HLT_Mu9_IP*","HLT_Mu10p5_IP*", "HLT_Mu12_IP*","HLT_Mu8p5*"]
#list taken from https://github.com/cms-sw/cmssw/blob/CMSSW_9_2_X/HLTrigger/Configuration/tables/GRun.txt


looseMuons = cms.EDFilter("PATMuonSelector",
                          src = cms.InputTag("slimmedMuons"),
                          #cut = cms.string('pt > 0.5 &&  abs(eta)<2.4 && (innerTrack().isNonnull) && (charge!=0) && (innerTrack().hitPattern().numberOfValidPixelHits()>0) && innerTrack.quality("highPurity")'), 
                          cut = cms.string('pt > 2 &&  abs(eta)<2.4 && (innerTrack().isNonnull) && (charge!=0) && (innerTrack().hitPattern().numberOfValidPixelHits()>0)'), 
                          filter = cms.bool(True)                                
)

TwoMuonsFilter = cms.EDFilter("CandViewCountFilter",
                             src = cms.InputTag("looseMuons"),
                              minNumber = cms.uint32(2),
                             #filter = cms.bool(True)
)


TwoMuonsCand = cms.EDProducer("CandViewShallowCloneCombiner",
                         checkCharge = cms.bool(False),
                         #cut = cms.string('(mass < 10) && (mass >0.5)  && (abs(charge)=1) && (abs(daughter(0).vz - daughter(1).vz) < 1) && (abs(daughter(1).vz - daughter(2).vz) < 1) && (abs(daughter(0).vz - daughter(2).vz) < 1)'),
                         #cut = cms.string('(mass < 10) && (mass >0.5)  && (abs(charge)=1)'),       
                              cut = cms.string('(abs(charge)=0)'),       
                         decay = cms.string("looseMuons looseMuons")
) 

TwoMuonsCandFilter = cms.EDFilter("CandViewCountFilter",
                                    src = cms.InputTag("TwoMuonsCand"),
                                    minNumber = cms.uint32(1),
                                    #filter = cms.bool(True)
)


LooseTrack = cms.EDFilter("CandPtrSelector",
                          src = cms.InputTag("packedPFCandidates"),
                          cut = cms.string("pt > 2 &&  abs(eta)<2.4 &&  (charge!=0) && hasTrackDetails() && trackerLayersWithMeasurement()>5 && pixelLayersWithMeasurement()>=1"),
                          #filter = cms.bool(True)                                
)


OneTrackFilter  = cms.EDFilter("CandViewCountFilter",
                               src = cms.InputTag("LooseTrack"),
                               minNumber = cms.uint32(1),
                               #filter = cms.bool(True)
)



DiMuonCand  = cms.EDProducer("CandViewShallowCloneCombiner",
                             checkCharge = cms.bool(False),
                             #cut = cms.string('(mass < 10) && (mass >0.5)  && (abs(charge)=1) && (abs(daughter(0).vz - daughter(1).vz) < 1) && (abs(daughter(1).vz - daughter(2).vz) < 1) && (abs(daughter(0).vz - daughter(2).vz) < 1)'),
                             cut = cms.string('(abs(charge)=0) && (mass < 1.5) && (mass >0.5)'),
                              decay = cms.string("looseMuons looseMuons")
)



DiMuonCandFilter = cms.EDFilter("CandViewCountFilter",
                                src = cms.InputTag("DiMuonCand"),
                                minNumber = cms.uint32(1),
                                #filter = cms.bool(True)
)


TwoMuonsOneTrackCand = cms.EDProducer("CandViewShallowCloneCombiner",
                                      checkCharge = cms.bool(False),
                                      cut = cms.string(' (abs(charge)=1) && ((daughter(0).charge+daughter(1).charge)==0) && (daughter(0).eta!=daughter(1).eta) && (daughter(2).eta!=daughter(1).eta) && (daughter(2).eta!=daughter(0).eta) && (mass < 3.0) && (mass >0.8)'),
                                      decay = cms.string("looseMuons looseMuons LooseTrack")
)



TwoMuonsOneTrackKalmanVtxFit = cms.EDProducer("KalmanVertexFitCompositeCandProducer",
                                              src = cms.InputTag("TwoMuonsOneTrackCand"),
                                              #cut = cms.string('mass <5'),                                                                                       
                                              )



TwoMuonsOneTrackCandFilter = cms.EDFilter("CandViewCountFilter",
                                    src = cms.InputTag("TwoMuonsOneTrackCand"),
                                    minNumber = cms.uint32(1),
                                    #filter = cms.bool(True)
)

########################Define Histograms########################
InitialPlots = cms.EDAnalyzer('SimpleEventCounter',
                                   muonsInputTag = cms.InputTag("slimmedMuons"),
                                   )

PlotsMatchedMuonsHLT = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("slimmedMuons"),
                                   )

PlotsAfterTrigger = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("slimmedMuons"),
                                   )

PlotsAfterOnePFCand = cms.EDAnalyzer('RecoMuonAnalyzer',
                                     muonsInputTag = cms.InputTag("slimmedMuons"),
                                 )



PlotsAfterDiMuonCand = cms.EDAnalyzer('RecoMuonAnalyzer',
                                     muonsInputTag = cms.InputTag("looseMuons"),
                                     )

PlotsAfter2Mu1Track = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("looseMuons"),
                                   )

PlotsAfterPhiPiCand = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("looseMuons"),
                                   )


PlotsAfterPhiPiCandSel = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("looseMuons"),
                                   )
PlotsAfterLooseMuon = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("looseMuons"),
                                   )



TwoMuOneTrackSelSeq = cms.Sequence(InitialPlots *
                               Tau3MuHLTFilter *
                               PlotsAfterTrigger *
                               LooseTrack *
                               OneTrackFilter *
                               PlotsAfterOnePFCand *   
                               looseMuons *
                               PlotsAfterLooseMuon *
                               TwoMuonsFilter *
                               DiMuonCand *
                               DiMuonCandFilter *
                               PlotsAfterDiMuonCand *
                               #LooseTrack *
                               TwoMuonsOneTrackCand *
                               TwoMuonsOneTrackKalmanVtxFit *
                               PlotsAfter2Mu1Track *
                               TwoMuonsOneTrackCandFilter *
                               PlotsAfterPhiPiCandSel 
                               )









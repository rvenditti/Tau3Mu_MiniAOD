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
#Tau3MuHLTFilter.HLTPaths = ["HLT_DoubleMu3_Trk_Tau3mu*", "HLT_DoubleMu3_TkMu_DsTau3Mu_v*", "HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass_v*"]
Tau3MuHLTFilter.HLTPaths = ["HLT_Mu8*","HLT_Mu7*","HLT_Mu9_IP*","HLT_Mu10p5_IP*", "HLT_Mu12_IP*","HLT_Mu8p5*"]
#Tau3MuHLTFilter.HLTPaths = ["HLT_DoubleMu3_TkMu_DsTau3Mu_v*"]
#list taken from https://github.com/cms-sw/cmssw/blob/CMSSW_9_2_X/HLTrigger/Configuration/tables/GRun.txt
#Tau3MuHLTFilter.HLTPaths = ["HLT_Mu9_IP*"]

PatMuons = patMuons.clone(
    src = cms.InputTag("muons"),
    useParticleFlow = cms.bool( False ),
    #embedHighLevelSelection = cms.bool(True),
    computeMiniIso = cms.bool(False), 
    computeMuonMVA= cms.bool(False),
    computeSoftMuonMVA = cms.bool(True),
    addTriggerMatching = cms.bool(False),
    addGenMatch   = cms.bool(False),
    embedGenMatch = cms.bool(True),
)



looseMuons = cms.EDFilter("PATMuonSelector",
                          src = cms.InputTag("slimmedMuons"),
                          cut = cms.string('pt > 2 &&  abs(eta)<2.4 && (innerTrack().isNonnull) && (charge!=0) && (innerTrack().hitPattern().numberOfValidPixelHits()>0)'), 
                          filter = cms.bool(True)                                
)

tightMuons = cms.EDFilter("PATMuonSelector",
                          src = cms.InputTag("looseMuons"),
                          cut = cms.string('isGlobalMuon()'),
                          filter = cms.bool(True)
)


TwoMuonsFilter = cms.EDFilter("CandViewCountFilter",
                              src = cms.InputTag("looseMuons"),
                              minNumber = cms.uint32(3),
                             #filter = cms.bool(True)
)

TightMuonsFilter = cms.EDFilter("CandViewCountFilter",
                                src = cms.InputTag("tightMuons"),
                                minNumber = cms.uint32(1),
                                #filter = cms.bool(True)                                                                                                 
)

ThreeMuonsCand = cms.EDProducer("CandViewShallowCloneCombiner",
                            checkCharge = cms.bool(False),
                                #cut = cms.string('(mass < 10) && (mass >0.5)  && (abs(charge)=1) && (abs(daughter(0).vz - daughter(1).vz) < 1) && (abs(daughter(1).vz - daughter(2).vz) < 1) && (abs(daughter(0).vz - daughter(2).vz) < 1)'),
                                #cut = cms.string('(abs(charge)=1)'),       
                                #decay = cms.string("tightMuons looseMuons looseMuons"),
                                decay = cms.string("looseMuons looseMuons looseMuons"),
                                cut = cms.string('(mass < 3.0) && (mass >0.8) && (abs(charge)=1)'),       

) 

ThreeMuonsCandFilter = cms.EDFilter("CandViewCountFilter",
                                    src = cms.InputTag("ThreeMuonsCand"),
                                    minNumber = cms.uint32(1),
                                    #filter = cms.bool(True)
)

ThreeMuonsVtxKinFit = cms.EDProducer("KinematicVertexFitCompositeCandProducer",
                                     src = cms.InputTag("ThreeMuonsCand")
                                     )

ThreeMuonsVtxKalmanFit = cms.EDProducer("KalmanVertexFitCompositeCandProducer",
                                        src = cms.InputTag("ThreeMuonsCand"),
                                        #cut = cms.string('mass <5'), 
                                        #cut = cms.string('(vertexChi2 < 40) && (vertexNdof == 3) && (mass <5)'),
                                        ##filter = cms.bool(True)
                                        )
#GoodThreeMuonsVtxKalmanFit = cms.EDFilter("CompositeCandSelector",
#                                            src = cms.InputTag("ThreeMuonsVtxKalmanFit"),
#                                            cut = cms.string('(vertexChi2 < 40) && (vertexNdof == 3)'),
#                                            filter = cms.bool(True)
#                                            )

########################Define Histograms########################
InitialPlots = cms.EDAnalyzer('SimpleEventCounter',
                                   muonsInputTag = cms.InputTag("slimmedMuons"),
                                   )


PlotsAfterTrigger = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("slimmedMuons"),
                                   )

PlotsAfterLooseMuon = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("looseMuons"),
                                   )

PlotsAfterTwoMuons = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("looseMuons"),
                                   )

PlotsAfterTightMuons = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("tightMuons"),
                                   )

PlotsAfterTightMuonsFilter = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("tightMuons"),
                                   )

PlotsAfterTauCand = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("looseMuons"),
                                   )


PlotsAfterTauCandSel = cms.EDAnalyzer('RecoMuonAnalyzer',
                                   muonsInputTag = cms.InputTag("looseMuons"),
                                   )


ThreeMuonSelSeq = cms.Sequence(InitialPlots *
                               Tau3MuHLTFilter *
                               #PatMuons *
                               PlotsAfterTrigger *
                               looseMuons *
                               PlotsAfterLooseMuon *
                               #tightMuons*
                               #TightMuonsFilter*  
                               TwoMuonsFilter *
                               PlotsAfterTwoMuons*
                               #PlotsAfterTightMuons*
                               #TightMuonsFilter*
                               #PlotsAfterTightMuonsFilter*
                               ThreeMuonsCand *
                               ThreeMuonsCandFilter *
                               PlotsAfterTauCand *
                               ThreeMuonsVtxKalmanFit 
                               #GoodThreeMuonsVtxKalmanFit *
                               #PlotsAfterTauCandSel
                               )









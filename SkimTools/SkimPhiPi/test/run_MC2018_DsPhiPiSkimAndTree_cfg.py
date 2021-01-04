import FWCore.ParameterSet.Config as cms

process = cms.Process('DsPhiPiSkim')

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
#process.load('DsPhiPiTreeMaker.DsPhiPiTreeMaker.DsPhiPiSkimAOD_cff')
#process.load('DsPhiPiTreeMaker.DsPhiPiTreeMaker.DsPhiPiMuMuPi_BParking_cff')
process.load('SkimTools.SkimPhiPi.DsPhiPiMuMuPi_miniAOD_cff')

process.GlobalTag.globaltag = '102X_upgrade2018_realistic_v21' #MC2018
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        #Official MC DsPhiPi 2018 rereco --> /DsToPhiPi_ToMuMu_MuFilter_TuneCP5_13TeV-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM
        '/store/mc/RunIIAutumn18MiniAOD/DsToPhiPi_ToMuMu_MuFilter_TuneCP5_13TeV-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/280000/F4B328B9-59B3-AF4B-A6DF-89B9008CF78C.root',
        #'/store/mc/RunIIAutumn18MiniAOD/DsToPhiPi_ToMuMu_MuFilter_TuneCP5_13TeV-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/280000/E73118AF-8559-664C-ADBF-054272ABB0EE.root',
        #'/store/mc/RunIIAutumn18MiniAOD/DsToPhiPi_ToMuMu_MuFilter_TuneCP5_13TeV-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/280000/BDC74239-A1F0-1C41-A3F1-8A7039472187.root',
        #'/store/mc/RunIIAutumn18MiniAOD/DsToPhiPi_ToMuMu_MuFilter_TuneCP5_13TeV-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/280000/B3B63CC2-C394-7F4B-B8B5-AA201C25BA0F.root',
        #'/store/mc/RunIIAutumn18MiniAOD/DsToPhiPi_ToMuMu_MuFilter_TuneCP5_13TeV-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/280000/AD627BAA-400A-F64F-A339-BEC308E0AD54.root',
        #'/store/mc/RunIIAutumn18MiniAOD/DsToPhiPi_ToMuMu_MuFilter_TuneCP5_13TeV-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/280000/A4CDAE59-D894-184C-844B-89C7780EDFF1.root',
        #'/store/mc/RunIIAutumn18MiniAOD/DsToPhiPi_ToMuMu_MuFilter_TuneCP5_13TeV-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/280000/9CEDDC25-2F5C-5644-99FE-E77DBB199767.root',
        '/store/mc/RunIIAutumn18MiniAOD/DsToPhiPi_ToMuMu_MuFilter_TuneCP5_13TeV-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/280000/8DC7B013-41C1-D740-BF91-4A0A2A856C2E.root'

	)
)


process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("Tree_PhiPi.root"))



process.unpackedPatTrigger = cms.EDProducer("PATTriggerObjectStandAloneUnpacker",
    patTriggerObjectsStandAlone = cms.InputTag( 'slimmedPatTrigger' ),
    triggerResults              = cms.InputTag( 'TriggerResults::HLT' ),
    unpackFilterLabels = cms.bool(True)
)

process.Tree3Mu = cms.EDAnalyzer("DsPhiPiTreeMakerMINI",
                                 isMcLabel = cms.untracked.bool(True),
                                 isAnaLabel = cms.untracked.bool(True),
                                 is2016Label = cms.untracked.bool(True),
                                 is2017Label = cms.untracked.bool(True),
                                 is2018Label = cms.untracked.bool(True),
                                 isBParkingLabel = cms.untracked.bool(False),
                                 #is3MuLabel = cms.untracked.bool(False),
                                 muonLabel=cms.InputTag("looseMuons"),
                                 VertexLabel=cms.InputTag("offlineSlimmedPrimaryVertices"),
                                 TracksLabel=cms.InputTag("LooseTrack"),
                                 genParticleLabel=cms.InputTag("prunedGenParticles"),
                                 #Cand3MuLabel=cms.InputTag("ThreeMuonsVtxKalmanFit"),
                                 Cand2Mu1TrackLabel=cms.InputTag("TwoMuonsOneTrackKalmanVtxFit"),
                                 DiMuonLabel=cms.InputTag("DiMuonsVtxFit"),
                                 pileupSummary = cms.InputTag("slimmedAddPileupInfo"),
                                 triggerResults = cms.InputTag("TriggerResults", "", "HLT"),
                                 #triggerSummary = cms.InputTag("hltTriggerSummaryAOD", "", "HLT"),
                                 objects = cms.InputTag("unpackedPatTrigger"),
                                 AlgInputTag = cms.InputTag( "gtStage2Digis" )
)



process.DsPhiPiSkim = cms.Path( process.TwoMuOneTrackSelSeq*
                                process.unpackedPatTrigger* 
                                process.Tree3Mu
)




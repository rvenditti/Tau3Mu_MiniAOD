import FWCore.ParameterSet.Config as cms

process = cms.Process('Tau3MuSkim')

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
process.load("SkimTools.SkimTau3Mu.Tau3MuSkim_miniAOD_cff")

#process.GlobalTag.globaltag = '94X_mc2017_realistic_v14'
process.GlobalTag.globaltag = '102X_dataRun2_v13' #data2018 A-C
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

#Begin processing the 25271st record. Run 320012, Event 56448719, LumiSection 36 on stream 0 at 20-Apr-2020 18:53:30.862 CEST
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'root://xrootd-cms.infn.it///store/data/Run2018C/DoubleMuonLowMass/MINIAOD/17Sep2018-v1/90000/F5DA5914-34B8-F647-B5A2-1AE50E687E3C.root',  
        #'root://xrootd-cms.infn.it//store/data/Run2018A/DoubleMuonLowMass/AOD/17Sep2018-v1/120000/3C6EECC5-5787-AC43-ACF0-3BE40CE1291C.root',
        #root://xrootd-cms.infn.it//store/data/Run2017F/DoubleMuonLowMass/AOD/09May2018-v1/80000/AECC4C56-BAB0-E811-B92A-008CFA1979AC.root'
        #"file:/lustrehome/venditti/TestMiniAOD2017/CMSSW_9_4_4/src/CrabSubmission/MC/PiGun_RECO.root"
        #"file:/lustre/cms/store/user/rosma/PionGun_Pt0to30GeV/PiGun_13TeV_MC2017_RECO/190313_143541/0000/PiGun_RECO_979.root"
        #'file:/lustre/cms/store/user/fsimone/DsTau3Mu/crab_crab_DsTau3Mu__13TeV_MC2016_RECO/190120_140919/0001/custom_DsTau3Mu_13TeV_RECO_crab350_1010.root',


    ),
            #eventsToProcess = cms.untracked.VEventRange('320012:56448719')
)


process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("TreeData.root"))




process.unpackedPatTrigger = cms.EDProducer("PATTriggerObjectStandAloneUnpacker",
    patTriggerObjectsStandAlone = cms.InputTag( 'slimmedPatTrigger' ),
    triggerResults              = cms.InputTag( 'TriggerResults::HLT' ),
    unpackFilterLabels = cms.bool(True)
)

process.TreeMakerBkg = cms.EDAnalyzer("MiniAnaTau3Mu",
                                      isMcLabel = cms.untracked.bool(False),
                                      isAnaLabel = cms.untracked.bool(True),
                                      is2016Label = cms.untracked.bool(True),
                                      is2017Label = cms.untracked.bool(True),
                                      is2018Label = cms.untracked.bool(True),
                                      isBParkingLabel = cms.untracked.bool(False),
                                      muonLabel=cms.InputTag("looseMuons"),
                                      photonLabel=cms.InputTag("slimmedPhotons"),
                                      VertexLabel=cms.InputTag("offlineSlimmedPrimaryVertices"),
                                      genParticleLabel=cms.InputTag("prunedGenParticles"),
                                      pileupSummary = cms.InputTag("slimmedAddPileupInfo"),
                                      Cand3MuLabel=cms.InputTag("ThreeMuonsVtxKalmanFit"),
                                      triggerResults = cms.InputTag("TriggerResults", "", "HLT"),
                                      objects = cms.InputTag("unpackedPatTrigger"),
                                      AlgInputTag = cms.InputTag( "gtStage2Digis" )
                                      
)




process.Tau3MuSkim = cms.Path(process.ThreeMuonSelSeq*
                              process.unpackedPatTrigger*
                              process.TreeMakerBkg
                     )






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
#process.load("SkimTools.SkimTau3Mu.Tau3MuSkim_miniAOD_cff")
process.load("SkimTools.SkimTau3Mu.Tau3MuSkim_miniAOD_BParking_Skim1_cff") 
process.GlobalTag.globaltag = '102X_dataRun2_v11' #data2018 
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

#Run 316995, Event 853072535, LumiSection 565 on stream 0 at 17-Apr-2020 15:26:52.399 UTC

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
         'root://cmsxrootd.fnal.gov//store/data/Run2018A/ParkingBPH4/MINIAOD/05May2019-v1/270000/46876D1C-188D-7841-BE43-EEBD1DDDE57D.root',
        'root://cmsxrootd.fnal.gov//store/data/Run2018A/ParkingBPH4/MINIAOD/05May2019-v1/270000/460356CA-50A9-7A46-AE3A-C0C0F623A20A.root',
        # 'root://cmsxrootd.fnal.gov//store/data/Run2018A/ParkingBPH1/MINIAOD/05May2019-v1/20000/E2D83C0F-8AE1-6441-86FB-D116359E8ACF.root',
       #'root://xrootd-cms.infn.it///store/data/Run2018C/DoubleMuonLowMass/MINIAOD/17Sep2018-v1/90000/F5DA5914-34B8-F647-B5A2-1AE50E687E3C.root',
       # 'root://cmsxrootd.fnal.gov//store/data/Run2018A/ParkingBPH1/MINIAOD/05May2019-v1/280003/FEE7FDF4-F180-904F-B4EC-ACADF3B2FF13.root', 
        #'root://cmsxrootd.fnal.gov//store/data/Run2018A/ParkingBPH3/MINIAOD/05May2019-v1/100000/D3516780-29EB-4E4B-83EB-A2C166A15EED.root',
        #'root://cmsxrootd.fnal.gov//store/data/Run2018A/ParkingBPH1/MINIAOD/05May2019-v1/280003/FE7EE683-58D8-2B40-9AB5-73F4D2F4CBFC.root',
       # 'root://cmsxrootd.fnal.gov//store/data/Run2018A/ParkingBPH1/AOD/05May2019-v1/280013/BC7F8403-4E85-5C4C-8A46-40E88B2DC7C2.root',
        #'root://cmsxrootd.fnal.gov//store/data/Run2018A/ParkingBPH1/AOD/05May2019-v1/280013/AEC067D7-F97E-A34A-993C-B20E048E0250.root',
        #'root://xrootd-cms.infn.it//store/data/Run2018A/DoubleMuonLowMass/AOD/17Sep2018-v1/120000/3C6EECC5-5787-AC43-ACF0-3BE40CE1291C.root',
        #root://xrootd-cms.infn.it//store/data/Run2017F/DoubleMuonLowMass/AOD/09May2018-v1/80000/AECC4C56-BAB0-E811-B92A-008CFA1979AC.root'


    ),
            #eventsToProcess = cms.untracked.VEventRange('316995:853072535') 
)


process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("TreeData_SkimNew.root"))

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
                                      isBParkingLabel = cms.untracked.bool(True),
                                      muonLabel=cms.InputTag("looseMuons"),
                                      VertexLabel=cms.InputTag("offlineSlimmedPrimaryVertices"),
                                      genParticleLabel=cms.InputTag("prunedGenParticles"),
                                      pileupSummary = cms.InputTag("slimmedAddPileupInfo"),
                                      Cand3MuLabel=cms.InputTag("ThreeMuonsVtxKalmanFit"),
                                      triggerResults = cms.InputTag("TriggerResults", "", "HLT"),
                                      #triggerSummary = cms.InputTag("hltTriggerSummaryAOD", "", "HLT"),
                                      #objects = cms.InputTag("slimmedPatTrigger"),
                                      objects = cms.InputTag("unpackedPatTrigger"),
                                      AlgInputTag = cms.InputTag( "gtStage2Digis" )
)




process.Tau3MuSkim = cms.Path(process.ThreeMuonSelSeq*
                              process.unpackedPatTrigger*
                              process.TreeMakerBkg
                     )







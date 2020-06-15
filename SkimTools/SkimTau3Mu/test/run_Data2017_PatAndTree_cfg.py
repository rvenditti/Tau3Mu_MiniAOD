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
process.GlobalTag.globaltag = '94X_dataRun2_ReReco_EOY17_v6' #data2017 
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

#Begin processing the 25271st record. Run 320012, Event 56448719, LumiSection 36 on stream 0 at 20-Apr-2020 18:53:30.862 CEST
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        #data2017C --> /DoubleMuonLowMass/Run2017C-17Nov2017-v1/MINIAOD
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/DA4C28DA-55EC-E711-9AB0-A4BF0126D1BB.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/DA23EEFA-5FED-E711-84E4-1866DA87EE25.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/D8D859E9-E4EC-E711-91D6-842B2B42B582.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/D8A8C3B4-B7EC-E711-9A0D-3417EBE743C0.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/D63A987B-C8EC-E711-875C-B083FED4239B.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/D6350533-1CF2-E711-9088-008CFAC93D24.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/D4C034FB-45F2-E711-85C1-008CFA197D48.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/D4AB8E50-10F2-E711-B182-008CFAC91CA4.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/D2CB8BFE-5FED-E711-802C-1866DA879EDE.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/D0DA4502-C4EB-E711-A4C4-3417EBE743C0.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/D0C72DB4-CEEB-E711-8D05-008CFAC93CB8.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CEC75992-07EC-E711-9898-00266CF3E0BC.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CE1C35F1-5EEC-E711-85C6-0025904B577C.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CCFEBC82-2DF2-E711-9613-008CFAC91960.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CC3FC1F8-9AEC-E711-8D86-00266CF32CF0.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CC1C22EB-EDEB-E711-A7CB-3417EBE743C0.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CAD5951A-43EC-E711-B30F-0025901D4854.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CAD10C44-92EC-E711-B46A-D4AE52E7F60F.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CACB675C-60ED-E711-A3DC-0CC47A00AA80.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CAB9E310-9EEB-E711-9B75-002590FD5E3E.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CA63249C-CDEB-E711-A811-002590DE3AC0.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CA398CE1-20ED-E711-8B22-F01FAFD1BA8A.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/CA021149-DBEB-E711-A0F2-3417EBE743C0.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/C8F8CEA4-FDED-E711-8B2D-D4AE526A0922.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/C8BFEEE6-8FF1-E711-BB2D-0CC47A7E6A4C.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/C8B96067-58EC-E711-AF41-008CFAE45380.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/C8A898B7-85ED-E711-B9BA-0CC47A00934A.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/C83C4220-1DEC-E711-9FB0-3417EBE7446B.root',
        'root://xrootd-cms.infn.it///store/data/Run2017C/DoubleMuonLowMass/MINIAOD/17Nov2017-v1/60000/C6FB4CCA-32EC-E711-AA06-00266CF3E0BC.root',

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






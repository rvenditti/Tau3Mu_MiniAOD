import FWCore.ParameterSet.Config as cms

process = cms.Process('pldrawer')

process.load("FWCore.MessageService.MessageLogger_cfi")

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
                                'file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_99.root',
                            ))

process.printTree = cms.EDAnalyzer("ParticleListDrawer",
                                   maxEventsToPrint = cms.untracked.int32(1),
                                   printVertex = cms.untracked.bool(False),
                                   printOnlyHardInteraction = cms.untracked.bool(False), # Print only status=3 particles. This will not work for Pythia8, which does not have any such particles.
                                   src = cms.InputTag("genParticles")
                               )

process.p = cms.Path(process.printTree)

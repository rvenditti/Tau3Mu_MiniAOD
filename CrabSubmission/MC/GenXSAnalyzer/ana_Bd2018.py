# Auto generated configuration file
# using: 
# Revision: 1.381.2.7 
# Source: /local/reps/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: Configuration/GenProduction/python/EightTeV/Hadronizer_MgmMatchTuneZ2star_8TeV_madgraph_tauola_cff.py --step GEN --beamspot Realistic8TeVCollision --conditions START52_V9::All --pileup NoPileUp --datamix NODATAMIXER --eventcontent RAWSIM --datatier GEN -n -1 --python_filename=Temp_Hadronizer_5498_1.py --filein root://eoscms//eos/cms//store/lhe/5498/DY1JetsToLL_M-50_8TeV-madgraph_10001.lhe --no_output --no_exec
import FWCore.ParameterSet.Config as cms
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
options.parseArguments()

process = cms.Process('ana')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic8TeVCollision_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:mc', '')
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.MessageLogger.cerr.FwkReport.reportEvery = 10000

process.source = cms.Source(
    "PoolSource",
    #fileNames  = cms.untracked.vstring(options.inputFiles),
    fileNames  = cms.untracked.vstring(


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_99.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_98.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_97.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_95.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_93.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_91.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_9.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_87.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_82.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_81.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_80.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_8.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_77.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_76.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_74.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_71.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_70.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_7.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_69.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_68.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_67.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_66.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_64.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_63.root', 

'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_62.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_61.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_60.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_6.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_59.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_58.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_57.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_55.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_54.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_53.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_51.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_50.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_5.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_49.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_48.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_47.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_46.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_45.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_442.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_440.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_438.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_436.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_434.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_432.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BdTau3Mu/CRAB3_MC2018_BdTau3Mu_13TeV_DIGI/191216_111437/0000/BdTau3Mu_2018MC_43.root', 



    ),
    duplicateCheckMode = cms.untracked.string('noDuplicateCheck')
)


process.dummy2 = cms.EDAnalyzer("GenXSecAnalyzer")



# Path and EndPath definitions
process.ana = cms.Path(process.dummy2)
# Schedule definition
process.schedule = cms.Schedule(process.ana)

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

'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_128.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_127.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_126.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_125.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_124.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_123.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_122.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_121.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_120.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_12.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_119.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_118.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_117.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_116.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_115.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_114.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_113.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_112.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_111.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_110.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_11.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_109.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_108.root', 



'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_106.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_105.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_104.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_103.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_102.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_101.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_100.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_10.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_1.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_158.root', 

'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_157.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_19.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_189.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_187.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_186.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_185.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_184.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_183.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_182.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_181.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_180.root', 


'root://xrootd-cms.infn.it///store/user/bjoshi/BuTau3Mu/CRAB3_MC2018_BuTau3Mu_13TeV_DIGI/191212_193400/0000/BuTau3Mu_2018MC_18.root',



    ),
    duplicateCheckMode = cms.untracked.string('noDuplicateCheck')
)


process.dummy2 = cms.EDAnalyzer("GenXSecAnalyzer")



# Path and EndPath definitions
process.ana = cms.Path(process.dummy2)
# Schedule definition
process.schedule = cms.Schedule(process.ana)

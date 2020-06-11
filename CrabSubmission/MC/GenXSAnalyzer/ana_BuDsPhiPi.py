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

"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_740.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_741.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_742.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_743.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_744.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_745.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_746.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_747.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_748.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_749.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_75.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_750.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_751.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_752.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_753.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_754.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_755.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_756.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_757.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_758.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_759.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_76.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_760.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_761.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_762.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_763.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_764.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_765.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_766.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_767.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_768.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_769.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_77.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_770.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_771.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_772.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_773.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_774.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_775.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_776.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_777.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_778.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_779.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_78.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_780.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_781.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_782.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_783.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_784.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_785.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_786.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_787.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_788.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_789.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_79.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_790.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_791.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_792.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_793.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_794.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_795.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_796.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_797.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_798.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_799.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_8.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_80.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_800.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_801.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_802.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_803.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_804.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_805.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_806.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_807.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_808.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_809.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_81.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_810.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_811.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_812.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_813.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_814.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_815.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_816.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_817.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_818.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_819.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_82.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_820.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_821.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_822.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_823.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_824.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_825.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_826.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_827.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_828.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_829.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_83.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_830.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_831.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_832.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_833.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_834.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_835.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_836.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_837.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_838.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_839.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_84.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_840.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_841.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_842.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_843.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_844.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_845.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_846.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_847.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_848.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_849.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_85.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_850.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_851.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_852.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_853.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_854.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_855.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_856.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_857.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_858.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_859.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_86.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_860.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_861.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_862.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_863.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_864.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_865.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_866.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_867.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_868.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_869.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_87.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_870.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_871.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_872.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_873.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_874.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_875.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_876.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_877.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_878.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_879.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_88.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_880.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_89.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_9.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_90.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_91.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_92.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_93.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_94.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_95.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_96.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_97.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_98.root",
"file:/lustre/cms/store/user/rosma/DsToPhiMuMuPi_CMSSW_10_2_X_2018/DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1/200110_115854/0000/TSG-RunIIAutumn18DR-00006_99.root",      



    ),
    duplicateCheckMode = cms.untracked.string('noDuplicateCheck')
)


process.dummy2 = cms.EDAnalyzer("GenXSecAnalyzer")



# Path and EndPath definitions
process.ana = cms.Path(process.dummy2)
# Schedule definition
process.schedule = cms.Schedule(process.ana)

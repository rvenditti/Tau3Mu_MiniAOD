#from CRABClient.UserUtilities import config, getUsernameFromSiteDB
from CRABClient.UserUtilities import config,getUsername
config = config()

config.General.requestName = 'SkimPhiPi_BParking_Run2018D_BPH1_Mini_v0'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
#config.JobType.psetName = '/lustrehome/venditti/Tau3Mu_MiniAOD/CMSSW_10_2_1/src/SkimTools/SkimTau3Mu/test/run_Data2018_BParking_MiniAOD_cfg.py'
#config.JobType.psetName = '/lustrehome/venditti/Tau3Mu_MiniAOD/CMSSW_10_2_1/src/SkimTools/SkimTau3Mu/test/run_Data2018_BParking_MiniAOD_Skim1_cfg.py'
config.JobType.psetName = '/lustrehome/venditti/Tau3Mu_MiniAOD/CMSSW_10_2_1/src/SkimTools/SkimPhiPi/test/run_DsPhiPiSkimAndTree_cfg.py'
config.Data.inputDataset = '/ParkingBPH1/Run2018D-05May2019promptD-v1/MINIAOD'
config.Data.inputDBS = 'global'
#config.Data.splitting = 'LumiBased'
config.Data.splitting = 'Automatic'
#config.Data.unitsPerJob = 50
config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions18/13TeV/ReReco/Cert_314472-325175_13TeV_17SeptEarlyReReco2018ABC_PromptEraD_Collisions18_JSON.txt'
#config.Data.runRange = '193093-193999' # '193093-194075'
#config.Data.publication = True
config.Data.outputDatasetTag = 'SkimPhiPi_BParking_Run2018D_BPH1_Mini_v0'
config.JobType.allowUndistributedCMSSW = True 
config.Site.storageSite = 'T2_IT_Bari'
#config.Site.ignoreGlobalBlacklist  = False
#config.Data.lumiMask = 'crab_projects/crab_SkimTau3Mu_BParking_Run2018D_BPH1_Mini_v4/results/lumisToProcess.json'
config.Site.blacklist=['T2_US_UCSD']
#config.Data.outLFN = '/lustre/cms/store/user/rosma/'


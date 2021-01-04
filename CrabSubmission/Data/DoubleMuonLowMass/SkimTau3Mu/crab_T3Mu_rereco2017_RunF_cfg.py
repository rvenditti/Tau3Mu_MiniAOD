from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = 'SkimTau3Mu_2017eraF_rereco31Mar2018_Mini_v0'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'


config.JobType.psetName = '/lustrehome/fsimone/MINIAOD_ntuplizer/CMSSW_10_2_18/src/SkimTools/SkimTau3Mu/test/run_Data2017_PatAndTree_cfg.py'

config.Data.inputDataset = '/DoubleMuonLowMass/Run2017F-31Mar2018-v1/MINIAOD'
config.Data.inputDBS = 'global'
#config.Data.splitting = 'LumiBased'
config.Data.splitting = 'Automatic'
#config.Data.unitsPerJob = 20
config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions17/13TeV/ReReco/Cert_294927-306462_13TeV_EOY2017ReReco_Collisions17_JSON.txt'
#config.Data.runRange = '193093-193999' # '193093-194075'
#config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'SkimTau3Mu_2017eraF_rereco31Mar2018_Mini_v0'
config.JobType.allowUndistributedCMSSW = True 
config.Site.storageSite = 'T2_IT_Bari'
config.Site.ignoreGlobalBlacklist  = True


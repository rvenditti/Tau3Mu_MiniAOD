from CRABClient.UserUtilities import config, getUsername
config = config()

config.General.requestName = 'SkimTau3Mu_MC2018_DsTau3Mu_Mini_privJian_v0'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'


config.JobType.psetName = '/lustrehome/fsimone/MINIAOD_ntuplizer/CMSSW_10_2_18/src/SkimTools/SkimTau3Mu/test/run_MC2018_PatAndTree_cfg.py'

config.Data.inputDataset = '/DsToTau_TauTo3Mu_November2020/wangjian-RunIIAutumn18MiniAOD-102X-c64c34953e011388ee7948c74fdb7fa0/USER'
#config.Data.inputDataset = '/DsToTau_To3Mu_MuFilter_TuneCUEP8M1_13TeV-pythia8/RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/MINIAODSIM'
config.Data.inputDBS = 'phys03'
#config.Data.inputDBS = 'global'
#config.Data.splitting = 'LumiBased'
config.Data.splitting = 'Automatic'
#config.Data.unitsPerJob = 20
#config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'SkimTau3Mu_MC2018_DsTau3Mu_Mini_privJian_v0'
config.JobType.allowUndistributedCMSSW = True 
config.Site.storageSite = 'T2_IT_Bari'
config.Site.ignoreGlobalBlacklist  = True


from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'TreeMaker_QCD_DoubleMu4_v2'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/lustrehome/venditti/Tau3Mu2018/CMSSW_10_3_0/src/SkimTools/SkimTau3Mu/test/run_Tau3MuSkimAndTree_cfg.py'
#config.Data.inputDataset = '/DsTau3Mu/fsimone-crab_crab_DsTau3Mu__13TeV_MC2016_RECO-c3763c515b5d7d94a8137c090655e1bb/USER'
config.Data.inputDataset = '/QCD_DoubleMu4/wangjian-CRAB3_RunIIAutumn18DR_AODSIM-c5ffe086db9ac96902dde93cd44a5aa0/USER'
#config.Data.inputDBS = 'phys03'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = False
config.Data.outputDatasetTag = 'TreeMaker_QCD_DoubleMu4_v2'

config.Site.storageSite = 'T2_IT_Bari'
config.JobType.allowUndistributedCMSSW = True
config.Site.storageSite = 'T2_IT_Bari'
#config.Site.ignoreGlobalBlacklist =True
#config.Site.whitelist = ['T2_IT_Bari']

from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()


config.General.requestName = 'SkimDsPhiPi_DsToPhiMuMuPi_2018_CMSSW_10_6_1_v6_noTrg'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/lustrehome/venditti/Tau3Mu2018_final/CMSSW_10_6_1/src/DsPhiPiTreeMaker/DsPhiPiTreeMaker/test/run_DsPhiPiSkimAndTree_MC_cfg.py'
config.Data.inputDataset = '/DsToPhiMuMuPi_CMSSW_10_2_X_2018/rosma-DsToPhiMuMuPi_CMSSW_10_2_X_2018_RECO_v1-fd6b33a813d01b1040d615bf889c29c4/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 20
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = False
config.Data.outputDatasetTag = 'SkimDsPhiPi_DsToPhiMuMuPi_2018_CMSSW_10_6_1_v6_noTrg'

config.Site.storageSite = 'T2_IT_Bari'
#config.JobType.allowUndistributedCMSSW = True 
config.Site.ignoreGlobalBlacklist  = True

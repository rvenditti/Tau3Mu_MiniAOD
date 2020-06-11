from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'SkimDsPhiPi_BParking_Run2018B_BPH4_v1_missingLumis'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/lustrehome/venditti/Tau3Mu2018_final/CMSSW_10_6_1/src/DsPhiPiTreeMaker/DsPhiPiTreeMaker/test/run_DsPhiPiSkimAndTree_cfg.py'


config.Data.inputDataset = '/ParkingBPH4/Run2018B-05May2019-v2/AOD'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
#config.Data.splitting = 'Automatic'
config.Data.unitsPerJob = 3
config.Data.lumiMask = '/lustrehome/venditti/Tau3Mu2018_final/CMSSW_10_6_1/src/CrabSubmission/Data/SkimDsPhiPi/BParking_RunB/crab_projects/crab_SkimDsPhiPi_BParking_Run2018B_BPH4_v1/results/notFinishedLumis.json'
#config.Data.runRange = '193093-193999' # '193093-194075'
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'SkimDsPhiPi_BParking_Run2018B_BPH4_v1'
config.JobType.allowUndistributedCMSSW = True 
config.Site.storageSite = 'T2_IT_Bari'
#config.Site.ignoreGlobalBlacklist  = True


///
/// \file Pythia_GammaTriggerAndJet.C
/// \brief Configuration of gamma-jet and jet-jet with/out decay gamma trigger
///
/// Generate PYTHIA8 or PYTHIA6 gamma-jet (kPyDirectGamma) or jet-jet (kPyJets), with or without 
/// triggering the gamma in one of the calorimeter possible acceptances.
/// Options are:
/// * process and trigger :
///   * Pythia6Jets/Pythia8Jets: jet-jet events, kPyJets (optionally with jet axis restricted to some zone or not, preferred open)
///   * Pythia6GammaJet/Pythia8GammaJet: gamma-jet events, kPyDirectGamma, with gamma restricted to a calorimeter acceptance.
///   * Pythia6JetsTrg/Pythia8JetsGammaTrg: jet-jet events, kPyJets, with a decay gamma to a calorimeter acceptance above a given pT.
///
/// * acceptance of photon :
///   * FullDetector: Minimal acceptance cuts
///   * EMCRun1 : EMCal |eta| < 0.70,  80 < phi < 180
///   * EMCRun2 : EMCal |eta| < 0.70,  80 < phi < 187
///   * PHSRun1 : PHOS  |eta| < 0.13, 260 < phi < 320
///   * PHSRun2 : PHOS  |eta| < 0.13, 250 < phi < 320
///   * PHSDMC  : DCal+PHOS |eta| < 0.7, 250 < phi < 327
  
///
/// Main configuration method 
///
AliGenerator * 
GeneratorCustom
(TString opt = "kFullDetector")
{
  // acceptance
  Int_t acceptance = kCalorimeterAcceptance_FullDetector;
  if (opt.EqualTo("FullDetector"))
    acceptance = kCalorimeterAcceptance_FullDetector;
  if (opt.EqualTo("EMCRun1"))
    acceptance = kCalorimeterAcceptance_EMCRun1;
  if (opt.EqualTo("PHSRun1"))
    acceptance = kCalorimeterAcceptance_PHSRun1;
  if (opt.EqualTo("EMCRun2"))
    acceptance = kCalorimeterAcceptance_EMCRun2;
  if (opt.EqualTo("PHSRun2"))
    acceptance = kCalorimeterAcceptance_PHSRun2;
  if (opt.EqualTo("PHSDMC"))
    acceptance = kCalorimeterAcceptance_PHSDMC;
  
  // process
  // PYTHIA6
  if (processConfig.EqualTo("Pythia6Jets"))
    return GeneratorPythia6Jets         (kPythia6Tune_Perugia2011, acceptance); 
  if (processConfig.EqualTo("Pythia6GammaJet"))
    return GeneratorPythia6GammaJet     (kPythia6Tune_Perugia2011, acceptance); 
  if (processConfig.EqualTo("Pythia6JetsGammaTrg"))
    return GeneratorPythia6JetsGammaTrg (kPythia6Tune_Perugia2011, acceptance); 
  
  // PYTHIA8
  if (processConfig.EqualTo("Pythia8Jets"))
    return GeneratorPythia8Jets         (kPythia8Tune_Monash2013 , acceptance); 
  if (processConfig.EqualTo("Pythia8GammaJet"))
    return GeneratorPythia8GammaJet     (kPythia8Tune_Monash2013 , acceptance); 
  if (processConfig.EqualTo("Pythia8JetsGammaTrg"))
    return GeneratorPythia8JetsGammaTrg (kPythia8Tune_Monash2013 , acceptance); 
}

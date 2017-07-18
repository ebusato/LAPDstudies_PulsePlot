
void PulsePlot()
{
  TFile* f = new TFile("~/godaq_rootfiles/analysis_v2.18-calibG2/run92LOR.root", "read");
  TTree* t = (TTree*) f->Get("tree");


  TCanvas* c = new TCanvas("c","c");
  int n= t->Draw("Pulse[0]:SampleTimes", "Evt == 15000");
   TGraph *g = new TGraph(n,t->GetV2(),t->GetV1());
 g->Draw("ap");
 g->GetXaxis()->SetTitle("Time [ns]");
 g->GetYaxis()->SetTitle("Amplitude [ADC counts]");
 g->GetXaxis()->SetLabelSize(0.05);
 g->GetYaxis()->SetLabelSize(0.05);
 g->GetXaxis()->SetTitleSize(0.05);
 g->GetYaxis()->SetTitleSize(0.05);
 g->GetXaxis()->SetTitleOffset(1.25);
 g->GetYaxis()->SetTitleOffset(1.5);
 g->SetMarkerColor(kMagenta);
 gPad->SetGridx(1);
 gPad->SetGridy(1);

 PutText(0.53, 0.78, kBlack, "LAPD", 0.047);
 PutText(0.53, 0.72, kBlack, "Protons 65 MeV, I = 5 nA ", 0.047);
 PutText(0.53, 0.66, kBlack, "Target PMMA 5#times5#times5 cm^{3}", 0.047);

 gPad->SaveAs("PulsePlot.png");
}

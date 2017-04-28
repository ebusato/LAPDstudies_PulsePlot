
void PulsePlot()
{
  TFile* f = new TFile("~/godaq_rootfiles/analysis_v2.18-calibG2/run92LOR.root", "read");
  TTree* t = (TTree*) f->Get("tree");


  TCanvas* c = new TCanvas("c","c",600,600);
  int n= t->Draw("Pulse[0]:SampleTimes", "Evt == 15000");
   TGraph *g = new TGraph(n,t->GetV2(),t->GetV1());
 g->Draw("ap");
 g->GetXaxis()->SetTitle("Time [ns]");
 g->GetYaxis()->SetTitle("Amplitude [ADC counts]");
 g->GetXaxis()->SetLabelSize(0.045);
 g->GetYaxis()->SetLabelSize(0.045);
 g->GetXaxis()->SetTitleSize(0.05);
 g->GetYaxis()->SetTitleSize(0.05);
 g->GetXaxis()->SetTitleOffset(1.3);
 g->GetYaxis()->SetTitleOffset(1.7);
 g->SetMarkerColor(kMagenta);
 gPad->SetGridx(1);
 gPad->SetGridy(1);
 gPad->SaveAs("PulsePlot.png");
}

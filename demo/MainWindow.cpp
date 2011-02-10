#include "ContentComponentConstrainer.h"
#include "MainWindow.h"
#include "DemoPanel.h"
#include "MainPanel.h"

MainWindow::MainWindow () 
  : DocumentWindow (TRANS("Dsp Filters Demo"),
                    Colours::lightgrey, 
                    DocumentWindow::allButtons,
                    true)
{
  setResizable (true, false);
  
#if 1
  DemoPanel* contentComponent = new DemoPanel;
  setMenuBar (contentComponent);
  setContentComponent (contentComponent, true, true);
#else
  MainPanel* contentComponent = new MainPanel;
  setMenuBar (contentComponent);
  setContentComponent (contentComponent, true, true);
  contentComponent->setAsConstrainerFor (this);
  ContentComponentConstrainer::attachTo (this);
#endif

  centreWithSize (getWidth(), getHeight());
  setVisible (true);
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeButtonPressed()
{
  JUCEApplication::quit();
}
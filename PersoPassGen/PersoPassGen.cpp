// PersoPassGen.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "PersoPassGen.h"

#include <thread>

#include "qtwidgetsapplication1.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

//#include "workflowLibrary.h"


using namespace std;


void Sleepms(unsigned ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}


int main(int argc, char* argv[])
{
	//workflowLibrary::workflow w;

	QApplication a(argc, argv);

	QtWidgetsApplication1 window;
	a.setApplicationName("PersoPassGen");
	//window.ui.ListWidget->addItem("Amazon Privataccount");
	//window.ui.ListWidget->addItem("Amazon Firma");
	//window.ui.ListWidget->addItem("PayPal privat1");
	//window.ui.ListWidget->addItem("PayPal Firma");
	//window.ui.ListWidget->addItem("Email T-Online");


	//window.ui.lineEditInput->setText("test");
	//window.on_InputButton_clicked();
	//window.ui.ListWidget->setCurrentRow(window.ui.ListWidget->count() - 1);
	//window.on_DeleteButton_clicked();
	//QPixmap pix("C:\\Users\\user\\cpp\\CMakeProject2\\out\\build\\x64-Debug\\CMakeProject2\\buergerserviceorg.jpg");
	QPixmap pix("buergerserviceorg.jpg");
	window.ui.label_4->setPixmap(pix);
	window.statusBar()->setSizeGripEnabled(false);
	window.setFixedSize(window.width(), window.height());
	window.show();
	//window.ui.Label1->setText("program");
	return a.exec();

	Sleepms(3000);
	

	//std::cout << "starting getcertificate." << std::endl;
	//w.getcertificate();
	//std::cout << "parsed certificate as StyledString: " << w.certificateStyledString << std::endl;
	return 0;
}
